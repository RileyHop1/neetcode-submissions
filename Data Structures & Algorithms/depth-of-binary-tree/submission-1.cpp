#include <list>

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

    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        list<TreeNode*> qu{};
        TreeNode* last = root;
        int depth = 0;
        last->val = depth;

        qu.push_front(last);
        while(!qu.empty()) {
            last = qu.back();
            int level = last->val + 1;
            TreeNode* left = last->left;
            TreeNode* right = last->right;
            if(left) {
                left->val = level;
                qu.push_front(left);
            }
            if(right) {
                right->val = level;
                qu.push_front(right);
            }
            qu.pop_back();
            if(level > depth) depth = level;
        } 
        return depth;
        
    }
};
