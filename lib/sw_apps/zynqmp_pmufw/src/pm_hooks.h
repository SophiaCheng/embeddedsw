/*
 * Copyright (C) 2017 - 2018 Xilinx, Inc.  All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Except as contained in this notice, the name of the Xilinx shall not be used
 * in advertising or otherwise to promote the sale, use or other dealings in
 * this Software without prior written authorization from Xilinx.
 */

#ifndef PM_HOOKS_H_
#define PM_HOOKS_H_
#include "pm_common.h"
#include "pm_slave.h"

#define POS_DDR_REQS_SIZE	1U

/**
 * PmPosRequirement - Power Off Suspend requirements
 * @slave	Slave for which the requirements are set
 * @caps	Capabilities of the slave that are required by the system
 */
typedef struct PmPosRequirement {
	PmSlave* const slave;
	u32 caps;
} PmPosRequirement;

extern PmPosRequirement pmPosDdrReqs_g[POS_DDR_REQS_SIZE];

int PmHookPosSaveDdrContext(void);
void PmHookFinalizePowerOffSuspend(void);
void PmHookPowerDownLpd(void);
void PmHookInitPowerOffSuspend(void);
u32 PmHookGetBootType(void);
int PmHookRestoreDdrContext(void);
void PmHookPowerOffSuspendDdrReady(void);

#endif
