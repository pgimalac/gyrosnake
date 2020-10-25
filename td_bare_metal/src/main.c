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

extern const uint8_t _binary_image_raw_start;

void display_img() {
    const uint8_t *raw = &_binary_image_raw_start;

    rgb_color img[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            img[i][j].r = *raw;
            raw++;
            img[i][j].g = *raw;
            raw++;
            img[i][j].b = *raw;
            raw++;
        }
    }

    while (1) {
        for (int i = 0; i < 8; i++) {
            mat_set_row(i, img[i]);
            sleep(10000);
        }
    }
}

int main() {
    clocks_init();
    matrix_init();

    while (1) {
        test_pixels();
    }
    // display_img();

    return 0;
}
