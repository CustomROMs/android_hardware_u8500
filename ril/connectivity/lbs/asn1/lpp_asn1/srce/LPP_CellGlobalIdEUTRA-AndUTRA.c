/*
 * LPP_CellGlobalIdEUTRA-AndUTRA.c
 *
 * Copyright (C) ST-Ericsson SA 2010. All rights reserved.
 * Author: sunilsatish.rao@stericsson.com for ST-Ericsson.
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
 * Generated by asn1c-0.9.21 (http://lionet.info/asn1c)
 * From ASN.1 module "LPP_PDU-Definitions"
 * 	found in "LPP_RRLP_Rel_10.asn"
 * 	`asn1c -gen-PER`
 */

#include <asn_internal.h>

#include "LPP_CellGlobalIdEUTRA-AndUTRA.h"

static int
memb_NativeInteger_constraint_3(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 9)) {
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
memb_NativeInteger_constraint_5(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 9)) {
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
memb_mcc_constraint_2(asn_TYPE_descriptor_t *td, const void *sptr,
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
	
	if((size == 3)) {
		/* Perform validation of the inner elements */
		return td->check_constraints(td, sptr, ctfailcb, app_key);
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_mnc_constraint_2(asn_TYPE_descriptor_t *td, const void *sptr,
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
	
	if((size >= 2 && size <= 3)) {
		/* Perform validation of the inner elements */
		return td->check_constraints(td, sptr, ctfailcb, app_key);
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_eutra_constraint_7(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const BIT_STRING_t *st = (const BIT_STRING_t *)sptr;
	size_t size;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	if(st->size > 0) {
		/* Size in bits */
		size = 8 * st->size - (st->bits_unused & 0x07);
	} else {
		size = 0;
	}
	
	if((size == 28)) {
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
memb_utra_constraint_7(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const BIT_STRING_t *st = (const BIT_STRING_t *)sptr;
	size_t size;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	if(st->size > 0) {
		/* Size in bits */
		size = 8 * st->size - (st->bits_unused & 0x07);
	} else {
		size = 0;
	}
	
	if((size == 32)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_memb_Member_constr_4 = {
	{ APC_CONSTRAINED,	 4,  4,  0,  9 }	/* (0..9) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 }
};
static asn_TYPE_member_t asn_MBR_mcc_3[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
		0,
		&asn_DEF_NativeInteger,
		memb_NativeInteger_constraint_3,
		&asn_PER_memb_Member_constr_4,
		0,
		""
		},
};
static ber_tlv_tag_t asn_DEF_mcc_tags_3[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_mcc_specs_3 = {
	sizeof(struct LPP_CellGlobalIdEUTRA_AndUTRA__plmn_Identity__mcc),
	offsetof(struct LPP_CellGlobalIdEUTRA_AndUTRA__plmn_Identity__mcc, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static asn_per_constraints_t asn_PER_mcc_constr_3 = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 0,  0,  3,  3 }	/* (SIZE(3..3)) */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_mcc_3 = {
	"mcc",
	"mcc",
	SEQUENCE_OF_free,
	SEQUENCE_OF_print,
	SEQUENCE_OF_constraint,
	SEQUENCE_OF_decode_ber,
	SEQUENCE_OF_encode_der,
	SEQUENCE_OF_decode_xer,
	SEQUENCE_OF_encode_xer,
	SEQUENCE_OF_decode_uper,
	SEQUENCE_OF_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_mcc_tags_3,
	sizeof(asn_DEF_mcc_tags_3)
		/sizeof(asn_DEF_mcc_tags_3[0]) - 1, /* 1 */
	asn_DEF_mcc_tags_3,	/* Same as above */
	sizeof(asn_DEF_mcc_tags_3)
		/sizeof(asn_DEF_mcc_tags_3[0]), /* 2 */
	&asn_PER_mcc_constr_3,
	asn_MBR_mcc_3,
	1,	/* Single element */
	&asn_SPC_mcc_specs_3	/* Additional specs */
};

static asn_per_constraints_t asn_PER_memb_Member_constr_6 = {
	{ APC_CONSTRAINED,	 4,  4,  0,  9 }	/* (0..9) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 }
};
static asn_TYPE_member_t asn_MBR_mnc_5[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
		0,
		&asn_DEF_NativeInteger,
		memb_NativeInteger_constraint_5,
		&asn_PER_memb_Member_constr_6,
		0,
		""
		},
};
static ber_tlv_tag_t asn_DEF_mnc_tags_5[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_mnc_specs_5 = {
	sizeof(struct LPP_CellGlobalIdEUTRA_AndUTRA__plmn_Identity__mnc),
	offsetof(struct LPP_CellGlobalIdEUTRA_AndUTRA__plmn_Identity__mnc, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static asn_per_constraints_t asn_PER_mnc_constr_5 = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 1,  1,  2,  3 }	/* (SIZE(2..3)) */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_mnc_5 = {
	"mnc",
	"mnc",
	SEQUENCE_OF_free,
	SEQUENCE_OF_print,
	SEQUENCE_OF_constraint,
	SEQUENCE_OF_decode_ber,
	SEQUENCE_OF_encode_der,
	SEQUENCE_OF_decode_xer,
	SEQUENCE_OF_encode_xer,
	SEQUENCE_OF_decode_uper,
	SEQUENCE_OF_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_mnc_tags_5,
	sizeof(asn_DEF_mnc_tags_5)
		/sizeof(asn_DEF_mnc_tags_5[0]) - 1, /* 1 */
	asn_DEF_mnc_tags_5,	/* Same as above */
	sizeof(asn_DEF_mnc_tags_5)
		/sizeof(asn_DEF_mnc_tags_5[0]), /* 2 */
	&asn_PER_mnc_constr_5,
	asn_MBR_mnc_5,
	1,	/* Single element */
	&asn_SPC_mnc_specs_5	/* Additional specs */
};

static asn_per_constraints_t asn_PER_memb_mcc_constr_3 = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 0,  0,  3,  3 }	/* (SIZE(3..3)) */
};
static asn_per_constraints_t asn_PER_memb_mnc_constr_5 = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 1,  1,  2,  3 }	/* (SIZE(2..3)) */
};
static asn_TYPE_member_t asn_MBR_plmn_Identity_2[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct LPP_CellGlobalIdEUTRA_AndUTRA__plmn_Identity, mcc),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_mcc_3,
		memb_mcc_constraint_2,
		&asn_PER_memb_mcc_constr_3,
		0,
		"mcc"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct LPP_CellGlobalIdEUTRA_AndUTRA__plmn_Identity, mnc),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_mnc_5,
		memb_mnc_constraint_2,
		&asn_PER_memb_mnc_constr_5,
		0,
		"mnc"
		},
};
static ber_tlv_tag_t asn_DEF_plmn_Identity_tags_2[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_plmn_Identity_tag2el_2[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* mcc at 2550 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* mnc at 2551 */
};
static asn_SEQUENCE_specifics_t asn_SPC_plmn_Identity_specs_2 = {
	sizeof(struct LPP_CellGlobalIdEUTRA_AndUTRA__plmn_Identity),
	offsetof(struct LPP_CellGlobalIdEUTRA_AndUTRA__plmn_Identity, _asn_ctx),
	asn_MAP_plmn_Identity_tag2el_2,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_plmn_Identity_2 = {
	"plmn-Identity",
	"plmn-Identity",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	SEQUENCE_decode_uper,
	SEQUENCE_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_plmn_Identity_tags_2,
	sizeof(asn_DEF_plmn_Identity_tags_2)
		/sizeof(asn_DEF_plmn_Identity_tags_2[0]) - 1, /* 1 */
	asn_DEF_plmn_Identity_tags_2,	/* Same as above */
	sizeof(asn_DEF_plmn_Identity_tags_2)
		/sizeof(asn_DEF_plmn_Identity_tags_2[0]), /* 2 */
	0,	/* No PER visible constraints */
	asn_MBR_plmn_Identity_2,
	2,	/* Elements count */
	&asn_SPC_plmn_Identity_specs_2	/* Additional specs */
};

static asn_per_constraints_t asn_PER_memb_eutra_constr_8 = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 0,  0,  28,  28 }	/* (SIZE(28..28)) */
};
static asn_per_constraints_t asn_PER_memb_utra_constr_9 = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 0,  0,  32,  32 }	/* (SIZE(32..32)) */
};
static asn_TYPE_member_t asn_MBR_cellIdentity_7[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct LPP_CellGlobalIdEUTRA_AndUTRA__cellIdentity, choice.eutra),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BIT_STRING,
		memb_eutra_constraint_7,
		&asn_PER_memb_eutra_constr_8,
		0,
		"eutra"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct LPP_CellGlobalIdEUTRA_AndUTRA__cellIdentity, choice.utra),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BIT_STRING,
		memb_utra_constraint_7,
		&asn_PER_memb_utra_constr_9,
		0,
		"utra"
		},
};
static asn_TYPE_tag2member_t asn_MAP_cellIdentity_tag2el_7[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* eutra at 2554 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* utra at 2555 */
};
static asn_CHOICE_specifics_t asn_SPC_cellIdentity_specs_7 = {
	sizeof(struct LPP_CellGlobalIdEUTRA_AndUTRA__cellIdentity),
	offsetof(struct LPP_CellGlobalIdEUTRA_AndUTRA__cellIdentity, _asn_ctx),
	offsetof(struct LPP_CellGlobalIdEUTRA_AndUTRA__cellIdentity, present),
	sizeof(((struct LPP_CellGlobalIdEUTRA_AndUTRA__cellIdentity *)0)->present),
	asn_MAP_cellIdentity_tag2el_7,
	2,	/* Count of tags in the map */
	0,
	-1	/* Extensions start */
};
static asn_per_constraints_t asn_PER_cellIdentity_constr_7 = {
	{ APC_CONSTRAINED,	 1,  1,  0,  1 }	/* (0..1) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 }
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_cellIdentity_7 = {
	"cellIdentity",
	"cellIdentity",
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
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	&asn_PER_cellIdentity_constr_7,
	asn_MBR_cellIdentity_7,
	2,	/* Elements count */
	&asn_SPC_cellIdentity_specs_7	/* Additional specs */
};

