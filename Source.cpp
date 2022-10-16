#include <stdio.h>
#include <math.h>


// additional 4.30

int nsd(int n, int m) {
    if (n%m == 0)
        return m;
    else {
        int n1 = m;
        int m1 = n%m;
        return nsd(n1, m1);
    }
}

int main() {
    int fi;
    int k = 0;
    printf("Input number: ");
    scanf_s("%d", &fi);

    for (int i = 1; i < fi; i++) {
        if (nsd(i, fi) == 1) {
            k++;
        } 
    } 

    printf("Res => %d", k);
            
}