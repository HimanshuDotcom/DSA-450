
void sort012(int *arr, int n)
{
    //Write your code here
    int zeroIndex = 0,
    twoIndex = n-1,
    i = 0;
    
    while(i <= twoIndex) {
        if(arr[i] == 0) {
            std::swap(arr[zeroIndex], arr[i]);
            zeroIndex++;
            i++;
        }
        else if(arr[i] == 2) {
            std::swap(arr[twoIndex], arr[i]);
            twoIndex--;
        }
        else
            ++i;
    }
}
