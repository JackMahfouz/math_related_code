#include <iostream>
int greatCommonDivisorForAandB(int a,int b)
{ 
	if(b<=a && a%b == 0)
		return b;
	if(a < b)
		return greatCommonDivisorForAandB(b,a);
	else
		return greatCommonDivisorForAandB(b,a%b);
}
int main() {
    std::cout<<greatCommonDivisorForAandB(6,2);
    return 0;
}
