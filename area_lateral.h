#pragma once
#include <stdio.h>

namespace lateral {

	int area_lateral() {
		int lado = 3;
		int area_quadrado = lado * lado;
		printf("\nArea Lateral eh: %d\n", area_quadrado);
		return area_quadrado;
	}
}

