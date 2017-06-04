/*
    Veggie Vertical Farm Cybernetics Project (V2FP)

    Control a vertical vegetable farm with up to 8 columns.

    The peripherals:

    * 1x Arduino Duemilanove
    * 2x 74HC4051 8-Channel-Mux Analog Multiplexer Demultiplexer
    * up to 8 humidity sensors
    * up to 8 valves (12V) switched using a relais each.
    * up to 8 LED to indicate a valve is open.
    * 1 submerged pump (12V) switched using a relais.
    * 1 float switch
    * 1 buzzer

    Created 2017-01-12
    By Jens W. Klein <jk@kleinundpartner.at>
    Modified day month year
    By author's name

    License: under GPLv2

*/

static int HUMIDITY_BOUNDARY = 500;
static int PUMP_TIME = 5000;

static int VALVES[3] = {9, 10, 11};
static int SENSORS[3] = {6, 7, 8};

int pumpPin = 12;      // select the pin for the pump

int sensorPin = A0;    // select the input pin for the humidity
int sensorValue = 0;   // variable to store the value coming from the sensor

void setup() {
  Serial.begin(9600);
  for (ixd=0; idx<=3; count++) {
    pinMode(VALES[idx], OUTPUT);
  }
  pinMode(pumpPin, OUTPUT);
}

void switchMultiplexer(int *multiplexer, int port) {
  
}

void pump(int column) {
    digitalWrite(pumpPin, HIGH);
    delay(PUMP_TIME);
    digitalWrite(pumpPin, LOW);
}

int readSensor(int column) {
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  return sensorValue;
}

void loop() {
  // loop over all sensors with idx:
    // check if enough water, if not:
        // go into waiting for water loop with buzzer alarm
    // check sensor of idx:
        // power on sensor
        // wait some ms
        // read sensor
    // check if a value at all comes in (like >10) (connected!)
    // AND check if value is < HUMIDITY_BOUNDARY:
        // pump!
  // wait for 10 minutes

  // TODO
  // if (readSensor(0) > HUMIDITY_BOUNDARY) {
  //   pump(0);
  //   delay(2000);
  // }
  delay(200);
}
