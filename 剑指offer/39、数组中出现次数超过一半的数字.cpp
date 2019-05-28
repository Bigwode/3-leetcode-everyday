class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if(numbers.size() == 0)
        return 0;
        int res = numbers[0];
        int count = 1;
        for(int i=1; i<numbers.size(); i++)
        {
            if(count == 0)
            {
                res = numbers[i];
                count = 1;
            }
            if(numbers[i] == res)
                count += 1;
            else
                count -= 1;
        }
        int num = 0;
        for(int j=0; j<numbers.size(); j++)  //　注意判断这个数字出现的次数是否超过数组长度的一半。
        {
            if(numbers[j] == res)
                ++num;
        }
        if(num > numbers.size()/2)
            return res;
        else
            return 0;
    }
};

/*Solution 2:Partition + 中间位置的值（注意，必须要判断中间位置的值是不是出现的次数超过一半）*/
class Solution {
public:
    int Partition(vector<int>& num, int low, int high)
    {
        int dummy = num[low];
        //从最后搬一个小的数过来
        while(low<high)
        {
            while (low<high && num[high]>=dummy)  --high;
            num[low] = num[high];
            // ++low;  //这时候肯定是要满足下边第一次循环的条件的。
            while (low<high && num[low]<=dummy)  ++low;
            num[high] = num[low];
        }
        num[high] = dummy;
        return high;
    }
    
    bool checkMoreThanHalf(vector<int>& numbers, int middle)  //必须检查是否超过一半
    {
        int times = 0;
        int num = numbers[middle];
        int length = numbers.size();
        for (int i=0; i< length; i++)
        {
            if(numbers[i] == num)
                times++;
        }
        if(2*times<=length)
            return false;
        else
            return true;
    }
    
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        int middle = numbers.size()/2;
        int low = 0;
        int high = numbers.size()-1;
        int pivot = Partition(numbers, low, high);
        while(pivot != middle)
        {
            if(pivot < middle)
                pivot = Partition(numbers, pivot+1, high);
            else
                pivot = Partition(numbers, low, pivot-1);
        }
        if (checkMoreThanHalf(numbers, middle))
            return numbers[middle];
        else
            return 0;
    }
};
