/*
 * RRLP_Rel7-MsrPosition-Req-Extension.h
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
 * From ASN.1 module "RRLP_Components"
 * 	found in "LPP_RRLP_Rel_10.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_RRLP_Rel7_MsrPosition_Req_Extension_H_
#define	_RRLP_Rel7_MsrPosition_Req_Extension_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NULL.h>
#include "RRLP_GANSSPositioningMethod.h"
#include "RRLP_RequiredResponseTime.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct RRLP_GANSS_AssistData;
struct RRLP_Add_GPS_AssistData;

/* RRLP_Rel7-MsrPosition-Req-Extension */
typedef struct RRLP_Rel7_MsrPosition_Req_Extension {
	NULL_t	*velocityRequested	/* OPTIONAL */;
	RRLP_GANSSPositioningMethod_t	*ganssPositionMethod	/* OPTIONAL */;
	struct RRLP_GANSS_AssistData	*ganss_AssistData	/* OPTIONAL */;
	NULL_t	*ganssCarrierPhaseMeasurementRequest	/* OPTIONAL */;
	NULL_t	*ganssTODGSMTimeAssociationMeasurementRequest	/* OPTIONAL */;
	RRLP_RequiredResponseTime_t	*requiredResponseTime	/* OPTIONAL */;
	struct RRLP_Add_GPS_AssistData	*add_GPS_AssistData	/* OPTIONAL */;
	NULL_t	*ganssMultiFreqMeasurementRequest	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RRLP_Rel7_MsrPosition_Req_Extension_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RRLP_Rel7_MsrPosition_Req_Extension;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "RRLP_GANSS-AssistData.h"
#include "RRLP_Add-GPS-AssistData.h"

#endif	/* _RRLP_Rel7_MsrPosition_Req_Extension_H_ */
