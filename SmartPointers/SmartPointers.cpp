#include <iostream>


template<class T>
class unique_ptr {
public:
    unique_ptr() : ptr(nullptr) {}
    unique_ptr(const unique_ptr& sp) = delete;
    unique_ptr(T* ptr) {
        this->ptr = ptr;
    }

    ~unique_ptr() {
        delete ptr;
    }

    T& operator*() {
        return *ptr;
    }

    T* get() {
        return ptr;
    }

    void reset() {
        delete ptr;
        ptr = nullptr;
    }

    void realese() {
        ptr = nullptr;
    }

    void swap(unique_ptr<T>& p){
        std::swap(ptr, p.ptr);
    }

private:
    T* ptr;
};


template<class T>
class shared_ptr {
public:
    shared_ptr() : ptr(nullptr),count(nullptr) {}
    shared_ptr(T* ptr) {
        this->ptr = ptr;
        count = new int(1);
    }

    shared_ptr(const shared_ptr& p) {
        ptr = p.ptr;
        count = p.count;
        (*count)++;
    };

    ~shared_ptr() {
        if (*count > 1) {
            (*count)--;
            return;
        }
        else {
            delete ptr;
        }
    }

    T& operator*() {
        return *ptr;
    }

    T* get() {
        return ptr;
    }

    void reset() {
        ptr = nullptr;
    }

    void swap(shared_ptr<T>& p) {
        std::swap(ptr, p.ptr);
    }

    void operator=(shared_ptr<T>& p) {
        ptr = p.ptr;
        count = p.count;
        (*count)++;
    }

    int use_count() {
        return *count;
    }

private:
    T* ptr;
    int* count;
};

int main()
{
    /*shared_ptr<int> p(new int(5));
    shared_ptr<int> p2;
    std::cout << p.use_count() << std::endl;
    p2 = p;
    std::cout << p.use_count() << std::endl;

    std::cout << "---------------------------------------------------\n";

    shared_ptr<int> y;
    std::cout << p.use_count() << std::endl;
    y = p2;
    std::cout << p.use_count() << std::endl;*/


    unique_ptr<int> p(new int(8));
    //unique_ptr<int> p2(p);
    unique_ptr<int> p2;
    p2.swap(p);
    std::cout << "p2 " << *p2 << std::endl;

    int* ptr = new int(5);
    unique_ptr<int> pt(ptr);
    pt.reset();


    int* ptr2 = new int(7);
    unique_ptr<int> pt2(ptr);
    pt2.realese();
    
    return 0;
}

