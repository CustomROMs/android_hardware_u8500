int ump_mapped_pointer_release(int a1) {
    int result = *(int *)(a1 + 4); // 0x1458
    if (result != 0) {
        // 0x146c
        int r2 = *(int *)(a1 + 8);
        ump_arch_unlock(*(int *)(a1 + 20), result, r2);
        // branch -> 0x1478
    } else {
        result = a1;
    }
    // 0x1478
    *(int *)(a1 + 4) = 0;
    return result;
}
