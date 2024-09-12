obj-m += nvme_adaptive_io.o
nvme_adaptive_io-objs := src/main.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

