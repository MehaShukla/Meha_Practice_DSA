/*
    link: https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

    sol: https://www.geeksforgeeks.org/find-median-row-wise-sorted-matrix/

    here logic was
    1. based on the total ele in matrix find mid pos (called it desired pos, will help for count)
    2. find max, min
    3. now everytime find mid based on min and max, parallely find count of ele. less than mid and if
       total count is greater than desired place means our mid is much higher than original one as it is not near
       to the desired and hence reduce the max, and if count of ele. is less than desired means our mid is way too
       small and make it greater hence increase the min.

*/



// ----------------------------------------------------------------------------------------------------------------------- //
// function to find median in the matrix- each row binary search so MlogN (m=rowno,n=col no)
int binaryMedian(vector<vector<int>>& matrix, int r, int c)
{
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < r; i++)
    {
        // Finding the minimum element
        //sabse min elemt sare rows k phle column pe hoga and max hoga sare rows k last column me kahi
        mn = min(mn, matrix[i][0]);// so row badalre through loop column phle 0 then n-1

        // Finding the maximum element
        mx = max(mn, matrix[i][c - 1]);
    }

    int desired = (r * c + 1) / 2;
    while (mn < mx)
    {
        int mid = mn + (mx - mn) / 2;
        int place = 0;

        // Find count of elements smaller than mid- why?- our median is that elmnt jiske phle n bad equal no of
        //elemnts(adhe adhe ) ho.
        for (int i = 0; i < r; ++i) {
            place += upper_bound(matrix[i].begin(), matrix[i].begin() + c, mid) - matrix[i].begin();
            // cout << i << ": " << curr << endl;
        }

        if (place < desired) mn = mid + 1;
        else mx = mid;
        // cout << mx << " " << mn << endl;
    }
    return mn;
}
