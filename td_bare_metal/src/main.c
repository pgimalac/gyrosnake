#include "clocks.h"
#include "led.h"
#include "matrix.h"
#include "uart.h"
#include "utils.h"

void test_pixels() {
    rgb_color colors[8];

    for (int i = 0; i < 8; i++) {
        colors[i].r = ((i + 1) << 5) - 1;
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
        colors[i].g = ((i + 1) << 5) - 1;
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
        colors[i].b = ((i + 1) << 5) - 1;
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

    test_pixels();

    return 0;
}
