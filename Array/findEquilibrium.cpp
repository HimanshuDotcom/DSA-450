int findEquilibrium(int arr[], int n)
{
  //Your code here
  int sum = 0;
  for(int i = 0; i < n; i++)
    sum += arr[i];
  int leftSum = arr[0];
  for(int i = 1; i < n-1; i++) {
      int rightSum = sum - (leftSum + arr[i]);
      if(leftSum == rightSum)
        return i;
      leftSum += arr[i];
  }
  return -1;
}
