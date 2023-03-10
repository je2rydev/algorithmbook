/*
    101. Symmetric Tree
    1hour
*/

/**
 * 
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
    bool isSymmetric(TreeNode* root) {
        TreeNode* curLeft = root->left;
        TreeNode* curRight = root->right;
        queue<TreeNode*> leftQueue;
        queue<TreeNode*> rightQueue;
        if((curLeft == NULL && curRight != NULL) || (curLeft != NULL && curRight == NULL))
            return false;
        else if(curLeft == NULL && curRight == NULL)
            return true;
        if(curLeft->val != curRight->val)
            return false;
        leftQueue.push(curLeft);
        rightQueue.push(curRight);
        while(!(leftQueue.empty() && rightQueue.empty())){
            curLeft = leftQueue.front();
            leftQueue.pop();
            curRight = rightQueue.front();
            rightQueue.pop();

            // cout <<"asdasdasd" << endl;
            
            if(curLeft != NULL && curRight != NULL){
                // cout << "curLeft : " << curLeft->val << endl;
                // cout << "curRight : " << curRight->val << endl;
                if(curLeft->val != curRight->val)
                    return false;
                // cout << "curLeft->right : " << curLeft->right->val << endl;
                // cout << "curRight->left : " << curRight->left->val << endl;
                // cout << "curRight : " << curRight->left->val << endl;
                leftQueue.push(curLeft->right);
                leftQueue.push(curLeft->left);
                rightQueue.push(curRight->left);
                rightQueue.push(curRight->right);
                // cout << "curRight : " << curRight->val << endl;
            }else if(curLeft == NULL && curRight == NULL)
                continue;
            else
                return false;
        }
        return true;
    }
};