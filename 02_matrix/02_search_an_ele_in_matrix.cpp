/*
    link: https://leetcode.com/problems/search-a-2d-matrix/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
// search in rowwise column wise sorted-aditya verma- O(m+n) meeeeeeeeeeeeeeeeeeeeeeeeeeee
// C++ program to search an element in row-wise
// and column-wise sorted matrix
#include <bits/stdc++.h>

using namespace std;

/* Searches the element x in mat[][]. If the
element is found, then prints its position
and returns true, otherwise prints "not found"
and returns false */
int search(int mat[4][4], int n, int x)
{
	if (n == 0)
		return -1;

	int smallest = mat[0][0], largest = mat[n - 1][n - 1];
	if (x < smallest || x > largest)
		return -1;

	// set indexes for top right element
	int i = 0, j = n - 1;
	while (i < n && j >= 0)
	{
		if (mat[i][j] == x)
		{
			cout << "Element found at "
				<< i << ", " << j;
			return 1;
		}
		if (mat[i][j] > x)
			j--;

		// Check if mat[i][j] < x
		else
			i++;
	}

	cout << "n Element not found";
	return 0;
}

// Driver code
int main()
{
	int mat[4][4] = { { 10, 20, 30, 40 },
					{ 15, 25, 35, 45 },
					{ 27, 29, 37, 48 },
					{ 32, 33, 39, 50 } };
	search(mat, 4, 29);

	return 0;
}



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using binary search- rowwise sorted but next row ka element greeater that prev ka last to overall each
    array is sorted and there are n sorted arrrays(each row)
    so imaginary 1 d arraty imagine krk bs lgao
    TC: O(log(mn)) meeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
*/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // treat the matrix as an array, just taking care of indices
    // [0..n*m]
    // (row, col) -> row*n + col
    // i -> [i/n][i%n]
    if (matrix.empty() || matrix[0].empty())
    {
        return false;
    }
    int m = matrix.size(), n = matrix[0].size();
    int start = 0, end = m * n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int e = matrix[mid / n][mid % n];
        /*
            here mid/n show how many complete row do we have
            while mid % n is just that column doesn't overflow.
        */
        if (target < e)
        {
            end = mid - 1;
        }
        else if (target > e)
        {
            start = mid + 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}
// This code is contributed
// by Akanksha Rai(Abby_akku)

/*
    simple approach, by smallest ele in row and then smallest ele in that row's col.
    TC: O(max(row, col))
*/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size(), col = matrix[0].size();

    int i = row - 1, j = col - 1;
    while (i > 0 && matrix[i][0] > target) i--;
    while (j > 0 && matrix[i][j] > target) j--;
    return matrix[i][j] == target;
}
