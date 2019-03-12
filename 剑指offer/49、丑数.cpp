class Solution {
public:
    int Min(int num1, int num2, int num3)
    {
        int min = (num1 < num2)?num1:num2;
        min = (min<num3)?min:num3;
        return min;
    }
    
    int GetUglyNumber_Solution(int index)
    {
        if(index<1)
            return 0;
        int* p = new int[index];
        int* ind2 = p;
        int* ind3 = p;
        int* ind5 = p;
        p[0] = 1;
        int uglyIndex = 1;
        while(uglyIndex < index)
        {
            int min = Min(*ind2 * 2, *ind3 * 3, *ind5 * 5);
            p[uglyIndex] = min;
            while(*ind2 * 2 <= p[uglyIndex])
                ind2++;
            while(*ind3 * 3 <= p[uglyIndex])
                ind3++;
            while(*ind5 * 5 <= p[uglyIndex])
                ind5++;
            uglyIndex++;
        }
        int ugly = p[uglyIndex-1];
        delete[] p;
        return ugly;
    }
};
