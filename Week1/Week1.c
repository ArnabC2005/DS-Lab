#include<stdio.h>
#include<stdlib.h>

void printArray(int * arr, int n) {
for(int i=0;i<n;i++){
printf("%d\t", arr[i]);
}
printf("\n");

}

void SelectionSort(int * arr, int n) {
for(int i=0;i<n-1;i++){
int small=arr[i];
int min_pos=i;
for(int j=i+1; j<n;j++) {
if(arr[j]<small) {
small=arr[j];
min_pos=j;
}
}

arr[min_pos]=arr[i];
arr[i]=small;
}
}


int main() {
int arr[]={7,8,9,56,78,90};

int n=6;

printArray(arr,n);

SelectionSort(arr,n);

printArray(arr,n);




}
