#include <iostream>
#include "TBitField.h"
#include "TSet.h"
int main()
{
	size_t size;
	cin >> size;

	if (size <= 1) {
		cout << "{}";
		return 0;
	}

	TSet set(~(TBitField(size + 1)));
	set.DelElement(0);
	if(set.GetMaxPower() > 1)set.DelElement(1);
	for (size_t i = 2; i * i <= size; i++) {
		if (set.IsMemper(i)) {
			for (size_t j = i * i; j <= size; j += i) {
				set.DelElement(j);
			}
		}
	}

	cout << set << endl;
}