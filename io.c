#include <stdio.h>

void merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;

    int temp[100];

    // Compare both halves
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Remaining elements of left half
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Remaining elements of right half
    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy temp back to arr
    for (i = low, k = 0; i <= high; i++, k++)
    {
        arr[i] = temp[k];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        // Divide
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Merge
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {38, 12, 27, 43, 9, 31, 18, 25};
    int n = 8;

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}