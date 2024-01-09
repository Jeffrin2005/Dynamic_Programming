#include <bits/stdc++.h>
#define ll long long
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>ss;
        ll maxi =0;
        ll start = 0;

        
        ll end = 0;
        while(start < s.size()){
            if(ss.find(s[start]) != ss.end()){ 
                ss.erase(s[end]);
                end++;
            }else{
                maxi = max(start-end + 1, maxi);
                ss.insert(s[start]);
                start++;
            }
        }
        return  maxi;
        
    }
};
