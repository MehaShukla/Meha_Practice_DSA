/*

Given a number n, find the nth fibonacci no.

Example :
	Input : n = 7
	Output : 13

*/

#include<iostream>
#include<vector>

using namespace std;

int fibo(int n) {

	// base case
	if(n == 0 || n == 1) {
		return n;
	}

	// recursive case
	return fibo(n-1) + fibo(n-2);

}

int fiboTopDown(int n, vector<int>& dp) {

	// base case
	if(n == 0 || n == 1) {
		return dp[n] = n;
	}

	// lookup
	if(dp[n] != -1) {
		return dp[n];
	}

	// recursive case
	return dp[n] = fiboTopDown(n-1, dp) +
	               fiboTopDown(n-2, dp);

}

int fiboBottomUp(int n) {

	vector<int> dp(n+1);

	// base case

	dp[0] = 0;
	dp[1] = 1;

	// recurisve case

	for(int i=2; i<=n; i++) {
		dp[i] = dp[i-1] + dp[i-2];
	}

	return dp[n];

}

int fiboBottomUpSpaceOptimised(int n) {

	int a = 0;
	int b = 1;

	// recurisve case

	for(int i=2; i<=n; i++) {
		int c = a + b;
		a = b;
		b = c;
	}

	return b;

}


int main() {

	int n = 6;

	cout << fibo(n) << endl;

	vector<int> dp(n+1, -1);
	cout << fiboTopDown(n, dp) << endl;
	cout << fiboBottomUp(n) << endl;
	cout << fiboBottomUpSpaceOptimised(n) << endl;

	return 0;
}
/*

Given a number n, count the minimum steps to reduce n to 1 such that at each
step you may

	reduce n to n/2 if n is divisible by 2
	or reduce n to n/3 if n is divisible by 3
	or reduce n to n-1 by decrementing n by 1

Example :
	Input : n = 10
	Output : 3

	Input : 6
	Output : 2

*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int minStepsToOne(int n) {

	// base case
	if(n == 1) {
		return 0;
	}

	// recursive case

	int a = INT_MAX;
	if(n%2 == 0) {
		// ask your friend to find minSteps reqd. to reduce n/2 to 1
		a = minStepsToOne(n/2);
	}

	int b = INT_MAX;
	if(n%3 == 0) {
		// ask your friend to find minSteps reqd. to reduce n/3 to 1
		b = minStepsToOne(n/3);
	}

	int c = minStepsToOne(n-1);

	return 1 + min(a, min(b, c));

}

int minStepsToOneTopDown(int n, vector<int>& dp) {

	// base case
	if(n == 1) {
		return dp[n] = 0;
	}

	// lookup
	if(dp[n] != -1) {
		return dp[n];
	}

	// recursive case

	int a = INT_MAX;
	if(n%2 == 0) {
		// ask your friend to find minSteps reqd. to reduce n/2 to 1
		a = minStepsToOneTopDown(n/2, dp);
	}

	int b = INT_MAX;
	if(n%3 == 0) {
		// ask your friend to find minSteps reqd. to reduce n/3 to 1
		b = minStepsToOneTopDown(n/3, dp);
	}

	int c = minStepsToOneTopDown(n-1, dp);

	return dp[n] = 1 + min(a, min(b, c));

}

int minStepsToOneBottomUp(int n) {
	vector<int> dp(n+1); // 0th idx is reserved

	// base case
	dp[1] = 0;

	// recursive case
	for(int i=2; i<=n; i++) {
		int a = INT_MAX;
		if(i%2 == 0) {
			a = dp[i/2];
		}
		int b = INT_MAX;
		if(i%3 == 0) {
			b = dp[i/3];
		}
		int c = dp[i-1];
		dp[i] = 1 + min(a, min(b, c));
	}

	return dp[n];
}

int main() {

	int n = 30;

	cout << minStepsToOne(n) << endl;

	vector<int> dp(n+1, -1); // 0th idx is reserved
	cout << minStepsToOneTopDown(n, dp) << endl;
	cout << minStepsToOneBottomUp(n) << endl;

	return 0;
}
/*

You are given an integer array coins representing coins of different denominations
and an integer amount representing a total amount of money.Return the fewest number
of coins that you need to make up that amount.

You may assume that you have an infinite number of each kind of coin.

Don't forget to handle the case if that amount of money cannot be made up by any
combination of the coins.

Example 1:

	Input: coins = [1,2,5], amount = 11
	Output: 3

	Input: coins = [3, 6], amount = 13
	Output: noWay

*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int minCoins(int n, vector<int>& c) {
	// base case
	if(n == 0) {
		return 0;
	}

	// recursive case
	int ans = INT_MAX;
	int k = c.size();
	for(int j=0; j<k; j++) {
		if(n-c[j] >= 0) {
			ans = min(ans, minCoins(n-c[j], c));
		}
	}

	return ans == INT_MAX ? INT_MAX : 1 + ans;
}

int minCoinsTopDown(int n, vector<int>& c, vector<int>& dp) {
	// base case
	if(n == 0) {
		return dp[n]=0;
	}

	// lookup
	if(dp[n] != -1) {
		return dp[n];
	}

	// recursive case
	int ans = INT_MAX;
	int k = c.size();
	for(int j=0; j<k; j++) {
		if(n-c[j] >= 0) {
			ans = min(ans, minCoinsTopDown(n-c[j], c, dp));
		}
	}

	return dp[n] = ans == INT_MAX ? INT_MAX : 1 + ans;
}

int minCoinsBottomUp(int n, vector<int>& c) {

	int k = c.size();

	vector<int> dp(n+1);

	// base case
	dp[0] = 0;

	// recursive case
	for(int i=1; i<=n; i++) {
		int ans = INT_MAX;
		for(int j=0; j<k; j++) {
			if(i-c[j] >= 0) {
				ans = min(ans, dp[i-c[j]]);
			}
		}
		dp[i] = ans == INT_MAX ? INT_MAX : 1 + ans;
	}

	return dp[n];

}


int main() {

	int n = 13;
	vector<int> c = {3, 6};

	cout << minCoins(n, c) << endl;

	vector<int> dp(n+1, -1);
	cout << minCoinsTopDown(n, c, dp) << endl;
	cout << minCoinsBottomUp(n, c) << endl;

	return 0;
}
/*

Suppose there is a ladder with n steps.  A person standing at the  bottom of the
ladder and  wants to reach to its top. Assume the person can take a jump of size 1
to k at a time. Then, count the number of ways, the person can reach the top of
the ladder.

Example
	Input : n = 4, k = 3
	Output: 7
	Explanation : [1, 1, 1, 1],
	              [1, 1, 2],
	              [1, 2, 1],
	              [2, 1, 1],
	              [2, 2],
	              [1, 3],
	              [3, 1]

*/
#include<iostream>
#include<vector>

