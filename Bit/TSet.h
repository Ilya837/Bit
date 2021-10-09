#pragma once

#include "TBitField.h"
#include <math.h>
#include <string>

class TSet
{
private:
	uint MaxPower;
	TBitField BitField;
public:
	TSet(uint size = 1);
	TSet(const TSet& set);
	TSet(const TBitField& tb);

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

	friend istream& operator >> (istream& in, TSet& ts);
	friend ostream& operator << (ostream& out, TSet& ts);

};