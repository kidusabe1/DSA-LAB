#include<stdio.h>
#include<math.h>

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
            
           if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
int main()
{
	int choice;
	int arr[] = { 1, 5, 2, 4, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	printf ("Enter your choice: ");
	scanf ("%d", &choice);
	
	switch (choice)
	{
		case 1:	 
		    insertionSort(arr, n);
		    printArray(arr, n);
		    break;
		    
		case 2:
			selectionSort(arr, n);
			printArray(arr, n);
			break;
		
		case 3:
			bubbleSort(arr, n);
			printArray(arr, n);
			break;
		
		default:
			printf ("Enter the correct option.");
			break;
	}
	
	return 0;
}