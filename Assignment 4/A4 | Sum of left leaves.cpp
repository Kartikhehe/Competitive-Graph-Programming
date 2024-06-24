//assignment 4
//sum of left leaves
//Leetcode problem: https://leetcode.com/problems/sum-of-left-leaves/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        if(root->left!=nullptr && root->left->left==nullptr && root->left->right==nullptr){
            return root->left->val + sumOfLeftLeaves(root->right);
        }if(root->left==nullptr && root->right==nullptr){
            return 0;
        }
        if(root->left==nullptr && root->right!=nullptr){
            return sumOfLeftLeaves(root->right);
        }return sumOfLeftLeaves(root->left)+ sumOfLeftLeaves(root->right);
    }
};