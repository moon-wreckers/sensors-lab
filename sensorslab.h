
#ifndef sensorslab
#define sensorslab

//--------- COMPONENTS PIN DEFINITIONS ----------

#define BUTTON_PIN 2

/*
 * DC Motor
 */
#define DC_MOTOR_ENC_A 1
#define DC_MOTOR_ENC_B 4


#define DC_MOTOR_EN 5
#define DC_MOTOR_1 6
#define DC_MOTOR_2 7


#define DC_SPEED_LOW 140
#define DC_SPEED_MEDIUM 198
#define DC_SPEED_HIGH 255

/*
 * Servo Motor
 */
#define SERVO_PIN 8


/*
 * Rotary Potentiometer
 */
#define IR_PIN A0

/*
 * Light Gate Sensor
 */
#define SLOT_PIN  A1

/*
 * Rotary Potentiometer
 */
#define ROT_POT_SENSOR_PIN A2

/*
 * Flex Sensor
 */
#define FLEX_SENSOR_PIN A5

typedef enum{
CLOCKWISE,
COUNTERCLOCKWISE
} rot_dir;

#endif
