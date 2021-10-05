#include <iostream>
#include <functional>

using namespace std;

void generateAllBinaryAndConsume(int n, function<void(string)> consumer, string bits = "") {
	if (n <= 0) {
		consumer(bits);
	} else {
		generateAllBinaryAndConsume(n - 1, consumer, bits + "0");
		generateAllBinaryAndConsume(n - 1, consumer, bits + "1");
	}
}
// 10101
string toGrayCode(const string &bits) {
	string grayCode(bits.length(), bits[0]);
	for (unsigned int i = 1; i < bits.length(); i++) {
		grayCode[i] = bits[i] != bits[i - 1]? '1': '0'; 
	}
	return grayCode;
}

int main() {
	int n;
	cin >> n;
	generateAllBinaryAndConsume(n, [&](const string &bits){
		cout << toGrayCode(bits) << endl;
	});
	return 0;
}