#include <stdio.h>
int elmntSrch(int arr[], int size, int x) {
    int rec;
    size--;
    if (size >= 0) {
        if (arr[size] == x)
            return size;
        else
            rec = elmntSrch(arr, size, x);
    }
    else
        return -1;
    return rec;
}

int recursiveBinarySearch(int array[], int start_index, int end_index, int element){
   if (end_index >= start_index){
      int middle = start_index + (end_index - start_index )/2;
      if (array[middle] == element)
         return middle;
      if (array[middle] > element)
         return recursiveBinarySearch(array, start_index, middle-1, element);
      return recursiveBinarySearch(array, middle+1, end_index, element);
   }
   return -1;
}

int main(){
    int arr[] = {12, 34, 54, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int x = 3;
    int indx;
    indx = elmntSrch(arr, size, x);
    if (indx != -1)
        printf("Linear search: Element %d is present at index %d", x, indx);
    else
        printf("Linear search: Element %d is not present", x);
    int index=recursiveBinarySearch(arr,0,4,54);
    printf("\n");
    if (index != -1)
        printf("Binary search: Element %d is present at index %d", 54, index);
    else
        printf("Binary search: Element %d is not present", 54);
    return 0;
}