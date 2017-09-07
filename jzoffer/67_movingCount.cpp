class Solution {
public:
    int getDigitSum(int number){
        int sum=0;
        while(number){
            sum+=number%10;
            number/=10;
        }
        
        return sum;
    }
    
    int movingCore(int threshold,int rows,int cols,int row,int col,bool* visited){
        int c=0;
        
        //check(threshold,rows,cols,row,col,visited)
        if(col<cols && col>=0 && row<rows && row>=0 && !visited[row*cols+col] && getDigitSum(row)+getDigitSum(col)<=threshold){
            visited[row*cols+col]=true;
            
            c=1+movingCore(threshold,rows,cols,row-1,col,visited)+movingCore(threshold,rows,cols,row,col-1,visited)
                +movingCore(threshold,rows,cols,row+1,col,visited)+movingCore(threshold,rows,cols,row,col+1,visited);
        }
        
        return c;
    }
    
    int movingCount(int threshold, int rows, int cols)
    {
        bool* visited=new bool[rows*cols];
        
        for(int i=0;i<rows*cols;++i)
            visited[i]=false;
        
        int c=movingCore(threshold,rows,cols,0,0,visited);
        
        delete []visited;
        return c;
    }
};