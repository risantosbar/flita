#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int decimal(int number, int *p_res) {
    int new_number = 0, discharge = 1, err = 0;
    if (number <= 0) {
        err = 1;
    }
    while (number != 0) {
        new_number += (number % 10) * discharge;
        number /= 10;
        discharge *= 2;
    }
    if (err == 0) {
        *p_res = new_number;
    }
    return err;

}

int main(int argc, char *argv[]) {
    int number_in_ten, number_in_two, err;
    printf("Conversion from binary to decimal:\n");
    for (int i = 1; i < argc; i++) {
        number_in_two = strtol(argv[i], NULL, 10);
        err = decimal(number_in_two, &number_in_ten);
        if (err) {
            if (!strcmp(argv[i], "0")) {
                number_in_ten = 0;
                printf("%d -> %d\n", number_in_two, number_in_ten);
            } else {
                printf("%s -> Unsuitable element!\n", argv[i]);
            }
        } else {
            printf("%d -> %d\n", number_in_two, number_in_ten);
        }
    }
    return 0;
}
