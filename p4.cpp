#include <stdio.h>
#include <chrono>
#include "area_base.h"
#include "area_lateral.h"
#include "area_total.h"
#include "loop.h"
#include "ASCII.h"
#include "Multiplos_Threads.h"



int main() {
	threading::uso_threads();
	printf("\n----------------------------------------------------------------------------------------------------------\n");
	printf("\nIniciando a execucao do loop single threaded\n");
	printf("\n----------------------------------------------------------------------------------------------------------\n");
	loop::single_thread_loop();
	printf("\n----------------------------------------------------------------------------------------------------------\n");
	printf("\nA execucao do loop single threaded terminou\n");
	printf("\n----------------------------------------------------------------------------------------------------------\n");
	printf("\nIniciando a execucao do loop multi threaded\n");
	printf("\n----------------------------------------------------------------------------------------------------------\n");
	loop::multi_thread_loop();
	printf("\n----------------------------------------------------------------------------------------------------------\n");
	printf("\nA execucao do loop multi threaded terminou\n");
	printf("\n----------------------------------------------------------------------------------------------------------\n");
	printf("\n----------------------------------------------------------------------------------------------------------\n");
	printf("\nIniciando a execucao single threaded do print da tabela ASCII\n");
	printf("\n----------------------------------------------------------------------------------------------------------\n");
	ASCII::single_thread_ASCII();
	printf("\n----------------------------------------------------------------------------------------------------------\n");
	printf("\nExecucao single threaded da tabela ASCII finalizada\n");
	printf("\n----------------------------------------------------------------------------------------------------------\n");
	printf("\nIniciando a execucao multi threaded do print da tabela ASCII\n");
	printf("\n----------------------------------------------------------------------------------------------------------\n");
	ASCII::multi_thread_ASCII();
	printf("\n----------------------------------------------------------------------------------------------------------\n");
	printf("\nExecucao multi threaded da tabela ASCII finalizada\n");
	printf("\n----------------------------------------------------------------------------------------------------------\n");

	return 0;
}

