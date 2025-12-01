#include <iostream>
using namespace std;

class Majority {
public:
    int majorityElement(int a[], int n) {
        int cand = a[0], count = 1;

        for (int i=1;i<n;i++) {
            if (a[i] == cand) count++;
            else count--;
            if (count == 0) {
                cand = a[i];
                count = 1;
            }
        }
        return cand;
    }
};

int main() {
    int n, a[100];
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    Majority obj;
    cout << obj.majorityElement(a,n);
}
