/*
Order agnostic binary search.

Given a sorted array of numbers, find if a given number ‘key’ is
present in the array.
We don’t know if it’s sorted in ascending or descending order.
You should assume that the array can have duplicates.

Input: [10, 6, 4], key = 10
Output: 0

Input: [4, 6, 10], key = 10
Output: 2
*/

#include <bits/stdc++.h>
using namespace std;


/*
API to search the target in the sorted array which can be either sorted in
ascending or descending way.
Parameters:
int *arr: base pointer pointing to the first element of array.
int size: size of the array.
int target: the element to be searched in the array.

Return Type: int
On success, API returns index of the target value. Otherwise return -1.
*/
int order_agnostic_search(int* arr, int size, int target)
{
    int start = 0;
    int end = size - 1;

    // true: array is sorted in increasing/asceding order.
    // false: array is sorted in decreasing/dessceding order.
    bool is_increasing = arr[start] < arr[end];

    while(start <= end)
    {
        // get the mid element of the array
        int mid = (start + end) / 2;

        // target found, return index mid.
        if(arr[mid] == target)
            return mid;

        if(is_increasing == true)
        {
            // target is less than value at mid, obviously target may
            // lie left to mid index (start to end = mid - 1).
            if(arr[mid] > target)
                end = mid - 1;
            // otherwise, target may lie in the second half of array
            // (start = mid + 1 to end)
            else
                start = mid + 1;
        }
        else
        {
            // reverse the above logic as array is sorted in decreasing order.
            if(arr[mid] > target)
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    return -1;
}


/*
Driver code.
*/
int main(void)
{
    // int arr[] = {10, 6, 4};
    int arr[] = {4, 6, 10};
    int target;
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Enter the target value: ");
    scanf("%d", &target);

    // print index if target found, else prints -1.
    printf("%d\n", order_agnostic_search(arr, size, target));

    return 0;
}
