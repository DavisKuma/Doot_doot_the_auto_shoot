int incomingByte = 0; // for incoming serial data
  #include <Stepper.h>
unsigned val_x;
unsigned val_y;
// change this to the number of steps on your motor
const int stepsPerRevolution = 100;

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper_x(stepsPerRevolution, 8, 9, 10, 11);
Stepper stepper_y(stepsPerRevolution, 4, 5, 6, 7);

// the previous reading from the analog input
int previous = 0;

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  // set the speed of the motor to 30 RPMs
  stepper_x.setSpeed(20);
  stepper_y.setSpeed(20);
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read() -'0';
    Serial.flush();

    // say what you got:
     
  }

  // get the sensor value
  //X axis stepper motor 
   switch (incomingByte){
    case 1:
     stepper_y.step(stepsPerRevolution);
     break;
    case 2:
     stepper_y.step(-stepsPerRevolution);
     break;
    case 3:
     stepper_x.step(stepsPerRevolution);
     break;
    case 4:
     stepper_x.step(-stepsPerRevolution);
     break;
  }


  // remember the previous value of the sensor
}
