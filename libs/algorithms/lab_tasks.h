//
// Created by ivanu on 29.03.2024.
//

#ifndef LAB_16_LAB_TASKS_H
#define LAB_16_LAB_TASKS_H

#include "../data_structures/matrix/matrix.h"

//task 1
// меняет местами строки с максимальным и минимальным элементом
void swap_max_min_row_element(matrix *m);

//task 2
//возвращает максимальный элемент массива
int getMax(int *a, int n);

//упорядочивает строки матрицы по неубыванию наибольших элементов строк
void sortRowsByMinElement(matrix m);

//task 3
//выводит минимальный элемент матрицы
int getMin(int *a, int n);

//упорядочивает столбцы матрицы по неубыванию минимальных элементов столбцов
void sortColsByMinElement(matrix m);

//task 4
//умножает матрицы друг на друга
matrix mulMatrices(matrix m1, matrix m2);

//если матрица симметрична, то заменяет ее квадратом этой матрицы
void getSquareOfMatrixIfSymmetric(matrix *m);

//task 5
//возвращает истину если в массиве нет одинаковых элементов
bool isUnique(long long *a, int n);

//возвращает сумму элементов
long long getSum(int *a, int n);

// транспонирует матрицу если суммы строк различны
void transposeIfMatrixHasNotEqualSumOfRows(matrix m);

//task 6
//возвращает истинна если матрицы явл. взаимно обратными
bool isMutuallyInverseMatrices(matrix m1, matrix m2);

//task 7
//из a и b выбирает максимальный и возвращает его
int max(int a, int b);

//находит сумму максимальных элементов псевдодиагонали
long long findSumOfMaxesOfPseudoDiagonal(matrix m);

//task 8
//находит минимальный элемент матрицы в выделенной области
int getMinInArea(matrix m);

//task 9
//возвращает расстояние до начала координат
float getDistance(int *a, int n);

//сортирует строки матрицы m по не убыванию, основываясь на критерии criteria
void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int));

// сортирует строки матрицы m, относительно их удалённости от начала координат
void sortByDistances(matrix m);

//task 10
int cmp_long_long(const void *pa, const void *pb);

//возвращает количество уникальных элементов массива a размера n
int countNUnique(long long *a, int n);

//возвращает количество уникальных сумм строк матрицы m
int countEqClassesByRowsSum(matrix m);

//task 11
//возвращает кол-во элементов столбцов, которые больше суммы остальных элементов
int getNSpecialElement(matrix m);

//task 12
//возвращает позицию первого столбца с минимальным элементом
position getLeftMin(matrix m);

//заменяет предпоследную строчку матрицы на первый столбец с минимальным элементом
void swapPenultimateRow(matrix m);

//task 13
//возвращает true, если массив a размера n отсортирован по не убыванию
bool isNonDescendingSorted(int *a, int n);

// возвращает true, если все строки матрицы m отсортированы по не убыванию
bool hasAllNonDescendingRows(matrix m);

//возвращает количество матриц, из массива матриц ms размера n_matrix, строки в которых упорядочены по не убыванию
int countNonDescendingRowsMatrices(matrix *ms, int nMatrix);

//task 14
//возвращает кол-во эл. value в массива a размером n
int  countValues(const  int  *a,  int  n,  int  value);

//считает нулевые строки
int  countZeroRows(matrix  m);

//выводит матрицы с максимальным кол-ом нулевых строк
void  printMatrixWithMaxZeroRows(matrix  *ms,  int  nMatrix);

//task 15
//возвращает максимальный по модулю элемент матрицы
int get_max_abs_value(matrix m);

//выводит матрицу у которой максимальный эл. по модулю меньше чем у остальных
void print_matrix_min_standart(int *ms, int nMatrix);

//task 16
//возвращает меньший из двух элементов
int min2(int a, int b);

//выводит кол-во особых эл. (если слева от числа все числа меньше или справа от числа все числа больше)
int getNSpecialElement2(matrix m);

#endif //LAB_16_LAB_TASKS_H
