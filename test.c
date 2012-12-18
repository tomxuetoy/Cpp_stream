#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

class test{
public:
    int v;
    /*构造函数*/
    test():v(0){}
    test(const int &a):v(a){}
    test(const test &t1):v(t1.v){}

    /*以下重载 输入>> 输出<< */
    /*友元函数：因为左操作数不是类的对象，而是ostream&类型，所以无法以成员函数的身份设定，只能是友元函数*/
    friend inline ostream & operator << (ostream & os, test &t1){
        cout << "class t(" << t1.v << ")" << endl;
        return os;
    }
};

int main(){
    test t1;
    test t2(5);
    test t3(-4);
    // writes "0 5 -4\n" to standard output
    cout << t1 << t2 << t3 << endl; 

    ofstream ofs("my_file.txt");
    // writes "0 5 -4\n" to the file my_file.txt
    ofs << 0 << " " << 1 << " " << 2 << endl;

    ostringstream oss;
    // writes "0 5 -4\n" to oss, which is then written to standard output
    oss << 3 << " " << 4 << " " << 5 << endl;
    cout << oss.str() << endl;
     
    return 0;
}
