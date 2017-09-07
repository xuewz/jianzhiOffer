class Solution {
public:
    void Insert(int num)
    {
        if(((min.size()+max.size())&1) == 0)
            {
            if(max.size()>0 && num<max[0]){
                max.push_back(num);
                push_heap(max.begin(),max.end(),less<int>());
                
                num=max[0];
                
                pop_heap(max.begin(),max.end(),less<int>());
                max.pop_back();
            }
            
            min.push_back(num);
            push_heap(min.begin(),min.end(),greater<int>());
        }
        else{
            if(min.size()>0 && num>min[0]){
                min.push_back(num);
                push_heap(min.begin(),min.end(),greater<int>());
                
                num=min[0];
                
                pop_heap(min.begin(),min.end(),greater<int>());
                min.pop_back();
            }
            
            max.push_back(num);
            push_heap(max.begin(),max.end(),less<int>());
        }
          
    }

    double GetMedian()
    { 
        int size=min.size()+max.size();
        if(size==0)
           return 0;// throw exception("No numbers are available");
        
        double median=0;
        if((size&1)==1)
            median=min[0];
        else
            median=(double(min[0])+max[0])/2;
        
        return median;
                                  
        
    }

    private:
    vector<int> min;
    vector<int> max;

};
/*******************************************************/
typedef multiset<int,greater<int>> maxSet;
typedef multiset<int,less<int>> minSet;

class Solution {
public:
    void Insert(int num)
    {
        if(((min.size()+max.size())&0x1)==0){
            if(max.size()>0 && num < *(max.begin())){
                max.insert(num);
                
                num=*(max.begin());
                
                max.erase(max.begin());
            }
            min.insert(num);
        }
        else{
            if(min.size()>0 && num>*(min.begin())){
                min.insert(num);
                
                num=*(min.begin());
                
                min.erase(min.begin());
            }
            max.insert(num);
        }
    }

    double GetMedian()
    { 
     	int size=min.size()+max.size();
        
        if(size==0)
            return 0;
        
        double median=0;
        if((size&0x1)==1)
            median=*(min.begin());
        else
            median=(double(*(max.begin()))+*(min.begin()))/2;
        
        return median;
    }
    private:
    maxSet max;
    minSet min;

};