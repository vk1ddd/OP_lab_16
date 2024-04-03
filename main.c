#include <stdio.h>
#include <assert.h>
#include "libs/algorithms/lab_tasks.h"

void swap_max_min_row_element_test1() {
    matrix m = getMemMatrix(3, 3);

    int num = 20;
    for (int row = 0; row < m.nRows; row++) {
        for (int col = 0; col < m.nCols; col++) {
            m.values[row][col] = num;
            num--;
        }
    }

    swap_max_min_row_element(&m);

    assert(m.values[0][0] == 14 && m.values[0][1] == 13 && m.values[0][2] == 12);
    assert(m.values[1][0] == 17 && m.values[1][1] == 16 && m.values[1][2] == 15);
    assert(m.values[2][0] == 20 && m.values[2][1] == 19 && m.values[2][2] == 18);

    freeMemMatrix(&m);
}

void swap_max_min_row_element_test2() {
    matrix m = getMemMatrix(5, 9);

    int num = 100;
    for (int row = 0; row < m.nRows; row++) {
        for (int col = 0; col < m.nCols; col++) {
            if (row == 1 && col == 2) {
                m.values[row][col] = 1;
            } else if (row == 4 && col == 6) {
                m.values[row][col] = 999;
            } else {
                m.values[row][col] = num;
                num--;
            }
        }
    }

    swap_max_min_row_element(&m);

    assert(m.values[1][6] == 999 && m.values[4][2] == 1);

    freeMemMatrix(&m);
}

void swap_max_min_row_element_test() {
    swap_max_min_row_element_test1();
    swap_max_min_row_element_test2();
}

void sortRowsByMinElement_test1() {
    matrix m = getMemMatrix(3, 3);

    int num = 1;
    for (int row = 0; row < m.nRows; row++) {
        for (int col = 0; col < m.nCols; col++) {
            if (row == 0 && col == 0) {
                m.values[row][col] = 7;
            } else if (row == 1 && col == 1) {
                m.values[row][col] = 8;
            } else if (row == 2 && col == 0) {
                m.values[row][col] = 3;
            } else {
                m.values[row][col] = num;
            }
        }
    }

    sortRowsByMinElement(m);

    assert(m.values[0][0] == 3 && m.values[1][0] == 7 && m.values[2][1] == 8);

    freeMemMatrix(&m);
}

void sortRowsByMinElement_test2() {
    matrix m = getMemMatrix(3, 3);

    int num = 1;
    for (int row = 0; row < m.nRows; row++) {
        for (int col = 0; col < m.nCols; col++) {
            if (row == 0 && col == 0) {
                m.values[row][col] = 3;
            } else if (row == 1 && col == 1) {
                m.values[row][col] = 8;
            } else if (row == 2 && col == 0) {
                m.values[row][col] = 5;
            } else {
                m.values[row][col] = num;
            }
        }
    }

    sortRowsByMinElement(m);

    assert(m.values[0][0] == 3 && m.values[1][0] == 5 && m.values[2][1] == 8);

    freeMemMatrix(&m);
}

void sortRowsByMinElement_test() {
    sortRowsByMinElement_test1();
    sortRowsByMinElement_test2();
}

void sortColsByMinElement_test1() {
    matrix m = createMatrixFromArray((int[]) {3, 5, 2, 4, 3, 3,
                                              2, 5, 1, 8, 2, 7,
                                              6, 1, 4, 4, 8, 3}, 3, 6);

    sortColsByMinElement(m);

    assert(m.values[2][0] == 1 && m.values[1][1] == 1 && m.values[1][2] == 2
           && m.values[1][3] == 2 && m.values[0][4] == 3 && m.values[0][5] == 4);

    freeMemMatrix(&m);
}

void sortColsByMinElement_test2() {
    matrix m = createMatrixFromArray((int[]) {2, 0, 4, 1,
                                              3, 2, 4, 2,
                                              2, 2, 4, 2,}, 3, 4);

    sortColsByMinElement(m);

    assert(m.values[0][0] == 0 && m.values[0][1] == 1 && m.values[1][2] == 3 && m.values[1][3] == 4);

    freeMemMatrix(&m);
}

void sortColsByMinElement_test() {
    sortColsByMinElement_test1();
    sortColsByMinElement_test2();
}

void getSquareOfMatrixIfSymmetric_test1() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              2, 5, 6,
                                              3, 6, 9}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {14, 30, 42,
                                                  30, 65, 90,
                                                  42, 90, 126}, 3, 3);

    getSquareOfMatrixIfSymmetric(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void getSquareOfMatrixIfSymmetric_test2() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0,
                                              0, 1, 0,
                                              0, 0, 1}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {1, 0, 0,
                                                  0, 1, 0,
                                                  0, 0, 1}, 3, 3);

    getSquareOfMatrixIfSymmetric(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void getSquareOfMatrixIfSymmetric_test() {
    getSquareOfMatrixIfSymmetric_test1();
    getSquareOfMatrixIfSymmetric_test2();
}

void transposeIfMatrixHasNotEqualSumOfRows_test1(){
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 9}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {1, 4, 7,
                                                     2, 5, 8,
                                                     3, 6, 9}, 3, 3);

    transposeIfMatrixHasNotEqualSumOfRows(m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void transposeIfMatrixHasNotEqualSumOfRows_test2(){
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              1, 2, 3,
                                              1, 2, 3,}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {1, 2, 3,
                                                  1, 2, 3,
                                                  1, 2, 3,}, 3, 3);

    transposeIfMatrixHasNotEqualSumOfRows(m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void transposeIfMatrixHasNotEqualSumOfRows_test(){
    transposeIfMatrixHasNotEqualSumOfRows_test1();
    transposeIfMatrixHasNotEqualSumOfRows_test2();
}

void test() {
    swap_max_min_row_element_test();
    sortRowsByMinElement_test();
    sortColsByMinElement_test();
    getSquareOfMatrixIfSymmetric_test();
    transposeIfMatrixHasNotEqualSumOfRows_test();
}

int main() {
    test();

    return 0;
}
