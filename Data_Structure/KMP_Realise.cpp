#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> getPM(string Pattern);
string Text="ababcabcacbab";
string Pattern="abc";
int n=Text.length();
int m=Pattern.length();

int main(){
    int i=0,j=0;
    vector<int> PM=getPM(Pattern);
    for(int k=0;k<PM.size();k++){
        cout<<PM[k]<<endl;
    }
    vector<int> next(PM);
    next[0]=0;
    for(int q=1;q<next.size();q++){
        next[q]=PM[q-1]+1;
    }
    while(i<n&&j<m){
    if(Text[i]==Pattern[j]){
        i++;
        j++;
    }else{
        if(j>0){
            j=next[j]-1;
        }else{
            i++;}}}
    if(j==m){
        cout<<"Search Success!"<<endl;
        cout<<"The index is:"<<i-j<<endl;
    }else{
        cout<<"Search Failed!"<<endl;
    }
    return 0;
}
vector<int> getPM(string Pattern){
    vector<int> PM;
    int mlength=Pattern.length();
    if(mlength!=0){
        PM.resize(mlength);
        PM[0]=0; 
    }
    int i=1,j=0;
    while(i<mlength){
        if(Pattern[i]==Pattern[j]){
            j++;
            PM[i]=j;
            i++;
        }else if(j>0){
            j=PM[j-1];
        }else{
                PM[i]=0;
                i++;
        }
    }
       
    return PM;
}
