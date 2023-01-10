#pragma once

typedef struct 
{
    struct node* left;
    struct node* right;
    char arr[3][3];
    int cost;
} node;

typedef struct {
    node* head;
} tree;

void insert(tree*, node*);