using namespace std;

int numberOfWays(int n, int k) {

	// base case
	if(n == 0) {
		return 1;
	}

	// recursive case
	int count = 0;
	for(int j=1; j<=k; j++) {
		if(n-j >= 0) {
			count += numberOfWays(n-j, k);
		}
	}

	return count;

}

int numberOfWaysBottomUp(int n, int k) {
	vector<int> dp(n+1);

	// base case
	dp[0] = 1;

	// recursive case
	for(int i=1; i<=n; i++) {
		int count = 0;
		for(int j=1; j<=k; j++) {
			if(i-j >= 0) {
				count += dp[i-j];
			}
		}
		dp[i] = count;
	}

	return dp[n];
}

int numberOfWaysBottomUpTimeOptimised(int n, int k) {
	vector<int> dp(n+1);

	// base case
	dp[0] = 1;
	dp[1] = dp[0];

	// recursive case
	for(int i=2; i<=k; i++) {
		dp[i] = 2*dp[i-1];
	}

	for(int i=k+1; i<=n; i++) {
		dp[i] = 2*dp[i-1] - dp[i-k-1];
	}

	return dp[n];
}


int main() {

	int n = 4;
	int k = 3;

	cout << numberOfWays(n, k) << endl;
	cout << numberOfWaysBottomUp(n, k) << endl;
	cout << numberOfWaysBottomUpTimeOptimised(n, k) << endl;

	return 0;
}

