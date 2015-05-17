#pragma once

#include <QObject>
#include <QtTest>
#include "filePrinter.h"

class FilePrinterTests : public QObject
{
   Q_OBJECT
public:
   explicit FilePrinterTests(QObject *parent = 0) : QObject(parent) {}

private slots:

    void smallArrayPrinting()
    {
        int size = 1;
        int **stdArray = new int *[size];
        for (int i = 0; i < size; i++)
            stdArray[i] = new int[size];

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                stdArray[i][j] = j;

        SquareArray *array = new SquareArray(stdArray, size);

        for (int i = 0; i < size; i++)
            delete[] stdArray[i];
        delete[] stdArray;

        FilePrinter printer;
        printer.openFile("test.txt");
        printer.print(array);
        printer.closeFile();

        delete array;


        int rightArray[size * size] = {0};

        int resultArray[size * size];
        std::ifstream file;
        file.open("test.txt");
        for (int i = 0; i < size * size; i++)
            file >> resultArray[i];
        file.close();

        for (int i = 0; i < size * size; i++)
            QVERIFY(rightArray[i] == resultArray[i]);
    }

    void arrayPrinting()
    {
        int size = 3;
        int **stdArray = new int *[size];
        for (int i = 0; i < size; i++)
            stdArray[i] = new int[size];

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                stdArray[i][j] = j;

        SquareArray *array = new SquareArray(stdArray, size);

        for (int i = 0; i < size; i++)
            delete[] stdArray[i];
        delete[] stdArray;

        FilePrinter printer;
        printer.openFile("test.txt");
        printer.print(array);
        printer.closeFile();

        delete array;


        int rightArray[size * size] = {1, 2, 2, 1, 0, 0, 0, 1, 2};

        int resultArray[size * size];
        std::ifstream file;
        file.open("test.txt");
        for (int i = 0; i < size * size; i++)
            file >> resultArray[i];
        file.close();

        for (int i = 0; i < size * size; i++)
            QVERIFY(rightArray[i] == resultArray[i]);
    }

};
