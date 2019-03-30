class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        int len = sequence.size();
        if(len==0) return false;
        int root = sequence[len-1];
        int i = 0;
        for(;i<len-1;i++)
        {
            if(sequence[i]>root)
                break;
        }
        int j = i;
        for(;j<len-1;j++)
        {
            if(sequence[j]<root)
                return false;
        }
        bool left = true;
        if(i>0)  // 确保元素数大于1
            left = VerifySquenceOfBST(vector<int>(sequence.begin(), sequence.begin()+i));
        bool right = true;
        if(i<len-1)  //  
            right = VerifySquenceOfBST(vector<int>(sequence.begin()+i, sequence.begin()+len-1));
        return left && right;
    }
};
