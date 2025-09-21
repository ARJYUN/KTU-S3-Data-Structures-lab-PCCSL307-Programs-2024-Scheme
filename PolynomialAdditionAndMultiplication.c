#include <stdio.h>
#include <stdlib.h>

//structure of node
typedef struct Node
{
    int coef;
    int exp;
    struct Node *link;
} Node;

//creating a node
Node *createnode(int coef, int exp)
{
    Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->coef = coef;
    node->exp = exp;
    node->link = NULL;
    return node;
}

//insert a term to a polynomial
void insert(Node **poly, int coef, int exp)
{
    if (coef == 0)
        return;

    Node *ptr = *poly;
    Node *pre = NULL;

    while (ptr && ptr->exp > exp)
    {
        pre = ptr;
        ptr = ptr->link;
    }

    if (ptr && ptr->exp == exp)
    {
        ptr->coef += coef;
        if (ptr->coef == 0)
        {
            if (pre)
            {
                pre->link = ptr->link;
            }
            else
            {
                *poly = ptr->link;
            }
            free(ptr);
        }
    }
    else
    {
        Node *term = createnode(coef, exp);
        term->link = ptr;
        if (pre)
        {
            pre->link = term;
        }
        else
        {
            *poly = term;
        }
    }
}

//input polynomial from the user
void input(Node **poly)
{
    int n;
    printf("Enter the number of terms in polynomial : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int coef, exp;
        printf("Enter the coeff, exp : ");
        scanf("%d %d", &coef, &exp);
        insert(poly, coef, exp);
    }
}

//displaying polynomial
void display(Node *poly)
{
    while (poly)
    {
        printf(" %dx^%d ", poly->coef, poly->exp);
        if (poly->link && poly->link->coef > 0)
        {
            printf("+");
        }
        poly = poly->link;
    }
}

//adding 2 polynomials
Node *add(Node *poly1, Node *poly2)
{
    Node *result = NULL;
    while (poly1 && poly2)
    {
        if (poly1->exp > poly2->exp)
        {
            insert(&result, poly1->coef, poly1->exp);
            poly1 = poly1->link;
        }
        else if (poly2->exp > poly1->exp)
        {
            insert(&result, poly2->coef, poly2->exp);
            poly2 = poly2->link;
        }
        else
        {
            insert(&result, poly1->coef + poly2->coef, poly1->exp);
            poly1 = poly1->link;
            poly2 = poly2->link;
        }
    }
    while (poly1)
    {
        insert(&result, poly1->coef, poly1->exp);
        poly1 = poly1->link;
    }
    while (poly2)
    {
        insert(&result, poly2->coef, poly2->exp);
        poly2 = poly2->link;
    }
    return result;
}

//multiplying 2 polynomials
Node *multi(Node *poly1, Node *poly2)
{
    Node *result = NULL;
    for (Node *p1 = poly1; p1 != NULL; p1 = p1->link)
    {
        for (Node *p2 = poly2; p2 != NULL; p2 = p2->link)
        {
            int coef = p1->coef * p2->coef;
            int exp = p1->exp + p2->exp;
            insert(&result, coef, exp);
        }
    }
    return result;
}

//menu driven main function
int main()
{
    Node *poly1 = NULL;
    Node *poly2 = NULL;
    printf("Enter polynomial 1 : \n");
    input(&poly1);
    display(poly1);
    printf("\n");
    printf("Enter polynomial 2 : \n");
    input(&poly2);
    display(poly2);
    printf("\n");
    Node *sum = add(poly1, poly2);
    printf("The Sum is : ");
    display(sum);
    printf("\n");
    Node *product = multi(poly1, poly2);
    printf("The product is : ");
    display(product);
    return 0;
}