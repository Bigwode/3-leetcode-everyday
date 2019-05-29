class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n<1) return 0;
        int count = 0;
        int base = 1;
        int round = n;
        while(round>0)
        {
            int weight = round%10;
			round /= 10;
			count += round * base;  // if weight=0
			if(weight == 1)
				count += (n%base)+1;  // if weight=1 return count+former+1;
			else if(weight > 1)
				count += base;  // if weight>1 return count+base;
			base *= 10;
        }
        return count;
    }
};

/*
(round, weight)
*/
