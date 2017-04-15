/*
 * By	: Alisa
 * Date	: 15-07-26
 *
 * Implement wildcard pattern matching with support for '?' and '*'.
 *
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 *
 * The matching should cover the entire input string (not partial).
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
		// 将2维数组压至两个一维的
		// 结果好像还是差不多
		vector<bool> pre(p.size()+1,0);
	
		pre[0]=1;
		for(int j=1; j<=p.size(); j++)
			pre[j] = pre[j-1] && p[j-1]=='*';
	
		for(int i=1; i<=s.size(); i++)
		{
			vector<bool> now(p.size()+1,0);

			for(int j=1; j<=p.size(); j++)
			{
				if(p[j-1]=='*')	// 这题的区别就是*可以替代任何字符，不限相同的字符 撸个正则表达式什么的....
				{
					now[j] = now[j-1] || pre[j];
				}
				else
				{
					now[j] = pre[j-1] && (s[i-1]==p[j-1] || p[j-1]=='?');
				}
			}
			pre = now;
		}
		return pre[p.size()];
    }
};

int main()
{
	Solution S;
	cout << S.isMatch("abcdbcb", "a*") << endl;
	cout << S.isMatch("abcdbcb", "a*bcd*") << endl;
	cout << S.isMatch("abefcdgiescdfimde", "ab*cd?i*de") << endl;
	cout << S.isMatch("", "") << endl;
	cout << S.isMatch("", "*") << endl;
	cout << S.isMatch("", "a") << endl;			 // f
	cout << S.isMatch("aa", "a") << endl;		 // f
	cout << S.isMatch("aa", "aa") << endl;
	cout << S.isMatch("aaa", "aa") << endl;		 // f
	cout << S.isMatch("aa", "*") << endl;
	cout << S.isMatch("ab", "a*") << endl;
	cout << S.isMatch("aab", "?*") << endl;
	cout << S.isMatch("aabbbb", "*a*b") << endl;
	cout << S.isMatch("aabbbbc", "*a*b") << endl; // f
	cout << S.isMatch("aabbbbc", "*a*bc") << endl;
	return 0;
}

/* 1st Ver.

bool isMatch(string s, string p)
{
    vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, 0));
        
    dp[0][0] = 1;
    for (int i=1; i<=p.size(); ++i)
		dp[0][i] = dp[0][i-1] && p[i-1] == '*';
		
		
	for (int j=1; j<=p.size(); ++j)
	{
		bool first = 1;
		for (int i=1; i<=s.size(); ++i)
		//if (p[j-1] != '*')
		//	dp[i][j] = dp[i-1][j-1] && (p[j-1] == s[i-1] || p[j-1] == '?');
		//else if (dp[i-1][j-1] || dp[i][j-1])
		//{
		//	for (int k=i; k<=s.size(); ++k)
		//		dp[k][j] = 1;
		//	break;
		//}
		//else dp[i][j] = 0;	

			if (p[j-1] != '*')
				dp[i][j] = dp[i-1][j-1] && (p[j-1] == s[i-1] || p[j-1] == '?');
			else
			{
				if ((dp[i][j] = j>1 && dp[i][j-1]) == 1)
					continue;							
				if (dp[i-1][j-1])
				{
					for (int k=i; k<=s.size(); ++k)
						dp[k][j] = 1;
					break;
				}
				else dp[i][j] = 0;
			}
		
	}
	return dp[s.size()][p.size()];
}
*/

/*  超时
class Solution {
	bool recursion(const string & s, const string & p, int beg_s, int beg_p)
	{
		int i = beg_s, j = beg_p;
		while (j<p.size())
		{
			if (p[j] != '*')
			{
				if (s[i] == p[j] || p[j] == '?')
				{
					++i; ++j;
					if (j==p.size() && i==s.size())
						return true;
					continue;
				}
				else return false;
			}
			else
			{
				if (j == p.size()-1) return true;
				for (int k=i; k<s.size(); ++k)
					if (recursion(s, p, k, j+1))
						return true;
				return false;
			}
		}
		return false;
	}
public:
    bool isMatch(string s, string p) {
		if (!s.compare(p)) return true;
		return recursion(s, p, 0, 0);
		
    }
};
*/

/*
bool isMatch(string s, string p)
	{
		int re_s = 0, re_p = 0;
		int i = 0, j = 0;
		while(i<s.size() && j<p.size())
		{
			if (i<s.size() && j<p.size() && (s[i] == p[j] || p[j] == '?'))
			{
				++i; ++j;
				continue;
			}
			if (p[j] == '*')
			{
				re_s = i;
				re_p = j++;
				if (j == p.size()) return true;
				continue;
			}
			if (re_p < p.size())
			{
				i = ++re_s;
				j = re_p + 1;
				continue;
			}
			return false;
		}
		
		while (j<p.size() && p[j] == '*')
			++j;
		return i == s.size() && j == p.size();
	}
*/