/*
 * By	: Alisa
 * Date	: 15-07-25
 *
 * Validate if a given string is numeric.
 *
 * Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
	inline bool isdig(char c)
	{
		return (c >= '0' && c <= '9');
	}
public:
    bool isNumber(string s)
	// ���ʽ��ž��ǣ� [�ո�][����] [[��]] (��) �� (��)[e][[����]][-��-][�ո�]
	//                                ��    ��       ��        ��      ��
	//                   ���п��ޣ����ڵ��  ֻ��һ��       ����e  ��e��һ��������
	
	// {digit}+(\.{digit}+)?([Ee][+-]?{digit}+)?
	{
        int point = 0;
		int E = 0;
        int first = 0;
        
        if (s.size() == 0) return false;
        
        while (first < s.size() && s[first] == ' ') ++first;					// ǰ���ո�
		if (first < s.size() && (s[first] == '+' || s[first] == '-')) ++first;	// ����
		
		if (first >= s.size()) return false;

		for (int i=first; i<s.size(); ++i)
		{
			if (!point && s[i] == '.')		// .1 �ǿ��Ե� ��ô˵ -.1 ����1.
			{// .������һ������e֮ǰ
				point = 1;
				// .���������֣���.ǰ������� û�С��ո񡢷��Ż�����
				if (i < s.size()-1 && isdig(s[i+1]) && (i==0 || (i>0 && (isdig(s[i-1]) || s[i-1]==' ' || s[i-1]=='-' || s[i-1]=='+'))))
					++i;
				// .ǰ�������֣���.��������� û�С��ո����ֻ�e
				else if (i>0 && isdig(s[i-1]) && (i==s.size()-1 || (i<s.size()-1 && (s[i+1]=='e' || s[i+1]=='E' ||s[i+1]==' '))));
				else return false;
			}

			else if (!E && (s[i] == 'e' || s[i] == 'E') && i > 0 && (isdig(s[i-1]) || s[i-1]=='.'))	//eǰ�������ֻ�.
			{
				E = 1;
				point = 1;	// e���治����С����
				
				if (i<s.size()-1 && isdig(s[i+1]))	// e����û����
					++i;
				else if (i<s.size()-2 && (s[i+1]=='-'||s[i+1]=='+') && isdig(s[i+2]) )	// e�����з���
					i += 2;
				else return false;
			}

			else if (s[i] <= '9' && s[i] >= '0');

			else if (s[i] == ' ')	// β���ո�
			{
				for (int j=i+1; j<s.size(); ++j)
					if (s[j] != ' ')
						return false;
				break;
			}
			else return false;
		}
		return true;
    }
};

int main()
{
	Solution S;
	string SS [] = {"6e-8", "6e6.5", "0.e", "46e.3", "46.e3", "123", "1", "01", "0.0", "-0.3", "+.8", "-.6", "0x.63", "e", "0..", "0..3", "  - 99",
					"   .9", "   9.", " .", "-19", "2e30", ".", " ", "", " 3cc", "15.6", "16.3k", "1  a "};
	for (int i=0; i<28; ++i)
		cout << SS[i] << "\t: " << S.isNumber(SS[i]) << endl;
	return 0;
}