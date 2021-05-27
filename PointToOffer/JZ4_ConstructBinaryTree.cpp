/*
    思路：
        根据前序遍历序列和中序遍历序列构造二叉树。以下为例：
        前序遍历：1 2 3 4 5 6 7
        中序遍历：3 2 4 1 6 5 7
        前序遍历的顺序是“根-左-右”，中序遍历的顺序是“左-根-右”。
        那么：
            1. 前序遍历序列的第一个值就是根节点的值，即 1；
            2. 前序遍历序列中1后边的就是左子树和右子树的节点值，只是目前无法知道左右子树的分界点在哪里；
            3. 在中序遍历中找到1这个值，那么左边的就是左子树的节点值，右边的就是右子树的值；
            4. 在中序遍历序列中，1的左边有三个值，说明左子树有三个节点；1右边有三个值，说明右子树有三个节点；
            5. 根据左右子树节点的个数，可以在前序遍历序列中判断出左右子树的分界点；
            6. 前序遍历序列中234是左子树的节点值，567是右子树的节点值；
            7. 现在相当于知道了根节点1，左子树前序遍历序列：234，左子树中序遍历序列：324；
                                      右子树前序遍历序列：567，右子树中序遍历序列：657；
            8. 接下来以递归的方法构造左子树和右子树。
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution{
public:
    TreeNode* constructBinaryTree(std::vector<int> pre, std::vector<int> vin){
        const int treeSize = pre.size();
        for(int i = 0; i < treeSize; ++i)
            location.insert(pair<int, int>(vin[i], i));
        return rebuild(pre, vin, 0, treeSize-1, 0, treeSize-1);
    }
private:
    std::unordered_map<int, int> location;
    TreeNode* rebuild(std::vector<int> pre, std::vector<int> vin, int preLeft, int preRight, int vinLeft, int vinRight){
        if(preLeft > preRight)
            return nullptr;
        int preRoot = preLeft;
        int vinRoot = location[pre[preRoot]];
        //构造根节点
        TreeNode* root = new TreeNode(pre[preRoot]);
        //得到左子树的节点个数
        int sizeOfSubLeft = vinRoot - vinLeft;
        //递归地构造左子树
        root->left = rebuild(pre, vin, preLeft+1, preLeft+sizeOfSubLeft, vinLeft, vinRoot-1);
        //递归地构造右子树
        root->right = rebuild(pre, vin, preLeft+sizeOfSubLeft+1, preRight, vinRoot+1, vinRight);
        return root;
    }
};
