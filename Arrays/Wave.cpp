
/*
Q: Sort the array to form a wave
A: Starting from the second element, compare with previous element
   to either swap or not the next element
*/


#include <iostream>

using namespace std;

void printArray(int array[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

void waving(int data[], int size)
{
    int i;
    for(i=1;i<size-1;i++)
    {
        if(data[i-1]<=data[i] && data[i+1]>=data[i])
        {
           swap(&data[i],&data[i+1]);
        }

        else if(data[i-1]>=data[i] && data[i+1]<=data[i])
        {
            swap(&data[i],&data[i+1]);
        }

    }

}

int main()
{
    int data[] = {1, 3, 6, 3, 7, 8, 9, 3, 4, 7, 2, 4};
    int n = sizeof(data) / sizeof(data[0]);

    waving(data, n);
    printArray(data, n);
    return 0;
}
