/*  $NetBSD: util.c,v 1.1.1.3.4.1 2007/05/17 00:40:00 jdc Exp $ */

/*
 * Copyright (c) 2004 by Internet Systems Consortium, Inc. ("ISC")
 * Copyright (c) 1996,1999 by Internet Software Consortium.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
#include "port_before.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include "resolv.h"
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "irs.h"

#include "port_after.h"

#include "irs_p.h"

void
map_v4v6_address(const char *src, char *dst) {
    u_char *p = (u_char *)dst;
    char tmp[NS_INADDRSZ];
    int i;

    /* Stash a temporary copy so our caller can update in place. */
    memcpy(tmp, src, NS_INADDRSZ);
    /* Mark this ipv6 addr as a mapped ipv4. */
    for (i = 0; i < 10; i++)
        *p++ = 0x00;
    *p++ = 0xff;
    *p++ = 0xff;
    /* Retrieve the saved copy and we're done. */
    memcpy((void*)p, tmp, NS_INADDRSZ);
}
