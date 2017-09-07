class Solution {
public://给定一个数组，求将这些数字组合起来形成的最大数字
    static bool com(const string &a, const string &b){
        string str1=a+b;
        string str2=b+a;
        return str1<str2;//连接两个字符串数字，组成比较小的
    }
    string PrintMinNumber(vector<int> numbers) {
        vector<string> strNum;
        string ans;
        int i;
        
        for(i=0;i<numbers.size();++i)
            {
            strNum.push_back(to_string(numbers[i]));//先把数字从转换成字符串
        }
        sort(strNum.begin(),strNum.end(),com);//根据最大的数字排序
        
        for(i=0;i<numbers.size();++i){
            ans+=strNum[i];//最后直接累加输出
        }
        return ans;
    }
};