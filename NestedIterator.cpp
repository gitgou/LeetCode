#include<vector>
using namespace std;
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const;

     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const;

     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
     const vector<NestedInteger> &getList() const;
 };

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList)
    :_resIndex(0)
    {
        flat(nestedList);
    }
    
    void flat(const vector<NestedInteger>& nestedList){
       
        for(auto & ref : nestedList){
            if(! ref.isInteger()){
                flat(ref.getList());
           
            }else{
                _res.push_back(ref.getInteger()); 
            }
        }
    }
    int next() {
        return _res[_resIndex++];
    }
    

    bool hasNext() {
        return _resIndex < _res.size();
    }

private: 
    size_t _resIndex;
    vector<int> _res;
};
