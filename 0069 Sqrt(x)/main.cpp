/*
 * By	:Alisa
 * Date	: 15-08-04
 *
 * Implement int sqrt(int x).
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        unsigned int left = 0, right = x, m, pow;
		
		if (1 >= x) return x;

		while (left < right)
        {
			if ((m = (left + right) / 2) > 46340)
				m = right = 46340;		// (int)sqrt(0x7fffffff)

            pow = m * m;
            if (pow <= x)
			{
				unsigned int tmp = pow + 2 * m + 1;
				if (tmp > 0x7fffffff)	goto _NEXT;
				if (tmp > x)			return m;
				else if (tmp == x)		return m+1;
				else
_NEXT:									left = m;
			}
            else
				right = m;
		}
        return m;
    }
};

int main()
{
	Solution S;
	for (int i=0; i<126; ++i)
		cout << i << "\t" << S.mySqrt(i) << endl;
	cout << 0x7fffffff << "\t" << S.mySqrt(0x7fffffff) << endl;
	cout << 2147395599 << "\t" << S.mySqrt(2147395599) << endl;
	
	return 0;
}