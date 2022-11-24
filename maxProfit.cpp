#include <stdio.h>
#include <vector>
#include<iostream>
#include <stdint.h>
using std::cout;
using std::endl;
using std::vector;

int maxProfit(vector<int>& prices) {
    if(prices.size() <= 1)
    {
        return 0;
    }

    int minPrice = INT32_MAX;
    int maxProfit = 0;
  

    for(int i = 0; i < prices.size(); ++i) 
    {
        // 即往下走时， 要么寻找最大的收益，要么寻找最小的价格(该最小值相对于往后走的最小值)
        if(minPrice > prices[i])
        {
            minPrice = prices[i];
        }else if(prices[i] - minPrice > maxProfit)
        {
            maxProfit = prices[i] - minPrice;
        }
    }

    return maxProfit;


}