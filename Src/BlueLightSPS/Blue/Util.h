#pragma once
#include "UILib/BSStatic.h"
#include "BRButton.h"
#include <vector>
#include <Windows.h>
#include <memory>
namespace Util_Tools
{
	class Util
	{
	public:
		Util();
		~Util();
		static void base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len, CString& strBase64);
		static void SetWindowSize(HWND hWnd, int iWheight, int iHeight);
		static void SetClientSize(HWND hWnd, int iWheight, int iHeight);
		static CComboBox* CreateComboBox(CWnd* pParent, UINT Id, CString csFont, int iFSize, BOOL isReadOnly = FALSE);
		static CBSStatic* CreateStatic(CWnd* pParent, UINT Id, CString csWindowText, CString csFont, int iFSize);
		static CEdit* CreateEdit(CWnd* pParent, UINT Id, CString csDefaultText, CString csFont, int iFSize);
		static CDateTimeCtrl* CreateDateTimePicker(CWnd* pParent, UINT Id, CString csFont, int iFSize);
		static CDateTimeCtrl* CreateDateTimePickerWithoutCheckbox(CWnd* pParent, UINT Id, CString csFont, int iFSize);
		static CBRButton* CreateButton(CWnd* pParent, UINT Id, CString csWindowText, CString csFont, int iFSize);
		static CButton* CreateCheckBox(CWnd* pParent, UINT Id, CString csWindowText, CString csFont, int iFSize);
		static void Split(CString& src, TCHAR split, std::vector<CString>& retData);
		static void Split(CString& src, TCHAR split, std::vector<int>& retData);
		static void Join(const std::vector<CString>& retData, CString& dest);
		static void Join(const std::vector<int>& retData, CString& dest);
		static LPCTSTR ToString(bool bVal);

		static void StringToDate(CString &strData, COleDateTime& objDataTime);
		static void StringToDataTime(CString &strData, COleDateTime& objDataTime);
		static DOUBLE CompareTime(CString& strLeftUpdateTime, CString& strRightUpdateTime);
		static DOUBLE CompareTime(SYSTEMTIME &tmLeftTime, SYSTEMTIME &tmRightTime);
		static bool MakeDir(LPCTSTR lpPath);
		static bool DeleteFiles(LPCTSTR strFolderPath);
		static bool GetExpandPath(LPCTSTR pszEnvironmentPath, CString &csExpandPath);
		static void Utf16leToUtf8(const CString& unicodeString, std::string& str)
		{
			int stringLength = ::WideCharToMultiByte(CP_UTF8, NULL, unicodeString, wcslen(unicodeString), NULL, 0, NULL, NULL);
			char* buffer = new char[stringLength + 1];
			::WideCharToMultiByte(CP_UTF8, NULL, unicodeString, wcslen(unicodeString), buffer, stringLength, NULL, NULL);
			buffer[stringLength] = '\0';
			str = buffer;
			delete[] buffer;
		}

