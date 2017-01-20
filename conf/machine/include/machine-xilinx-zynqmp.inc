#add Boot.bin dependency
IMAGE_CLASSES_xilinx-hdf_append += " xilinx-bootbin"

#specify BIF common attribute for FSBL
BIF_COMMON_ATTR= "fsbl_config"
BIF_COMMON_ATTR[fsbl_config]="a53_x64"


#specify BIF partition attributes required for BOOT.bin
BIF_PARTITION_ATTR= "fsbl pmu atf u-boot"

#specify BIF partition attributes for FSBL
#bootloader is FSBL. Location where FSBL binary is present and dependency to build FSBL
BIF_PARTITION_ATTR[fsbl]="bootloader"
BIF_PARTITION_IMAGE[fsbl]="${DEPLOY_DIR_IMAGE}/fsbl-${MACHINE}.elf"
BIF_PARTITION_DEPENDS[fsbl]="virtual/fsbl"

#specify BIF partition attributes for PMU Firmware
#destination cpu for PMU. Location where PMU binary is present and dependency to build PMU Firmware
BIF_PARTITION_ATTR[pmu]="destination_cpu=pmu"
BIF_PARTITION_IMAGE[pmu]="${DEPLOY_DIR_IMAGE}/pmu-${MACHINE}.elf"
BIF_PARTITION_DEPENDS[pmu]="virtual/pmufw"

#specify BIF partition attributes for ATF
#destination cpu for ATF, security levels. Location where ATF binary is present (dependency is not required as ATF is always built for ZU+, see zcu102-zynqmp.conf)
BIF_PARTITION_ATTR[atf]="destination_cpu=a53-0,exception_level=el-3,trustzone"
BIF_PARTITION_IMAGE[atf]="${DEPLOY_DIR_IMAGE}/arm-trusted-firmware.elf"
BIF_PARTITION_DEPENDS[atf]="arm-trusted-firmware"

#specify BIF partition attributes for u-boot
#destination cpu for u-boot, security levels. Location where u-boot binary is present (dependency is not required as u-boot is always built for ZU+, see zcu102-zynqmp.conf)
BIF_PARTITION_ATTR[u-boot]="destination_cpu=a53-0,exception_level=el-2"
BIF_PARTITION_IMAGE[u-boot]="${DEPLOY_DIR_IMAGE}/u-boot-${MACHINE}.elf"
BIF_PARTITION_DEPENDS[u-boot]="virtual/bootloader"