/*
    link: https://practice.geeksforgeeks.org/problems/max-rectangle/1#

    sol: https://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/
    Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1’s.

    video(watch just for the animation from here): https://youtu.be/hGl8Boeb7S4?t=70
*/



// -------------------------------------------------------------------------------------
max area histogram
https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
int main(){
    int arr[] = {6,2,5,4,5,1,6};
    // To calculate NLR
    vector<int> right;
    stack<pair<int,int>> s1;

    for(int i=6; i>=0; i--){
    if(s1.empty()){
        right.push_back(7);
    }
  else if(s1.size()>0 && s1.top().first<arr[i]){
      right.push_back(s1.top().second);
  }
    else if(s1.size()>0 && s1.top().first>=arr[i]){
        while(s1.size()>0 && s1.top().first>=arr[i]){
            s1.pop();
        }
        if(s1.empty()){
            right.push_back(7);
        }
        else{
            right.push_back(s1.top().second);
        }
    }
    s1.push({arr[i],i});
    }
     reverse(right.begin(),right.end());
     for(int i=0; i<7; i++){
         cout<<right[i]<<" ";
     }
   cout<<endl;
// To calculate NLL

  vector<int> left;
stack<pair<int,int>> s2;

for(int i=0; i<7; i++){
    if(s2.empty()){
        left.push_back(-1);
    }
    else if(s2.size()>0 && s2.top().first<arr[i]){
        left.push_back(s2.top().second);
    }
    else if(s2.size()>0 && s2.top().first>=arr[i]){
        while(s2.size()>0 && s2.top().first>=arr[i]){
            s2.pop();
        }
        if(s2.empty()){
            left.push_back(-1);
        }
        else{
            left.push_back(s2.top().second);
        }
    }
    s2.push({arr[i],i});
}
  for(int i=0; i<7; i++){
      cout<<left[i]<<" ";
  }
    cout<<endl;
   vector<int> width;
   for(int i=0; i<7; i++){
       width.push_back(right[i]-left[i]-1);
   }
   for(int i=0; i<7; i++){
       cout<<width[i]<<" ";
   }
   cout<<endl;
   int max=0;
   for(int i=0; i<7; i++){
       if((width[i]*arr[i])>max){
           max = (width[i]*arr[i]);
       }
   }
    cout<<"The Area of Histogram is- "<<max<<endl;
    return 0;
}
///////////////////max area rectangle in a binary matrix

CHIRAG SAHU
1 year ago
//MAX RECT AREA IN A BINARY MATRIX
#include<iostream>
#include<stack>
using namespace std;
int* NSLi(int arr[], int n)
{//CHECKED
	int* NSLi = new int[n];
	stack <pair<int,int>> st;
	for(int i = 0 ; i < n ; i ++)
	{
		if(!st.size())
			NSLi[i] = -1;
		else if (st.top().first < arr[i])
			NSLi[i] = st.top().second;
		else
		{
			while(st.size() > 0 && st.top().first >= arr[i])
				st.pop();
			if(!st.size())
				 NSLi[i] = -1;
			else NSLi[i] = st.top().second;
		}
	st.push({arr[i],i});
	}
	return NSLi;
}
int* NSRi(int arr[], int n)
{//CHECKED
	int* nsri = new int [n];
	stack < pair <int,int> > st;
	for(int i = n-1; i >= 0 ; i --)
	{
		if(!st.size())
			nsri[i] = n;
		else if (st.top().first < arr[i])
			nsri[i] = st.top().second;
		else
		{
			while(st.size()>0 && st.top().first >= arr[i])
				st.pop();
			if(!st.size())
				nsri[i] = n;
			else nsri[i] = st.top().second;
		}
	st.push({arr[i],i});
	}
	return nsri;
}
int MAH(int arr[], int n)
{//CHECKED
	int* nsli = NSLi(arr,n);
	int* nsri = NSRi(arr,n);

	int area[n];
	for(int i = 0 ; i < n ; i ++)
		area[i] = arr[i] * (nsri[i] - nsli[i] - 1);
	int max = 0;
		for(int i = 0 ; i < n ; i ++)
			if (area[i] >= max)
				max = area[i];

	return max;
}
int main()
{
	freopen("input.txt","r",stdin);
	int n , m ; cin >> n >> m;
	int arr[n][m];

	for(int i = 0 ; i < n ; i ++)
		for (int j = 0 ; j < m ; j ++)
			cin >> arr[i][j];			//input

	for(int i = 1 ; i < n ; i ++)
		for(int j = 0 ; j < m ; j++)
			if(arr[i][j] > 0)
				arr[i][j] += arr[i-1][j] ;

	int ans[n];
	for(int i = 0 ; i < m ; i ++)
		ans[i] = MAH(arr[i],m);

	int max = 0;
	for(int i = 0 ; i < n ; i ++)
		if (ans[i] >= max)
			max = ans[i];

	cout << max << endl;

}
///////////////////////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

// Finds the maximum area under
// the histogram represented
// by histogram. See below article for details.
class Solution {
    public:
    int mhist(int row[], int m1) {
        // Create an empty stack.
        // The stack holds indexes of
        // hist[] array/ The bars stored
        // in stack are always
        // in increasing order of their heights.
        stack<int> result;

        int top_val;  // Top of stack

        int max_area = 0;  // Initialize max area in current

        int area = 0; // Initialize area with current top

        int i = 0;

        // Run through all bars of given histogram (or row)
        for (i = 0; i < m1;) {
            // If this bar is higher than the bar on top stack,
            // push it to stack
            if (result.empty() || row[result.top()] <= row[i])
                result.push(i++);

            else {
                // If this bar is lower than top of stack, then
                // calculate area of rectangle with stack top as
                // the smallest (or minimum height) bar. 'i' is
                // 'right index' for the top and element before
                // top in stack is 'left index'
                top_val = row[result.top()];
                result.pop();

                // this will be understood after watching the video
                area = row[top_val] * (result.empty() ? i : i - result.top() - 1);

                max_area = max(area, max_area);
            }
        }

        // Now pop the remaining bars from stack and calculate
        // area with every popped bar as the smallest bar
        while (!result.empty()) {
            top_val = row[result.top()];
            result.pop();

            area = row[top_val] * (result.empty() ? i : i - result.top() - 1);

            max_area = max(area, max_area);
        }
        return max_area;
    }


    // Returns area of the largest rectangle with all 1s in
    // A[][]
    int kewl(int M[MAX][MAX], int n, int m) {
        // Calculate area for first row and initialize it as
        // result
        int res = mhist(M[0], m);

        // iterate over row to find maximum rectangular area
        // considering each row as histogram
        for (int i = 1; i < n; i++) {

            // just to update the current row
            for (int j = 0; j < m; j++) {
                // if it's 1 then add the prev value to current else leave it
                if (M[i][j]) M[i][j] += M[i - 1][j];
            }

            // Update result if area with current row (as last
            // row) of rectangle) is more
            res = max(res, mhist(M[i], m));
        }
        return res;
    }


    // main function
    int maxArea(int M[MAX][MAX], int n, int m) {
        return kewl(M, n, m);
    }
};
