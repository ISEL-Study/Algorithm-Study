#include <iostream>
#include <queue>

using namespace std;

int check(int s, int a, int b, int c, int d) {
    int chess[s][s]; //값으로 ID지정
    int visit[s][s]; //방문여부  1:방문함, 0: 방문안함
    int finally=0;
    queue<pair<int, int>> que;

    for (int i=0;i<s;i++) {
        for (int j=0;j<s;j++) {
            chess[i][j] = 0;
            visit[i][j] = 0;
        }
    }

    visit[a][b] = 1; // 방문O
    chess[a][b] = 0; // ID = 0

    que.push(make_pair(a, b));

    while(!que.empty()) {
        int A = que.front().first;
        int B = que.front().second;

        que.pop(); 

        if (A == c && B == d) {
            finally = chess[A][B];
            //cout << "A: " << A << " B: " << B << " ID: " <<chess[A][B];
            break;
        }
        // 1
        if (A+1>=0 && B+2>=0 && A+1<s && B+2<s && visit[A+1][B+2] == 0) {
            que.push(make_pair(A+1, B+2));
            visit[A+1][B+2] = 1;
            chess[A+1][B+2] = chess[A][B]+1;
        }
        // 2
        if (A+2>=0 && B+1 >0 && A+2<s && B+1<s && visit[A+2][B+1] == 0) {
            que.push(make_pair(A+2, B+1));
            visit[A+2][B+1] = 1;
            chess[A+2][B+1] = chess[A][B]+1;
        }
        // 3
        if (A+2>=0 && B-1>=0 && A+2<s && B-1<s && visit[A+2][B-1] == 0) {
            que.push(make_pair(A+2, B-1));
            visit[A+2][B-1] = 1;
            chess[A+2][B-1] = chess[A][B]+1;
        }
        // 4
        if (A+1>=0 && B-2>=0 && A+1<s && B-2<s && visit[A+1][B-2] == 0) {
            que.push(make_pair(A+1, B-2));
            visit[A+1][B-2] = 1;
            chess[A+1][B-2] = chess[A][B]+1;
        }
        // 5
        if (A-1>=0 && B-2>=0 && A-1<s && B-2<s && visit[A-1][B-2] == 0) {
            que.push(make_pair(A-1, B-2));
            visit[A-1][B-2] = 1;
            chess[A-1][B-2] = chess[A][B]+1;
        }
        // 6
        if (A-2>=0 && B-1>=0 && A-2<s && B-1<s && visit[A-2][B-1] == 0) {  
            que.push(make_pair(A-2, B-1));
            visit[A-2][B-1] = 1;
            chess[A-2][B-1] = chess[A][B]+1;
        }
        // 7
        if (A-2>=0 && B+1>=0 && A-2<s && B+1<s && visit[A-2][B+1] == 0) {
            que.push(make_pair(A-2, B+1));
            visit[A-2][B+1] = 1;
            chess[A-2][B+1] = chess[A][B]+1; // 맞나...
        }
        // 8
        if (A-1>=0 && B+2>=0 && A-1<s && B+2<s && visit[A-1][B+2] == 0) { 
            que.push(make_pair(A-1, B+2));
            visit[A-1][B+2] = 1;
            chess[A-1][B+2] = chess[A][B]+1;
        }
        
        //cout << que.front().first << " " << que.front().second << " ID: " << chess[que.front().first][que.front().second] << endl;

    }

    //cout << "finally: " << finally << endl;
    return finally;
}
// chess[][]로 ID 설정하기

int main() {
    int number, count=0;
    int size, startX, startY, arriveX, arriveY;
    int total=0;

    cin >> number;
    int result[number];

    while (count != number) {
        cin >> size;

        cin >> startX >> startY;
        cin >> arriveX >> arriveY;

        total = check(size, startX, startY, arriveX, arriveY);

        result[count] = total;

        count++;
    }

    for (int i=0;i<number;i++) {
        cout << result[i] << endl;
    } 

    return 0;

}