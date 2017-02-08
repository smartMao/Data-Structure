#include"AVL-Tree.h"
#include<stdio.h>
#include<stdlib.h>
#include <sys/timeb.h>
#if defined(WIN32)
# define  TIMEB    _timeb
# define  ftime    _ftime
#else
#define TIMEB timeb
#endif

int main()
{
 // 实现： 生成具有最少节点、高度为H的AVL树

	time_t ltime1, ltime2, tmp_time;
	struct TIMEB tstruct1, tstruct2;

	
	ftime (&tstruct1);            // start time ms
	time (&ltime1);               // start time s

	AvlTree t = makeRandomAvlTree(30);

	time (&ltime2);               // end time sec
	ftime (&tstruct2);            // end time ms

	tmp_time = (ltime2 * 1000 + tstruct2.millitm) - (ltime1 * 1000 + tstruct1.millitm);
	printf("%I64d \n", tmp_time);

}
