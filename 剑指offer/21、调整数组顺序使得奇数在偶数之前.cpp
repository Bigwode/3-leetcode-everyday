/*这种是没说要保证相对位置不变的条件*/
class Solution {
public:
    void reOrderArray(vector<int> &array)
    {
        int len = array.size();
        int i = 0, j = len-1;
        while(i<j)
        {
            while(i<j && (array[i]&1)==1) ++i;　　// 奇数后移 
            while(i<j && (array[j]&1)==0) --j;  //　偶数前移
            if(i<j)
            {
                int temp = array[i];　　// 交换前面的偶数和后面的奇数
                array[i] = array[j];
                array[j] = temp;
                ++i;
                --j;
            }
        }
    }
};

/*要保证相对位置不变的条件*/
class Solution {
public:
    void reOrderArray(vector<int> &array)
    {
        int len = array.size();
        vector<int> even;
        vector<int> odd;
        for(int i=0; i<len;i++)
        {
            if((array[i]&0x1) == 1)
                odd.push_back(array[i]);
            else
                even.push_back(array[i]);
        }
        odd.insert(odd.end(),even.begin(),even.end());
        array =odd;
    }
};
