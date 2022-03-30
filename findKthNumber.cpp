#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
//求mid
int kThCount(int m, int n, int mid)
{

}
*/
//bound是一个界限，确定数组中是否有>= k 个数字满足 <= bound。
bool enough(int bound, int m, int n, int k)
{
    int count = 0;
    for(int i = 1; i <= m; ++i)
    {
        count += min(bound / i, n); // 按行遍历，每行都是递增等差序列，所以可以找到每行中小于bound的数
    }
    return count >= k;
}

int findKthNumber(int m, int n, int k) 
{
    int low = 1, high = m * n;
    while(low < high)
    {
        int mid = low + (high - low) / 2;
        if(! enough(mid, m, n, k))
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return low;
    /*
    int left = 1, right = m * n;
    while(left < right)
    {
        int mid = (left + right) / 2;
    }
    */

   /* int index = 0, min = 0; //记录上一个最小值
    vector<int> vec;
    vec.reserve(m * n);
   for(int i = 1; i <= m; ++i)
   {
       for(int j = 1; j <= n; ++j)
       {
           vec.push_back(i * j);
       }
   }

    cout << "vec.size: " << vec.size() << endl;
    std::sort(vec.begin(), vec.end());
    cout << "vec.size: " << vec.size() << endl;
   return vec[k - 1];
   */


}

int main()
{

    cout << findKthNumber(2, 3, 2) << endl;
}