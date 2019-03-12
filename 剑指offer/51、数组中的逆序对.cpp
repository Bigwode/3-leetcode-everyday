class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.size()<=1) return 0;//如果少于等于1个元素，直接返回0
        int* copy=new int[data.size()];
        //初始化该数组，该数组作为存放临时排序的结果，最后要将排序的结果复制到原数组中
        for(unsigned int i=0;i<data.size();i++)
            copy[i]=0;
        //调用递归函数求解结果
        int count=InversePairCore(data,copy,0,data.size()-1);
        delete[] copy;//删除临时数组
        return count;
    }
    //程序的主体函数
    int InversePairCore(vector<int>& data,int* copy,int start,int end)
    {
        if(start==end)
        {
            copy[start]=data[start];
            return 0;
        }
        //将数组拆分成两部分
        int length=(end-start)/2;//这里使用的下标法，下面要用来计算逆序个数；也可以直接使用mid=（start+end）/2
        //分别计算左边部分和右边部分
        int left=InversePairCore(data,copy,start,start+length)%1000000007;
        int right=InversePairCore(data,copy,start+length+1,end)%1000000007;
        //进行逆序计算
        int i=start+length;//前一个数组的最后一个下标
        int j=end;//后一个数组的下标
        int index=end;//辅助数组下标，从最后一个算起
        int count=0;
        while(i>=start && j>=start+length+1)
        {
            if(data[i]>data[j])
            {
                copy[index--]=data[i--];
                //统计长度
                count+=j-start-length;
                if(count>=1000000007)//数值过大求余
                    count%=1000000007;
            }
            else
            {
                copy[index--]=data[j--];
            }
        }

        for(;i>=start;--i)
        {
            copy[index--]=data[i];
        }
        for(;j>=start+length+1;--j)
        {
            copy[index--]=data[j];
        }
        // 排序
        for(int i=start; i<=end; i++) {
            data[i] = copy[i];
        }
        //返回最终的结果
        return (count+left+right)%1000000007;
    }
};
