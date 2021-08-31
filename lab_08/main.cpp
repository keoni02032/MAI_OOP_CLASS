#include <iostream>
#include <vector>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "factory.hpp"
#include "subscriber.hpp"
#include "rhombus.hpp"
#include "pentagon.hpp"
#include "hexagon.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "./lab8 N\n";
        return 0;
    }

    unsigned int BufSize = std::atoi(argv[1]);
    std::vector<std::shared_ptr<figure>> f;
    int command = 1;
    factory factory;
    bool done = false;
    std::condition_variable rd;
    std::condition_variable hd;
    std::mutex mutex;
    int in = 1;
    std::vector<std::shared_ptr<sub>> s;
    s.push_back(std::make_shared<PrintC>());
    s.push_back(std::make_shared<PrintF>());

    std::thread sub([&]() {
        std::unique_lock<std::mutex> sub_lock(mutex);
        while (!done) {
            rd.wait(sub_lock);
            if (done) {
                hd.notify_all();
                break;
            }
            for (unsigned int i = 0; i < s.size(); i++) {
                s[i]->Print(f);
            }
            in++;
            f.resize(0);
            hd.notify_all();
        }
    });

    std::cout << "Для начала программы введите 1" << "\n" << "Для выхода введите 0" << "\n";

    while(command != 0) {
        std::cin >> command;
        if (command != 0) {
            std::unique_lock<std::mutex> main_lock(mutex);
            for (unsigned int i = 0; i < BufSize; i++) {
                f.push_back(factory.FigureCreate(std::cin));
                if (f.size() == BufSize) {
                    std::cout << "Buffer is full!\n";
                }
            }
            rd.notify_all();
            hd.wait(main_lock);
            std::cout << "Для продолжения введите 1" << "\n" << "Для выхода введите 0" << "\n";
        } else {
            done = true;
            rd.notify_all();
            sub.join();
            return 0;
        }
    }

    done = true;
    rd.notify_all();
    sub.join();
    return 0;
}