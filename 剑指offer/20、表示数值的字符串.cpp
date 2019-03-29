class Solution {
public:
    bool isUnsignedInt(char** string)
    {
        char* before = *string;
        while(**string != '\0' && **string >= '0' && **string <='9')
        {
            ++(*string);  // 通过指针判断是否存在0-9的数字
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
        
        if(*string == '.')  // 小数部分
        {
            ++string;
            numeric = isUnsignedInt(&string)  || numeric;  // 小数点前后只需要有一侧含有整数就可以，但是小数点后不能有正负号
        }
        if(*string == 'e' || *string == 'E')  // 指数部分
        {
            ++string;
            numeric = numeric && isInt(&string);  // E/e的两侧必须都含有整数
        }
        return numeric && (*string == '\0');
    }

};
