/*
 * LPP_GNSS-GenericAssistDataSupportElement.h
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

#ifndef	_LPP_GNSS_GenericAssistDataSupportElement_H_
#define	_LPP_GNSS_GenericAssistDataSupportElement_H_


#include <asn_application.h>

/* Including external dependencies */
#include "LPP_GNSS-ID.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct LPP_SBAS_ID;
struct LPP_GNSS_TimeModelListSupport;
struct LPP_GNSS_DifferentialCorrectionsSupport;
struct LPP_GNSS_NavigationModelSupport;
struct LPP_GNSS_RealTimeIntegritySupport;
struct LPP_GNSS_DataBitAssistanceSupport;
struct LPP_GNSS_AcquisitionAssistanceSupport;
struct LPP_GNSS_AlmanacSupport;
struct LPP_GNSS_UTC_ModelSupport;
struct LPP_GNSS_AuxiliaryInformationSupport;

/* LPP_GNSS-GenericAssistDataSupportElement */
typedef struct LPP_GNSS_GenericAssistDataSupportElement {
	LPP_GNSS_ID_t	 gnss_ID;
	struct LPP_SBAS_ID	*sbas_ID	/* OPTIONAL */;
	struct LPP_GNSS_TimeModelListSupport	*gnss_TimeModelsSupport	/* OPTIONAL */;
	struct LPP_GNSS_DifferentialCorrectionsSupport	*gnss_DifferentialCorrectionsSupport	/* OPTIONAL */;
	struct LPP_GNSS_NavigationModelSupport	*gnss_NavigationModelSupport	/* OPTIONAL */;
	struct LPP_GNSS_RealTimeIntegritySupport	*gnss_RealTimeIntegritySupport	/* OPTIONAL */;
	struct LPP_GNSS_DataBitAssistanceSupport	*gnss_DataBitAssistanceSupport	/* OPTIONAL */;
	struct LPP_GNSS_AcquisitionAssistanceSupport	*gnss_AcquisitionAssistanceSupport	/* OPTIONAL */;
	struct LPP_GNSS_AlmanacSupport	*gnss_AlmanacSupport	/* OPTIONAL */;
	struct LPP_GNSS_UTC_ModelSupport	*gnss_UTC_ModelSupport	/* OPTIONAL */;
	struct LPP_GNSS_AuxiliaryInformationSupport	*gnss_AuxiliaryInformationSupport	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} LPP_GNSS_GenericAssistDataSupportElement_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_LPP_GNSS_GenericAssistDataSupportElement;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "LPP_SBAS-ID.h"
#include "LPP_GNSS-TimeModelListSupport.h"
#include "LPP_GNSS-DifferentialCorrectionsSupport.h"
#include "LPP_GNSS-NavigationModelSupport.h"
#include "LPP_GNSS-RealTimeIntegritySupport.h"
#include "LPP_GNSS-DataBitAssistanceSupport.h"
#include "LPP_GNSS-AcquisitionAssistanceSupport.h"
#include "LPP_GNSS-AlmanacSupport.h"
#include "LPP_GNSS-UTC-ModelSupport.h"
#include "LPP_GNSS-AuxiliaryInformationSupport.h"

#endif	/* _LPP_GNSS_GenericAssistDataSupportElement_H_ */