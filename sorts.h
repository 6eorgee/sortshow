#pragma once
#include "renderer.h"

class SortStrategy {
public:
    virtual ~SortStrategy() = default;
    virtual void Sort(int* arr, int size) = 0;
    void DrawOnScreen(int* arr, int size);
    void setRenderer(Renderer* rd) {
        this->r = rd;
    }

private:
    Renderer* r = nullptr;
};

class InsertionSort : public SortStrategy {
public:
    virtual void Sort(int* arr, int size) override;
};

class MergeSort : public SortStrategy {
public:
    virtual void Sort(int* arr, int size) override;
private:
    void merge(int* arr, int start, int mid, int end);
    void merge_sort(int* arr, int start, int end);
};