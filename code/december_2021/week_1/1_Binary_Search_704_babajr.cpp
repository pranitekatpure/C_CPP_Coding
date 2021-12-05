/*
Qestion Link: https://leetcode.com/problems/binary-search/
*/

#include <bits/stdc++.h>
using namespace std;


/*
API to search the target in the sorted array.
Parameters:
int *arr: base pointer pointing to the first element of array.
int size: size of the array.
int target: the element to be searched in the array.

Return Type: int
On success, API returns index of the target value. Otherwise return -1.
*/
int search(int* arr, int size, int target)
{
    int start = 0;
    int end = size - 1;

    while(start <= end)
    {
        // get the mid element of the array
        int mid = (start + end) / 2;

        // target found, return index mid.
        if(arr[mid] == target)
            return mid;
        // target is less than value at mid, obviously target may lie left to mid index
        // (start to end = mid - 1).
        else if(arr[mid] > target)
            end = mid - 1;
        // otherwise, target may lie in the second half of array (start = mid + 1 to end)
        else
            start = mid + 1;
    }

    return -1;
}


/*
Driver code.
*/
int main(void)
{
    int arr[] = {-1,0,3,5,9,12};
    int target;
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Enter the target value: ");
    scanf("%d", &target);

    // print index if target found, else prints -1.
    printf("%d\n", search(arr, size, target));

    return 0;
}
