/*
思路：
（1）先判断输入是否满足条件，即，输入的数组是不是空指针；数组的长度是不是小于0；数组中的数字是不是在规定范围内。
（2）循环遍历数组，如果当前值和当前坐标不同：先判断当前值和以当前值为坐标的位置上的值是不是相等，如果相等，就说明是重复的数字。
否则，交换当前值和以当前值为坐标的数值。
*/

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) 
    {
        if(numbers== nullptr || length <= 0)
            return false;
        for(int i=0; i<length; i++)
        {
            if(numbers[i]<0 || numbers[i]>=length)
                return false;
        }
        for(int i=0; i<length; i++)
        {
            while(numbers[i] != i)
            {
                if(numbers[i] == numbers[numbers[i]])
                {
                    *duplication = numbers[i];
                    return true;
                }
                int temp = numbers[i];
                numbers[i] = numbers[temp];
                numbers[temp] = temp;
            }
        }
        return false;
    }
};


/*****************************************************/
#include <unordered_map>
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) 
    {
        if(numbers== nullptr || length <= 0)
            return false;
        for(int i=0; i<length; i++)
        {
            if(numbers[i]<0 || numbers[i]>=length)
                return false;
        }
        unordered_map<int, int> m;
        for(int i=0; i<length; i++)
        {
            if (m.count(numbers[i]) == 0)
                m[numbers[i]]++;
            else
            {
                *duplication = numbers[i];
                return true;
            }
        }
        return false;
    }
};
