/*
    link: https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/
*/

https://www.youtube.com/watch?v=5MeI5Kk8KTQ

// ----------------------------------------------------------------------------------------------------------------------- //
//o (n) time n o(1) space
/*
in rearranged array Negative elements are found at Even index(0,2,4,6,8..) and Positive Elements are found at odd index(1,3,5,7,9...)
The idea is to process array from left to right. While processing, find the first out of place element in the remaining unprocessed array.
An element is out of place if it is negative and at odd index (0 based index), or it is positive and at even index (0 based index) . Once we find an out of place element,
we find the first element after it with opposite sign. We right rotate the subarray between these two elements (including these two).
*/

public static void rearrange(int[] arr)
	{
	      int wrongIndex = -1;//No Wrong Index
             for (int i=0;i<arr.length;i++)
            {
                if (wrongIndex>=0)
                    if ((arr[wrongIndex]<0 && arr[i] >= 0) || (arr[wrongIndex]>= 0 && arr[i] < 0))
                   {
                       rightRotate(arr,wrongIndex,i);
                       if((i - wrongIndex)==1)
                          wrongIndex = -1;
                      else((i - wrongIndex)>= 2)
                         wrongIndex+=2;
                  }

               if (wrongIndex==-1)
                   if(((i%2)==0 && arr[i]>= 0)|| ((i%2)==1 && arr[i]<0))
                       wrongIndex = i;
             }
	}


	 public static void rightRotate(int a[], int wrongIndex, int index)
	 {
            int temp=a[index];
           for(int i=index;i>wrongIndex;i--)
             a[i]=a[i-1];
            a[wrongIndex]=temp;
         }


  For better Explanation Trace the Below Examples--->

 Input:  arr[] = {-5, -2,7,-6,} //(i - wrongIndex)==1
output: arr[] = {-5, 7, -2, -6}

Input:  arr[] = {-5, -2,-7,5}  //(i - wrongIndex)==2
output: arr[] = {-5, 5, -2, -7}

Input:  arr[] = {-5, -2,-7,-6,5}  //(i - wrongIndex)>2
output: arr[] = {-5, 5, -2, -7,-6}


/*
    Time Complexity : O(N^2)
    Space Complexity : O(1)
*/
// Utility function to right rotate all elements between [outofplace, cur]
void rightrotate(int arr[], int n, int outofplace, int cur)
{
    char tmp = arr[cur];
    for (int i = cur; i > outofplace; i--)
        arr[i] = arr[i - 1];
    arr[outofplace] = tmp;
}

void rearrange(int arr[], int n)
{
    int outofplace = -1;

    for (int index = 0; index < n; index++)
    {
        if (outofplace >= 0)
        {
            // find the item which must be moved into the out-of-place entry if out-of-place entry is
            // positive and current entry is negative OR if out-of-place entry is negative and current
            // entry is negative then right rotate

            // [...-3, -4, -5, 6...] --> [...6, -3, -4, -5...]
            //	 ^						 ^
            //	 |						 |
            //	 outofplace	 -->	 outofplace

            if (((arr[index] >= 0) && (arr[outofplace] < 0)) || ((arr[index] < 0) && (arr[outofplace] >= 0)))
            {
                rightrotate(arr, n, outofplace, index);

                // the new out-of-place entry is now 2 steps ahead
                if (index - outofplace >= 2) outofplace = outofplace + 2;
                else outofplace = -1;
            }
        }

        // if no entry has been flagged out-of-place
        if (outofplace == -1) {
            // check if current entry is out-of-place
            if (((arr[index] >= 0) && (!(index % 2))) || ((arr[index] < 0) && (index % 2))) {
                outofplace = index;
            }
        }
    }
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    JAVA code


    Time Complexity: O(N*logN)
    Space Complexity: O(1)
*/
public class Main {

    // function which works in the condition when number of
    // negative numbers are lesser or equal than positive numbers
    static void fill1(int a[], int neg, int pos)
    {
        if (neg % 2 == 1) {
            for (int i = 1; i < neg; i += 2) {
                int c = a[i];
                int d = a[i + neg];
                int temp = c;
                a[i] = d;
                a[i + neg] = temp;
            }
        }
        else {
            for (int i = 1; i <= neg; i += 2) {
                int c = a[i];
                int d = a[i + neg - 1];
                int temp = c;
                a[i] = d;
                a[i + neg - 1] = temp;
            }
        }
    }
    // function which works in the condition when number of
    // negative numbers are greater than positive numbers
    static void fill2(int a[], int neg, int pos)
    {
        if (pos % 2 == 1) {
            for (int i = 1; i < pos; i += 2) {
                int c = a[i];
                int d = a[i + pos];
                int temp = c;
                a[i] = d;
                a[i + pos] = temp;
            }
        }
        else {
            for (int i = 1; i <= pos; i += 2) {
                int c = a[i];
                int d = a[i + pos - 1];
                int temp = c;
                a[i] = d;
                a[i + pos - 1] = temp;
            }
        }
    }
    static void reverse(int a[], int n)
    {
        int i, k, t;
        for (i = 0; i < n / 2; i++) {
            t = a[i];
            a[i] = a[n - i - 1];
            a[n - i - 1] = t;
        }
    }

    public static void main(String[] args)
        throws java.lang.Exception
    {
        // Given array
        int[] arr = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 };
        int n = arr.length;

        int neg = 0, pos = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0)
                neg++;
            else
                pos++;
        }
        // Sort the array
        Arrays.sort(arr);

        if (neg <= pos) {
            fill1(arr, neg, pos);
        }
        else {
            // reverse the array in this condition
            reverse(arr, n);
            fill2(arr, neg, pos);
        }
    }
}
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

// Partitioning routine of Quicksort
int partition(int A[], int n)
{
    int j = 0;
    int pivot = 0;    // consider 0 as a pivot

    // each time we find a negative number, `j` is incremented,
    // and a negative element would be placed before the pivot
    for (int i = 0; i < n; i++)
    {
        if (A[i] < pivot)
        {
            swap(A[i], A[j]);  //{ 9, -3, 5, -2, -8, -6, 1, 3 }; // -3 -2 -8 -6
            j++;
        }
    }

    // `j` holds the index of the first positive element
    return j;
}

// Function to rearrange a given array such that it contains positive
// and negative numbers at alternate positions
int rearrange(int A[], int size)
{
    // partition a given array such that all positive elements move
    // to the end of the array
    int p = partition(A, size);

    // swap alternate negative elements from the next available positive
    // element till the end of the array is reached, or all negative or
    // positive elements are exhausted.

    for (int n = 0; (p < size && n < p); p++, n += 2) {
        swap(A[n], A[p]);
    }
}

int main()
{
    int A[] = { 9, -3, 5, -2, -8, -6, 1, 3 };
    int n = sizeof(A)/sizeof(A[0]);

    rearrange(A, n);

    // print the rearranged array
    for (int i = 0; i < n; i++) {
        cout << setw(3) << A[i];
    }

    return 0;
}