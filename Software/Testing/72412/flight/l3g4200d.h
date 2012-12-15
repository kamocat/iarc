/* Note that I'm using the same exclude clause for both gyros.
 * Only include the one you're actually using.
 */
#ifndef GYRO_HEADER
#define GYRO_HEADER

#define GYRO 0b11010000

void l3g4200d_init(TWI_Master_t *title);

void getgyro(int * gyrocache, TWI_Master_t *imu);


#endif
