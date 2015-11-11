#include "IMessageStation.h"
#include "ThreadCorrespondent.h"

#define WM_TRD_DELEGATE WM_APP + 5564

// Used as template parameters:
//		/*typename T0*/; typename T1, typename T2, ..., typename Tn
#define DELEGATE_TEMPLATE_PARAMS	MAKE_PARAMS1(DELEGATE_NUM_ARGS, typename T)

// Used as template arguments:
//		/*T0*/; T1, T2, ..., Tn
#define DELEGATE_TEMPLATE_ARGS	MAKE_PARAMS1(DELEGATE_NUM_ARGS, T)

// Used as function parameters:
//		/*T0 a0*/; T1 a1, T2 a2, ..., Tn an
#define DELEGATE_FUNCTION_PARAMS	MAKE_PARAMS2(DELEGATE_NUM_ARGS, T, a)

// Used as function arguments:
//		/*a0*/; a1, a2, ..., an
#define DELEGATE_FUNCTION_ARGS	MAKE_PARAMS1(DELEGATE_NUM_ARGS, a)


//		/*a0*/; ptr->a1, ptr->a2, ..., ptr->an
#define DELEGATE_LPARAM_ARGS(ptr)	MAKE_PARAMS4(DELEGATE_NUM_ARGS, ptr, a)

//	/*T0 a0*/; T1 a1; T2 a2; ...; Tn an;
#define DELEGATE_STRUCT_MEMBER	MAKE_PARAMS3(DELEGATE_NUM_ARGS, T, a)


// Comma if nonzero number of arguments.
#if DELEGATE_NUM_ARGS == 0
#define DELEGATE_COMMA
#else
#define DELEGATE_COMMA	,
#endif

// template < typename R, typename T1, typename T2, ..., typename Tn >
// class CDelegate< R ( T1, T2, ..., Tn ) >
template < typename R DELEGATE_COMMA DELEGATE_TEMPLATE_PARAMS >
class CDelegate < R(DELEGATE_TEMPLATE_ARGS) > : public IMessageStation<R>
{
private:
	
	auto_ptr<CThreadCorrespondent<R>> m_thrCorrespondent;
	struct Package{
		DELEGATE_STRUCT_MEMBER
	};

	// Functor invoker.
	template < typename TFunctor >
	struct Invoker
	{
		// static R Invoke(const TFunctor&f, T1 a1, T2 a2, ..., Tn an )
		static R Invoke( const TFunctor& f DELEGATE_COMMA DELEGATE_FUNCTION_PARAMS )
		{
			// return ( const_cast<TFunctor&>(f) )( a1, a2, ..., an );
			return ( const_cast < TFunctor& > (f) )( DELEGATE_FUNCTION_ARGS);
		}
	};

	// Member function invoker.
	template < typename TPtr, typename TFunctionPtr >
	struct Invoker < pair < TPtr, TFunctionPtr > >
	{
		// static R Invoke( const pair<TPtr, TFunctionPtr>& mf, T1 a1, T2 a2, ..., Tn an )
		static R Invoke( const pair < TPtr, TFunctionPtr > &mf DELEGATE_COMMA DELEGATE_FUNCTION_PARAMS )
		{
			// return ( (* mf.first) .* mf.second )( a1, a2, ..., an );
			return ( (* mf.first) .* mf.second )( DELEGATE_FUNCTION_ARGS );
		}
	};

	// DelegateImplBase
	class CDelegateImplBase
	{
	public:
		CDelegateImplBase* m_pPrevious;

	protected:
		CDelegateImplBase() : m_pPrevious(0) { }
		CDelegateImplBase(const CDelegateImplBase& other) : m_pPrevious(0) { }

	public:
		virtual ~CDelegateImplBase() { }

		virtual CDelegateImplBase* Clone() const = 0;

		// virtual R Invoke( T1 a1, T2 a2, ..., Tn an ) const = 0;
		virtual R Invoke( DELEGATE_FUNCTION_PARAMS ) const = 0;
	};

	// Functor DelegateImpl
	template < typename TFunctor >
	class CDelegateImpl : public CDelegateImplBase
	{
	public:
		TFunctor m_Functor;

	public:
		CDelegateImpl(const TFunctor& f) : m_Functor(f) { }

		CDelegateImpl(const CDelegateImpl& other) : m_Functor(other.m_Functor) { }

	public:
		virtual CDelegateImpl* Clone() const
		{
			return new CDelegateImpl( *this );
		}

