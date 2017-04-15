/*
 * By	: Alisa
 * Date	: 15-07-24
 *
 * Implement regular expression matching with support for '.' and '*'.
 *
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
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
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, 0));

		dp[0][0] = 1;	// dp[i][j]代表s[0,i)与p[0,j)匹配, dp中的i j对应s/p中的i-1 j-1
		for (int i=1; i<=p.size(); ++i)	// 初始化与空串匹配的结果
			if (p[i-1] != '*')
				dp[0][i] = 0;			// a*b*d*g
			else dp[0][i] = dp[0][i-2];	// a*b*d*g*

		for (int i=1; i<=s.size(); ++i)
			for (int j=1; j<=p.size(); ++j)
				if (p[j-1] != '*')
					dp[i][j] = dp[i-1][j-1] && (p[j-1] == '.' || p[j-1] == s[i-1]);
				else
					dp[i][j] =	dp[i][j-2] ||	// *作为0略过 abc : abd*c
								dp[i-1][j] && (p[j-2] == s[i-1] || p[j-2] == '.');	// *替换的字符数大于等于1
		return dp[s.size()][p.size()];
    }
};

int main()
{
	Solution S;

	cout << S.isMatch("ab", ".*..") << endl;	
	cout << S.isMatch("a", "ab*a") << endl;		// f
	cout << S.isMatch("cb", "a*cb") << endl;
	cout << S.isMatch("a", "aa") << endl;		// f
	cout << S.isMatch("a", "ab*") << endl;	
	cout << S.isMatch("aa","a") << endl;	// f
	cout << S.isMatch("aa","aa") << endl;
	cout << S.isMatch("aaa","aa") << endl;	// f
	cout << S.isMatch("aa", "a*") << endl;
	cout << S.isMatch("aa", ".*") << endl;
	cout << S.isMatch("ab", ".*") << endl;	// <=> ".." -> "ab"
	cout << S.isMatch("aab", "c*a*b") << endl;
	cout << S.isMatch("aaaacb", "a*acb") << endl;	
	cout << S.isMatch("aaaacb", "a*a.b") << endl;	
	cout << S.isMatch("aaaacb", "a*.b") << endl;	// ?
	cout << S.isMatch("aaaacb", "a*ab") << endl;	// f
	cout << S.isMatch("aaaaaaaaa", "a*") << endl;
	cout << S.isMatch("a", "a*") << endl;			
	cout << S.isMatch("aaaaaaaab", "c*aa*b") << endl;
	cout << S.isMatch("aaaaaaaab", "c*aa*c") << endl;	// f
	cout << S.isMatch("aaaaaaaab", "c*aa*ab") << endl;	
	cout << S.isMatch("ab", ".*b") << endl;				
	cout << S.isMatch("aaa", "ab*a") << endl;	// f
		
	return 0;
}