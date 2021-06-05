#include <iostream>
#include<fstream>
#include<vector>
#include <stdlib.h>
using namespace std;
long long THash[500000];
vector<int>result;
long long prim=1000081;
int x =rand()% prim+1;
long long PolyHash(string P)
{
    long long h=0;
    for(int i=P.length()-1; i>=0; i--)
        h=((h * x+P[i])%prim+prim)%prim;
    return h;
}
void PrecomputeHashes(string T,int len)
{
    string s=T.substr(T.length()-len,T.length()-1);
    THash[T.length()-len]=PolyHash(s);
    int y=1;
    for(int i=1; i<=len; i++)
        y=(y*x)%prim;
    for(int i= T.length()-len-1; i>=0; i--)
        THash[i]=((x*THash[i+1])%prim+(T[i])%prim-(y*T[i+len])%prim+prim)%prim;
}
void RabinKarp(string T,string P)
{

    long long PHash=PolyHash(P);
    //cout<<"PHash = "<<PHash<<"\n";
    PrecomputeHashes(T,P.length());
    for(int i=0; i<=T.length()-P.length(); i++)
    {
      //  cout<<"THash"<< i<<" = "<<THash[i]<<"\n";
        if(PHash!=THash[i])
            continue;
        if(P.compare(T.substr(i,P.length()))==0)
            result.push_back(i);
    }
}
int main()
{
    string T,P;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>P>>T;

    RabinKarp(T,P);
    for(int i=0; i<result.size(); i++)
cout<<result[i]<<" ";
    return 0;
}
