#include<iostream>
#include<string>
#include <vector>

using namespace std;

string multiply(string num1, string num2)
{
    int m = num1.size(), n = num2.size();
    string ans(m + n, '0');  // 初始化一个string字符串
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int sum = (num1[i] - '0') * (num2[j] - '0') + (ans[i + j + 1] - '0');
            ans[i + j + 1] = sum % 10 + '0';
            ans[i + j] += sum / 10;
        }
    }
    for (int i = 0; i < m + n; i++) {
        if (ans[i] != '0') {
            return ans.substr(i);  // 从第一个部位0的数一直打印到最后一个数
        }
    }
    return "0";
}

int main() {
    string s1 = "123";
    string s2 = "456";
    cout << multiply(s1, s2) << endl;
    return 0;
};

