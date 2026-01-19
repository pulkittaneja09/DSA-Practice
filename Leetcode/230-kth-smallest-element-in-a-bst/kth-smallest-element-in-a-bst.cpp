class Solution {
public:
    int prevOrder = 0;

    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL) {
            return -1;
        }

        if (root->left != NULL) {
            int leftAns = kthSmallest(root->left, k);
            if (leftAns != -1)
                return leftAns;
        }

        if (prevOrder + 1 == k) {
            return root->val;
        }

        prevOrder++;

        return kthSmallest(root->right, k);
    }
};
