#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0)
        {
            return false;
        }
        string s=to_string(x);
        vector<int> result;
        for (int i=0;i<s.length();i++){
            result.push_back(s[i]-'0');
        }
        vector<int> result2=result;
        reverse(result2.begin(),result2.end());

        bool flag=true;
        for(int m=0;m<s.length();m++){
            if(result[m]!=result2[m]){
               flag=false;
        }
    }
        if (flag==true)
        {
            return true;
        }else
        {
            return false;
        }
    }
};

int main(){
    int a;
    cin>>a;
    Solution sol;
    cout<<( sol.isPalindrome(a)? "true":"false")<<endl;
    return 0;
}
