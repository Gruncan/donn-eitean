DESCRIPTION = "Development driver for mem allocations"
LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://donn_eitean.c;md5=6e141e82c5115ae06915ed2df5d1a886"

inherit module

PR = "r0"

SRC_URI = "file://Makefile file://donn_eitean.c"
S = "${WORKDIR}"
