/*
    link: https://practice.geeksforgeeks.org/problems/three-way-partitioning/1
*/



// ----------------------------------------------------------------------------------------------------------------------- //
void threeWayPartition(vector<int>& array, int a, int b)
{
    int i = 0, n = array.size() - 1, j = 0;

    while (j <= n) {
        if (array[j] < a) {
            swap(array[j++], array[i++]);   // we r sure after swap we won't get <a, bcoz it would have processed earlier.
        }
        else if (array[j] > b) {
            swap(array[n--], array[j]);    // here it is possible that after swap we can get >b value again hence no increment in j.
        }
        else j++;
    }
}