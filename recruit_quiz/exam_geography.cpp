#include "exam_geography.h"
#include "utility.h"
#include <iostream>
#include <fstream>
#include <random>
using namespace std;

/*
* 都道府県の問題を作成する
*/
QuestionList CreatePrefecturesExam()
{
	//都道府県データ
	struct PrefectureData
	{
		string name;				//都道府県
		string capital;				//県庁所在地
		vector<string> features;	//特徴
	};
	vector<PrefectureData> data;

	{//都道府県データを読み込む
		constexpr char filename[] = "japanese_prefectures.txt";
		ifstream ifs(filename);
		if (!ifs) {
			cerr << "エラー:" << filename << "を読み込めません。\n";
			return {};
		}

		string s;
		while (true) {
			getline(ifs, s);	//1行読み取る
			if (!ifs) {
				break;	//ファイル終端に達したので終了
			}
			const vector<string> v = Split(s, ',');
			data.push_back({ v[0],v[1],vector<string>(v.begin() + 2,v.end()) });
		}
	}//都道府県データを読み込む

	constexpr int quizCount = 5;
	QuestionList questions;
	questions.reserve(quizCount);
	vector<int>indices = CreateRandomIndices((int)data.size());
	random_device rd;

	const int type = 1;	// uniform_int_distribution<>(0, 2)(rd);
	switch (type) {
	case 0:		//特徴から都道府県を答える
		for (int i = 0; i < quizCount; i++) {
			//正解以外の答えをランダムに選ぶ
			const int correctIndex = indices[i];
			vector<int> answers = CreateWrongIndices((int)data.size(), correctIndex);

			//ランダムな位置を正しい番号で上書き
			const int correctNo = std::uniform_int_distribution<>(1, 3)(rd);
			answers[correctNo - 1] = correctIndex;

			//問題文を作成
			string s = "以下の特徴を持つ都道府県の番号を選べ\n";

			//都道府県の特徴をランダムな順番で連結し、問題文に追加
			const auto& features = data[correctIndex].features;
			vector<int> featureIndices = CreateRandomIndices((int)features.size());
			s += features[featureIndices[0]];
			for (int j = 1; j < features.size(); j++) {
				s += ", ";
				s += features[featureIndices[j]];
			}

			//答えとなる都道府県を問題文に追加
			for (int j = 0; j < 3; j++) {
				s += "\n " + to_string(j + 1) + ":" + data[answers[j]].name;
			}

			//問題文と答えのペアを問題配列に追加
			questions.push_back({ s,to_string(correctNo) });
		}
		break;

	case 1:		//都道府県を表す特徴を答える
		for (int i = 0; i < quizCount; i++) {
			//正解以外の答えをランダムに選ぶ
			const int correctIndex = indices[i];
			vector<int> answers = CreateWrongIndices((int)data.size(), correctIndex);

			//ランダムな位置を正しい番号で上書き
			const int correctNo = std::uniform_int_distribution<>(1, 3)(rd);
			answers[correctNo - 1] = correctIndex;

			//問題文を作成
			string s = "「" + data[correctIndex].name + "」の特徴を表す番号を選べ";
			for (int j = 0; j < 3; j++) {
				const auto& features = data[answers[j]].features;
				const int n = uniform_int_distribution<>(0, (int)features.size() - 1)(rd);
				s += "\n " + to_string(j + 1) + ":" + features[n];
			}

			//問題文と答えのペアを問題配列に追加
			questions.push_back({ s,to_string(correctNo) });
		}
		break;

	case 2:		//都道府県から県庁所在地を答える
		break;
	}//switch(type)

	return questions;
}