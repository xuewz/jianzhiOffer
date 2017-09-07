class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        /*int sum=0;
        for(int i=1;i<=n;++i){
            while(i){
                int j=i;
                if(i%10==1)
                    sum++;
                i/=10;
            }
        }
        return sum;*/
		/*
		a=n/100;b=n%100;
		假设百位>=2,如31256，共(a/10+1)*100
		百位==1，如31156，公有(a/10)*100+(b+1)
		百位==0，如31056，公有(a/10)*100
		*/
        int ans=0;
        for(int i=1;i<=n;i*=10){
            int a=n/i;
            int b=n%i;
            ans+=(a+8)/10*i+(a%10==1)*(b+1);
        }
        return ans;
    }
};