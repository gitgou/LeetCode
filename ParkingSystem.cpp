#include<iostream>
#include<vector>
using namespace std;

class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) 
    {
        _vecParks.push_back(big);
        _vecParks.push_back(medium);
        _vecParks.push_back(small);
    }
    
    bool addCar(int carType) {
        if(_vecParks[carType - 1] <= 0)
            return false;
        
        _vecParks[carType - 1] -= 1;
        return true;
    }

private: 
    vector<int> _vecParks;
};