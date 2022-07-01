class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool is_valid(int* arr, int n, int m, int mid){
        int count = 1;
        int sum = 0;
        for (int i = 0; i<n; i++){
            sum += arr[i];
            if (sum > mid){
                count++;
                sum = arr[i];
            }
            if (count > m) return false;
        }
        return true;
    }
    
    int findPages(int arr[], int n, int m) 
    {
        //code here
        int start = *max_element(arr, arr + n);
        int end = accumulate(arr, arr+n, 0);
        int res = -1;
        while (end >= start){
            int mid = start + (end - start)/2;
            if (is_valid(arr, n, m, mid) == true){
                res = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return res;
    }
};