class Solution {
public:
    void Reverse(char* start, char* end)
    {
        if(start==nullptr || end==nullptr)
            return ;
        while(start<end)
        {
            char temp = *start;
            *start = *end;
            *end = temp;
            start++;
            end--;
        }
    }
    
    string ReverseSentence(string str)
    {
        int len = str.length();
        if(len < 1)
            return "";
        char* start = &str[0];
        char* end = &str[len-1];
        
        Reverse(start, end);  // 
        start = end = &str[0];  //
        while(*start != '\0')
        {
            if(*start==' ')
            {
                start++;
                end++;
            }
            else if(*end == '\0' || *end == ' ')  // 一个单词结束
            {
                Reverse(start, --end);
                ++end;
                start = end;
            }
            else
                end++;
        }
        return str;
    }
};


/*
Method 2
*/

//翻转str从s到e的部分
void ReverseWord(string &str, int s, int e)
{
	while(s < e)
	    swap(str[s++], str[e--]);
}

string ReverseSentence(string str) 
{
	ReverseWord(str, 0, str.size() - 1); //先整体翻转
	int s = 0, e = 0;
	int i = 0;
	while(i < str.size())
	{
	    while(i < str.size() && str[i] == ' ') //空格跳过
		i++;
	    e = s = i; //记录单词的第一个字符的位置
	    while(i < str.size() && str[i] != ' ') //不是空格 找单词最后一个字符的位置
	    {
		i++;
		e++;
	    }
	    ReverseWord(str, s, e - 1); //局部翻转
	}
	return str;
}
