/*
Question Link: https://leetcode.com/problems/find-peak-element/
*/

#include <bits/stdc++.h>
using namespace std;


/*
Efficient Approach: Using Binary Search, TC = O(log n).

API to search the peak element. A peak element is an element that is strictly
greater than its neighbors.
Parameters:
int *arr: base pointer pointing to the first element of array.
int size: size of the array.

Return Type: int
On success, API returns index of the peak element.
*/
int findPeakElement(int* arr, int size)
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
    int arr[] = {1,2,1,3,5,6,4};
    // int arr[] = {1,2,3,1};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", findPeakElement(arr, size));

    return 0;
}
