#include<vector>
#include<iostream>

using namespace std;

    int reverse(int x) 
    {
        int result = 0;
        while(x != 0)
        {
            if(result > INT_MAX / 10 || result < INT_MIN / 10)
            {
                return 0;
            }
            result = result * 10 + x % 10;
            x = x / 10;
        } 

        return result;
    }

int main()
{
    cout << reverse(123) << endl;
    cout << -1 % 10 << endl;
    return 0;
}