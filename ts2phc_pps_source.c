/**
 * @file ts2phc_pps_source.c
 * @note Copyright (C) 2019 Richard Cochran <richardcochran@gmail.com>
 * @note SPDX-License-Identifier: GPL-2.0+
 */
#include "ts2phc_generic_pps_source.h"
#include "ts2phc_nmea_pps_source.h"
#include "ts2phc_phc_pps_source.h"
#include "ts2phc_pps_source_private.h"

struct ts2phc_pps_source *ts2phc_pps_source_create(struct config *cfg, const char *dev,
						   enum ts2phc_pps_source_type type)
{
	struct ts2phc_pps_source *src = NULL;

	switch (type) {
	case TS2PHC_PPS_SOURCE_GENERIC:
		src = ts2phc_generic_pps_source_create(cfg, dev);
		break;
	case TS2PHC_PPS_SOURCE_NMEA:
		src = ts2phc_nmea_pps_source_create(cfg, dev);
		break;
	case TS2PHC_PPS_SOURCE_PHC:
		src = ts2phc_phc_pps_source_create(cfg, dev);
		break;
	}
	return src;
}

void ts2phc_pps_source_destroy(struct ts2phc_pps_source *src)
{
	src->destroy(src);
}

int ts2phc_pps_source_getppstime(struct ts2phc_pps_source *src, struct timespec *ts)
{
	return src->getppstime(src, ts);
}
