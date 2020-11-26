#include <iostream>
#include <vector>
#include <algorithm>
#include <sys/time.h>
#include <type_traits>
#include <condition_variable>
#include <thread>
#include <mutex>
#include <future>
#include <iostream>
using namespace  std;

class semaphore {
 public:
    semaphore(int value) {
        this->_count = value;
    }

    void wait() {
        unique_lock<mutex> mu(_mu);
        if (--_count < 0) {
            _cv.wait(mu);
        }
    }

    void signal() {
        unique_lock<mutex> mu(_mu);
        ++_count;
        mu.unlock();
        _cv.notify_one();
    }
 private:
    int _count;
    mutex _mu;
    condition_variable _cv;
};

semaphore sf(0), se(1);

[[noreturn]] void producer() {
    while (true) {
        se.wait();
        cout << "producer" << endl;
        sf.signal();
        std::this_thread::yield();
    }
}

[[noreturn]] void consumer() {
    while (true) {
        sf.wait();
        cout << "consumer" << endl;
        se.signal();
        std::this_thread::yield();
    }
}

int main() {
    thread t(producer);
    consumer();
    t.join();
}