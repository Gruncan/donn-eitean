DESCRIPTION = "Development driver for mem allocations"
LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://donn_eitean.c;md5=08804161b208d28f83f85cd78c2e2338"

inherit module

PR = "r0"

SRC_URI = "file://Makefile file://donn_eitean.c"
S = "${WORKDIR}"
