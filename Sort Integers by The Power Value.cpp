class Solution {
private:
int check(int n) {
    if(n == 1) return 0;
    if (n % 2 == 0){
        return check(n / 2) + 1;
    }else{
        return check(3 * n + 1) + 1;
    }
}
public:
    int getKth(int lo, int hi, int k){

        vector<pair<int,int>>v;
        for(int i=lo;i <= hi;i++){
            v.push_back({check(i) , i});
        }
        sort(v.begin(),v.end());
        return v[k-1].second;
    }
};
