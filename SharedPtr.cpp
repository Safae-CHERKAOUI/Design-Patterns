#include <iostream>


template<typename T>

class SharedPtr {
private:
    T* ptr;
    int* refCount;

public:
    SharedPtr(T* p){
        ptr=p;
        refCount=new int(1);
    } 
    ~SharedPtr() {
        decrementRefCount();
    }


    SharedPtr(const SharedPtr& other){
        ptr=other.ptr;
        refCount= other.refCount;
        incrementRefCount();
    }
        
    SharedPtr& operator=(const SharedPtr& other) {
        if (this != &other) {
            decrementRefCount();
            ptr = other.ptr;
            refCount = other.refCount;
            incrementRefCount();
        }                                                                             
        return *this;
    }

    T& operator*() const {
        return *ptr;
    }

    T* get() const {
        return ptr;
    }


    int use_count() const {
        return *refCount;
    }

private:
    void incrementRefCount() {
        (*refCount)++;
        std::cout<<"Reference incremented"<<std::endl;
    }

    void decrementRefCount() {
        if (*refCount>0){
        (*refCount)--;
        std::cout<<"Decrement RefCount"<<std::endl;}
        if (*refCount == 0) {
            delete ptr;
            delete refCount;
            std::cout<<"Ptr Deleted"<<std::endl;
        }
    }
};


int main(){

SharedPtr<int> ptr1(new int(10));
std::cout<<*ptr1;
SharedPtr<int> ptr2 = ptr1;
SharedPtr<int> ptr3 = ptr2;
SharedPtr<int> ptr4 = ptr3;
std::cout<<ptr4.use_count()<<std::endl;
SharedPtr<int> ptr5(new int(30));
ptr4=ptr5;
std::cout<<ptr4.use_count()<<std::endl;
std::cout<<*ptr3<<std::endl;
std::cout<<*ptr1<<std::endl;
int* rawPtr1 = ptr1.get();
int* rawPtr2 = ptr2.get();
int* rawPtr3 = ptr3.get();
int* rawPtr4 = ptr3.get();
std::cout<<rawPtr1<<std::endl;
std::cout<<rawPtr2<<std::endl;
std::cout<<rawPtr3<<std::endl;
std::cout<<rawPtr4<<std::endl;


}