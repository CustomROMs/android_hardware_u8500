/*
 * SUPL_ULP_ReqDataBitAssistanceList.c
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
 * From ASN.1 module "ULP-Version-2-parameter-extensions"
 *     found in "ULP_v2.0.0.asn"
 *     `asn1c -gen-PER -fcompound-names`
 */

#include <asn_internal.h>

#include "SUPL_ULP_ReqDataBitAssistanceList.h"

static int
memb_NativeInteger_constraint_4(asn_TYPE_descriptor_t *td, const void *sptr,
            asn_app_constraint_failed_f *ctfailcb, void *app_key) {
    long value;
    
    if(!sptr) {
        _ASN_CTFAIL(app_key, td, sptr,
            "%s: value not given (%s:%d)",
            td->name, __FILE__, __LINE__);
        return -1;
    }
    
    value = *(const long *)sptr;
    
    if((value >= 0 && value <= 63)) {
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
memb_ganssDataBitInterval_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
            asn_app_constraint_failed_f *ctfailcb, void *app_key) {
    long value;
    
    if(!sptr) {
        _ASN_CTFAIL(app_key, td, sptr,
            "%s: value not given (%s:%d)",
            td->name, __FILE__, __LINE__);
        return -1;
    }
    
    value = *(const long *)sptr;
    
    if((value >= 0 && value <= 15)) {
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
memb_ganssDataBitSatList_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
            asn_app_constraint_failed_f *ctfailcb, void *app_key) {
    size_t size;
    
    if(!sptr) {
        _ASN_CTFAIL(app_key, td, sptr,
            "%s: value not given (%s:%d)",
            td->name, __FILE__, __LINE__);
        return -1;
    }
    
    /* Determine the number of elements */
    size = _A_CSEQUENCE_FROM_VOID(sptr)->count;
    
    if((size >= 1 && size <= 32)) {
        /* Perform validation of the inner elements */
        return td->check_constraints(td, sptr, ctfailcb, app_key);
    } else {
        _ASN_CTFAIL(app_key, td, sptr,
            "%s: constraint failed (%s:%d)",
            td->name, __FILE__, __LINE__);
        return -1;
    }
}

static asn_per_constraints_t asn_PER_memb_Member_constr_5 = {
    { APC_CONSTRAINED,     6,  6,  0,  63 }    /* (0..63) */,
    { APC_UNCONSTRAINED,    -1, -1,  0,  0 },
    0, 0    /* No PER value map */
};
static asn_per_constraints_t asn_PER_type_ganssDataBitSatList_constr_4 = {
    { APC_UNCONSTRAINED,    -1, -1,  0,  0 },
    { APC_CONSTRAINED,     5,  5,  1,  32 }    /* (SIZE(1..32)) */,
    0, 0    /* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_ganssDataBitInterval_constr_3 = {
    { APC_CONSTRAINED,     4,  4,  0,  15 }    /* (0..15) */,
    { APC_UNCONSTRAINED,    -1, -1,  0,  0 },
    0, 0    /* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_ganssDataBitSatList_constr_4 = {
    { APC_UNCONSTRAINED,    -1, -1,  0,  0 },
    { APC_CONSTRAINED,     5,  5,  1,  32 }    /* (SIZE(1..32)) */,
    0, 0    /* No PER value map */
};
static asn_TYPE_member_t asn_MBR_ganssDataBitSatList_4[] = {
    { ATF_POINTER, 0, 0,
        (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
        0,
        &asn_DEF_NativeInteger,
        memb_NativeInteger_constraint_4,
        &asn_PER_memb_Member_constr_5,
        0,
        ""
        },
};
static ber_tlv_tag_t asn_DEF_ganssDataBitSatList_tags_4[] = {
    (ASN_TAG_CLASS_CONTEXT | (2 << 2)),
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_ganssDataBitSatList_specs_4 = {
    sizeof(struct ReqDataBitAssistanceList__ganssDataBitSatList),
    offsetof(struct ReqDataBitAssistanceList__ganssDataBitSatList, _asn_ctx),
    0,    /* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ganssDataBitSatList_4 = {
    "ganssDataBitSatList",
    "ganssDataBitSatList",
    SEQUENCE_OF_free,
    SEQUENCE_OF_print,
    SEQUENCE_OF_constraint,
    SEQUENCE_OF_decode_ber,
    SEQUENCE_OF_encode_der,
    SEQUENCE_OF_decode_xer,
    SEQUENCE_OF_encode_xer,
    SEQUENCE_OF_decode_uper,
    SEQUENCE_OF_encode_uper,
    0,    /* Use generic outmost tag fetcher */
    asn_DEF_ganssDataBitSatList_tags_4,
    sizeof(asn_DEF_ganssDataBitSatList_tags_4)
        /sizeof(asn_DEF_ganssDataBitSatList_tags_4[0]) - 1, /* 1 */
    asn_DEF_ganssDataBitSatList_tags_4,    /* Same as above */
    sizeof(asn_DEF_ganssDataBitSatList_tags_4)
        /sizeof(asn_DEF_ganssDataBitSatList_tags_4[0]), /* 2 */
    &asn_PER_type_ganssDataBitSatList_constr_4,
    asn_MBR_ganssDataBitSatList_4,
    1,    /* Single element */
    &asn_SPC_ganssDataBitSatList_specs_4    /* Additional specs */
};

static asn_TYPE_member_t asn_MBR_ReqDataBitAssistanceList_1[] = {
    { ATF_NOFLAGS, 0, offsetof(struct ReqDataBitAssistanceList, gnssSignals),
        (ASN_TAG_CLASS_CONTEXT | (0 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &asn_DEF_GANSSSignals,
        0,    /* Defer constraints checking to the member type */
        0,    /* No PER visible constraints */
        0,
        "gnssSignals"
        },
    { ATF_NOFLAGS, 0, offsetof(struct ReqDataBitAssistanceList, ganssDataBitInterval),
        (ASN_TAG_CLASS_CONTEXT | (1 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &asn_DEF_NativeInteger,
        memb_ganssDataBitInterval_constraint_1,
        &asn_PER_memb_ganssDataBitInterval_constr_3,
        0,
        "ganssDataBitInterval"
        },
    { ATF_POINTER, 1, offsetof(struct ReqDataBitAssistanceList, ganssDataBitSatList),
        (ASN_TAG_CLASS_CONTEXT | (2 << 2)),
        0,
        &asn_DEF_ganssDataBitSatList_4,
        memb_ganssDataBitSatList_constraint_1,
        &asn_PER_memb_ganssDataBitSatList_constr_4,
        0,
        "ganssDataBitSatList"
        },
};
static int asn_MAP_ReqDataBitAssistanceList_oms_1[] = { 2 };
static ber_tlv_tag_t asn_DEF_ReqDataBitAssistanceList_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_ReqDataBitAssistanceList_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* gnssSignals at 972 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* ganssDataBitInterval at 973 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* ganssDataBitSatList at 974 */
};
static asn_SEQUENCE_specifics_t asn_SPC_ReqDataBitAssistanceList_specs_1 = {
    sizeof(struct ReqDataBitAssistanceList),
    offsetof(struct ReqDataBitAssistanceList, _asn_ctx),
    asn_MAP_ReqDataBitAssistanceList_tag2el_1,
    3,    /* Count of tags in the map */
    asn_MAP_ReqDataBitAssistanceList_oms_1,    /* Optional members */
    1, 0,    /* Root/Additions */
    2,    /* Start extensions */
    4    /* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_ReqDataBitAssistanceList = {
    "ReqDataBitAssistanceList",
    "ReqDataBitAssistanceList",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    SEQUENCE_decode_uper,
    SEQUENCE_encode_uper,
    0,    /* Use generic outmost tag fetcher */
    asn_DEF_ReqDataBitAssistanceList_tags_1,
    sizeof(asn_DEF_ReqDataBitAssistanceList_tags_1)
        /sizeof(asn_DEF_ReqDataBitAssistanceList_tags_1[0]), /* 1 */
    asn_DEF_ReqDataBitAssistanceList_tags_1,    /* Same as above */
    sizeof(asn_DEF_ReqDataBitAssistanceList_tags_1)
        /sizeof(asn_DEF_ReqDataBitAssistanceList_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_ReqDataBitAssistanceList_1,
    3,    /* Elements count */
    &asn_SPC_ReqDataBitAssistanceList_specs_1    /* Additional specs */
};
