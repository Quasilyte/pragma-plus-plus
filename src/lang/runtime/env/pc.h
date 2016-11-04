#pragma once

#include "project/project.h"

//! @brief Program counter which controls execution
STRUCT(ProgramCounter);

//! @brief ProgramCounter constructor
ProgramCounter* new_pc(const byte* code);

//! @brief ProgramCounter destructor
void delete_pc(ProgramCounter*);

//! @see frame_exchange; this function has same notes and warnings
ProgramCounter* pc_excange(ProgramCounter*);

//! @brief Perform an unconditional jump using relative offset
void pc_jump_rel(i16 offset);

//! @brief Perform an unconditional jump using absolute offset
void pc_jump_abs(u64 offset);

//! @brief Get current ProgramCounter offset
u64 pc_offset(void);

/*!
 * @defgroup pc_fetch_<T>
 * @brief Fetch required type from program stream; PC is moved after fetch
 */
//!{
byte pc_fetch_byte(void);
i16 pc_fetch_i16(void);
i32 pc_fetch_i32(void);
i64 pc_fetch_i64(void);
u32 pc_fetch_u32(void);
//!}
