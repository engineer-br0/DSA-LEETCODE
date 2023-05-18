class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v(26, -1);
    
    for(int i = 0; i<s.length(); i++){
        int temp = s[i] - 'a';
        v[temp]++;
    }
    
    for(int i = 0; i<s.length(); i++){
        int temp = s[i] - 'a';
        if(v[temp] == 0) return i;
    }
    return -1;
    }
};