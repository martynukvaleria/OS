#include <thread>
#include "buffered_channel.h"

void Test_1(BufferedChannel<int> &bufferedChannel) {
    bufferedChannel.Send(1);
    bufferedChannel.Send(2);
    bufferedChannel.Send(3);
    bufferedChannel.Send(4);
    bufferedChannel.Send(5);
    bufferedChannel.Send(6);
    bufferedChannel.Send(7);
}

void Test_2(BufferedChannel<int> &bufferedChannel) {
    bufferedChannel.Recv();
    bufferedChannel.Recv();
    bufferedChannel.Recv();
    bufferedChannel.Recv();
    bufferedChannel.Recv();
    bufferedChannel.Recv();
    bufferedChannel.Recv();
}


int main() {
    BufferedChannel<int> bufferedChannel(7);

    std::vector<std::thread> threads;
    for (int i = 0; i < 7; ++i) {
        threads.emplace_back(Test_1, std::ref(bufferedChannel));
        threads.emplace_back(Test_2, std::ref(bufferedChannel));
    }
    for (auto &thread: threads) { thread.join(); }
    return 0;
}
