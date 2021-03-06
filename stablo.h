#ifndef STABLO_H_INCLUDED
#define STABLO_H_INCLUDED

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} node;

int broj_cvorova(node* root);
int broj_listova(node* root);
int proizvod_cvorova(node* root);
int broj_prostih(node* root);
int najmanji(node* root);
float prosek(node* root);
int minimum(node* root);
node* novi(int value);
void dodaj(node** root, int value);
void print(node* root);

#endif // STABLO_H_INCLUDED
