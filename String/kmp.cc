#include <algorithm>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>

class KMP
{
    std::vector<int> next;

    void _gen_next(std::string pat)
    {
        int len = pat.size();
        next.assign(len, 0);
        int i = 2;
        int m = next[i - 1]; // i-1元素对应的最长公共前后缀的长度
        while (i < len)
        {
            while (m > 0 && pat[i - 1] != pat[m]) // pat[i-1] 和 pat[next[i-1]] 匹配失败
                m = next[m];
            if (pat[i - 1] == pat[m])
                m++;
            next[i++] = m;
        }
    }

  public:
    std::string pat;
    KMP() = default;
    KMP(std::string pat)
    {
        this->pat = pat;
        _gen_next(pat);
    }
    int Search(std::string txt)
    {
        int i = 0; // 指向txt字符串的指针
        int j = 0; // 指向pat字符串的指针
        int txt_len = txt.size();
        int pat_len = pat.size();

        while (i < txt_len && j < pat_len)
        {
            if (pat[j] == txt[i])
            {
                i++;
                j++;
            }
            else if (j == 0)
                i++;
            else
                j = next[j];
        }
        return j == pat_len ? (i - j) : -1;
    }
    void Reset(std::string pat)
    {
        this->pat = pat;
        _gen_next(pat);
    }
};

int test_generate_next_array()
{
    std::string pat("abcabeeeabcabc");
    KMP kmp(pat);

    return 0;
}
int main()
{
    std::string txt("abababaababacb");
    std::string pat("ababacb");
    KMP kmp(pat);
    int pos = kmp.Search(txt);
    assert(pos == 7);
    return 0;
}
