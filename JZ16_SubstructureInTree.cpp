/*
    题目：
        输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
    思路：
        分两步完成：1. 在A中找到和B的根节点值相等的节点R；
                   2. 判断A中以R为根节点的子树是否包含和B一样的结构。
*/



bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
    bool result = false;

    if(pRoot1 && pRoot2){
        if(pRoot1->val == pRoot2->val)
            result = DoesTree1HaveTree2(pRoot1, pRoot2);
        if(!result)
            result = HasSubtree(pRoot1->left, pRoot2);
        if(!result)
            result = HasSubtree(pRoot1->right, pRoot2);
    }

    return result;
}

bool DoesTree1HaveTree2(TreeNode* pRoot1, TreeNode* pRoot2){
    if(!pRoot2)
        return true;
    if(!pRoot1)
        return false;
    if(pRoot1->val != pRoot2->val)
        return false;
    return DoesTree1HaveTree2(pRoot1->left, pRoot2->left) && DoesTree1HaveTree2(pRoot1->right, pRoot2->right);
}
