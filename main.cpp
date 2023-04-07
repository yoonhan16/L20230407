#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
// c 에서 만든 난수는 2바이트 기준으로 하는거라 3만 언저리까지 밖에 생성 안됨
// 표에 있는대로 읽어오는 거라 rand() 넣으면 41이 고정으로 나옴
// 시드를 바꿔주면 다른 숫자가 나오긴 하지만.. 굳이?
// 앞에 srand(time(0)) 을 넣어주면 시작할 때 마다 숫자가 다르게 나옴 (최대 3만 2천 언저리)
// srand((unsigned int)time(0)) 으로 하면 warning 안나옴 
// **절대 출력 로그의 warning 을 무시하지마**

using namespace std;

class AActor
{

};

class FBall : public AActor            // 다른 사람에게 팔려면 캡슐화를 해야된다...
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

	FPocket(int Count = 45)                                  // 함수 인자의 기본값을 설정하는 방법, 여기를 비우면 45가 들어감
	{
		srand((unsigned int)time(0));
		for (int i = 0; i < Count; i++)                      //로또로 하면 45개, 다른 걸로 해도 됨
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
	
	//FBall Balls[45];               //이거보다
	vector<FBall> Balls;             //얘가 관리 편함

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
	//random_shuffle(Ball.begin(), Ball.end());                //시작부터 끝까지 섞어


	//shuffle()
	//for (int i = 0; i < 10000; i++)
	//{
	//	int First = (rand() % 45) + 1;
	//	int Second = (rand() % 45) + 1;

	//	//swap()
	//	int Temp = Ball[First];               // 처음 값을 다른 공간에 저장하고         
	//	Ball[First] = Ball[Second];           // 두번째 값을 첫번째에 넣어주고
	//	Ball[Second] = Temp;                  // 반복
	//}                                       // 이렇게 쓰면

	//for (int i = 0; i < 6; i++)             // 얘가
	//{
	//	int Choice = (rand() % 45) + 1;
	//	cout << Ball[Choice] << endl;
	//}

	//for (int i = 0; i < 6; i++)               // 이렇게 됨
	//{
	//	cout << Ball[i] << endl;
	//}


	//for (int i = 0; i < 45; i++)          //얘랑
	//{
	//	cout << Ball[i] << endl;
	//}
	//for (int Value : Ball)                //얘랑 같음 (탐색용)
	//{
	//	cout << Value << endl;
	//}

	//위의 클래스대로 만들면
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
		FBall Ball = Pockets->Draw();                              // public 으로 설정하면 밖에서 건드릴 수 있음
		cout << Ball.GetNumber() << endl;

		//cout << Pockets->Draw().Number << endl;                  //private으로 int number를 설정하면 좋지만
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
	Balls.erase(Balls.begin());                       // 뽑은 번호를 지워주는 함수..놀랍다

	return DrawBall;
}
