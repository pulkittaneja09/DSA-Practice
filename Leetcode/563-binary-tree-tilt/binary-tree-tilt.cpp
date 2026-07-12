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
    int tilt=0;
    int findsum(TreeNode * root){
        if(root==NULL) return 0;
        int leftsum=findsum(root->left);
        int rightsum=findsum(root->right);
        tilt+=abs(leftsum-rightsum);
        return leftsum+rightsum+root->val;
    }
    int findTilt(TreeNode* root) {
        if(root==NULL) return 0;
        findsum(root);
        return tilt;

    }
};