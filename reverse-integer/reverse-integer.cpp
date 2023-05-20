class Solution {
public:
    int reverse(int x) {
        if(x == -2147483648) return 0;
         int ans = 0;
         int mul = 1;
         if(x < 0) {
             mul = -1;
             x = -x;
         }
        
        int limit = INT_MAX/10;
        while(x){
            if(ans > limit) return 0;
            //else if(ans == limit )
            ans = ans * 10 + x % 10;
            x = x/10;
        }
        
        return ans * mul;
    }
};