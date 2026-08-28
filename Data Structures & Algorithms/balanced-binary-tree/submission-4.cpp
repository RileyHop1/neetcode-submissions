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
        if(root) {
            int left = findMaxDepth(root->left);
            int right = findMaxDepth(root->right);

            if (abs(left-right)>1) this->balanced = false;
        }
        return this->balanced;
    }
private:
    bool balanced = true;
    int findMaxDepth(TreeNode* root) {
        if(!root || this->balanced == false ) return 0;

        int left = findMaxDepth(root->left);
        int right = findMaxDepth(root->right);

        if (abs(left-right)>1) this->balanced = false;



        return std::max(left,right) + 1;


    }
};
