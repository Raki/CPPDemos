#include <fmt/format.h>
#include <vector>
#include <chrono>
#include <memory>
#include <future>

template <typename T>
struct Node
{
	T data;
	std::unique_ptr<Node> next;

	Node(T d) :data(d), next(nullptr)
	{
	};
};

template <typename T>
class LinkedList
{
public:
	void pushFront(const T& value)
	{
		auto newNode = std::make_unique<Node<T>>(value);
		newNode->next = std::move(head);
		head = std::move(newNode);
	}

	void printMiddle()
	{
		size_t cnt = 0;
		auto h = head.get();
		auto mid = head.get();

		while (h!=nullptr)
		{
			if (cnt & 1)
			{
				mid = mid->next.get();
			}

			cnt += 1;
			h = h->next.get();
		}

		fmt::print("middle value: {}",mid->data);
	}

	void push(const T& value)
	{
		auto newNode = std::make_unique<Node<T>>(value);

		//linked list is empty
		if (head == nullptr)
		{
			head = std::move(newNode);
		}
		else
		{
			auto h = head.get();

			while (h != nullptr)
			{
				if (h->next == nullptr)
				{
					h->next = std::move(newNode);
					break;
				}

				h = h->next.get();
			}
		}
	}

	void print()
	{
		auto h = head.get();
		while (h != nullptr)
		{
			fmt::print("{}\n",h->data);
			h = h->next.get();
		}
	}
private:
	std::unique_ptr<Node<T>> head=nullptr;
};

int main()
{

	//prepare linked list

	LinkedList<int> ls;

	/*ls.pushFront(5);
	ls.pushFront(4);
	ls.pushFront(3);
	ls.pushFront(2);
	ls.pushFront(1);*/

	ls.push(1);
	ls.push(2);
	ls.push(3);
	ls.push(4);
	ls.push(5);
	
	ls.print();

	ls.printMiddle();
	
	return EXIT_SUCCESS;
}


