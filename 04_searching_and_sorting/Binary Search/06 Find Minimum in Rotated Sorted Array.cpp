class Solution {
public:
    int findMin(vector<int>& arr) {
    int lo=0, hi=arr.size()-1;
    int mid;
    int prev, next;
    int n=arr.size();
    if(arr[0]<arr[n-1])
        return arr[0];
    while(lo<=hi){
        
        mid=lo+(hi-lo)/2;

        prev=(mid-1+n)%n;
        next=(mid+1)%n;
        cout<<mid<<endl;
        if(arr[mid]<=arr[prev] and arr[mid]<=arr[next])
            return arr[mid];
        
        if(arr[0]<=arr[mid])
            lo=mid+1;
        
        else if(arr[mid]<=arr[n-1])
                hi=mid-1;
    }
    
    return -1;
    }
};