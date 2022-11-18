#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct {
    char col;
    int row;
} Field;

bool correctness(Field x) {
    if (x.col < 'a' || x.col > 'h')
        return false;

    if (x.row < 1 || x.row > 8)
        return false;

    return true;
}

Field field_input() {
    Field res;
    char c;
    printf("Col, row => ");
    scanf_s("%c", &c);
    res.col = tolower(c);
    scanf_s("%d", &res.row);
    
    return res;
}

void output(const Field x) {
    printf("%c:%u", x.col, x.row);
}

bool check(Field x, Field y) {
    if (x.col == y.col) return true;
    if (x.row == y.row) return true;
    if ((x.col - y.col) == (x.row - y.row)) return true;
    if ((x.col - y.col) == (y.row - x.row)) return true;

    return false;
}


int main5() {
    Field pstn1, pstn2;
    do {
        printf("Field1:\n");
        pstn1 = field_input();
    } while (!correctness(pstn1));

    do
    {
        printf("Field2:\n");
        pstn2 = field_input();
    } while (!correctness(pstn2));

    if (check(pstn1, pstn2))
    {
        printf("\nYes, it can move from ");
    }
    else
    {
        printf("\nNo, it can't move from ");
    }

    output(pstn1);
    printf(" to ");
    output(pstn2);

    return 0;
}