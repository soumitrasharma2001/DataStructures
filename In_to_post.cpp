#include <iostream>
#include <map>
#include <stack>
using namespace std;
class InToPost{
    public:
    string exp; 
    InToPost(string s){
       exp=s;
    }
    string InfixToPostfix(){
        map<char,int> pri;
        pri['/']=2;
        pri['*']=2;
        pri['+']=1;
        pri['-']=1;
        stack<char> stk;
        string result;
       for(int i=0;i<exp.length();i++){
        if((exp[i]>='a'&& exp[i]<='z')||(exp[i]>='A'&& exp[i]<='Z')){
           result.push_back(exp[i]);
        }
        else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'){
           if(stk.empty()){
            stk.push(exp[i]);
           }
           else if(pri[exp[i]]<=pri[stk.top()]){
              result.push_back(stk.top());
              stk.pop();
              while(pri[exp[i]]<=pri[stk.top()]){
                if(pri[exp[i]]<=pri[stk.top()]){
                    result.push_back(stk.top());
                    stk.pop();
                }
              }
              stk.push(exp[i]);
           }
           else{
            stk.push(exp[i]);
           }
        }
       }
       while(!stk.empty()){
        result.push_back(stk.top());
        stk.pop();
       }
       return result;
    }
};
int main(){
    InToPost a("a+a/b+b/c+d");
    cout<<a.InfixToPostfix();
    return 0;
}