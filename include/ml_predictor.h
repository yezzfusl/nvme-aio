#ifndef ML_PREDICTOR_H
#define ML_PREDICTOR_H

#include <linux/types.h>

int init_ml_predictor(void);
void cleanup_ml_predictor(void);
void record_io_event(int32_t io_size);
int32_t predict_next_io_size(void);

#endif // ML_PREDICTOR_H

