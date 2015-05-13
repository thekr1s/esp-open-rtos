/*
 * Copyright (c) 2001-2003 Swedish Institute of Computer Science.
 * All rights reserved. 
 * 
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED 
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT 
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 * 
 * Author: Adam Dunkels <adam@sics.se>
 *
 */
#ifndef __ARCH_CC_H__
#define __ARCH_CC_H__

/* Include some files for defining library routines */
#include <stdio.h> /* printf, fflush, FILE */
#include <stdlib.h> /* abort */
#include <stdint.h>

#define BYTE_ORDER LITTLE_ENDIAN

/** @todo fix some warnings: don't use #pragma if compiling with cygwin gcc */
#ifndef __GNUC__
	#include <limits.h>
	#pragma warning (disable: 4244) /* disable conversion warning (implicit integer promotion!) */
	#pragma warning (disable: 4127) /* conditional expression is constant */
	#pragma warning (disable: 4996) /* 'strncpy' was declared deprecated */
	#pragma warning (disable: 4103) /* structure packing changed by including file */
#endif

#define LWIP_PROVIDE_ERRNO

/* Define generic types used in lwIP */
typedef uint8_t    u8_t;
typedef int8_t    s8_t;
typedef uint16_t   u16_t;
typedef int16_t   s16_t;
typedef uint32_t    u32_t;
typedef int32_t    s32_t;

typedef size_t mem_ptr_t;
typedef int sys_prot_t;

/* Define (sn)printf formatters for these lwIP types */
#define X8_F  "02x"
#define U16_F "hu"
#define S16_F "hd"
#define X16_F "hx"
#define U32_F "lu"
#define S32_F "ld"
#define X32_F "lx"
#define SZT_F U32_F

/* Compiler hints for packing structures */
#define PACK_STRUCT_STRUCT __attribute__( (packed) )

/* Plaform specific diagnostic output */
#define LWIP_PLATFORM_DIAG(x)   do { printf x; } while(0)

#define LWIP_PLATFORM_ASSERT(x) do { printf("Assertion \"%s\" failed at line %d in %s\n", \
					    x, __LINE__, __FILE__); while(1) {} } while(0)

#define LWIP_ERROR(message, expression, handler) do { if (!(expression)) { \
  printf("Assertion \"%s\" failed at line %d in %s\n", message, __LINE__, __FILE__); \
  handler;} } while(0)

#define LWIP_PLATFORM_BYTESWAP 1

#define LWIP_PLATFORM_HTONS(_n)  ((u16_t)((((_n) & 0xff) << 8) | (((_n) >> 8) & 0xff)))
#define LWIP_PLATFORM_HTONL(_n)  ((u32_t)( (((_n) & 0xff) << 24) | (((_n) & 0xff00) << 8) | (((_n) >> 8)  & 0xff00) | (((_n) >> 24) & 0xff) ))

#endif /* __ARCH_CC_H__ */
