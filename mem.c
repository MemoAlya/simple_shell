#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ssize_t _memchr(const void *src, unsigned char chr, size_t n) {
    const unsigned char *mem = src;
    
    for (size_t i = 0; i < n; i++) {
        if (mem[i] == chr)
            return i;
    }
    
    return -1;
}

void *_memcpy(void *dest, const void *src, size_t n) {
    return memcpy(dest, src, n);
}

void *_memdup(const void *src, size_t n) {
    void *dup = malloc(n);
    if (dup)
        memcpy(dup, src, n);
    return dup;
}

void *_memset(void *dest, unsigned char chr, size_t n) {
    return memset(dest, chr, n);
}

