#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;

//問題文をまとめる構造体
struct Question
{
	string s;//問題文
	string a;//答え
};

//最大公約数を求める
int gcd(int a,int b){
	//余りが0になったときの除数を返す
	while (b){
		int r = a % b;
		a = b;	//除数を次の被除数にする
		b = r;	//余りを次の除数にする
	}
	return a;
}

int main() {
	vector<Question> questions(3);

	random_device rd;
	mt19937 rand(rd());

	//掛け算
	int x = uniform_int_distribution<>(1, 30)(rand);
	int y = uniform_int_distribution<>(1, 20)(rand);
	questions[0].s = to_string(x) + "x" + to_string(y) + "の答えは？";
	questions[0].a = to_string(x * y);

	//割り算
	x = uniform_int_distribution<>(1, 30)(rand);
	y = uniform_int_distribution<>(1, 20)(rand);
	questions[1].s = to_string(x * y) + "÷" + to_string(y) + "の答えは？";
	questions[1].a = to_string(x);

	//複雑な式
	x = uniform_int_distribution<>(1, 100)(rand);
	y = uniform_int_distribution<>(1, 10)(rand);
	int z = uniform_int_distribution<>(1, 10)(rand);
	int w = uniform_int_distribution<>(1, 10)(rand);
	questions[2].s = to_string(x) + "-(" + to_string(y * w) + "+" + to_string(z * w) + ")÷" + to_string(w) + "の答えは？";
	questions[2].a = to_string(x - (y + z));

	//三角形の面積
	x = uniform_int_distribution<>(1, 10)(rand);
	y = uniform_int_distribution<>(1, 5)(rand) * 2;
	questions.push_back({
		"面積" + to_string(x * y / 2) + "cm^2、底辺" + to_string(y) + "cmの三角形の高さを求めよ。",to_string(x) });

	//円錐の体積
	x = uniform_int_distribution<>(1, 10)(rand);
	y = uniform_int_distribution<>(1, 5)(rand) * 3;
	questions.push_back({
		"底面の半径" + to_string(x) + "cm、高さ" + to_string(y) + "cmの円錐がある。\n" +
		"この円錐の体積をXπcm^3とする。Xの値を求めよ。",to_string(x * x * y / 3) });

	//球の体積
	x = uniform_int_distribution<>(1, 5)(rand) * 3;
	questions.push_back({
		"半径" + to_string(x) + "cmの球がある。\n" +
		"この球の体積をXπcm^3とする。Xの値を求めよ。",to_string(x * x * x * 4 / 3) });

	//サイコロの確率
	x = uniform_int_distribution<>(1, 5)(rand);
	y = uniform_int_distribution<>(1, 6 - x)(rand);
	z = gcd(y + 1, 6);
	questions.push_back({
		"サイコロを1回ふって、" + to_string(x) + "から" + to_string(x + y) + "が出る確率を求めよ。",
		to_string((y + 1) / z) + "/" + to_string(6 / z) });

	//順列
	x = uniform_int_distribution<>(1, 7)(rand);
	y = uniform_int_distribution<>(1, x)(rand);
	z = 1;
	for (int i = 0; i < y; i++) {
		z *= x - i;
	}
	questions.push_back({
		to_string(x) + "人のうち" + to_string(y) + "人を選んで並べる方法は何通りあるか？",
		to_string(z) });

	//組み合わせ
	x = uniform_int_distribution<>(3, 6)(rand);
	y = uniform_int_distribution<>(1, x)(rand);
	z = 1;
	for (int i = 0; i < y; i++) {
		z *= x - i;
	}
	for (int i = 0; i < y; i++) {
		z /= y - i;
	}
	questions.push_back({
		to_string(x) + "人のうち" + to_string(y) + "人を選ぶ組み合わせは何通りあるか？",
		to_string(z) });


	cout << "[リクルート試験対策クイズ]\n";

	for (const auto& e : questions) {
		cout << e.s << "\n";
		string answer;
		cin >> answer;
		if (answer == e.a) {
			cout << "正解！\n";
		}
		else {
		cout << "間違い！正解は" << e.a << "\n";
		}
	}	// for questions
}