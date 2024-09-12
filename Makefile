obj-m += nvme_adaptive_io.o
nvme_adaptive_io-objs := src/main.o src/ssd_detector.o src/queue_manager.o src/ml_predictor.o src/wear_leveling.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

