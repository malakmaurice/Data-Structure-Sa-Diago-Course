#include <iostream>
#include<fstream>
#include<vector>
#include <stdlib.h>
using namespace std;
long long THash[500000];
vector<int>result;
long long prim=1000081;
long long PolyHash(string p,int x)
{
    long long h=0;
    for(int i=p.length()-1; i>=0; i--)
        h=((h * x+p[i])%prim +prim)%prim;
    return h;
}
void PrecomputeHashes(string T,int len,int x){
    string s=T.substr(T.length()-len,len);
    THash[T.length()-len]=PolyHash(s,x);
    int y=1;
    for(int i=1;i<=len;i++)
        y=((y*x)%prim+prim)%prim;
    for(int i= T.length()-len-1;i>=0;i--)
        THash[i]=(x*THash[i+1]+T[i]-y*T[i+len])%prim;
}
void RabinKarp(string T,string P)
{
    int x =rand()% prim+1;
    long long PHash=PolyHash(P,x);
    PrecomputeHashes(T,P.length(),x);
    for(int i=0; i<T.length()-P.length(); i++)
    {
        if(PHash!=THash[i])
            continue;
        if(P.compare(T.substr(i,P.length()))==0)
            result.push_back(i);
        }
}
int main()
{string T,P;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>P>>T;

RabinKarp(T,P);
for(int i=0;i<result.size();i++)
    cout<<result[i]<<endl;

    return 0;
}
