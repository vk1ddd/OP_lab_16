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

void transposeIfMatrixHasNotEqualSumOfRows_test1() {
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

void transposeIfMatrixHasNotEqualSumOfRows_test2() {
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

void transposeIfMatrixHasNotEqualSumOfRows_test() {
    transposeIfMatrixHasNotEqualSumOfRows_test1();
    transposeIfMatrixHasNotEqualSumOfRows_test2();
}

void isMutuallyInverseMatrices_test1() {
    matrix m1 = createMatrixFromArray((int[]) {3, -5,
                                               1, -2}, 2, 2);

    matrix m2 = createMatrixFromArray((int[]) {2, -5,
                                               1, -3}, 2, 2);

    assert(isMutuallyInverseMatrices(m1, m2) == 1);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void isMutuallyInverseMatrices_test2() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               0, 1, 4,
                                               5, 6, 0}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {-24, 18, 5,
                                               20, -15, -4,
                                               -5, 4, 1}, 3, 3);

    assert(isMutuallyInverseMatrices(m1, m2) == 1);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void isMutuallyInverseMatrices_test() {
    isMutuallyInverseMatrices_test1();
    isMutuallyInverseMatrices_test2();
}

void findSumOfMaxesOfPseudoDiagonal_test1() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 5, 4,
                                              1, 3, 6, 3,
                                              3, 2, 1, 2}, 3, 4);

    long long check = findSumOfMaxesOfPseudoDiagonal(m);

    assert(check == 20);

    freeMemMatrix(&m);
}

void findSumOfMaxesOfPseudoDiagonal_test2() {
    matrix m = createMatrixFromArray((int[]) {3, 5, 2, 4, 3, 3,
                                              2, 5, 1, 8, 2, 7,
                                              6, 1, 4, 4, 8, 3}, 3, 6);

    long long check = findSumOfMaxesOfPseudoDiagonal(m);

    assert(check == 35);

    freeMemMatrix(&m);
}

void findSumOfMaxesOfPseudoDiagonal_test() {
    findSumOfMaxesOfPseudoDiagonal_test1();
    findSumOfMaxesOfPseudoDiagonal_test2();
}

void getMinInArea_test1() {
    matrix m = createMatrixFromArray((int[]) {3, 5, 2, 4, 6, 1,
                                              32, 45, 15, 8, 10, 7,
                                              36, 124, 44, 424, 48, 23}, 3, 6);

    long long check = getMinInArea(m);

    assert(check == 1);

    freeMemMatrix(&m);
}

void getMinInArea_test2() {
    matrix m = createMatrixFromArray((int[]) {10, 7, 5, 6,
                                              3, 11, 8, 9,
                                              4, 1, 12, 2}, 3, 4);

    long long check = getMinInArea(m);

    assert(check == 5);

    freeMemMatrix(&m);
}

void getMinInArea_test3() {
    matrix m = createMatrixFromArray((int[]) {6, 8, 9, 2,
                                              7, 12, 3, 4,
                                              10, 11, 5, 1}, 3, 4);

    long long check = getMinInArea(m);

    assert(check == 6);

    freeMemMatrix(&m);
}

void getMinInArea_test() {
    getMinInArea_test1();
    getMinInArea_test2();
    getMinInArea_test3();
}

void sortByDistances_test1() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              -1, 0, 1}, 3, 3);

    sortByDistances(m);

    assert(m.values[0][0] == -1 && m.values[1][0] == 1 && m.values[2][0] == 4);

    freeMemMatrix(&m);
}

void sortByDistances_test2() {
    matrix m = createMatrixFromArray((int[]) {2, 1, -3, 4,
                                              0, 3, 1, -2,
                                              -1, 2, 2, 0}, 3, 4);

    sortByDistances(m);

    assert(m.values[0][0] == -1 && m.values[1][0] == 0 && m.values[2][0] == 2);

    freeMemMatrix(&m);
}

void sortByDistances_test() {
    sortByDistances_test1();
    sortByDistances_test2();
}

void countEqClassesByRowsSum_test1() {
    matrix m = createMatrixFromArray((int[]) {7, 1,
                                              2, 7,
                                              5, 4,
                                              4, 3,
                                              1, 6,
                                              8, 0}, 6, 2);

    int check = countEqClassesByRowsSum(m);

    assert(check == 3);

    freeMemMatrix(&m);
}

void countEqClassesByRowsSum_test2() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              1, 3, 2,
                                              2, 1, 3,
                                              2, 3, 1}, 4, 3);


    int result = countEqClassesByRowsSum(m);

    assert(result == 1);

    freeMemMatrix(&m);
}

void countEqClassesByRowsSum_test() {
    countEqClassesByRowsSum_test1();
    countEqClassesByRowsSum_test2();
}

void getNSpecialElement_test1() {
    matrix m = createMatrixFromArray((int[]) {3, 5, 5, 4,
                                              2, 3, 6, 7,
                                              12, 2, 1, 2}, 3, 4);


    int result = getNSpecialElement(m);

    assert(result == 2);

    freeMemMatrix(&m);
}

