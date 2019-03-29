class Solution {
public:
    int Fibonacci(int n)
    {
        if(n<2)
            return n==0 ? 0:1;
        int zero= 0;
        int one = 1;
        int res = 0;
        for(int i=2; i<=n; i++)
        {
            res = zero + one;
            zero = one;
            one =  res;
        }
        return res;
    }
};
