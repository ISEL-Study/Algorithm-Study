#include <iostream>
#include <queue>

using namespace std;

int main() {
	int case_nbr;
	int length, currentX, currentY, wantX, wantY;
	int x, y, flag;
	int a[301][301];
	cin >> case_nbr;


	for (int i = 0; i < case_nbr; i++) {
		cin >> length;
		cin >> currentX >> currentY >> wantX >> wantY;

		queue<pair<int, int>> q;
		fill(a[0], a[300], 0);

		q.push(make_pair(currentX, currentY));
		a[currentX][currentY] = 1;
		flag = 0;


		while (!q.empty()) {
			x = q.front().first;
			y = q.front().second;

			q.pop();

			if (x == wantX && y == wantY) {
				cout << a[x][y] - 1 << "\n";
				flag = 1;
				break;
			}


			//(2,1)
			if (x + 2 < length && y + 1 < length && a[x + 2][y + 1] == 0) {
				q.push(make_pair(x + 2, y + 1));
				a[x + 2][y + 1] = a[x][y] + 1;
			}

			//(2, -1)
			if (x + 2 < length && y - 1 >= 0 && a[x + 2][y - 1] == 0) {
				q.push(make_pair(x + 2, y - 1));
				a[x + 2][y - 1] = a[x][y] + 1;
			}

			//(1, 2)
			if (x + 1 < length && y + 2 < length && a[x + 1][y + 2] == 0) {
				q.push(make_pair(x + 1, y + 2));
				a[x + 1][y + 2] = a[x][y] + 1;
			}

			//(1, -2)
			if (x + 1 < length && y - 2 >= 0 && a[x + 1][y - 2] == 0) {
				q.push(make_pair(x + 1, y - 2));
				a[x + 1][y - 2] = a[x][y] + 1;
			}

			//(-2, -1)
			if (x - 2 >= 0 && y - 1 >= 0 && a[x - 2][y - 1] == 0) {
				q.push(make_pair(x - 2, y - 1));
				a[x - 2][y - 1] = a[x][y] + 1;
			}

			//(-2, 1)
			if (x - 2 >= 0 && y + 1 < length && a[x - 2][y + 1] == 0) {
				q.push(make_pair(x - 2, y + 1));
				a[x - 2][y + 1] = a[x][y] + 1;
			}

			//(-1, 2)
			if (x - 1 >= 0 && y + 2 < length && a[x - 1][y + 2] == 0) {
				q.push(make_pair(x - 1, y + 2));
				a[x - 1][y + 2] = a[x][y] + 1;
			}

			//(-1, -2)
			if (x - 1 >= 0 && y - 2 >= 0 && a[x - 1][y - 2] == 0) {
				q.push(make_pair(x - 1, y - 2));
				a[x - 1][y - 2] = a[x][y] + 1;
			}
		}
		
		if (q.empty() && flag == 0)
			cout << a[wantX][wantY] << "\n";

	}
}
