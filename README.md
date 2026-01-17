# EC&P Robotics Fundamentals – Robocon Preparation

This repository contains basic but important programs related to
electronics, control, and programming used in mobile robotics.


The focus of this repository is on understanding logic, feedback,
and motor control rather than complex frameworks.

---

## Technologies Used
- Arduino Uno
- C / Embedded C
- DC Motors
- Encoders
- IR Sensors
- Motor Drivers (L298N / L293D)

---

## Programs Included

### 1. Sensor-based decision logic (C)
- Uses if-else conditions
- Simulates obstacle detection logic
- Demonstrates basic decision-making used in robots

---

### 2. Encoder pulse counting (Arduino Uno)
- Counts encoder pulses using hardware interrupt
- Uses `attachInterrupt()` for accurate pulse detection
- Demonstrates feedback sensing

File: `encoder_basic.ino`

---

### 3. Motor stop using encoder feedback
- Encoder pulses are counted continuously
- Motor runs until target pulse count is reached
- Demonstrates distance-based closed-loop control

File: `encoder_motor_stop.ino`

---

### 4. PID motor speed control using encoder
- Encoder feedback used to measure motor speed
- PID controller adjusts PWM output
- Demonstrates closed-loop speed control

File: `pid_motor_control.ino`

---

### 5. Line follower robot (2 IR sensors)
- Uses two IR sensors for line detection
- Rule-based control logic
- Demonstrates sensor-based motion control

File: `line_follower_basic.ino`

---

### 6. Differential drive robot control
- Independent control of left and right motors
- Implements forward, turning, and rotation
- Core motion model used in mobile robots

File: `differential_drive_basic.ino`

---

## Key Concepts Demonstrated
- Interrupts
- Encoder feedback
- PWM motor control
- PID control
- Line following logic
- Differential drive motion

---

## Notes
- Programs are written for learning and understanding purposes
- Hardware testing can be done during lab sessions
- Code is kept simple and readable for beginners

---

## Author
Raj  


