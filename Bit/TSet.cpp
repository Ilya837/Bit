#include "TSet.h"

TSet::TSet(uint size)
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

istream& operator >> (istream& in, TSet& ts)
{
    int temp;
    char ch;
    for (int i = 0; i < ts.GetMaxPower(); i++) {
        ts.DelElement(i);
    }
    do {
        in >> ch;
    } while (ch != '{');
    in >> temp;
    ts.InsElement(temp);
    do {
        do {
            in >> ch;
        } while ((ch != ',') && (ch != '}'));
        if(ch == ',') in >> temp;        
        ts.InsElement(temp);
    } while (ch != '}');

    return in;

}// ������ ����� : 

ostream& operator << (ostream& out, TSet& ts)
{
    int a = ts.GetMaxPower() ;
    out << '{';

    int i = 0;
    while (i < a) {
        if (ts.IsMemper(i)) {
            out << i;
            break;
        }
        i++;
    }
    i++;
    while (i < a) {
        if (ts.IsMemper(i)) out << ',' << i;
        i++;
    }

    out << '}';

    return out;
}
