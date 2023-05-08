#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, n = gas.size();
        while (start < n)
        {
            int gasSum = 0, costSum = 0;   
            int index = 0; 
            int cnt = 0;
            while(cnt < n){
                index = (start+cnt) % n;
                gasSum += gas[index], costSum += cost[index];
                if(gasSum < costSum){
                  break;
                }
                cnt++;
            }

            if(index == start)
                return start;
            else{
              start = index + cnt + 1;
            }
            cout << start << endl;
        }
        return -1; 
    }
};

int main(){
    vector<int> gas{1,2,3,4,5}, cost{3,4,5,1,2};
    Solution solve;
    int res = solve.canCompleteCircuit(gas, cost);
    cout << res << endl;
    return 0; 
}