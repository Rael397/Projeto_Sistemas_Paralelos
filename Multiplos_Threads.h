#pragma once
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>
#include "area_base.h"
#include "area_lateral.h"
#include "area_total.h"

namespace threading {
    void uso_threads() {
        int area_base = 0;
        int area_lateral = 0;
        int area_total = 0;
        int num_threads = 3;
        printf("\n----------------------------------------------------------------------------------------------------------\n");
        printf("\nIniciando execucao dos calculos em single threaded\n");
        printf("\n----------------------------------------------------------------------------------------------------------\n");
        // Executa em 1 thread
        auto start = std::chrono::high_resolution_clock::now();
        area_base = base::Area();
        area_lateral = lateral::area_lateral();
        area_total = soma_total::total(area_base, area_lateral);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        printf("\n----------------------------------------------------------------------------------------------------------\n");
        printf("\nTempo de execucao com 1 thread: %f segundos\n", duration.count());
        printf("\n----------------------------------------------------------------------------------------------------------\n");
        printf("\nExecucao em single threaded finalizada\n");
        printf("\n----------------------------------------------------------------------------------------------------------\n");
        // Executa em 3 threads
        printf("\n----------------------------------------------------------------------------------------------------------\n");
        printf("\nIniciando execucao de calculos em multi threaded\n");
        printf("\n----------------------------------------------------------------------------------------------------------\n");
        start = std::chrono::high_resolution_clock::now();
        std::vector<std::thread> threads;
        std::mutex mutex;
        int calculos_completos = 0;
        threads.push_back(std::thread([&] {
            area_base = base::Area();
            std::unique_lock<std::mutex> lock(mutex);
            calculos_completos++;
            }));
        threads.push_back(std::thread([&] {
            area_lateral = lateral::area_lateral();
            std::unique_lock<std::mutex> lock(mutex);
            calculos_completos++;
            }));
        threads.push_back(std::thread([&] {
            std::unique_lock<std::mutex> lock(mutex);
            while (calculos_completos < 2) {
                lock.unlock();
                std::this_thread::yield();
                lock.lock();
            }
            area_total = soma_total::total(area_base, area_lateral);
            }));
        for (auto& thread : threads) {
            thread.join();
        }
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        printf("\n----------------------------------------------------------------------------------------------------------\n");
        printf("\nTempo de execucao com %d threads: %f segundos\n", num_threads, duration.count());
        printf("\n----------------------------------------------------------------------------------------------------------\n");
        printf("\nExecucao multi threaded finalizada\n");
        printf("\n----------------------------------------------------------------------------------------------------------\n");

    }
}

