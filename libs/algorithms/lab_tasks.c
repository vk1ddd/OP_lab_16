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
    for (int i = 0; i < m.nRows - 1; i++) {
        for (int j = 1; j < m.nRows; j++) {
            if (res_criteria[i] > res_criteria[j]) {
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

//task 10
int cmp_long_long(const void *pa, const void *pb) {
    return (int) (*(long long int *) pa - *(long long int *) pb);
}

int countNUnique(long long *a, int n) {
    int amount = 1;

    for (int i = 0; i < n - 1; i++) {
        if (a[i] != a[i + 1])
            amount++;
    }

    return amount;
}

int countEqClassesByRowsSum(matrix m) {
    long long int values[m.nRows];

    for (int i = 0; i < m.nRows; i++)
        values[i] = getSum(m.values[i], m.nCols);

    qsort(values, m.nRows, sizeof(long long int), cmp_long_long);

    int result = countNUnique(values, m.nRows);

    return result;
}

//task 11
int getNSpecialElement(matrix m) {
    int array[m.nRows];
    int max_num;
    int sum;
    int amount = 0;
    for (int col = 0; col < m.nCols; col++) {
        for (int row = 0; row < m.nRows; row++) {
            array[row] = m.values[row][col];
        }
        max_num = getMax(array, m.nRows);
        sum = (int) getSum(array, m.nRows);
        sum -= max_num;
        if (max_num > sum)
            amount++;
    }

    return amount;
}

//task 12
position getLeftMin(matrix m) {
    position min_left_pos;
    int min_num = m.values[0][0];
    min_left_pos.rowIndex = 0;
    min_left_pos.colIndex = 0;
    for (int row = 0; row < m.nRows; row++) {
        for (int col = 0; col < m.nCols; col++) {
            if (min_num > m.values[row][col]) {
                min_num = m.values[row][col];
                min_left_pos.rowIndex = row;
                min_left_pos.colIndex = col;
            }
        }
    }

    return min_left_pos;
}

void swapPenultimateRow(matrix m) {
    position min_pos = getLeftMin(m);
    int array[m.nRows];
    for (int row = 0; row < m.nRows; row++) {
        array[row] = m.values[row][min_pos.colIndex];
    }
    for (int col = 0; col < m.nCols; col++) {
        m.values[m.nRows - 2][col] = array[col];
    }
}

//task 13
bool isNonDescendingSorted(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < a[i + 1])
            return false;
    }

    return true;
}

bool hasAllNonDescendingRows(matrix m) {
    for (int row = 0; row < m.nRows; row++) {
        if (isNonDescendingSorted(m.values[row], m.nCols))
            return false;
    }

    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int amount = 0;

    for (int matrix = 0; matrix < nMatrix; matrix++) {
        if (hasAllNonDescendingRows(ms[matrix]))
            amount++;
    }

    return amount;
}

//task 14
int countValues(const int *a, int n, int value) {
    int amount = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == value)
            amount++;
    }

    return amount;
}

int countZeroRows(matrix m) {
    int zero_count;
    int amount = 0;

    for (int row = 0; row < m.nRows; row++) {
        zero_count = countValues(m.values[row], m.nCols, 0);
        if (zero_count == m.nCols)
            amount++;
    }

    return amount;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int amount_zero[nMatrix];
    int max_zero_rows = 0;
    int amount_zero_rows;

    for (int i = 0; i < nMatrix; i++) {
        amount_zero_rows = countZeroRows(ms[i]);
        amount_zero[i] = amount_zero_rows;

        if (amount_zero_rows > max_zero_rows)
            max_zero_rows = amount_zero_rows;
    }

    for (int i = 0; i < nMatrix; i++)
        if (amount_zero[i] == max_zero_rows)
            outputMatrix(*(ms + i));
}

//tasl 15
int get_max_abs_value(matrix m){
    int max_num = abs(m.values[0][0]);

    for (int row = 0; row < m.nRows; row++){
        for (int col = 0; col < m.nCols; col++){
            if(abs(m.values[row][col]) > max_num)
                max_num = abs(m.values[row][col]);
        }
    }

    return max_num;
}

void print_matrix_min_standard(matrix *ms, int nMatrix){
    int array[nMatrix];
    int min_standard = get_max_abs_value(ms[0]);

    for (int matrix = 0; matrix < nMatrix; matrix++){
        array[matrix] = get_max_abs_value(ms[matrix]);
        if (array[matrix] < min_standard)
            min_standard = array[matrix];
    }

    for (int matrix = 0; matrix < nMatrix; matrix++) {
        if (array[matrix] == min_standard)
            outputMatrix(ms[matrix]);
    }
}
