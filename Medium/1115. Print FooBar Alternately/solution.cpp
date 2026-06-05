#include <functional>
#include <mutex>
#include <condition_variable>

class FooBar {
private:
    int n;
    std::mutex mtx;
    std::condition_variable cv;
    bool foo_turn = true;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(
                lock, 
                [this]()
                {
                    return foo_turn;
                }
            ); 
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();

            foo_turn = false;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(
                lock,
                [this]()
                {
                    return !foo_turn;
                }
            );

        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();

            foo_turn = true;
            cv.notify_one();
        }
    }
};