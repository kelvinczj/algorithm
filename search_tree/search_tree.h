/// @file search_tree.h
/// @brief this version is not support add same value 
/// @author kelvin
/// @version 1.0
/// @email kelvinczj@126.com
/// @date 2016-12-06


#ifndef __SEARCH_TREE_H__
#define __SEARCH_TREE_H__

typedef int ElementType;

typedef struct TreeNode 
{
    ElementType element;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

typedef TreeNode* SearchTree;
typedef TreeNode* Position;


Position st_find(ElementType e, SearchTree tree);
Position st_find_min(SearchTree tree);
Position st_find_max(SearchTree tree);
SearchTree st_delete(ElementType e, SearchTree tree);
void st_make_empty(SearchTree* tree);
SearchTree st_add(ElementType e, SearchTree tree);


#endif
