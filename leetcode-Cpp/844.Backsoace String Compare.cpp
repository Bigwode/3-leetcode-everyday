#include<stack>

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s1;
        stack<char> s2;
        
        for (char& c : S)
        {
            if (c == '#')
            {
                if (s1.empty() != 1) s1.pop();
            }
            else
            {
                s1.push(c); 
            }
        }
        
        for (char& c : T)
        {
            if (c == '#')
            {
                if (s2.empty() != 1) s2.pop();
            }
            else
            {
                s2.push(c); 
            }
        }
        
        return s1 == s2;
    }
};
