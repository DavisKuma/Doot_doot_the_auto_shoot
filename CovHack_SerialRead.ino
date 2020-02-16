unsigned incomingByte = 0; // for incoming serial data
  #include <Stepper.h>
unsigned val_x;
unsigned val_y;
// change this to the number of steps on your motor
#define STEPS 100

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper_x(STEPS, 8, 9, 10, 11);
Stepper stepper_y(STEPS, 4, 5, 6, 7);

// the previous reading from the analog input
int previous = 0;

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  // set the speed of the motor to 30 RPMs
  stepper_x.setSpeed(30);
  stepper_y.setSpeed(30);
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.println(incomingByte);   
  }

  // get the sensor value
  //X axis stepper motor 
  if(incomingByte==left){
  val_x = 10;
  }
  else if(incomingByte==right{
   val_x = -10;
  }
  //Y axis stepper motor
  if(incomingByte==up){
  val_y = 10;
  }
  else{
   val_y = -10;
  }
  

  // move a number of steps equal to the change in the
  // sensor reading
  stepper_x.step(val_x - previous);
  stepper_y.step(val_y - previous);

  // remember the previous value of the sensor
  previous = val_x;
  previous = val_y;
}
