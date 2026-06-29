
#include <iostream>
using namespace std;

const int SIZE = 10;


int linearSearch(int arr[], int size, int target);
int binarySearch(int arr[], int size, int target);


void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);


void quickSort(int arr[], int low, int high);
int  partition(int arr[], int low, int high);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);


void printArray(int arr[], int size);
void copyArray(int src[], int dest[], int size);


int main()
{
    
    int original[SIZE] = {64, 25, 12, 78, 33, 90, 47, 5, 61, 18};

    int arr[SIZE];

    cout << "=== Chapter 18: Searching and Sorting ===" << endl << endl;


    cout << "--- Linear Search ---" << endl;
    cout << "Array: ";
    printArray(original, SIZE);

    int target = 78;
    int result = linearSearch(original, SIZE, target);
    if (result != -1)
        cout << "Found " << target << " at index " << result << endl;
    else
        cout << target << " not found." << endl;

    target = 99;
    result = linearSearch(original, SIZE, target);
    if (result != -1)
        cout << "Found " << target << " at index " << result << endl;
    else
        cout << target << " not found." << endl;

    cout << endl;


    cout << "--- Bubble Sort ---" << endl;
    copyArray(original, arr, SIZE);
    cout << "Before: ";
    printArray(arr, SIZE);

    bubbleSort(arr, SIZE);

    cout << "After:  ";
    printArray(arr, SIZE);
    cout << endl;


    cout << "--- Selection Sort ---" << endl;
    copyArray(original, arr, SIZE);
    cout << "Before: ";
    printArray(arr, SIZE);

    selectionSort(arr, SIZE);

    cout << "After:  ";
    printArray(arr, SIZE);
    cout << endl;


    cout << "--- Insertion Sort ---" << endl;
    copyArray(original, arr, SIZE);
    cout << "Before: ";
    printArray(arr, SIZE);

    insertionSort(arr, SIZE);

    cout << "After:  ";
    printArray(arr, SIZE);
    cout << endl;


    cout << "--- Quick Sort (scaffolded) ---" << endl;
    copyArray(original, arr, SIZE);
    cout << "Before: ";
    printArray(arr, SIZE);

    quickSort(arr, 0, SIZE - 1);

    cout << "After:  ";
    printArray(arr, SIZE);
    cout << endl;


    cout << "--- Merge Sort (scaffolded) ---" << endl;
    copyArray(original, arr, SIZE);
    cout << "Before: ";
    printArray(arr, SIZE);

    mergeSort(arr, 0, SIZE - 1);

    cout << "After:  ";
    printArray(arr, SIZE);
    cout << endl;


    cout << "--- Binary Search ---" << endl;
    copyArray(original, arr, SIZE);
    bubbleSort(arr, SIZE);  
    cout << "Sorted array: ";
    printArray(arr, SIZE);

    target = 47;
    result = binarySearch(arr, SIZE, target);
    if (result != -1)
        cout << "Found " << target << " at index " << result << endl;
    else
        cout << target << " not found." << endl;

    target = 99;
    result = binarySearch(arr, SIZE, target);
    if (result != -1)
        cout << "Found " << target << " at index " << result << endl;
    else
        cout << target << " not found." << endl;

    cout << endl;

    return 0;
}





void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}


void copyArray(int src[], int dest[], int size)
{
    for (int i = 0; i < size; i++)
        dest[i] = src[i];
}



int linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
            return i;   
    }
    return -1;          
}



void bubbleSort(int arr[], int size)
{
    int i, j, temp;
    bool swapped;

    for (i = 0; i < size - 1; i++)
    {
        swapped = false;

        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]) 
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = true;
            }    
        }

        if (!swapped)
        {
            break;
        }
    }

}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {64, 25, 12, 78, 33, 90, 47, 5, 61, 18};
    int size = sizeof(data) / sizeof(data[0]);
    
    printf("Original array:\n");
    printArray(data, size);
    
    bubbleSort(data, size);
    
    printf("Sorted array in ascending order:\n");
    printArray(data, size);
    
    return 0;
}


void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++) {
        
        int min_idx = i;
        
        
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; 
            }
        }
        
        
        if (min_idx != i) {
            swap(&arr[min_idx], &arr[i]);
        }
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {64, 25, 12, 78, 33, 90, 47, 5, 61, 18};
    int size = sizeof(data) / sizeof(data[0]);
    
    printf("Original array:\n");
    printArray(data, size);
    
    selectionSort(data, size);
    
    printf("Sorted array in ascending order:\n");
    printArray(data, size);
    
    return 0;
}


void insertionSort(int arr[], int size)
{
   for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }

}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {64, 25, 12, 78, 33, 90, 47, 5, 61, 18};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Original array:\n");
    printArray(data, size);

    insertionSort(data, size);

    printf("Sorted array in ascending order:\n");
    printArray(data, size);

    return 0;
}


int partition(int arr[], int low, int high)
{
    int pivot = arr[high];  
    int i = low - 1;        

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            
            int temp = arr[i];
            arr[i]   = arr[j];
            arr[j]   = temp;
        }
    }

    
    int temp   = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high]  = temp;

    return i + 1;  
}


void quickSort(int arr[], int low, int high)
{
    
    if (low >= high)
        return;

    
    int pi = partition(arr, low, high);

   
    quickSort(arr, low, pi - 1);   
    quickSort(arr, pi + 1, high);  
}



void merge(int arr[], int left, int mid, int right)
{
   
    int n1 = mid - left + 1;
    int n2 = right - mid;

    
    int L[n1], R[n2];

    
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

   
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}


void mergeSort(int arr[], int left, int right)
{
    
    if (left >= right)
        return;

   
    int mid = left + (right - left) / 2;

   
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    
    merge(arr, left, mid, right);
}



int binarySearch(int arr[], int size, int target)
{
int low = 0;
    int high = size - 1;

    while (low <= high) {
        
        int mid = low + (high - low) / 2;

       
        if (arr[mid] == target) {
            return mid;
        }
        
       
        if (arr[mid] < target) {
            low = mid + 1;
        } 
        
        else {
            high = mid - 1;
        }
    }

    return -1;  
}

int main() {
    
    int arr[] = {5, 12, 18, 25, 33, 47, 61, 64, 78, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 47;

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}