#include <iostream>
#include <conio.h>
#include <vector>
#include <stack>
using namespace std;

void show(int array[], int size);
void stackSort(int array[], int size);
void toStacks(vector<stack<int>*>& stacks, int array[], int size);
void fromStacks(vector<stack<int>*>& stacks, int array[], int size);

int main()
{
    cout << "Stack Sorting" << endl << endl;
    int array[]{ 18, 92, 64, 12, 51, 82, 93, 14, 55, 31, 12, 90, 77, 28 };
    int size = sizeof(array) / sizeof(int);
    show(array, size);
    stackSort(array, size);
    show(array, size);
    cout << endl;
    _getch();
    return 0;
}

void show(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl << endl;
}

void stackSort(int array[], int size)
{
    vector<stack<int>*> stacks;
    toStacks(stacks, array, size);
    fromStacks(stacks, array, size);
    for (auto& p : stacks)
    {
        delete p;
    }
    return;
}

void toStacks(vector<stack<int>*>& stacks, int array[], int size)
{
    stack<int>* pstack = new stack<int>;
    pstack->push(array[0]);
    stacks.push_back(pstack);
    for (int i = 1; i < size; i++)
    {
        bool placed = false;
        for (auto& it : stacks)
        {
            if (array[i] < it->top())
            {
                it->push(array[i]);
                placed = true;
                break;
            }
        }
        if (!placed)
        {
            stack<int>* pnext = new stack<int>;
            pnext->push(array[i]);
            stacks.push_back(pnext);
        }
    }
}

void fromStacks(vector<stack<int>*>& stacks, int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int next = INT_MAX;
        stack<int>* pnext = stacks[0];
        for (auto it : stacks)
        {
            if (!it->empty() && it->top() < next)
            {
                next = it->top();
                pnext = it;
            }
        }
        array[i] = next;
        pnext->pop();
    }
}