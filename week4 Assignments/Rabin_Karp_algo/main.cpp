#include <iostream>
#include<fstream>
#include<vector>
#include <stdlib.h>
using namespace std;
vector<int>result;
long long prim=1e9 + 9;
int x =31,j;
long long power=1;
long long PolyHash(string str,int start,int len)
{
    long long h=0;
    for(int i=start; i<start+len; i++)
        h=(x * h+str[i])%prim;
    h= (h+prim)%prim;
    return h;
}
void powe(int len)
{
    for(int i=0; i<len-1; i++)
        power*=x;
}
void RabinKarp(string txt,string pat,int txtLen,int patLen)
{
    result.clear();
    powe(patLen);
    long long patHash=PolyHash(pat,0,patLen);
    long long txtHash=PolyHash(txt,0,patLen);
    //cout<<"PHash = "<<PHash<<"\n";
    for(int i=0; i<=txtLen-patLen; i++)
    {
        if(patHash==txtHash)
        {
            for(j=0; j<patLen; j++)
            {
                if(pat[j]!=txt[i+j])
                    break;
            }
            if(j==patLen)
                result.push_back(i);
        }
        if(i<txtLen-patLen)
        {
            txtHash=(x*(txtHash-txt[i]*power))+txt[i+patLen];
            txtHash=(txtHash+prim)%prim;
        }
    }
    if(result.size())
    {
        cout<<result.size()<<"\n";
        for(int i=0; i<result.size(); i++)
            cout<<result[i]+1<<" ";
        cout<<"\n";
    }
    else
    {
        cout<<"Not Found";
        cout<<"\n";
    }
}
int main()
{
    int n;
    int txtLen,patLen;
    string txt,pat;

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n;
    while(n--)
    {
        cin>>txt>>pat;
        txtLen=txt.length();
        patLen=pat.length();
        if(txtLen>=patLen)
            RabinKarp(txt,pat,txtLen,patLen);
        else
            cout<<"Not Found";
        cout<<"\n";
    }
    return 0;
}
