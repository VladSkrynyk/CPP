#include <stdio.h>
#include <math.h>
#include <vector>

typedef struct
{
    char name[60];
    double cost;
    unsigned age_min;
    unsigned age_max;
}Toy;

Toy inputToyConsole()
{
    Toy a;
    printf("Name: ");
    scanf("%50s", &a.name);
    printf("Cost: ");
    scanf("%lf", &a.cost);
    printf("Min age: ");
    scanf("%u", &a.age_min);
    printf("Max age: ");
    scanf("%5u", &a.age_max);
    return a;
}

void printToyConsole(const Toy a)
{
    printf("Name: %50s\n", a.name);
    printf("Cost: %lf\n", a.cost);
    printf("Min age: %u\n", a.age_min);
    printf("Max age: %u\n", a.age_max);
}

void writeToBin(const char* fname, const Toy a)
{
    FILE* fp;
    if ((fp = fopen(fname, "ab")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }
    fwrite(&a, 1, sizeof(Toy), fp);
    fclose(fp);
}
std::vector <Toy> readFromBin(const char* fname)
{
    std::vector <Toy> a;
    FILE* fp;
    if ((fp = fopen(fname, "rb")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }
    Toy b;

    while (!feof(fp))
    {
        fread(&b, 1, sizeof(Toy), fp);
        //printToyConsole(b);
        a.push_back(b);
    }
    fclose(fp);
    return a;
}

void find(const std::vector <Toy> a, unsigned dif, const char* fname, char name[50])
{
    Toy exp = a.at(0);
    for (auto b : a)
    {
        if (exp.name == name)
        {
            exp = b;
            printToyConsole(b);
            writeToBin(fname, b);
        }
    }

}

int main()
{
    int n;
    char name1[] = "11_12readFrom";
    char name2[] = "11_12writeTo";

    /*
    printf("NUmber of toys:");
    scanf("%i", &n);
    Toy temp;
    for (int i = 0; i < n; i++)
    {
        temp = inputToyConsole();
        writeToBin(name1, temp);
    }
    */
    unsigned int g;
    printf("Input difference:");
    scanf("%u", &g);
    char name[50] = "name";
    find(readFromBin(name1), g, name2, name);
}
