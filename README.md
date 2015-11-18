_Note: Unless you are a developer integrating rump kernels into
your project, there should be no reason to be here._

This repository contains a git mirror of NetBSD source code relevant to
rump kernels.  There are three basic, non-overlapping branches:

* kernel-src: rump kernel components and build tools
* user-src: selection of NetBSD userspace sources for providing a POSIX-y interface _on top_ of a rump kernel
* posix-src: support for running rump kernels _on_ POSIX-y platforms

For most projects, any of the above branches are not useful alone,
so we provide merged versions:

* buildrump-src: kernel+posix, what buildrump.sh wants in POSIX mode
* appstack-src: kernel+user, useful for e.g. unikernels
* all-src: kernel+user+posix

Note, this repository is a mirror of NetBSD sources, so patches will
not be accepted.  Either submit patches directly to NetBSD via the
[problem report web
page](http://netbsd.org/cgi-bin/sendpr.cgi?gndb=netbsd) or to the
[rumpkernel-users mailing list](https://www.freelists.org/list/rumpkernel-users).
