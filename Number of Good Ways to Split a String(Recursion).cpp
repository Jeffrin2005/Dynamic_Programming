class Solution {
public:
       
    bool checkIfGood(string s1, string s2){
        set<char> x1;
        set<char> x2;
        int c1 = 0;
        int c2 = 0;
        for(int i=0; i<s1.size(); i++){
            if(x1.find(s1[i]) == x1.end()){
                c1++;
                x1.insert(s1[i]);
            }
            else{
                
            }
        }
        for(int i=0; i<s2.size(); i++){
            if(x2.find(s2[i]) == x2.end()){
                c2++;
                x2.insert(s2[i]);
            }
            else{
                
            }
        }
        return c1 == c2;
    }
    
    int numSplits(string s) {
        int count = 0;
        for(int i=0; i<s.length()-1; i++){
            if(checkIfGood(s.substr(0,i+1), s.substr(i+1, s.length())))
                count++;
        }
        return count;
    }
    
};
