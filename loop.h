#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>


namespace loop {
    void task(int n) {
        for (int i = 0; i < n; i++) {
            printf("\nExecutando o loop, a iteracao esta em: %d\n", i);
        }
    }

    int single_thread_loop() {
        printf("\nExecucao do loop single threaded iniciada\n");
        int n = 100;

        auto start = std::chrono::high_resolution_clock::now();
        task(n);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        printf("\n----------------------------------------------------------------------------------------------------------\n");
        std::cout << "Tempo de execucao do loop com um unico thread: " << duration.count() << " segundos\n";
        printf("\n----------------------------------------------------------------------------------------------------------\n");
        return 0;
    }

    int multi_thread_loop() {
        printf("\nExecucao do loop multi threaded iniciada\n");
        int n = 100;
        int num_threads = 4;
        auto start = std::chrono::high_resolution_clock::now();
        std::vector<std::thread> threads;
        for (int i = 0; i < num_threads; i++) {
            threads.push_back(std::thread(task, n / num_threads));
        }
        for (auto& thread : threads) {
            thread.join();
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        printf("\n----------------------------------------------------------------------------------------------------------\n");
        std::cout << "Tempo de execucao do loop com " << num_threads << " threads: " << duration.count() << " segundos\n";
        printf("\n----------------------------------------------------------------------------------------------------------\n");

        return 0;
    }
}

