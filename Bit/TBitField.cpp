#include "TBitField.h"

uint TBitField::GetMemIndex(const uint n) const
{
	return n / (sizeof(uint) * 8);
}

uint TBitField::GetMemMask(const uint n) const 
{
	return 1 << (n % (sizeof(uint) * 8));
}

TBitField::TBitField(uint len = 1): BitLen(len)
{
	assert(len > 0);

	MemLen = (len - 1) / 32 + 1;
	pMem = new uint[MemLen];
	for (int i = 0; i < BitLen; i++) pMem[i] = 0;
}

TBitField::TBitField(const TBitField& bf)
{
	BitLen = bf.BitLen;
	MemLen = bf.MemLen;
	pMem = new uint(MemLen);
	for (int i = 0; i < BitLen; i++) pMem[i] = bf.pMem[i];
}

TBitField::~TBitField()
{
	delete[] pMem;
}

uint TBitField::GetLength() const
{
	return BitLen;
}

void TBitField::SetBit(const int n, bool num)
{
	if (num == 0) {
		pMem[GetMemIndex(n)] &= ~(GetMemMask(n));
	}
	else {
		pMem[GetMemIndex(n)] |= GetMemMask(n);
	}
}

uint TBitField::GetBit(const int n) const
{
	return (pMem[GetMemIndex(n)] & GetMemMask(n)) == 0 ? 0 : 1;
}

bool TBitField::operator==(const TBitField& bf) const
{
	if (bf.BitLen == BitLen) {
		for (int i = 0; i < MemLen;i++) {
			if (pMem[i] != bf.pMem[i]) return false;
		}
		return true;
	}
	return false;
}

TBitField& TBitField::operator=(const TBitField& bf)
{
	BitLen = bf.BitLen;
	MemLen = bf.MemLen;
	delete[] pMem;
	pMem = new uint[MemLen];
	for (int i = 0; i < MemLen; i++) {
		pMem[i] = bf.pMem[i];
	}
	return *this;
}

TBitField TBitField::operator&(const TBitField& bf) const
{
	uint len = MemLen;
	if (len < bf.MemLen) len = bf.MemLen;

	TBitField tbf(len);

	for (int i = 0; i < MemLen; i++) {
		tbf.pMem[i] = pMem[i];
	}

	for (int i = 0; i < bf.MemLen; i++) {
		tbf.pMem[i] &= bf.pMem[i];
	}
	
	return tbf;
}

TBitField TBitField::operator|(const TBitField& bf) const
{
	uint len = MemLen;
	if (len < bf.MemLen) len = bf.MemLen;

	TBitField tbf(len);

	for (int i = 0; i < MemLen; i++) {
		tbf.pMem[i] = pMem[i];
	}

	for (int i = 0; i < bf.MemLen; i++) {
		tbf.pMem[i] |= bf.pMem[i];
	}

	return tbf;
}

TBitField TBitField::operator~()
{
	TBitField tbf(MemLen);
	for (int i = 0; i < MemLen; i++) {
		tbf.pMem[i] = ~(pMem[i]);
	}
	return tbf;
}

/*istream& operator>>(istream& in, TBitField& bf)
{
	string str;
	in >> str;
	bitset<sizeof(str)> bit(str);
	
	for (int i = 0; i < sizeof(str); i++) {

	}
}*/

ostream& operator<<(ostream& out, TBitField& bf)
{
	for (int i = 0; i < bf.BitLen; i++) {
		out << bf.GetBit(i);
	}
	return out;
}
