class Solution {
public://模拟约瑟夫环的链表，从头到尾删除节点并返回最后一个
    int LastRemaining_Solution(int n, int m)
    {
        if(n<1 || m<1)
            return -1;
        
        int i=0;
        list<int> li;
        for(i=0;i<n;++i){//将n个数存入链表
            li.push_back(i);
        }
        
        auto it=li.begin();
        while(li.size()>1){//链表中元素个数大于1时
            for(i=1;i<m;++i){//找到第m个
                it++;
                if(it==li.end())//如果第m个到末尾，则移动到开始
                    it=li.begin();
            }
            
            //记录删除的下一个位置，为了保证删除当前元素之后下一个元素存在
            auto next= ++it;
            if(next==li.end())//如果下一个是末尾，则直接让下一个指向开头
                next=li.begin();
            
            it--;
            li.erase(it);//删除当前元素，并移动到下一个
            it=next;
        }
        
        return *(it);
    }
};

//用函数映射方式的到递归公式
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n<1 || m<1)
            return -1;
        
        int last=0;
        for(int i=2;i<=n;++i){
            last=(last+m)%i;
        }
        
        return last;
    }
};