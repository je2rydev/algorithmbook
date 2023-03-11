// 102. Binary Tree Level Order Traversal
// 30 mins
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
private:
    vector<vector<int>> res;
    void curOrder(TreeNode* cur, int depth){
        if(cur != NULL){
            if(res.size() <= depth){
            vector<int> tmp = {cur->val};
            res.push_back(tmp);
            }else{
                res[depth].insert(res[depth].end(), cur->val);
            }
        }else
            return;
        
        if(cur->left != NULL){
            curOrder(cur->left, depth+1);
        }
        if(cur->right != NULL){
            curOrder(cur->right, depth+1);
        }
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        curOrder(root, 0);

        return res;
    }
};