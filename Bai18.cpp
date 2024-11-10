#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dx[8] = {2, 2, -2, -2, 1, -1, 1, -1};
const int dy[8] = {1, -1, 1, -1, 2, 2, -2, -2};
// ktra xem co vuot qua mang ko
bool ktra(int x,int y, int n, int m){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
// tim so buoc di
int sobuocdi(int x1, int y1, int x2, int y2, int n, int m){
    if(x1==x2 && y1==y2) return 0;

    queue<pair<int, int>> q; 
    vector<vector<int>> visited(n+1,vector<int>(m+1,-1));

    q.push({x1,y1}); 
    visited[x1][y1] = 0; 

    while(!q.empty()){
        auto [x,y] = q.front(); 
        q.pop(); 

        for(int i=0;i<8;i++){
            int ax = x + dx[i];
            int ay = y + dy[i];
            if(ktra(ax,ay,n,m) && visited[ax][ay] == -1){ 
                visited[ax][ay] = visited[x][y] +1; 
                if(ax == x2 && ay == y2) return visited[ax][ay];
                q.push({ax,ay});
            }
        }
    }
    return -1;
}
int main(){
    int x1,y1,x2,y2,n,m;
    cout << "Nhap kich thuoc n*m: "; cin >> n >> m;
    cout << "Nhap toa do x1,y1: "; cin >> x1 >> y1;
    cout << "Nhap toa do x2,y2: "; cin >> x2 >> y2;
    int value = sobuocdi(x1, y1, x2, y2, n, m);
    if(value == -1){
        cout << "-1";
    }
    else{
        cout << value;
    }
}