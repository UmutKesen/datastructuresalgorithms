#include <stdio.h>

// 1. Sıralama Algoritmaları

// Bubble Sort Algoritması
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Quick Sort Algoritması
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        int pi = i + 1;
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// 2. Arama Algoritmaları

// Binary Search Algoritması
int binary_search(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Linear Search Algoritması
int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

// 3. Veri Yapıları

// Stack (Yığın) Yapısı
#define MAX 100

typedef struct {
    int items[MAX];
    int top;
} Stack;

void push(Stack *s, int value) {
    if (s->top < MAX - 1) {
        s->items[++s->top] = value;
    }
}

int pop(Stack *s) {
    if (s->top >= 0) {
        return s->items[s->top--];
    }
    return -1;
}

// Queue (Kuyruk) Yapısı
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

void enqueue(Queue *q, int value) {
    if (q->rear < MAX - 1) {
        q->items[++q->rear] = value;
    }
}

int dequeue(Queue *q) {
    if (q->front <= q->rear) {
        return q->items[q->front++];
    }
    return -1;
}

// Test Kısmı
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    bubble_sort(arr, n);
    printf("Bubble Sort Sonucu: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    quick_sort(arr, 0, n - 1);
    printf("Quick Sort Sonucu: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("Binary Search (25): %d\n", binary_search(arr, n, 25));
    printf("Linear Search (12): %d\n", linear_search(arr, n, 12));
    
    return 0;
}
