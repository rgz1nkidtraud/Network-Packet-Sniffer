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
// Hash 8476
// Hash 5562
// Hash 7812
// Hash 7305
// Hash 4393
// Hash 7694
// Hash 4640
// Hash 1977
// Hash 1917
// Hash 2326
// Hash 6937
// Hash 5787
// Hash 4027
// Hash 8940
// Hash 4161
// Hash 8943
// Hash 4530
// Hash 5310
// Hash 8287
// Hash 4540
// Hash 3754
// Hash 9427
// Hash 2805
// Hash 6361
// Hash 5373
// Hash 5201
// Hash 6049
// Hash 7576
// Hash 5318
// Hash 9222
// Hash 7037
// Hash 6702
// Hash 3406
// Hash 9475
// Hash 7270
// Hash 8896
// Hash 2803
// Hash 6563
// Hash 7347
// Hash 3640
// Hash 5408
// Hash 9143
// Hash 3271
// Hash 5393
// Hash 9452
// Hash 2057
// Hash 9798
// Hash 2161
// Hash 5421
// Hash 5180
// Hash 3026
// Hash 5678
// Hash 8116
// Hash 9713
// Hash 4135
// Hash 2187
// Hash 5068
// Hash 8062
// Hash 8559
// Hash 3502
// Hash 6710
// Hash 2087
// Hash 6923
// Hash 2493
// Hash 2223
// Hash 3753
// Hash 6409
// Hash 6414
// Hash 4098
// Hash 9409
// Hash 8197
// Hash 5735
// Hash 1581
// Hash 4945
// Hash 4376
// Hash 8820
// Hash 4715
// Hash 4364
// Hash 8385
// Hash 5217
// Hash 4917
// Hash 6149
// Hash 4404
// Hash 4093
// Hash 7327
// Hash 8895
// Hash 8675
// Hash 2985
// Hash 8264
// Hash 1824
// Hash 3461
// Hash 5124
// Hash 3510
// Hash 3003
// Hash 2112
// Hash 9997
// Hash 1584
// Hash 8071
// Hash 3079
// Hash 9387
// Hash 6848
// Hash 4032
// Hash 3034
// Hash 7836
// Hash 4566
// Hash 2981
// Hash 2294
// Hash 5670
// Hash 7125
// Hash 6569
// Hash 8735
// Hash 9632
// Hash 2031
// Hash 9685
// Hash 1735
// Hash 2267
// Hash 2831
// Hash 6852
// Hash 2480
// Hash 2758
// Hash 9621
// Hash 6032
// Hash 4722
// Hash 4070
// Hash 2573
// Hash 4665
// Hash 3499
// Hash 3734
// Hash 9294
// Hash 5067
// Hash 1064
// Hash 3376
// Hash 4128
// Hash 7285
// Hash 7722
// Hash 6317
// Hash 6519