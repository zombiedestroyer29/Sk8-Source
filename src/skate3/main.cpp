#include <iostream>
#include "./include/defs.h"
int sub_82370000(int result, int a2, int a3, int (__fastcall *a4)(int)) {
    /* First call in this function (bl at addr 82370004) is for stack setup, 
    this should not need to be implemented.*/
    v6 = a3 - 1;
    for (i = a2 * a3 + result; v6 >= 0; --v6) {
        i -= a2;
        result = a4(i);
    }
    // 82370040 - More stack setup.
    return result;
}
int sub_82370048(int result, int a2, int a3, int (__fastcall *a4)(int)) {
    // 8237004C - Stack setup.
    v4 = result;
    for (i = a3 - 1; i >= 0; v4 += a2) {
        result = a4(v4);
        --i
    }
    // 82370084 - Stack setup.
    return result;
}
int sub_82370088(unsigned int a1){
    unsigned int qword_822F4500 = 0xDA8BB8E6405779F1;
    v1 = 0;
    while(1) {
        v2 = &qword_822F4500[2 * v1];
        v3 = *v2;
        if (*((_DWORD *)v2 + 1) == a1)
            break;
        v1 = 2 * HIDWORD(v3) + (*((_DWORD *)v2 + 1) < a1) + 1;
        if (v1 >= 0xE)
            return 0;
    }
    result = v2;
    if (HIDWORD(v3) >= 0xE)
        result = 0;
    return result;
}