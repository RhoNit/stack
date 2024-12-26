class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int> st1, st2;

        for(auto ch: s) {
            if(st1.size() > 0 and ch == '#') st1.pop();
            else if(ch != '#') st1.push(ch);
        }

        string s1;
        while(st1.size() > 0) {
            s1 += st1.top();
            st1.pop();
        }

        for(auto ch: t) {
            if(st2.size() > 0 and ch == '#') st2.pop();
            else if(ch != '#') st2.push(ch);
        }

        string s2;
        while(st2.size() > 0) {
            s2 += st2.top();
            st2.pop();
        }

        return (s1 == s2) ? true : false;
    }
};