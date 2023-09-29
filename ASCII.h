#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

namespace ASCII {
    void printAscii(float  start, float end) {
        for (int i = start; i < end; ++i) {
            std::cout << "ASCII " << i << ": " << static_cast<char>(i) << std::endl;
        }
    }

    int multi_thread_ASCII() {
        int NUM_THREADS = 4;
        auto start = std::chrono::high_resolution_clock::now();

        std::vector<std::thread> threads;
        int range = 128 / NUM_THREADS;

        for (int i = 0; i < NUM_THREADS; ++i) {
            int startChar = i * range;
            int endChar = (i == NUM_THREADS - 1) ? 128 : (i + 1) * range;
            threads.emplace_back(printAscii, startChar, endChar);
        }

        for (std::thread& thread : threads) {
            thread.join();
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        float seconds = duration.count() / 1e6;
        printf("\n----------------------------------------------------------------------------------------------------------\n");
        std::cout << "Tempo de execucao para imprimir tabela ASCII com " << NUM_THREADS << " threads: " << seconds << " segundos\n" << std::endl;

        return 0;
    }

    int single_thread_ASCII() {
        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < 128; ++i) {
            std::cout << "ASCII " << i << ": " << static_cast<char>(i) << std::endl;
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        float seconds = duration.count() / 1e6;
        printf("\n----------------------------------------------------------------------------------------------------------\n");
        std::cout << "Tempo de execucao para imprimir tabela ASCII com 1 thread: " << seconds << " segundos" << std::endl;

        return 0;
    }
}
