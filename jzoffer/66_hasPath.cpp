class Solution {
public:
    bool hasPathCore(char* matrix,int rows,int cols,int row,int col,char* str,int pathLen,bool *visited){
        if(str[pathLen]=='\0')
            return true;
        
        bool hasPath=false;
        if(row<rows && col<cols && col>=0 && row>=0 && matrix[row*cols+col]==str[pathLen] && !visited[row*cols+col]){
            pathLen++;
            visited[row*cols+col]=true;
            
            hasPath=hasPathCore(matrix,rows,cols,row-1,col,str,pathLen,visited)
                ||hasPathCore(matrix,rows,cols,row,col-1,str,pathLen,visited)
                ||hasPathCore(matrix,rows,cols,row+1,col,str,pathLen,visited)
                ||hasPathCore(matrix,rows,cols,row,col+1,str,pathLen,visited);
            
            if(!hasPath){
                pathLen--;
                visited[row*cols+col]=false;
            }
        }
            
        return hasPath;
    }
    
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix==NULL || rows<1 || cols<1 || str==NULL)
            return false;
        
        bool *visited= new bool[rows*cols];
        memset(visited,0,rows*cols);
        
        int pathLen=0;
        for(int row=0;row<rows;++row){
            for(int col=0;col<cols;col++){
                if(hasPathCore(matrix,rows,cols,row,col,str,pathLen,visited))
                    return true;
            }
        }
        
        delete []visited;
        return false;
    }


};