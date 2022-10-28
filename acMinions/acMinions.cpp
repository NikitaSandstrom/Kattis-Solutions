#include<vector>
#include<bits/stdc++.h>
using namespace std;
bool c(pair<int,int>l,pair<int,int>r){return l.second==r.second?l.first<r.first:l.second<r.second;}
int main(){int a,i=0,j=0,k=1,l,h;cin>>a;vector<pair<int,int>>m;for(i;i<a;i++){cin>>l>>h;m.emplace_back(l,h);}sort(m.begin(),m.end(),c);i=m[0].second;for(j;j<a;j++){m[j].first>i?k++,i=m[j].second:0;}cout<<k;}