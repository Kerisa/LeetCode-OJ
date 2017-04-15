/*
 * By	: Alisa
 * Date	: 15-08-04
 *
 * Implement pow(x, n).
 */

#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (!n) return 1;
        if (1 == n) return x;
       
		double ret = n>0 ? myPow(x, n/2) : myPow(1/x, -(n/2));
		return ret * ret * (n%2 ? (n>0 ? x: 1/x) : 1);
    }
};

int main()
{
	Solution S;
	cout << S.myPow(34.00515, -3) << endl;
	cout << S.myPow(3, 3) << endl;
	cout << S.myPow(3, -3) << endl;
	cout << S.myPow(3, -2) << endl;
	cout << S.myPow(3, 2) << endl;
	cout << S.myPow(0.00001, 2147483647) << endl;

	return 0;
}