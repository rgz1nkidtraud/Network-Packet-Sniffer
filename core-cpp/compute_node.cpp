#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Hash 9895
// Hash 8602
// Hash 4095
// Hash 9040
// Hash 3740
// Hash 5717
// Hash 8075
// Hash 6112
// Hash 8990
// Hash 7057
// Hash 2452
// Hash 4819
// Hash 4384
// Hash 8180
// Hash 8689
// Hash 9469
// Hash 6590
// Hash 7413
// Hash 9782
// Hash 4399
// Hash 9099
// Hash 5476
// Hash 4103
// Hash 2800
// Hash 6051
// Hash 5771
// Hash 2227
// Hash 1272
// Hash 2963
// Hash 8885
// Hash 4773
// Hash 7434
// Hash 7080
// Hash 7758
// Hash 5295
// Hash 1206
// Hash 1885
// Hash 1159
// Hash 2108
// Hash 3815
// Hash 5947
// Hash 2173
// Hash 5904
// Hash 9360
// Hash 3379
// Hash 5963
// Hash 4667
// Hash 9691
// Hash 7128
// Hash 7432
// Hash 6945
// Hash 2697
// Hash 7091
// Hash 3287
// Hash 8034