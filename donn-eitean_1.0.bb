DESCRIPTION = "Development driver for mem allocations"
LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://donn_eitean.c;md5=ca60b8535185bceca633d640c65e6962"

inherit module

PR = "r0"

SRC_URI = "file://Makefile file://donn_eitean.c"
S = "${WORKDIR}"
