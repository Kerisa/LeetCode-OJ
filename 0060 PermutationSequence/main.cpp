/*
 * By	: Alisa
 * Date	: 15-08-04
 *
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 * "123" "132" "213" "231" "312" "321"
 * Given n and k, return the kth permutation sequence.
 * Note: Given n will be between 1 and 9 inclusive.
 */

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        static const unsigned int fact[11] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
        string ret;
        bool used[10] = {0};
		used[0] = true;
        
        for (int i=0; k && n; --n)	// i代表要添加到串中的数字
        {
            if (fact[n-1] > k)	// 直接添加k之后的组合（即相对这个k不变化的数）
            {
				i = 1;
                while (used[i]) ++i;
				ret.push_back('0' + i);
                used[i] = true;	// 现在i之前的都是“用过的”，不用重置i
            }
            else
            {
				int c;	// c记录要跳过未使用的数字的个数
                for (c=1; fact[n-1]*c<k; ++c);
				k -= (c-1)*fact[n-1];
				
                while (c)
				{
					++i;
					if (!used[i]) --c;
				}
				ret.push_back('0' + i);
                used[i] = true;
				i = 0;	// 下次要从头搜起
            }
        }
		return ret;
    }
};
int main()
{
	Solution S;
	cout << S.getPermutation(2, 2) << endl;
	for (int i=1; i<7; ++i)
		cout << S.getPermutation(3, i) << endl;
	cout << S.getPermutation(7, 100) << endl;
	cout << S.getPermutation(7, 101) << endl;
	return 0;
}