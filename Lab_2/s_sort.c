#include<stdio.h>
#include<stdlib.h>

int selection_sort(int arr[],int n, int i) {

	int small=arr[i];
	int min_pos=i;

	for(int j=i+1;j<n;j++){
		if(arr[j]<small){
			small=arr[j];
			min_pos=j;
		}
	}

	
	arr[min_pos]=arr[i];
	arr[i]=small;

	if((i+1)==n-1){
		return 0;
	}

	else {
		selection_sort(arr,n,i+1);
	}

	
}

int main() {

	int arr[]={4,7,8,9,11,34,78};
	int n=7;

	selection_sort(arr,n,0);

	printf("Sorted array:\n");
	for(int i=0;i<n;i++) {
		printf("%d\t",arr[i]);
	}

	printf("\n");

}