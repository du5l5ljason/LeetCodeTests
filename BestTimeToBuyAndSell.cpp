//
//  BestTimeToBuyAndSell.cpp
//  
//
//  Created by 廷芳 杜 on 4/26/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
//  From the question, we know:
//  1. for buying, we only want to buy at those days that the price is "local minimum".
//  Further, if day j is after day i, then we only consider to modify our strategy at day j if price[j] is lower than price[i].
//  2. Keep updating the largest profit, if it is larger than current profit, save that day to the sell day.

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( prices.size() == 0 ) return 0;
        
        int minPrice = prices[0];
        int maxProfit = 0;
        int curProfit = 0;

        for( int i = 0; i < prices.size(); i++ )
        {
            //Keep updating the largest profit
            curProfit = prices[i] - minPrice;
            if( curProfit > maxProfit )
            {
                maxProfit = curProfit;
            }
            
            //update the minimum value.
            if( prices[i] < minPrice )
                minPrice = prices[i];
        }
        
        return maxProfit;
    }
};
