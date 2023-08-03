#include <iostream>
#include <random>
#include <string>
#include<fstream>
using namespace std;
random_device engine;

void Reset(string str) {
	ofstream outfile1("Yours.txt");
	cout << "";
	outfile1 << "\n";
	cout << endl;
	outfile1.close();
	ofstream outfile2("Dealer.txt");
	cout << "";
	outfile2 << "\n";
	cout << endl;
	outfile2.close();
}

string drow(string str) {
	uniform_int_distribution<unsigned>dist(4, 55);
	int a = dist(engine);
	string b;
	string c;
	if (a / 4 == 1) b = "11", cout << "A,";
	else if (a / 4 == 2)b = "2", cout << "2,";
	else if (a / 4 == 3)b = "3", cout << "3,";
	else if (a / 4 == 4)b = "4", cout << "4,";
	else if (a / 4 == 5)b = "5", cout << "5,";
	else if (a / 4 == 6)b = "6", cout << "6,";
	else if (a / 4 == 7)b = "7", cout << "7,";
	else if (a / 4 == 8)b = "8", cout << "8,";
	else if (a / 4 == 9)b = "9", cout << "9,";
	else if (a / 4 == 10)b = "10", cout << "10, ";
	else if (a / 4 == 11)b = "10", cout << "J,";
	else if (a / 4 == 12)b = "10", cout << "Q,";
	else if (a / 4 == 13)b = "10", cout << "K,";

	if (a % 4 == 0)c = "Spade", cout << "Spade,";
	else if (a % 4 == 1)c = "Herats", cout << "Hearts,";
	else if (a % 4 == 2)c = "Diamond", cout << "Diamond,";
	else if (a % 4 == 3)c = "Clover", cout << "Clover,";
	return b;
}

string outfileYours(string b) {
	ofstream outfile("Yours.txt", ios_base::app);
	cout << "";
	outfile << b << "\n";
	cout << endl;
	outfile.close();
	return b;
}

string outfileDealer(string b) {
	ofstream outfile("Dealer.txt", ios_base::app);
	cout << "";
	outfile << b << "\n";
	cout << endl;
	outfile.close();
	return b;
}

int sumYours(string str) {
	ifstream infile("Yours.txt");
	int num1, sum1 = 0;
	while (infile >> num1) {
		sum1 += num1;
	}
	cout << "あなたのカードの合計" << sum1 << endl;
	if (sum1 < 21)cout << "You can continue to hit\n";
	else if (sum1 == 21)cout << "You have Black Jack!!!\npush stop\n";
	else {
		cout << "You lose\n最初からやり直す→Ctrl+z→Enter2回→F5\n";
		vector<int>v;
		ifstream file("Yours.txt");
		int num;
		while (file >> num)v.push_back(num);
		cout << "あなたのカード" << v.cend() - v.cbegin() << "枚" << endl;
	};
	return num1;
}

int sumDealers(string str) {
	ifstream infile2("Dealer.txt");
	int num2, sum2 = 0;
	while (infile2 >> num2) {
		sum2 += num2;
	}
	cout << "ディーラーのカードの合計" << sum2 << endl;
	if (sum2 > 21) {
		cout << "Dealer Burst\nYou Win!!\n最初からやり直す→Ctrl + z→Enter2回\n";
		vector<int>v;
		ifstream file("Yours.txt");
		int num;
		while (file >> num)v.push_back(num);
		cout << "あなたのカード" << v.cend() - v.cbegin() << "枚" << endl;
	}
	else if (sum2 < 17)cout << "Dealer continue\npush n\n";
	else cout << "Dealer stop\npush vs\n";
	return num2;
}

int main() {
	string str;
	Reset(str);
	cout << "あなたのカード\n";
	for (int i = 1; i <= 2; i++) {
		outfileYours(drow(str));
	}
	cout << "\nディーラーのカード\n";
	outfileDealer(drow(str));
	cout << "\nカードを引く→ hit\n手番を追える→ stop\n\n";
	sumYours(str);
	ifstream infile2("Dealer.txt");
	int num2, sum2 = 0;
	while (infile2 >> num2) {
		sum2 += num2;
	}
	cout << "ディーラーのカードの合計 " << sum2 << "\n" << endl;

	while (cin >> str) {
		if (str == "hit") {
			outfileYours(drow(str));
			(sumYours(str));
		}
		else if (str == "stop") {
			outfileDealer(drow(str));
			sumDealers(str);
		}
		else if (str == "n") {
			outfileDealer(drow(str));
			sumDealers(str);
		}
		else {
			ifstream infile("Yours.txt");
			int num1, sum1 = 0;
			while (infile >> num1) {
				sum1 += num1;
			}
			cout << "あなたのカードの合計 " << sum1 << endl;
			ifstream infile2("Dealer.txt");
			int num2, sum2 = 0;
			while (infile2 >> num2) {
				sum2 += num2;
			}
			cout << "ディーラーのカードの合計 " << sum2 << endl;

			if (sum1 > sum2) {
				if (sum1 <= 21)
				{
					vector<int>v;
					ifstream file("Yours.txt");
					int num;
					while (file >> num)v.push_back(num);
					cout << "あなたのカード" << v.cend() - v.cbegin() << "枚" << endl;
					cout << "You Win!!\n最初からやり直す→Ctrl+z→Enter2回\n";
				}
			}
			else {
				cout << "You Lose\n最初からやり直す→Ctrl+z→Enter2回\n";
				vector<int>v;
				ifstream file("Yours.txt");
				int num;
				while (file >> num)v.push_back(num);
				cout << "あなたのカード" << v.cend() - v.cbegin() << "枚" << endl;
			}
		}
	}
}