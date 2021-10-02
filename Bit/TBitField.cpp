#include "TBitField.h"

uint TBitField::GetMemIndex(const uint n) const
{
	return n / (sizeof(uint) * 8);
}

uint TBitField::GetMemMask(const uint n) const 
{
	return 1 << (n % (sizeof(uint) * 8));
}

TBitField::TBitField() {
	BitLen = 1;
	MemLen = 1;
	pMem = new uint[MemLen];
	pMem[0] = 0;
}

TBitField::TBitField(uint len ): BitLen(len)
{
	assert(len > 0);

	MemLen = (len - 1) / 32 + 1;
	pMem = new uint[MemLen];
	for (int i = 0; i < MemLen; i++) pMem[i] = 0; 

}

TBitField::TBitField(const TBitField& bf)
{
	BitLen = bf.BitLen;
	MemLen = bf.MemLen;
	pMem = new uint[MemLen];
	for (int i = 0; i < MemLen; i++) pMem[i] = bf.pMem[i];
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
	

	pMem = new uint[BitLen];
	for (int i = 0; i < MemLen; i++) {
		pMem[i] = bf.pMem[i];
	}
	return *this;
}

TBitField TBitField::operator&(const TBitField& bf) const
{
	uint len = BitLen;
	if (len < bf.BitLen) len = bf.BitLen;

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
	uint len = BitLen;
	if (len < bf.BitLen) len = bf.BitLen;

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
	TBitField tbf(BitLen);
	for (int i = 0; i < MemLen; i++) {
		tbf.pMem[i] = ~(pMem[i]);
	}
	return tbf;
}

istream& operator>>(istream& in, TBitField& bf)
{
	int i = 0;
	string str;
	in >> str;
	bitset<sizeof(str)> bit(str);
	assert(bf.GetLength() >= str.size());
	

	for ( i = 0; i < sizeof(str); i++) {
		bf.SetBit(i, bit.test(i));
	}
	for (i ; i < bf.GetLength(); i++) {
		bf.SetBit(i, 0);
	}
	return in;
}

ostream& operator<<(ostream& out, TBitField& bf)
{
	for (int i = 0; i < bf.BitLen; i++) {
		out << bf.GetBit(i);
	}
	return out;
}
