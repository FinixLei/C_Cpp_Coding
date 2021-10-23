#ifndef LIST_HPP
#define LIST_HPP

#include <memory>
#include <iostream>

namespace finix {
    template <typename T> 
    class List {
    private: 
        struct Node {
            T data;
            std::shared_ptr<Node> next;
            std::weak_ptr<Node> prev;
            
            Node() : next(std::shared_ptr<Node>()), prev(std::weak_ptr<Node>()) {}
            
            Node(T d) : data(d), next(std::shared_ptr<Node>()), prev(std::weak_ptr<Node>()) {}
            
            ~Node() {
                std::cout << "Destructing Node: data = " << data << std::endl;
            }
        };
        
    private: 
        std::shared_ptr<Node> head;
        
    public:
        List<T>() : head(std::shared_ptr<Node>(new Node)) {
            head -> prev = head;
        }
        
        // For simplity, disable the following functions
        List<T>(const List<T>& other) = delete;
        List<T>(List<T>&& other) = delete;
        List<T>& operator = (const List<T> & other) = delete;
        List<T>& operator = (List<T> && other) = delete;
        
        // No need to release memory with Destructor
        virtual ~List<T>() {}
        
        bool empty() {
            return head->prev.lock() == head; 
        }
        
        // we can traverse the shared_ptr list now! 
        void traverse_list() {
            std::shared_ptr<Node> h = head;
            while (h) {
                if (h->next) {
                    std::cout << h->next->data << " ";
                }
                h = h->next; 
            }
            std::cout << std::endl;
        }

        
        void push_back(T d) {
            // The "next" pointer of the last node of the looped-doubly-linked list must be nullptr 
            // No need to point to "head", as which can find the last node by "prev"
            std::shared_ptr<Node> pNode = std::make_shared<Node>(d);
            pNode->prev = head->prev;
            head->prev = pNode;
            pNode->prev.lock()->next = pNode;
        }
        
        void push_front(T d) {
            std::shared_ptr<Node> pNode = std::make_shared<Node>(d);
            pNode->next = head->next;
            pNode->prev = head;
            head->next->prev = pNode; 
            head->next = pNode;
        }
        
        void pop_front() {
            if (empty()) return;
            
            std::shared_ptr<Node> tmp = head->next;
            head->next = tmp->next; 
            if(tmp->next) {
                tmp->next->prev = head;
            }
        }
        
        void pop_back() {
            if (empty()) return; 
            
            std::weak_ptr<Node> tmp = head->prev; 
            head->prev = tmp.lock()->prev.lock(); 
            tmp.lock()->prev.lock()->next = std::shared_ptr<Node>();
        }
        
        T& front() {
            return head->next->data;
        }
        
        T& back() {
            return head->prev.lock()->data;
        }
    };
}

#endif
