#include <iostream>
#include <string>
using namespace std;

//��蕶���܂Ƃ߂�\����
struct Question
{
	string s;//��蕶
	int a;//����
};

int main() {
	Question questions[] = {
		{"13�~(-5)",13 * -5},
		{"(-21)��(-3)",-21 / -3},
		{"7-(4+2)��2",7 - (4 + 2) / 2},
	};

	cout << "[���N���[�g�����΍�N�C�Y]\n";

	for (const auto& e : questions) {
		cout << e.s << "�̓����́H\n";
		int answer;
		cin >> answer;
		if (answer == e.a) {
			cout << "�����I\n";
		}
		else {
		cout << "�ԈႢ�I������" << e.a << "\n";
		}
	}	// for questions
}