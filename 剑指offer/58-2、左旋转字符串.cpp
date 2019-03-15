class Solution {
public:
    string LeftRotateString(string str, int n)
    {
        int len = str.length();
        if(len < 1) return str;
        n %= len;
        if(n<1) return str;
        
        Rotate(str, 0, n-1);
        Rotate(str, n, len-1);
        Rotate(str, 0, len-1);
        
        return str;
    }
    
    void Rotate(string& str, int start, int end)
    {
        while(start<end)
        {
            char temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            start++;
            end--;
        }
    }
};
