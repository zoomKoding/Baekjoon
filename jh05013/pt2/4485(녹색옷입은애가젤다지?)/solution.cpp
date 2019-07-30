#include <cstdio>
#include <queue>
using namespace std;

typedef struct Point{
    int x, y, w;
    bool operator<(const Point& o)const {
		return w > o.w;
	}
}Point;

char buf[1 << 17];

inline char read() {
	static int idx = 1 << 17;
	if (idx == 1 << 17) {
		fread(buf, 1, 1 << 17, stdin);
		idx = 0;
	}
	return buf[idx++];
}
inline int readInt() {
	int sum = 0;
	bool flg = 1;
	char now = read();

	while (now == 10 || now == 32) now = read();
	if (now == '-') flg = 0, now = read();
	while (now >= 48 && now <= 57) {
		sum = sum * 10 + now - 48;
		now = read();
	}

	return flg ? sum : -sum;
}


int main(){
    int d[4][2] = { {0,1}, {1,0}, {-1,0}, {0, -1} };
    int dist[126][126];
    int cave[126][126];
    int n, x, y, cnt = 0;
    while(1){
        cnt++;
        n = readInt();
        if(!n)break;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cave[i][j] = readInt();
                dist[i][j] = 2000;
            }
        }
        priority_queue<Point> q;
        dist[0][0] = cave[0][0];
        q.push({0,0, dist[0][0]});
        while(!q.empty()){ 
            Point front = q.top(); q.pop();
            for(int i = 0; i < 4; i++){
                x = front.x + d[i][0], y = front.y + d[i][1];
                if(x >= n || y >= n || x < 0 || y < 0)continue;
                if(dist[x][y] > dist[front.x][front.y] + cave[x][y]){
                    dist[x][y] = dist[front.x][front.y] + cave[x][y];
                    q.push({x, y, dist[x][y]});
                } 
            }
        }
        printf("Problem %d: %d\n", cnt, dist[n-1][n-1]);
    } 
}