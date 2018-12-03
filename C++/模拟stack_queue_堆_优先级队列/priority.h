//#include "common.h"
//#include "heap.h"
//
//template<class T,class Compare = Less<T>>
//class PriorityQueue
//{
//public:
//	PriorityQueue()
//	{
//		;
//	}
//	PriorityQueue(T* a, size_t size)
//		:_q(a, size)
//	{}
//
//	void Push(const T& data)
//	{
//		_q.push(data);
//	}
//	void Pop()
//	{
//		_q.pop();
//	}
//
//	size_t Size() const
//	{
//		return _q.size();
//	}
//
//	const T& Front()
//	{
//		return _q.top();
//	}
//
//	bool Empty()
//	{
//		return _q.empty();
//	}
//private:
//
//	Heap<T, Compare> _p;
//};



/////////////////////�º���/�ִ�������������
//���������������һ��ʹ�ã�����һ�����أ����Կ�����Ҫ���ƵĲ���
//���Ͳ��ܴ�ֵ���ᷢ�����
template<class T>
class Less
{	 
	//˳������С���󣬿�ʼ�����������
	bool operator()(const T& left, const T& right)
	{
		return left < right;
	}
};

template<class T>
class Greater
{
	//˳�������С����ʼ��������С��
	bool operator()(const T& left, const T& right)
	{
		return left > right;
	}
};
////////////////////priority_queue

//��vector������Ԫ��������������Ϳ���Ӧ�ö��㷨�ҳ���ǰ���е����Ԫ��
//����������������ײ���ȷ�����Ԫ�����ȳ��ӣ�
template <class T,class container = vector<T>,class Compare = Less<int>>

class priority_queue
{

public:
	void AdjustUp(size_t child)
	{
		//���һ��Ԫ���±��һ����
		size_t parent = (child - 1) / 2;
		while (child)
		{
			//if (_con[child] > _con[parent])
			Compare con;
			if (con(_con[child] ,_con[parent]))
			{
				swap(_con+child,_con+parent);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}

	}
	void push(const T& x)
	{
		_con.push_back(x);
		AdjustUp(_con.size()-1);

	}
						
	void AdjustDown(size_t parent)
	{
		/*int child = parent * 2 + 1;
		while (child < _con.size())
		{
			if (child + 1 < _con.size() && _con[child + 1] > _con[child])
				child++;
			if (_con[child]>_con[parent])
			{
				swap(_con + child, _con + parent);
				parent = child;
				child = parent*2+1;
				
			}*/


			Compare con;
			if (child + 1 < _con.size() && con(_con[child], _con[child+1]))
				child++;
			if (con(_con[child], _con[parent]))
			{
				swap(_con + child, _con + parent);
				parent = child;
				child = parent * 2 + 1;

			}
		}

	void pop()
	{
		//swap(_con.front(),_con.back());
		swap(_con[0],_con[_con.size()-1]);
		_con.pop_back();
		AdjustDown(0);
	}
	T& top()
	{
		return _con[0];

	}

	size_t size()
	{
		return _con.size();

	}

	bool empty()
	{
		return _con.empty();

	}

private:
	container _con;

};