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

    int longest = 0;
    int diameterOfBinaryTree(TreeNode* root) {

        if (!root) return 0;

        int path_left = longestSubPath(root->left);
        int path_right = longestSubPath(root->right);

        if (path_left + path_right > this->longest) return path_left + path_right;
        else return this->longest;
    }

    int longestSubPath(TreeNode* root) {
        if (!root) return 0;

        int path_left = longestSubPath(root->left);
        int path_right = longestSubPath(root->right);

        int longest_sub_path = std::max(path_left, path_right);
        if (path_left + path_right > this->longest) this->longest = path_left + path_right;

        return longest_sub_path + 1;

    }
};
