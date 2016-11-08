#ifndef _MAMEDBG_H
#define _MAMEDBG_H

#include "mame.h"

#define DEBUGGER_TOTAL_COLORS 16

/* If this flag is set, a CPU core should call MAME_Debug from it's execution loop */
extern int mame_debug;

#define CALL_MAME_DEBUG
#define debugger_idle 0

#endif  /* !MAME_DEBUG */
