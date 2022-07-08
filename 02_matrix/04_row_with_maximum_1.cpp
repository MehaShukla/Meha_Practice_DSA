/*
    link: https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1
  -row wise sorted h
    logic: if we get 1 shift to left and if not then shift to bottom-
*/

//brute force= take out no of 1s in each row and after i traversal compare with a variable- O(n sq)
//jisme b max aye vhi row return

// ----------------------------------------------------------------------------------------------------------------------- //
// TC: O(m+n)- Me
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {// traverse top to bottom instead left to right
	int res=-1;//jha b 1 milega phle vhi 1 ka starting point hoga us row k liye jiska b 1 phle mil gya
    //mtlb us row me bhut ones h
	    for(int col=0;col<m;col++){// swapped order of row col
	        for(int row=0;row<n;row++){
	            if(arr[row][col] == 1){
	                return row;
	            }
	     }
	   }
	   return res;

	   ///////////////////////////////////////////////////////////
int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
        // code here
    int row = 0, col = m - 1, ans = -1;

    while (col >= 0 && row < n) {
        if (arr[row][col] == 1) {
            one = max(one, col);
            ans = max(ans, row);
            col--;
        }
        else row++;
    }
    return ans;
}




// ----------------------------------------------------------------------------------------------------------------------- //
// similar solution
int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
    int r = 0;              // keeps track of row; starts at first row
    int c = m - 1;            // keeps track of column; starts at last column
    int max_row_index = -1;   // keeps track of result row index

    // starting from top right corner
    // go left if you encounter 1
    // do down if you encounter 0
    while (r < n && c >= 0)
    {
        if (arr[r][c] == 1)
        {
            max_row_index = r;
            c--;
        }
        else
            r++;
    }
    return max_row_index;
}