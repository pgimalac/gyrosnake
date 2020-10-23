#include "clocks.h"
#include "led.h"
#include "matrix.h"
#include "uart.h"
#include "utils.h"

void test_pixels() {
    rgb_color colors[8];

    for (int i = 0; i < 8; i++) {
        colors[i].r = 1 << i;
        colors[i].g = 0;
        colors[i].b = 0;
    }

    for (int j = 0; j < 8; j++) {
        deactivate_rows();
        mat_set_row(j, colors);
        sleep(100000000);
    }

    for (int i = 0; i < 8; i++) {
        colors[i].r = 0;
        colors[i].g = 1 << i;
        colors[i].b = 0;
    }

    for (int j = 0; j < 8; j++) {
        deactivate_rows();
        mat_set_row(j, colors);
        sleep(100000000);
    }

    for (int i = 0; i < 8; i++) {
        colors[i].r = 0;
        colors[i].g = 0;
        colors[i].b = 1 << i;
    }

    for (int j = 0; j < 8; j++) {
        deactivate_rows();
        mat_set_row(j, colors);
        sleep(100000000);
    }
}

int main() {
    clocks_init();
    matrix_init();

    while (1) {
        test_pixels();
    }

    return 0;
}
