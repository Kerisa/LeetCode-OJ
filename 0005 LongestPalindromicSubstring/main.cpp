/*
 * By	: Alisa
 * Date	: 15-07-23
 *
 * Given a string S, find the longest palindromic substring in S.
 * You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 */
 
#include <iostream>
#include <string>

using namespace std;

class Solution {
	struct RECORD
	{
		int begin;
		int len;
	};
public:	// 8ms Version
    string longestPalindrome(string s)
	{
		int len = s.size();
		struct RECORD ret = {0, 0}; 
		int l = 0, r = 0;
        for (int i=0; i<len;)
		{
			l = i - 1;	// 判断的左起始
			while (i >= 0 && i < len-1 && s[i] == s[i+1]) ++i;	// 略过相同的字符
			++i;
			r = i;	// 右起始
			while (l >= 0 && r < len && s[l] == s[r])
			{
				--l;
				++r;
			}
			
			if (r - l - 1 > ret.len)
			{
				ret.begin = l + 1;
				ret.len   = r - l - 1;
			}
		}
		
		return s.substr(ret.begin, ret.len);
    }
};

int main()
{
	Solution S;
	string SS[] = {	"1234565344356",
					"cc",
					"aabcde",
					"asdwqeqwdkaopdmqwepofd",
					"abcdefgfedb",
					"z",
					"aba",
					"plas,ddflplfeveflpl"};

	for (int i=0; i<8; ++i)
		cout << "case " << i << ": " << S.longestPalindrome(SS[i]) << endl;

	return 0;
}

/* 56ms Version
class Solution {
	struct RECORD
	{
		int begin;
		int end;
	};
public:
    string longestPalindrome(string s)
	{
		int len = s.size();
		struct RECORD ret = {0, 0}; 
        for (int i=1; i<len; ++i)
		{
			if (s[i] == s[i-1])
			{
				int j, k;
				for (j=i-2, k=i+1; j>=0 && k<len; --j, ++k)
				{
					if (s[j] == s[k]) continue;
					break;
				}
				if (k - j - 2 > ret.end - ret.begin)
				{
					ret.begin = j + 1;
					ret.end   = k - 1;
				}
			}
			if (i>1 && s[i] == s[i-2])
			{
				int j, k;
				for (j=i-3, k=i+1; j>=0 && k<len; --j, ++k)
				{
					if (s[j] == s[k]) continue;
					break;
				}
				if (k - j - 2 > ret.end - ret.begin)
				{
					ret.begin = j + 1;
					ret.end   = k - 1;
				}
			}
		}
		if (ret.end == len - 1)
		{
			string re(s.begin()+ret.begin, s.end());
			return re;
		}
		else
		{
			string re(&s[ret.begin], &s[ret.end+1]);
			return re;
		}
    }
};
*/