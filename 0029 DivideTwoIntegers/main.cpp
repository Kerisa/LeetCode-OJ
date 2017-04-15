/*
 * By	: Alisa
 * Date	: 15-08-04
 *
 * Divide two integers without using multiplication, division and mod operator.
 * If it is overflow, return MAX_INT.
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || dividend == 0x80000000 && divisor == -1)
            return 0x7fffffff;
        
        int minus = dividend & 0x80000000 ^ divisor & 0x80000000;
        int ret = 0;
        
        unsigned int D = dividend < 0 ? -dividend : dividend;
        unsigned int d = divisor < 0 ? -divisor : divisor;
        
        for (int  i=31; i>=0; --i) // 竖式除法的二进制版
        {
            if (D >> i >= d)
            {
                ret <<= 1;
                ++ret;
				D -= d << i;
            }
            else ret <<= 1;
        }
        
        if (minus) ret = -ret;
        return ret;
    }
};

int main()
{
	Solution S;
	cout << S.divide(-1, 1) << endl;
	return 0;
}