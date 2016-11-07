/******************************************************************************

  driver.c

  The list of all available drivers. Drivers have to be included here to be
  recognized by the executable.

  To save some typing, we use a hack here. This file is recursively #included
  twice, with different definitions of the DRIVER() macro. The first one
  declares external references to the drivers; the second one builds an array
  storing all the drivers.

******************************************************************************/

#include "driver.h"


#ifndef DRIVER_RECURSIVE

/* The "root" driver, defined so we can have &driver_##NAME in macros. */
struct GameDriver driver_0 =
{
	__FILE__,
	0,
	"",
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	NOT_A_DRIVER
};

#endif

#ifdef TINY_COMPILE

extern struct GameDriver TINY_NAME;

const struct GameDriver *drivers[] =
{
	TINY_POINTER,
	0	/* end of array */
};

const struct GameDriver *test_drivers[] =
{
	0	/* end of array */
};

#else

#ifndef DRIVER_RECURSIVE

#define DRIVER_RECURSIVE

/* step 1: declare all external references */
#define DRIVER(NAME) extern struct GameDriver driver_##NAME;
#define TESTDRIVER(NAME) extern struct GameDriver driver_##NAME;
#include "driver.c"

/* step 2: define the drivers[] array */
#undef DRIVER
#undef TESTDRIVER
#define DRIVER(NAME) &driver_##NAME,
#define TESTDRIVER(NAME)
const struct GameDriver *drivers[] =
{
#include "driver.c"
	0	/* end of array */
};

/* step 2: define the test_drivers[] array */
#undef DRIVER
#undef TESTDRIVER
#define DRIVER(NAME)
#define TESTDRIVER(NAME) &driver_##NAME,

const struct GameDriver *test_drivers[] =
{
#include "driver.c"
	0	/* end of array */
};

#else	/* DRIVER_RECURSIVE */

	/* Williams/Midway games */
	DRIVER( narc )		/* (c) 1988 Williams */
	DRIVER( narc3 )		/* (c) 1988 Williams */
	DRIVER( trog )		/* (c) 1990 Midway */
	DRIVER( trog3 )		/* (c) 1990 Midway */
	DRIVER( trogpa6 )	/* (c) 1990 Midway */
	DRIVER( trogp )		/* (c) 1990 Midway */
	DRIVER( smashtv )	/* (c) 1990 Williams */
	DRIVER( smashtv6 )	/* (c) 1990 Williams */
	DRIVER( smashtv5 )	/* (c) 1990 Williams */
	DRIVER( smashtv4 )	/* (c) 1990 Williams */
	DRIVER( hiimpact )	/* (c) 1990 Williams */
	DRIVER( shimpact )	/* (c) 1991 Midway */
	DRIVER( shimpacp )	/* (c) 1991 Midway */
	DRIVER( strkforc )	/* (c) 1991 Midway */
	DRIVER( mk )		/* (c) 1992 Midway */
	DRIVER( mkr4 )		/* (c) 1992 Midway */
	DRIVER( mkprot9 )	/* (c) 1992 Midway */
	DRIVER( mkla1 )		/* (c) 1992 Midway */
	DRIVER( mkla2 )		/* (c) 1992 Midway */
	DRIVER( mkla3 )		/* (c) 1992 Midway */
	DRIVER( mkla4 )		/* (c) 1992 Midway */
	DRIVER( term2 )		/* (c) 1992 Midway */
	DRIVER( term2la2 )	/* (c) 1992 Midway */
	DRIVER( term2la1 )	/* (c) 1992 Midway */
	DRIVER( totcarn )	/* (c) 1992 Midway */
	DRIVER( totcarnp )	/* (c) 1992 Midway */
	DRIVER( mk2 )		/* (c) 1993 Midway */
	DRIVER( mk2r32 )	/* (c) 1993 Midway */
	DRIVER( mk2r21 )	/* (c) 1993 Midway */
	DRIVER( mk2r14 )	/* (c) 1993 Midway */
	DRIVER( mk2r42 )	/* hack */
	DRIVER( mk2r91 )	/* hack */
	DRIVER( mk2chal )	/* hack */
	DRIVER( jdreddp )	/* (c) 1993 Midway */
	DRIVER( nbajam )	/* (c) 1993 Midway */
	DRIVER( nbajamr2 )	/* (c) 1993 Midway */
	DRIVER( nbajamte )	/* (c) 1994 Midway */
	DRIVER( nbajamt1 )	/* (c) 1994 Midway */
	DRIVER( nbajamt2 )	/* (c) 1994 Midway */
	DRIVER( nbajamt3 )	/* (c) 1994 Midway */
	DRIVER( revx )		/* (c) 1994 Midway */
	DRIVER( mk3 )		/* (c) 1994 Midway */
	DRIVER( mk3r20 )	/* (c) 1994 Midway */
	DRIVER( mk3r10 )	/* (c) 1994 Midway */
	DRIVER( umk3 )		/* (c) 1994 Midway */
	DRIVER( umk3r11 )	/* (c) 1994 Midway */
	DRIVER( wwfmania )	/* (c) 1995 Midway */
	DRIVER( openice )	/* (c) 1995 Midway */
	DRIVER( nbahangt )	/* (c) 1996 Midway */
	DRIVER( nbamaxht )	/* (c) 1996 Midway */
	DRIVER( rmpgwt )	/* (c) 1997 Midway */
	DRIVER( rmpgwt11 )	/* (c) 1997 Midway */

#endif	/* DRIVER_RECURSIVE */

#endif	/* TINY_COMPILE */
