//ACCESSING ARRAY USING POINTERS
#include <stdio.h>

int main() {
    int num[4] = {14, 65, 45, 48};
    char ch[4] = {'f', '6', 'w', 'g'};

    int *ptr = &num[0];
    char *chPtr = &ch[0];

    for (int i = 0; i < 4; i++) {
        printf("num[%d] address: %p && ptr = %p\n", i, &num[i], ptr);
        printf("num[%d] using pointer = %d\n", i, *ptr++);

        printf("ch[%d] address: %p && chPtr = %p\n", i, &ch[i], chPtr);
        printf("ch[%d] using pointer = %c\n", i, *chPtr++);
    }

    return 0;
}
