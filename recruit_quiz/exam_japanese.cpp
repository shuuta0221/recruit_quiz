#include "exam_japanese.h"
#include "utility.h"
using namespace std;

/*
	�����̓ǂݎ������쐬����
*/
QuestionList CreateKanjiExam()
{
	static const struct {
		const char* Kanji;		//����
		const char* reading;	//�ǂ�
		const char* meaning;	//�Ӗ�
	} data[] = {
		{"�s��", "������", "�l�������W�܂��ĕ�炷�Ƃ���A��" },
		{"���", "�Ȃ���", "(�����Ƌ���)��ӂ���������" },
		{"���E", "��������", "���������̌��ʁA�����Ȃ��Ȃ邱��" },
		{"�}��", "�͂�ꂢ", "�{��}�\�̂͂��߂ɁA�g������񑩎����ӏ������ɂ�������" },
		{"���", "�₭���傤", "�񑩂��Č��߂邱�ƁA�_��" },
	};

	constexpr int quizCount = 5;
	QuestionList questions;
	questions.reserve(quizCount);
	const vector<int> indices = CreateRandomIndices(size(data));

	for (int i = 0; i < quizCount; i++) {
		const auto& e = data[indices[i]];
		questions.push_back({
			"�u" + string(e.Kanji) + "�v�̓ǂ݂��Ђ炪�Ȃœ�����",e.reading });
	}
	return questions;
}