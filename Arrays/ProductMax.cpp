

/*
Q: Find two integers that produce the largest product in an array.
A: First use Quick Sort to sort in ascending order.
   Then compare product of first two and last two integers
   Complexity : O(nlogn). Comparison will be a constant operation
*/


#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}
void printArray(int array[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}
int partition(int array[], int low, int high)
{
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++)
  {
    if (array[j] <= pivot)
    {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  printArray(array, 7);
  cout << "........\n";
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}
void quickSort(int array[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}
int main()
{
  int data[] = {20, 2, -6, -19, 3, 3, -13};
  int n = sizeof(data) / sizeof(data[0]);
  quickSort(data, 0, n - 1);
  cout << "Sorted array in ascending order: \n";
  printArray(data, n);

  if((data[n-1]*data[n-2]) < (data[0]*data[1]))
  {
     cout << "Integers producing max result are : " << data[0] << " and " << data[1];
  }
  else
  {
     cout << "Integers producing max result are : " << data[n-1] << " and " << data[n-2];
  }


  return 0;
}


