#include "../lib_stack/TStack.h"

bool is_valid(const std::string& str) {
    TStack<char> stack(str.size());

    for (char c : str) {
        if (c == '(' || c == '[' || c == '{' || c == '|') {
            stack.push(c);
        }
        else if (c == ')' || c == ']' || c == '}' || c == '|') {
            stack.top();

            if (stack.isEmpty()) {
                return false;
            }
            char top = stack.top();
            stack.pop();

            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{') || (c == '|' && top != '|')) {
                return false;
            }
        }
    }
    return true;
}