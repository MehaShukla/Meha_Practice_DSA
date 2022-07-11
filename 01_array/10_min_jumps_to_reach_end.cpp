/*
    link: https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1#
*/


// ----------------------------------------------------------------------------------------------------------------------- //
In Set -1, O(n2) solution is discussed.
Implementation:
Variables to be used:

maxReach= The variable maxReach stores at all time the maximal reachable index in the array.
jump= jump stores the amount of jumps necessary to reach the maximal reachable position.
It also indicates the current jump we are making in the array.
step =The variable step stores the number of steps we can still take in the current jump
‘jump’ (and is initialized with value at index 0, i.e. initial number of steps)
Given array arr = 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9

maxReach = arr[0]; // arr[0] = 1, so the maximum index we can reach at the moment is 1.
step = arr[0]; // arr[0] = 1, the amount of steps we can still take is also 1.
jump = 1; // we are currently making our first jump.
Now, starting iteration from index 1, the above values are updated as follows:
First we test whether we have reached the end of the array, in that case we just need to return
the jump variable.
if (i == arr.length - 1)
    return jump;
2.  Next we update the maxReach. This is equal to the maximum of maxReach and i+arr[i]
(the number of steps we can take from the current position).

maxReach = Math.max(maxReach, i+arr[i]);
3.  We used up a step to get to the current index, so steps has to be decreased.

step--;
4. If no more steps are remaining (i.e. steps=0, then we must have used a jump.
Therefore increase jump. Since we know that it is possible somehow to reach maxReach,
we again initialize the steps to the number of steps to reach maxReach from position i.
But before re-initializing step, we also check whether a step is becoming zero or negative.
In this case, It is not possible to reach further.

if (step == 0) {
    jump++;
    if(i>=maxReach)
       return -1;
    step = maxReach - i;
}

// C++ program to count Minimum number
// of jumps to reach end
#include <bits/stdc++.h>
using namespace std;

int max(int x, int y)
{
    return (x > y) ? x : y;
}

// Returns minimum number of jumps
// to reach arr[n-1] from arr[0]
int minJumps(int arr[], int n)
{

    // The number of jumps needed to
    // reach the starting index is 0
    if (n <= 1)
        return 0;

    // Return -1 if not possible to jump
    if (arr[0] == 0)
        return -1;

    // initialization
    // stores all time the maximal
    // reachable index in the array.
    int maxReach = arr[0];

    // stores the number of steps
    // we can still take
    int step = arr[0];

    // stores the number of jumps
    // necessary to reach that maximal
    // reachable position.
    int jump = 1;

    // Start traversing array
    int i = 1;
    for (i = 1; i < n; i++) {
        // Check if we have reached the end of the array
        if (i == n - 1)
            return jump;

        // updating maxReach
        maxReach = max(maxReach, i + arr[i]);

        // we use a step to get to the current index
        step--;

        // If no further steps left
        if (step == 0) {
            // we must have used a jump
            jump++;

            // Check if the current index/position or lesser index
            // is the maximum reach point from the previous indexes
            if (i >= maxReach)
                return -1;

            // re-initialize the steps to the amount
            // of steps to reach maxReach from position i.
            step = maxReach - i;
        }
    }

    return -1;
}

// Driver program to test above function
int main()
{
    int arr[] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
    int size = sizeof(arr) / sizeof(int);

    // Calling the minJumps function
    cout << ("Minimum number of jumps to reach end is %d ",
             minJumps(arr, size));
    return 0;
}
// This code is contributed by
// Shashank_Sharma
Output
3
Complexity Analysis:

Time complexity: O(n).
Only one traversal of the array is needed.
Auxiliary Space: O(1).
There is no space required.
/////////////////////////////////////////////
int minJumps(int arr[], int n) {

    // base condition
    if (n <= 1) return 0;
    if (arr[0] == 0) return -1;

    int maxReach = arr[0];
    int step = arr[0];
    int jump = 1;

    for (int i = 1;i < n;i++) {
        if (i == n - 1) return jump;

        maxReach = max(maxReach, arr[i] + i);

        step--;     // do step-- until its 0 as we r sure we can reach till that end but parallely keep updating maxReach

        if (step == 0) {
            jump++;

            if (i >= maxReach) return -1;

            step = maxReach - i;    // here we got help of that maxReach
            // this shows that why iterating all the elements till now how max. farthest we can go and we will set step as such.
        }
    }
    return -1;
}