class Solution {
public:
     int  NumberOf1(int n)
     {
         int count = 0;
         int i = 1;
         while(i)
         {
             if(n & i)
                 ++count;
             i = i << 1;
         }
         return count;
     }
};

/*method 2*/
class Solution {
public:
     int  NumberOf1(int n)
     {
         int count = 0;
         while(n)
         {
             ++count;
             n = (n-1) & n;
         }
         return count;
     }
};
