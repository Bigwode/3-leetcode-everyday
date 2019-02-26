class Solution {
public:
    double Power(double base, int exponent)
    {
        if(base == 0)
            return 0;
        if(exponent == 0)
            return 1;
        double pow = 1;
        if(exponent > 0)
        {
            while(exponent--)
                pow = pow * base;
            return pow;
        }
        else
        {
            exponent = -exponent;
            while(exponent--)
                pow = pow * base;
            return 1.0 / pow;
        }
    }
};
