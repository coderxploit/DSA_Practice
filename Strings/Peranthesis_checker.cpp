// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char>st;
        if(x.length()<=1) return false;
        
        for(int i = 0;i<x.length();i++){
            if(x[i]=='{' || x[i]=='(' || x[i]=='['){
                if(x[i]=='{'){
                    st.push('}');
                }
                if(x[i]=='('){
                    st.push(')');
                }
                if(x[i]=='['){
                    st.push(']');
                }
                
            }
            else
            {
                if(!st.empty()&&st.top()==x[i]){
                    st.pop();
                }
                else return false;
            }
        }
        return st.empty();
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends