/*
    link: https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#

    sol: https://www.geeksforgeeks.org/minimize-the-maximum-difference-between-the-heights/
    note: this above sol. by geeks for geeks is not working... :(
*/


// ----------------------------------------------------------------------------------------------------------------------- //
// simple and correct solution.
int getMinDiff(int arr[], int n, int k) {
    if (n == 1) return 0;
    sort(arr, arr + n);
    int ans = arr[n - 1] - arr[0];

    for (int i = 0;i < n;i++) {
        if (arr[i] < k) continue;     // to avoid negative height in curr_min
        int curr_min = min(arr[0] + k, arr[i] - k);
        int curr_max = max(arr[n - 1] - k, arr[i - 1] + k);
        if (curr_max < curr_min) continue;      // as max till now can't be smaller than min till now hence ignore that element.
        ans = min(ans, curr_max - curr_min);
    }
    return ans;
}
#include <bits/stdc++.h>
using namespace std;

// User function Template
int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int ans = arr[n - 1] - arr[0]; // Maximum possible height difference

    int tempmin, tempmax;
    tempmin = arr[0];
    tempmax = arr[n - 1];

    for (int i = 1; i < n; i++) {
        if(arr[i] - k < 0) // if on subtracting k we got negative then continue
        continue;
        tempmin= min(arr[0] + k,arr[i] - k); // Minimum element when we
                                                // add k to whole array
        tempmax = max(arr[i - 1] + k, arr[n - 1] - k); // Maximum element when we
                                                         // subtract k from whole array
        ans = min(ans, tempmax - tempmin);
    }
    return ans;
}

// Driver Code Starts
int main()
{
    int k = 6, n = 6;
    int arr[n] = { 7, 4, 8, 8, 8, 9 };
    int ans = getMinDiff(arr, n, k);
    cout << ans;
}