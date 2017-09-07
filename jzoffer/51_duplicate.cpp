class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        int h[1000]={0};
        for(int i=0;i<length;++i){
            h[numbers[i]]++;
        }
        for(int i=0;i<length;++i){
            if(h[numbers[i]]>1)
            {
                *duplication = numbers[i];
                return true;
            }     
        }
        return false;
    }
};

//优化
bool duplicate(int number[], int len, int* duplication){
	if(number==NULL || len<=0)
		return false;
	
	for(int i=0;i<len;++i){
		while(number[i]!=i){
			if(number[i]==number[number[i]])
			{
				*duplication =number[i];
				return true;
			}
			
			swap(number[i],number[number[i]]);
		}
	}
	return false;
}