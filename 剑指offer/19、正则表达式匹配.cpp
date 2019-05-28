class Solution {
public:
    bool matchCore(char* str, char* pattern)
    {
        if(*str=='\0' && *pattern=='\0') return true;
        if(*str!='\0' && *pattern=='\0') return false;  // 不能加 *str=='\0' && *pattern!='\0'是因为（“”， “.*”）

        if(*(pattern+1) == '*')  // 先判断下一个字符是不是'*'
        {
            if(*str == *pattern  || (*str != '\0' && *pattern == '.'))  // 字符匹配或者.匹配
                return matchCore(str, pattern+2) ||  // 直接跳过*，表示匹配0个
                matchCore(str+1, pattern) ||  // 循环可实现匹配多个字符
                matchCore(str+1, pattern+2);  // 匹配一个
            else
                return matchCore(str, pattern+2);  // 没有匹配上，直接跳过两个字符
        }
        if(*str == *pattern || (*str != '\0' && *pattern == '.'))  // 字符匹配或者.匹配
        {
            return matchCore(str+1, pattern+1);
        }
        return false;
    }
    
    bool match(char* str, char* pattern)
    {
        if(str == nullptr || pattern == nullptr) return false;
        return matchCore(str, pattern);
    }
};
