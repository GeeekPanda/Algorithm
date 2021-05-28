/*
    题目：
        输入一颗二叉树的根节点和一个整数，按字典序打印出二叉树中结点值的和为输入整数的所有路径。
        路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
    思路：

*/
class Solution{
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root == nullptr)
            return listAll;
        list.push_back(root->val);
        expectNumber -= root->val;
        if(expectNumber == 0 && root->left == nullptr && root->right == nullptr)
            listAll.push_back(list);
        FindPath(root->left, expectNumber);
        FindPath(root->right, expectNumber);
        list.pop_back();
        return listAll;
    }
private:
    vector<vector<int> > listAll;
    vector<int> list;
};