// Basic PID Motor Speed Control using Encoder

volatile long encoderCount = 0;

const int encoderPin = 2;

// Motor pins
const int IN1 = 8;
const int IN2 = 9;
const int ENA = 10;

// PID variables
float Kp = 1.5;
float Ki = 0.1;
float Kd = 0.05;

float targetSpeed = 100;   // desired encoder pulses per interval
float currentSpeed = 0;

float error, prevError = 0;
float integral = 0;
float derivative;
float outputPWM;

unsigned long lastTime = 0;

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
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - lastTime >= 100) {   // 100 ms interval
    noInterrupts();
    long pulses = encoderCount;
    encoderCount = 0;
    interrupts();

    currentSpeed = pulses;

    // PID calculations
    error = targetSpeed - currentSpeed;
    integral += error;
    derivative = error - prevError;

    outputPWM = (Kp * error) + (Ki * integral) + (Kd * derivative);
    outputPWM = constrain(outputPWM, 0, 255);

    analogWrite(ENA, outputPWM);

    prevError = error;
    lastTime = currentTime;

    Serial.print("Speed: ");
    Serial.print(currentSpeed);
    Serial.print(" PWM: ");
    Serial.println(outputPWM);
  }
}
