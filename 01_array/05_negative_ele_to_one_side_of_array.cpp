/*
    link: https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/

    variation: 2-pointer
*/


// ----------------------------------------------------------------------------------------------------------------------- //
void arrange(int a[], int n) {
    int negi = 0;
    int posi = n - 1;

    while (negi <= posi) {
        if (a[negi] < 0 && a[posi] < 0) {
            negi++;
        }
        else if (a[negi] > 0 && a[posi] < 0) {
            swap(a[negi], a[pos]);
            negi++;
            pos--;
        }
        else if (a[negi] > 0 && a[posi] > 0) posi--;
        else {
            negi++;
            posi--;
        }
    }
}
int j=n-1,i=0;
while(i<=j)
{
    if(a[i]>0)
swap(a[i],a[j--]);       //-7, 5, -3, -6 // -7 -6 -3 5 j=2
else// i=1, j=3
i++;

}