class Solution {
public:
    int jumpFloor(int number)
    {
        int begin = 0;
        int end   = 1;
        int result= 0; 
        for(int i=1; i<=number; i++)
        {
            result = begin+end;
            begin  = end;
            end    = result;
        }
        return result;
    }
};
