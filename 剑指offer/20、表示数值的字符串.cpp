class Solution {
public:
    bool isUnsignedInt(char** string)
    {
        char* before = *string;
        while(**string != '\0' && **string >= '0' && **string <='9')
        {
            ++(*string);  // 指针前移一个
        }
        return *string > before;
    }
    
    bool isInt(char** string)
    {
        if(**string == '+' || **string == '-')
            ++(*string);
        return isUnsignedInt(string);
        
    }
    
    bool isNumeric(char* string)
    {
        if(string == nullptr)
            return false;
        bool numeric = isInt(&string);  // 判断整数部分是否包含含有正负号的整数
        
        if(*string == '.')
        {
            ++string;
            numeric = isUnsignedInt(&string)  || numeric;  // 判断小数部分是否包含无符号整数，小数点前后只需要有一方含有整数就可以
        }
        if(*string == 'e' || *string == 'E')
        {
            ++string;
            numeric = numeric && isInt(&string);  // E/e的两侧必须都含有整数
        }
        return numeric && (*string == '\0');
    }

};
