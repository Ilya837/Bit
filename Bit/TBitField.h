#pragma once

#include <iostream>
#include <assert.h>
#include <bitset>
#include <string>

typedef unsigned int uint;

using namespace std;

class TBitField
{
private:
	uint BitLen;
	uint MemLen;
	uint* pMem;
	uint GetMemIndex(const uint n) const; // Возвращает номер байта по номеру бита
	uint GetMemMask(const uint n) const; 
public:
	TBitField();
	TBitField(uint len );
	TBitField(const TBitField& bf);
	~TBitField();
	uint GetLength()const; // размер в битах
	void SetBit(const int n, bool num); // изменяет значение бита
	uint GetBit(const int n) const; // Выдаёт значение бита
	bool operator == (const TBitField& bf) const; 
	TBitField& operator = (const TBitField& bf);
	TBitField operator & (const TBitField& bf) const;
	TBitField operator | (const TBitField& bf) const;
	TBitField operator ~();
	//friend istream& operator >> (istream& in, TBitField& bf);
	friend ostream& operator << (ostream& out, TBitField& bf);
};

