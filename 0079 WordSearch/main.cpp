/*
 * By	: Alisa
 * Date	: 15-08-14
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 * For example, Given board =
 *          [
 *            ["ABCE"],
 *            ["SFCS"],
 *            ["ADEE"]
 *          ]
 *     word = "ABCCED", -> returns true,
 *     word = "SEE", -> returns true,
 *     word = "ABCB", -> returns false.
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    bool dfs(vector<vector<char>>& b, int x, int y, char dir, int s, string & word, vector<vector<bool>>& state)
    {
        if (s >= word.size())
			return true;
        
		if (dir != 'l' && y>0 && !state[x][y-1] && b[x][y-1]==word[s])
		{
			state[x][y-1] = true;
            if (dfs(b, x, y-1, 'r', s+1, word, state))
                return true;
			state[x][y-1] = false;
		}
                
        if (dir != 'u' && x>0 && !state[x-1][y] && b[x-1][y]==word[s])
		{
			state[x-1][y] = true;
            if (dfs(b, x-1, y, 'd', s+1, word, state))
                return true;
			state[x-1][y] = false;
		}
                
        if (dir != 'r' && y<b[0].size()-1 && !state[x][y+1] && b[x][y+1]==word[s] )
		{
			state[x][y+1] = true;
            if (dfs(b, x, y+1, 'l', s+1, word, state))
                return true;
			state[x][y+1] = false;
		}
                
        if (dir != 'd' && x<b.size()-1 && !state[x+1][y] && b[x+1][y]==word[s])
		{
			state[x+1][y] = true;
            if (dfs(b, x+1, y, 'u', s+1, word, state))
                return true;
			state[x+1][y] = false;
		}
        
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (!word.size()) return false;
        
        vector<vector<bool>> state(board.size(), vector<bool>(board[0].size(), 0));
        
        for (int i=0; i<board.size(); ++i)
            for (int j=0; j<board[0].size(); ++j)
            {
                if (board[i][j] == word[0])
                {
					state[i][j] = true;
                    if (dfs(board, i, j, 0, 1, word, state))
                        return true;
                    state[i][j] = false;
                }
                        
            }
        return false;
    }
};

int main()
{
	Solution S;
	char a0 [] = "AAAA";
	char a1 [] = "AAAA";
	char a2 [] = "AAAA";
	vector<vector<char>> A;
	A.push_back(vector<char>(a0,a0+4));
	A.push_back(vector<char>(a1,a1+4));
	A.push_back(vector<char>(a2,a2+4));

	cout << S.exist(A, "AAAAAAAAAAAAA") << endl;
	cout << S.exist(A, "AAAAAAAAAAAA") << endl;
	cout << S.exist(A, "ABCB") << endl;
	return 0;
}