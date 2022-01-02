#ifndef  probablility_h
#define  probablility_h
#include<iostream>
    template<typename T>
    float appearanceTimeNumber(T arrayToSearchIn[],T element,int size) {
        float times = 0;
        for (int i = 0; i < size; i++)
        {
            if (arrayToSearchIn[i]==element)
            {
                times++;
            }
        }
        return times;
    }
    template<typename T,size_t n>
    float probablilityX(T (&SampleSpace)[n],T numberToFindProbabilityFor) {
        int size = sizeof(SampleSpace)/sizeof(int);
        return (appearanceTimeNumber(SampleSpace,numberToFindProbabilityFor,size)/size);
    }
#endif