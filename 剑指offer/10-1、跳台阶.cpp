class Solution {
public:
    int jumpFloor(int number)
    {
        if(number<2)
            return number==0 ? 0:1;
        int begin = 1;
        int end   = 2;
        int result= 2; 
        for(int i=3; i<=number; i++)
        {
            result = begin+end;
            begin  = end;
            end    = result;
        }
        return result;
    }
};
