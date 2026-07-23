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
    bool hasPathSum(TreeNode* root, int targetsum) {
        if(root==nullptr){
            return false;
        }
        if(root->left==nullptr&&root->right==nullptr){
            if(targetsum==root->val){
                return true;
            }
            else{
                return false;
            }
        }
        bool left=hasPathSum(root->left,targetsum-root->val);
        bool right=hasPathSum(root->right,targetsum-root->val);
        if(left||right){
            return true;
        }
        else {
            return false;
        }
    }
};