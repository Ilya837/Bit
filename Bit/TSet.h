#pragma once

#include "TBitField.h"
#include <math.h>

class TSet
{
private:
	int MaxPower;
	TBitField BitField;
public:
	TSet(int size);
	TSet(const TSet& set);
	TSet(const TBitField& tb);

	operator TBitField();

	int GetMaxPower();
	void InsElement(const int n);
	void DelElement(const int n);
	bool IsMemper(const int n);

	bool operator ==(const TSet& ts);
	TSet& operator =(const TSet& ts);
	TSet operator+ (const int n) const;
	TSet operator- (const int n) const;
	TSet operator| (const TSet& n) const;
	TSet operator& (const TSet& n) const;
	TSet operator~ ();

	friend istream& operator << (istream& in, TSet& ts);
	friend ostream& operator >> (ostream& out, TSet& ts);

};