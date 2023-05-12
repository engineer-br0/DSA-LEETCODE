// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(1)) return 1;
        
        int l = 2;
        int r = n;
        while(l <= r){
            long long int mid = l;
            mid = (mid + r)/2;
            if(isBadVersion(mid)){
                if(!isBadVersion(mid-1)) return mid;
                else{
                    r = mid - 1;
                }
            }
            else l = mid + 1;
        }
        return -1;
    }
};