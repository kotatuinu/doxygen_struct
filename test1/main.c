#include <malloc.h>
#include "test_define.h"
#include "test_struct.h"

/*  main routine	*/
int main()
{
	int rtn = 0;

	stTest1 test1;

	test1.ui32test1 = 1;
	test1.sttest1_1.eTest01 = TEST_START;
	test1.sttest1_1.ui32test1 = 2;
	test1.pNext = (stTest1*)malloc(sizeof(stTest1));

	test1.pNext->pNext = (stTest1*)NULL;
	test1.ui32test1 = 3;

	free(test1.pNext);

	return rtn;
}
