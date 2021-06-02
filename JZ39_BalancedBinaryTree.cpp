/*
    题目：
        输入一棵二叉树，判断该二叉树是否是平衡二叉树。
        在这里，我们只需要考虑其平衡性，不需要考虑其是不是排序二叉树。注：我们约定空树是平衡二叉树。
        平衡二叉树（Balanced Binary Tree），具有以下性质：
            1. 它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，
            2. 并且左右两个子树都是一棵平衡二叉树。
    思路：
        根据JZ_38:TreeDepth = max(LeftSubTreeDepth, RightSubTreeDepth) + 1。
*/

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == nullptr)
            return true;
        return abs(TreeDepth(pRoot->left) - TreeDepth(pRoot->right)) <= 1 
               && IsBalanced_Solution(pRoot->left) 
               && IsBalanced_Solution(pRoot->right);
    }
private:
    int TreeDepth(TreeNode* pRoot) {
    if(pRoot == nullptr)
        return 0;
    return max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
    }
};