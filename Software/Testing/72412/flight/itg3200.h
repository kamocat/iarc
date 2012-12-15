/* Note that I'm using the same exclude clause for both gyros.
 * Only include the one you're actually using.
 */
#ifndef GYRO_HEADER
#define GYRO_HEADER

#define GYRO (0xD0 >> 1)

void itg3200Init(TWI_Master_t *title, int rate);

void getgyro(int *gyrocache, TWI_Master_t *imu, uint8_t *gyrostartbyte);

#endif
