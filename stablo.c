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
