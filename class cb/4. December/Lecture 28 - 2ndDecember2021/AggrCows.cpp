/*

https://www.spoj.com/problems/AGGRCOW/
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located
 along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall.
 To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance
  between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.

*/

#include<iostream>
#include<climits>

using namespace std;

bool canPlaceCows(int n, int c, int* pos, int m) {
	// place the 1st cow in the 1st stall
	int numOfCowsPlaced = 1;
	// track the position of the last cow you've place
	int prevCowPosition = pos[0];
	for(int i=1; i<n; i++) {
		// can I place the next cow in the stall at the ith position ?
		if(pos[i]-prevCowPosition >= m) {
			numOfCowsPlaced++;
			prevCowPosition = pos[i];
			if(numOfCowsPlaced == c) {
				// you've managed to place c cows in n stalls
				return true;
			}
		}
	}
	return false;
}

// void updatePositions(int n, int c, int* pos, int m, vector<int>& v) {
// 	// place the 1st cow in the 1st stall
// 	int numOfCowsPlaced = 1;
// 	// track the position of the last cow you've place
// 	int prevCowPosition = pos[0];
// 	v.push_back(prevCowPosition);
// 	for(int i=1; i<n; i++) {
// 		// can I place the next cow in the stall at the ith position ?
// 		if(pos[i]-prevCowPosition >= m) {
// 			numOfCowsPlaced++;
// 			prevCowPosition = pos[i];
// 			v.push_back(prevCowPosition);
// 		}
// 	}
// }

int largestMinDist(int n, int c, int* pos) {

	int s = INT_MAX; // place the two cows at the two closest stalls
	for(int i=1; i<n; i++) {
		if(pos[i]-pos[i-1] < s) {
			s = pos[i]-pos[i-1];
		}
	}

	int e = pos[n-1]-pos[0]; // place the two cows at extreme ends
	int ans = s;

	// vector<int> v;

	while(s <= e) {
		int m = s + (e-s)/2;
		if(canPlaceCows(n, c, pos, m)) {
			// reduce the search space from [s, e] to [m+1, e]
			// updatePositions(n, c, pos, m, v);
			ans = m;
			s = m+1;
		} else {
			// reduce the search from [s, e] to [s, m-1]
			e = m-1;
		}
	}

	// for(int i=0; i<c; i++) {
	// 	cout << v[v.size()-1-i] << " ";
	// }

	return ans;

}

int main() {

	// int t;
	// cin >> t;

	// int n, c;
	// int* pos = new int[n];

	// while(t--) {
	// 	cin >> n >> c;
	// 	for(int i=0; i<n; i++) {
	// 		cin >> pos[i];
	// 	}
	// 	sort(pos, pos+n);
	// 	cout << largestMinDist(n, c, pos) << endl;
	// }

	int n = 5;
	int c = 3;
	int pos[] = {1, 2, 4, 8, 9};
	cout << largestMinDist(n, c, pos) << endl;

	return 0;
}
/*

https://hack.codingblocks.com/app/contests/2631/1057/problem
Given K painters to paint N boards where each painter takes 1 unit of time to paint 1 unit of boards i.e. if the length of a particular board is 5, it will take 5 units of time to paint the board. Compute the minimum amount of time to paint all the boards.

Note that:

Every painter can paint only contiguous segments of boards.
A board can only be painted by 1 painter at maximum.
Input Format
First line contains K which is the number of painters. Second line contains N which indicates the number of boards. Third line contains N space separated integers representing the length of each board.

Constraints
1 <= K <= 10
1 <= N <= 10
1<= Length of each Board <= 10^8

Output Format
Output the minimum time required to paint the board.

Sample Input
2
2
1 10
Sample Output
10

When we calculate the mid point 'm', we ask the question

	can 'k' painters paint 'n' boards of given 'len' in 'm' amt. of time ?

	now, we can rephrase this question in two ways

	1. how many painters are required to paint 'n' boards of given 'len' in 'm' amt. of time ?

	   say, 'x' painters can paint 'n' boards of given 'len' in 'm' amt. of time then

	   case (a)

	   now, if x <= k then that means 'k' painters can also paint 'n' boards of given 'len'
	   in 'm' amt. of time so we get 'true' and move towards the left to minimize time

	   case (b)

	   if x > k then that means 'k' painters cannot paint 'n' boards of given 'len' in 'm'
	   amt. of time i.e we get false and move towards the right.

    2. how many boards of given 'len' can 'k' painters paint in 'm' amt. of time ?

*/

