/****************************************************************************
 *	window.c
 *	Text mode window engine
 *
 *	Written by Neil Bradley (neil@synthcom.com)
 *	Heavily modified by Juergen Buchmueller (pullmoll@t-online.de)
 *
 *  Designed to fit the needs of the new MAME debugger (a bit more ;)
 *
 *	Warning: This code is still buggy!
 *	Some of the changes I made were contrary to the original design,
 *	so expect 'assertions' for every non common case (ie. window too
 *	big, hanging out of the screen etc.)
 ****************************************************************************/
#include <stdio.h>

