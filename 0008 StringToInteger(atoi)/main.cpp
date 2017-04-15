/*
 * By	: Alisa
 * Date	: 15-07-24
 *
 * Requirements for atoi:
 * The function first discards as many whitespace characters as necessary until the first non-whitespace character is found.
 * Then, starting from this character,
 * takes an optional initial plus or minus sign followed by as many numerical digits as possible,
 * and interprets them as a numerical value.
 *
 * The string can contain additional characters after those that form the integral number,
 * which are ignored and have no effect on the behavior of this function.
 *
 * If the first sequence of non-whitespace characters in str is not a valid integral number,
 * or if no such sequence exists because either str is empty or it contains only whitespace characters,
 * no conversion is performed.
 *
 * If no valid conversion could be performed, a zero value is returned.
 * If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int i = 0, minus = 0, dangerous = 0;
		long long ret = 0;

		if (str.size() == 0) return 0;

		while (str[i] == ' ') ++i;

		if (str[i] == '-') minus = 1;
		else if (str[i] == '+') ++i;

		// 削掉越long long界的
		int j = i;
		while (j < str.size() && str[j] <= '9' && str[j] >= '0') ++j;
		if (j - i > 18) //9223372036854775807 long long (正)上限
			if (minus) return 0x80000000;
			else return 0x7fffffff;

		for (i+=minus; i<str.size(); ++i)
		{
			int tmp = str[i] - '0';
			if (tmp > 9 || tmp < 0) break;	// 不转换后面的
			ret = ret * 10 + tmp;
		}

		if (minus) ret = ret>0 ? -ret :  ret;	// 正负号
		else       ret = ret>0 ?  ret : -ret;

		if (ret < 0 && (long)ret < -2147483648)	// 越int界的
			return 0x80000000;
		else if (ret > 0 && ret > 0x7fffffff)
			return 0x7fffffff;
		else return ret;
    }
};

int main()
{
	Solution S;
	string SS [] = {"",
					"           123aaaaaaaawwwwwwwwew3", // 123
					"-123",
					"2147483647",
					"2147483648", // 0x7fffffff
					"+-2", // 0
					"-2147483648", // 0x80000000
					"-2147483649", // 0x80000000
					"2147483649", // 0x7fffffff
					"01",
					"  -  0001",
					"9223372036854775809", // 0x7fffffff
					"18446744073709551617" // 0x7fffffff
					};

	for (int i=0; i<13; ++i)
		cout << SS[i] << ": " << S.myAtoi(SS[i]) << endl;
	return 0;
}