//在排序数组中找到给定数字出现的次数
class Solution {
public:
    int BinarySearch(vector<int> a, int k, bool isLeft){
        int begin=0;
        int end=a.size()-1;
 //利用二分查找，找的的时候设置一个下标，看是左边还是右边，返回两边的下标，然后相减+1即为次数，注意最后要判断找不到元素时候返回0的情况
        int last=-1;
        while(begin<=end){
            int mid=(begin+end)/2;
            if(a[mid]>k)
                end=mid-1;
            else if(a[mid]<k)
                begin=mid+1;
            else{
                last=mid;//这里的思想很巧妙
                if(isLeft)
                    end=mid-1;
                else
                    begin=mid+1;
            }   
        }
        return last;
    }
    int GetNumberOfK(vector<int> data ,int k) {
        int begin=BinarySearch(data,k,true);
        int end=BinarySearch(data,k,false);
        return (begin==-1 && end==-1)?0:end-begin+1;
    }
};


class Solution {
public:
    int GetFirstK(vector<int> data,int k,int begin,int end){
        if(begin>end)
            return -1;
        
        int mid=(end+begin)>>1;
        int midK=data[mid];
        
        if(midK==k){
            if(mid==0||data[mid-1]!=k&&mid>0)
                return mid;
            else 
                end=mid-1;
        }
        else if(midK>k)
            end=mid-1;
        else
            begin=mid+1;
        
        return GetFirstK(data,k,begin,end);
    }
    
    int GetLastK(vector<int> data,int k,int begin,int end){
        if(begin>end)
            return -1;
        
        int mid=(end+begin)>>1;
        int midK=data[mid];
        
        if(midK==k){
            if(mid==data.size()-1||data[mid+1]!=k&&mid<data.size()-1)
                return mid;
            else 
                begin=mid+1;
        }
        else if(midK>k)
            end=mid-1;
        else
            begin=mid+1;
        
        return GetLastK(data,k,begin,end);
    }
    int GetNumberOfK(vector<int> data ,int k) {
        int ans=0;
        int first=GetFirstK(data,k,0,data.size()-1);
        int last=GetLastK(data,k,0,data.size()-1);
        if(first>-1 && last>-1)
        	return last-first+1;
        return ans;
    }
};