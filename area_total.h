#pragma once
#include <stdio.h>
#include "area_base.h"
#include "area_lateral.h"


namespace soma_total {
    int total(int area_base, int area_lateral) {
        int area_total = 2 * (area_base + area_lateral);
        printf("\nArea total da figura eh: %d\n", area_total);
        return 0;
    }
}
