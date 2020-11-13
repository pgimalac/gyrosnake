#include "clocks.h"
#include "irq.h"
#include "matrix.h"

void display_img() {
    while (1) {
        for (int i = 0; i < 8; i++) {
            mat_set_row(i, matrix[i]);
            sleep(10000);
        }
    }
}

int main() {
    irq_init();

    clocks_init();

    matrix_init();

    display_img();

    return 0;
}
