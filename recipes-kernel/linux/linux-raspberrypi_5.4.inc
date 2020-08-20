FILESEXTRAPATHS_prepend := "${THISDIR}/linux-raspberrypi:"

SRCREV_meta = "aafb8f095e97013d6e55b09ed150369cbe0c6476"

SRC_URI = " \
    git://github.com/raspberrypi/linux.git;branch=${LINUX_RPI_BRANCH} \
    "
SRC_URI_remove = "file://rpi-kernel-misc.cfg"
SRC_URI_append += " \
                git://git.yoctoproject.org/yocto-kernel-cache;type=kmeta;name=meta;branch=yocto-5.4;destsuffix=kernel-meta \
		"             
require linux-raspberrypi.inc

LIC_FILES_CHKSUM = "file://COPYING;md5=bbea815ee2795b2f4230826c0c6b8814"

KERNEL_EXTRA_ARGS_append_rpi = " DTC_FLAGS='-@ -H epapr'"
