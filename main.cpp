//
// Created by 82107 on 2021-07-20.
//

#include<iostream>
using namespace std;
const int MAX = 100001;
class min_heap
{
private:
    int heap[MAX];
    int idx = 0;
public:
    int size();
    void push(int data);
    int pop();
    void swap(int* a, int* b);
    int select(int child);
};

int min_heap::size()
{
    return idx;
}

void min_heap::push(int data)
{
    heap[++idx] = data;

    int child = idx;
    int parent = child / 2;
    while (child > 1 && heap[child] < heap[parent]) {
        swap(&heap[child], &heap[parent]);
        child = parent;
        parent = child / 2;
    }
}

int min_heap::pop()
{
    int result = heap[1];

    swap(&heap[idx--], &heap[1]);

    int parent = 1;
    int child = parent * 2;
    child = select(child);

    while (child <= idx && heap[parent] > heap[child]) {
        swap(&heap[parent], &heap[child]);
        parent = child;
        child = child * 2;
        child = select(child);
    }

    return result;
}

void min_heap::swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int min_heap::select(int child)
{
    if (child + 1 <= idx) child = (heap[child] < heap[child + 1]) ? child : child + 1;
    return child;
}

int main(void)
{
    min_heap h;

    int n; cin >> n;

    while (n--) {
        int c; cin >> c;
        if (c == 0) {
            if (h.size()) cout << h.pop();
            else cout << 0;
            cout << '\n';
        }
        else h.push(c);
    }

    return 0;
}