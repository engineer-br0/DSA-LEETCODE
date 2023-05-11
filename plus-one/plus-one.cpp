class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        
        int n = v.size();
        int i = n-1;
        while(i>=0){
            v[i]++;
            if(v[i] == 10){
                v[i] = 0;
                i--;
            }
            else break;
        }
        if(v[0] == 0){
            v[0] = 1;
            v.push_back(0);
        }
        return v;
    }
};