#include <stdio.h>
#include <stdlib.h>
#include "stablo.h"

int main()
{
    node* root=NULL;
    dodaj(root);
    printf("Stablo koje ste uneli u preorder redosledu:\n");
    print(root);
    printf("\nBroj cvorova stabla je %d\n", broj_cvorova(root));
    printf("Broj listova stabla je %d\n", broj_listova(root));
    printf("Proizvod cvorova stabla je %d\n", proizvod_cvorova(root));
    printf("Broj prostih brojeva je %d\n", broj_prostih(root));
    printf("Najmanji element stabla je %d\n", najmanji(root));
    printf("Prosecna vrednost cvorova u stablu je %.2f", prosek(root));
    printf("Proizvod vrednosti manjih od korena je %d\n", proizvod_cvorova(root->left));

    return 0;
}
