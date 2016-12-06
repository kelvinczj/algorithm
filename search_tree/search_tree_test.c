/// @file search_tree_test.c
/// @brief test for search_tree
/// @author kelvin
/// @version 1.0
/// @email kelvinczj@126.com
/// @date 2016-12-06


#include <stdio.h>
#include <stdlib.h>

#include "search_tree.h"

#define SEED_CNT 11
static  int rand_seed[] = {10, 8, 99, 55, 6, 3, 9, 100, 51, -63, -8};

void print_sort(SearchTree t)
{
    if (NULL == t)
        return;

    if (NULL != t->left)
        print_sort(t->left);
    printf(" %d ", t->element);
    if (NULL != t->right)
        print_sort(t->right);
}

int main(int argc, char* argv[])
{
    SearchTree s = NULL;
    int i = 0;

    for (i = 0; i < SEED_CNT - 1; i++)
        s = st_add(rand_seed[i], s);
    
    print_sort(s); 
    printf("\n");

    s = st_delete(rand_seed[3], s); 
    print_sort(s); 
    printf("\n");

    Position p = st_find(rand_seed[2], s);
    if (NULL != p) 
        printf("find %d\n", p->element);
    else
        printf("can not find element\n");

    printf("find max:%d, min:%d\n", st_find_max(s)->element, st_find_min(s)->element);

    st_make_empty(&s);
    if (NULL == s)
        printf("make empty success\n");
    else
        printf("make empty failed\n");

    return 0;
}
