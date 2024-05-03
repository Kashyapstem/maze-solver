#define motor1Pin1 2 // Motor 1 input pin 1
#define motor1Pin2 3 // Motor 1 input pin 2
#define motor2Pin1 4 // Motor 2 input pin 1
#define motor2Pin2 5 // Motor 2 input pin 2


// Define ultrasonic sensor pins
#define trigPin 6
#define echoPin 7


// Define variables
long duration;
int distance;


void setup() {
  // Initialize motor pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);


  // Initialize ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


  // Initialize serial communication
  Serial.begin(9600);
}
void loop() {
  // Move forward
  moveForward();
 
  // Check for obstacles
  checkObstacle();
}
void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}


void turnRight() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  delay(1000); // Adjust delay according to your robot's turning speed
}
void checkObstacle() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read ultrasonic echo
  duration = pulseIn(echoPin, HIGH);
 
  // Calculate distance
  distance = duration * 0.034 / 2;
 
  // Print distance to serial monitor
  Serial.print("Distance: ");
  Serial.println(distance);
 
  // If obstacle detected, turn right
  if (distance < 20) {
    turnRight();
  }
}
