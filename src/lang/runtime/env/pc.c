#include "lang/runtime/env/pc.h"

#include "cstd/stdlib.h"

STRUCT(ProgramCounter) {
  const byte* top;
  const byte* ptr;
};

static const byte* pc_top;
static const byte* pc_ptr;

ProgramCounter* current_pc = NULL;

ProgramCounter* new_pc(const byte* code) {
  ProgramCounter* pc = malloc(sizeof(ProgramCounter));

  pc->top = code;
  pc->ptr = code;

  return pc;
}

void delete_pc(ProgramCounter* f) {
  free(f);
}

ProgramCounter* pc_excange(ProgramCounter* new_pc) {  
  ProgramCounter* old_pc = current_pc;
  if (old_pc) {
    old_pc->ptr = pc_ptr;
  }

  pc_ptr = new_pc->ptr;
  pc_top = new_pc->top;

  current_pc = new_pc;

  return old_pc;
}

void pc_jump_rel(i16 offset) {
  pc_ptr += offset;
}

void pc_jump_abs(u64 offset) {
  pc_ptr = pc_top + offset;
}

u64 pc_offset(void) {
  return pc_ptr - pc_top;
}

byte pc_fetch_byte(void) {
  return *pc_ptr++;
}

#define GEN_FETCH(T) \
  T pc_fetch_##T(void) { \
    T result = *(T*)pc_ptr; \
    pc_ptr += sizeof(T); \
    return result; \
  }

GEN_FETCH(i16)
GEN_FETCH(i32)
GEN_FETCH(i64)
GEN_FETCH(u32)
