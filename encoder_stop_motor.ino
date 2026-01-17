// Encoder + Motor Stop at Target Distance
volatile long encoderCount = 0;

const int encoderPin = 2;

// Motor pins
const int IN1 = 8;
const int IN2 = 9;
const int ENA = 10;

const long targetPulses = 200;   // distance target

void encoderISR() {
  encoderCount++;
}

void setup() {
  pinMode(encoderPin, INPUT_PULLUP);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(encoderPin), encoderISR, RISING);

  // Motor forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 150);   // motor speed
}

void loop() {
  Serial.print("Encoder Count: ");
  Serial.println(encoderCount);

  if (encoderCount >= targetPulses) {
    // Stop motor
    analogWrite(ENA, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);

    Serial.println("Target reached. Motor stopped.");

    while (1); // stop loop permanently
  }

  delay(100);
}
