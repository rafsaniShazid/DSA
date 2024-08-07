#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class PriorityQueue
{
private:
    vector<T> heap;
    bool ascending;

    void heapifyUp(int index)
    {
        int parent = (index - 1) / 2;
        while (index > 0 && compare(heap[index], heap[parent]))
        {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < heap.size() && compare(heap[left], heap[smallest]))
        {
            smallest = left;
        }
        if (right < heap.size() && compare(heap[right], heap[smallest]))
        {
            smallest = right;
        }
        if (smallest != index)
        {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    bool compare(const T &a, const T &b)
    {
        if (ascending)
        {
            return a < b;
        }
        else
        {
            return a > b;
        }
    }

public:
    PriorityQueue(bool ascendingOrder = true) : ascending(ascendingOrder) {}

    void push(const T &value)
    {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void pop()
    {
        if (!empty())
        {
            heap[0] = heap.back();
            heap.pop_back();
            heapifyDown(0);
        }
    }

    const T &top() const
    {
        if (!empty())
        {
            return heap[0];
        }
        throw out_of_range("PriorityQueue is empty");
    }

    bool empty() const
    {
        return heap.empty();
    }

    size_t size() const
    {
        return heap.size();
    }
};

int main()
{

    PriorityQueue<int> pqAsc;
    pqAsc.push(30);
    pqAsc.push(10);
    pqAsc.push(50);
    pqAsc.push(20);

    cout << "PriorityQueue with ascending order:" << endl;
    while (!pqAsc.empty())
    {
        cout << pqAsc.top() << " ";
        pqAsc.pop();
    }
    cout << endl;

    PriorityQueue<int> pqDesc(false);
    pqDesc.push(30);
    pqDesc.push(10);
    pqDesc.push(50);
    pqDesc.push(20);

    cout << "PriorityQueue with descending order:" << endl;
    while (!pqDesc.empty())
    {
        cout << pqDesc.top() << " ";
        pqDesc.pop();
    }
    cout << endl;

    return 0;
}
