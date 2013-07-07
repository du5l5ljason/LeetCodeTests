//
//  3SumClosest.cpp
//  
//
//  Created by 廷芳 杜 on 7/7/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( num.size() == 0 ) return 0;
        if( num.size() <=3 ) 
        {
            int sum=0;
            for( int i = 0 ; i < num.size(); i ++ )
                sum = sum + num[i];
            return sum;
        }
        
        sort( num.begin(), num.end() );
        
        int sum = 0;
        int start = 1;
        int end = num.size()-1;
        int closestValue = num[0] + num[start] + num[end];
        for( int i = 0 ; i < num.size()-2; i++ )
        {
            start = i + 1;
            sum = num[i] + num[start] + num[end];
            
            if( sum == target ) return sum;
            while( end>start+1 && num[i] + num[start] + num[end] < target )
            {
                sum = num[i]+num[start]+num[end];
                if( abs(target - closestValue ) > abs(target - sum) )
                    closestValue = sum;
                start++;
            }    
            
            
            while( end>start+1 && num[i] + num[start] + num[end] > target )
            {
                sum = num[i]+num[start]+num[end];
                if( abs(target - closestValue ) > abs(target - sum) )
                    closestValue = sum;
                end--;
            }
            
            sum = num[i] + num[start] + num[end] ;
            
            if( abs(target - closestValue) > abs(target - sum) )
                closestValue = sum;
        }
        
        return closestValue;
    }
};