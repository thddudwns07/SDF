// 모터 드라이버 핀 설정
const int motor1Pin1 = 2; // 왼쪽 앞 모터
const int motor1Pin2 = 3;
const int motor2Pin1 = 4; // 왼쪽 뒤 모터
const int motor2Pin2 = 5;
const int motor3Pin1 = 6; // 오른쪽 앞 모터
const int motor3Pin2 = 7;
const int motor4Pin1 = 8; // 오른쪽 뒤 모터
const int motor4Pin2 = 9;

// 청소 모터 핀 설정
const int cleanerMotorPin = 10;

// 초음파 센서 핀 설정
const int trigPin = 11;
const int echoPin = 12;

void setup() {
  // 모터 핀을 출력으로 설정
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(motor3Pin1, OUTPUT);
  pinMode(motor3Pin2, OUTPUT);
  pinMode(motor4Pin1, OUTPUT);
  pinMode(motor4Pin2, OUTPUT);
  
  // 청소 모터 핀을 출력으로 설정
  pinMode(cleanerMotorPin, OUTPUT);
  
  // 초음파 센서 핀을 설정
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // 청소 모터를 켬
  digitalWrite(cleanerMotorPin, HIGH);
}

void loop() {
  // 초음파 센서로 거리 측정
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  if (distance < 20) {
    // 장애물이 가까우면 후진
    moveBackward();
    delay(500);
    turnRight();
    delay(500);
  } else {
    // 장애물이 없으면 전진
    moveForward();
  }
}

// 전진 함수
void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor3Pin1, HIGH);
  digitalWrite(motor3Pin2, LOW);
  digitalWrite(motor4Pin1, HIGH);
  digitalWrite(motor4Pin2, LOW);
}

// 후진 함수
void moveBackward() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  digitalWrite(motor3Pin1, LOW);
  digitalWrite(motor3Pin2, HIGH);
  digitalWrite(motor4Pin1, LOW);
  digitalWrite(motor4Pin2, HIGH);
}