/*
    题目：
        操作给定的二叉树，将其变换为源二叉树的镜像。
    思路：
        先前序遍历树的每个节点，若遍历到的节点存在子节点，则交换其左右子节点。
        当交换完所有非叶子节点的左右子节点后，就得到了整棵树的镜像。
        这是一个递归过程。
*/
TreeNode* Mirror(TreeNode* pRoot){
    if(pRoot == nullptr)
        return nullptr;
    if(!pRoot->left && !pRoot->right)
        return pRoot;
    TreeNode* pTemp = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = pTemp;

    if(pRoot->left)
        Mirror(pRoot->left);
    if(pRoot->right)
        Mirror(pRoot->right);
}