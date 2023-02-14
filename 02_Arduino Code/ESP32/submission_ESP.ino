#include <Arduino.h>
#include <Servo.h>
#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>

//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

// Insert your network credentials
#define WIFI_SSID "your wifi ssid"// input the wifi ssid here
#define WIFI_PASSWORD "your wifi password"// input the wifi password here

// Insert Firebase project API Key
#define API_KEY "your firebase api key"// copy the api key from firebase and paste it here

#define USER_EMAIL "firebase account email"// input an authenticated account here
#define USER_PASSWORD "firebase account password"// input the authenticated account password here

// Insert RTDB URL define the RTDB URL */
#define DATABASE_URL "your database URL" // copy your database url here

//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

/*database access variables*/
unsigned long sendDataPrevMillis = 0;
int intValue;
float floatValue;
bool signupOK = false;

/*initialise servo*/
Servo myservo;

/*pins used for ultrasonic sensor*/
const int trigPin = 5;
const int echoPin = 18;

/*settings and variables for ultra sound*/
#define SOUND_SPEED 0.034
long duration;
float distanceCm;

/*otp variables*/
char OTP[7] = "testss";
int otp = 0;

void setup() {
  Serial.begin(115200);
  randomSeed(analogRead(A0));
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);//connect to wifi
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  myservo.attach(4);//attaching servo motor to a pin
  Serial.println("setup done");  
  
  /* Assign the api key (required) */
  config.api_key = API_KEY;

/*firebase authentication with email and password*/
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  
  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;
  
  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")) {
    Serial.println("ok");
    signupOK = true;
  }
  else {
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_SPEED/2;
Serial.println(distanceCm);
/*detecting an object*/
  if (distanceCm < 5){//if obect is less than 5 cm away open door for 15 seconds
    myservo.write(90);
    delay(15000);
    myservo.write(0);//close door
    delay(1000);
    }
    /*check if firebase is ready*/
  if (Firebase.ready() && (millis() - sendDataPrevMillis > 1000 || sendDataPrevMillis == 0)) {
    sendDataPrevMillis = millis();
    /*reading firebase for door open variable = 1*/
    if (Firebase.RTDB.getInt(&fbdo, "/door/open")) {
      if (fbdo.dataType() == "int") {
        intValue = fbdo.intData();
        if(intValue == 1){//IF variable door open is 1 open door
          myservo.write(90);//open lock
          delay(15000);
           if (Firebase.RTDB.setInt(&fbdo, "door/open", 0)) {//set door open to 0
            Serial.println("PASSED");
            Serial.println("PATH: " + fbdo.dataPath());
            Serial.println("TYPE: " + fbdo.dataType());
            Serial.println(intValue);
          }
          delay(1000);
          updateOTP();//reset otp
          if (Firebase.RTDB.setInt(&fbdo, "otp/num", otp)) {
            Serial.println("PASSED");
            Serial.println("PATH: " + fbdo.dataPath());
            Serial.println("TYPE: " + fbdo.dataType());
            Serial.println(intValue);
          }
          myservo.write(0);//close lock
          delay(1000);
        }
        if (fbdo.dataType() == "int") {
        intValue = fbdo.intData();
        if(intValue == 0){//door to remain lock by default
          myservo.write(0);
          delay(1000);
        }
        }
    }
    else {
      Serial.println(fbdo.errorReason());
    }
  }
  if (Firebase.RTDB.getInt(&fbdo, "/otp/cfm")){//check if otp request was sent
    if (fbdo.dataType() == "int") {
        intValue = fbdo.intData();
        if(intValue == 1){
          delay(1000);
          updateOTP();//if true generate otp
          Serial.println(otp);
          if (Firebase.RTDB.setInt(&fbdo, "otp/num", otp)) {//set otp in database
            Serial.println("PASSED");
            Serial.println("PATH: " + fbdo.dataPath());
            Serial.println("TYPE: " + fbdo.dataType());
            Serial.println(intValue);
          }
          delay(1000);
          if (Firebase.RTDB.setInt(&fbdo, "otp/cfm", 0)) {//reset otp request
            Serial.println("PASSED");
            Serial.println("PATH: " + fbdo.dataPath());
            Serial.println("TYPE: " + fbdo.dataType());
            Serial.println(intValue);
          }
          if (Firebase.RTDB.setInt(&fbdo, "send", 1)) {//send the otp via telegram
            Serial.println("PASSED");
            Serial.println("PATH: " + fbdo.dataPath());
            Serial.println("TYPE: " + fbdo.dataType());
            Serial.println(intValue);
          }
        }
  }
}
}
}

void updateOTP()//otp generator function
{
  char newString [7];
  for (int i = 0; i < sizeof(newString); i++)
  {
    if (i == sizeof(newString) - 1)
    {
      newString[i] = '\0';
    }
    else
    {
      newString[i] = random('0',':');
    }
  }
  strcpy(OTP, newString);
  String stringotp(OTP);
  otp = stringotp.toInt();
  
}
