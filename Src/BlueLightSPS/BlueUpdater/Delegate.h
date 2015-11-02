#ifndef __DELEGATE_H__
#define __DELEGATE_H__

#include <utility>
using namespace std;



//
// Helper macros.
//
#define JOIN(a, b)		DO_JOIN(a, b)
#define DO_JOIN(a, b)	DO_JOIN2(a, b)
#define DO_JOIN2(a, b)	a##b

#define MAKE_PARAMS1_0(t)
#define MAKE_PARAMS1_1(t)	t##1
#define MAKE_PARAMS1_2(t)	t##1, ##t##2
#define MAKE_PARAMS1_3(t)	t##1, ##t##2, ##t##3
#define MAKE_PARAMS1_4(t)	t##1, ##t##2, ##t##3, ##t##4
#define MAKE_PARAMS1_5(t)	t##1, ##t##2, ##t##3, ##t##4, ##t##5
#define MAKE_PARAMS1_6(t)	t##1, ##t##2, ##t##3, ##t##4, ##t##5, ##t##6
#define MAKE_PARAMS1_7(t)	t##1, ##t##2, ##t##3, ##t##4, ##t##5, ##t##6, ##t##7
#define MAKE_PARAMS1_8(t)	t##1, ##t##2, ##t##3, ##t##4, ##t##5, ##t##6, ##t##7, ##t##8

#define MAKE_PARAMS2_0(t1, t2)
#define MAKE_PARAMS2_1(t1, t2)	t1##1 t2##1
#define MAKE_PARAMS2_2(t1, t2)	t1##1 t2##1, t1##2 t2##2
#define MAKE_PARAMS2_3(t1, t2)	t1##1 t2##1, t1##2 t2##2, t1##3 t2##3
#define MAKE_PARAMS2_4(t1, t2)	t1##1 t2##1, t1##2 t2##2, t1##3 t2##3, t1##4 t2##4
#define MAKE_PARAMS2_5(t1, t2)	t1##1 t2##1, t1##2 t2##2, t1##3 t2##3, t1##4 t2##4, t1##5 t2##5
#define MAKE_PARAMS2_6(t1, t2)	t1##1 t2##1, t1##2 t2##2, t1##3 t2##3, t1##4 t2##4, t1##5 t2##5, t1##6 t2##6
#define MAKE_PARAMS2_7(t1, t2)	t1##1 t2##1, t1##2 t2##2, t1##3 t2##3, t1##4 t2##4, t1##5 t2##5, t1##6 t2##6, t1##7 t2##7
#define MAKE_PARAMS2_8(t1, t2)	t1##1 t2##1, t1##2 t2##2, t1##3 t2##3, t1##4 t2##4, t1##5 t2##5, t1##6 t2##6, t1##7 t2##7, t1##8 t2##8

#define MAKE_PARAMS1(n, t)		JOIN(MAKE_PARAMS1_, n)(t)
#define MAKE_PARAMS2(n, t1, t2)	JOIN(MAKE_PARAMS2_, n)(t1, t2)


// Dummy declaration.
template < typename T >
class CDelegate;


//
// Specializations.
//
// CDelegate<R ()>
#define DELEGATE_NUM_ARGS	0
#include "delegatetemplate.h"
#undef DELEGATE_NUM_ARGS

// CDelegate<R (T1)>
#define DELEGATE_NUM_ARGS	1
#include "delegatetemplate.h"
#undef DELEGATE_NUM_ARGS

// CDelegate<R (T1, T2)>
#define DELEGATE_NUM_ARGS	2
#include "delegatetemplate.h"
#undef DELEGATE_NUM_ARGS

// CDelegate<R (T1, T2, T3)>
#define DELEGATE_NUM_ARGS	3
#include "delegatetemplate.h"
#undef DELEGATE_NUM_ARGS

// CDelegate<R (T1, T2, T3, T4)>
#define DELEGATE_NUM_ARGS	4
#include "delegatetemplate.h"
#undef DELEGATE_NUM_ARGS

// CDelegate<R (T1, T2, T3, T4, T5)>
#define DELEGATE_NUM_ARGS	5
#include "delegatetemplate.h"
#undef DELEGATE_NUM_ARGS

// CDelegate<R (T1, T2, T3, T4, T5, T6)>
#define DELEGATE_NUM_ARGS	6
#include "delegatetemplate.h"
#undef DELEGATE_NUM_ARGS

// CDelegate<R (T1, T2, T3, T4, T5, T6, T7)>
#define DELEGATE_NUM_ARGS	7
#include "delegatetemplate.h"
#undef DELEGATE_NUM_ARGS

// CDelegate<R (T1, T2, T3, T4, T5, T6, T7, T8)>
#define DELEGATE_NUM_ARGS	8
#include "delegatetemplate.h"
#undef DELEGATE_NUM_ARGS

#endif // __DELEGATE_H__
