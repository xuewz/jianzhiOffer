class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(numbers==NULL || length<=0)
            return false;
        
        for(int i=0;i<length;++i){
            while(numbers[i]!=i){
                if(numbers[i]==numbers[numbers[i]]){//判断当前数字是否已经重复
                *duplication=numbers[i];
                return true;
                }
                swap(numbers[i],numbers[numbers[i]]);//不重复的话交换数字
            }
        }
        return false;
    }
};
//在数组长度为n的数组里面包含0-n-1的数字，找到重复的数字