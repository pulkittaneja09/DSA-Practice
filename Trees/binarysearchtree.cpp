#include<iostream>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        val=x;
        left=nullptr;
        right=nullptr;
    }
};
class Solution{
    public:
    TreeNode* searchBST(TreeNode* root,int val){
        while(root !=nullptr&&root->val!=val){
            root=val<root->val? root->left:root->right;
        }
        return root;
    }
};
TreeNode* insertBST(TreeNode* root, int val) {
    if (root == nullptr) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}
int main() {
    
    TreeNode* root = nullptr;
    root = insertBST(root, 4);
    root = insertBST(root, 2);
    root = insertBST(root, 7);
    root = insertBST(root, 1);
    root = insertBST(root, 3);

    Solution s;
    int val = 2;
    TreeNode* res = s.searchBST(root, val);

    if (res != nullptr)
        cout << "Found node with value: " << res->val << endl;
    else
        cout << "Value not found in BST" << endl;

    return 0;
}