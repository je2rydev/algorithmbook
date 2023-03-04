/*
    1hour
    // temp->left = NULL;
    -> occur on error about heap-use-after-free
*/

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
    void flatten(TreeNode* root) {
        TreeNode* temp = root;
        stack<TreeNode*> stackNode;
        if(root == NULL)
            return;
        stackNode.push(root);
        while(!stackNode.empty()){
            TreeNode* cur = stackNode.top();
            stackNode.pop();
            if(cur->right != NULL){
                stackNode.push(cur->right);
            }
            if(cur->left != NULL){
                stackNode.push(cur->left);
            }
            if(root == cur)
                continue;
            temp->right = cur;
            temp->left = NULL;
            temp = cur;
        }
    }
};