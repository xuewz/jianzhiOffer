class Solution {
public://顺时针打印矩阵
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int i,j;
        int l=0,t=0,r=col-1,b=row-1;
        vector<int> ans;
        
        if(col==0 || row==0)
            return ans;
        
        while(l<=r && t<=b){//这句一定要有等于，不然会报错
            for(i=l;i<=r;++i)
                ans.push_back(matrix[t][i]);
            for(i=t+1;i<=b;++i)
                ans.push_back(matrix[i][r]);
            
            if(t!=b)
                for(i=r-1;i>=l;i--)
                    ans.push_back(matrix[b][i]);
            
            if(l!=r)
                for(i=b-1;i>t;i--)
                    ans.push_back(matrix[i][l]);
            l++,r--;
            t++,b--;
        }
        return ans;
    }
};

class Solution {
public:
   
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;        
        if(matrix.empty())
            return ans;
        int row=matrix.size();
        int col=matrix[0].size();
        int i,j;
        int l=0,t=0,r=col-1,b=row-1;

        
        
        while(l<=r && t<=b){//这句一定要有等于，不然会报错
            for(i=l;i<=r;++i)//从左到右
                ans.push_back(matrix[t][i]);
            for(i=t+1;i<=b;++i)//从上到下
                ans.push_back(matrix[i][r]);
            
            if(t!=b)//如果不是只有一行
                for(i=r-1;i>=l;i--)
                    ans.push_back(matrix[b][i]);
            
            if(l!=r)//如果不是只有一列
                for(i=b-1;i>t;i--)
                    ans.push_back(matrix[i][l]);
            l++,r--;//左边加，右边减
            t++,b--;//上边加，下边减
        }
        return ans;
    }
};