/*
    link: https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1#

    sol: https://www.geeksforgeeks.org/minimum-swaps-required-bring-elements-less-equal-k-together/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
int minSwap(int* arr, int n, int k) {

    // Find count of elements which are
    // less than equals to k
    int count = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i] <= k)
            ++count;

    // Find unwanted elements in current
    // window of size 'count'
    int bad = 0;
    for (int i = 0; i < count; ++i)
        if (arr[i] > k)
            ++bad;

    // Initialize answer with 'bad' value of
    // current window
    int ans = bad;
    for (int i = 0, j = count; j < n; ++i, ++j) {

        // Decrement count of previous window
        if (arr[i] > k)
            --bad;

        // Increment count of current window
        if (arr[j] > k)
            ++bad;

        // Update ans if count of 'bad'
        // is less in current window
        ans = min(ans, bad);
    }
    return ans;
}
public static int minSwap (int[] arr, int n, int k) {     // total ele=valid, count=invalid
        // number of element smaller than and equal to K
        int totalEle = 0;

        // finding number of element through this loop
        for(int i = 0; i < n; i++)
            if(arr[i] <= k)
                totalEle++;

        // if there is no small element in the array then we'll print 0
        if(totalEle == 0)
            return 0;

        // finding element in first window( of size totalEle) which is less than and equal to K
        int i;
        // Count in first window
        int count = 0;
        for(i = 0; i < totalEle; i++)
            if(arr[i] <= k)
                count++;

        // Initialise maxCount as to check which window has the highest number of element in every window of size totalEle
        int maxCount = count;
        // window fixed size= totalele

        while(i < n){
            // while moving to next window, we have to check 2 points
            // 1 - last element which is going to be kicked less than or equal to K or not
            // if yes then we'll decrement the count
            if(arr[i-totalEle] <= k)                                            //000  t 1111
                count--; //q werty
            // 2 - element at index i is less than or equal to K or not
            // if yes then we'll increment the count
            if(arr[i] <= k)
                count++;

            // we'll keep note that which windows has the highest amount of elements belongs to this category (<=K)
            maxCount = Math.max(maxCount, count);
            i++;
        }

        // then to sum up, after getting window with maximum number of elements (<=K)
        // we'll just subtract it with total elements which is <=K
        // in order to get the amount of min swap
        return totalEle - maxCount;
    }
