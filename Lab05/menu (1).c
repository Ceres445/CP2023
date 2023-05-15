#include <stdio.h>

void convert(int n) {
    if ( n > 0) {
        int rem = n %2;
        convert ( n  / 2);
        printf("%d", rem);
    }
}

int main() {
    convert(23);
}
