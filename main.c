#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int getArraySize() {
    while (1) {
        int sizeArr;

        printf("Enter size of array:\n");
        scanf("%d", &sizeArr);

        if (sizeArr > 0) {
            return sizeArr;
        } else {
            printf("Size must be greater than zero\nTry again!");
            for (int i = 0; i < 29; i++) {
                printf("\n");
            }
        }
    }
}

void initArr(int intArr[], int sizeArr) {
    srand(time(NULL));

    for (int i = 0; i < sizeArr; i++) {
          intArr[i]=rand();
//        printf("Enter %d element:\n", i); // ���������������� ����� ��������� ������ �������
//        scanf("%d", &intArr[i]);
    }
}

int getNumIncArrAndInitIncArr(int increment[], int sizeArr) {
    int p1, p2, p3, i;

    p1 = p2 = p3 = 1;

    if (sizeArr > 0) {
        for (int i = 0; i < sizeArr; i++) {
            if (i % 2) {
                increment[i] = 8*p1 - 6*p2 + 1;
            } else {
                increment[i] = 9*p1 - 9*p3 + 1;
                p2 *= 2;
                p3 *= 2;
            }

            p1 *= 2;

            if (3*increment[i] > sizeArr) {
                increment[i] = 0;
                return i;
            }
        }
    } else {
        return 0;
    }
}

void sort(int intArr[], int sizeArr) {
    int increment[100]; // ������ � ������������
    int inc; // ��������������� ����� ��� �������� ����������
    int numInc; // ���������� �������� ���������� ������ ������� ����������
    int comp; // ��������������� ����� ��� �������� �������
    unsigned long startUnixTime; // ����� ����� ����������� �������
    unsigned long finishUnixTime; // ����� ����� ���������� �������
    unsigned long dif; // ����� ����������

    numInc = getNumIncArrAndInitIncArr(increment, sizeArr); // ������� ���������� �������� ���������� ������ ������� ����������

//    printArr(intArr, sizeArr); // ����������������, ����� ���������� ����������� ������
    startUnixTime = (unsigned long) time(NULL);
    while (numInc > 0) {
        inc = increment[numInc--]; // �������� �������� �������� ����������
        int j = 0, i = 0;

        while (j = i + inc < sizeArr) { // ����������� ��������� �� ������ ���������, ���������� ����� �������� ����� ����������, ���� ��� ���������� �� ������ ����� 1
            if (intArr[i] > intArr[j]) {
                comp = intArr[i];
                intArr[i] = intArr[j];
                intArr[j] = comp;
            }

            i++;
        }
    }

    insertSort(intArr, sizeArr); // ������������� ���������� ���������
    finishUnixTime = (unsigned long) time(NULL);
    dif = finishUnixTime - startUnixTime;

    printArr(intArr, sizeArr);

    printf("\nIt took - %lu\n", startUnixTime);
    printf("\nIt took - %lu\n", finishUnixTime);
    printf("\nIt took - %lu\n", dif);
}

void insertSort(int intArr[], int sizeArr)
{
    int newElement, index;

    for (int i = 1; i < sizeArr; i++)
    {
        newElement = intArr[i];
        index = i - 1;

        while(index >= 0 && intArr[index] > newElement)
        {
            intArr[index+1] = intArr[index];
            index = index - 1;
        }

        intArr[index+1] = newElement;
    }
}

void printArr(int array[], int sizeArr) {
    for (int i = 0; i < sizeArr; i++) {
        printf("%d Element - %d\n", i, array[i]);
    }

    printf("\n");
}

void main()
{
    int sizeArr = getArraySize(); // ������ ������ �������
    int intArr[sizeArr]; // �������  ������ �������� �����

    initArr(&intArr, sizeArr); // ��������� ���������� ������

    sort(&intArr, sizeArr); // ����������

    getch();
}
