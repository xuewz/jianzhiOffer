#include <iostream>
#include <vector>
//在有序数组中找到给定元素
using namespace std;
//数组中数组元素从左到右递增，从上到下递增，给定一个元素，找出数组中是否存在
    bool Find(int target, vector<vector<int> > array) {
        int cols = array[0].size();
        int rows = array.size();
		
        bool found = false;
        if(!array.empty() && rows>0 && cols>0){//当数组非空时
			//选择右上角数字开始判断是否相等
            int row=0;
            int col=cols-1;
            while(row<rows && col>=0){
                if(array[row][col]==target)//找到目标跳出循环
                    {
                    found =true;
                    break;
                }
                else if(array[row][col]>target){//比目标值大，左移
                    --col;
                }
                else
                    ++row;//比目标值小，下移
            }
        }
        return found;
    }

	//将vector换成指针指向的数组，只是访问数组的下标改变
	bool findPartiallySortedMatrix(int* arr,int rows,int cols,int key)
{
	bool flag = false;
	
	if(arr!=NULL && cols>0 && rows>0)
	{
		int col=cols-1;
		int row = 0;
		while(col>=0 && row<rows)
		{
			if(arr[row*cols+col] == key)
			{
				flag = true;
				break;
			}
			else if(arr[row*cols+col]>key)
				col--;
			else
				row++;
		}
	}
	return flag;
}

//在有序数组中 搜索给定元素，这个是三种中最简洁易懂的
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //if(matrix.empty())
            //return false;
        
        int rows=matrix.size();//注意二维数组的行是直接取size
        if(rows==0)
            return false;//实际上跟上面代码等价，先判断数组是不是空，不是空执行下面
        int cols=matrix[0].size();

        int row=0;
        int col=cols-1;
        

        while(row<rows && col>=0){
            if(matrix[row][col]==target)
                return true;
            else if(matrix[row][col]<target)
                row++;
            else if(matrix[row][col]>target)
                col--;
        }
         
        return false;
    }
int main()
{
	int a[][4]= { { 1, 2, 8, 9 },{2, 4, 9, 12}, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	cout << findPartiallySortedMatrix(*a,4,4,9)<<endl;
	return 0;
}