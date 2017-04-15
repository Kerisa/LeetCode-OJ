/*
 * By	: Alisa
 * Date	: 15-07-23
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays.
 * The overall run time complexity should be O(log (m+n)).
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n1 = nums1.size();
		int n2 = nums2.size();
		int m1 = (n1 - 1) / 2;
		int m2 = (n2 - 1) / 2;

		if (n1 == 0) return n2%2!=0 ? nums2[m2] : (double)(nums2[m2]+nums2[m2+1])/2;
		if (n2 == 0) return n1%2!=0 ? nums1[m1] : (double)(nums1[m1]+nums1[m1+1])/2;

		double mid1 = n1%2==0 ? (double)(nums1[m1]+nums1[m1+1])/2 : nums1[m1];
		double mid2 = n2%2==0 ? (double)(nums2[m2]+nums2[m2+1])/2 : nums2[m2];

		if (n1 == 1)  // 边界
		{
			if (n2 == 1)
				return (double)(nums1[0] + nums2[0]) / 2;
			else if (n2 % 2 == 0)
			{
				if (nums1[0] > nums2[m2+1])
					return nums2[m2+1];
				else if (nums1[0] < nums2[m2])
					return nums2[m2];
				else
					return nums1[0];
			}
			else
			{
				if (nums1[0] > nums2[m2+1])
					return (double)(nums2[m2] + nums2[m2+1]) / 2;
				else if (nums1[0] < nums2[m2-1])
					return (double)(nums2[m2-1] + nums2[m2]) / 2;
				else
					return (double)(nums1[0] + nums2[m2]) / 2;
			}
		}
		else if (n2 == 1)	// 边界
		{
			if (n1 % 2 == 0)
			{
				if (nums2[0] > nums1[m1+1])
					return nums1[m1+1];
				else if (nums2[0] < nums1[m1])
					return nums1[m1];
				else
					return nums2[0];
			}
			else
			{
				if (nums2[0] > nums1[m1+1])
					return (double)(nums1[m1] + nums1[m1+1]) / 2;
				else if (nums2[0] < nums1[m1-1])
					return (double)(nums1[m1-1] + nums1[m1]) / 2;
				else
					return (double)(nums2[0] + nums1[m1]) / 2;
			}
		}
		else if (n1 ==2 || n2 == 2)	// 边界， 直接重组成一个数组
		{
			vector<int> t;
			int i1, i2;
			for (i1=0, i2=0; i1<n1 || i2<n2;)
			{
				if (i1<n1 && i2<n2) t.push_back(nums1[i1]<nums2[i2] ? nums1[i1++] : nums2[i2++]); 
				else if (i1<n1) t.push_back(nums1[i1++]);
				else t.push_back(nums2[i2++]);
			}
			int tm = t.size()-1;
			return tm%2!=0 ? (double)(t[tm/2] + t[tm/2+1])/2 : t[tm/2];
		}
		else	// 递归
		{
			int decrease = n1 > n2 ? (n2-1)/2 : (n1-1)/2;
			
			if (mid1 - mid2 < 1e-9 && mid1 - mid2 > -1e-9)
				return mid1;
			else if (mid1 < mid2)
			{
				vector<int> d1(nums1.begin() + decrease, nums1.end());
				vector<int> d2(nums2.begin(), nums2.end() - decrease);
				return findMedianSortedArrays(d1, d2);
			}
			else
			{
				vector<int> d1(nums1.begin(), nums1.end() - decrease);
				vector<int> d2(nums2.begin() + decrease, nums2.end());
				return findMedianSortedArrays(d1, d2);
			}
		}
    }
};

// test case
int main()
{
	Solution S;
	vector<int> a1, a2;
{
	int r2[] = {2, 3};

	for (int i=0; i<2; ++i)
		a2.push_back(r2[i]);

	cout << S.findMedianSortedArrays(a1, a2) << endl;
}{ a1.clear(); a2.clear();
	int r1[] = {1, 2};
	int r2[] = {1, 2};

	for (int i=0; i<2; ++i)
		a1.push_back(r1[i]);
	for (int i=0; i<2; ++i)
		a2.push_back(r2[i]);

	cout << S.findMedianSortedArrays(a1, a2) << endl;
}{ a1.clear(); a2.clear();
	int r1[] = {1, 2};
	int r2[] = {1, 2, 3};

	for (int i=0; i<2; ++i)
		a1.push_back(r1[i]);
	for (int i=0; i<3; ++i)
		a2.push_back(r2[i]);

	cout << S.findMedianSortedArrays(a1, a2) << endl;
}{ a1.clear(); a2.clear();
	int r1[] = {1, 2};
	int r2[] = {1, 1};

	for (int i=0; i<2; ++i)
		a1.push_back(r1[i]);
	for (int i=0; i<2; ++i)
		a2.push_back(r2[i]);

	cout << S.findMedianSortedArrays(a1, a2) << endl;
}{ a1.clear(); a2.clear();
	int r1[] = {1};
	int r2[] = {2, 3, 4};

	for (int i=0; i<1; ++i)
		a1.push_back(r1[i]);
	for (int i=0; i<3; ++i)
		a2.push_back(r2[i]);

	cout << S.findMedianSortedArrays(a1, a2) << endl;
}{ a1.clear(); a2.clear();
	int r1[] = {1, 2, 6};
	int r2[] = {3, 4, 5};

	for (int i=0; i<3; ++i)
		a1.push_back(r1[i]);
	for (int i=0; i<3; ++i)
		a2.push_back(r2[i]);

	cout << S.findMedianSortedArrays(a1, a2) << endl;
}{ a1.clear(); a2.clear();
	int r1[] = {1, 2, 6, 7};
	int r2[] = {1, 3, 4, 5};

	for (int i=0; i<4; ++i)
		a1.push_back(r1[i]);
	for (int i=0; i<4; ++i)
		a2.push_back(r2[i]);

	cout << S.findMedianSortedArrays(a1, a2) << endl;
}{ a1.clear(); a2.clear();
	int r1[] = {1, 2};
	int r2[] = {3, 4, 5, 6};

	for (int i=0; i<2; ++i)
		a1.push_back(r1[i]);
	for (int i=0; i<4; ++i)
		a2.push_back(r2[i]);

	cout << S.findMedianSortedArrays(a1, a2) << endl;
}
	return 0;
}