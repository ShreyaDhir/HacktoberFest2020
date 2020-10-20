#include<iostream>
#include<string>
#include<stack>

using namespace std;

string isBalanced(string str){
    stack<char> st;

    for(auto c:str){
        switch(c){
            case '{':
            case '(':
            case '[':
                st.push(c);
                break;
            case '}':
                    if(st.empty() || st.top()!='{'){
                    return "NO";
                }
                st.pop();
                break;

            case ')':
                if(st.empty() || st.top()!='('){
                    return "NO";
                }
                st.pop();
                break;

            case ']':
                if(st.empty() || st.top()!='['){
                    return "NO";
                }
                st.pop();
                break;
        }
    
    }
    return st.empty()? "YES" : "NO";
}

int main(){
    string s;
    cout<<"Enter the string of parenthesis: ";
    cin>>s;
    cout<<"Ques. Is string of parenthesis balanced?"<<endl;
    cout<<"Ans. "<<isBalanced(s)<<endl;
}