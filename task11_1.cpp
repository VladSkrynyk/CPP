#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void write_in_file(const char* fname, double lst[], int n) {
    FILE* file;
    fopen_s(&file, fname, "w");

    for (int i = 0; i < n; i++) {
        fprintf(file, "%lf\t", lst[i]);
    }

    fclose(file);
}

void read_fromn_file(const char* fname, int n) {
    FILE* fl;
    fopen_s(&fl, fname, "rt");
    double temp;

    fscanf_s(fl, "%lf ", &temp);
    printf("%.2lf", temp);

    for (int i = 1; i < n; i++)
    {
        fscanf_s(fl, "%lf ", &temp);
        printf(", %.2lf", temp);
    }

    printf("\n");
    fclose(fl);
}


int main() {
    char str[100];
    printf("Input filename => ");
    fgets(str, 100, stdin);
    int size = strlen(str); 
    str[size - 1] = '\0';

    printf("Your filename : %s", str);
    
    int n;

    printf("\nnumber of elemnts: ");
    scanf_s("%d", &n);
   
    double* array1 = (double*)malloc(n * sizeof(array1));
    for (int i = 0; i < n; i++) {
        printf("a[%d]=", i + 1);
        scanf_s("%lf", &array1[i]);
    }
    
    
    write_in_file(str, array1, n);
    read_fromn_file(str, n);

    free(array1);

    return 0;
}