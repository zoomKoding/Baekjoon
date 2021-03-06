#include <cstdio>
#include <queue>

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

typedef struct Point{
    int x, y;
    Point(int i, int j){
        x = i;
        y = j;
    }

}Point;

using namespace std;

int board[300][300];
int d[8][2] = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}, {1, -2}, {2, -1}};
int n, m, sx, sy, dx, dy;

int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%d %d %d %d %d", &m, &sx, &sy, &dx, &dy);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++) board[i][j] = 0;
        }
        if(sx == dx && sy == dy) {
            printf("0\n");
            continue;
        }
        queue<Point> q;
        q.push(Point(sx, sy));
        while(!q.empty()){
            Point p = q.front(); q.pop();
            if(p.x == dx && p.y == dy) break;
            int c = board[p.x][p.y];
            for(int i = 0; i < 8; i++){
                int X = p.x + d[i][0], Y = p.y + d[i][1];
                if(X < 0 || Y < 0 || X >= m || Y >= m) continue;
                if(board[X][Y] != 0) continue;
                board[X][Y] = c + 1;
                q.push(Point(X, Y));
            }
        }
        printf("%d\n", board[dx][dy]);
    }
}