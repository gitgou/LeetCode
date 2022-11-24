#include<math.h>
#include<unordered_set>
using namespace std;
    bool isHappy(int n) {
       unordered_set<int> hashN; 
        while(n != 1 && hashN.find(n) == hashN.end()){
            int tmp = n;
            n = 0;
            while (tmp != 0)
            {
                n += pow(tmp % 10, 2);
                tmp /= 10;
            }
            hashN.insert(n);
        }

        return n == 1;
    }