//146. LRU 缓存机制
#include<iostream>
#include<list>
#include<unordered_map>

using namespace std;
//原理：
//  LRU: 最近最少使用算法，在cache中，如果cache中容量已满，首先删除元素是在最近时间内，最不经常使用的元素。
//       注意和最少使用法的区别。
// 1:使用双向链表list存储数据: pair<int, int> (key, value), LRU; 
//   选择list 因为 头部、中间插入元素，或者删除尾部元素时间复杂度均为o(1),无需移动元素;
//   最近使用的元素放在链表的最前面。
// 2: 选择unordered_map<int, list<pair<int, int>>::iterator> 做哈希表，unordered_map利用哈希表实现， 元素间无序，查找和插入的时间复杂度均为o(1);
//    所以通过key完成查找节点的时间复杂度o(1)。

//输出双向链表
std::ostream& operator<<(std::ostream& ostr, const std::list<pair<int, int> >& list)
{
    for (auto i : list) {
        ostr << i.first << ", " << i.second << "; ";
    }
    return ostr;
}

class LRUCache {
public:
    using ListIter = list<pair<int, int> >::iterator;
    using UnorderMapIter = unordered_map<int, ListIter>::iterator; 
    LRUCache(int capacity) 
    :_capacity(capacity)
    {
        
    }
    
    int get(int key)
    {
        UnorderMapIter ite = _cache.find(key); 
        //
        //查找时未找到， 直接返回 -1
        if(ite == _cache.end())
        {
            return -1;
        }

        //如果存在，因为最近一次使用到该元素，所以需将该key的数据移动到链表最前面;
        _data.splice(_data.begin(), _data, ite->second);
        //_cache[key] = _data.begin();
        return ite->second->second;
    }
    
    void put(int key, int value)
    {
        UnorderMapIter ite = _cache.find(key); 
        if(ite == _cache.end())
        {
            //如果该元素没在cache中， 需要添加到cache中，首先判断cache是否已满，如果满了，将链表最后一个元素移除
            if(_data.size() == _capacity)
            {
                _cache.erase(_data.back().first);
                _data.pop_back();
            }

            _data.push_front(make_pair(key, value));
            _cache.insert(make_pair(key, _data.begin()));
        }
        else
        {
            //如果元素已经存在cache中，更新该key的value值，并且将该元素移到链表最前面。
            ite->second->second = value;
            _data.splice(_data.begin(), _data, ite->second);
            _cache[key] = _data.begin();
        }
    }
    //打印链表
    void print()
    {
        cout << _data << endl;
    }
private:

    int _capacity; 
    list<pair<int, int> > _data;
    unordered_map<int, ListIter> _cache;  
};

int main()
{ 
    LRUCache lru(2);
    lru.put(1,1);
    lru.put(2,2);
    lru.print();
    lru.put(3,3);
    lru.print();
    lru.get(1);
    lru.print();
    cout << "get2 " << lru.get(2) << endl;;
    lru.print();
    lru.put(2, 3);
    lru.print();
    return 0;
}