#include "sorts.h"
#include "tools.h"

namespace
{
    void Swap(int* a, int* b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

void SortStrategy::SetRenderer(Renderer* poRenderer_p)
{
    m_poRenderer = poRenderer_p;
}

void SortStrategy::DrawOnScreen(int* arr, int size)
{
    if (!m_poRenderer)
    {
        return;
    }
    // Wait(1);
    m_poRenderer->Clear();
    m_poRenderer->DrawArray(arr, size);
    m_poRenderer->Display();
}

void InsertionSort::Sort(int* arr, int size)
{
    for (int i = 1; i < size; ++i)
    {
        int temp = i;
        while (i > 0 && arr[i] < arr[i - 1])
        {
            Swap(&arr[i], &arr[i - 1]);
            --i;
            DrawOnScreen(arr, size);
        }
        i = temp;
    }
}

void MergeSort::Sort(int* arr, int size)
{
    DoMergeSort(arr, 0, size - 1);
}

void MergeSort::Merge(int* arr, int start, int mid, int end)
{
    int sizeL = mid - start + 1;
    int sizeR = end - mid;
    int left[sizeL + 1] = {};
    int right[sizeR + 1] = {};
    for (int i = 0; i < sizeL; ++i)
    {
        left[i] = arr[start + i];
    }
    for (int i = 0; i < sizeR; ++i)
    {
        right[i] = arr[mid + i + 1];
    }
    left[sizeL] = std::numeric_limits<int>::max();
    right[sizeR] = std::numeric_limits<int>::max();
    int i = 0, j = 0;
    for (int k = start; k <= end; ++k)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            ++i;
        }
        else
        {
            arr[k] = right[j];
            ++j;
        }
        DrawOnScreen(arr, end + 1);
    }
}

void MergeSort::DoMergeSort(int* arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end)/2;
        DoMergeSort(arr, start, mid);
        DoMergeSort(arr, mid + 1, end);
        Merge(arr, start, mid, end);
    }
}