/*

Given a m x n grid filled with non-negative numbers, find a path from (0, 0) to
(m-1, n-1), which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example :
	Input: grid = [[1,3,1],
	               [1,5,1],
	               [4,2,1]]

	Output: 7
	Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Constraints :
	1 <= m, n <= 200
	0 <= grid[i][j] <= 100

*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int minSum(vector<vector<int>>& grid, int i, int j) {

	// base case
	if(i == 0 && j == 0) {
		return grid[0][0];
	}

	// additional base case that allows you to go outside the grid

	// if(i < 0 || j < 0) {
	// 	return INT_MAX;
	// }

	// recursive case
	if(i == 0) {
		// you can reach the (i, j)th cell from the left
		return grid[i][j] + minSum(grid, i, j-1);
	}

	if(j == 0) {
		// you can reach the (i, j)th cell from the top
		return grid[i][j] + minSum(grid, i-1, j);
	}

	// you can reach the (i, j)th cell from top or left

	int x = minSum(grid, i-1, j);
	int y = minSum(grid, i, j-1);

	return grid[i][j] + min(x, y);

}

int minSumTopDown(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {

	// base case
	if(i == 0 && j == 0) {
		return dp[i][j] = grid[0][0];
	}

	// lookup
	if(dp[i][j] != -1) {
		return dp[i][j];
	}

	// recursive case
	if(i == 0) {
		// you can reach the (i, j)th cell from the left
		return dp[i][j] = grid[i][j] + minSumTopDown(grid, i, j-1, dp);
	}

	if(j == 0) {
		// you can reach the (i, j)th cell from the top
		return dp[i][j] = grid[i][j] + minSumTopDown(grid, i-1, j, dp);
	}

	// you can reach the (i, j)th cell from top or left

	int x = minSumTopDown(grid, i-1, j, dp);
	int y = minSumTopDown(grid, i, j-1, dp);

	return dp[i][j] = grid[i][j] + min(x, y);

}

int minSumBottomUp(vector<vector<int>>& grid) {
 	int m = grid.size();
   	int n = grid[0].size();

   	vector<vector<int>> dp(m, vector<int>(n));

   	for(int i=0; i<m; i++) {
   		for(int j=0; j<n; j++) {
   			if(i == 0 && j == 0) {
   				dp[i][j] = grid[i][j];
   			} else if(i == 0) {
   				dp[i][j] = grid[i][j] + dp[i][j-1];
   			} else if(j == 0) {
   				dp[i][j] = grid[i][j] + dp[i-1][j];
   			} else {
				dp[i][j] = grid[i][j] + min(dp[i-1][j],
					                        dp[i][j-1]);
   			}
   		}
   	}

   	return dp[m-1][n-1];
}

int main() {

	vector<vector<int>> grid = {{1, 3, 1},
   								{1, 5, 1},
   								{4, 2, 1}};

   	int m = grid.size();
   	int n = grid[0].size();

   	cout << minSum(grid, m-1, n-1) << endl;

   	vector<vector<int>> dp(m, vector<int>(n, -1));
   	cout << minSumTopDown(grid, m-1, n-1, dp) << endl;
   	cout << minSumBottomUp(grid) << endl;

	return 0;
}







/*

You are packing for a vacation on the sea side and you are going to carry only one bag with
capacity C (1 <= C <= 1000). You also have N (1<= N <= 1000) items that you might want to take
with you to the sea side. Unfortunately you can not fit all of them in the knapsack so you will
have to choose. For each item you are given its size and its value. You want to maximize the total
value of all the items you are going to bring. What is this maximum total value?

Example :
	Input : N = 5, W = 4
			weight[] = {1, 2, 3, 2, 2}
			profit[] = {8, 4, 1, 5, 3}
	Output: 12

*/


#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& weight, vector<int>& profit, int i, int w, int N) {

	// base case

	if(i == N) {
		// you've no more object to consider
		return 0;
	}

	if(w == 0) {
		// you've no more capacity left in the knapsack
		return 0;
	}

	// recursive case

	if(weight[i] > w) {
		// exclude the ith object from the knapsack
		return maxProfit(weight, profit, i+1, w, N);
	}

	// for the ith object, we have two options

	// 1. include the ith object in the knapsack
	int X = maxProfit(weight, profit, i+1, w-weight[i], N);

	// 2. exclude the ith object from the knapsack
	int Y = maxProfit(weight, profit, i+1, w, N);

	return max(profit[i]+X, Y);

}

