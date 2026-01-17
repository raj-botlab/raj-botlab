int rpm1  = 6;
int forw1 = 2;
int back1 = 3;

int rpm2  = 10;
int forw2 = 4;
int back2 = 5;

// ===== Button pins =====
int leftBtn   = 8;
int rightBtn  = 9;
int fwdBtn    = 11;
int backBtn   = 12;

int speedUpBtn   = A0;   // gear up
int speedDownBtn = A1;   // gear down

// ===== Speed variable (GEAR SYSTEM) =====
int baseSpeed = 120;

// ===== Motor functions =====
void stopMotors() {
  analogWrite(rpm1, 0);
  analogWrite(rpm2, 0);

  digitalWrite(forw1, LOW);
  digitalWrite(back1, LOW);
  digitalWrite(forw2, LOW);
  digitalWrite(back2, LOW);
}

void forward(int spd) {
  digitalWrite(forw1, HIGH);
  digitalWrite(back1, LOW);
  digitalWrite(forw2, HIGH);
  digitalWrite(back2, LOW);

  analogWrite(rpm1, spd);
  analogWrite(rpm2, spd);
}

void backward(int spd) {
  digitalWrite(forw1, LOW);
  digitalWrite(back1, HIGH);
  digitalWrite(forw2, LOW);
  digitalWrite(back2, HIGH);

  analogWrite(rpm1, spd);
  analogWrite(rpm2, spd);
}

void turnLeft(int spd) {
  digitalWrite(forw1, HIGH);
  digitalWrite(back1, LOW);
  digitalWrite(forw2, HIGH);
  digitalWrite(back2, LOW);

  analogWrite(rpm1, spd - 60);  // left slow
  analogWrite(rpm2, spd);       // right fast
}

void turnRight(int spd) {
  digitalWrite(forw1, HIGH);
  digitalWrite(back1, LOW);
  digitalWrite(forw2, HIGH);
  digitalWrite(back2, LOW);

  analogWrite(rpm1, spd);        // left fast
  analogWrite(rpm2, spd - 60);   // right slow
}

// ===== Setup =====
void setup() {
  pinMode(rpm1, OUTPUT);
  pinMode(forw1, OUTPUT);
  pinMode(back1, OUTPUT);

  pinMode(rpm2, OUTPUT);
  pinMode(forw2, OUTPUT);
  pinMode(back2, OUTPUT);

  pinMode(leftBtn, INPUT_PULLUP);
  pinMode(rightBtn, INPUT_PULLUP);
  pinMode(fwdBtn, INPUT_PULLUP);
  pinMode(backBtn, INPUT_PULLUP);

  pinMode(speedUpBtn, INPUT_PULLUP);
  pinMode(speedDownBtn, INPUT_PULLUP);
}

// ===== Loop =====
void loop() {

  // ----- Gear control -----
  if (digitalRead(speedUpBtn) == LOW) {
    baseSpeed += 20;
    if (baseSpeed > 255) baseSpeed = 255;
    delay(200);
  }

  if (digitalRead(speedDownBtn) == LOW) {
    baseSpeed -= 20;
    if (baseSpeed < 60) baseSpeed = 60;
    delay(200);
  }

  // ----- Movement control -----
  if (digitalRead(leftBtn) == LOW) {
    turnLeft(baseSpeed);
  }
  else if (digitalRead(rightBtn) == LOW) {
    turnRight(baseSpeed);
  }
  else if (digitalRead(fwdBtn) == LOW) {
    forward(baseSpeed);
  }
  else if (digitalRead(backBtn) == LOW) {
    backward(baseSpeed);
  }
  else {
    stopMotors();
  }
}
