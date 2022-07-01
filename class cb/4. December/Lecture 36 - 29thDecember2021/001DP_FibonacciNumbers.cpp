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







