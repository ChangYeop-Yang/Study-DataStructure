#include <vector>
#include <iostream>
using namespace std;

void counting(int number, int sum, int * count) {

	const vector<int> bucket = {1, 2, 3};

	if (sum == number) { (*count)++; sum = 0; return; }
	if (sum > number) { sum = 0; return; }

	for (int ii = 0, length = bucket.size(); ii < length; ii++) {
		counting(number, sum + bucket[ii], count);
	}
}

int main(void)
{
	int testcase = 0;
	cin >> testcase;

	for (int ii = 0; ii < testcase; ii++) {
		
		int input = 0;
		cin >> input;

		int count = 0;
		counting(input, 0, &count);

		cout << count << endl;
	}

	return 0;
}