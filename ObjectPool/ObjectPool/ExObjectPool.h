#pragma once

template<typename T, int SIZE = 64>
class TObjectArrayPool
{
public:
	using OBJECT_PTR = T*;

	TObjectArrayPool()
	{
		// 할당과 초기화
	}

	~TObjectArrayPool()
	{
		// 해제
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
		// 할당과 초기화
	}

	~TOjbectListPool()
	{
		// 해제
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

