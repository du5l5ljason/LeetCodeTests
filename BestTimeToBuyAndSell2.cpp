//
//  BestTimeToBuyAndSell2.cpp
//  
//  
//  Created by 廷芳 杜 on 7/5/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
//  Every time, we buy at local minimum and sell at local maximum. Add all the local profit.
//  TC O(n) solution.

#include <iostream>
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int curDay = 0;
        int curPrice = 0;
        int maxProfit = 0;
        
        bool buyOrSell = 0; //0 - buy, 1 - sell
        
        if( prices.size() == 0 ) return 0;
        if( prices.size() == 1 ) return 0;
        
        if( prices[1] >= prices[0] )
        {
            curPrice = prices[0];
            buyOrSell = 0;
        }
        else
            buyOrSell = 1;
        
        while( curDay < prices.size() )
        {
            switch( buyOrSell ){
                case 0: 
                    if( prices[curDay] >= prices[curDay-1] && (prices[curDay] >= prices[curDay+1] || curDay == prices.size()-1 ) )
                    {
                        maxProfit = maxProfit + prices[curDay] - curPrice;
                        //curPrice = prices[curDay];
                        buyOrSell = 1;
                    }
                case 1:
                    if( prices[curDay] <= prices[curDay-1] && (prices[curDay] <=prices[curDay+1] || curDay == prices.size()-1 ))
                    {
                        curPrice = prices[curDay];
                        buyOrSell = 0;
                    }
            }
            curDay++;
        }
        
        return maxProfit;
    }
};
