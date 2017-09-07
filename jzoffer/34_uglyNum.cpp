class Solution {
public://判断一个数字是不是丑数，他的因子只有2,3,5
    /*bool isUglyNumber(int n){
		
		while(n>=2 && n%2==0)n/=2;
		while(n>=3 && n%3==0)n/=3;
		while(n>=5 && n%5==0)n/=5;
		
		return n==1;
	}
    
    int GetUglyNumber_Solution(int index) {
        if(index<=0)
            return 0;
        
        int num = 0;
        int i=0;
        while(i<index){
            ++num;
            if(isUglyNumber(num))//输出第index个丑数，如果直接遍历会超时
                ++i;
        }
        return num;
    }*/
    int GetUglyNumber_Solution(int index) {
        list<int> l1;//采用三个链表分别存放当前能被2，3,5整除的数，
        list<int> l2;
        list<int> l3;
        l1.push_back(1);
        l2.push_back(1);
        l3.push_back(1);
        int u=0;
        
        for(int i=0;i<index;i++){//每次将三个链表中最小的数输出即为一个丑数，注意要去除重复的数
            u=l1.front() >l2.front()?l2.front():l1.front();
            u=u>l3.front()?l3.front():u;//最小的数给u,并删除当前链表中已有的u
            if(l1.front()==u)
                l1.erase(l1.begin());
            if(l2.front()==u)
                l2.erase(l2.begin());
            if(l3.front()==u)
                l3.erase(l3.begin());
            l1.push_back(u*2);//依次输入倍数
            l2.push_back(u*3);
            l3.push_back(u*5);
        }
        
        return u;
    }
};