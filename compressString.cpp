#include<iostream>
#include<string>

using namespace std;

    string compressString(string S) {
        if(S.length() == 0)
        {
            return S;
        }
        string sCompress;
        char x = S[0];
        int num = 0;
        for(auto & c : S)
        {
            if(c == x)
            {
                ++num;
            }else
            {
                sCompress.push_back(x);
                sCompress.append(to_string(num));
                x = c;
                num = 1;
            }
        }

        sCompress.push_back(x);
        sCompress.append(to_string(num));
        return sCompress.size() < S.size()  ? sCompress : S;
    }

int main()
{
    cout << compressString("aabcccccaaac") << endl;
    return 0;
}