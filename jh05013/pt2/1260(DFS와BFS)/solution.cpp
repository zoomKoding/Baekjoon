#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <queue>

using namespace std;

int N, M, src, v1, v2;

void dfs(int s, int** arr, bool* visited, int count){
    visited[s] = 1;
    printf("%d ", s);
    for(int i = 1; i < N+1; i++){
        if(i == s)continue;
        if(arr[s][i] == 1 && visited[i] == 0) dfs(i, arr, visited, count+1);
    }
}



void bfs(int s, int** arr, bool* visited, int count){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        int temp = q.front();
        printf("%d ", temp);
        q.pop();
        for(int i = 1 ; i < N+1 ; i++){
            if(arr[temp][i] == 1 && !visited[i] && i != temp ){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}


int main(){
    bool visited[1001] = {0,};
    
    scanf("%d %d %d", &N, &M, &src);
    int** arr = new int*[N+1];
    for(int i = 0; i < N+1; i++){
        arr[i] = new int[N+1];
        for(int j = 0; j < N; j++)arr[i][j] = 0;
    }

    for(int i = 0; i < M; i++){
        scanf("%d %d", &v1, &v2);
        arr[v1][v2] = arr[v2][v1] = 1;
    }
    
    dfs(src, arr, visited, 0);
    printf("\n");
    for(int i = 0; i < N+1; i++)visited[i] = 0;
    bfs(src, arr, visited, 0);

    return 0;
}