#include "stablo.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

node* novi(int value)
{
    node* n = (node*)malloc(sizeof(node));
    n->left = NULL;
    n->right = NULL;
    n->data = value;
    return n;
}

void dodaj(node** root, int value)
{
    if(*root == NULL)
        *root = novi(value);
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


int IsPrime(int x)
{
    int i=0;
    x=abs(x);
    if (x<=1)
        return 0;
    for (i=2; i*i<=x; i++){
        if (x % i == 0)
            return 0;
    }
    return 1;
}

int n = 0;
void izbroj_cvorove(node* root)
{
    if(root == NULL) return;
    n++;
    izbroj_cvorove(root->left);
    izbroj_cvorove(root->right);
}
int broj_cvorova(node* root)
{
    n = 0;
    izbroj_cvorove(root);
    return n;
}

int proizvod = 1;
void izracunaj_proizvod(node* root)
{
    if(root == NULL) return;
    proizvod *= root->data;
    izracunaj_proizvod(root->left);
    izracunaj_proizvod(root->right);
}
int proizvod_cvorova(node* root)
{
    proizvod = 1;
    izracunaj_proizvod(root);
    return proizvod;
}

int brProstih = 0;
void izbroj_proste(node* root)
{
    if(root == NULL) return;
    if(IsPrime(root->data)) brProstih++;
    izbroj_proste(root->left);
    izbroj_proste(root->right);
}
int broj_prostih(node* root)
{
    brProstih = 0;
    izbroj_proste(root);
    return brProstih;
}

int minimum(node* root)
{
    if(root->left)
        return minimum(root->left);
    else
        return root->data;
}

int brListova;
void izbroj_listove(node* root)
{
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL)
        brListova++;
    izbroj_listove(root->left);
    izbroj_listove(root->right);
}
int broj_listova(node* root)
{
    brListova = 0;
    izbroj_listove(root);
    return brListova;
}

int zbir;
void izracunaj_zbir(node* root)
{
    if(root == NULL)
        return;
    zbir += root->data;
    izracunaj_zbir(root->left);
    izracunaj_zbir(root->right);
}
float prosek(node* root)
{
    zbir = 0;
    izracunaj_zbir(root);
    return (float)zbir/broj_cvorova(root);
}
