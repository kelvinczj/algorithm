/// @file search_tree.c
/// @brief this version is not support add same value
/// @author kelvin
/// @version 1.0
/// @email kelvinczj@126.com
/// @date 2016-12-06


#include <stdlib.h>
#include <stdio.h>

#include "search_tree.h"

Position st_find(ElementType e, SearchTree tree)
{
    Position T;

    if (NULL == tree) 
        return NULL;

    if (tree->element == e) {
        T =  tree;
    } else if (tree->element > e ) {
        if (NULL == tree->left) 
            T =  NULL;
        else 
            T = st_find(e, tree->left);
    } else {
        if (NULL == tree->right)
            T =  NULL;
        else 
            T = st_find(e, tree->right);
    }

    return T;
}

Position st_find_min(SearchTree tree) 
{
    if (NULL == tree) 
        return NULL;

    if (NULL == tree->left)
        return tree;
    else 
        return st_find_min(tree->left);
}

Position st_find_max(SearchTree tree)
{
    if (NULL == tree)
        return NULL;

    if (NULL == tree->right)
        return tree;
    else 
        return st_find_max(tree->right);
}

SearchTree st_delete(ElementType e, SearchTree tree)
{
    SearchTree T = tree;

    if (NULL == tree)
        return NULL;

    if (e < tree->element) {
        tree->left = st_delete(e, tree->left);
    } else if (e > tree->element) {
        tree->right = st_delete(e, tree->right);
    } else {
        if (NULL != tree->right && NULL != tree->left) {
            Position max = st_find_max(tree->left);
            tree->element = max->element;
            tree->left = st_delete(max->element, tree->left);
            T = tree;
        } else {
            if (NULL == tree->left && NULL != tree->right) 
                T = tree->right;
            else if (NULL == tree->right && NULL != tree->left) 
                T = tree->left;
            else 
                T = NULL;
            free(tree);
        }
    }

    return T;
}

void st_make_empty(SearchTree* tree) 
{
    if (NULL == (*tree)) 
        return;

    if (NULL != (*tree)->left) 
        st_make_empty(&((*tree)->left));
    if (NULL != (*tree)->right)
        st_make_empty(&((*tree)->right));
    free((*tree));
    
    *tree = NULL;
}

SearchTree st_add(ElementType e, SearchTree tree)
{
    SearchTree T;

    if (NULL == tree) { 
        TreeNode* node= (TreeNode*)malloc(sizeof(TreeNode));
        if (NULL == node) {
            printf("leack of memory\n");
            return tree;
        }
        node->left = node->right = NULL;
        node->element = e;
        T = node;
    } else {
        if (e < tree->element) 
            tree->left = st_add(e, tree->left);
        else if( e > tree->element) 
            tree->right = st_add(e, tree->right);
        else 
            printf("not support add same value now\n");
        T = tree;
    }

    return T;
}
