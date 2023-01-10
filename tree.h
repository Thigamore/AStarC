#pragma once
#include <stdbool.h>

typedef struct
{
    struct node *left;
    struct node *right;
    struct node *prev;
    char arr[3][3];
    int cost;
    bool isLeft;
} node;

typedef struct
{
    node *head;
    node *smallest;
} tree;

void insert(tree *, node *);

node *getSmallest(tree *);