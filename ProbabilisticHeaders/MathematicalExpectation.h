#ifndef MathematicalExpectation_h
#define MathematicalExpectation_h
#include "probabilityOfX.h"
float ex = 0;
template<typename T,size_t n>
void primeExpectation(T (&SampleSpace)[n],int Size) {
   
   Size--;
   if(Size >= 0){
    ex += SampleSpace[Size]*probablilityX(SampleSpace,SampleSpace[Size]);
    primeExpectation(SampleSpace,Size);
   }
}
template<typename T,size_t n>
int arraySize(T (&SampleSpace)[n]) {
    return sizeof(SampleSpace)/sizeof(int);
}
template<typename T,size_t n>
float finalExpectation(T (&SampleSpace)[n]) {
    primeExpectation(SampleSpace, arraySize(SampleSpace));
    return ex;
}
#endif