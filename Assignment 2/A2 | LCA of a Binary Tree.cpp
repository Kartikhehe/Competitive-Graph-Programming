//LCA of a Binary Tree
//Assignment 2
//Problem Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* answer= root;
        if(root == nullptr || root ==q || root == p){
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left == nullptr){
            return right;
        }else if(right==nullptr){
            return left;
        }else{
            return root;
        }

        
    }
};