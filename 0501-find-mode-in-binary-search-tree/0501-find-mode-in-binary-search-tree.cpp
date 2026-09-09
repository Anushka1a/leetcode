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
    vector<int> v;

    void inorder(TreeNode* root) {
        if (root == NULL) return;

        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);

        sort(v.begin(), v.end());

        vector<int> ans;
        int maxFreq = 0, cnt = 1;

        for (int i = 1; i <= v.size(); i++) {
            if (i < v.size() && v[i] == v[i - 1])
                cnt++;
            else {
                if (cnt > maxFreq) {
                    maxFreq = cnt;
                    ans.clear();
                    ans.push_back(v[i - 1]);
                } 
                else if (cnt == maxFreq) {
                    ans.push_back(v[i - 1]);
                }
                cnt = 1;
            }
        }

        return ans;
    }
};