#include<iostream>
#include<climits>

using namespace std;

int numOfPaintersRequired(int n, int* len, int timeLimit) {
	int numPainters = 1;
	int time = 0;
	for(int i=0; i<n; i++) {
		// paint the ith board
		time += len[i];
		if(time > timeLimit) {
			// increase the number of painters
			numPainters++;
			// restart the painting of the ith board
			time = len[i];
		}
	}
	return numPainters;
}

int getMinTime(int k, int n, int*len) {
	int s = INT_MIN; // assign a painter to each board
	int e = 0; // assign a single painter to paint all the N boards
	for(int i=0; i<n; i++) {
		s = max(s, len[i]);
		e += len[i];
	}
	int ans = e;

	while(s <= e) {
		int m = s + (e-s)/2;
		int x = numOfPaintersRequired(n, len, m);
		if(x <= k) {
			// 'k' painters can also do the job in <= m amt. of time
			// therefore reduce the search space from [s, e] to [s, m-1]
			ans = m;
			e = m-1;
		} else {
			// 'k' painters cannot do the job in <= m amt. of time
			// therefore reduce the search space from [s, e] to
			// [m+1, e]
			s = m+1;
		}
	}

	return ans;
}

int main() {

	int k;
	cin >> k;

	int n;
	cin >> n;

	int* len = new int[n];
	for(int i=0; i<n; i++) {
		cin >> len[i];
	}

	cout << getMinTime(k, n, len) << endl;

	return 0;
}
/*

https://www.spoj.com/problems/PRATA/

When we calculate the mid point 'm', we ask the question

	can 'l' cooks with given ranks cook 'p' pratas in 'm' amt. of time ?

	now, we can rephrase this question in two ways

	1. how many pratas can 'l' cooks cook in 'm' amt. of time ?
	   say, 'l' cooks can cook 'x' pratas in 'm' amt. of time

	   case (a)

	   now, if x >= p (initial requirement) then that means 'l' cooks
	   can also cook 'p' pratas in 'm' amt. of time so  we get 'true'
	   and move towards the left to minimize time

	   case (b)

	   if x < p then that means 'l' cooks cannot cook 'p' pratas in 'm'
	   amt. of time i.e we get false and move towards the right.

	2. how many cooks are required to cook 'p' pratas in 'm' amt. of time ?

	   the problem with asking this question is that we cannot implement it.
	   why ? because in the question we associate a rank with each cook, so
       if we were to implement this function we need know the ranks of cooks
       that we do not know.

	   try to implement this function, and you'll understand the problem :)


*/

#include<iostream>
#include<climits>

using namespace std;

int numOfPratasCookedByCook(int r, int timeLimit) {
	int count = 0;
	int time = 0;
	int n = 1;

	while (true) {
		// cook the nth prata
		time += r*n;
		if(time > timeLimit) {
			// stop cooking pratas since you've exceeded the time limit
			break;
		}
		count++;
		n++;
	}

	return count;
}

int numOfPratasCooked(int l, int* ranks, int timeLimit) {
	int totalPratas = 0;
	for(int i=0; i<l; i++) {
		totalPratas += numOfPratasCookedByCook(ranks[i], timeLimit);
	}
	return totalPratas;
}

int getMinTime(int p, int l, int* ranks) {
	int s = 0;
	int e = INT_MAX;
	int ans = e;
	while(s <= e) {
		int m = s+(e-s)/2;
		int x = numOfPratasCooked(l, ranks, m);
		if(x >= p) {
			// L cooks can also cook P pratas in 'm' units of time
			// therefore reduce the search space to [s, m-1]
			ans = m;
			e = m-1;
		} else {
			// L cooks cannot cook P pratas in 'm' units of time
			// therefore reduce teh search to [m+1, e]
			s = m+1;
		}
	}
	return ans;
}

int main() {

	int t;
	cin >> t;

	int p, l;
	int* ranks = new int[l];

	while(t--) {
		cin >> p >> l;
		for(int i=0; i<l; i++) {
			cin >> ranks[i];
		}
		cout << getMinTime(p, l, ranks) << endl;
	}

	return 0;
}
