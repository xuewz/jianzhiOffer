class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty())
            return 0;
        
        int ans=numbers[0];
        int times=1;
        for(int i=1;i<numbers.size();++i){
            if(times==0)
                {
                ans=numbers[i];
                times=1;
            }
            else if(numbers[i]==ans)
                times++;
            else
                times--;
               
        }
        
        times=0;
        for(int j=0;j<numbers.size();++j){
            if(numbers[j]==ans)
                times++;
        }
        if(times*2<=numbers.size())
            return 0;
        
        return ans;
    }
};