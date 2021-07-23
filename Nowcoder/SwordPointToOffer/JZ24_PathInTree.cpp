/*
    题目：
        输入一颗二叉树的根节点和一个整数，按字典序打印出二叉树中结点值的和为输入整数的所有路径。
        路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
    思路：
        递归回溯的解法:
        按照前序方式去遍历（根，左，右）
        递归处理：
            1. 忽略空节点
            2. 递归过程中去修改sum的结果，一旦发现等于0同时是根节点则返回结果
            3. 回溯就是每次先插入当前节点，递归完成后删除
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