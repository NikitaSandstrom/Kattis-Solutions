#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    queue<int> q;
    int res=0;

    for (int i=0;i<n;i++) {
        int x;
        cin>>x;
        q.push(x);
        if (q.front()<=q.back()-1000) {
            q.pop();
        }
        int temp=(q.size()+k-1)/k;
        res=max(res,temp);
    }

    cout<<res;
}