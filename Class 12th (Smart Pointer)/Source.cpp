﻿#include <iostream>
#include <memory>
using namespace std;

#pragma region RAII 패턴
// 자원의 안전한 사용을 위해 객체가 쓰이는 범위를 벗어나게 되면
// 자원을 해제ㅔ해주는 기법

class File
{
public:
	File()
	{
		cout << "Create File " << endl;
	}
	~File()
	{
		cout << "Release File" << endl;
	}

};


#pragma endregion

class Player
{
#pragma region weak 포인터
	// 자신이 참조하고 있는 원시 포인터의 강한 참조 카운트가 0 이 되면
	// expired 라는 상태가 되는데, 이는 원시 포인터의 참조 카운트가 0이 되어
	// 메모리가 해제되었으므로, 이 원시 포인터를 소유한 weak 포인터를
	// 유효하지 않다고 판단하여 해제하는 포인터이다.

	//shared_ptr -> weak_ptr
#pragma endregion



private:
	weak_ptr<Player> partner;

public:
	Player()
	{
		cout << "Create Player" << endl;
	}
	~Player()
	{
		cout << "Release Player" << endl;
	}

	void SetPartner(weak_ptr<Player> partner)
	{
		this->partner = partner;
	}
};





int main()
{
#pragma region unique 포인터


	//unique_ptr<File> uniquePtr1(new File());

	//cout << "UniquePtr1의 값 : " << uniquePtr1 << endl;

	//unique_ptr<File> uniquePtr2 = std::make_unique<File>();


	//unique_ptr<File> uniquePtr1 = std::make_unique<File>();



	//// 하나의 unique 포인터는 하나의 객체만 가질 수 있다.
	//// 하지만, 객체에 대한 소유권을 이전하는 것은 가능하다.
	//unique_ptr<File> uniquePtr3 = move(uniquePtr2);

	//cout << "uniquePtr2의 값: " << uniquePtr2 << endl;
	//cout << "uniquePtr3의 값: " << uniquePtr3 << endl;

#pragma endregion

#pragma region shared 포인터
	// 하나의 객체에 여러 개의 포인터가 공유할 수 있으며
	// 공유할 때마다 창조 카운트를 이용해서 메모리를 관리하는 스마트포인터.

	//shared_ptr<Player> player1 = make_shared <Player>();
	//
	//shared_ptr<Player> player2 = make_shared <Player>();
	//
	//
	//cout << "player1의 참조 횟수 : " << player1.use_count() << endl;
	//cout << "player2의 참조 횟수 : " << player2.use_count() << endl;
	//
	//player1->SetPartner(player2);
	//player2->SetPartner(player1);



#pragma endregion

	return 0;

}
