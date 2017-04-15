/*
 * By	: Alisa
 * Date	: 15-07-23
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 * (you may want to display this pattern in a fixed font for better legibility)
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */
 
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
		if (numRows == 1 || s.size() <= numRows) return s;
		
        int step0 = 2 * numRows - 2;
		int step = step0;
		int len = s.size();
		int idx = 0;
		string ret;
		while (idx < len)	// 第一排和最后一排跨度都是step0
		{
			ret.push_back(s[idx]);
			idx += step;
		}
		for (int i=1; i<numRows-1; ++i)	// 中间部分有两个不同的跨度
		{
			idx = i;
			step = step0 - i * 2;
			while (idx < len)
			{
				ret.push_back(s[idx]);
				idx += step;
				step = step0 - step;
			}
		}
		idx = step0 / 2;
		while (idx < len)	// 最后一排锯齿
		{
			ret.push_back(s[idx]);
			idx += step0;
		}
		return ret;
    }
};

int main()
{
	Solution S;
	string SS[] = {	"abcdefghijklmnopqrst",
					"1234565344356",
					"cc",
					"aabcde",
					"asdwqeqwdkaopdmqwepofd",
					"abcdefgfedb",
					"z",
					"aba",
					"plas,ddflplfeveflpl"};

	for (int i=0; i<9; ++i)
	{
		for (int j=10; j<12; ++j)
			cout << "case " << i << ": " << S.convert(SS[i], j) << endl;
		cout << "**********************************\n";
	}

	return 0;
}