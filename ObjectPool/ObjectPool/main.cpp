#include <stdio.h>
#include <iostream>
#include <forward_list>
#include "ExObjectPool.h"
#include <Windows.h>
#include <time.h>
#include <random>

struct Dummy
{
	int seq;	// �߰��� ����
	int number; // ���� ��ȣ
};

class MinAndAvg
{
public:
	void AddNumber(int number) {}
	void Print(){/* �ֱ� 10���� ���� ��հ� �ּҰ� ��� */ }

	// get , set
	std::forward_list<Dummy*> GetList() const { return m_list; }
	void SetList(std::forward_list<Dummy*> val) { m_list = val; }
private:

	// forward_list (���� ���Ḯ��Ʈ) �ڷᱸ���� �̿��Ͽ� ���� ������ �����̳��̴�.
	/*
		�� std::forward_list�� ����ؾ� �ϴ� ���
		double linked list �� �ƴ� single linked list �ε� ����Ҷ�
	*/
	std::forward_list<Dummy*>m_list;
	TObjectArrayPool<Dummy>m_arrayPool;

	// �ʿ��� ��� �߰�
};

class MaxAndAvg
{
public:

	void AddNumber(int number) {}
	void Print() { /*�ֱ� 10���� ���� ��հ� �ִ� ���*/ }

private:
	std::forward_list<Dummy*> m_list;
	TOjbectListPool<Dummy> m_listPool;
};


int main()
{
	MinAndAvg minAvg;
	MaxAndAvg maxAvg;



	// �õ尪�� ��� ���� random_device ����
	std::random_device rd;

	// random_device�� ���� ���� ���� ������ �ʱ�ȭ�Ѵ�.
	std::mt19937 gen(rd());

	// 0 ���� 99���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����.
	std::uniform_int_distribution<int> dis(0, 99);

	bool bRun = true;
	int count = 0;
	while (bRun)
	{
		if (count == 100)
		{
			bRun = false;
		}
		// 1. �� 2�ʸ��� ������ ���� n �� ����
		Sleep(2000); // 2�ʸ���

		std::cout << "���� ù��°" <<  count <<" " << ":" << dis(gen) << std::endl;
		// 2. minAvg.AddNumber(n); minAvg.Print()
		minAvg.AddNumber(dis(gen));
		minAvg.Print();

		std::cout << "���� �ι�°" << count << " " << ":" << dis(gen) << std::endl << std::endl;
		// 3. maxAvg.AddNumber(n); maxAvg.Print()
		maxAvg.AddNumber(dis(gen));
		maxAvg.Print();

		count++;
		// 100�� �̻��̸� �ߴ�
	}

	system("pause");

	return 0;
}