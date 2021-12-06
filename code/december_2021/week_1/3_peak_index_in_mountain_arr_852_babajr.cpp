/*
Question Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/
*/

#include <bits/stdc++.h>
using namespace std;


/*
Brute Force: TC = O(n).

API to search the peak element in the mountain array.
Parameters:
int *arr: base pointer pointing to the first element of array.
int size: size of the array.

Return Type: int
On success, API returns index of the peak element.
There won't be any failure case as arr is guaranteed to be a mountain array.

*/
int peakIndexInMountainArrayBf(int arr[], int size)
{
    int index = -1;

    for(int i = 1; i < (size - 1); i++)
    {
        if(arr[i] > arr[i + 1] && arr[i] > arr[i - 1])
        {
            index = i;
            break;
        }
    }

    return index;
}


/*
Efficient Approach: Using Binary Search, TC = O(log n).

API to search the peak element in the mountain array.
Parameters:
int *arr: base pointer pointing to the first element of array.
int size: size of the array.

Return Type: int
On success, API returns index of the peak element.
There won't be any failure case as arr is guaranteed to be a mountain array.
*/
int peakIndexInMountainArray(int* arr, int size)
{
    int start = 0;
    int end = size - 1;

    while(start < end)
    {
        // get the mid element of the array
        int mid = (start + end) / 2;

        // arr[mid] is either peak or present in the decreasing part of the array.
        if(arr[mid] > arr[mid + 1])
            end = mid; // search in the left subarray
        // arr[mid] is present in the increasing part of the array
        else
            start = mid + 1; // search in the right subarray
    }

    return start;
}


/*
Driver code.
*/
int main(void)
{
    // int arr[] = {0,1,0};
    int arr[] = { 0,2,1,0};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", peakIndexInMountainArray(arr, size));
    printf("%d\n", peakIndexInMountainArrayBf(arr, size));

    return 0;
}
