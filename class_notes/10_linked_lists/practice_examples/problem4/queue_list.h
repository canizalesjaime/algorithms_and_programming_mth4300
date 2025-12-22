#pragma once
struct Node
{
    int data;
    Node* next;

    Node(int val):next(nullptr), data(val) {}
};

// Linked List class
class QueueList
{
private:
    Node* head_;  // Points to the first node (or nullptr if the list is empty)
    void eraseList(); //helper to delete the whole list

public:
    QueueList();
    QueueList(const QueueList& l);
    QueueList(QueueList&& l);
    ~QueueList();
    QueueList& operator=(const QueueList& rhs);
    QueueList& operator=(QueueList&& rhs);


    void push(int value);
    void pop();
    int back() const;
    int front() const;
};