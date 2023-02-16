/*
    104. Maximum Depth of Binary Tree
    Spend 10 minutes
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
    int explore(TreeNode* node){
        if(node == NULL){
            return 0;
        }
        if(node->left == NULL && node->right == NULL)
            return 1;

        return max(explore(node->right)+1, explore(node->left)+1);
    }

    int maxDepth(TreeNode* root) {
        return explore(root);
    }
};