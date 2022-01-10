#pragma once

template<typename T, int SIZE = 64>
class TObjectArrayPool
{
public:
	using OBJECT_PTR = T*;

	TObjectArrayPool()
	{
		// �Ҵ�� �ʱ�ȭ
	}

	~TObjectArrayPool()
	{
		// ����
	}

	OBJECT_PTR Alloc() { return nullptr; }
	void Free(OBJECT_PTR pObj) {}

private:
	OBJECT_PTR* objectArray;
};

template<typename T, int SIZE = 64>
class TOjbectListPool
{
public:
	using OBJECT_PTR = T*;

	TOjbectListPool()
	{
		// �Ҵ�� �ʱ�ȭ
	}

	~TOjbectListPool()
	{
		// ����
	}

	OBJECT_PTR Alloc() { return nullptr; }
	void Free(OBJECT_PTR pObj) {}

private:
	struct Node
	{
		T obj;
		Node* pNext;
	};

	Node* pHead;
	Node* pTail;
};

