class Solution {
public:
    int myAtoi(string s) {
        int flag=1;
		long long ans = 0;
		int i = 0;
		if (s.empty())return ans;
		while (i < s.size() && s[i] == ' ')
			++i;
		if (s[i] == '+')
		{
		    flag = 1;
		    ++i;
		}
		else if (s[i] == '-')
			{
			    flag = -1;
		        ++i;
			}
		while (i < s.size())
		{
			if (s[i] <= '9' && s[i] >= '0')
				ans = ans * 10 + flag*(s[i] - '0');
			else
				return ans;
			if (ans > INT_MAX || ans < INT_MIN)return (ans>0)?INT_MAX :INT_MIN;
			++i;
		}
		return ans;
    }
};