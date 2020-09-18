#include <bits/stdc++.h>
using namespace std ;

void fasterIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0) ;
}
int Upper_Bound(int v1[] , int left , int right , int key) {
    while(left <= right) {
        int mid = (left + right) / 2 ;
        if(v1[mid] <= key) 
            left = mid + 1 ;
        else
            right = mid - 1 ;
    }
    return left ;       
}
int main() {
    fasterIO() ;
    int n , m ;
    cin >> n >> m ;
    int v1[n + 5] , v2[m + 5] ; 
    for(int i = 0 ; i < n ; i++) 
        cin >> v1[i] ;
    for(int i = 0 ; i < m ; i++) 
        cin >> v2[i] ;
    sort(v1 , v1 + n) ;
    for(int i = 0 ; i < m ; i++) {
        int key = v2[i] ;
        int ans = Upper_Bound(v1 , 0 , n - 1 , key) ;
        cout << ans << " " ;
    }
    cout << "\n" ;
    return 0 ;
}