/*
 * By	: Alisa
 * Date	: 15-08-12
 *
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 * You may assume that the intervals were initially sorted according to their start times.
 * Example 1:
 *   Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 * Example 2:
 *   Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 *
 * 渣代码
 */

#include <iostream>
#include <vector>
using namespace std;

// Definition for an interval.
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ret;
        
        Interval covered(-1, -1);
        bool IsLeftIn = false, IsRightIn = false;
        int i;
		// (新区间)位于最左
		if (!intervals.size() || intervals[0].start > newInterval.end)
			goto Next;
		// 最右
		else if (intervals[intervals.size()-1].end < newInterval.start)
		{
			covered.start = intervals.size();
			covered.end = intervals.size();
			goto Next;
		}

        for (i=0; i<intervals.size(); ++i)
        {	// 左边界落在区间中
            if (intervals[i].start <= newInterval.start && intervals[i].end >= newInterval.start)
            {
                IsLeftIn = true;
                covered.start = i;
                break;
			// 落在区间外
			} else if (intervals[i].start > newInterval.start ||
					   i>0 && intervals[i-1].end < newInterval.start && intervals[i].start > newInterval.start) {
                covered.start = i;
                break;
			
            }
        }
        for (i=intervals.size()-1; i>=0; --i)
        {	// 右边界
            if (intervals[i].start <= newInterval.end && intervals[i].end >= newInterval.end)
            {
                IsRightIn = true;
                covered.end = i;
                break;

            } else if (intervals[i].end < newInterval.end) {
				covered.end = i;
                break;
			} else if (i>0 && intervals[i-1].end < newInterval.end && intervals[i].start > newInterval.end) {
				covered.end = i-1;
                break;
            }
        }
Next:   // 复制比新区间小的
		for (i=0; i<covered.start; ++i)
			ret.push_back(intervals[i]);
        
        Interval tmp;
        tmp.start = IsLeftIn  ? intervals[covered.start].start : newInterval.start;
        tmp.end   = IsRightIn ? intervals[covered.end].end     : newInterval.end;
        ret.push_back(tmp);
        
		// 复制比它大的
        for (i=covered.end+1; i<intervals.size(); ++i)
            ret.push_back(intervals[i]);
            
        return ret;
    }
};

void out(vector<Interval> a)
{
	for (int i=0; i<a.size(); ++i)
		cout << '[' << a[i].start << ", " << a[i].end << "]   ";
	cout << endl;
}

int main()
{
	Solution S;
	vector<Interval> a;
	a.push_back(Interval(3,5));
/*	a.push_back(Interval(4,5));
	a.push_back(Interval(6,7));
	a.push_back(Interval(8,10));
	a.push_back(Interval(14,16));
*/
	out(S.insert(a, Interval(1,2))); //2
	out(S.insert(a, Interval(1,3))); //1
	out(S.insert(a, Interval(1,4))); //1
	out(S.insert(a, Interval(1,5))); //1
	out(S.insert(a, Interval(1,7))); //1
	out(S.insert(a, Interval(5,7))); //1
	out(S.insert(a, Interval(6,7))); //2
	out(S.insert(a, Interval(3,5))); //1

	return 0;
}