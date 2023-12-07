#include <iostream>
#include <string>
#include <stack>
using namespace std;
//================================================================
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
//==================================================================
bool is_digit(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')|| (c >= '0' && c <= '9');
}
//==================================================================
string infixToPostfix(string s)
{
    stack<char> st;
    string Postfix;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (is_digit(c))
            Postfix += c;
        else if (c == '(')
            st.push('(');
        else if (c == ')') {
            while (st.top() != '(') {
                Postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty()&& prec(s[i]) <= prec(st.top())) {
                Postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        Postfix+= st.top();
        st.pop();
    }
    return Postfix;
}
//====================================================================
int main()
{
     string infix;
     cout<<"please enter your operation_ ";
     cin>>infix;
     cout<<"your operation in Postfix_ "<< infixToPostfix(infix);
    return 0;
}
