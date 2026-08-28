#include <algorithm>
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
    bool isBalanced(TreeNode* root) {
        bool res = true;
        findMaxDepth(root, res);
        return res;    
    }
private:
    int findMaxDepth(TreeNode* root, bool& res) {
        if(!root || res == false ) return 0;

        int left = findMaxDepth(root->left, res);
        int right = findMaxDepth(root->right, res);

        if (abs(left-right)>1) res = false;

        return std::max(left,right) + 1;
    }
};