		// virtual R Invoke( T1 a1, T2 a2, ..., Tn an ) const
		virtual R Invoke( DELEGATE_FUNCTION_PARAMS ) const
		{
			// return Invoker<TFunctor>::Invoke( this->Functor, a1, a2, ..., an );
			return Invoker < TFunctor > ::Invoke( m_Functor DELEGATE_COMMA DELEGATE_FUNCTION_ARGS );
		}
	};

private:
	CDelegateImplBase* m_pLast;

public:
	/// Default constructor.
	CDelegate() 
		: m_pLast(0){
		m_thrCorrespondent.reset(new CThreadCorrespondent<R>(this));
	}

	/// Functor constructor.
	template < typename TFunctor >
	explicit CDelegate(const TFunctor& f) 
		: m_pLast(0)
	{
		*this = f;
		m_thrCorrespondent.reset(new CThreadCorrespondent<R>(this));
	}

	/// Member function constructor.
	template < typename TPtr, typename TFunctionPtr >
	explicit CDelegate(const TPtr& objPtr, const TFunctionPtr& mfPtr) 
		: m_pLast(0)
	{
		*this = make_pair(objPtr, mfPtr);
		m_thrCorrespondent.reset(new CThreadCorrespondent<R>(this));
	}

	/// Copy constructor.
	CDelegate(const CDelegate& d) 
		: m_pLast(0)
	{
		*this = d;
		m_thrCorrespondent.reset(new CThreadCorrespondent<R>(this));
	}

	/// Destructor.
	virtual ~CDelegate()
	{
		Clear();
	}

	virtual void OnMessage(UINT uMsg, WPARAM wParam, LPARAM lParam){
		if (m_pLast->m_pPrevious)
		{
			InvokeDelegateList(m_pLast->m_pPrevious DELEGATE_COMMA DELEGATE_LPARAM_ARGS(((Package*)(lParam))));
		}
		return m_pLast->Invoke(DELEGATE_LPARAM_ARGS(((Package*)(lParam))));
	}

public:
	/// Whether this delegate have no method yet?
	BOOL IsEmpty() const
	{
		return (!m_pLast);
	}

	/// Is this a multi-cast delegate?
	BOOL IsMulticast() const
	{
		return ( m_pLast && m_pLast->m_pPrevious );
	}

private:
	/// Clone method chain.
	static CDelegateImplBase* CloneDelegateList(CDelegateImplBase* pList, CDelegateImplBase** ppOutFirst)
	{
		CDelegateImplBase* pOldLast = pList;
		CDelegateImplBase* pNewLast = 0;
		CDelegateImplBase** ppNewLast = &pNewLast;
		CDelegateImplBase* temp = 0;

		try
		{
			while ( pOldLast )
			{
				temp = pOldLast->Clone();
				*ppNewLast = temp;
				ppNewLast = &temp->m_pPrevious;
				pOldLast = pOldLast->m_pPrevious;
			}
		}
		catch ( ... )
		{
			FreeDelegateList(pNewLast);
			return 0;
		}

		if ( ppOutFirst )
		{
			*ppOutFirst = temp;
		}

		return pNewLast;
	}

	/// Destroy method chain.
	static void FreeDelegateList(CDelegateImplBase* pList)
	{
		CDelegateImplBase* temp = 0;
		while ( pList )
		{
			temp = pList->m_pPrevious;
			delete pList;
			pList = temp;
		}
	}

	/// Invoke method chain.
	// static void InvokeDelegateList(CDelegateImplBase* pList, T1 a1, T2 a2, ..., Tn an )
	static void InvokeDelegateList( CDelegateImplBase* pList DELEGATE_COMMA DELEGATE_FUNCTION_PARAMS )
	{
		if ( pList )
		{
			// Invoke previous recursively.
			if ( pList->m_pPrevious )
			{
				// InvokeDelegateList( pList->m_pPrevious, a1, a2, ..., an );
				InvokeDelegateList( pList->m_pPrevious DELEGATE_COMMA DELEGATE_FUNCTION_ARGS );
			}

			// Invoke self.
			// pList->Invoke( a1, a2, ..., an );
			pList->Invoke( DELEGATE_FUNCTION_ARGS );
		}
	}

public:
	/// Append a functor to the method chain.
	template < typename TFunctor >
	void Add(const TFunctor& f)
	{
		CDelegateImplBase* d = new CDelegateImpl < TFunctor > (f);
		d->m_pPrevious = m_pLast;
		m_pLast = d;
	}

	/// Append a member function to the method chain.
	template < typename TPtr, typename TFunctionPtr >
	void Add(const TPtr& objPtr, const TFunctionPtr& mfPtr)
	{
		CDelegateImplBase* d = new CDelegateImpl < pair < TPtr, TFunctionPtr > > ( make_pair(objPtr, mfPtr) );
		d->m_pPrevious = m_pLast;
		m_pLast = d;
	}

