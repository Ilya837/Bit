#include <iostream>
#include "TBitField.h"
#include "TSet.h"
int main()
{
	string str = "100010";
	bitset<sizeof(str)> a(str);
	int b = 0;
	TSet k = (TSet)b;

	
}