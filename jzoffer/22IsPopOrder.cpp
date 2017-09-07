class Solution {//12345,45321是，43512不是
public://判断序列是不是栈的输出序列采用一个辅助栈，
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int i=0,j=0;
        stack<int> temp;//用一个辅助栈模拟入栈操作，存放当前没有匹配的元素
        if(pushV.empty() || popV.empty())
            return false;
        
        while(j<popV.size()){
            while(temp.empty() || temp.top()!=popV[j]){
                if(i==pushV.size())
                    break;
                
                temp.push(pushV[i]);
                i++;
            }
            
            if(temp.top()!=popV[j])
                break;
            
            temp.pop();
            j++;
        }
        
        if(temp.empty() && j==popV.size())
            return true;
        
        return false;
    }
};