#include <stdio.h>

void TowerOfHanoi(int n, char source, char destination, char auxiliary, int *moveCount) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        (*moveCount)++;
        return;
    }
    
    TowerOfHanoi(n - 1, source, auxiliary, destination, moveCount);
    
    printf("Move disk %d from %c to %c\n", n, source, destination);
    (*moveCount)++;
    
    TowerOfHanoi(n - 1, auxiliary, destination, source, moveCount);
}

int main() {
    int n; 
    int moveCount = 0;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of disks must be a positive integer.\n");
        return 1;
    }

    TowerOfHanoi(n, 'A', 'C', 'B', &moveCount);

    printf("Total number of moves: %d\n", moveCount);

    return 0;
}