int maxProfitTopDown(vector<int>& weight, vector<int>& profit,
	                 int i, int w, int N, vector<vector<int>>& dp) {

	// base case

	if(i == N) {
		// you've no more object to consider
		return dp[i][w] = 0;
	}

	if(w == 0) {
		// you've no more capacity left in the knapsack
		return dp[i][w] = 0;
	}

	// lookup

	if(dp[i][w] != -1) {
		return dp[i][w];
	}

	// recursive case

	if(weight[i] > w) {
		// exclude the ith object from the knapsack
		return dp[i][w] = maxProfitTopDown(weight, profit, i+1, w, N, dp);
	}

	// for the ith object, we have two options

	// 1. include the ith object in the knapsack
	int X = maxProfitTopDown(weight, profit, i+1, w-weight[i], N, dp);

	// 2. exclude the ith object from the knapsack
	int Y = maxProfitTopDown(weight, profit, i+1, w, N, dp);

	return dp[i][w] = max(profit[i]+X, Y);

}

int maxProfitBottomUp(vector<int>& weight, vector<int>& profit, int N, int W) {

	vector<vector<int>> dp(N+1, vector<int>(W+1));

	// base case
	for(int i=0; i<=N; i++) {
		dp[i][0] = 0;
	}

	for(int w=0; w<=W; w++) {
		dp[N][w] = 0;
	}

	for(int i=N-1; i>=0; i--) {
		for(int w=1; w<=W; w++) {
			if(weight[i] > w) {
				dp[i][w] = dp[i+1][w];
			} else {
				int X = dp[i+1][w-weight[i]];
				int Y = dp[i+1][w];
				dp[i][w] = max(profit[i]+X, Y);
			}
		}
	}

	return dp[0][W];

}


int main() {

	int N = 5;
	int W = 4;

	vector<int> weight = {1, 2, 3, 2, 2};
	vector<int> profit = {8, 4, 1, 5, 3};

	cout << maxProfit(weight, profit, 0, W, N) << endl;

	vector<vector<int>> dp(N+1, vector<int>(W+1, -1));
	cout << maxProfitTopDown(weight, profit, 0, W, N, dp) << endl;
	cout << maxProfitBottomUp(weight, profit, N, W) << endl;

	return 0;
}
/*

Given n wines in a row, with integers denoting the cost of each wine respectively. Each year you can
sell the first or the last wine in the row. However, the price of wines increases over time.

Let the initial profits from the wines be [p_1, p_2, ... , p_n]. In the yth year, the profit from
the kth wine will be y*p_k.

Find the maximum profit from all the wines.

Example :
	Input : price[] = {2, 3, 5, 1, 4}
	Ouptut: 50

*/

#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& price, int i, int j, int y) {

	// base case
	if(i == j) {
		// you're left with a single bottle of wine
		return y * price[i]; // here y is equal to n
	}

	// recursive case

	// in the yth year, you've to decide which bottle of wine you should sell

	// 1. sell the ith wine
	int X = maxProfit(price, i+1, j, y+1);

	// 2. sell the jth wine
	int Y = maxProfit(price, i, j-1, y+1);

	return max(y*price[i] + X,
		       y*price[j] + Y);

}

int maxProfitBottomUp(vector<int>& price, int n) {

	vector<vector<int>> dp(n, vector<int>(n));

	// base case
	for(int i=0; i<n; i++) {
		dp[i][i] = price[i]*n; // y == n
	}

	// recursive
	for(int i=n-1; i>=0; i--) {
		for(int j=i+1; j<n; j++) {
			int y = n-(j-i);
			dp[i][j] = max(price[i]*y + dp[i+1][j],
				           price[j]*y + dp[i][j-1]);
		}
	}

	return dp[0][n-1];

}


int main() {

	vector<int> price = {2, 3, 5, 1, 4};
	int n = price.size();

	cout << maxProfit(price, 0, n-1, 1) << endl;
	cout << maxProfitBottomUp(price, n) << endl;


	return 0;
}
/*

Given two strings s1 and s2, return the length of their longest common subsequence.
If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters
(can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example :

	Input : s1 = "ABCDGH", s2 = "AEDFHR"
	Output: 3
	Explanation : "ADH" is the LCS between s1 and s2

	Input : s1 = “AGGTAB”, s2 = “GXTXAYB”
	Output: 4
	Explanation : “GTAB” is the LCS between s1 and s2

*/

#include<iostream>
#include<vector>

using namespace std;

int LCS(string&s1, string& s2, int m, int n, int i, int j) {

	// base case

	if(i == m || j == n) {
		return 0;
	}

	// recursive case
	if(s1[i] == s2[j]) {
		return 1 + LCS(s1, s2, m, n, i+1, j+1); // Z
	}

	return max(LCS(s1, s2, m, n, i+1, j), // X
		       LCS(s1, s2, m, n, i, j+1)); // Y

}

