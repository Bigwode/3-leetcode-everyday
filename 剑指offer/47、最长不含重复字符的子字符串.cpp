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

