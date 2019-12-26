#include <stddef.h>
#include <stdint.h>
#include <arm/atag.h>

#ifndef MEM_H
#define MEM_H

typedef struct {
    uint8_t allocated: 1;           // This page is allocated to something
    uint8_t kernel_page: 1;         // This page is a part of the kernel
    uint32_t reserved: 30;
} page_flags_t;

typedef struct page {
    uint32_t vaddr_mapped;  // The virtual address that maps to this page   
    page_flags_t flags;
} page_t;

size_t get_mem_size(atag_t* tag);

#endif
