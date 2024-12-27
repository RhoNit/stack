class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();

        for(int i = 0; i < n; i++) {
            // check if there is any already processed char/digit
            // which is greater than current char/digit.. if found pop it from the stack till `k` times
            // afterall we are removing all possible larger digits from the stack
            while(st.size() > 0 and k > 0 and st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        // special case 1 - When the digits in input are already in ASC order,
        // we need to remove the larger digits from the end 
        while(k > 0) {
            st.pop();
            k--;
        }

        // now pop the digits from the stack and store those in a resultant string
        string res = "";
        while(st.size() > 0) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        
        // special case 2 - Remove the leading 0s
        int i = 0;
        while(i < res.size() and res[i] == '0') i++;

        // finally we are at a position where no leading 0s are there
        // so new resultant string would be from that posn i.e. `i` to the rest of the length
        res = res.substr(i); // position == i, length == from to last index of the string

        return (res.size() == 0) ? "0" : res;
    }
};