#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }
    
    bool insert(int val) {
        if(_hashMap.find(val) != _hashMap.end()){
            return false;
        }
        
        _container.emplace_back(val);    
        _hashMap.insert(make_pair(val, _container.size() - 1));
        
        return true;
    }
    
    bool remove(int val) {
        if(_hashMap.find(val) == _hashMap.end())
            return false;

        int location = _hashMap.find(val)->second;
        _hashMap.erase(val);
        if(location != _container.size() - 1){
            _container[location] = _container.back();
            _hashMap[_container[location]] = location;
        }
            
        _container.pop_back();
        return true; 
    }
    
    int getRandom() {
        int Random = rand() % _container.size();
        return _container[Random];
    }

private: 
    unordered_map<int, int> _hashMap;
    vector<int> _container;
 
    
};

