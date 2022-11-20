#include <stdio.h>
#include <stdlib.h>

int main5() {

    FILE* file;
    const int bufferLength = 255;
    char buffer[bufferLength];

    fopen_s(&file, "task11_6a.txt", "r");

    int count = 0;
    while (fgets(buffer, bufferLength, file)) {
        char* ptr;
        int number = strtol(buffer, &ptr, 10);
        if (number % 2 == 0) count++;
    }

    printf("Res => %d", count);

    fclose(file);

    return 0;
}