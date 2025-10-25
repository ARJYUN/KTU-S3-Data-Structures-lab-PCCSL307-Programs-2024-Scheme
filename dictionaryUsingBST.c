#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char word[50];
    char meaning[200];
    struct Node *left, *right;
};

struct Node* root = NULL;

struct Node* createNode(char word[], char meaning[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->word, word);
    strcpy(newNode->meaning, meaning);
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(char word[], char meaning[]) {
    struct Node *parent = NULL, *p = root;

    while (p != NULL) {
        parent = p;
        if (strcmp(word, p->word) < 0)
            p = p->left;
        else if (strcmp(word, p->word) > 0)
            p = p->right;
        else {
            printf("Word already exists in dictionary!\n");
            return;
        }
    }
    struct Node* newNode = createNode(word, meaning);
    if (parent == NULL)
        root = newNode;
    else if (strcmp(word, parent->word) < 0)
        parent->left = newNode;
    else
        parent->right = newNode;
}


struct Node* search(char word[]) {
    struct Node *p = root;
    while (p != NULL) {
        if (strcmp(word, p->word) == 0)
            return p;
        else if (strcmp(word, p->word) < 0)
            p = p->left;
        else
            p = p->right;
    }
    return NULL;
}


void inorder(struct Node* node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%s : %s\n", node->word, node->meaning);
        inorder(node->right);
    }
}

void main() {
    int choice;
    char word[50], meaning[200];

    while (1) {
        printf("\nDictionary Menu\n------------------\n");
        printf("1. Insert Word\n");
        printf("2. Search Word\n");
        printf("3. Display Dictionary\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter word: ");
                scanf("%s",word);
                printf("Enter meaning: ");
                scanf("%s",meaning);
                insert(word, meaning);
                break;

            case 2:
                printf("Enter word to search: ");
                scanf("%s",word);
                struct Node* res = search(word);
                if (res != NULL)
                    printf("Meaning of %s: %s\n", res->word, res->meaning);
                else
                    printf("Word not found!\n");
                break;

            case 3:
                printf("\nDictionary Words\n--------------------\n");
                inorder(root);
                break;

            case 4:
                return;

            default:
                printf("Invalid choice!\n");
                
        }
    }
}