	/// Remove a functor from the method chain.
	template < typename TFunctor >
	BOOL Remove(const TFunctor& f)
	{
		CDelegateImplBase* d = m_pLast;
		CDelegateImplBase** pp = &m_pLast;
		CDelegateImpl < TFunctor > *impl;

		while ( d )
		{
			impl = dynamic_cast < CDelegateImpl < TFunctor > * > (d);
			if ( impl && ( impl->m_Functor == f ) )
			{
				*pp = d->m_pPrevious;
				delete impl;
				return TRUE;
			}
			pp = &d->m_pPrevious;
			d = d->m_pPrevious;
		}
		return FALSE;
	}

	/// Remove a member function from the method chain.
	template < typename TPtr, typename TFunctionPtr >
	BOOL Remove(const TPtr& objPtr, const TFunctionPtr& mfPtr)
	{
		return Remove( make_pair(objPtr, mfPtr) );
	}

	/// Clean up the method chain.
	void Clear()
	{
		FreeDelegateList(m_pLast);
		m_pLast = 0;
	}

private:
	/// Compare to a functor.
	template < typename TFunctor >
	BOOL Equals(const TFunctor& f) const
	{
		if ( !m_pLast || ( m_pLast->m_pPrevious ) )
		{
			return FALSE;
		}

		CDelegateImpl < TFunctor > *impl = dynamic_cast < CDelegateImpl < TFunctor > * > (m_pLast);
		if ( !impl )
		{
			return FALSE;
		}
		return (impl->m_Functor == f);
	}

public:
	/// Override BOOL type cast.
	operator BOOL() const
	{
		return !IsEmpty();
	}

	/// Override operator !.
	BOOL operator!() const
	{
		return IsEmpty();
	}

	/// Functor assignment.
	template < typename TFunctor >
	CDelegate& operator = (const TFunctor& f)
	{
		CDelegateImplBase* d = new CDelegateImpl < TFunctor > (f);
		FreeDelegateList(m_pLast);
		m_pLast = d;
		return *this;
	}

	/// Delegate assignment.
	CDelegate& operator = (const CDelegate& d)
	{
		if (this != &d)
		{
			CDelegateImplBase* pNewList = CloneDelegateList(d.m_pLast, 0);
			FreeDelegateList(m_pLast);
			m_pLast = pNewList;
		}
		return *this;
	}

	/// Override operator +=.
	template < typename TFunctor >
	CDelegate& operator += (const TFunctor& f)
	{
		Add(f);
		return *this;
	}

	/// Override operator +.
	template < class TFunctor >
	friend CDelegate operator + (const CDelegate& d, const TFunctor& f)
	{
		return (CDelegate(d) += f);
	}

	/// Override operator +.
	template < class TFunctor >
	friend CDelegate operator + (const TFunctor& f, const CDelegate& d)
	{
		return (d + f);
	}

	/// Override operator -=.
	template < typename TFunctor >
	CDelegate& operator -= (const TFunctor& f)
	{
		Remove(f);
		return *this;
	}

	/// Override operator -.
	template < typename TFunctor >
	CDelegate operator - (const TFunctor& f) const
	{
		return (CDelegate(*this) -= f);
	}

	/// Override operator ==.
	template < typename TFunctor >
	friend BOOL operator == (const CDelegate& d, const TFunctor& f)
	{
		return d.Equals(f);
	}

	/// Override operator ==.
	template < typename TFunctor >
	friend BOOL operator == (const TFunctor& f, const CDelegate& d)
	{
		return (d == f);
	}

	/// Override operator !=.
	template < typename TFunctor >
	friend BOOL operator != (const CDelegate& d, const TFunctor& f)
	{
		return !(d == f);
	}

	/// Override operator !=.
	template < typename TFunctor >
	friend BOOL operator != (const TFunctor& f, const CDelegate& d)
	{
		return (d != f);
	}

	/// Override operator ().
	R operator()(DELEGATE_FUNCTION_PARAMS DELEGATE_COMMA bool bStrideThread = false) const
	{
		if ( m_pLast )
		{
			
			if (bStrideThread)
			{
				Package pk = { DELEGATE_FUNCTION_ARGS };
				return m_thrCorrespondent->Send(WM_TRD_DELEGATE, 0, (LPARAM)&pk);
			}
			else
			{
				if (m_pLast->m_pPrevious)
				{
					InvokeDelegateList(m_pLast->m_pPrevious DELEGATE_COMMA DELEGATE_FUNCTION_ARGS);
				}
				return m_pLast->Invoke(DELEGATE_FUNCTION_ARGS);
			}
		}
	}
};


#undef DELEGATE_TEMPLATE_PARAMS
#undef DELEGATE_TEMPLATE_ARGS
#undef DELEGATE_FUNCTION_PARAMS
#undef DELEGATE_FUNCTION_ARGS
#undef DELEGATE_COMMA
