class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> maxWindow;
        if(num.size()>=size && size>=1){
            deque<int> index;
            
            for(int i=0;i<size;++i){
                while(!index.empty() && num[i]>=num[index.back()])
                    index.pop_back();
                index.push_back(i);
            }
            
            for(int i=size;i<num.size();++i){
                maxWindow.push_back(num[index.front()]);
                
                while(!index.empty() && num[i]>=num[index.back()])
                    index.pop_back();
                
                while(!index.empty() && index.front()<=i-size)
                    index.pop_front();
                
                index.push_back(i);
            }
            maxWindow.push_back(num[index.front()]);
        }
        return maxWindow;
    }
};