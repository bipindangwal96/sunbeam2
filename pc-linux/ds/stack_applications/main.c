/*
 * main.c
 *
 *  Created on: 15-Sep-2019
 *      Author: sunbeam
 */


#include<stdio.h>
#include<string.h>

#include"stack.h"

void infix_to_postfix(char *infix, char *postfix);
void infix_to_prefix(char *infix, char *prefix);
int is_operand(char ch);
int priority(char opr);
void strrev(char *str);
int postfix_evaluation(char *post);
int calculate(int op1, int op2, char opr);


int main(void)
{
	//char infix[64] = "a+b*c/d*e/f+g-h";
	//char infix[64] = "4*5/6*8+9-2*6+3";
	char infix[64] = "45*20+120-100-15+5";
	//char infix[64] = "(a+b)*(c-d)/e*f+g-h";
	char postfix[64] = " ";
	//char prefix[64] = " ";

	printf("infix expression is: %s\n", infix);
	infix_to_postfix(infix, postfix);
	//infix_to_prefix(infix, prefix);

	printf("postfix expression is: %s\n", postfix);
	//printf("prefix expression is: %s\n", prefix);

	printf("result is: %d\n", postfix_evaluation(postfix));
	return 0;
}

int postfix_evaluation(char *post)
{
	int i;
	int res;
	stack_t s;
	init_stack(&s);

	//start scanning postfix string from left to right
	for( i = 0 ; post[i] != '\0' ; i++ )
	{
		//if the cur ele is an operand
		if( is_operand( post[i] ) )
		{
			//push it into the stack
			push_element(&s, post[i]-'0');
		}
		else//if the cur ele is an operator
		{
			//pop two ele's from the stack
			//first popped ele will be the second operand
			int op2 = peek_element(&s); pop_element(&s);
			//second  popped ele will be the first operand
			int op1 = peek_element(&s); pop_element(&s);
			//perform "post[i]" operation between them
			res = calculate(op1, op2, post[i]);
			//push the result into the stack
			push_element(&s, res);
		}
	}//end of for loop
	//pop the final result from the stack
	res = peek_element(&s); pop_element(&s);
	//return it to the calling function
	return res;
}

int calculate(int op1, int op2, char opr)
{
	switch(opr)
	{
	case '+': return ( op1 + op2 );
	case '-': return ( op1 - op2 );
	case '*': return ( op1 * op2 );
	case '/': return ( op1 / op2 );
	case '%': return ( op1 % op2 );
	}
}

int priority(char opr)
{
	switch(opr)
	{
	case '(': return 0;

	case '+':
	case '-': return 1;

	case '*':
	case '/':
	case '%': return 3;
	}
}

void strrev(char *str)
{
	char *left = str;
	char *right = str;

	while( *right )
		right++;

	right--;

	while( left <= right )
	{
		char t = *left;
		*left = *right;
		*right = t;

		left++;
		right--;
	}
}

void infix_to_prefix(char *in, char *pre)
{
	int i;
	int j=0;
	stack_t s;

	init_stack(&s);

	//start scanning infix expression from right to left
	for( i = strlen(in)-1 ;  i >= 0 ; i-- )
	{
		//if the cur ele is an operand
		if( is_operand(in[i]) )
		{
			//- append it into the prefix string
			pre[j++] = in[i];
		}
		else//if the cur ele is an operator
		{
			//if stack is not empty && priority(topmost) ele > priority(cur ele)
			while( !is_stack_empty(&s) &&  priority( peek_element(&s) ) > priority(in[i]) )
			{
				//pop ele from the stack and append it into the prefix string
				pre[j++] = peek_element(&s);
				pop_element(&s);
			}
			//push cur ele into the stack
			push_element(&s, in[i]);
		}
	}//end of for loop

	//while stack not becomes empty pop ele's one by one and append them into the prefix string
	while( !is_stack_empty(&s))
	{
		pre[j++] = peek_element(&s);
		pop_element(&s);
	}

	pre[j] = '\0';

	printf("prefix exp: %s\n", pre);
	strrev(pre);
}

void infix_to_postfix(char *in, char *post)
{
	int i;
	int j=0;
	stack_t s;
	init_stack(&s);

	//start scanning infix expression  from left to right
	for( i = 0 ; in[i] != '\0' ; i++ )
	{
		//if the cur ele is an operand
		if( is_operand(in[i]) )
		{
			//append it into the postfix string
			post[j++] = in[i];
		}
		else
		if( in[i] == '(' )//if the cur ele is an opening brace
		{
			//push it into the stack
			push_element(&s, in[i]);
		}
		else
		if( in[i] == ')' )//if the cur ele is a closing brace
		{
			//pop the ele's from the stack till its corresponding opening brace do not occurs
			//and append them into the postfix string
			while( peek_element(&s) != '(' )
			{
				post[j++] = peek_element(&s);
				pop_element(&s);
			}

			//pop opening brace from the stack
			pop_element(&s);
		}
		else//if the cur ele is an operator
		{
			//if stack is not empty && priority(topmost) ele >= priority(cur ele)
			while( !is_stack_empty(&s) &&  priority( peek_element(&s)) >= priority(in[i]) )
			{
				//pop ele from the stack and append it into the postfix string
				post[j++] = peek_element(&s);
				pop_element(&s);
			}
			//push cur ele into the stack
			push_element(&s, in[i]);
		}
	}//end of for loop

	//while stack not becomes empty pop ele's one by one and append them into the postfix string
	while( !is_stack_empty(&s))
	{
		post[j++] = peek_element(&s);
		pop_element(&s);
	}
	post[j] = '\0';
}

/*
void infix_to_postfix(char *in, char *post)
{
	int i;
	int j=0;
	stack_t s;
	init_stack(&s);

	//start scanning infix expression  from left to right
	for( i = 0 ; in[i] != '\0' ; i++ )
	{
		//if the cur ele is an operand
		if( is_operand(in[i]) )
		{
			//- append it into the postfix string
			post[j++] = in[i];
		}
		else//if the cur ele is an operator
		{
			//if stack is not empty && priority(topmost) ele >= priority(cur ele)
			while( !is_stack_empty(&s) &&  priority( peek_element(&s)) >= priority(in[i]) )
			{
				//pop ele from the stack and append it into the postfix string
				post[j++] = peek_element(&s);
				pop_element(&s);
			}
			//push cur ele into the stack
			push_element(&s, in[i]);
		}
	}//end of for loop

	//while stack not becomes empty pop ele's one by one and append them into the postfix string
	while( !is_stack_empty(&s))
	{
		post[j++] = peek_element(&s);
		pop_element(&s);
	}
	post[j] = '\0';
}
*/

int is_operand(char ch)
{
	return ( ( ch >= 48 && ch <= 57 ) || ( ch >= 65 && ch <= 90 ) || ( ch >= 97 && ch <= 122 ) );
}










