//Zigzag traversal;
//Assignment 2
//Problem Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if(root==NULL){return answer;}
        queue<TreeNode*> hey;
        int check = 0;//left to right;
        hey.push(root);
        while(hey.empty()==false){
            
            int sizeofQ=hey.size();
            vector<int> temp(sizeofQ);
            
            for(int i=0;i<sizeofQ;i++){
                
                TreeNode* current = hey.front();
                hey.pop();
                if(check==1){
                    temp[sizeofQ-i-1] = current->val;
                    
                }else{
                    temp[i] = current->val;
                    
                }
                
                if(current->left!=NULL){
                    hey.push(current->left);
                }if(current->right!=NULL){
                    hey.push(current->right);
                }
            
            }check = (check==1) ? 0 : 1;
            answer.push_back(temp);
            
        }
        
        // for(int i=0;i<answer.size();i++){
        //     if(i%2==1){
        //         reverse(answer[i].begin(),answer[i].end()); 
        //     }
        // }


        return answer;
    }
};