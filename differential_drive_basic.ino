// Differential Drive Robot - Basic Control

// Left motor pins
const int L_IN1 = 8;
const int L_IN2 = 9;

// Right motor pins
const int R_IN3 = 10;
const int R_IN4 = 11;

// Enable pins (PWM)
const int ENA = 5;
const int ENB = 6;

void setup() {
  pinMode(L_IN1, OUTPUT);
  pinMode(L_IN2, OUTPUT);
  pinMode(R_IN3, OUTPUT);
  pinMode(R_IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Set base speed
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void loop() {
  // Move Forward
  forward();
  delay(2000);

  // Turn Left
  turnLeft();
  delay(1000);

  // Turn Right
  turnRight();
  delay(1000);

  // Rotate in place
  rotate();
  delay(1000);

  // Stop
  stopMotors();
  delay(2000);
}

// -------- Movement Functions --------

void forward() {
  digitalWrite(L_IN1, HIGH);
  digitalWrite(L_IN2, LOW);
  digitalWrite(R_IN3, HIGH);
  digitalWrite(R_IN4, LOW);
}

void turnLeft() {
  digitalWrite(L_IN1, LOW);
  digitalWrite(L_IN2, LOW);
  digitalWrite(R_IN3, HIGH);
  digitalWrite(R_IN4, LOW);
}

void turnRight() {
  digitalWrite(L_IN1, HIGH);
  digitalWrite(L_IN2, LOW);
  digitalWrite(R_IN3, LOW);
  digitalWrite(R_IN4, LOW);
}

void rotate() {
  digitalWrite(L_IN1, LOW);
  digitalWrite(L_IN2, HIGH);
  digitalWrite(R_IN3, HIGH);
  digitalWrite(R_IN4, LOW);
}

void stopMotors() {
  digitalWrite(L_IN1, LOW);
  digitalWrite(L_IN2, LOW);
  digitalWrite(R_IN3, LOW);
  digitalWrite(R_IN4, LOW);
}

