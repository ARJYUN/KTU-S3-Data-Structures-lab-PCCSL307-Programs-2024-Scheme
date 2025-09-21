#include <stdio.h>

struct poly
{
    int coef;
    int exp;
} p[10], q[10], r[10];

int n1, n2;
int i = 0, j = 0, k = 0;

//adding 2 polynomials
void add()
{

    while (i < n1 && j < n2)
    {
        if (p[i].exp < q[j].exp)
        {
            r[k].exp = q[j].exp;
            r[k].coef = q[j].coef;
            j++, k++;
        }
        else if (p[i].exp > q[j].exp)
        {
            r[k].exp = p[i].exp;
            r[k].coef = p[i].coef;
            i++, k++;
        }
        else
        {
            if (p[i].coef + q[j].coef == 0)
            {
                i++, j++;
            }
            else
            {
                r[k].exp = p[i].exp;
                r[k].coef = p[i].coef + q[j].coef;
                i++, j++, k++;
            }
        }
    }
    while (i < n1)
    {
        r[k].coef = p[i].coef;
        r[k].exp = p[i].exp;
        k++, i++;
    }
    while (j < n2)
    {
        r[k].coef = q[j].coef;
        r[k].exp = q[j].exp;
        k++, j++;
    }
}

//display polynomial
void display()
{
    for (int a = 0; a < k; a++)
    {
        printf("%dx^%d ", r[a].coef, r[a].exp);
        if (a < k - 1)
        {
            printf("+");
        }
    }
}

//main function
int main()
{

    printf("Enter the no.of terms in polynomial 1: ");
    scanf("%d", &n1);
    printf("Enter the polynomial 1 in coef exp order: ");
    for (int a = 0; a < n1; a++)
    {
        scanf("%d", &p[a].coef);
        scanf("%d", &p[a].exp);
    }
    printf("Polynomial 1 is : ");
    for (int a = 0; a < n1; a++)
    {
        printf("%dx^%d ", p[a].coef, p[a].exp);
        if (a < n1 - 1)
        {
            printf("+");
        }
    }

    printf("\nEnter the no.of terms in polynomial 2: ");
    scanf("%d", &n2);
    printf("Enter the polynomial 2 in coef exp order: ");
    for (int b = 0; b < n2; b++)
    {
        scanf("%d", &q[b].coef);
        scanf("%d", &q[b].exp);
    }
    printf("Polynomial 2 is : ");
    for (int a = 0; a < n2; a++)
    {
        printf("%dx^%d ", q[a].coef, q[a].exp);
        if (a < n1 - 1)
        {
            printf("+");
        }
    }

    add();
    printf("\nSum is : \n");
    display();
}