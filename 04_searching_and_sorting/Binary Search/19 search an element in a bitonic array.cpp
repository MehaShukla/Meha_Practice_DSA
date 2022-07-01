#include<bits/stdc++.h>
using namespace std;
int asc_bs(vector<int>&v, int low, int high, int element)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (v[mid] == element)
			return mid;
		else if (v[mid] < element)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

int desc_bs(vector<int>&v, int low, int high, int element)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (v[mid] == element)
			return mid;
		else if (v[mid] < element)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}
int bitonic(vector<int>& nums, int t)
{
	int low = 0, high = nums.size() - 1, mid;
	while (low <= high) {
		mid = low + (high - low) / 2;
		if (mid > 0 && mid < nums.size() - 1)
		{
			if (nums[mid] == t)
				return mid;
			if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
				return mid;
			else if (nums[mid - 1] > nums[mid])
				high = mid - 1;
			else if (nums[mid + 1] > nums[mid])
				low = mid + 1;
		}
		else if (mid == 0)
		{
			if (nums[0] > nums[1])
				return 0;
			else
				return 1;
		}
		else if (mid == nums.size() - 1)
		{
			if (nums[nums.size() - 1] > nums[nums.size() - 2])
				return nums.size() - 1;
			else
				return nums.size() - 2;
		}
	}
	return -1;
}
int main()
{
	int n, t;
	cin >> n >> t;
	vector<int>v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int result = bitonic(v, t);
	if (v[result] == t)
	{
		cout << result << endl;
		return 0;
	}
	int val1 = asc_bs(v, 0, result, t);
	int val2 = desc_bs(v, result + 1, v.size() - 1, t);
	if (val1 == -1 && val2 == -1)
		cout << "no element" << endl;
	else if (val1 != -1)
		cout << val1 << endl;
	else if (val2 != -1)
		cout << val2 << endl;
	return 0;
}