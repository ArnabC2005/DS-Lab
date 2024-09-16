#include<stdio.h>
#include<stdlib.h>

void Triplets(int * arr, int n) {
    int a,b,c;


    for(int i=0;i<n;i++) {
        int a=arr[i];

        for(int j=i+1;j<n;j++){
            int b=arr[j];

            int k=j+1;
            while(arr[k]+a+b!=0){
                k++;
            }

            c=arr[k];
            printf("%d %d %d\n",a,b,c);
        }
    }
}

int main() {
int arr[]={0,-1,2,-3,1};
int n=5;

Triplets(arr,5);

}
