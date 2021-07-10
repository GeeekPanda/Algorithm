/*
    题目：
        给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
*/

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

// 递归版本
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return {};
        res.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return res;
    }
private:
    std::vector<int> res;
};

//非递归版本
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return {};
        std::stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* top = stk.top();
            stk.pop();
            res.push_back(top->val);
            if(top->right != nullptr)
                stk.push(top->right);
            if(top->left != nullptr)
                stk.push(top->left);
        }
        return res;
    }
private:
    std::vector<int> res;
};
