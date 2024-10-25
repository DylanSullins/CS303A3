#pragma once

template <typename T>
struct Node
// Node struct for use in Queue implementation
{
    T data;
    Node<T>* next;
    Node(T data, Node<T>* next) : data(data), next(next) {}
};

template <typename T>
class Queue
{
    protected:
        Node<T>* head;
        Node<T>* tail;
        size_t size;

    public:
        Queue() : head(nullptr), tail(nullptr) , size(0)
        // Default Constructor
        {}
        Queue(T data)
        // Constructor with initial data
        {
            head = new Node<T>(data, nullptr);
            tail = head;
            size = 1;
        }
        Queue(Node<T>* node)
        // Constructor with initial node
        {
            head = node;
            if (head == nullptr) 
            {
                tail = nullptr;
                size = 0;
            }
            else 
            {
                tail = head;
                size = 1;
                while (tail->next != nullptr)
                {
                    tail = tail->next;
                    ++size;
                }
            }
        }
        ~Queue()
        // Destructor
        {
            while (!empty()) pop();
        }


        void push(T data)
        /*
            Pushes data to end of queue
            Parameters:
                T data: Data to add
            
            Returns:
                None
        */
        {
            if (head == nullptr)
            {
                head = new Node<T>(data, nullptr);
                tail = head;
                size = 1;
                return;
            }
            tail->next = new Node<T>(data, nullptr);
            tail = tail->next;
            ++size;
        }
        void pop()
        /*
            Removes the node at head position
            Parameters:
                None

            Returns:
                None
        */
        {
            if (head == nullptr) return;
            if (head->next == nullptr) 
            {
                head = nullptr;
                tail = nullptr;
                size = 0;
                return;    
            }
            Node<T>* delNode = head;
            head = head->next;
            delete delNode;
            --size;
        }
        T front() const 
        /*
            Returns data at front of queue
            Parameters:
                None
            
            Returns:
                Type T head->data
        */
        {
            if (head == nullptr) throw std::out_of_range("Empty Queue");
            return head->data;
        }
        size_t getSize() const
        /*
            Returns size of queue
            Parameters:
                None
            
            Returns:
                size_t size
        */ 
        {
            return size;
        }
        bool empty() const 
        /*
            Returns if queue is empty
            Parameters:
                None
            
            Returns:
                bool (head == nullptr)
        */
        {
            return (head == nullptr);
        }

        void move_to_rear()
        /*
            Moves front node to rear
            Parameters:
                None
            
            Returns:
                None
        */
        {
            if (head == nullptr) return;
            if (head->next == nullptr) return;
            push(front());
            pop();
        }

        class iterator
        /*
            Unused Iterator Class
            Can be used to traverse the queue without pushing and popping.
            But if you need an iterator, you might want to rethink using
            a Queue.
        */
        {
            public:
                Node<T>* current;
                iterator(Node<T>* position) : current(position)
                // Constructor
                {}

                T& operator*() const
                // Dereference Operator
                {
                    if (current == nullptr)
                        throw std::runtime_error("Attempt to dereference end()");
                    return current->data;
                }
                T* operator->() const
                // Dereference Operator
                {
                    if (current == nullptr)
                        throw std::runtime_error("Attempt to dereference end()");
                    return &(current->data);
                }
                iterator& operator++()
                // Increment Operator Postfix
                {
                    if (current == nullptr)
                        throw std::runtime_error("Attempt to advance past end()");
                    current = current->next;
                    return *this;
                }
                iterator operator++(int)
                // Increment Operator Prefix
                {
                    iterator returnValue = *this;
                    ++(*this);
                    return returnValue;
                }
                bool operator==(const iterator& other) const
                // Equality Operator
                {
                    return current == other.current;
                }
                bool operator!=(const iterator& other) const
                // Inequality Operator
                {
                    return current != other.current;
                }
        };

        iterator begin() const 
        // Returns iterator at head
        {return iterator(head);}
        iterator end() const {return iterator(nullptr);}
        // Returns iterator at end of queue
};