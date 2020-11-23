#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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
    for (int i = 0; i < sizeArr; i++) {
        printf("Enter %d element:\n", i);
        scanf("%d", &intArr[i]);
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
    int increment[20], inc, numInc, comp, j;

    numInc = getNumIncArrAndInitIncArr(increment, sizeArr);

    printArr(intArr, sizeArr);
    while (numInc > 0) {
        inc = increment[numInc - 1];

        for (int i = inc; i < sizeArr; i++) {
            int comp = intArr[i];

            for (j = i - inc; (j >= 0) &&( intArr[i] < intArr[j]); j -= inc) {
                intArr[j + inc] = intArr[j];
            }

            intArr[j + inc] = comp;
        }

        numInc--;
    }

    insertSort(intArr, sizeArr);

    printArr(intArr, sizeArr);
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
    int sizeArr = getArraySize();
    int intArr[sizeArr];

    initArr(&intArr, sizeArr);

    sort(&intArr, sizeArr);

    getch();
}
