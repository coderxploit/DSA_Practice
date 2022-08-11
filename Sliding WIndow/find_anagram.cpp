/*
*fixed sliding window
*avoid complete hashmap traversal multiple times

*/

/*438. Find All Anagrams in a String*/

#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

vector<int> findAnagram(string s1,string s2){
    vector<int> ans;
    unordered_map<char, int>ht;
    for(auto x: s2){
        ht[x]++;
    }
    int window = ht.size();
    int count = ht.size();
    int i = 0, j = 0;
    while(j<s1.size()){
        if(ht.find(s1[j])!=ht.end()){
            ht[s1[j]]--;
            if(ht[s1[j]] == 0){
                count --;
            }
        }

        //if window sizenot achieved

        if(j-i+1 != window){
            j++;
        }
        else if(j-i+1 == window){
            if(count == 0){
                ans.push_back(i);
            }
            if(ht.find(s1[i])!= ht.end()){
                ht[s1[i]]++;
                if(ht[s1[i]]==1){
                    count++;
                }
            }
            i++;
            j++;
        }
    }
    return ans;

}

/*
vector<int> findAnagram(string s,string p){
vector<int> ans;
        vector<int> hash(26, 0);
        vector<int> phash(26, 0);
        int window = p.size();
        int len = s.size();
        if(len < window)
        {
            return ans;
        }
        int left = 0,right = 0;
        while(right < window)
        {
            phash[p[right] - 'a'] += 1;
            hash[s[right] - 'a'] += 1;
            right++;
        }
        right -=1;
        while(right < len)
        {
            if(phash == hash)
            {
                ans.push_back(left);
            }
            right+=1;
            if(right != len)
            {
                hash[s[right] - 'a'] += 1;
            }
            hash[s[left] - 'a'] -=1 ;
            left += 1;
        }
        return ans;
    }
*/
int main(){
    string s1 = "cbaebabacd";
    string s2 = "abc";

    vector<int> ans = findAnagram(s1, s2);
    
    for(auto x : ans){
        cout<<x<<", "<<endl;
    }
    return 0;
}