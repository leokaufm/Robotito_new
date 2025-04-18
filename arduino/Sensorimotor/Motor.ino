// #define REEL_WAIT_TIME 300
// #define REEL_RETRACT_TIME 500

// bool retracting = false;

// void setReelsSpeed(long speed) {
//   botState.reelSpeed = speed;
// }

// void reelsMotors() {
//   static unsigned long lastReelStart = millis();
//   static unsigned long lastReelEnd = millis();

//   static long lastRightPulses = 0;
//   static long lastLeftPulses = 0;
//   unsigned long currMillis = millis();
  
//   if (!retracting) {
//     // wheels are moving
//     if (botState.rightSpeed > 0 || botState.leftSpeed > 0) {
//       retracting = true;
//       lastReelStart = currMillis;
//     }
//     // wheels are not moving forward but wait time is over
//     else if (currMillis - lastReelEnd > REEL_WAIT_TIME) {
//       retracting = true;  
//       lastReelStart = currMillis;
//     }
//   } else {
//     // Reels are moving, so we take as if they just started retracting
//     if (lastLeftPulses != sensor.leftReelEncoder || lastRightPulses != sensor.rightReelEncoder) {
//       lastReelStart = currMillis;
//     }
    
//     // Both wheels not going forward and retract time is over
//     if (botState.rightSpeed == 0 && botState.leftSpeed == 0 && currMillis - lastReelStart > REEL_RETRACT_TIME) {
//       retracting = false; 
//       lastReelEnd = currMillis;  
//     }
//   }

//   lastLeftPulses = sensor.leftReelEncoder;
//   lastRightPulses = sensor.rightReelEncoder;

//   if (retracting) {
//     leftReel->setSpeed(botState.reelSpeed);
//     rightReel->setSpeed(botState.reelSpeed);
//     rightReel->run(FORWARD);
//     leftReel->run(FORWARD);
//   } else {
//     rightReel->run(RELEASE);
//     leftReel->run(RELEASE); 
//   }
// }

void moveLeft(int speed) {
  move(leftMotor, speed);
}

void moveRight(int speed) {
  move(rightMotor, speed);
}

void stopLeft() {
  move(leftMotor, 0);
}

void stopRight() {
  move(rightMotor, 0);
}

void moveHead(int speed) {
  botState.headSpeed = speed;
  if (speed == 0){
    head->run(RELEASE);
  } else {
    head->setSpeed(abs(speed));
    if (speed > 0) {
      head->run(FORWARD);
    } else {
      head->run(BACKWARD);
    }
  }
}

void stopHead() {
  moveHead(0);
}

void move(Adafruit_DCMotor * motor, int speed) {
  if (motor == rightMotor)
    botState.rightSpeed = speed;
  else
    botState.leftSpeed = speed;

  if (speed == 0) {
    motor->run(RELEASE);
  } else {
    motor->setSpeed(abs(speed));
    if (speed > 0) {
      motor->run(FORWARD);
    } else {
      motor->run(BACKWARD);
    }
  }    
}

// void stopReels() {
//   moveReels(0);
// }

// void moveReels(int speed) {
//   if (speed == 0) {
//     leftReel->run(RELEASE);
//     rightReel->run(RELEASE);
//   } else {
//     leftReel->setSpeed(speed);
//     rightReel->setSpeed(speed);
//     if (speed > 0) {
//       rightReel->run(FORWARD);
//       leftReel->run(FORWARD);    
//     } else {
//       rightReel->run(BACKWARD);
//       leftReel->run(BACKWARD);
//     }
//   }    
// }
