class Solution {
public://实现atoi
    int StrToInt(string s) {
        int flag=1;
		long long ans = 0;
		int i = 0;
		if (s.empty())return ans;
        
		while (i < s.size() && s[i] == ' ')
			++i;//首先跳过空格
        
		if (s[i] == '+')
		{
		    flag = 1;//对加减号进行标识
		    ++i;
		}
		else if (s[i] == '-')
			{
			    flag = -1;
		        ++i;
			}
        
		while (i < s.size())//依次对剩下的数字求和
		{
			if (s[i] <= '9' && s[i] >= '0')
				ans = ans * 10 + flag*(s[i] - '0');
			else//如果非数字直接结束
				return 0;
			if (ans > INT_MAX || ans < INT_MIN)return (ans>0)?INT_MAX :INT_MIN;//判断数字和是否越界
			++i;//继续下一位
		}
		return ans;
    }
};