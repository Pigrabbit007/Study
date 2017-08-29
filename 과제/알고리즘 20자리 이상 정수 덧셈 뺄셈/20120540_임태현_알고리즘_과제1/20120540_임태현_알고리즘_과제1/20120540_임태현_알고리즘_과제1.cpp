#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bigint.h"

void main(int argc, char** argv)
{
	char temp = 'a';


	//create 3 bigints: 2 for the summands, and one for the result
	bigint* a = newnumc("1");
	bigint* b = newnumc("1");
	bigint* c = newnumc("0");



	//clear a, b, and the result
	delnum(a);
	delnum(b);
	delnum(c);

}