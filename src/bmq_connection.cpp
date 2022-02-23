#include <bmq/hex.h>
#include "bmq/bmq.h"
#include "bmq/connections.h"
#include <bits/stdc++.h>
#include <iostream>
#include <thread>
#include <vector>
using namespace std;
using namespace bmq;
int main()
{
    std::cout << "main called 's " << std::endl;
    using LMQ_ptr = std::shared_ptr<bmq::BMQ>;
    LMQ_ptr m_LMQ = std::shared_ptr<bmq::BMQ>();
     m_LMQ->start();
 std::cout << "before connect remote ";
    std::cout << "before connect remote ";
auto c = m_LMQ->connect_remote("tcp://192.168.1.49:4567",
      [](ConnectionID conn) { std::cout << "Connected \n";},
      [](ConnectionID conn, std::string f) { std::cout << "connect failed: \n";}
      );
    //   Request req{}
      m_LMQ->request(c, "rpc.get_hashes", [](bool s, std::vector<std::string> d) {
            if (s && d.size() == 2)
            std::cout << "Current height: " << d[1] << "\n";
            else
            std::cout << "Timeout fetching height!";
        });
        // std::this_thread::sleep_for(20s);
}
