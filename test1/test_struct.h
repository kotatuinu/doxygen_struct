#ifndef TEST_STRUCT_H
#define TEST_STRUCT_H

#include "test_define.h"

typedef unsigned long UINT32;	/**< breif Datatype UINT32(unsigned long). */

/** breif Union Test2.	*/
typedef union uTEST2_ {
	unsigned long	ulmember1;		/**<breif uTest2 Member ulmember1. */
	unsigned int	uimember2;		/**<breif uTest2 Member uimember2. */
	unsigned char	ucmember3[5];	/**<breif uTest2 Member ucmember3. */
} uTest2;

/** breif Struct Test1_1.	*/
typedef struct stTEST1_1_ {
	UINT32	ui32test1;		/**<breif test1_1 Member test1. */
	UINT8	ui8Padding[4];	/**<breif test1_1 Member Padding.	*/
	eTEST01 eTest01;		/**<breif test1_1 Member enum Test01.	*/
} stTest1_1;

/** breif Struct Test1.	*/
typedef struct stTEST1_ {
	uTest2	utest2;			/**<breif test1 Member test2. */
	UINT32	ui32test1;		/**<breif test1 Member test1. */
	UINT8	ui8Padding[4];	/**<breif test1 Member Padding.	*/
	stTest1_1	sttest1_1;	/**<breif test1 Member stTest1_1.	*/
	struct stTEST1_ *pNext;	/**<breif test1 Member pNext - Next Pointer. */
} stTest1;


#endif /* TEST_STRUCT_H */
