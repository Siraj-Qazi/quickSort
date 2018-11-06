#include <iostream>

void swapVal(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

long swapCount = 0;

int partition(int arr[], int first, int pivotIndex) {  // Partition function
    int j = first;
    int pivot = arr[pivotIndex];
    for (int i = first; i < pivotIndex; ++i) {
        if (arr[i] <= pivot) {
            if (arr[i] != arr[j]) {
                std::cout << "\n Swapping " << arr[i] << " with " << arr[j];
                swapVal(&arr[i], &arr[j]);
                swapCount++;
            }
            j += 1;
        }
    }
    swapVal(&arr[j], &arr[pivotIndex]);
    swapCount++;
    return j;
}

void quickSort(int arr[], int start, int end) {  // Recursive quickSort function
    if (start < end) {
        std::cout << "\n Partitioning array from " << start << " to " << end;
        int mid = partition(arr, start, end);  // Partition the array into two halves

        std::cout << "\n\n QuickSorting lower sub half " << start << " : " << mid - 1;
        quickSort(arr, start, mid - 1);      // Call quickSort on lower sub half

        std::cout << "\n\n QuickSorting upper sub half " << mid + 1 << " : " << end;
        quickSort(arr, mid + 1, end);        // Call quickSort on upper sub half
    }
}

int main() {
    /* std::cout << "\n Enter size of array: ";
     int size;
     std::cin >> size;
     while (!std::cin || size < 1) {
         std::cin.ignore(std::numeric_limits<int>::max(), '\n');
         std::cin.clear();
         std::cout << "\n Invalid size! Please enter a natural number: ";
         std::cin >> size;
     }
     */

    int size = 1000;
    int *array = new int[size];
    // std::cout << "\n Begin entering data.\n";

    std::cout << "\n Input Array: \n\n [ ";

    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        /*std::cout << "\n Enter element " << i + 1 << ": ";
        std::cin >> array[i]; */

        array[i] = rand() + (i + rand());
        std::cout << "\t" << array[i];
        if (i != size - 1)
            std::cout << ",";
    }
    std::cout << " ]";
    quickSort(array, 0, size - 1);

    std::cout << "\n\n ######################################################################"
              << "\n\n The array sorted by quickSort is:\n\n [";
    for (int i = 0; i < size; ++i) {
        std::cout << "\t" << array[i];
        if (i != size - 1)
            std::cout << ",";
    }
    std::cout << " ]";

    std::cout << "\n -------------------------------------------------------------------------"
              << "\n\n Total swaps made to sort this " << size << "-element array: " << swapCount;

    getchar();
}
	
	