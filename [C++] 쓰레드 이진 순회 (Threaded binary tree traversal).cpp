#include <stdio.h>
#include <stdlib.h>
 
enum product { TRUE = 1, FALSE = 2 };
 
typedef struct treeNode * TreePtr;
typedef struct treeNode
{
    int data;
    TreePtr left;
    TreePtr right;
    int isThread;
} TreeNode;
 
/* 사용자 정의 함수 선언 */
TreePtr findThread(TreePtr node);
TreePtr threadInorder(TreePtr node);
 
void main(void)
{
    TreeNode n1 = { 'A', NULL, NULL, 1 };
    TreeNode n2 = { 'B', NULL, NULL, 1 };
    TreeNode n3 = { 'C', &n1, &n2, 0 };
    TreeNode n4 = { 'D', NULL, NULL, 1 };
    TreeNode n5 = { 'E', NULL, NULL, 0 };
    TreeNode n6 = { 'F', &n4, &n5, 0 };
    TreeNode n7 = { 'G', &n3, &n6, 0 };
    TreeNode *exp = &n7;
 
    n1.right = &n3;
    n2.right = &n7;
    n4.right = &n6;
    threadInorder(exp);
 
    return;
}
 
/* 사용자 정의 함수 정의 */
TreePtr findThread(TreePtr node)
{
    TreePtr temporary = node->right;
 
    if (((temporary == NULL) || (node->isThread == TRUE)))
    { return temporary; }
    else
    { 
        while (temporary->left != NULL) { temporary = temporary->left; } 
        return temporary;
    }
}
TreePtr threadInorder(TreePtr node)
{
    TreePtr temporary = node;
 
    while (temporary->left) { temporary = temporary->left; }
 
    do
    {
        printf("[%c] ", temporary->data);
        temporary = findThread(temporary);
    } while (temporary);
}
