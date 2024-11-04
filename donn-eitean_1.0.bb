DESCRIPTION = "Development driver for mem allocations"
LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://${BPN}.c;md5=2c7c6bf3402cde2ac4fbeba9f6497456"

inherit module

PR = "r0"

SRC_URI = "file://Makefile file://${BPN}.c"
S = "${WORKDIR}"
