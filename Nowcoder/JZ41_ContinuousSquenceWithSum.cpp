/*
    题目：
        小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
        但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
        没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
        现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
    思路：
        滑动窗口（双指针）
        设连续正整数序列的左边界i和右边界j，则可构建滑动窗口从左向右滑动。
        循环中，每轮判断滑动窗口内元素和与目标值target的大小关系：
            1. 若相等则记录结果;
            2. 若大于target则移动左边界i（以减小窗口内的元素和）;
            3. 若小于target则移动右边界j（以增大窗口内的元素和）。
*/

vector<vector<int> > FindContinuousSequence(int sum){
    int left = 1;
    int right = 2;
    int curSum = 3;
    vector<vector<int>> result;
    while(left < right){
        if(curSum == sum){
            vector<int> ans;
            for(int i = left; i <= right; ++i)
                ans.push_back(i);
            result.push_back(ans);
        }
        if(curSum >= sum){
            curSum -= left;
            ++left;
        }
        else{
            ++right;
            curSum += right;
        }
    }
    return result;
}