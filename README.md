This repository contains a git mirror of NetBSD source code relevant to
rump kernels.  There are three basic branches (note, these branches
have no overlap):

* kernel-src: NetBSD sources necessary for building rump kernel components
* user-src: selection of NetBSD userspace sources for appstacks on top of rump kernel (libs, utils)
* posix-src: NetBSD sources for rump kernels on POSIX-y platforms

For convenience, we provide "consumer-ready" merged branches:

* buildrump-src: kernel+posix, what buildrump.sh wants in POSIX mode
* appstack-src: kernel+user, what you want for most appstacks (e.g. Xen)
* all-src: kernel+user+posix

Note, the goal of this repository is to mirror NetBSD sources, so
pullup requests will not be accepted.  Either submit patches directly
to NetBSD via the [problem report web
page](http://netbsd.org/cgi-bin/sendpr.cgi?gndb=netbsd) or to the
[rumpkernel-users mailing list](https://lists.sourceforge.net/lists/listinfo/rumpkernel-users).
