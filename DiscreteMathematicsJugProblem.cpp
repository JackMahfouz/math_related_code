#include <iostream>

struct container
{
    int capacity;
    int value ;
};

void setCapacity(container& cont, int capacity) {
    cont.capacity=capacity;
}

void FillContainer(container& cont) {
    cont.value = cont.capacity;
}

void EmptyContainer(container& cont) {
    cont.value = 0;
}

bool isFull(container& cont) {
    return cont.value >= cont.capacity;
}

bool isEmpty(container& cont) {
    return cont.value == 0;
}

void fromBtoA(container& contA, container& contB){
    int temp = contA.value;
    contA.value += contB.value;
    contA.value = (contA.value > contA.capacity)?contA.capacity:contA.value;
    contB.value -= (contA.value-temp);
}

int greatCommonDivisorForAandB(int a,int b)
{ 
	if(b<=a && a%b == 0)
		return b;
	if(a < b)
		return greatCommonDivisorForAandB(b,a);
	else
		return greatCommonDivisorForAandB(b,a%b);
}

bool check(int a, int b, int c) {
    if(c>a) {
        std::cout<<"A cant hold value more than it,s capacity."<<std::endl;
        return false;
    }
    else if(c % greatCommonDivisorForAandB(a,b) == 0) {
        return true;
    }
    else {
        std::cout<<"unreachable state for Jack's Machine :( "<<std::endl;
        return false;
    }
}

void soultionStateMachine(container A,container B, int wantedValue) {
    while (A.value != wantedValue)
    {
        if(!isFull(A) && isEmpty(B)) {
            std::cout<<"Fill Container B"<<std::endl;
            FillContainer(B);
            std::cout<<"(A, B) = ("<<A.value<<", "<<B.value<<")"<<std::endl;
        }
        else if(isFull(A)) {
            std::cout<<"Empty Container A"<<std::endl;
            EmptyContainer(A);
            std::cout<<"(A, B) = ("<<A.value<<", "<<B.value<<")"<<std::endl;
        }
        else {
            std::cout<<"Pour from B to A"<<std::endl;
            fromBtoA(A, B);
            std::cout<<"(A, B) = ("<<A.value<<", "<<B.value<<")"<<std::endl;
        }

    }
    
}
void finite() {
    int a, b, c;
    std::cout<<"Enter capacity of First Container:"; std::cin>>a;
    std::cout<<"Enter capacity of Second Container :"; std::cin>>b;

    do {
        std::cout<<"Enter capacity of Wanted Value :"; std::cin>>c;
    } while(!check(a,b,c));
    container A,B;
    A.capacity = a;
    B.capacity = b;
    A.value = 0;
    B.value = 0;
    std::cout<<"\nFirst State (A, B) = ("<<A.value<<", "<<B.value<<")"<<std::endl;    
    soultionStateMachine(A,B,c);
    std::cout<<"Finite"<<std::endl;
}
int main() {
    char answer;
    do{
        finite();
        std::cout<<"play again ? type Y/y : "; std::cin>>answer;
    } while(answer=='Y'||answer=='y');
    system("pause");
}