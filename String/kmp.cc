#include<iostream>
#include<string>

int c_kmp(std::string s, std::string w) {
    return 0;
}

int main() {
    std::string s("ABC ABCDAB ABCDABCDABDE");
    std::string w("ABCDABD");
    int ret = c_kmp(s, w);
    static_assert(ret == 15, "result wrong");
    return 0;s
}