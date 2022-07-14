#include<iostream>
#include<string>
using namespace std;

string reverse(string str,int e, int s){
    if(s>e){
        return str;
    }
    swap (str[s],str[e]);
    return reverse(str, e-1, s+1);
}

int main(){
    string s= "Hello";
    cout<<reverse(s, s.size()-1,0);
}