#include <iostream>
 
class Singleton {

private:
    // Private constructor to prevent external instantiation
    Singleton()
    {
        std::cout << "Singleton instance created."
                  << std::endl;
    }
 
    // Private static instance variable
    static Singleton* instance;

public:
    // Static method to access the singleton instance
    static Singleton& getInstance()
    {
        // If the instance doesn't exist, create it
        if (!instance) {
            instance = new Singleton();
        }
        return *instance;
    }
 
 
    // Delete the copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
 

};
 
// Initialize the static instance variable to nullptr
Singleton* Singleton::instance = nullptr;
 
int main()
{
    Singleton& instance1 = Singleton::getInstance();
    Singleton& instance2 = Singleton::getInstance();

    // instance1 and instance2 refer to the same object
    if (&instance1 == &instance2) {
        std::cout << "Both instances refer to the same object." << std::endl;
    } else {
        std::cout << "Error: Different instances detected." << std::endl;
    }
    return 0;
}