/*
 * By	: Alisa
 * Date	: 15-08-04
 *
 * Implement a basic calculator to evaluate a simple expression string.
 * The expression string may contain open ( and closing parentheses ), the plus + or minus sign -,
 * non-negative integers and empty spaces .
 * You may assume that the given expression is always valid.
 *
 * Some examples:
 * "1 + 1" = 2
 * " 2-1 + 2 " = 3
 * "(1+(4+5+2)-3)+(6+8)" = 23
 * Note: Do not use the eval built-in library function.
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
	int MakeDigit(string &s, int *pcur, int len)
	{
		int ret = 0;
		while (*pcur < len && s[*pcur] >= '0' && s[*pcur] <= '9')
			ret = 10 * ret + s[(*pcur)++] - '0';

		return ret;
	}

public:
    int calculate(string s) {
        // '+':49956235   '-':49956236    '(':49956237	
		// 仅用作区分数字和符号，更通用的匹配可能还需另设一个栈
        int *stack = new int[5000], top = -1, cur = 0;
        int oper, i, len, digit;
        
        for (i=len=0; i<s.size(); ++i)	// 剔除空格
            if (s[i] != ' ')
                s[len++] = s[i];
		if (len < s.size())
			s[len] = 0;

        while (cur < len)
        {
            switch (s[cur])
            {
			// 运算符，分两种情况处理
            case '+':
                if (top == -1 || s[cur+1] == '(')
                    stack[++top] = 49956235;  // '+'
                else
                {
					++cur;
					digit = MakeDigit(s, &cur, len);
					stack[top] += digit;
					--cur;
				}
                break;
                
            case '-':
                if (top == -1 || s[cur+1] == '(')
                    stack[++top] = 49956236;  // '-'
                else
                {
					++cur;
					digit = MakeDigit(s, &cur, len);
					stack[top] -= digit;
					--cur;
				}
                break;
                
            case '(':
                stack[++top] = 49956237;	// '('
                break;
                
            case ')':
				if (stack[top] == 49956237)	// 空括号对
				{
					if (--top == -1) stack[0] = 0;
					break;
				}												//      ————————————
				else if (stack[top-1] == 49956237 && top == 1)	// 形如 |(1)
				{												//      ————————————
					stack[top-1] = stack[top--];
					break;
				}
                else if (stack[top-2] == 49956235)	// '+'
                     stack[top-3] += stack[top];
                else stack[top-3] -= stack[top];	// '-'
                top -= 3;
                break;

			// 数字入栈
			default:
				digit = MakeDigit(s, &cur, len);
				--cur;
				stack[++top] = digit;
				break;
            }
			++cur;
        }
        int ret = stack[0];
        delete [] stack;
        return ret;
    }
};

int main()
{
	Solution S;
	cout << S.calculate("1-(3+5-2+(3+19-(3-1-4+(9-4-(4-(1+(3)-2)-5)+8-(3-5)-1)-4)-5)-4+3-9)-4-(3+2-5)-10") << endl;	// -15
	cout << S.calculate("1+(2+3-(4+5))-7+     9 + 10 -13+(14-5)") << endl;	// 5
	cout << S.calculate("()") << endl;
	cout << S.calculate("()(5)()") << endl;
	return 0;
}