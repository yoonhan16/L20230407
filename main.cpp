#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
// c ���� ���� ������ 2����Ʈ �������� �ϴ°Ŷ� 3�� ���������� �ۿ� ���� �ȵ�
// ǥ�� �ִ´�� �о���� �Ŷ� rand() ������ 41�� �������� ����
// �õ带 �ٲ��ָ� �ٸ� ���ڰ� ������ ������.. ����?
// �տ� srand(time(0)) �� �־��ָ� ������ �� ���� ���ڰ� �ٸ��� ���� (�ִ� 3�� 2õ ������)
// srand((unsigned int)time(0)) ���� �ϸ� warning �ȳ��� 
// **���� ��� �α��� warning �� ����������**

using namespace std;

class AActor
{

};

class FBall : public AActor            // �ٸ� ������� �ȷ��� ĸ��ȭ�� �ؾߵȴ�...
{
public:
	int GetNumber() { return Number; }
	void SetNumber(int Value)
	{
		if (Value > 0)
		{
			Number = Value;
		}
	}

private:
	int Number;
};

class FPocket : public AActor
{
public:

	FPocket() { }

	FPocket(int Count = 45)                                  // �Լ� ������ �⺻���� �����ϴ� ���, ���⸦ ���� 45�� ��
	{
		srand((unsigned int)time(0));
		for (int i = 0; i < Count; i++)                      //�ζǷ� �ϸ� 45��, �ٸ� �ɷ� �ص� ��
		{
			FBall NewBall;
			NewBall.SetNumber(i + 1);
			Balls.push_back(NewBall);
		}
	}
	void shuffle();
	FBall Draw();

	void Push(FBall NewBall)
	{
		Balls.push_back(NewBall);
	}
	
	//FBall Balls[45];               //�̰ź���
	vector<FBall> Balls;             //�갡 ���� ����

};


int main()
{
	//srand((unsigned int)time(0));

	//int Ball[45];
	//vector<int> Ball;

	//for (int i = 0; i < 45; i++)
	//{
	//	Ball[i] = i + 1;
	//}
	//for (int i = 0; i < 45; i++)
	//{
	//	Ball.push_back(i + 1);
	//}
	//
	//random_shuffle(Ball.begin(), Ball.end());                //���ۺ��� ������ ����


	//shuffle()
	//for (int i = 0; i < 10000; i++)
	//{
	//	int First = (rand() % 45) + 1;
	//	int Second = (rand() % 45) + 1;

	//	//swap()
	//	int Temp = Ball[First];               // ó�� ���� �ٸ� ������ �����ϰ�         
	//	Ball[First] = Ball[Second];           // �ι�° ���� ù��°�� �־��ְ�
	//	Ball[Second] = Temp;                  // �ݺ�
	//}                                       // �̷��� ����

	//for (int i = 0; i < 6; i++)             // �갡
	//{
	//	int Choice = (rand() % 45) + 1;
	//	cout << Ball[Choice] << endl;
	//}

	//for (int i = 0; i < 6; i++)               // �̷��� ��
	//{
	//	cout << Ball[i] << endl;
	//}


	//for (int i = 0; i < 45; i++)          //���
	//{
	//	cout << Ball[i] << endl;
	//}
	//for (int Value : Ball)                //��� ���� (Ž����)
	//{
	//	cout << Value << endl;
	//}

	//���� Ŭ������� �����
	FPocket* Pockets = new FPocket();
	
	for (int i = 0; i < 45; i++)
	{
		FBall Ball;
		Ball.SetNumber(i + 1);
		Pockets->Push(Ball);
	}
	
	
	Pockets->shuffle();

	for (int i = 0; i < 6; i++)
	{
		FBall Ball = Pockets->Draw();                              // public ���� �����ϸ� �ۿ��� �ǵ帱 �� ����
		cout << Ball.GetNumber() << endl;

		//cout << Pockets->Draw().Number << endl;                  //private���� int number�� �����ϸ� ������
	}

	delete Pockets;



	return 0;
}

void FPocket::shuffle()
{
	random_shuffle(Balls.begin(), Balls.end());
}

FBall FPocket::Draw()
{
	FBall DrawBall = *(Balls.begin());
	Balls.erase(Balls.begin());                       // ���� ��ȣ�� �����ִ� �Լ�..�����

	return DrawBall;
}