int LCSBottomUp(string& s1, string& s2, int m, int n) {

	vector<vector<int>> dp(m+1, vector<int>(n+1));

	// base case

	for(int i=0; i<=m; i++) {
		dp[i][n] = 0;
	}

	for(int j=0; j<=n; j++) {
		dp[m][j] = 0;
	}

	// recursive case

	for(int i=m-1; i>=0; i--) {
		for(int j=n-1; j>=0; j--) {
			if(s1[i] == s2[j]) {
				dp[i][j] = 1 + dp[i+1][j+1];
			} else {
				dp[i][j] = max(dp[i+1][j],
					           dp[i][j+1]);
			}
		}
	}

	return dp[0][0];

}

int main() {

	string s1("AGGTAB");
	string s2("GXTXAYB");

	int m = s1.size();
	int n = s2.size();

	cout << LCS(s1, s2, m, n, 0, 0) << endl;
	cout << LCSBottomUp(s1, s2, m, n) << endl;

	return 0;
}

/*

Given an integer array 'nums', and an integer 'k', return the length of the longest increasing
subsequence starting at the kth index.

A subsequence is a sequence that can be derived from an array by deleting some or no elements
without changing the order of the remaining elements.

Example 1:
	Input: nums[] = [10, 9, 2, 5, 1, 7], k = 2
	Output: 3
	Explanation: The longest increasing subsequence starting at 2nd index is [2, 5, 7],
	             therefore the output is 3.

Example 2:
	Input: nums[] = [0, 1, 0, 3, 2, 3], k = 1
	Output: 3
	Explanation: The longest increasing subsequence starting at the 0th index is [1, 2, 3],
	             therefore the output is 3.
*/


#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int lis_k(vector<int>& nums, int n, int i) {
	// base case
	if(i == n-1) {
		return 1;
	}

	// recursive case
	int ans = INT_MIN;
	for(int j=i+1; j<n; j++) {
		if(nums[j] > nums[i]) {
			ans = max(ans, lis_k(nums, n, j));
		}
	}

	return ans == INT_MIN ? 1 : 1 + ans;

}

int lis_k_bottom_up(vector<int>& nums, int n, int k) {

	vector<int> dp(n);

	// base case
	dp[n-1] = 1;

	// recursive case
	for(int i=n-2; i>=k; i--) {
		int ans = INT_MIN;
		for(int j=i+1; j<n; j++) {
			if(nums[j] > nums[i]) {
				ans = max(ans, dp[j]);
			}
		}
		dp[i] = ans == INT_MIN ? 1 : 1 + ans;
	}

	for(int i=k; i<n; i++) {
		cout << dp[i] << " ";
	}

	cout << endl;

	return dp[k];

}

int main() {

	vector<int> nums = {10, 9, 2, 5, 1, 7};
	int n = nums.size();
	int k = 0;

	cout << lis_k(nums, n, k) << endl;
	cout << lis_k_bottom_up(nums, n, k) << endl;

	return 0;
}

/*

Given an integer array 'nums', return the length of the longest increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without
changing the order of the remaining elements.

Example 1:
	Input: nums[] = [10, 9, 2, 5, 3, 7, 18]
	Output: 4
	Explanation: The longest increasing subsequence is [2, 5, 7, 18], therefore the output is 4.

Example 2:
	Input: nums[] = [0,1,0,3,2,3]
	Output: 4
	Explanation: The longest increasing subsequence is [0, 1, 2, 3], therefore the output is 4.
*/


#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int lis_k(vector<int>& nums, int n, int i) {
	// base case
	if(i == n-1) {
		return 1;
	}

	// recursive case
	int ans = INT_MIN;
	for(int j=i+1; j<n; j++) {
		if(nums[j] > nums[i]) {
			ans = max(ans, lis_k(nums, n, j));
		}
	}

	return ans == INT_MIN ? 1 : 1 + ans;

}

int lis(vector<int>& nums, int n) {

	int res = INT_MIN;
	for(int k=0; k<n; k++) {
		res = max(res, lis_k(nums, n, k));
	}
	return res;

}

int lis_bottom_up(vector<int>& nums, int n) {

	vector<int> dp(n);

	// base case
	dp[n-1] = 1;

	// recursive case
	for(int i=n-2; i>=0; i--) {
		int ans = INT_MIN;
		for(int j=i+1; j<n; j++) {
			if(nums[j] > nums[i]) {
				ans = max(ans, dp[j]);
			}
		}
		dp[i] = ans == INT_MIN ? 1 : 1 + ans;
	}

	int res = INT_MIN;
	for(int i=0; i<n; i++) {
		res = max(res, dp[i]);
	}

	return res;

}

