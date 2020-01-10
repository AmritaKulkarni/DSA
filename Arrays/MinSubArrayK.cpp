/*
Q: Find the sub array of size k that yields the lowest sum
A: Use a sliding window that moves through the array and update the lowest sum
   while keeping track of the starting index
*/


#include <iostream>

using namespace std;

void findMinSubArrayK(int data[], int n, int k)
{
    int i;
    int sum = 0;
    int sum_new = 0;
    for(i=0;i<k;i++) // find the sum of the first window of size k
    {
        sum = sum+data[i];
    }
    cout << "sum: " << sum << endl;
    i=1;
    sum_new = sum;
    int start = 0;
    while(i<=(n-k))
    {
        sum_new = sum_new - data[i-1] + data[i+k-1]; // the new sum is found by subtracting the old index and adding new index value
        //cout << "data[" << i << "-1] :" << data[i-1] << "  data[" << i << "+" << k << "-1]: " << data[i+k-1] << "  sum_new : " <<sum_new << endl;

        if(sum_new < sum) // compare if the new sum is lower than the old sum
        {
            sum = sum_new;
            start = i;
            //cout << "updated sum is : " << sum << endl;
        }
        i++;
        //cout << "updated i : " << i << endl;
    }

    cout << "final start : " << start << endl; // print the start index of the sub array that yields lowest sum
}

int main()
{
    int data[] = {3,0,0,5,6,3,8,0,0,16};
    int n = sizeof(data) / sizeof(data[0]);
    int k = 3;

    findMinSubArrayK(data, n, k);

    return 0;
}

