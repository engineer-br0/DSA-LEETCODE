class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mpt;
        unordered_map<char, int> mps;
        int count = t.size();  // 
        int n = s.size(); 
        for(int i =0; i<count; i++){
            mpt[t[i]]++;
        }
        int l = 0;
        int r = 0;
        int mini = INT_MAX;
        int head = 0;
        while(r<n){
                    mps[s[r]]++;
                    if(mps[s[r]] <= mpt[s[r]])count--;
                    while(count == 0){
                        if(r-l+1 < mini){
                            mini = r-l+1;
                            head = l;
                        }
                        if(mpt[s[l]] > 0) {
                            mps[s[l]]--;
                            if(mps[s[l]] < mpt[s[l]]) count++;
                        }
                        l++;
                    }
                r++;
        }
        return (mini == INT_MAX)? "" : s.substr(head, mini);
    }
};