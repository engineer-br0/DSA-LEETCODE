class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<bool> v(n, true);
        int ans = 1;
        for(int i = 3; i<n; i+=2){
          if(v[i]){
            ans++;
            int k = 2;
            for(int j = i+i; j<n; j += i ){
              v[j] = false;
            }
          }
        }
        return ans;
    }
};