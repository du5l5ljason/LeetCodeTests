//
//  BestTimeToBuyAndSell.cpp
//  
//
//  Created by 廷芳 杜 on 4/26/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int min, maxProfit, buyDay, sellDay,curProfit;
        
        buyDay = 0;
        sellDay = 0;
        min = 0;
        maxProfit = 0;
        
        if( prices.size() == 0 ) return 0;
        if( prices.size() == 1 ) return 0;
        
        min = prices[0];
        for( int i = 0 ; i < prices.size(); i++ )
        {
            if( prices[i] < min )
            {
                min = prices[i];
                buyDay = i;
            }    
            curProfit = prices[i] - min;
            
            if( curProfit > maxProfit )
            {
                maxProfit = curProfit;
                sellDay = i;
            }
        }
        
        return maxProfit;
    }
};