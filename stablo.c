#include "stablo.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int IsPrime(int x)
{
    int i=0;
    x=abs(x);
    if (x<=1)
        return -1;
    for (int i=2; i*i<=x; i++){
        if (x % i == 0)
            return 0;
    }
    return ++i;
}

int minimum(node* root)
{
    if(root->left)
        return minimum(root->left);
    else
        return root->data;
}

node* novi(int value)
{
    node* n = (node*)malloc(sizeof(node));
    n->left = NULL;
    n->right = NULL;
    n->data = value;
    return n;
}

node* dodaj(node** root, int value)
{
    if(*root == NULL)
        root = novi(value);
    else if(value <= (*root)->data)
        dodaj(&(*root)->left, value);
    else
        dodaj(&(*root)->right, value);
}

void print(node* root)
{
    if(root==NULL)
        return;
    printf("%d ", root->data);
    print(root->left);
    print(root->right);
}

