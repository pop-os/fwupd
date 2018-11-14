/*
 * Copyright (C) 2017 Intel Corporation.
 *
 * SPDX-License-Identifier: LGPL-2.1+
 */

#ifndef __FU_THUNDERBOLT_IMAGE_H__
#define __FU_THUNDERBOLT_IMAGE_H__

#include <glib.h>

typedef enum {
	VALIDATION_PASSED,
	VALIDATION_FAILED,
	UNKNOWN_DEVICE,
} FuPluginValidation;

FuPluginValidation	fu_thunderbolt_image_validate		(GBytes  *controller_fw,
								 GBytes  *blob_fw,
								 GError **error);

gboolean	fu_thunderbolt_image_controller_is_native	(GBytes    *controller_fw,
								 gboolean  *is_native,
								 GError   **error);

#endif /* __FU_THUNDERBOLT_IMAGE_H__ */
