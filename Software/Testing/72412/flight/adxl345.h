/* Note that I'm using the same exclude clause for both accelerometers.
 * Only include the one you're actually using.
 */
#ifndef ACCELEROMETER_HEADER
#define ACCELEROMETER_HEADER

#define ACCEL (0xA6 >> 1)

void adxl345Init(TWI_Master_t *title);

void getaccel(int *accelcache, TWI_Master_t *imu, uint8_t *accelstartbyte);

#endif