static asn_per_constraints_t asn_PER_memb_cellIdentity_constr_7 = {
	{ APC_CONSTRAINED,	 1,  1,  0,  1 }	/* (0..1) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 }
};
static asn_TYPE_member_t asn_MBR_LPP_CellGlobalIdEUTRA_AndUTRA_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct LPP_CellGlobalIdEUTRA_AndUTRA, plmn_Identity),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_plmn_Identity_2,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"plmn-Identity"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct LPP_CellGlobalIdEUTRA_AndUTRA, cellIdentity),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_cellIdentity_7,
		0,	/* Defer constraints checking to the member type */
		&asn_PER_memb_cellIdentity_constr_7,
		0,
		"cellIdentity"
		},
};
static ber_tlv_tag_t asn_DEF_LPP_CellGlobalIdEUTRA_AndUTRA_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_LPP_CellGlobalIdEUTRA_AndUTRA_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* plmn-Identity at 2550 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* cellIdentity at 2554 */
};
static asn_SEQUENCE_specifics_t asn_SPC_LPP_CellGlobalIdEUTRA_AndUTRA_specs_1 = {
	sizeof(struct LPP_CellGlobalIdEUTRA_AndUTRA),
	offsetof(struct LPP_CellGlobalIdEUTRA_AndUTRA, _asn_ctx),
	asn_MAP_LPP_CellGlobalIdEUTRA_AndUTRA_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	1,	/* Start extensions */
	3	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_LPP_CellGlobalIdEUTRA_AndUTRA = {
	"LPP_CellGlobalIdEUTRA-AndUTRA",
	"LPP_CellGlobalIdEUTRA-AndUTRA",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	SEQUENCE_decode_uper,
	SEQUENCE_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_LPP_CellGlobalIdEUTRA_AndUTRA_tags_1,
	sizeof(asn_DEF_LPP_CellGlobalIdEUTRA_AndUTRA_tags_1)
		/sizeof(asn_DEF_LPP_CellGlobalIdEUTRA_AndUTRA_tags_1[0]), /* 1 */
	asn_DEF_LPP_CellGlobalIdEUTRA_AndUTRA_tags_1,	/* Same as above */
	sizeof(asn_DEF_LPP_CellGlobalIdEUTRA_AndUTRA_tags_1)
		/sizeof(asn_DEF_LPP_CellGlobalIdEUTRA_AndUTRA_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_LPP_CellGlobalIdEUTRA_AndUTRA_1,
	2,	/* Elements count */
	&asn_SPC_LPP_CellGlobalIdEUTRA_AndUTRA_specs_1	/* Additional specs */
};

