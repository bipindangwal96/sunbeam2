#include <stdio.h>
//int main(int argc, char *argv[], char *envp[])
int main(int argc, char **argv, char **envp)
{
	int no1, no2, ans;
	char op;
	if(argc!=4)
	{
		printf("\n invalid arguments =%d ", argc);
		printf("\n ProgName No1 Operator No2 \n");
	}
	else
	{
		no1= atoi(argv[1]);
		//op= argv[2][0]; /// array notation
		op= *argv[2]; // *(400) == '+' // pointer noatation

		no2= atoi(argv[3]);

		switch(op)
		{
			case '+' : ans= no1 + no2;break;
			case '-' : ans= no1 - no2;break;
			case '*' : ans= no1 * no2;break;
			case '/' : ans= no1 / no2;break;
		}
		printf("\n %d %c %d =%d ", no1, op, no2, ans);
	}
	return 0;
}

