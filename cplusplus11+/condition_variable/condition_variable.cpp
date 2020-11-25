#include <iostream>
#include <vector>
#include <algorithm>
#include <sys/time.h>
#include <type_traits>
#include <condition_variable>
#include <thread>
#include <mutex>
#include <future>

using namespace  std;

condition_variable cv;
//
bool ready = false;
#define MAX 1
mutex m;

void producer() {
    while (true) {
        unique_lock<mutex> mu(m);
        if (!ready) {
            cv.wait(mu);
        }
        mu.unlock();
        cout << "start producer\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void consumer() {
    while (true) {
        unique_lock<mutex> mu(m);
        ready = true;
        mu.unlock();
        cv.notify_all();
        cout << "start consumer\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int main() {
    thread c(consumer);
    //thread p(producer);
    producer();
    c.join();
}