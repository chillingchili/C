#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int s1, s2;
    printf("Enter the number of elements in the first array: ");
    scanf(" %d", &s1);
    int *arr1 = (int *)malloc(s1 * sizeof(int));
    printf("Enter the elements of the first array: ");
    for(int i = 0; i < s1; i++){
        scanf(" %d", &arr1[i]);    
    }
    printf("Enter the number of elements in the second array: ");
    scanf(" %d", &s2);
    int *arr2 = (int *)malloc(s2 * sizeof(int));
    printf("Enter the elements of the second array: ");
    for(int i = 0; i < s2; i++){
        scanf(" %d", &arr2[i]);    
    }
    int newSize = s1 + s2;
    arr1 = (int *)realloc(arr1, newSize*sizeof(int));
    memcpy(&arr1[s1], arr2, s2*sizeof(int));
    printf("Concatenated array: ");
    for(int i = 0; i < newSize; i++){
        printf("%d ", arr1[i]);
    }
    free(arr1);
    free(arr2);
    return 0;
}