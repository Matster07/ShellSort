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

void sort(int intArr[], int sizeArr) {
    int period;
    int dop;

    if (sizeArr % 2 == 0) {
        period = sizeArr/2;
        printf("\n%d\n", period);

        printArr(intArr, sizeArr);

//        for (int i = 0; i < period; i++) {
//            dop = intArr[i + period];
//
//            if (intArr[i] > intArr[i + period]) {
//                intArr[i + period] = intArr[i];
//                intArr[i] = dop;
//            }
//        }

        printArr(intArr, sizeArr);

    } else {
        printf("Size must be even!");
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
