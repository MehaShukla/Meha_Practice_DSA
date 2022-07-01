




//Program to search any element in nearly sorted array

int main()
{
    int n=6;
    int arr[n] = {5,10,30,20,40,50};

    int l=0; //lowest value
    int h=n-1; //highest value
    int target = 5; //target value

    while(l<=h){
        int m = l + (h-l)/2; //finding mid value
        int prev = (m+n-1)%n; //previous value --mod to prevent segmentation fault
        int next = (m+1)%n; //next value --mod to prevent segmentation fault

        if(arr[m]==target){
            return m; //target found return value
        }
        else if(arr[prev]==target){
            return prev; //target found return value
        }
        else if(arr[next]==target){
            return next;  //target found return value
        }
        else if(arr[m]>=target){
            h = m-2; //target on left
        }
        else if(arr[m]<=target){
            l = m+2; //target on right
        }
    }
    return -1; //target not found
    return 0;
}