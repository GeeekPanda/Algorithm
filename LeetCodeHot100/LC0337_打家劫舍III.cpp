/*
    题目：
        小偷发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。
        除了“根”之外，每栋房子有且只有一个“父“房子与之相连。
        一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。
        如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
        计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。
    思路：
        动态规划
        简化一下这个问题：一棵二叉树，树上的每个点都有对应的权值，每个点有两种状态（选中和不选中），
        问在不能同时选中有父子关系的点的情况下，能选中的点的最大权值和是多少。

*/

class Solution {
public:
    int rob(TreeNode* root) {
        
    }
private:
    std::unordered_map<TreeNode*, int> selected;
    std::unordered_map<TreeNode*, int> unselected;
    
    void dfs(TreeNode* node){
        if(!node){
            return;
        }
        dfs(node->left);
        dfs(node->right);
        selected[node] = node->val + 
    }
};