/*
 * By	: Alisa
 * Date	: 15-07-24
 *
 * Determine whether an integer is a palindrome.
 * Do this without extra space.
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int h = 1000000000;
		if (x<0) return false;
		while (h>0 && x/h == 0) h /= 10;
		for (int l=1; l<h; h/=10, l*=10)
			if (x/h%10 != x/l%10) return false;
		return true;
    }
};

int main()
{
	Solution S;
	int d [] = {0, 1, 2, 12, 10, 11, 152, 151, 999, 36599563, -1, -1991};
	for (int i=sizeof(d)/sizeof(d[0])-1; i>=0; --i)
		cout << d[i] << "\t: " << (int)S.isPalindrome(d[i]) << endl;
	return 0;
}