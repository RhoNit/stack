class TextEditor {
private:
    stack<char> left_of_cursor, right_of_cursor;
public:
    TextEditor() {
        
    }
    
    void addText(string text) {
        for(auto letter: text) left_of_cursor.push(letter);
        return;
    }
    
    int deleteText(int k) {
        int counter = 0;

        // scenario 1 - When no. of chars in the left side of cursor < k, in that case left stack would be emptied
        // scenario 2 - When no. of chars in the left side of cursor > k, then stack won't be emptied
        while(left_of_cursor.size() > 0 and counter < k) {
            left_of_cursor.pop();
            counter++;
        }

        return counter; // returning the count of letters got deleted or backspaced
    }
    
    string cursorLeft(int k) {
        while(left_of_cursor.size() > 0 and k--) {
            int cursor_at_char = left_of_cursor.top();
            left_of_cursor.pop();
            right_of_cursor.push(cursor_at_char);
        }

        return getLeftStrOfCursor();
    }

    string getLeftStrOfCursor() {
        stack<char> st = left_of_cursor;
        string res = "";

        // maintaining a counter - As there are 2 scenarios
        // scene 1: len(leftStrOfCursor) < 10
        // scene 2: len(leftStrOfCursor) >= 10
        // and we need to return the min(10, len(leftStrOfCursor))
        int counter = 0;
        while(st.size() > 0 and counter < 10) {
            res += st.top();
            st.pop();
            counter++;
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
    
    string cursorRight(int k) {
        while(right_of_cursor.size() > 0 and k--) {
            int cursor_at_char = right_of_cursor.top();
            right_of_cursor.pop();
            left_of_cursor.push(cursor_at_char);
        }

        return getLeftStrOfCursor();
    }
};
