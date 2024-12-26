class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st; // we will store <char,freq> pair in stack

        for(int i = 0; i < s.size(); i++) {
            if(st.size() > 0 and st.top().first == s[i]) {
                int freq = st.top().second;
                st.pop();
                st.push({s[i], ++freq});
            }
            else st.push({s[i], 1});

            if(st.size() > 0 and st.top().second == k) st.pop();
        }

        string res;
        while(st.size() > 0) {
            char ch = st.top().first;
            int freq = st.top().second;
            st.pop();

            while(freq--) {
                res += ch;
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};