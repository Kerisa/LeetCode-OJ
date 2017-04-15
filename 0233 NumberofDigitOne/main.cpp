/*
 * By	: Alisa
 * Date	: 15-08-04
 *
 * Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
 *
 * For example: Given n = 13,
 * Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 */

#include <iostream>
using namespace std;
class Solution {
    int CountNext(int n,	// ����n
				  int c,	// 10^n��λ��
				  int w)	// n��λ��
    {
		// Sum[i]����i-1λ���ֵ�����1����֮�ͣ�����iλ��ʱֱ�Ӳ����
		static const long long Sum [11] = {0, 0, 1, 20, 300, 4000, 50000, 600000, 7000000, 80000000, 900000000};
        int ret = 0;
		if (!n || !c) return 0;

		if (!(n/c)) return CountNext(n%c, c/10, w-1);	// ���������м��0

        if (n / 100)   // ��λ������
        {
			// �������λ���ּ��ϲ�ͬ������1
			if (n/c > 1)	ret = Sum[w] * (n/c) + c;
			else			ret = Sum[w] + n%c+1;

			// ͳ�Ƴ�ȥ���λ���ʣ�ಿ��
			ret += CountNext(n%c, c/10, w-1);
        }
		else	// ��λ��������ֱ�ӷ��ؽ��
		{
			if (n / 10 > 1)
				ret = (n/10-1) + 11 + (n%10 ? 1 : 0);

			else if (n / 10 == 1)
				ret = n%10 ? (n%10)+3 : 2;

			else ret = n%10 ? 1 : 0;
		}
        return ret;
    }
public:
    int countDigitOne(int n) {
		if (n <= 0) return 0;	// ��������ĸ���...
        int c = 1000000000, i = 10;
		while (c && n / c == 0) {c /= 10; --i;}
        
        return CountNext(n, c, i);
    }
};

int main()
{
	Solution S;
	cout << S.countDigitOne(-1) << endl;
	cout << S.countDigitOne(10065408) << endl;
	cout << S.countDigitOne(65408) << endl;
	cout << S.countDigitOne(1410065408) << endl;
	cout << S.countDigitOne(1001) << endl;
	cout << S.countDigitOne(8) << endl;
	cout << S.countDigitOne(408) << endl;
	cout << S.countDigitOne(5408) << endl;
	return 0;
}