#include <cstdio>
#include <algorithm>
using namespace std;

int m, x, n, v1, v2, ans = 987654321, visited[251], w1[251], w2[251];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &w1[i], &w2[i]);
        v1 += w1[i];
    }
    m = v1;
    while(1){
        int temp = m;
        for(int i = 1; i <= n; i++){
            if(visited[i])continue;
            if(w1[i] < w2[i])continue;
            v1 -= w1[i], v2 += w2[i];
            if(max(v1, v2) < temp)temp = max(v1, v2), x = i;
            v1 += w1[i], v2 -= w2[i];
        }
        if(temp == m)break;
        visited[x] = 1;
        v1 -= w1[x], v2 += w2[x]; 
        m = temp;
    }
    
    printf("%d", m);
}