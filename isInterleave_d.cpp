#include <iostream>
#include <string>
#include<algorithm>
#include<vector>
using namespace std; 

 

    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size())
            return false;

        
        vector<vector<bool> > f(s1.size() + 1, vector<bool>(s2.size() + 1, 0));
        f[0][0] = true;
        for(int i = 0; i <= s1.size(); ++i)
        {
            for(int j = 0; j <= s2.size(); ++j)
            {
                //限制下界
                if(i > 0){
                    f[i][j] = (f[i - 1][j] && (s3[i + j - 1] == s1[i - 1])) ? true : f[i][j];
                }
                //限制下界
                if(j > 0){
                    f[i][j] = (f[i][j - 1] && s3[i + j - 1] == s2[j - 1]) ? true : f[i][j];
                }
            }
        }

        return f[s1.size()][s2.size()];
    }

int main()
{
    return 0;
}