#include<iostream>
#include<stack>
#include<string>
using namespace std;

int precedence(char c){
    if(c=='^') return 3;
    else if(c=='*' || c=='/' ) return 2;
    else if(c=='+' || c=='-' ) return 1;
    else return -1;
}
string infix_to_postfix(string str1)
{
    stack<char> s;
    string postfix;
    int len=str1.size();
    for(int i=0;i<len;i++){
        if((str1[i]>='a' && str1[i]<='z') ||
        (str1[i]>='A' && str1[i]<='Z')) postfix+=str1[i];
        else if(str1[i]=='(') s.push(str1[i]);
        else if(str1[i]==')'){
            while(!(s.empty()) && s.top()!='('){
                postfix+=s.top();
                s.pop();
            }
            s.pop();
        }
        else {
            while(!(s.empty()) &&
             (precedence(s.top())>=precedence(str1[i]))){
                postfix+=s.top();
                s.pop();
            }
            s.push(str1[i]);
        }
    }
        while(!(s.empty())){
            postfix+=s.top();
            s.pop();
        }
    return postfix;
}
int main()
{
std::ios_base::sync_with_stdio(false);
    string str="A-(B*C)+(D/E)";
    string str2=infix_to_postfix(str);
    cout<<str2;
    return 0;
}