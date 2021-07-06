#include <iostream>

int Add(const int a, const int b){
    return a + b;
}

int main(){
    int A = 0;
    int B = 0;
    std::cin >> A >> B;
    std::cout << Add(A, B) << std::endl;
    return 0;
}