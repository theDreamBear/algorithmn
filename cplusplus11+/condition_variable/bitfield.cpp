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

struct IpHeader {
     unsigned int version:4;
     unsigned int header_len:4;
     unsigned int tos:8;
     unsigned int total_len:16;

     unsigned int identifying:16;
     unsigned int flag:3;
     unsigned int off_set:13;

     unsigned int ttl:8;
     unsigned int protocol:8;
     unsigned int check_sum:16;

     unsigned int source_ip;

     unsigned int destination_ip;
};

int main() {
    IpHeader header;
    header.version = 0;
    header.header_len = 20;
    header.tos = 0;
    header.total_len = 20;
    header.identifying = 0;
    header.flag = 0;
    header.off_set = 0;
    header.ttl = 0;
    header.protocol = 4;
    header.check_sum = 0;
    header.source_ip = 123;
    header.destination_ip = 234;

    cout << sizeof(header) << endl;
}