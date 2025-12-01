#include <iostream>
using namespace std;

class IceCream {
public:
    int maxIceCream(int a[], int n, int coins) {
        int freq[100001]={0};
        int maxi=0;

        for(int i=0;i<n;i++){
            freq[a[i]]++;
            if(a[i] > maxi) maxi=a[i];
        }

        int count=0;
        for(int cost=1; cost<=maxi; cost++){
            while(freq[cost] > 0 && coins >= cost){
                coins -= cost;
                freq[cost]--;
                count++;
            }
        }
        return count;
    }
};

int main(){
    int n,a[100],coins;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>coins;
    IceCream obj;
    cout << obj.maxIceCream(a,n,coins);
}
