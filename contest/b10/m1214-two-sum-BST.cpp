/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    bool search(TreeNode *root, int target) {
        if (root==NULL) return false;
        if (root->val==target)
            return true;
        return search(root->left,target) || search(root->right,target);
    }
    
    bool loop(TreeNode *rt, TreeNode *root2, int target) {
        if (rt == NULL) return false;
        int t = target-rt->val;
        if (search(root2, t)) return true;
        return loop(rt->left, root2, target) || loop(rt->right, root2, target);
    }

    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        return loop(root1, root2, target);
    }
};
