#include "clocks.h"
#include "led.h"
#include "matrix.h"
#include "uart.h"
#include "utils.h"

#define N 1000

void test_pixels() {
    for (int j = 0; j < 8; j++) {
        rgb_color colors[8];

        for (int i = 0; i < 8; i++) {
            colors[i].r = i;
            colors[i].g = 0;
            colors[i].b = 0;
        }
        deactivate_rows();
        mat_set_row(j, colors);
        sleep(1000000000);

        for (int i = 0; i < 8; i++) {
            colors[i].r = 0;
            colors[i].g = i;
            colors[i].b = 0;
        }
        deactivate_rows();
        mat_set_row(j, colors);
        sleep(1000000000);

        for (int i = 0; i < 8; i++) {
            colors[i].r = 0;
            colors[i].g = 0;
            colors[i].b = i;
        }
        deactivate_rows();
        mat_set_row(j, colors);
        sleep(100000000);
    }
}

int main() {
    clocks_init();
    matrix_init();

    SB(1);
    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            SDA(0);
            pulse_SCK();
        }
        for (int i = 0; i < 8; i++) {
            SDA(0);
            pulse_SCK();
        }
        for (int i = 0; i < 8; i++) {
            SDA(1);
            pulse_SCK();
        }
    }
    pulse_LAT();

    // deactivate_rows();
    activate_row(0);
    // activate_row(1);
    // activate_row(2);
    // activate_row(3);
    // activate_row(4);
    // activate_row(5);
    // activate_row(6);
    // activate_row(7);

    // test_pixels();

    // rgb_color colors[] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 1, 0},
    //                       {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    // mat_set_row(0, colors);
    // mat_set_row(1, colors);
    // mat_set_row(2, colors);
    // mat_set_row(3, colors);
    // mat_set_row(4, colors);
    // mat_set_row(5, colors);
    // mat_set_row(6, colors);
    // mat_set_row(7, colors);

    return 0;
}
