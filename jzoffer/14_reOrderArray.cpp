class Solution {
public://重排序数组，使得奇数在前，偶数在后。
    void reOrderArray(vector<int> &array) {
       vector<int> a1;
       vector<int> a2;//两个数组分别放奇数和偶数
       for(size_t i=0;i<array.size();++i){
           if(array[i]&1==1)
               a1.push_back(array[i]);//奇数
           else
               a2.push_back(array[i]);//偶数
       }
        array.clear();
        
        for(size_t j=0;j<a1.size();++j){
            array.push_back(a1[j]);
        }
        a1.clear();
        for(size_t k=0;k<a2.size();++k){
            array.push_back(a2[k]);//再将两个数组都放到array里面
        }
        a2.clear();
    }
};

//或者从头和尾开始交换奇数和偶数
void reOrderArray(vector<int> &a){
	if(a.empty())
		return;
	
	int i=0;
	int j=a.size()-1;
	while(i<j){
		while(i<j&&(a[i]&0x1)!=0){
			i++;
		}
		
		while(i<j && (a[i]&0x1==0)
			j--;
		
		if(i<j)
			swap(a[i],a[j]);
	}
	
}