class Solution {
public:
    int FirstNotRepeatingChar(string str)
    {
        unsigned int p[256] = {0};
        for(int i=0; i<str.length(); i++)
            p[str[i]]++;
        for(int i=0; i<str.length(); i++)
            if(p[str[i]]==1)
                return i;
        return -1;
    }
};
