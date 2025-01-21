#include "question.h"
#include "exam_mathematics.h"
#include "exam_japanese.h"
#include "exam_english.h"
#include "exam_science.h"
#include "exam_geography.h"
#include "exam_politics.h"
#include "exam_economics.h"
#include "utility.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;


int main() {
	//���ȃf�[�^�z��
	static const struct {
		const char* name;			//���Ȗ�
		QuestionList(*create)();	//���쐬�֐��̃A�h���X
	} subjectData[]={
		{"���w",CreateMathematicsExam},
		{"����",CreateJapaneseExam},
		{"�p��",CreateEnglishExam},
		{"����",CreatePhysicsExam},
		{"�n��",CreatePrefecturesExam},
		{"����",CreatePoliticsExam},
		{"�o��",CreateEconomicsExam},
	};

	vector<Question> questions(3);

	cout << "[���N���[�g�����΍�N�C�Y]\n";

	cout << "���Ȃ�I��ł�������\n";
	for (int i = 0; i < size(subjectData); i++) {
		cout << i + 1 << '=' << subjectData[i].name << '\n';
	}

	int subject;
	cin >> subject;
	if (subject > 0 && subject <= size(subjectData)) {
		questions = subjectData[subject - 1].create();
	}

	for (const auto& e : questions) {
		cout << e.s << "\n";
		string answer;
		cin >> answer;

		const string ascii = ConvertSjisNumberToAscii(answer);
		//�ϊ������������ꍇ�͕������u��������
		if (!ascii.empty()) {
			answer = ascii;
		}

		if (answer == e.a) {
			cout << "�����I\n";
		} else if(e.b.empty()) {
			//������������̏ꍇ
		cout << "�ԈႢ�I������" << e.a << "\n";
		} else {
			//��������������ꍇ�A�����ꂩ�ƈ�v����ΐ����Ƃ���
			bool isMatch = false;
			for (const auto& b : e.b) {
				if (answer == b) {
					isMatch = true;	//��v���铚������������
					break;
				}
			}

			//��r���ʂ��o��
			if (isMatch) {
				cout << "�����I\n";
			} else {
				cout << "�ԈႢ�I�@������" << e.a << "(�܂���";
				for (auto& b : e.b) {
					cout << "�A" << b;
				}
				cout << ")\n";
			}
		}// if answer == e.a
	}	// for questions
}