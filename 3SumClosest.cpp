//
//  3SumClosest.cpp
//  
//  tag: sort
//  Created by 廷芳 杜 on 7/7/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
//  Similar to 3Sum problem. 
//  Because maybe there is no triplet that adds up to target. The "closest Value" could happen at the both side of the target.
//  Solution: Each time, compare the sum to the current closest value, if sum is closer to the target, update the value.
//  That's it.
//  Tc O(n^2). SC O(1)

#include <iostream>

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( num.size() == 0 ) return 0;
        if( num.size() <= 3 ) 
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
