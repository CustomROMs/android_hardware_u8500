/*
 * SUPL_ULP_GanssReqGenericData.h
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

#ifndef    _SUPL_ULP_GanssReqGenericData_H_
#define    _SUPL_ULP_GanssReqGenericData_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <BIT_STRING.h>
#include <BOOLEAN.h>
#include "SUPL_ULP_DGANSS-Sig-Id-Req.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct GanssNavigationModelData;
struct GanssDataBits;
struct GanssAdditionalDataChoices;
struct ExtendedEphemeris;
struct GanssExtendedEphCheck;

/* SUPL_ULP_GanssReqGenericData */
typedef struct GanssReqGenericData {
    long     ganssId;
    BIT_STRING_t    *ganssSBASid    /* OPTIONAL */;
    BOOLEAN_t     ganssRealTimeIntegrity;
    DGANSS_Sig_Id_Req_t    *ganssDifferentialCorrection    /* OPTIONAL */;
    BOOLEAN_t     ganssAlmanac;
    struct GanssNavigationModelData    *ganssNavigationModelData    /* OPTIONAL */;
    BIT_STRING_t    *ganssTimeModels    /* OPTIONAL */;
    BOOLEAN_t     ganssReferenceMeasurementInfo;
    struct GanssDataBits    *ganssDataBits    /* OPTIONAL */;
    BOOLEAN_t     ganssUTCModel;
    struct GanssAdditionalDataChoices    *ganssAdditionalDataChoices    /* OPTIONAL */;
    BOOLEAN_t     ganssAuxiliaryInformation;
    struct ExtendedEphemeris    *ganssExtendedEphemeris    /* OPTIONAL */;
    struct GanssExtendedEphCheck    *ganssExtendedEphemerisCheck    /* OPTIONAL */;
    /*
     * This type is extensible,
     * possible extensions are below.
     */
    
    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} GanssReqGenericData_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GanssReqGenericData;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "SUPL_ULP_GanssNavigationModelData.h"
#include "SUPL_ULP_GanssDataBits.h"
#include "SUPL_ULP_GanssAdditionalDataChoices.h"
#include "SUPL_ULP_ExtendedEphemeris.h"
#include "SUPL_ULP_GanssExtendedEphCheck.h"

#endif    /* _SUPL_ULP_GanssReqGenericData_H_ */
