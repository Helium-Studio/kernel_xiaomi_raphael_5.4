/* Copyright (c) 2017-2018, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _CAM_ICP_SUBDEV_H_
#define _CAM_ICP_SUBDEV_H_

/**
 * @brief : API to register ICP subdev to platform framework.
 * @return struct platform_device pointer on on success, or ERR_PTR() on error.
 */
int cam_icp_init_module(void);

/**
 * @brief : API to remove ICP subdev from platform framework.
 */
void cam_icp_exit_module(void);

#endif /* _CAM_ICP_SUBDEV_H_ */
