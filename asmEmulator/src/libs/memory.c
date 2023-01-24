typedef struct
{
    uint8_t zero : 1;
    uint8_t sign : 1;
    uint8_t overflow : 1;
} flags_t;

typedef struct
{
    uint16_t size;
    uint8_t *buffer;
    uint8_t *dataoffset;
    flags_t flags;
} asm_memory_t;

static inline asm_memory_t new_asm_memory(uint16_t size)
{
    uint8_t *b = (uint8_t *)calloc(size, 1);
    return (asm_memory_t){
        .size = size,
        .buffer = b,
        .dataoffset = b,
    };
}

static inline void asm_memory_clear(asm_memory_t mem)
{
    memset(mem.buffer, 0, mem.size);
}

uint8_t *asm_memory_alloc(asm_memory_t *mem, uint16_t size)
{
    mem->dataoffset = (uint8_t *)((uint64_t)mem->dataoffset + (uint64_t)size);
    return (uint8_t *)((uint64_t)mem->dataoffset - (uint64_t)size);
}