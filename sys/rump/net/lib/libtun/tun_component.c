/*	$NetBSD: tun_component.c,v 1.1 2016/09/05 02:25:38 ozaki-r Exp $	*/

/*
 * Copyright (c) 2016 Internet Initiative Japan Inc.
 * All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: tun_component.c,v 1.1 2016/09/05 02:25:38 ozaki-r Exp $");

#include <sys/param.h>
#include <sys/device.h>
#include <sys/stat.h>

#include <rump-sys/kern.h>
#include <rump-sys/vfs.h>

#include "ioconf.h"

CFDRIVER_DECL(tun, DV_IFNET, NULL);

RUMP_COMPONENT(RUMP_COMPONENT_NET_IF)
{
	extern const struct cdevsw tun_cdevsw;
	devmajor_t bmaj, cmaj;
	int error;

	config_cfdriver_attach(&tun_cd);
	tunattach(0);

	bmaj = cmaj = NODEVMAJOR;
	error = devsw_attach("tun", NULL, &bmaj, &tun_cdevsw, &cmaj);
	if (error != 0)
		panic("tun devsw attach failed: %d", error);

	error = rump_vfs_makeonedevnode(S_IFCHR, "/dev/tun", cmaj,
	    0xfffff);
	if (error != 0)
		panic("cannot create tun device node: %d", error);

	error = rump_vfs_makedevnodes(S_IFCHR, "/dev/tun", '0', cmaj,
	    0, 4);
	if (error != 0)
		panic("cannot create tun[0-4] device node: %d", error);
}
