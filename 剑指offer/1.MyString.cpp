/*
编写拷贝赋值函数，拷贝构造函数，操作符重载
*/
#include<iostream>
#include<cstring>
using namespace std;

class MyString{
public:
    MyString(char* cstr = nullptr);
    MyString(const MyString& str);
    MyString& operator= (const MyString& str);
    ~MyString();
    char* get_c_str() const{return m_data;};
private:
    char* m_data;
};

MyString::MyString(char *cstr) {
    if (cstr){
        m_data = new char[strlen(cstr)+1];
        strcpy(m_data, cstr);
    }
    else{
        m_data = new char[1];
        *m_data = '\0';
    }
    cout << "init success" << endl;
}

inline MyString::~MyString() {
    delete[] m_data;
}

MyString::MyString(const MyString &str) {
    m_data = new char[strlen(str.m_data)+1];
    strcpy(m_data, str.m_data);
}

inline MyString& MyString::operator= (const MyString& str){
    if(this == &str)
        return *this;

    delete[] m_data;
    m_data = new char[strlen(str.m_data)+1];
    strcpy(m_data, str.m_data);
    return *this;
};

ostream& operator<< (ostream& os, const MyString& str){
    os << str.get_c_str() << endl;
    return os;
};

int main() {
    char* h = "hello";
    MyString s1(h);
    MyString s2("world");
    MyString s3 = s2;  //这里调用的是拷贝构造函数
    MyString s4;
    s4 = s3;  // 这里调用的是拷贝赋值函数
    cout << s1;
    cout << s3;

    return 0;
};
