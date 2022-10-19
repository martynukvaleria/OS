#ifndef BUFFERED_CHANNEL_H_
#define BUFFERED_CHANNEL_H_

#include <utility>
#include <queue>
#include <condition_variable>
#include <iostream>

template<class T>
class BufferedChannel {

private:
    int buffer_size{};
    bool isClosed{};
    std::queue<T> channel;
    std::mutex mutex;
    std::condition_variable condition_variable;
public:

    explicit BufferedChannel(int size) : buffer_size(size), isClosed(false) {}

    void Send(T value) {
        std::unique_lock<std::mutex> lock;
        if (isClosed) {
            throw std::runtime_error(" ");
        }
        condition_variable.wait(lock, [&] { return channel.size() != buffer_size; });
        channel.push(std::move(value));
        std::cout << "you added " << value << " value" << '\n';
//        lock.unlock();
        condition_variable.notify_one();
    }

    std::pair<T, bool> Recv() {
        std::unique_lock<std::mutex> lock(mutex);
        condition_variable.wait(lock, [&] { return !channel.empty(); });
        T value = channel.front();
        channel.pop();
        std::cout << "you deleted " << value << " value" << '\n';
//        lock.unlock();
        condition_variable.notify_one();
        return std::pair<T, bool>(value, !isClosed);
    }

    void Close() {
        std::lock_guard<std::mutex> lkg(mutex);
        isClosed = true;
        std::cout << "channel was closed" << '\n';
        condition_variable.notify_one();
    }
};

#endif // BUFFERED_CHANNEL_H_