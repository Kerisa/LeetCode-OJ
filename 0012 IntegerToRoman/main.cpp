/*
 * By	: Alisa
 * Date	: 15-08-05
 *
 * Given an integer, convert it to a roman numeral.
 * Input is guaranteed to be within the range from 1 to 3999.
 * I（1）、V（5）、X（10）、L（50）、C（100）、D（500）、M（1000）
 * 清楚规则就行
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
    inline void Add(string &s, char c, int times)
    {
        for (int i=0; i<times; ++i)
            s.push_back(c);
    }
    inline void Match(string &s, int n, char c1, char c2, char c3)
    {
        switch (n)
        {
        case 1:
        case 2:
        case 3:
            Add(s, c1, n);
            break;
            
        case 4:
        case 5:
            Add(s, c1, 5-n);
            Add(s, c2, 1);
            break;
            
        case 6:
        case 7:
        case 8:
            Add(s, c2, 1);
            Add(s, c1, n-5);
            break;
            
        case 9:
            Add(s, c1, 1);
            Add(s, c3, 1);
            break;
        }
        return;
    }
public:
    string intToRoman(int num) {
        string s;
        
        Match(s, num/1000, 'M', 0, 0);
        Match(s, num/100%10, 'C', 'D', 'M');
        Match(s, num/10%10, 'X', 'L', 'C');
        Match(s, num%10, 'I', 'V', 'X');

        return s;
    }
};

int main()
{
	Solution S;
	for (int i=400; i<500; i+=3)
		cout << i << ":\t" << S.intToRoman(i) << "\n";
	return 0;
}