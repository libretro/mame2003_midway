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

	/* Williams games */
	DRIVER( defender )	/* (c) 1980 */
	DRIVER( defendg )	/* (c) 1980 */
	DRIVER( defendw )	/* (c) 1980 */
	DRIVER( defndjeu )	/* bootleg */
	DRIVER( defcmnd )	/* bootleg */
	DRIVER( defence )	/* bootleg */
	DRIVER( mayday )
	DRIVER( maydaya )
	DRIVER( maydayb )
	DRIVER( colony7 )	/* (c) 1981 Taito */
	DRIVER( colony7a )	/* (c) 1981 Taito */
	DRIVER( stargate )	/* (c) 1981 */
	DRIVER( robotron )	/* (c) 1982 */
	DRIVER( robotryo )	/* (c) 1982 */
	DRIVER( joust )		/* (c) 1982 */
	DRIVER( joustr )	/* (c) 1982 */
	DRIVER( joustwr )	/* (c) 1982 */
	DRIVER( bubbles )	/* (c) 1982 */
	DRIVER( bubblesr )	/* (c) 1982 */
	DRIVER( bubblesp )	/* (c) 1982 */
	DRIVER( splat )		/* (c) 1982 */
	DRIVER( sinistar )	/* (c) 1982 */
	DRIVER( sinista1 )	/* (c) 1982 */
	DRIVER( sinista2 )	/* (c) 1982 */
	DRIVER( playball )	/* (c) 1983 */
	DRIVER( blaster )	/* (c) 1983 */
	DRIVER( blastkit )	/* (c) 1983 */
	DRIVER( spdball )	/* (c) 1985 */
	DRIVER( mysticm )	/* (c) 1983 */
	DRIVER( tshoot )	/* (c) 1984 */
	DRIVER( inferno )	/* (c) 1984 */
	DRIVER( joust2 )	/* (c) 1986 */
	DRIVER( lottofun )	/* (c) 1987 H.A.R. Management */

	/* Atari b/w games */
	/* Tank 8 */  		/* ??????			1976/04 [6800] */
	DRIVER( copsnrob )	/* 005625			1976/07 [6502] */
	DRIVER( flyball )	/* 005629			1976/07 [6502] */
	DRIVER( sprint2 )	/* 005922			1976/11 [6502] */
	DRIVER( sprint2a )	/* 005922			1976/11 [6502] */
	DRIVER( sprint4 )	/* 008716			1977/12 [6502] */
	DRIVER( sprint4a )	/* 008716			1977/12 [6502] */
	DRIVER( nitedrvr )	/* 006321			1976/10 [6502] */
	DRIVER( dominos )	/* 007305			1977/01 [6502] */
	DRIVER( triplhnt )	/* 008422-008791	1977/04 [6800] */
	DRIVER( sprint8 )	/* ??????           1977/05 [6800] */
	DRIVER( sprint8a )	/* ??????           1977/05 [6800] */
	DRIVER( dragrace )	/* 008505-008521	1977/06 [6800] */
	DRIVER( poolshrk )	/* 006281			1977/06 [6800] */
	DRIVER( starshp1 )	/* 007513-007531	1977/07 [6502] */
	DRIVER( starshpp )	/* 007513-007531	1977/07 [6502] */
	DRIVER( superbug )	/* 009115-009467	1977/09 [6800] */
	DRIVER( canyon )	/* 009493-009504	1977/10 [6502] */
	DRIVER( canyonp )	/* 009493-009504	1977/10 [6502] */
	DRIVER( destroyr )	/* 030131-030136	1977/10 [6800] */
	DRIVER( sprint1 )	/* 006443			1978/01 [6502] */
	DRIVER( ultratnk )	/* 009801			1978/02 [6502] */
	DRIVER( skyraid )	/* 009709			1978/03 [6502] */
	DRIVER( tourtabl )	/* 030170			1978/03 [6507] */
	DRIVER( tourtab2 )	/* 030170			1978/03 [6507] */
	DRIVER( avalnche )	/* 030574			1978/04 [6502] */
	DRIVER( firetrk )	/* 030926			1978/06 [6808] */
	DRIVER( skydiver )	/* 009787			1978/06 [6800] */
	/* Smokey Joe */	/* 030926			1978/07 [6502] */
	DRIVER( sbrkout )	/* 033442-033455	1978/09 [6502] */
	DRIVER( atarifb )	/* 033xxx			1978/10 [6502] */
	DRIVER( atarifb1 )	/* 033xxx			1978/10 [6502] */
	DRIVER( orbit )		/* 033689-033702	1978/11 [6800] */
	DRIVER( boxer )		/* ?????? prototype 1978    [6502] */
	DRIVER( wolfpack )	/* ?????? prototype         [6502] */
	DRIVER( videopin )	/* 034253-034267	1979/02 [6502] */
	DRIVER( atarifb4 )	/* 034754			1979/04 [6502] */
	DRIVER( subs )		/* 033714			1979/05 [6502] */
	DRIVER( bsktball )	/* 034756-034766	1979/05 [6502] */
	DRIVER( abaseb )	/* 034711-034738	1979/06 [6502] */
	DRIVER( abaseb2 )	/* 034711-034738	1979/06 [6502] */
	DRIVER( montecar )	/* 035763-035780	1980/04 [6502] */
	DRIVER( soccer )	/* 035222-035260	1980/04 [6502] */

	/* Atari "Missile Command hardware" games */
	DRIVER( missile )	/* 035820-035825	(c) 1980 */
	DRIVER( missile2 )	/* 035820-035825	(c) 1980 */
	DRIVER( suprmatk )	/* 					(c) 1980 + (c) 1981 Gencomp */

	/* Blasteroids */
	DRIVER( blstroid )	/* 136057			(c) 1987 */
	DRIVER( blstroi3 )	/* 136057			(c) 1987 */
	DRIVER( blstroi2 )	/* 136057			(c) 1987 */
	DRIVER( blstroig )	/* 136057			(c) 1987 */
	DRIVER( blsthead )	/* (proto)			(c) 1987 */
	/* Cyberball */
	DRIVER( cyberbal )	/* 136064			(c) 1989 */
	DRIVER( cyberba2 )	/* 136064			(c) 1989 */
	DRIVER( cyberbap )	/* 136064			(c) 1989 */
	/* Atari Tetris */
	DRIVER( atetcktl )	/* 136066			(c) 1989 */
	DRIVER( atetckt2 )	/* 136066			(c) 1989 */
	DRIVER( atetris )	/* 136066			(c) 1988 */
	DRIVER( atetrisa )	/* 136066			(c) 1988 */
	DRIVER( atetrisb )	/* (bootleg) */
	/* Escape from the Planet of Robot Monsters */
	DRIVER( eprom )		/* 136069			(c) 1989 */
	DRIVER( eprom2 )	/* 136069			(c) 1989 */
	/* Skull and Crossbones */
	DRIVER( skullxbo )	/* 136072			(c) 1989 */
	DRIVER( skullxb4 )	/* 136072			(c) 1989 */
	DRIVER( skullxb3 )	/* 136072			(c) 1989 */
	DRIVER( skullxb2 )	/* 136072			(c) 1989 */
	DRIVER( skullxb1 )	/* 136072			(c) 1989 */
	/* Cyberball Tournament */
	DRIVER( cyberbt )	/* 136073			(c) 1989 */
	DRIVER( cyberbt1 )	/* 136073			(c) 1989 */

	DRIVER( badlands )	/* 136074			(c) 1989 */
	DRIVER( klax )		/* 136075			(c) 1989 */
	DRIVER( klax2 )		/* 136075			(c) 1989 */
	DRIVER( klax3 )		/* 136075			(c) 1989 */
	DRIVER( klaxj )		/* 136075			(c) 1989 (Japan) */
	DRIVER( klaxd )		/* 136075			(c) 1989 (Germany) */
	DRIVER( klaxp1 )	/* prototype */
	DRIVER( klaxp2 )	/* prototype */
	DRIVER( thunderj )	/* 136076			(c) 1990 */

	/* Cyberball 2 Player */
	DRIVER( cyberb2p )	/*     ??			(c) 1989 */
	DRIVER( cyberb23 )	/*     ??			(c) 1989 */
	DRIVER( cyberb22 )	/*     ??			(c) 1989 */
	DRIVER( cyberb21 )	/*     ??			(c) 1989 */

	DRIVER( hydra )		/* 136079			(c) 1990 */
	DRIVER( hydrap )	/* (proto)			(c) 1990 */
	DRIVER( hydrap2 )	/* (proto)			(c) 1990 */
	DRIVER( pitfight )	/* 136081			(c) 1990 */
	DRIVER( pitfigh3 )	/* 136081			(c) 1990 */
	DRIVER( pitfighj )	/* Japan */
	DRIVER( pitfighb )	/* bootleg */
	DRIVER( rampart )	/* 136082			(c) 1990 */
	DRIVER( ramprt2p )	/* 136082			(c) 1990 */
	DRIVER( rampartj )	/* 136082			(c) 1990 (Japan) */
	DRIVER( shuuz )		/* 136083			(c) 1990 */
	DRIVER( shuuz2 )	/* 136083			(c) 1990 */
	DRIVER( batman )	/* 136085			(c) 1991 */
	DRIVER( roadriot )	/* 136089			(c) 1991 */
	DRIVER( offtwall )	/* 136090			(c) 1991 */
	DRIVER( offtwalc )	/* 136090			(c) 1991 */
	DRIVER( guardian )	/* 136092			(c) 1992 */
	DRIVER( relief )	/* 136093			(c) 1992 */
	DRIVER( relief2 )	/* 136093			(c) 1992 */
	DRIVER( arcadecl )	/* (proto)			(c) 1992 */
	DRIVER( sparkz )	/* (proto)			(c) 1992 */
	DRIVER( motofren )	/* 136094			(c) 1992 */
	DRIVER( spclords )	/* 136095			(c) 1992 */
	DRIVER( spclorda )	/* 136095			(c) 1992 */
	DRIVER( rrreveng )	/*     ??			(c) 1993 */
	DRIVER( rrrevenp )	/*     ??		    (c) 1993 */
	DRIVER( beathead )	/* (proto)			(c) 1993 */
	DRIVER( tmek )		/* 136100			(c) 1994 */
	DRIVER( tmekprot )	/* 136100			(c) 1994 */
	DRIVER( primrage )	/* 136102			(c) 1994 */
	DRIVER( primraga )	/* 136102			(c) 1994 */
	DRIVER( area51 )	/* 136105			(c) 1995 */
	DRIVER( area51mx )	/* 136105			(c) 1998 */
	DRIVER( a51mxr3k )	/*     ??           (c) 1998 */
	DRIVER( maxforce )	/*     ??			(c) 1996 */
	DRIVER( maxf_102 )	/*     ??			(c) 1996 */
	DRIVER( vcircle )	/*     ??			(c) 1996 */

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
	DRIVER( crusnusa )	/* (c) 1994 Midway */
	DRIVER( crusnu40 )	/* (c) 1994 Midway */
	DRIVER( crusnu21 )	/* (c) 1994 Midway */
	DRIVER( crusnwld )	/* (c) 1996 Midway */
	DRIVER( crusnw20 )	/* (c) 1996 Midway */
	DRIVER( crusnw13 )	/* (c) 1996 Midway */
	DRIVER( offroadc )	/* (c) 1997 Midway */
	DRIVER( wargods )	/* (c) 1996 Midway */

	/* Midway / Atari  Voodoo based Hardware (Seattle, Flagstaff) */
	DRIVER ( wg3dh )	/* (c) 1996 Atari Games */
	DRIVER ( mace )		/* (c) 1996 Atari Games */
	DRIVER ( sfrush )	/* (c) 1996 Atari Games */
	DRIVER ( calspeed )	/* (c) 1996 Atari Games */
	DRIVER ( carnevil )	/* (c) 1998 Midway Games */
	DRIVER ( biofreak )	/* (c) 1997 Midway Games */
	DRIVER ( blitz )	/* (c) 1997 Midway Games */
	DRIVER ( blitz99 )	/* (c) 1998 Midway Games */
	DRIVER ( blitz2k )	/* (c) 1999 Midway Games */


#endif	/* DRIVER_RECURSIVE */

#endif	/* TINY_COMPILE */
