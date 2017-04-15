/*
 * By	: Alisa
 * Date	: 15-08-05
 *
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
 * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 *
 * Note: You may not slant the container.
 */

#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int ret = 0;
        while (i < j)
        {
            int h = height[i] > height[j] ? height[j] : height[i];
            ret = (j-i)*h > ret ? (j-i)*h : ret;
            while (i < j && height[i] <= h) ++i;
            while (j>=0 && height[j] <= h) --j;
        }
        return ret;
    }
};

int main()
{
	Solution S;
	vector<int> a;
	srand(time(0));
	for (int i=0; i<0; ++i)
	{
		a.push_back(rand()%50);
		cout << a[i] << ' ';
	}
	cout << endl << S.maxArea(a) << endl;
	return 0;
}