#include <stdio.h>
#include <iostream>
#include <forward_list>
#include "ExObjectPool.h"
#include <Windows.h>
#include <time.h>
#include <random>

struct Dummy
{
	int seq;	// 추가된 순서
	int number; // 랜덤 번호
};

class MinAndAvg
{
public:
	void AddNumber(int number) {}
	void Print(){/* 최근 10개의 숫자 평균과 최소값 출력 */ }

	// get , set
	std::forward_list<Dummy*> GetList() const { return m_list; }
	void SetList(std::forward_list<Dummy*> val) { m_list = val; }
private:

	// forward_list (단일 연결리스트) 자료구조를 이용하여 만든 시퀀스 컨테이너이다.
	/*
		※ std::forward_list를 사용해야 하는 경우
		double linked list 가 아닌 single linked list 로도 충분할때
	*/
	std::forward_list<Dummy*>m_list;
	TObjectArrayPool<Dummy>m_arrayPool;

	// 필요한 멤버 추가
};

class MaxAndAvg
{
public:

	void AddNumber(int number) {}
	void Print() { /*최근 10개의 숫자 평균과 최댓값 출력*/ }

private:
	std::forward_list<Dummy*> m_list;
	TOjbectListPool<Dummy> m_listPool;
};


int main()
{
	MinAndAvg minAvg;
	MaxAndAvg maxAvg;



	// 시드값을 얻기 위한 random_device 생성
	std::random_device rd;

	// random_device를 통해 난수 생성 엔진을 초기화한다.
	std::mt19937 gen(rd());

	// 0 부터 99까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
	std::uniform_int_distribution<int> dis(0, 99);

	bool bRun = true;
	int count = 0;
	while (bRun)
	{
		if (count == 100)
		{
			bRun = false;
		}
		// 1. 매 2초마다 랜덤한 숫자 n 을 생성
		Sleep(2000); // 2초마다

		std::cout << "난수 첫번째" <<  count <<" " << ":" << dis(gen) << std::endl;
		// 2. minAvg.AddNumber(n); minAvg.Print()
		minAvg.AddNumber(dis(gen));
		minAvg.Print();

		std::cout << "난수 두번째" << count << " " << ":" << dis(gen) << std::endl << std::endl;
		// 3. maxAvg.AddNumber(n); maxAvg.Print()
		maxAvg.AddNumber(dis(gen));
		maxAvg.Print();

		count++;
		// 100개 이상이면 중단
	}

	system("pause");

	return 0;
}