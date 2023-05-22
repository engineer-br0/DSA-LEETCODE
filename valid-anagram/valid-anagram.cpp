class Solution {
public:
    bool isAnagram(string s, string t) {
        int ar[27] = {0};
        int ar2[27] = {0};
        for(int i = 0; i<s.length(); i++){
            ar[s[i]-'a']++;
        }
        for(int i = 0; i<t.length(); i++){
            ar2[t[i]-'a']++;
        }
        
        for(int i = 0; i<26; i++){
            if(ar[i] != ar2[i]) return false;
        }
        return true;
    }
};