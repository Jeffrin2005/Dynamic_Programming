class Solution {
public:
    void func(string s, vector<string>v,vector<vector<string>>&ans){
        if(s.size()==0) {
            ans.push_back(v);
            return;
        }
     
        for(int i=1; i<=s.size(); i++){
            string x = s.substr(0,i);
            if(is_pali(x)){
                v.push_back(x);
                string y = s.substr(i,s.size() - i);
                func(y,v,ans);
                v.pop_back();
            }
        }
    }
       bool is_pali(string z){
            string t = z;
            reverse(t.begin(),t.end());
            return z==t;
        }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>v;
        func(s,v,ans);
        return ans;
    }
};
