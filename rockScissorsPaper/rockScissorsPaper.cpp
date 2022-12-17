#include <iostream>
#include <string.h>
using namespace std;
int n,r,c,d,i,j,k,f;
char g[101][101],h[101][101];
void a(int i,int j,int ii,int jj){if(i<0||i>=r||j<0||j>=c)return;
if(g[i][j]=='R'&&g[ii][jj]=='S')h[ii][jj]='R';
if(g[i][j]=='S'&&g[ii][jj]=='P')h[ii][jj]='S';
if(g[i][j]=='P'&&g[ii][jj]=='R')h[ii][jj]='P';
}
int main(){
cin>>n;
for(i=0;i<n;i++){
cin>>r>>c>>d;
for(int j=0;j<r;j++){
for(int k=0;k<c;k++){
cin>>g[j][k];
}}
for(f=0;f<d;f++){
memcpy(h,g,sizeof(h));
for(j=0;j<r;j++){
for(k=0;k<c;k++){
a(j,k,j-1,k);
a(j,k,j+1,k);
a(j,k,j,k-1);
a(j,k,j,k+1);
}}
memcpy(g,h,sizeof(h));
}     
for(j=0;j<r;j++){
for(k=0;k<c;k++){
cout<<g[j][k];
}
cout<<endl;
}}}