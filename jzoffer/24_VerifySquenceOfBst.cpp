class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())
            return false;
        
        int len=sequence.size();
        int root=sequence[len-1];
        
        int i=0;
        for(i=0;i<len-1;++i){
            if(sequence[i]>root)
                break;
        }
        
        int j=i;
        for(j=i;j<len-1;++j){
            if(sequence[j]<root)
                return false;
        }
        
        bool left=true;
       vector<int> le;
        if(i>0)
        {
           // vector<int> le(&sequence[0],&sequence[i]);
            le.assign(sequence.begin(),sequence.begin()+i);
            left=VerifySquenceOfBST(le);
        }
        
        bool right=true;
        vector<int> ri;
        if(i<len-1)
        {
             //vector<int> ri(&sequence[i],&sequence[len-1]);
            ri.assign(sequence.begin()+i,sequence.end()-1);
            right=VerifySquenceOfBST(ri);
        }
            
        return left&&right;
    }
};