class Temp{
public:
    Temp(){++N; Sum += N;}
    static void reset(){N = 0; Sum = 0;}
    const static int getSum(){return Sum;}
private:
    static int N;
    static int Sum;
};

int Temp::N=0;
int Temp::Sum=0;

class Solution {
public:
    int Sum_Solution(int n)
    {
        Temp::reset();  //　必须在这里reset
        Temp* p = new Temp[n];
        int res = Temp::getSum();
        delete[] p;
        return res;
    }
};
