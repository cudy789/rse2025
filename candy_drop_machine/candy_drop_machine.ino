// A library to move the servo
#include <Servo.h>

// Define pins for motors and sensors
int disk_speed_pin = 12;
int disk_direction_pin = 13;
int servo_pin = 11;
int red_led_pin = 18;
int button_pin = 19;

// Spiral disk motor speed (0-255) and the servo angles for the hopper disk (0-180 degrees)
int disk_speed = 150;
int open_angle = 150;
int closed_angle = 5;

Servo drop_servo;

void setup() {
  pinMode(disk_speed_pin, OUTPUT);
  pinMode(disk_direction_pin, OUTPUT);
  pinMode(red_led_pin, OUTPUT);
  pinMode(button_pin, INPUT);

  drop_servo.attach(servo_pin);
  delay(100); // need a delay sometimes for the servo to connect properly
  drop_servo.write(closed_angle);

  digitalWrite(disk_direction_pin, HIGH);
  analogWrite(disk_speed_pin, disk_speed);

}

void loop() {

  bool button_pressed = digitalRead(button_pin);
  if (button_pressed == true){
    digitalWrite(red_led_pin, HIGH);
    drop_servo.write(open_angle);
    delay(500);
    drop_servo.write(closed_angle);
    delay(500);
    digitalWrite(red_led_pin, LOW);
  }

}
