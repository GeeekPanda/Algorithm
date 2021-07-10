/*
    题目：
        输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
        要求不能创建任何新的结点，只能调整树中结点指针的指向。
    思路：
        BST的中序遍历序列是递增序列。
*/

TreeNode* Convert(TreeNode* pRootOfTree){
    if(pRootOfTree == nullptr)
        return nullptr;
    std::vector<TreeNode*> inorder;
    GetInorder(inorder, pRootOfTree);
    const int size = inorder.size();
    for(int i = 0; i < size-1; ++i)
        inorder[i]->right = inorder[i+1];
    for(int i = size-1; i > 0; --i)
        inorder[i]->left = inorder[i-1];
    return inorder[0];
}

void GetInorder(std::vector<TreeNode*> &inorder, TreeNode* pRootOfTree){
    if(pRootOfTree == nullptr)
        return;
    GetInorder(inorder, pRootOfTree->left);
    inorder.push_back(pRootOfTree);
    GetInorder(inorder, pRootOfTree->right);
}