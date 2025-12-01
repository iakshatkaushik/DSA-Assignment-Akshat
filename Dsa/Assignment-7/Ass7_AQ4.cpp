#include <iostream>
using namespace std;

class EvenOddSort {
public:
    void solve(int a[], int n) {
        int even[100], e=0, odd[100], o=0;

        for(int i=0;i<n;i++){
            if(i%2==0) even[e++] = a[i];
            else odd[o++] = a[i];
        }

        for(int i=0;i<e;i++){
            int best=i;
            for(int j=i+1;j<e;j++)
                if(even[j] < even[best]) best=j;
            int t=even[i]; even[i]=even[best]; even[best]=t;
        }

        for(int i=0;i<o;i++){
            int best=i;
            for(int j=i+1;j<o;j++)
                if(odd[j] > odd[best]) best=j;
            int t=odd[i]; odd[i]=odd[best]; odd[best]=t;
        }

        int idx=0;
        for(int i=0;i<e;i++) cout << even[i] << " ";
        for(int i=0;i<o;i++) cout << odd[i] << " ";
    }
};

int main(){
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    EvenOddSort obj;
    obj.solve(a,n);
}
