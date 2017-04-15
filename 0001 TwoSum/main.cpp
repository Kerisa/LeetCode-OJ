/*
 * By	: Alisa
 * Date	: 15-07-22
 *
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 * The function twoSum should return indices of the two numbers such that they add up to the target, 
 * where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int _cdecl MyCmp(const void *a, const void *b) {return *(int*)a - *(int*)b; };
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	/* 将数组排序，从两端逼近找出满足条件的值，再从原数组中找出其索引 */
	{
		vector<int> tmp(nums.begin(), nums.end());
		qsort(&tmp[0], tmp.capacity(), sizeof(int), MyCmp);

		int front = 0;
		int rear = tmp.capacity()-1;

		vector<int> found(2);
		while (front < rear)
		{
			while (tmp[rear] > target - tmp[front]) --rear;
			if (tmp[front] + tmp[rear]== target)
			{
				found[0] = tmp[front];
				found[1] = tmp[rear];
				break;
			}
			++front;
		}

		vector<int> ret;
		int flag = 2;
		rear = nums.capacity();
		for (int i=0; flag && i<=rear; ++i)
		{
			if (flag && nums[i] == found[0] || nums[i] == found[1])
			{
				ret.push_back(i + 1);
				--flag;
			}
		}
		return ret;
	}
		
};

// test
#include <time.h>
#include <stdlib.h>
#define LEN 100
int main()
{
	srand(time(0));
	Solution T;
	vector<int> testcase(5);
	do{
		testcase[0] = -1;
		testcase[1] = 1;
		testcase[2] = -3;
		testcase[3] = 4;
		testcase[4] = 5;
/*	for (int i=0; i<LEN; ++i)
	{
		testcase[i] = rand()%65536;
		cout << testcase[i] << '\t';
	}*/
	
	int target;
	vector<int> recv(2);
	cout << "type target: ";
	cin >> target;
	recv = T.twoSum(testcase, target);

	cout << "Answer: " << recv[0] << ", " << recv[1] << endl;
	}while (cin);
	return 0;
}