int main() {

	vector<int> nums = {10, 9, 2, 5, 3, 7, 18};
	int n = nums.size();

	cout << lis(nums, n) << endl;
	cout << lis_bottom_up(nums, n) << endl;

	return 0;
}
/*

=============
Edit Distance
=============

Given two strings s1 and s2, return the min. no. of edit operations required to convert s1 to s2.

You have the following three operations permitted on a word:

	> Insert a character
	> Delete a character
	> Replace a character

The min. no. of edits required to convert s1 to s2 is also known as the edit distance between s1 & s2.

Examples

Example 1:

	Input: s1 = "horse", s2 = "ros"
	Output: 3

	Explanation:
	horse -> rorse (replace 'h' with 'r')
	rorse -> rose (remove 'r')
	rose -> ros (remove 'e')

Example 2:

	Input: s1 = "intention", s2 = "execution"
	Output: 5

	Explanation:
	intention -> inention (remove 't')
	inention -> enention (replace 'i' with 'e')
	enention -> exention (replace 'n' with 'x')
	exention -> exection (replace 'n' with 'c')
	exection -> execution (insert 'u')

Example 3:

	Input: s1 = "food", s2 = "money"
	Output: 4

Example 4:

	Input: s1 = "algorithm", s2 = "altruistic"
	Output: 6

*/

#include<iostream>
#include<vector>

using namespace std;

int editDistance(string& s1, string& s2, int m, int n, int i, int j) {
	// base case
	if(i == m and j == n) {
		return 0;
	}

	if(i == m) {
		return n-j;
	}

	if(j == n) {
		return m-i;
	}

	// recursive case

	// at the ith character of s1, we have three options

	// 1. letter insertion
	int X = editDistance(s1, s2, m, n, i, j+1);

	// 2. letter deletion
	int Y = editDistance(s1, s2, m, n, i+1, j);

	// 3. letter subsitution
	int Z = editDistance(s1, s2, m, n, i+1, j+1);

	return min(1+X,
		       min(1+Y,
		           int(s1[i]!=s2[j]) + Z));

}

int editDistanceBottomUp(string& s1, string& s2, int m, int n) {

	vector<vector<int>> dp(m+1, vector<int>(n+1));

	for(int i=m; i>=0; i--) {
		for(int j=n; j>=0; j--) {
			if(i == m && j == n) {
				dp[i][j] = 0;
			} else if(i == m) {
				dp[i][j] = n-j;
			} else if(j == n) {
				dp[i][j] = m-i;
			} else {
				dp[i][j] = min(1 + dp[i][j+1],
					           min(1 + dp[i+1][j],
				                   int(s1[i]!=s2[j]) + dp[i+1][j+1]));
			}
		}
	}

	return dp[0][0];

}

int main() {

	string s1("algorithm");
	int m = s1.size();

	string s2("altruistic");
	int n = s2.size();

	cout << editDistance(s1, s2, m, n, 0, 0) << endl;
	cout << editDistanceBottomUp(s1, s2, m, n) << endl;

	return 0;
}
/*

Example :

	Input : n = 8
	        length : [1,  2,  3,  4,  5,  6,  7,  8]
	        prices : [1,  5,  8,  9,  10, 17, 17, 20]
	Output : 22

	Input : n = 8
	        length : [1,  2,  3,  4,  5,  6,  7,  8]
	        prices : [3,  5,  8,  9, 10, 17, 17, 20]
	Output : 24


*/


#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int maxProfitBottomUp(vector<int>& prices, int n) {
	vector<int> dp(n+1);

	// base case
	dp[0] = 0;

	// recursive case
	for(int i=1; i<=n; i++) {
		int ans = INT_MIN;
		for(int j=1; j<=n; j++) {
			if(i-j >= 0) {
				int pj = prices[j-1];
				ans = max(ans, pj + dp[i-j]);
			}
		}
		dp[i] = ans;
	}

	return dp[n];
}

int main() {

	vector<int> prices = {3,  5,  8,  9, 10, 17, 17, 20};
	int n = prices.size();

	cout << maxProfitBottomUp(prices, n) << endl;

	return 0;
}