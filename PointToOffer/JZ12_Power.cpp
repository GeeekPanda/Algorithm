/*
    题目：
        给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
        保证base和exponent不同时为0。不得使用库函数，同时不需要考虑大数问题，也不用考虑小数点后面0的位数。
    思路：
                 a^(n/2)*a^(n/2) n为偶数
        1. a^n =                                      通过此公式，采用递归可降低计算次数，提高效率；
                 a^((n-1)/2)*a^((n-1)/2) n为奇数
        
        2. 要考虑到a为0同时n为负数的情况，这种情况下对0取倒数是要出错的。
*/

double Power(double base, int exponent){
    if(base == 0)   return 0;
    unsigned int absExponent = (unsigned int)exponent;
    if(exponent < 0)
        absExponent = (unsigned int)(-exponent);
    double result = PowerWithUnsignedExponent(base, absExponent);
    if(exponent < 0)
        result = 1.0/result;
    return result;
}
double PowerWithUnsignedExponent(double base, unsigned int exponent){
    if(exponent == 0)   return 1.0;
    if(exponent == 1)   return base;

    double result = PowerWithUnsignedExponent(base, exponent >> 1);
    result *= result;
    if(exponent & 0x1 == 1) //若exponent为奇数
        result *= base;
    return result;
}