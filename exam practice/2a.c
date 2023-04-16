#include <stdio.h>
#define INT_MAX 2147483647
#define INT_MIX -2147483648

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int x = 0;
    int len = 0;
    scanf("%d", &x);
    int tmp = x;

    while(tmp > 0) {
        len++;
        tmp /= 10;
    }

    int *arr = malloc(len * sizeof(int));

    for(int i = len - 1; i >= 0; i--) {
        arr[i] = x % 10;
        x /= 10;
    }

    int hold = INT_MAX;

    for(int i = len - 1; i > 0; i--) {
        if(arr[i - 1] < arr[i]) {
            hold = i;
            break;
        }
    }

    if(hold == INT_MAX) {
        printf("Largest Number\n");
        return 0;
    }
    
    int min = hold;

    for(int i = min + 1; i < len; i++) {
        if(arr[i] > arr[i - 1] && arr[i] > arr[min]) {
            min = i;
        }
    }

    swap(&arr[min - 1], &arr[hold]);

    // sorting algorithm use merge or quick sort to achieve O(log n)

}