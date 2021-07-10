/*
    题目：
        给定一棵二叉搜索树，请找出其中第k大的节点。
*/
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        this->k = k;
        dfs(root);
        return res;
    }
private:
    int res = 0;
    int k = 0;
    void dfs(TreeNode* root){
        if(root == nullptr)
            return;
        dfs(root->right);
        if(k == 0)
            return;
        if(--k == 0)
            res = root->val;
        dfs(root->left);
    }
};