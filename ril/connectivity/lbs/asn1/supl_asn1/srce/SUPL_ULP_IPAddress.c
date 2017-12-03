/*
 * SUPL_ULP_IPAddress.c
 *
 * Copyright (C) ST-Ericsson SA 2010. All rights reserved.
 * Author: david.gowers@stericsson.com for ST-Ericsson.
 * License terms: Redistribution and modifications are permitted subject to BSD license. 
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of ST-Ericsson nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ST-ERICSSON BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * Generated by asn1c-0.9.22 (http://lionet.info/asn1c)
 * From ASN.1 module "ULP-Components"
 *     found in "ULP_v2.0.0.asn"
 *     `asn1c -gen-PER -fcompound-names`
 */

#include <asn_internal.h>

#include "SUPL_ULP_IPAddress.h"

static int
memb_ipv4Address_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
            asn_app_constraint_failed_f *ctfailcb, void *app_key) {
    const OCTET_STRING_t *st = (const OCTET_STRING_t *)sptr;
    size_t size;
    
    if(!sptr) {
        _ASN_CTFAIL(app_key, td, sptr,
            "%s: value not given (%s:%d)",
            td->name, __FILE__, __LINE__);
        return -1;
    }
    
    size = st->size;
    
    if((size == 4)) {
        /* Constraint check succeeded */
        return 0;
    } else {
        _ASN_CTFAIL(app_key, td, sptr,
            "%s: constraint failed (%s:%d)",
            td->name, __FILE__, __LINE__);
        return -1;
    }
}

static int
memb_ipv6Address_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
            asn_app_constraint_failed_f *ctfailcb, void *app_key) {
    const OCTET_STRING_t *st = (const OCTET_STRING_t *)sptr;
    size_t size;
    
    if(!sptr) {
        _ASN_CTFAIL(app_key, td, sptr,
            "%s: value not given (%s:%d)",
            td->name, __FILE__, __LINE__);
        return -1;
    }
    
    size = st->size;
    
    if((size == 16)) {
        /* Constraint check succeeded */
        return 0;
    } else {
        _ASN_CTFAIL(app_key, td, sptr,
            "%s: constraint failed (%s:%d)",
            td->name, __FILE__, __LINE__);
        return -1;
    }
}

static asn_per_constraints_t asn_PER_memb_ipv4Address_constr_2 = {
    { APC_UNCONSTRAINED,    -1, -1,  0,  0 },
    { APC_CONSTRAINED,     0,  0,  4,  4 }    /* (SIZE(4..4)) */,
    0, 0    /* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_ipv6Address_constr_3 = {
    { APC_UNCONSTRAINED,    -1, -1,  0,  0 },
    { APC_CONSTRAINED,     0,  0,  16,  16 }    /* (SIZE(16..16)) */,
    0, 0    /* No PER value map */
};
static asn_per_constraints_t asn_PER_type_IPAddress_constr_1 = {
    { APC_CONSTRAINED,     1,  1,  0,  1 }    /* (0..1) */,
    { APC_UNCONSTRAINED,    -1, -1,  0,  0 },
    0, 0    /* No PER value map */
};
static asn_TYPE_member_t asn_MBR_IPAddress_1[] = {
    { ATF_NOFLAGS, 0, offsetof(struct IPAddress, choice.ipv4Address),
        (ASN_TAG_CLASS_CONTEXT | (0 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &asn_DEF_OCTET_STRING,
        memb_ipv4Address_constraint_1,
        &asn_PER_memb_ipv4Address_constr_2,
        0,
        "ipv4Address"
        },
    { ATF_NOFLAGS, 0, offsetof(struct IPAddress, choice.ipv6Address),
        (ASN_TAG_CLASS_CONTEXT | (1 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &asn_DEF_OCTET_STRING,
        memb_ipv6Address_constraint_1,
        &asn_PER_memb_ipv6Address_constr_3,
        0,
        "ipv6Address"
        },
};
static asn_TYPE_tag2member_t asn_MAP_IPAddress_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* ipv4Address at 1058 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* ipv6Address at 1059 */
};
static asn_CHOICE_specifics_t asn_SPC_IPAddress_specs_1 = {
    sizeof(struct IPAddress),
    offsetof(struct IPAddress, _asn_ctx),
    offsetof(struct IPAddress, present),
    sizeof(((struct IPAddress *)0)->present),
    asn_MAP_IPAddress_tag2el_1,
    2,    /* Count of tags in the map */
    0,
    -1    /* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_IPAddress = {
    "IPAddress",
    "IPAddress",
    CHOICE_free,
    CHOICE_print,
    CHOICE_constraint,
    CHOICE_decode_ber,
    CHOICE_encode_der,
    CHOICE_decode_xer,
    CHOICE_encode_xer,
    CHOICE_decode_uper,
    CHOICE_encode_uper,
    CHOICE_outmost_tag,
    0,    /* No effective tags (pointer) */
    0,    /* No effective tags (count) */
    0,    /* No tags (pointer) */
    0,    /* No tags (count) */
    &asn_PER_type_IPAddress_constr_1,
    asn_MBR_IPAddress_1,
    2,    /* Elements count */
    &asn_SPC_IPAddress_specs_1    /* Additional specs */
};

