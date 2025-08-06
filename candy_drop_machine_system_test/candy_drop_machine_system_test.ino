// A library to move the servo
#include <Servo.h>

// Define pins for motors and sensors
int disk_speed_pin = 12;
int disk_direction_pin = 13;
int servo_pin = 11;
int red_led_pin = 18;
int button_pin = 19;

Servo drop_servo;

void setup() {
  pinMode(disk_speed_pin, OUTPUT);
  pinMode(disk_direction_pin, OUTPUT);
  pinMode(red_led_pin, OUTPUT);
  pinMode(button_pin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  drop_servo.attach(servo_pin);


}

int counter = 0;

void loop() {
  bool button_pressed = digitalRead(button_pin);
  if (button_pressed){
    digitalWrite(LED_BUILTIN, HIGH);
  } else{
    digitalWrite(LED_BUILTIN, LOW);
  }

  if (counter == 0){
    drop_servo.write(10);
    digitalWrite(red_led_pin, HIGH);
    digitalWrite(disk_direction_pin, HIGH);
    analogWrite(disk_speed_pin, 255);
  } else if (counter == 333){
    digitalWrite(disk_direction_pin, LOW);
    analogWrite(disk_speed_pin, 255);
  } else if (counter == 500){
    drop_servo.write(90);
    digitalWrite(red_led_pin, LOW);
  } else if (counter == 666){
    digitalWrite(disk_direction_pin, LOW);
    analogWrite(disk_speed_pin, 0);
  }

  delay(1);
  counter++;
  if (counter == 1000){
    counter = 0;
  }
}
