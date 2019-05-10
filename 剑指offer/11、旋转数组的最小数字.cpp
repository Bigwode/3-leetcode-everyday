class Solution {
public:
    int findArray(vector<int>& rotateArray, int p1, int p2)  // 顺序查找数组区间内的最小值。
    {
        int result = rotateArray[p1];
        for(int i=p1+1; i<=p2; i++)
        {
            if(rotateArray[i] < result)
                result = rotateArray[i];
        }
        return result;
    }
    
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        int len = rotateArray.size();
        if(len==0) return 0;
        if(len==1) return rotateArray[0];
        
        int p1 = 0;
        int p2 = len-1;
        int mid = p1;  //这样如果第一个元素小于最后一个元素的话，就是未旋转的情况。
        
        while(rotateArray[p1] >= rotateArray[p2])
        {
            if(p2-p1 == 1)  // 当两个指针距离是1的时候，说明前一个指针指向的是大数部分的末尾，后一个是小数的开头
            {
                mid = p2;
                break;
            }
            mid = p1+(p2-p1)/2;
            
            if(rotateArray[p1] == rotateArray[mid] && rotateArray[mid] == rotateArray[p2])
                return findArray(rotateArray, p1, p2);
            if(rotateArray[p1] <= rotateArray[mid])  // 
                p1 = mid;
            if(rotateArray[p2] >= rotateArray[mid])  // 
                p2 = mid;
        }
        return rotateArray[mid];
    }
};
