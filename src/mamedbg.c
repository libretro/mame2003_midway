/****************************************************************************
 *	MAME debugger V0.54
 *	Juergen Buchmueller <pullmoll@t-online.de>
 *
 *	Based on code found in the preivous version of the MAME debugger
 *	written by: Martin Scragg, John Butler, Mirko Buffoni
 *	Chris Moore, Aaron Giles, Ernesto Corvi
 *
 *	Online help is available by pressing F1 (context sensitive!)
 *
 *	TODO:
 *	- Add stack view using activecpu_get_reg(REG_SP_CONTENTS+offset)
 *	- Add more display modes for the memory windows (binary? octal? decimal?)
 *
 ****************************************************************************/

#include <stdio.h>


