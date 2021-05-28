/*
    题目：
        从上往下打印出二叉树的每个节点，同层节点从左至右打印。
    思路：
        考虑用队列。
*/

std::vector<int> PrintFromTopToBottom(TreeNode* root){
    std::deque<TreeNode*> deq;
    std::vector<int> result;
    if(root == nullptr)
        return result;
    deq.push_back(root);
    while(!deq.empty()){
        TreeNode* curNode = deq.front();
        deq.pop_front();
        result.push_back(curNode->val);
        if(curNode->left)
            deq.push_back(curNode->left);
        if(curNode->right)
            deq.push_back(curNode->right);
    }
    return result;
}