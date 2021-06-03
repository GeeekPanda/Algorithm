/*
    题目：
        给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
        不能使用除法。（注意：规定B[0] = A[1] * A[2] * ... * A[n-1]，B[n-1] = A[0] * A[1] * ... * A[n-2];）
        对于A长度为1的情况，B无意义，故而无法构建，因此该情况不会存在。
    思路：

*/

vector<int> multiply(const vector<int>& A){
    const int size = A.size();
    if(size == 0)
        return {};
    vector<int> B(size);
    B[0] = 1;
    int temp = 1;
    for(int i = 1; i < size; ++i)
        B[i] = B[i-1] * A[i-1];
    for(int i = size-2; i >= 0; --i){
        temp *= A[i+1];
        B[i] *= temp;
    }
    return B;
}