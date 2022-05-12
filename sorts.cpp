#include "sorts.h"
#include "tools.h"

void SortStrategy::DrawOnScreen(int* arr, int size) {
    wait(1);
    r->Clear();
    r->DrawArray(arr, size);
    r->Display();
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void InsertionSort::Sort(int* arr, int size) {
    for (int i = 1; i < size; ++i) {
        int temp = i;
        while (i > 0 && arr[i] < arr[i - 1]) {
            swap(&arr[i], &arr[i - 1]);
            --i;
            DrawOnScreen(arr, size);
        }
        i = temp;
    }
}

void MergeSort::Sort(int* arr, int size) {
    merge_sort(arr, 0, size - 1);
}

void MergeSort::merge(int* arr, int start, int mid, int end) {
    int sizeL = mid - start + 1;
    int sizeR = end - mid;
    int Left[sizeL + 1] = {};
    int Right[sizeR + 1] = {};
    for (int i = 0; i < sizeL; ++i)
        Left[i] = arr[start + i];
    for (int i = 0; i < sizeR; ++i)
        Right[i] = arr[mid + i + 1];
    Left[sizeL] = std::numeric_limits<int>::max();
    Right[sizeR] = std::numeric_limits<int>::max();
    int i = 0, j = 0;
    for (int k = start; k <= end; ++k) {
        if (Left[i] <= Right[j]) {
            arr[k] = Left[i];
            ++i;
        } else {
            arr[k] = Right[j];
            ++j;
        }
        DrawOnScreen(arr, end + 1);
    }
}

void MergeSort::merge_sort(int* arr, int start, int end) {
    if (start < end) {
        int mid = (start + end)/2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}