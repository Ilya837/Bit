#include "TSet.h"

TSet::TSet(int size)
{
    MaxPower = size;
    BitField = TBitField(size);
}

TSet::TSet(const TSet& set)
{
    MaxPower = set.MaxPower;
    BitField = TBitField(set.BitField);
}

TSet::TSet(const TBitField& tb)
{
    MaxPower = tb.GetLength();
    BitField = TBitField(tb);
}

TSet::operator TBitField()
{
    TBitField tmp(this->BitField);
    return tmp;
}

int TSet::GetMaxPower()
{
    return MaxPower;
}

void TSet::InsElement(const int n)
{
    BitField.SetBit(n, 1);
}

void TSet::DelElement(const int n)
{
    BitField.SetBit(n, 0);
}

bool TSet::IsMemper(const int n)
{
    return BitField.GetBit(n) == 0 ? false : true;
    
}

bool TSet::operator==(const TSet& ts)
{
    return false;
}

TSet& TSet::operator=(const TSet& ts)
{
    MaxPower = ts.MaxPower;
    BitField = TBitField(ts.BitField);
    return *this;
}

TSet TSet::operator+(const int n) const
{
    TSet tmp(MaxPower);
    tmp.BitField.SetBit(n,1);
    return tmp;
}

TSet TSet::operator-(const int n) const
{
    TSet tmp(MaxPower);
    tmp.BitField.SetBit(n, 0);
    return tmp;
}

TSet TSet::operator|(const TSet& n) const
{
    TSet tmp(max(MaxPower,n.MaxPower));
    tmp.BitField = BitField | n.BitField;
    return tmp;
}

TSet TSet::operator&(const TSet& n) const
{
    TSet tmp(max(MaxPower, n.MaxPower));
    tmp.BitField = BitField & n.BitField;
    return tmp;
}

TSet TSet::operator~()
{
    TSet tmp(MaxPower);
    tmp.BitField = ~BitField;
    return tmp;
}

istream& operator<<(istream& in, TSet& ts)
{
    int temp;
    char ch;
    do {
        in >> ch;
    } while (ch != '{');
    in >> temp;
    ts.InsElement(temp);
    do {
        do {
            in >> ch;
        } while ((ch != ',') && (ch != '}'));
    } while (ch != '}');

    return in;

}// Формат ввода : 

ostream& operator>>(ostream& out, TSet& ts)
{
    int a = ts.MaxPower - 1;
    int i;
    out << '{';
    for ( i = 0; i < a; i++) {
        if (ts.IsMemper(i)) {
            out << i << ',';
        }
    }

    if (ts.IsMemper(i)) {
        out << i ;
    }
    else {
        out.
    }

    out << '}';

    return out;
}
