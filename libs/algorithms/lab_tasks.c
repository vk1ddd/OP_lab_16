//
// Created by ivanu on 29.03.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include "../data_structures/matrix/matrix.h"

// task 1
void swap_max_min_row_element(matrix *m) {
    int max_num = m->values[0][0];
    int min_num = m->values[0][0];
    int index_max = 0;
    int index_min = 0;

    for (int row = 0; row < m->nRows; row++) {
        for (int col = 0; col < m->nCols; col++) {
            if (max_num < m->values[row][col]) {
                max_num = m->values[row][col];
                index_max = row;
            } else if (min_num > m->values[row][col]) {
                min_num = m->values[row][col];
                index_min = row;
            }
        }
    }

    if (index_min != index_max) {
        swapRows(*m, index_max, index_min);
    }
}

//task 2
int getMax(int *a, int n) {
    int max_num = a[0];

    for (int i = 0; i < n; i++) {
        if (a[i] > max_num)
            max_num = a[i];
    }

    return max_num;
}

void sortRowsByMinElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

//task 3
int getMin(int *a, int n) {
    int min_num = a[0];

    for (int i = 0; i < n; i++) {
        if (a[i] < min_num)
            min_num = a[i];
    }

    return min_num;
}

void sortColsByMinElement(matrix m) {
    selectionSortColsMatrixByColCriteria(m, getMin);
}

//task 4
matrix mulMatrices(matrix m1, matrix m2) {
    assert(m1.nCols == m2.nRows);

    matrix result = getMemMatrix(m2.nRows, m1.nCols);
    for (int row = 0; row < m1.nRows; row++)
        for (int col = 0; col < m2.nCols; col++) {
            result.values[row][col] = 0;
            for (int k = 0; k < m1.nCols; k++)
                result.values[row][col] += m1.values[row][k] * m2.values[k][col];
        }

    return result;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    assert(isSymmetricMatrix(m));

    matrix result = mulMatrices(*m, *m);

    freeMemMatrix(m);

    m->values = result.values;
    m->nRows = result.nRows;
    m->nCols = result.nCols;
}

//task 5
bool isUnique(long long *a, int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] == a[j])
                return false;

    return true;
}

long long getSum(int *a, int n) {
    long long int result = 0;

    for (int i = 0; i < n; i++)
        result += a[i];

    return result;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long int sum[m.nRows];

    for (int i = 0; i < m.nRows; i++)
        sum[i] = getSum(m.values[i], m.nCols);

    if (isUnique(sum, m.nRows))
        transposeSquareMatrix(&m);
}


//task 6
bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix multi = mulMatrices(m1, m2);

    bool result = isEMatrix(&multi);

    freeMemMatrix(&multi);

    return result;
}

// task 7
int max(int a, int b) {
    if (a > b)
        return a;

    return b;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int max_elements[m.nCols + m.nRows - 1];

    for (int i = 0; i < (m.nCols + m.nRows - 1); i++)
        max_elements[i] = 0;

    for (int row = 0; row < m.nRows; row++) {
        for (int col = 0; col < m.nCols; col++) {
            if (row != col)
                max_elements[row - col + m.nCols - 1] = max(max_elements[row - col + m.nCols - 1],
                                                            m.values[row][col]);
        }
    }

    long long result = 0;
    for (int i = 0; i < (m.nCols + m.nRows - 1); i++) {
        result += max_elements[i];
    }

    return result;
}

// task 8
int getMinInArea(matrix m) {
    position max = getMaxValuePos(m);
    int min = m.values[max.rowIndex][max.rowIndex];
    int range = 0;

    while (max.rowIndex >= 0) {
        for (int col = ((max.colIndex - range) < 0 ? 0 : max.colIndex - range);
             col < ((max.colIndex + range + 1) > m.nCols ? m.nCols : max.colIndex + range + 1); col++) {
            if (min > m.values[max.rowIndex][col])
                min = m.values[max.rowIndex][col];
        }
        max.rowIndex--;
        range++;
    }

    return min;
}

//task 9
float getDistance(int *a, int n) {
    long long int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i] * a[i];

    return sqrt(sum);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    float res_criteria[m.nRows];

    for (size_t i = 0; i < m.nRows; i++)
        res_criteria[i] = criteria(m.values[i], m.nCols);

    float temp;
    for (int i = 0; i < m.nRows - 1; i++){
        for (int j = 1; j < m.nRows; j++){
            if(res_criteria[i] > res_criteria[j]){
                swapRows(m, i, j);
                temp = res_criteria[i];
                res_criteria[i] = res_criteria[j];
                res_criteria[j] = temp;
            }
        }
    }
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}
