#include <iostream>
#include "TBitField.h"
#include "TSet.h"
int main()
{
	TBitField bit(33);
	bit.SetBit(31,1);
	bit.SetBit(25, 1);
	bit.SetBit(26, 1);
	bit.SetBit(25, 0);
	bit.SetBit(32, 1);
	cout << bit << "\n";
	TBitField bit2(34);
	bit2 = TBitField(bit);
	TSet a(bit);
	cout << a;
}