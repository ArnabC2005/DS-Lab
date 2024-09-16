#include<stdio.h>
#include<stdlib.h>

int sparsityCheck(int n; int arr[][3]){
int zero_count=0;
int nz_count=0;

for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
        if(arr[i][j]==0) {
            zero_count++;
        }

        else nz_count++;
    }
}

if(zero_count>=nz_count) {
    return 1;
}

else return 0;

}

int main() {

int arr[3][3];

int n=3;

printf("Enter elements:\n");

for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
        scanf("%d",&arr[i][j]);
    }
}

if(sparsityCheck(n,arr)) {
    printf("Matrix is sparse\n");
}

else printf("Matrix is NOT sparse\n");


}
