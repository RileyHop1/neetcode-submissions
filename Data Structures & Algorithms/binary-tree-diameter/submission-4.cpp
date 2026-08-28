#include<algorithm>


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

    int diameterOfBinaryTree(TreeNode* root) {

        if (!root) return 0;

        int path_left = longestSubPath(root->left);
        int path_right = longestSubPath(root->right);

        return std::max(this->longest, path_left + path_right );
    }
private:
    int longest = 0;

    int longestSubPath(TreeNode* root) {
        if (!root) return 0;

        int path_left = longestSubPath(root->left);
        int path_right = longestSubPath(root->right);
        
        this->longest = std::max(this->longest, path_left + path_right );

        return std::max(path_left, path_right) + 1;

    }
};
