#pragma once

class Stack
{
public:
    Stack() = default;
    Stack(const Stack& source);
    Stack& operator=( const Stack& source );
    ~Stack();
	void Push( int val );
	int Pop();
	int Size() const;
	bool Empty() const;

private:
    class Node {
        public:
            Node( int value, Node* next );
            ~Node();
            Node& operator=( const Node& source ) = delete;
            int& operator[]( int data ) = delete;

        public:
            int data = 0;
            Node* p_next = nullptr;
    };

private:
    Node* head = nullptr;
};
