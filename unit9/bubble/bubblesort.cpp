#include <stdio.h>
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n-i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    int myArray[10086];
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&myArray[i]);
    bubbleSort(myArray, n);
    for (int i = 1; i <=n; i++) {
        printf("%d ", myArray[i]);
    }
    return 0;
}