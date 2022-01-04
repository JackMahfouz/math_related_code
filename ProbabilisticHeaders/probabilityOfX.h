#ifndef  probablility_h
#define  probablility_h
    
    template<typename T>
    float appearanceTimeNumber(T arrayToSearchIn[],T element,int size) {
        float times = 0;
        size--;
        if(arrayToSearchIn[size]==element)
        times++;
        if(size==0){  
            return times;
        }
        return (times + appearanceTimeNumber(arrayToSearchIn,element,size));
    }
    template<typename T,size_t n>
    float probablilityX(T (&SampleSpace)[n],T numberToFindProbabilityFor) {
        int size = sizeof(SampleSpace)/sizeof(int);
        return (appearanceTimeNumber(SampleSpace,numberToFindProbabilityFor,size)/size);
    }
#endif