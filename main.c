#include <stdio.h>
#include <assert.h>
#include "libs/algorithms/lab_tasks.h"

void swap_max_min_row_element_test1(){
    matrix m = getMemMatrix(3, 3);

    int num = 20;
    for (int row = 0; row < m.nRows; row++){
        for (int col = 0; col < m.nCols; col++){
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

void swap_max_min_row_element_test2(){
    matrix m = getMemMatrix(5, 9);

    int num = 100;
    for (int row = 0; row < m.nRows; row++){
        for (int col = 0; col < m.nCols; col++) {
            if(row == 1 && col == 2){
                m.values[row][col] = 1;
            }else if (row == 4 && col == 6){
                m.values[row][col] = 999;
            }else{
                m.values[row][col] = num;
                num--;
            }
        }
    }

    swap_max_min_row_element(&m);

    assert(m.values[1][6] == 999 && m.values[4][2] == 1);

    freeMemMatrix(&m);
}

void swap_max_min_row_element_test(){
    swap_max_min_row_element_test1();
    swap_max_min_row_element_test2();
}

void test(){
    swap_max_min_row_element_test();
}

int main() {
    test();

    return 0;
}
