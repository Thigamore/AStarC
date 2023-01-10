#include <string.h>
#include "tree.h"

void insert(tree *tr, node *n)
{
    if (!tr->head)
    {
        tr->head = n;
        tr->smallest = n;
        return;
    }
    node *cur = tr->head;
    while (1)
    {
        if (n->cost <= cur->cost)
        {
            if (!cur->left)
            {
                cur->left = n;
                n->prev = cur;
                break;
            }
            else
            {
                cur = cur->left;
            }
        }
        else
        {
            if (!cur->right)
            {
                cur->right = n;
                n->prev = cur;
                break;
            }
            else
            {
                cur = cur->right;
            }
        }
    }
    if (n->cost < tr->smallest->cost)
    {
        tr->smallest = n;   
    }
};

node *getSmallest(tree *tr)
{
    node *smallest = tr->smallest;
    node *prev = smallest->prev;
    if (smallest->right)
    {
        node *cur = smallest->right;
        if (smallest->isLeft)
        {
            prev->left = cur;
        }
        else
        {
            prev->right = cur;
        }
        while (cur->left)
        {
            cur = cur->left;
        }
        tr->smallest = cur;
    }
    else
    {
        tr->smallest = prev;
        if (smallest->isLeft)
        {
            prev->left = NULL;
        }
        else
        {
            prev->right = NULL;
        }
    }
    return smallest;
}