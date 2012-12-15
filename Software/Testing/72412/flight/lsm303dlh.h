/* Note that I'm using the same exclude clause for both accelerometers.
 * Only include the one you're actually using.
 */
#ifndef ACCELEROMETER_HEADER
#define ACCELEROMETER_HEADER


#define MAG 0b00011110
//#define ACCEL 0b00110010


void lsm303dlhInit(TWI_Master_t *title);

void getmag(int * magcache, TWI_Master_t *title);

//void getaccel(int * accelcache, TWI_Master_t *imu);

#endif
