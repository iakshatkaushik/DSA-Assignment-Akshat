#include <iostream>
using namespace std;

class MaxSumComb {
public:
    void solve(int a[], int b[], int n, int k) {
        int sums[10000], idx=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sums[idx++] = a[i] + b[j];
            }
        }

        for(int i=0;i<k;i++){
            int best=i;
            for(int j=i+1;j<idx;j++){
                if(sums[j] > sums[best]) best=j;
            }
            int t = sums[i];
            sums[i] = sums[best];
            sums[best] = t;
        }

        for(int i=0;i<k;i++) cout << sums[i] << " ";
    }
};

int main(){
    int n,a[100],b[100],k;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    cin>>k;
    MaxSumComb obj;
    obj.solve(a,b,n,k);
}
