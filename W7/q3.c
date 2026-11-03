#include <stdio.h>
#include <unistd.h>

int main(void) {
    // Rewrite this code using read and write instead of the stdio functions scanf and printf
    unsigned char c;
    scanf("%c", &c);
    printf("%c", c);
    return 0;
}