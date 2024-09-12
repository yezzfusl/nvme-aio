#ifndef SSD_DETECTOR_H
#define SSD_DETECTOR_H

struct nvme_ssd_info {
    const char* model;
    const char* fw_version;
    unsigned int capacity_gb;
};

int init_ssd_detector(void);
void cleanup_ssd_detector(void);
struct nvme_ssd_info* get_detected_ssd_info(void);

#endif // SSD_DETECTOR_H

