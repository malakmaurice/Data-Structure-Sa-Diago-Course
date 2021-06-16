#include <iostream>
#include<fstream>
#include<vector>
#include <stdlib.h>
using namespace std;
long long THash[1000000];
vector<int>result;
long long prim=1e9 + 9;
int x =31;
long long PolyHash(string P)
{
    long long h=0;
    for(int i=P.length()-1; i>=0; i--)
        h=((h * x+P[i])%prim+prim)%prim;
    return h;
}
void PrecomputeHashes(string T,int len,int txtLen)
{
    string s=T.substr(txtLen-len,txtLen-1);
    THash[txtLen-len]=PolyHash(s);
    int y=1;
    for(int i=1; i<=len; i++)
        y=(y*x)%prim;
    for(int i= txtLen-len-1; i>=0; i--)
        THash[i]=((x*THash[i+1])%prim+(T[i])%prim-(y*T[i+len])%prim+prim)%prim;
}
void RabinKarp(string T,string P,int txtLen,int patLen)
{
    result.clear();
    bool flag = true;
    long long PHash=PolyHash(P);
    //cout<<"PHash = "<<PHash<<"\n";
    PrecomputeHashes(T,patLen,txtLen);
    for(int i=0; i<=txtLen-patLen; i++)
    {
        flag=true;
        //cout<<"THash"<< i<<" = "<<THash[i]<<"\n";
        if(PHash!=THash[i])
            continue;
        for(int j=0; j<patLen; j++)
        {
            if(P[j]!=T[i+j])
            {
                flag=false;
                break;
            }
        }
        if(flag)
            result.push_back(i);
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
    int n,txtLen,patLen;
    string T,P;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n;
    while(n--)
    {
        cin>>T>>P;
        patLen=P.length();
        txtLen=T.length();
        // cout<<T<<" "<<P<<"\n";
        if(txtLen>=patLen)
            RabinKarp(T,P,txtLen,patLen);
        else
            cout<<"Not Found";
        cout<<"\n";
    }
    return 0;
}
