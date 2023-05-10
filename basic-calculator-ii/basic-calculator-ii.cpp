class Solution {
public:
    int precedence(char c){
        if(c == '*' || c == '/') return 2;
        else return 1;
    }
    string toPost(string s){
        string post = "";
        stack<int> st;
        int n = s.length();
        for(int i =0; i<n; i++){
            if(s[i] == ' ') continue;
            else if(isdigit(s[i])){
                post += s[i];
            }
            else{
                post += '|';
                while(st.size() && precedence(st.top()) >= precedence(s[i])){
                    post += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        post += '|';
        while(st.size() && precedence(st.top())){
                    post += st.top();
                    st.pop();
                }
        return post;
        
    }
    
    int calculatePost(string s){
        int ans = 0;
        long long int curr = 0;
        int n = s.length();
        stack<int> st;
        for(int i = 0; i<n; i++){
            if(isdigit(s[i])) curr = 10*curr + s[i] - '0';
            else if(s[i] == '|'){
                st.push(curr);
                curr = 0;
            }
            else{
                int curr1 = st.top();
                st.pop();
                int curr2 = st.top();
                st.pop();
                if(s[i] == '+') st.push(curr1 + curr2);
                else if(s[i] == '-') st.push(curr2 - curr1 );
                else if(s[i] == '*') st.push(curr1 * curr2);
                else st.push(curr2/curr1);
            }
        }
        
        return st.top();
    }
    int calculate(string s) {
        string post = toPost(s);
        int ans = calculatePost(post);
        return ans;
    }
};