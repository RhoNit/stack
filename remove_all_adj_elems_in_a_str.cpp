class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++) {
            if(st.size() > 0 and st.top() == s[i]) st.pop();
            else st.push(s[i]);
        }

        string res;
        while(st.size() > 0) {
            char ch = st.top();
            st.pop();
            res += ch;
        }

        reverse(res.begin(), res.end());

        return res;
    }
};