		static bool MakeDateQueryCommand(bool bHasFrom, bool bHasTo, CString& strFrom, CString& strTo, CString& strVal);
	};


	//Singleton
	template <typename TyFun_>
	class CEndCall
	{
	public:
		CEndCall(TyFun_ myFunCall)
			: m_myFunCall(myFunCall)
		{
		}

		~CEndCall(void)
		{
			m_myFunCall();
		}
	private:
		TyFun_ m_myFunCall;
	};

	// CCriticalSection
	class CCriticalSection
	{
	public:
		CCriticalSection(void)
		{
			InitializeCriticalSection(&m_clCriticalSection);
		}

		virtual ~CCriticalSection(void)
		{
			DeleteCriticalSection(&m_clCriticalSection);
		}

		inline void Enter(void)
		{
			EnterCriticalSection(&m_clCriticalSection);
		}

		inline void Leave(void)
		{
			LeaveCriticalSection(&m_clCriticalSection);
		}

	private:
		CRITICAL_SECTION m_clCriticalSection;
	};

	// CSingleton
	template <typename Type_>
	class CSingleton
	{
		friend Type_;
	protected:
		static Type_* GetInstance(void)
		{
			static CEndCall<void(*)(void)> clEndCall(&ReleaseInstance);

			if (NULL == m_pInstance)
			{
				m_CriticalSection.Enter();
				if (NULL == m_pInstance)
				{
					Type_* pInstance = new Type_;

					if (NULL != pInstance)
					{
						if (pInstance->Initialize())
						{
							m_pInstance = pInstance;
						}
						else
						{
							delete pInstance;
							pInstance = NULL;
						}
					}
				}
				m_CriticalSection.Leave();
			}

			return m_pInstance;
		}

		static void ReleaseInstance(void)
		{
			if (NULL != m_pInstance)
			{
				m_CriticalSection.Enter();
				if (NULL != m_pInstance)
				{
					Type_* pInstance = m_pInstance;
					m_pInstance = NULL;

					delete pInstance;
					pInstance = NULL;
				}
				m_CriticalSection.Leave();
			}

			return;
		}
	protected:
		static Type_* volatile m_pInstance;
		static CCriticalSection m_CriticalSection;
	};

	template <typename Type_>
	Type_* volatile CSingleton<Type_>::m_pInstance = NULL;

	template <typename Type_>
	CCriticalSection CSingleton<Type_>::m_CriticalSection;

	// TO_BE_SINGLETON

#define TO_BE_SINGLETON(ClassName)\
private:\
	friend class Util_Tools::CSingleton<ClassName>;\
	typedef Util_Tools::CSingleton<ClassName> CMySingleton;\
	ClassName(void);\
	ClassName(const ClassName&);\
	~ClassName(void) { UnInitialize(); }\
	ClassName& operator = (const ClassName&);\
public:\
	static ClassName* GetInstance(void)\
				{\
	return CMySingleton::GetInstance();\
				}\
	static void ReleaseInstance(void)\
				{\
	CMySingleton::ReleaseInstance();\
	return;\
				}\
private:\
	bool Initialize(void);\
	void UnInitialize(void);

	template < typename SingletonType_, bool bStaticSingleton_ >
	class CSingletonPtr
		: public CSingletonPtr < SingletonType_, false >
	{
	public:
		CSingletonPtr(void)
		{
			static CSingletonPtr<SingletonType_, false> s_pActiveInstance;
			return;
		}
	};

	template < typename SingletonType_ >
	class CSingletonPtr < SingletonType_, false >
	{
	public:
		CSingletonPtr(void) { add_ref(); }

		CSingletonPtr(const CSingletonPtr&) { add_ref(); }

		~CSingletonPtr(void) { remove_ref(); }

		inline SingletonType_* operator->(void)
		{
			return SingletonType_::GetInstance();
		}

		inline SingletonType_& operator* (void)
		{
			return *(operator->());
		}

		inline operator bool(void)
		{
			return (NULL != SingletonType_::GetInstance());
		}

	private:
		static void add_ref(void)
		{
			ms_CriticalSection.Enter();
			++ms_uRef;
			ms_CriticalSection.Leave();
		}

		static void remove_ref(void)
		{
			ms_CriticalSection.Enter();
			if (0U == --ms_uRef)
			{
				SingletonType_::ReleaseInstance();
			}
			ms_CriticalSection.Leave();
		}
	private:
		operator SingletonType_* (void);
		operator const SingletonType_* (void);

	protected:
		static volatile unsigned int ms_uRef;
		static CCriticalSection ms_CriticalSection;
	};

	template < typename SingletonType_ >
	volatile unsigned int CSingletonPtr<SingletonType_, false>::ms_uRef = 0U;

	template < typename SingletonType_ >
	CCriticalSection CSingletonPtr<SingletonType_, false>::ms_CriticalSection;

}