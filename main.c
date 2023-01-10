#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tree.h"
#include "hashmap.h"

int main()
{

    // Testing manDist

    char arr[3][3] = {{8, 3, 2}, {4, 7, 1}, {0, 5, 6}};
    int dist = manDist(arr);
    printf("dist: %d", dist);
    

    /* Testing Tree
    node n = {.left = NULL, .right = NULL, .cost = 10, .arr = {{0,1,2},{3,4,5}, {6,7,8} }};
    node n1 = {.left = NULL, .right = NULL, .cost = 8, .arr = {{0,1,2},{3,4,5}, {6,7,8} }};
    node n2 = {.left = NULL, .right = NULL, .cost = 9, .arr = {{0,1,2},{3,4,5}, {6,7,8} }};
    tree tr = {.head = &n};
    node* cur = tr.head;
    insert(&tr, &n1);
    insert(&tr, &n2);
    cur = tr.head->left;
    cur = cur->right;
    printf("cost: %d, arr: {{%d, %d, %d},{%d, %d, %d},{%d, %d, %d}}", cur->cost, cur->arr[0][0],cur->arr[0][1],cur->arr[0][2],cur->arr[1][0],cur->arr[1][1],cur->arr[1][2],cur->arr[2][0],cur->arr[2][1],cur->arr[2][2]);
    */

    return 0;
}

int isPossible(char arr[3][3])
{
    int inv = 0;
    char prev;
    for (int i = 1; i < 3; i++)
    {
        if (arr[0][i] > arr[0][i - 1])
        {
            inv++;
        }
    }
    for (int i = 1; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] > arr[i][j])
            {
                inv++;
            }
        }
    }
    return inv;
}

void findBlank(char arr[3][3], int pos[2])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == 0)
            {
                printf("i:%d, j:%d\n", i, j);
                pos[0] = i;
                pos[1] = j;
                return;
            }
        }
    }
}

void add1(char arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] += 1;
        }
    }
}

void sub1(char arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] -= 1;
        }
    }
}

void printTiles(char arr[3][3])
{
    printf("arr: {{%d, %d, %d},{%d, %d, %d},{%d, %d, %d}}\n", arr[0][0], arr[0][1], arr[0][2], arr[1][0], arr[1][1], arr[1][2], arr[2][0], arr[2][1], arr[2][2]);
}

int manDist(char arr[3][3])
{
    int dist = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dist += abs(i - (arr[i][j] / 3)) + abs(j - (arr[i][j] % 3));
        }
    }
    int pos[2] = {0, 0};
    findBlank(arr, pos);
    arr[pos[0]][pos[1]] = 9;
    sub1(arr);
    int dist2 = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dist2 += abs(i - (arr[i][j] / 3)) + abs(j - (arr[i][j] % 3));
        }
    }
    add1(arr);
    arr[pos[0]][pos[1]] = 0;
    if (dist < dist2)
    {
        return dist;
    }
    else
    {
        return dist2;
    }
}