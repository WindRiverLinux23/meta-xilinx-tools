SUMMARY = "Xilinx libdfx library"
DESCRIPTION = "Xilinx libdfx Library and headers"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE.md;md5=94aba86aec117f003b958a52f019f1a7"

BRANCH ?= "master"
REPO ?= "git://github.com/Xilinx/libdfx.git;protocol=https"
BRANCHARG = "${@['nobranch=1', 'branch=${BRANCH}'][d.getVar('BRANCH', True) != '']}"
SRC_URI = "${REPO};${BRANCHARG}"
SRCREV ?= "f45bded93fcb9b853ab04e52eec0e5816ef3b308"

COMPATIBLE_MACHINE = "^$"
COMPATIBLE_MACHINE_zynqmp = "zynqmp"
COMPATIBLE_MACHINE_versal = "versal"

S = "${WORKDIR}/git/"

inherit cmake

RDEPENDS_${PN} = "${PN}-staticdev"
PACKAGES =+ "${PN}-examples"

do_install () {
    install -d ${D}${libdir}
    install -d ${D}${includedir}
    install -d ${D}${bindir}
    install -m 0644 ${B}/src/libdfx.a ${D}${libdir}
    install -m 0644 ${B}/include/libdfx.h ${D}${includedir}
    install -m 0755 ${B}/apps/dfx_app ${D}${bindir}
}

ALLOW_EMPTY_${PN} = "1"
ALLOW_EMPTY_${PN}-examples = "1"
