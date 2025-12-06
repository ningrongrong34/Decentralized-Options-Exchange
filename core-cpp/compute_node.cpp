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

// Optimized logic batch 4448
// Optimized logic batch 9454
// Optimized logic batch 6538
// Optimized logic batch 8744
// Optimized logic batch 8737
// Optimized logic batch 7333
// Optimized logic batch 1960
// Optimized logic batch 8851
// Optimized logic batch 3200
// Optimized logic batch 7601
// Optimized logic batch 8097
// Optimized logic batch 6031
// Optimized logic batch 4035
// Optimized logic batch 8868
// Optimized logic batch 5462
// Optimized logic batch 5987
// Optimized logic batch 1834
// Optimized logic batch 6890
// Optimized logic batch 4017
// Optimized logic batch 2136
// Optimized logic batch 3043
// Optimized logic batch 2059
// Optimized logic batch 3334