#include <stdio.h>
//case 1 nothing is const
/*int main(void)
{
	//
	float pi=3.142f; // variable is not const
	float *ptr=&pi;  // value of ptr is not const
	                 // address of ptr is not const
	float pj=10.4f;
	printf("\n pi=%.3f pj=%.3f *ptr=%.3f", pi, pj, *ptr);

	pi=3.11f; // allowed as pi is not constant variable
	printf("\n pi=%.3f pj=%.3f *ptr=%.3f", pi, pj, *ptr);

	*ptr=3.152f; /// alloweed as value of pointer is not constant
	printf("\n pi=%.3f pj=%.3f *ptr=%.3f", pi, pj, *ptr);


	ptr=&pj; // allowed as address of pointer is not const
	printf("\n pi=%.3f pj=%.3f *ptr=%.3f", pi, pj, *ptr);


	return 0;
}
*/
//case 2 variable pi is const
         //value of ptr is not const & address of ptr is not const
/*int main(void)
{
	const float pi=3.142f; // variable is const
	float *ptr=&pi;  // value of ptr is not const
	                 // address of ptr is not const
	float pj=10.4f;
	printf("\n pi=%.3f pj=%.3f *ptr=%.3f", pi, pj, *ptr);

	//pi=3.11f; // not allowed to modify as pi is constant variable
	//pi++;
	//++pi;
	//--pi;
	//pi--;
	//pi+=10;
	//pi-=10;
	//pi*=10;
	//pi/=10;

	printf("\n pi=%.3f pj=%.3f *ptr=%.3f", pi, pj, *ptr);

	*ptr=3.152f; /// allowed as value of pointer is not constant
	printf("\n pi=%.3f pj=%.3f *ptr=%.3f", pi, pj, *ptr);


	ptr=&pj; // allowed as address of pointer is not const
	printf("\n pi=%.3f pj=%.3f *ptr=%.3f", pi, pj, *ptr);


	return 0;
}*/

//case 3   variable pi is const
         //value of ptr is constant and address of ptr is not constant

/*int main(void)
{
	
	const float pi=3.142f; // variable is const
       
       // way1
	//float const  *ptr=&pi  // value of ptr is  const
	                   // address of ptr is not const
       
      //way2
	const float *ptr=&pi;  // value of ptr is  const
	                   // address of ptr is not const

	float pj=10.4f;
	printf("\n pi=%.3f pj=%.3f *ptr=%.3f", pi, pj, *ptr);

	//pi=3.11f; // not allowed to modify as pi is constant variable
	//pi++;
	//++pi;
	//--pi;
	//pi--;
	//pi+=10;
	//pi-=10;
	//pi*=10;
	//pi/=10;

	printf("\n pi=%.3f pj=%.3f *ptr=%.3f", pi, pj, *ptr);

	//*ptr=3.152f; ///not  allowed as value of ptr is constant
	printf("\n pi=%.3f pj=%.3f *ptr=%.3f", pi, pj, *ptr);


	ptr=&pj; // allowed as address of pointer is not const
	printf("\n pi=%.3f pj=%.3f *ptr=%.3f", pi, pj, *ptr);


	return 0;
}*/

//case 4   variable pi is const
         //value of ptr is not  const
		 //address of ptr is const
/*int main(void)
{
	//
	const float pi=3.142f; // variable is  const

	float * const ptr=&pi;  // value of ptr is not const
	                   // address of ptr is const
	float pj=10.4f;

	printf("\n pi=%.3f pj=%.3f *ptr=%.3f", pi, pj, *ptr);

	//pi=3.11f; // not allowed to modify as pi is constant variable
	//pi++;
	//++pi;
	//--pi;
	//pi--;
	//pi+=10;
	//pi-=10;
	//pi*=10;
	//pi/=10;

	printf("\n pi=%.3f pj=%.3f *ptr=%.3f", pi, pj, *ptr);

	*ptr=3.152f; ///allowed as value of pointer is not constant
	printf("\n pi=%.3f pj=%.3f *ptr=%.3f", pi, pj, *ptr);


	//ptr=&pj; // notallowed as address of pointer is  const
	printf("\n pi=%.3f pj=%.3f *ptr=%.3f", pi, pj, *ptr);


	return 0;
}*/


//case 5   variable pi is const
         //value of ptr is   const
		 //address of ptr is const
int main(void)
{
	const float pi=3.142f; // variable is  const

	const float * const ptr=&pi;  // value of ptr is const
	                   // address of ptr is const
	float pj=10.4f;

	printf("\n pi=%.3f pj=%.3f *ptr=%.3f", pi, pj, *ptr);

	//pi=3.11f; // not allowed to modify as pi is constant variable
	//pi++;
	//++pi;
	//--pi;
	//pi--;
	//pi+=10;
	//pi-=10;
	//pi*=10;
	//pi/=10;

	printf("\n pi=%.3f pj=%.3f *ptr=%.3f", pi, pj, *ptr);

	//*ptr=3.152f; ///not allowed as value of pointer is  constant
	printf("\n pi=%.3f pj=%.3f *ptr=%.3f", pi, pj, *ptr);


//	ptr=&pj; // not allowed as address of pointer is  const
	printf("\n pi=%.3f pj=%.3f *ptr=%.3f", pi, pj, *ptr);


	return 0;
}
