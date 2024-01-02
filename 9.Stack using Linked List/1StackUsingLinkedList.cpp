#include <iostream>
using namespace std;
struct node
{
    int item;
    node *next;
    node(int data)
    {
        item = data;
        next = NULL;
    }
};
class Stack
{
private:
    node *top;

protected:
    void insertAtLast(int);

public:
    Stack();
    void push(int);
    int peek();
    int pop();
    ~Stack();
    void reverseStack();
    void print();
    bool isEmpty();
    Stack &operator=(Stack &);
};
Stack::Stack()
{
    top = NULL;
}
void Stack::push(int data)
{
    node *n = new node(data);
    n->next = top;
    top = n;
}
int Stack::peek()
{
    if (top == NULL)
        throw 1;
    return top->item;
}
int Stack::pop()
{
    int data;
    if (top == NULL)
    {
        throw 1;
    }
    node *temp = top;
    top = top->next;
    data = temp->item;
    delete temp;
    return data;
}
Stack::~Stack()
{
    while (top)
        pop();
}
void Stack::reverseStack()
{
    if (top)
    {
        node *prev = NULL, *temp = top, *next = NULL;
        while (temp != NULL)
        {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        top = prev;
    }
}
void Stack::print()
{
    if (top)
    {
        node *temp = top;
        cout << "\nStack item is:\n";
        while (temp != NULL)
        {
            cout << temp->item << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    else
    {
        cout << "\nStack Underflow";
    }
}
bool Stack::isEmpty()
{
    return top == NULL;
}
void Stack::insertAtLast(int data)
{
    node *n = new node(data);
    if (top == NULL)
    {
        top = n;
    }
    else
    {
        node *temp = top;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}
Stack &Stack::operator=(Stack &s)
{
    if (this != &s)
    {
        if (top != NULL)
        {
            while (top)
                pop();
        }
        node *temp;
        temp = s.top;
        while (temp)
        {
            insertAtLast(temp->item);
            temp = temp->next;
        }
    }
    return *this;
}
void reverseStack(Stack &s)
{
    Stack temp;
    while (!s.isEmpty())
        temp.push(s.pop());
    s = temp;
}
bool isPalindrome(int x)
{
    int l = 0, y, i;
    Stack s;
    y = x;
    while (y)
    {
        y = y / 10;
        l++;
    }
    for (i = 1; i <= l / 2; i++)
    {
        s.push(x % 10);
        x = x / 10;
    }
    if (l % 2) // odd
        x = x / 10;

    for (i = 1; i <= l / 2; i++)
    {
        if (x % 10 != s.pop())
            return false;
        x = x / 10;
    }
    return true;
}
int main()
{
    Stack stack;
    int choice, value, number;
    bool checkPalindrome;

    do
    {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Print\n5. Reverse\n6. Check Palindrome\n7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter a value to push: ";
            cin >> value;
            stack.push(value);
            break;
        case 2:
            try
            {
                cout << "Popped value: " << stack.pop() << endl;
            }
            catch (int e)
            {
                cout << "Stack underflow error." << endl;
            }
            break;
        case 3:
            try
            {
                cout << "Peek value: " << stack.peek() << endl;
            }
            catch (int e)
            {
                cout << "Stack is empty." << endl;
            }
            break;
        case 4:
            stack.print();
            break;
        case 5:
            reverseStack(stack);
            cout << "Stack has been reversed." << endl;
            break;
        case 6:
            cout << "Enter a number to check for palindrome: ";
            cin >> number;
            checkPalindrome = isPalindrome(number);
            if (checkPalindrome)
                cout << number << " is a palindrome." << endl;
            else
                cout << number << " is not a palindrome." << endl;
            break;
        case 7:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}