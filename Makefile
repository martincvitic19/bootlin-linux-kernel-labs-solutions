ifneq ($(KERNELRELEASE),)
obj-m := hello_version.o

else
KDIR := $(HOME)/linux-kernel-labs/src/linux
ARCH := arm
CROSS_COMPILE := arm-linux-gnueabihf-

all:
	$(MAKE) -C $(KDIR) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE)

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE)

endif

