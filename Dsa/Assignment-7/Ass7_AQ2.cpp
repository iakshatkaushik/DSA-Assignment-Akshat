#include <iostream>
using namespace std;

class TopK {
public:
    void solve(int a[], int n, int k) {
        int freq[1001]={0};
        int unique[1001], u=0;

        for(int i=0;i<n;i++){
            if(freq[a[i]]==0) unique[u++]=a[i];
            freq[a[i]]++;
        }

        for(int i=0;i<k;i++){
            int best=i;
            for(int j=i+1;j<u;j++){
                if(freq[unique[j]] > freq[unique[best]] ||
                   (freq[unique[j]] == freq[unique[best]] && unique[j] > unique[best])) {
                    best = j;
                }
            }
            int t = unique[i];
            unique[i] = unique[best];
            unique[best] = t;
        }

        for(int i=0;i<k;i++) cout << unique[i] << " ";
    }
};

int main(){
    int n,a[100],k;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>k;
    TopK obj;
    obj.solve(a,n,k);
}
