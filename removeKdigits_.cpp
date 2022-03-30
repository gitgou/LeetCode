#include<string>
#include<iostream>

using namespace std;

    string removeKdigits(string num, int k) {
        if(k == num.size())
            return "0";

        int i = 0, j = 0;
            while(j < k && i < num.size() - 1)
            {
                if(num[i] > num[i + 1])
                {
                    //num.erase(i, 1);
                    num[i - j] = num[i + 1];
                    ++j;
                    cout << num << endl;
                }else{
                    num[i - j + 1] = num[i + 1];
                    cout << num << endl;
                }

                ++i;
            }

        cout << num << endl;
        while(i < num.size() - 1)
        {
            num[i - j + 1] = num[i + 1];
            ++i;
        }

        num = num.substr(0, num.size() - k); 
        //去掉前导 0 
        for(int i = 0; i < num.size(); ++i)
        {
            if(num[i] == '0' && i == num.size() - 1){
                return "0";
            }else if(num[i] == '0'){
                continue;
            }else{
                num = num.substr(i);
                break;
            }
        } 

        return num;
    }

int main()
{
    cout << removeKdigits("1234567890", 9) << endl;
    return 0;
}
