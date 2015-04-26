#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "bubbleSorter.h"
#include "heapSorter.h"
#include "insertionSorter.h"
#include "quickSorter.h"

class SortersTests : public QObject
{
   Q_OBJECT
public:
   explicit SortersTests(QObject *parent = 0) : QObject(parent) {}

private slots:

    void bubbleSortingTest()
    {
        int array[10] = {7, 2, 0, 3, 7, 10, 5, 56, -10, -4};
        int sortedArray[10] = {-10, -4, 0, 2, 3, 5, 7, 7, 10, 56};
        bubble.sort(array, 10);
        for (int i = 0; i < 10; i++)
            QVERIFY(array[i] == sortedArray[i]);
    }

    void heapSortingTest()
    {
        int array[10] = {7, 2, 0, 3, 7, 10, 5, 56, -10, -4};
        int sortedArray[10] = {-10, -4, 0, 2, 3, 5, 7, 7, 10, 56};
        heap.sort(array, 10);
        for (int i = 0; i < 10; i++)
            QVERIFY(array[i] == sortedArray[i]);
    }

    void insertionSortingTest()
    {
        int array[10] = {7, 2, 0, 3, 7, 10, 5, 56, -10, -4};
        int sortedArray[10] = {-10, -4, 0, 2, 3, 5, 7, 7, 10, 56};
        insertion.sort(array, 10);
        for (int i = 0; i < 10; i++)
            QVERIFY(array[i] == sortedArray[i]);
    }

    void quickSortingTest()
    {
        int array[10] = {7, 2, 0, 3, 7, 10, 5, 56, -10, -4};
        int sortedArray[10] = {-10, -4, 0, 2, 3, 5, 7, 7, 10, 56};
        quick.sort(array, 10);
        for (int i = 0; i < 10; i++)
            QVERIFY(array[i] == sortedArray[i]);
    }

    void bubbleSortedArrayTest()
    {
        int array[10] = {-10, -4, 0, 2, 3, 5, 7, 7, 10, 56};
        int sortedArray[10] = {-10, -4, 0, 2, 3, 5, 7, 7, 10, 56};
        bubble.sort(array, 10);
        for (int i = 0; i < 10; i++)
            QVERIFY(array[i] == sortedArray[i]);
    }

    void heapSortedArrayTest()
    {
        int array[10] = {-10, -4, 0, 2, 3, 5, 7, 7, 10, 56};
        int sortedArray[10] = {-10, -4, 0, 2, 3, 5, 7, 7, 10, 56};
        heap.sort(array, 10);
        for (int i = 0; i < 10; i++)
            QVERIFY(array[i] == sortedArray[i]);
    }

    void insertionSortedArrayTest()
    {
        int array[10] = {-10, -4, 0, 2, 3, 5, 7, 7, 10, 56};
        int sortedArray[10] = {-10, -4, 0, 2, 3, 5, 7, 7, 10, 56};
        insertion.sort(array, 10);
        for (int i = 0; i < 10; i++)
            QVERIFY(array[i] == sortedArray[i]);
    }

    void quickSortedArrayTest()
    {
        int array[10] = {-10, -4, 0, 2, 3, 5, 7, 7, 10, 56};
        int sortedArray[10] = {-10, -4, 0, 2, 3, 5, 7, 7, 10, 56};
        quick.sort(array, 10);
        for (int i = 0; i < 10; i++)
            QVERIFY(array[i] == sortedArray[i]);
    }

private:
   BubbleSorter bubble;
   HeapSorter heap;
   InsertionSorter insertion;
   QuickSorter quick;
};
