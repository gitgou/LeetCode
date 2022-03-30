#include<iostream>
#include<semaphore.h>
using namespace std;

class FooBar {
private:
    int n;
    sem_t sem_foo, sem_bar;

public:
    FooBar(int n) {
        this->n = n;
        sem_init(&sem_foo, 0, 0);
        sem_init(&sem_bar, 0, 1);
    }

    ~FooBar()
    {
        sem_destroy(&sem_foo);
        sem_destroy(&sem_bar);
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            sem_wait(&sem_bar);
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            sem_post(&sem_foo);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            sem_wait(&sem_foo);
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            sem_post(&sem_bar);
        }
    }
};

int main()
{

}