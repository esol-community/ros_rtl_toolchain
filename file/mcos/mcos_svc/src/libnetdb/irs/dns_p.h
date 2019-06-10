/*  $NetBSD: dns_p.h,v 1.1.1.3.4.1 2007/05/17 00:39:45 jdc Exp $    */

/*
 * Copyright (c) 2004 by Internet Systems Consortium, Inc. ("ISC")
 * Copyright (c) 1996-1999 by Internet Software Consortium.
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

/*
 * Id: dns_p.h,v 1.3.18.1 2005/04/27 05:00:55 sra Exp
 */

#ifndef _DNS_P_H_INCLUDED
#define _DNS_P_H_INCLUDED

#define maybe_ok(res, nm, ok) (((res)->options & RES_NOCHECKNAME) != 0U || \
                               (ok)(nm) != 0)
#define maybe_hnok(res, hn) maybe_ok((res), (hn), res_hnok)
#define maybe_dnok(res, dn) maybe_ok((res), (dn), res_dnok)

/*
 * Object state.
 */
struct dns_p {
    void                *hes_ctx;
    struct __res_state  *res;
    void                (*free_res) (void *);
};

/*
 * Methods.
 */

extern struct irs_gr *  irs_dns_gr(struct irs_acc * this);
extern struct irs_pw *  irs_dns_pw(struct irs_acc * this);
extern struct irs_sv *  irs_dns_sv(struct irs_acc * this);
extern struct irs_pr *  irs_dns_pr(struct irs_acc * this);
extern struct irs_ho *  irs_dns_ho(struct irs_acc * this);
extern struct irs_nw *  irs_dns_nw(struct irs_acc * this);

#endif /*_DNS_P_H_INCLUDED*/
