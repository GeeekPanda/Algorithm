/*
    题目：
        输入一棵二叉树，求该树的深度。
        从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
    思路：
        考虑递归。
        求树的深度，相当于求树的左右子树的深度，取二者最大值，再加1（根节点），即得树的深度。
        即 TreeDepth = max(LeftSubTreeDepth, RightSubTreeDepth) + 1;
*/


int TreeDepth(TreeNode* pRoot) {
    if(pRoot == nullptr)
        return 0;
    return max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
}
