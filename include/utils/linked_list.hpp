#ifndef GOINTERPRETER_UTILS_LINKED_LIST_HPP
#define GOINTERPRETER_UTILS_LINKED_LIST_HPP

#include <vector>

template<class T>
class LinkedList
{
private:
    struct Item {
    public:
        ~Item()
        {
            if (this->tail != nullptr) {
                delete this->tail;
            }
        }

        void toStdVector(std::vector<T> &v) const
        {
            v.push_back(this->value);
            if (this->tail != nullptr) {
                this->tail->toStdVector(v);
            }
        }
        
        T value;
        Item *tail;
    };

    Item *head;

public:
    LinkedList(): head{nullptr} {}
    ~LinkedList()
    {
        delete this->head;
    }

    [[nodiscard]] long size() const
    {
        long size = 0;
        auto ptr = this->head;

        while (ptr != nullptr) {
            ++size;
            ptr = ptr->tail;
        }
        
        return size;
    }

    [[nodiscard]] T get(long index) const
    {
        long current = 0;
        auto ptr = this->head;

        if (index >= this->size()) {
            throw std::runtime_error("Index out of bounds");
        }

        while (current != index) {
            ++current;
            ptr = ptr->tail;
        }
        
        return ptr->value;
    }

    void insert(long index, T value)
    {
        long current = 0;
        LinkedList<T>::Item *last = nullptr;
        auto ptr = this->head;

        if (index > this->size()) {
            throw std::runtime_error("Index out of bounds");
        }

        auto item = new Item{};
        item->value = value;

        while (current != index) {
            ++current;
            last = ptr;
            ptr = ptr->tail;
        }
        
        item->tail = ptr;

        if (last == nullptr) {
            this->head = item;
        } else {
            last->tail = item;
        }
    }

    std::vector<T> toStdVector() const
    {
        std::vector<T> result;
        if (this->head != nullptr) {
            this->head->toStdVector(result);
        }
        return result;
    }
};

#endif // GOINTERPRETER_UTILS_LINKED_LIST_HPP