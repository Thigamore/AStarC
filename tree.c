#include <string.h>
#include "tree.h" 

void insert(tree* tr, node* n) {
    if(!tr->head) {
        tr->head = n;
    }
    node *cur = tr->head;
    while(1) {
        if(n->cost <= cur->cost) {
            if(!cur->left) {
                cur->left = n;
                return;
            } else {
                cur = cur->left;
            }
        } else {
            if(!cur->right) {
                cur->right = n;
                return;
            } else {
                cur = cur->right;
            }
        }
    }

};

