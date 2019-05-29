#include <iostream>
#include <vector>
#include <string>

using namespace std;


int longestSubstringWithoutDuplication(const string& str)
{
    int curLength = 0;
    int maxLength = 0;

    int* position = new int[26];
    for (int i = 0; i < 26; ++i)
        position[i] = -1;

    for (int i = 0; i < str.length(); ++i)
    {
        int prevIndex = position[str[i] - 'a'];
        if (prevIndex < 0 || i - prevIndex > curLength)  // 如果该字符没有出现或者距离上次出现的距离大于f(i-1)
            ++curLength;
        else  // 距离上次出现的位置小于或等于f(i-1)
        {
            if (curLength > maxLength)
                maxLength = curLength;

            curLength = i - prevIndex;  // =d;
        }

        position[str[i] - 'a'] = i;
    }

    if (curLength > maxLength)
        maxLength = curLength;

    delete[] position;
    return maxLength;
}


int main()
{
    cout<< longestSubstringWithoutDuplication("arabcacfr");
    return 0;
}


class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int len = s.size();
        if(len <= 0) return 0;
        int* pos = new int[26];
        for(int i=0; i<26; i++)
            pos[i] = -1;
        int maxlen = 0;
        int curlen = 0;
        
        for(int j=0;j<len; j++)
        {
            int dis = pos[s[j]-'a'];
            if(dis==-1 || j-dis>curlen)  // 没出现过或者距离大于maxlen
                curlen++;
            else  // 出现过且距离小于等于d，curlen=d
            {
                if(curlen > maxlen)
                    maxlen = curlen;
                curlen = j-dis;
            }
            pos[s[j]-'a'] = j;
        }

        if(curlen > maxlen)
            maxlen = curlen;
        
        delete[] pos;
        return maxlen;
        
    }
};
