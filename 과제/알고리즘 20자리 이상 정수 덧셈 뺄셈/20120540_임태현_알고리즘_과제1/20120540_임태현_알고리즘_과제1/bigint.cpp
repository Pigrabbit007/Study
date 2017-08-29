#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bigint.h"

void newnum(bigint* num)
{
	num->number = (digit*)malloc(1);
	num->number[0] = 0;
	num->length = 1;
}


//given a bigint that is _already_ allocated,
//and given a number string, allocate the bigint
void newnumf(bigint* num, char* numb)
{
	int numb1 = strlen(numb);
	digit* out = (digit*)malloc(numb1);
	for (int i = 0; i < numb1; i++)
	{
		out[i] = numb[i] - CHARZERO_ABOVEINTZERO;
	}
	num->number = out;
	num->length = numb1;
}


//this function allocates and returns a bigint pointer, with the number numb allocated
bigint* newnumc(char* numb)
{
	//allocate storage for the bigint
	bigint* num = (bigint*)malloc(sizeof(bigint));

	int numb1 = strlen(numb);
	int numb2 = numb1 - 1;
	//allocate storage for the number, in the right length
	digit* out = (digit*)malloc(numb1);
	for (int i = 0; i < numb1; i++)
	{
		out[i] = numb[numb2 - i] - CHARZERO_ABOVEINTZERO;
	}
	num->number = out;
	num->length = numb1;

	//return the new bigint
	return num;
}




//makes a deep copy of from, and put it in to
void numcpy(bigint* to, bigint* from)
{
	to->number = (digit*)realloc(to->number, from->length);

	//copy from's number into to's number
	int fl = from->length;
	digit* tn = to->number;
	digit* fn = from->number;
	for (int i = 0; i < fl; i++)
	{
		tn[i] = fn[i];
	}

	//copy from's length into two's length
	to->length = from->length;
}


//clear a bigint that was created by newnumc
void delnum(bigint* num)
{
	//free the bigint's number
	free(num->number);
	//free the bigint
	free(num);
}

//adds a to b, and stores the result in result
void add(bigint* a, bigint* b, bigint* result)
{
	//store the length of ac and bc
	int al = a->length;
	int bl = b->length;
	int length = al;
	if (bl > al) length = bl;

	//allocate storage for the length of the result
	int cl = length + 1;

	//allocate space for a and b's number
	digit* ac = a->number;
	digit* bc = b->number;
	//allocate space for the result
	digit* out = (digit*)malloc(cl);

	int temp = 0, carry = 0;
	for (int i = 0; i < length; i++)
	{
		if (i >= al) temp = bc[i] + carry;
		else if (i >= bl) temp = ac[i] + carry;
		else temp = ac[i] + bc[i] + carry;

		if (temp > 9)
		{
			carry = 1;
			temp -= 10;
		}
		else
		{
			carry = 0;
		}
		out[i] = temp;
	}

	//fix up the last digit of carry/the length of carry
	if (carry == 0)
	{
		out = (digit*)realloc(out, length);
		result->length = length;
	}
	else
	{
		out[length] = carry;
		result->length = cl;
	}

	result->number = out;
}

//print out a bigint's value
void print(bigint* num)
{
	digit* numc = num->number; //NOT A CHAR ARRAY
	int num1 = num->length;
	int num2 = num1 - 1;
	char* out = (char*)malloc(num1 + 1);
	for (int i = 0; i < num1; i++)
	{
		out[i] = numc[num2 - i] + CHARZERO_ABOVEINTZERO;
	}
	out[num1] = '\0';

	puts(out);
	free(out);
}