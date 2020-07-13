#include <iostream>
#define MAX 1000

using namespace std;

int main() {
	int n, k;
	int count = 0;

	cin >> n >> k;

	int arr[MAX] = { 0, };

	for (int i = 0; i <= n - 2; i++) {
		arr[i] = 2 + i;
	}

	for (int i = 0; i <= n - 2; i++) {
		if (arr[i] != 0) {
			int nbr = arr[i];
			int idx = arr[i] - 2;

			for (int t = idx; t <= n - 2; t += nbr) {
				if (arr[t] != 0) {
					count++;
					printf("count = %d, arr[%d] = %d\n", count, t, arr[t]);

					if (count == k) {
						printf("%d\n", arr[t]);
					}

					arr[t] = 0;	//delete
				}
			}
		}
	}
}