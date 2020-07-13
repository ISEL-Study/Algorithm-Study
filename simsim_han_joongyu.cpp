#include <iostream>
#define MAX 1000

using namespace std;


int main() {
	int length;
	int dec;
	char buffer[MAX];

	cin >> length;


	for (int i = 0; i < length; i++) {
		buffer[0] = 0;
		cin >> buffer;

		dec = strtol(buffer, NULL, 16);

		if ((dec >= 16 && dec <= 25) || (dec >= 22 && dec <= 31))
			printf(".");
		else
			printf("-");
	}


	// '.' = 2E, ' ' = 20 (hex)
	// '.' = 46, ' ' = 32 (dec)
}