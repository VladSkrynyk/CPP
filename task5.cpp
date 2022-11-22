#include <stdio.h>

typedef struct
{
    double coef;
    unsigned deg;
}monome;

monome inputMonome()
{
    monome a;
    printf("Coef:");
    scanf("%lf", a.coef);
    printf("deg:");
    scanf("%u", a.deg);
    return a;
}

void printMonome(monome a)
{
    if (a.deg)
    {
        printf("%lf*x^%u", a.coef, a.deg);
    }
    else
    {
        printf("%lf", a.coef);
    }
}

monome deriv(monome a)
{
    monome b;
    if (a.deg)
    {
        b.coef = a.coef * a.deg;
        b.coef = a.deg - 1;
    }
    else
    {
        b.coef = 0;
        b.deg = 0;
    }
}

int writePolynome(const char* fname)
{
    FILE* fp;
    if ((fp = fopen(fname, "rb")) == NULL) {
        printf("Cannot open file.\n");
        return -1;
    }

    unsigned i = 0;

    unsigned number;
    unsigned quantity;
    monome a;
    while (!feof(fp))
    {
        i++;
        fread(&number, 1, sizeof(number), fp);
        fread(&quantity, 1, sizeof(quantity), fp);
        for (unsigned j = 0; j < quantity; j++)
        {
            fread(&a, 1, sizeof(a), fp);
        }
    }
    fclose(fp);

    if ((fp = fopen(fname, "ab")) == NULL) {
        printf("Cannot open file.\n");
        return -1;
    }


    i++;
    printf("Number of polynom is %i", i);
    printf("Quantity of monomes: ");
    scanf("%u", &quantity);

    fwrite(&i, 1, sizeof(i), fp);
    fwrite(&quantity, 1, sizeof(quantity), fp);
    for (unsigned j = 0; j < quantity; j++)
    {
        printf("Monome N %u", j);
        a = inputMonome();
        fwrite(&a, 1, sizeof(a), fp);
    }
    fclose(fp);
    return 0;
}


int printInConsoleFromFile(const char* fname, unsigned g)
{
    FILE* fp;
    if ((fp = fopen(fname, "rb")) == NULL) {
        printf("Cannot open file.\n");
        return -1;
    }

    unsigned i = 0;

    unsigned number;
    unsigned quantity;
    monome a;
    while (!feof(fp))
    {
        i++;
        fread(&number, 1, sizeof(number), fp);
        fread(&quantity, 1, sizeof(quantity), fp);
        if (number == g)
        {
            printf("number:%u\n", number);
            printf("quantity:%u\n", quantity);
        }
        for (unsigned j = 0; j < quantity; j++)
        {
            fread(&a, 1, sizeof(a), fp);
            if (number == g)
            {
                printMonome(a);
                if (j != (quantity - 1))
                {
                    printf("+");
                }
            }
        }
        printf("\n");
    }
    fclose(fp);
    return 0;
}

int printdeirvInFileFromFile(const char* fname, const char* fname2, unsigned g)
{
    FILE* fp;
    FILE* fp1;
    if ((fp = fopen(fname, "rb")) == NULL) {
        printf("Cannot open file.\n");
        return -1;
    }

    if ((fp1 = fopen(fname, "ab")) == NULL) {
        printf("Cannot open file.\n");
        return -1;
    }

    unsigned i = 0;

    unsigned number;
    unsigned quantity;
    monome a;
    while (!feof(fp))
    {
        i++;
        fread(&number, 1, sizeof(number), fp);
        fread(&quantity, 1, sizeof(quantity), fp);
        if (number == g)
        {
            printf("number:%u\n", number);
            printf("quantity:%u\n", quantity);

            fwrite(&i, 1, sizeof(i), fp1);
            fwrite(&quantity, 1, sizeof(quantity), fp1);
        }
        for (unsigned j = 0; j < quantity; j++)
        {
            fread(&a, 1, sizeof(a), fp);
            if (number == g)
            {
                printMonome(deriv(a));
                if (j != (quantity - 1))
                {
                    printf("+");
                }
                if (a.deg != 0)
                {
                    a = deriv(a);
                    fwrite(&a, 1, sizeof(a), fp1);
                }
            }
        }
        printf("\n");
    }
    fclose(fp1);
    fclose(fp);
    return 0;
}

int deletePolynom(const char* fname, unsigned g)
{
    char name3[] = "temppp";
    FILE* p1;
    FILE* fp;
    if ((fp = fopen(fname, "rb")) == NULL) {
        printf("Cannot open file.\n");
        return -1;
    }

    if ((p1 = fopen(name3, "ab")) == NULL) {
        printf("Cannot open file.\n");
        return -1;
    }

    unsigned number;
    unsigned quantity;
    monome a;

    while (!feof(fp))
    {
        fread(&number, 1, sizeof(number), fp);
        fread(&quantity, 1, sizeof(quantity), fp);
        if (number != g)
        {
            fwrite(&number, 1, sizeof(number), p1);
            fwrite(&quantity, 1, sizeof(quantity), p1);
        }
        for (unsigned j = 0; j < quantity; j++)
        {
            fread(&a, 1, sizeof(a), fp);
            if (number != g)
            {
                fwrite(&a, 1, sizeof(a), p1);
            }
        }
    }
    fclose(p1);
    fclose(fp);
    remove(fname);
    rename(name3, fname);
    return 0;
}

int changeCoef(const char* name, unsigned polynom_number, unsigned degree, float cofe)
{
    char name3[] = "temppp";
    FILE* p1;
    FILE* fp;
    if ((fp = fopen(name, "rb")) == NULL) {
        printf("Cannot open file.\n");
        return -1;
    }

    if ((p1 = fopen(name3, "ab")) == NULL) {
        printf("Cannot open file.\n");
        return -1;
    }

    unsigned number;
    unsigned quantity;
    monome a;

    while (!feof(fp))
    {
        fread(&number, 1, sizeof(number), fp);
        fread(&quantity, 1, sizeof(quantity), fp);
        fwrite(&number, 1, sizeof(number), p1);
        fwrite(&quantity, 1, sizeof(quantity), p1);
        for (unsigned j = 0; j < quantity; j++)
        {
            fread(&a, 1, sizeof(a), fp);
            if ((number == polynom_number) && (a.deg == degree))
            {
                a.coef = cofe;
            }
            fwrite(&a, 1, sizeof(a), p1);
        }
    }

    fclose(p1);
    fclose(fp);
    remove(name);
    rename(name3, name);
    return 0;
}


int main()
{
    char name1[] = "11_5file";
    char name2[] = "11_5file_deriv";

    a&d
    writePolynome(name1);

    b
    unsigned num;
    printf("Print number of polynom to print:"); scanf("%u", &num);
    printInConsoleFromFile(name1, num);

    c
    printf("Print number of polynom to differentiate:"); scanf("%u", &num);
    printdeirvInFileFromFile(name1, name2, num);

    e
    deletePolynom(name1, num);

    f
    double cofe;
    unsigned degree;
    printf("Print number of polynom to change:"); scanf("%u", &num);
    printf("Print number of degree to change:"); scanf("%u", &degree);
    printf("Print new coef:");scanf("%lf", &cofe);
    changeCoef(name1, num, degree, cofe)
    return 0;
}