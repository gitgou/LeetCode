#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

//如果使用排序，每次插入的复杂度最小为o(n), 插入查找时查找可以实现o(log(n))，但是移动元素依然需要o(n)。
//而使用大小顶堆进行插入，调整堆的时间复杂度为o(log(n)),所以最好选用大小顶堆来做选择最大或者最小值。
//因为返回之后不会删除所有返回的数，使用add操作时会导堆膨胀，所以应该维护一个大小为k的。

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) 
    :_k(k)
    {
        //建堆
        for(auto & i : nums)
        {
            add(i);
        }
    }

    int add(int val)
    {
        _data.push(val);
        if(_data.size() > _k)
        {
            _data.pop();
        }

        return _data.top();
    }

    /* 使用vector排序, 时间复杂度高 
    int add(int val)
    {
        _data.push_back(val);
        sort(_data.begin(), _data.end(), std::greater<int>());
        if(_data.size() > _k)
        {
            _data.pop_back();
        }
            
        return _data.back();   
    }
    */

private:
    int _k;
    //优先级队列，建立一个小顶堆， 底层使用堆排序实现
    priority_queue<int, vector<int>, std::greater<int> > _data;
};


int main()
{
    vector<int> vec = {4,5,8,2};
    KthLargest* k = new KthLargest(3, vec);
    cout <<  k->add(3) << endl;
    cout <<  k->add(5) << endl;
    cout <<  k->add(10) << endl;
    cout <<  k->add(9) << endl;
    cout <<  k->add(4) << endl;
    return 0;
}