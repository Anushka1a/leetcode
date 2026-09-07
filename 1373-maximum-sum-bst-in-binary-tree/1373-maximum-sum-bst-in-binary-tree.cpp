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
    struct Node {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;

        Node(bool bst, int s, int mn, int mx)
            : isBST(bst), sum(s), minVal(mn), maxVal(mx) {}
    };

    int ans = 0;

    Node dfs(TreeNode* root) {
        if (!root)
            return Node(true, 0, INT_MAX, INT_MIN);

        Node left = dfs(root->left);
        Node right = dfs(root->right);

        if (left.isBST && right.isBST &&
            root->val > left.maxVal &&
            root->val < right.minVal) {

            int currSum = left.sum + right.sum + root->val;
            ans = max(ans, currSum);

            return Node(
                true,
                currSum,
                min(root->val, left.minVal),
                max(root->val, right.maxVal)
            );
        }

        return Node(false, 0, INT_MIN, INT_MAX);
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};