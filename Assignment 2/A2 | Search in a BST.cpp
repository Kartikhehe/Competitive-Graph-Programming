//Assignment 2
//Search in a BST
//Problem Link : https://leetcode.com/problems/search-in-a-binary-search-tree/


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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root->val == val){
            return root;
        
        }TreeNode* answer = root;

        while(answer!= nullptr ){
            if(answer->val == val){
                return answer;
            }
            if(answer->val > val){
                answer = answer->left;}
            else{
                answer = answer->right;
            }
        }return nullptr;
    }
};