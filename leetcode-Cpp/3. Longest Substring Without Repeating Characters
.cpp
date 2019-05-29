class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int curLength = 0;
        int maxLength = 0;

        int* position = new int[256];
        for (int i = 0; i < 256; ++i)
            position[i] = -1;

        for (int i = 0; i < s.length(); ++i)
        {
            int prevIndex = position[s[i]];
            if (prevIndex < 0 || i - prevIndex > curLength)
                ++curLength;
            else  // 距离上次出现的位置小于或等于f(i-1)
            {
                if (curLength > maxLength)
                    maxLength = curLength;

                curLength = i - prevIndex;  // =d;
            }

            position[s[i]] = i;
        }

        if (curLength > maxLength)
            maxLength = curLength;

        delete[] position;
        return maxLength;    
    }
};
