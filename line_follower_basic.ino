// Basic Line Follower Robot (2 IR Sensors)

const int leftSensor = A0;
const int rightSensor = A1;

// Motor pins
const int L_IN1 = 8;
const int L_IN2 = 9;
const int R_IN3 = 10;
const int R_IN4 = 11;

const int ENA = 5;
const int ENB = 6;

void setup() {
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);

  pinMode(L_IN1, OUTPUT);
  pinMode(L_IN2, OUTPUT);
  pinMode(R_IN3, OUTPUT);
  pinMode(R_IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void loop() {
  int leftValue = digitalRead(leftSensor);
  int rightValue = digitalRead(rightSensor);

  // BLACK line = LOW, WHITE surface = HIGH (common case)

  if (leftValue == LOW && rightValue == LOW) {
    // Move forward
    digitalWrite(L_IN1, HIGH);
    digitalWrite(L_IN2, LOW);
    digitalWrite(R_IN3, HIGH);
    digitalWrite(R_IN4, LOW);
  }
  else if (leftValue == LOW && rightValue == HIGH) {
    // Turn left
    digitalWrite(L_IN1, LOW);
    digitalWrite(L_IN2, LOW);
    digitalWrite(R_IN3, HIGH);
    digitalWrite(R_IN4, LOW);
  }
  else if (leftValue == HIGH && rightValue == LOW) {
    // Turn right
    digitalWrite(L_IN1, HIGH);
    digitalWrite(L_IN2, LOW);
    digitalWrite(R_IN3, LOW);
    digitalWrite(R_IN4, LOW);
  }
  else {
    // Stop (line lost)
    digitalWrite(L_IN1, LOW);
    digitalWrite(L_IN2, LOW);
    digitalWrite(R_IN3, LOW);
    digitalWrite(R_IN4, LOW);
  }
}
