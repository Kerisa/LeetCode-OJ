/*
 * By	: Alisa
 * Date	: 15-07-22
 *
 * Given a string, find the length of the longest substring without repeating characters. For example, the longest substring 
 * without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the 
 * length of 1.
 */
 
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
	{
		int flag[256];
		int len_t = 0, last_beg = 0, ret = 0;
		int size = s.size();

		memset(flag, -1, sizeof(flag)); // flag[x] 记录 x 上次出现的位置
		for (int i=0; i<size; ++i)
		{
			if (-1 == flag[s[i]])
			{
				++len_t;
				flag[s[i]] = i;
			}
			else
			{	// 字串中含有重复字母
				if (last_beg <= flag[s[i]])
				{
					len_t = i - flag[s[i]];
					last_beg = flag[s[i]] + 1;
				}
				else // 不含
					++len_t;
				flag[s[i]] = i;
			}
		
			if (len_t > ret)
				ret = len_t;
		}
		return ret;
    }
};

int main()
{
	Solution S;
	string T[7] = {	"akjsdihfowueoqw",//12 akjsdihfowue   akjsdihf owue oq w   akjsdihf o w ue oq w  akjsdihf o w ue o q w
					"aladmiwqjiweqmokl",//9 jiweqmokl
					"llappwqpwkq9u21i34n2mwf sd ",//12  ll ap pwq p wk q 9u 2 1i34n 2 mwf sd 
					"palpqwekqmkedsakmlk",//7   p al p q we k q m k edsa k ml k
					"xxxxxxxxaaaxxxxx",//2
					"abcdefghijklmnopqrstuvwxyz.,1234567890",//38
					"z"};

	for (int i=0; i<7; ++i)
		cout << S.lengthOfLongestSubstring(T[i]) << endl;
	return 0;
}
