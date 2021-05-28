/*
    题目：
        输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则返回true,否则返回false。
        假设输入的数组的任意两个数字都互不相同。（ps：我们约定空树不是二叉搜素树）
    补充知识：
        二叉搜索树，也叫二叉排序树、二叉查找树。Binary Search Tree。
        根节点的值大于其左子树中任意一个节点的值，小于其右节点中任意一节点的值，这一规则适用于二叉查找树中的每一个节点。
    思路：
        以[4,8,6,12,16,14,10]为例，10为根节点的值，左子树的节点值均小于10，右子树的节点均大于10，所以[4,8,6]是左子树，
        [12,16,14]是右子树。对于左右子树又有同样的规则，所以是一个递归的过程。
*/
bool VerifySquenceOfBST(vector<int> sequence){
    const int size = sequence.size();
    if(size == 0)
        return false;
    return recur(sequence, 0, size-1);
}

bool recur(vector<int> sequence, int start, int end){
    if(start >= end)
        return true;
    /*
     *因为数组中最后一个值sequence[end]是根节点，这里从左往右找出第一个比
     *根节点大的值，他后面的都是根节点的右子节点（包含当前值，不包含最后一个值，
     *因为最后一个是根节点），他前面的都是根节点的左子节点
     */
    int boundary = start;
    int root = sequence[end];
    while(sequence[boundary] < sequence[end])
        ++boundary;
    int temp = boundary;
    /*
     *因为sequence[boundary]前面的值都是比根节点root小的，
     *我们还需要确定sequence[boundary]后面的值都要比根节点root大，
     *如果后面有比根节点小的直接返回false
     */
    while(temp < end){
        if(sequence[temp++] < root)
            return false;
    }

    return recur(sequence, start, boundary-1) && recur(sequence, boundary, end-1); 
}