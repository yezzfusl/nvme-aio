# NVMe Adaptive I/O Scheduler

This kernel module implements an intelligent I/O scheduler optimized for modern NVMe SSDs. It uses machine learning techniques to predict I/O patterns, dynamically adjust queue depths, and manage wear leveling.

## Features

- Basic NVMe SSD detection
- Dynamic queue depth adjustment
- Simple machine learning-based I/O pattern prediction
- Adaptive scheduling based on predicted I/O sizes

## TODO

- Implement advanced wear-leveling strategies
- Enhance ML model for better I/O prediction
- Add support for various NVMe SSD architectures

## Building and Installing

To build the module:

`make`

To install the module:

`sudo insmod nvme_adaptive_io.ko`

To remove the module:

`sudo rmmod nvme_adaptive_io`

## Testing 
After loading the module, you can check the kernel log for initialization messages:

`dmesg | tail` or `sudo dmesg | tail`

## Licence
This project is licensed under the GPL License.