void getNSpecialElement_test2() {
    matrix m = createMatrixFromArray((int[]) {3, 5, 5, 4,
                                              2, 3, 6, 2,
                                              3, 2, 1, 2}, 3, 4);

    int result = getNSpecialElement(m);

    assert(result == 0);

    freeMemMatrix(&m);
}

void getNSpecialElement_test() {
    getNSpecialElement_test1();
    getNSpecialElement_test2();
}

void swapPenultimateRow_test1() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 1}, 3, 3);

    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               1, 4, 7,
                                               7, 8, 1}, 3, 3);

    swapPenultimateRow(m);

    assert(areTwoMatricesEqual(&m1, &m));

    freeMemMatrix(&m);
}

void swapPenultimateRow_test2() {
    matrix m = createMatrixFromArray((int[]) {1, 2,
                                              3, 4}, 2, 2);

    matrix check = createMatrixFromArray((int[]) {1, 3,
                                                  3, 4}, 2, 2);

    swapPenultimateRow(m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void swapPenultimateRow_test() {
    swapPenultimateRow_test1();
    swapPenultimateRow_test2();
}

void countZeroRows_test1() {
    matrix m = createMatrixFromArray((int[]) {0, 0,
                                              0, 0,
                                              4, 7}, 3, 2);

    int check = countZeroRows(m);

    assert(check == 2);

    freeMemMatrix(&m);
}

void countZeroRows_test2() {
    matrix m = createMatrixFromArray((int[]) {0, 0,
                                              0, 1,
                                              0, 0}, 3, 2);

    int check = countZeroRows(m);

    assert(check == 2);

    freeMemMatrix(&m);
}

void countZeroRows_test() {
    countZeroRows_test1();
    countZeroRows_test2();
}

void getNSpecialElement2_test1() {
    matrix m = createMatrixFromArray((int[]) {2, 3, 5, 5, 4,
                                              6, 2, 3, 8, 12,
                                              12, 12, 2, 1, 2}, 3, 5);

    int check = getNSpecialElement2(m);

    assert(check == 4);

    freeMemMatrix(&m);
}

void getNSpecialElement2_test2() {
    matrix m = createMatrixFromArray((int[]) {6, 3, 5, 5, 4,
                                              6, 2, 3, 8, 4,
                                              12, 12, 2, 1, 2}, 3, 5);

    int check = getNSpecialElement2(m);

    assert(check == 0);

    freeMemMatrix(&m);
}

void getNSpecialElement2_test() {
    getNSpecialElement2_test1();
    getNSpecialElement2_test2();
}

void getVectorIndexWithMaxAngle_test1() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 3, 3,
                                              1, 3, 5}, 3, 3);

    int b[3] = {3, 1, 2};

    int result = getVectorIndexWithMaxAngle(m, b);

    assert(result == 2);

    freeMemMatrix(&m);
}

void getVectorIndexWithMaxAngle_test2() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              1, 2, 3,
                                              1, 2, 3}, 3, 3);

    int b[3] = {3, 1, 2};

    int result = getVectorIndexWithMaxAngle(m, b);

    assert(result == 0);

    freeMemMatrix(&m);
}

void getVectorIndexWithMaxAngle_test() {
    getVectorIndexWithMaxAngle_test1();
    getVectorIndexWithMaxAngle_test2();
}

void getSpecialScalarProduct_test1() {
    matrix m = createMatrixFromArray((int[]) {4, 2, 3,
                                              3, 1, 2,
                                              2, 2, 3}, 3, 3);

    long long int result = getSpecialScalarProduct(m);

    assert(result == 16);

    freeMemMatrix(&m);
}


void getSpecialScalarProduct_test2() {
    matrix m = createMatrixFromArray((int[]) {4, 1, 3,
                                              3, 2, 2,
                                              2, 2, 3}, 3, 3);

    long long int result = getSpecialScalarProduct(m);

    assert(result == 12);

    freeMemMatrix(&m);
}


void getSpecialScalarProduct_test() {
    getSpecialScalarProduct_test1();
    getSpecialScalarProduct_test2();
}

void test() {
    swap_max_min_row_element_test();
    sortRowsByMinElement_test();
    sortColsByMinElement_test();
    getSquareOfMatrixIfSymmetric_test();
    transposeIfMatrixHasNotEqualSumOfRows_test();
    isMutuallyInverseMatrices_test();
    findSumOfMaxesOfPseudoDiagonal_test();
    getMinInArea_test();
    sortByDistances_test();
    countEqClassesByRowsSum_test();
    getNSpecialElement_test();
    swapPenultimateRow_test();
    countZeroRows_test();
    getNSpecialElement2_test();
    getVectorIndexWithMaxAngle_test();
    getSpecialScalarProduct_test();
}

int main() {
    test();

    return 0;
}
