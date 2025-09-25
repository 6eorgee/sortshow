#ifndef SORTS_H
#define SORTS_H

#include "renderer.h"

class SortStrategy
{
public:
    virtual ~SortStrategy() = default;
    virtual void Sort(int* arr, int size) = 0;
    void DrawOnScreen(int* arr, int size);
    void SetRenderer(Renderer* poRenderer_p);

private:
    Renderer* m_poRenderer = nullptr;
};

class InsertionSort : public SortStrategy
{
public:
    void Sort(int* arr, int size) override;
};

class MergeSort : public SortStrategy
{
public:
    void Sort(int* arr, int size) override;

private:
    void Merge(int* arr, int start, int mid, int end);
    void DoMergeSort(int* arr, int start, int end);
};

#endif // SORTS_H