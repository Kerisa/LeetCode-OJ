/*
    Given an array of citations sorted in ascending order (each citation is a non-negative integer) of a researcher,
    write a function to compute the researcher's h-index.

    According to the definition of h-index on Wikipedia:
        "A scientist has index h if h of his/her N papers have at least h citations each, and the other N ? h papers have no more than h citations each."

    Example:

    Input: citations = [0,1,3,5,6]
    Output: 3
    Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had
    received 0, 1, 3, 5, 6 citations respectively.
    Since the researcher has 3 papers with at least 3 citations each and the remaining
    two with no more than 3 citations each, her h-index is 3.
    Note:

    If there are several possible values for h, the maximum one is taken as the h-index.

    Follow up:

    This is a follow up problem to H-Index, where citations is now guaranteed to be sorted in ascending order.
    Could you solve it in logarithmic time complexity?
*/

#include <cassert>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0, right = citations.size() - 1;

        while (left <= right)
        {
            int middle = (left + right) / 2;
            if (citations[middle] == citations.size() - middle)
                return citations.size() - middle;
            else if (citations[middle] < citations.size() - middle)
                left = middle + 1;
            else
                right = middle - 1;
        }

        return citations.size() - 1 - right;
    }
};

int main()
{
    assert(Solution().hIndex(vector<int>{0, 1, 3, 5, 6}) == 3);
    assert(Solution().hIndex(vector<int>{0, 1, 1, 5, 6}) == 2);
    assert(Solution().hIndex(vector<int>{1, 1, 3, 3, 3}) == 3);
    assert(Solution().hIndex(vector<int>{1, 1, 2, 3, 4, 5, 7}) == 3);
    assert(Solution().hIndex(vector<int>{5, 5, 5, 5, 5}) == 5);
    assert(Solution().hIndex(vector<int>{2, 2, 2}) == 2);
    assert(Solution().hIndex(vector<int>{1, 1}) == 1);
    assert(Solution().hIndex(vector<int>{0, 1}) == 1);
    assert(Solution().hIndex(vector<int>{0}) == 0);
    return 0;
}