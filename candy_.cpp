#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;
//官方贪心算法的思路需要借鉴
int candy(vector<int>& ratings) 
{
    if(ratings.size() == 0)
    {
        return 0;
    }
    if(ratings.size() == 1)
    {
        return 1;
    }

    size_t size = ratings.size();
    set<int> lowPoint;
    vector<int> candy(size, 0);
    for(int i = 0; i < size; ++i)
    {
        if((i == 0 && ratings[0] <= ratings[1]) ||
        (i == size - 1 && ratings[i] <= ratings[i - 1]) ||
        (ratings[i] <= ratings[i - 1] && ratings[i] <= ratings[i + 1]))
        {
            cout << "lowPoint: " << i << endl;
            lowPoint.insert(i);
            candy[i] = 1;
        }
    }

    for(auto& it : lowPoint)
    {
        for(int i = 1; i < size; ++i)
        {
            //越界
            if((it - i < 0 && it + i >= size) || 
            (it - i >= 0 && it + i < size && ratings[it - i] <= ratings[it - i + 1] && ratings[it + i] <= ratings[it + i -1]) ||
            (it - i < 0 && ratings[it + i] <= ratings[it + i -1]) ||
            (it + i >=size && ratings[it - i] <= ratings[it - i + 1]))
            {
                break;
            }

            //往lowPoint的左边爬坡
            if(it - i >= 0 && ratings[it - i] > ratings[it - i + 1])
            {
                candy[it - i] = candy[it - i] >= candy[it - i + 1] ? candy[it - i] :  candy[it - i + 1] + 1;
                cout << "it - i: " << it - i << " candy:" << candy[it - i] << endl; 
            }

            //往lowPoint的右边爬坡
            if(it + i < size && ratings[it + i] > ratings[it + i -1])
            {
                //candy[it + i]candy[it + i] < candy[it + i - 1] + 1
                    candy[it + i] = candy[it + i -1] + 1;
            }
        }
    }

    int sum  = 0;
    for(int i = 0; i < size; ++i)
    {
        sum += candy[i];
    }
    return sum;
}

int main()
{
    vector<int> vec{1, 3, 4, 5, 2};

    cout << candy(vec) << endl;
    return 0;
}