//*1.
/*
	#include<stdio.h>
	int main(void)
	{
		int x = -1, y = 2, z = 0;
		z =x++ && y++;
		 // -1     2
		//t// T       T
		printf("\n x=%d, y=%d,  z=%d", x, y, z);
		return 0;
	}
*/
	///* 2.
/*
	#include<stdio.h>
	int main(void)
	{
		int x = -1, y = -1, z = 0;
		z = x++ && y++;
		   //-1    -1
		//T   //T     T
		printf("\n x=%d, y=%d,  z=%d\n", x, y, z);
		                                //0 0  1
		return 0;

	}
*/
	//3.
/*
	#include<stdio.h>
	int main(void)
	{
		int x = 0, y = 0, z = 0;
		z = ++x || ++y;
		   // 0
		   // 1
		   //T
		printf("\n x=%d, y=%d,  z=%d", x, y, z);
		                          // 1   0   1
		return 0;
	}
*/
	// 4.
/*
	#include<stdio.h>
	int  main(void)
	{
		int x = 1, y = 2, z = 0;
		z = x++ || y++;
		//  1
		 // T
		  // 2
		printf("\n x=%d, y=%d,  z=%d\n", x, y, z);
		                              // 2  2 1
		return 0;
	}
*/

	//5.
/*
	#include<stdio.h>
	int main(void)
	{
		int i, j, k, l;
		i = j = k =0;
		l = i++ || j++ && k++;
		  // 0     0
			//F    F
		   //1     1    // F
		//F
		printf("i=%d j=%d k=%d l=%d", i, j, k, l);
		                         //    1 1 0   0
		return 0;
	}
*/
	//6.
/*
	#include<stdio.h>
	int main(void)
	{
		int i, j, k, l;
		i = j = k =-1;
		l = ++i && ++j || ++k;
		//   -1           -1
		//   0             0
		  // f              F
		// F
		printf("i=%d j=%d k=%d l=%d", i, j, k, l);
		                            // 0 -1 0 0
		return 0;
	}

*/
/*
	//7.
	#include<stdio.h>
	int main()
	{
		int i, j, k, l;
		i = j = k =0;
		l = i++ && j++ && k++;
		  // 0
		  // F
		   // F
		printf("i=%d j=%d k=%d l=%d", i, j, k, l);
		                             // 1 0 0 0

	return 0;
	}
*/
	//8.
/*
	#include<stdio.h>
	int main(void)
	{
		int i, j, k, l;
		i = j = k = -1;
		l = ++i && ++j || ++k;
		//   -1
		//   0
		// f                -1
		// F                0
		 // F                F
		printf("i=%d j=%d k=%d l=%d", i, j, k, l);
		//                             0 -1 0 0
	return 0;
	}


*/

/*
	//9.
	#include<stdio.h>
	int main(void)
	{
		int i=3, j=0;
		j= ++i * ++i * ++i * ++i;// gcc
		//  3     4      5    6
		// 4      5       6  7
		// 5*5= 25*6== 150
		printf("i=%d j=%d\n", i, j);
		j= ++i * ++i * ++i ;// TC/VS
		   // 3    4    5
		   // 4    5    6
		// j == 6*6*6 =216
		return 0;
	}
*/

	//10.
/*
	#include<stdio.h>
	int main(void)
	{

	//int i = (3, 4, 5), j = (++i, i++, i++, ++i, ++i);
	    // 5               // 5    6   7    8    9
	                       //6     6   7    9    10

    //int i = (3, 4, 5), j = (++i, i++, i++, ++i, i++);
		 // 5             // 5    6   7     8   9
                          // 6     6  7     9   10
	printf("i=%d j=%d\n ", i, j);
	return 0;
	}
*/
#include<stdio.h>
int main()
{
	//int x=10, 20, y; // error as variable cant start with digits
	int x=(10, 20), y;
	//y= 10, 20, 30;
	y= (10, 20, 30);
	printf("\n x=%d y=%d", x, y);
	return 0;
}

