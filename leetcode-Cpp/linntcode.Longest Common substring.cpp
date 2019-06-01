#include<iostream>
#include<vector>
#include<string>

using namespace std;

void findMaxCommonStr(string s1,string s2)
{
    if(s1.length()>s2.length())
        swap(s1,s2);  //s1用于保存较短的子串
    
    int len1=s1.length(),len2=s2.length();
    int maxLen=0, start=0;
    
    vector<vector<int> >dp(len1+1,vector<int>(len2+1,0));
    
    for(int i=1;i<=len1;++i)
        for(int j=1;j<=len2;++j)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                if(dp[i][j]>maxLen)
                {
                    maxLen=dp[i][j];
                    start=i-maxLen;//记录最长公共子串的起始位置
                }
            }
        }
    cout<<s1.substr(start,maxLen)<<endl;
}

int main()
{
    string s1="ABC",s2="ABCD";

    findMaxCommonStr(s1,s2);

    return 0;
}

