#include <iostream>

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int lo, int hi)
{
    int pivot = arr[hi];
    int i = (lo - 1);
    for (int j = lo; j < hi; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    
    i++;
    swap(arr, i, hi);
    
    return i;
}

void quicksort(int arr[], int lo, int hi)
{
    if ((lo > hi) || (lo < 0))
    {
        return;
    }

    int p = partition(arr, lo, hi);
    quicksort(arr, lo, p - 1);
    quicksort(arr, p + 1, hi);

    return;
    
}

int main(int argc, char** argv)
{

    int arr[] = {4, 1, 2, 6, 8, 7, 11, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Unsorted array:\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    quicksort(arr, 0, n - 1);

    std::cout << "Sorted array:\n";

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}