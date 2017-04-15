/*
 * By	: Alisa
 * Date	: 15-07-24
 *
 *	Reverse digits of an integer.
 *
 *	Example1: x = 123, return 321
 *	Example2: x = -123, return -321
 *
 *	Have you thought about this?
 *	Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
 *
 *	If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
 *
 *	Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
 *
 *	For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 *
 *	Update (2014-11-10):
 *	Test cases had been added to test the overflow behavior.
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long ret = 0;
		while (x)
		{
			ret = ret * 10 + x % 10;
			x /= 10;
		}
		// еп╤от╫╫Г
		if (ret < 0 && ret < -2147483648 ||											// 2: < -2147483648
			ret > 0 && (unsigned long long)ret > (unsigned long long)0x7fffffff)	// 1: 0x7f...
			return 0;
		else return ret;
    }
};

int main()
{
	Solution S;
	int A[] = {123, -123, 0, 10, 100, -100, 1534236469, 116233, 1999999966, 101, 2000, 4294967293, 4294967295, -2147483648, 1563847412};

	for (int i=sizeof(A)/sizeof(A[0])-1; i>=0; --i)
		cout << A[i] << ":" << S.reverse(A[i]) << endl;

	return 0;
}