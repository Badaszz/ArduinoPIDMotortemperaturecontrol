// Program to control the fan speed based on the set temperature from the potentimetre
// And the current temperature is from the temperature sensor

// Hardware mapping
#define PWM_OUT  3 
#define ENCODER_A 2
#define POT_IN A0
#define TEMP_SENS A1

// Global Variables

int output;           // pwm output
int speed;        // motor speed
int lastError = 0;    // declaring the last error as zero

int setpoint;
int error = 0;           // current error
int I_error = 0;         // Integral error (error summation)
int D_error = 0;         // derivative error (error difference from last error)
float KP = 0.1;          // proportional constant
float KI = 0.0001;       // integral constant
float KD = 0.001;        // derivative constant
//tune constants as required
//code has to be run in a real environment to get proper tuning results

void setup() {
  
  Serial.begin(9600);                 // initialize serial communication
  
  pinMode(ENCODER_A, INPUT);         // define encoder as input
  pinMode(POT_IN, INPUT);     // define potentiometre as input
  pinMode(PWM_OUT, OUTPUT);// output for PWM
  pinMode(TEMP_SENS, INPUT);
  
  output = 10;                    // initial pwm output (motor speed) 
  analogWrite(PWM_OUT, output);   // set the initial output as 10
  }

void loop() {
   // get the reading from the potentiometre, this is the set point
  setpoint = map(analogRead(POT_IN), 0,1023,-35,120); //-40°C to +125°C is the tmp36 range  
   
  // read the ouptut of the temperature sensor
  int raw = analogRead(TEMP_SENS);
  float voltage = raw * 5.0 / 1023.0;  // Convert analog reading to voltage (0–5V)
  float temperatureC = (voltage - 0.5) * 100.0;  // TMP36: 10mV per °C with 500mV offset
 
  
  error = temperatureC - setpoint; // calculate error
   
  I_error += error; // error summation
  D_error = error - lastError; // the derivative error
  // Since this loop will be called regularly, we can
  // assume that dt is constant and not include it in the calculations above.
  // dt is implicitly included within KP, KI, and KD.

  
  // Implement the PID algorithm
  output += KP*error + KI*I_error + KD*D_error; //incremental updates, good for motors or fans     
  
  // limit output value between 10 and 255
  output = constrain(output, 10, 255);
 
  // control motor
  analogWrite(PWM_OUT, output);
  
  Serial.print("Temp: "); Serial.print(temperatureC);
  Serial.print(" | Target: "); Serial.print(setpoint);
  Serial.print(" | PWM: "); Serial.println(output);

  delay(500);
}
