/*
Problem link: https://leetcode.com/problems/find-in-mountain-array/
*/


#include <bits/stdc++.h>
using namespace std;


/*
Brute Force Approach.
API to find the target in mountain array.
TC = O(n).
*/
int find_in_mountain_arr_bf(int arr[], int size, int target)
{
    int index = -1;

    for(int i = 1; i < (size - 1); i++)
    {
        if(arr[i] == target)
        {
            index = i;
            break;
        }
    }

    return index;
}


/*
Helper API to search element in an array using order agnostic binary search.
TC = O(log n)
*/
int order_agnostic_search(int arr[], int size, int target, int start, int end)
{
    bool is_ascending = arr[start] < arr[end]; // True is array is in increasing.

    while(start <= end)
    {
        int mid = (start + end) / 2;

        // element is present at the mid. Return mid index.
        if(arr[mid] == target)
            return mid;

        if(is_ascending == 1) // array is increasing array
        {
            // element is present in the left subarray. reduce the window of search.
            if(arr[mid] > target)
                end = mid - 1;
            // element is present in the right subarray. reduce the window of search.
            else
                start = mid + 1;
        }
        else
        {
            if(arr[mid] > target)
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    return -1; // If element is not found in the array we will return -1.
}


/*
Helper API to find the index of peak in the mountain array
*/
int peak_index_mountain_arr(int arr[], int size)
{
    int start = 0;
    int end = size - 1;

    while(start < end) // this condition is very important
    {
        int mid = (start + end) / 2;

        // if arr[mid] is present in the decreasing part of the array
        if(arr[mid] > arr[mid + 1])
        {
            end = mid; // search in the left subarray
        }
        // if arr[mid] is present in the increasing part of the array
        else
        {
            start = mid + 1; // search in the right subarray
        }
    }

    // when the loop ends, start will always be pointing to the peak of the element.
    return start;
}


/*
API to find the target in mountain array.
TC = O(log n).

Parameters:
int *arr: base pointer pointing to the first element of array.
int size: size of the array.
int target: the element to be searched in the array.

Return Type: int
On success, API returns index of the target value. Otherwise return -1.
*/
int find_in_mountain_arr(int arr[], int size, int target)
{
    // get the index of peak element.
    int peak = peak_index_mountain_arr(arr, size);

    // search in the increasing subarray.
    int first_attempt = order_agnostic_search(arr, size, target, 0, peak);

    if(first_attempt != -1) // target found, return its index.
        return first_attempt;
    // search in the decreasing subarray.
    else
        return order_agnostic_search(arr, size, target, peak + 1, size - 1);
}


/*
Driver code.
*/
int main(void)
{
    // int arr[] = {1,2,3,4,5,3,1};
    int arr[] = {0,1,2,4,2,1};
    int target;
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Enter the target to be searched: ");
    scanf("%d", &target);

    // int index = find_in_mountain_arr_bf(arr, size, target);
    printf("%d\n", find_in_mountain_arr(arr, size, target));

    return 0;
}
