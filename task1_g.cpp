#include<stdio.h>
#include<stdlib.h>

struct poly {
	int coeff;
	int expo;
};

int readPoly(struct poly[], int t);
void displayPoly(struct poly[], int terms);

int main3() {
	int t;

	printf("Enter the total number of terms in the polynomial:");
	scanf_s("%d", &t);

	struct poly* p1 = (poly*)malloc(t * sizeof(poly));

	t = readPoly(p1, t);
	printf(" \n Polynomial : ");
	displayPoly(p1, t);


	return 0;
}

int readPoly(struct poly p[], int t) {
	printf("\n Enter the COEFFICIENT and EXPONENT in DESCENDING ORDER\n");
	for (int i = 0; i < t; i++) {
		printf("   Enter the Coefficient(%d): ", i + 1);
		scanf_s("%d", &p[i].coeff);
		printf("      Enter the exponent(%d): ", i + 1);
		scanf_s("%d", &p[i].expo);        
	}
	return(t);
}

void displayPoly(struct poly p[], int term) {
	int k;

	for (k = 0; k < term - 1; k++)
		printf("%d(x^%d)+", p[k].coeff, p[k].expo);
	printf("%d(x^%d)", p[term - 1].coeff, p[term - 1].expo);
}