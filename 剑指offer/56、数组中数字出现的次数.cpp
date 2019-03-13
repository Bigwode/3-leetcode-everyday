class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) 
    {
        int len = data.size();
        int xOr = 0;
        for(int i=0; i<len; i++)
        {
            xOr ^= data[i];
        }
        int index = idofRight1(xOr);  // 异或结果最右侧为1的位数
        *num1 = 0;
        *num2 = 0;
        for(int j=0; j<len; j++)
        {
            if(isright1(data[j], index))  // 判断一个数的倒数第多少位是不是为1
                *num1 ^= data[j];
            else
                *num2 ^= data[j];
        }

    }
    
    int idofRight1(int xOr)
    {
        int index = 0;
        while((xOr & 1) == 0)
        {
            xOr = xOr >> 1;
            index++;
        }
        return index;
    }
    
    bool isright1(int number, int index)
    {
        number = number >> index;
        return (number & 1);
    }
};
