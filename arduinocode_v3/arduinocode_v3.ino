//sensor variables
int sensor0;
int sensor1;
int sensor2;
int sensor3;
int sensor4;
int sensor5;

//variable to indiciate if something is on the sensor
int state0;
int state1;
int state2;
int state3;
int state4;
int state5;

//previous state
int prev0 = 0;
int prev1 = 0;
int prev2 = 0;
int prev3 = 0;
int prev4 = 0;
int prev5 = 0;

//compare current state to previous state --> checks for new pressure on sensors
boolean triggered0 = false;
boolean triggered1 = false;
boolean triggered2 = false;
boolean triggered3 = false;
boolean triggered4 = false;
boolean triggered5 = false;

//position variables
int genre = 0;
int posA = 1;
int posB = 2;
int posC = 3;
int posD = 4;
int posE = 5;
int posF = 6;

//checks if the position has already been sent to serial
boolean armrest_trig = false;
boolean posA_trig = false;
boolean posB_trig = false;
boolean posC_trig = false;
boolean posD_trig = false;
boolean posE_trig = false;
boolean posF_trig = false;

void setup() {

  Serial.begin(9600);

}

void loop() {

  //values straight from sensors
  sensor0 = analogRead(A0);
  sensor1 = analogRead(A1);
  sensor2 = analogRead(A2);
  sensor3 = analogRead(A3);
  sensor4 = analogRead(A4);
  sensor5 = analogRead(A5);

  //print values from each sensor
  //    Serial.println("SENSOR 1:");
  //    Serial.println(sensor1);
  //
  //    Serial.println("SENSOR 2:");
  //    Serial.println(sensor2);
  //
  //    Serial.println("SENSOR 3:");
  //    Serial.println(sensor3);
  //
  //      Serial.println("SENSOR 4:");
  //      Serial.println(sensor4);
  //
  //    Serial.println("SENSOR 5:");
  //    Serial.println(sensor5);

  //  Serial.println(sensor0);

  //check the state of each sensor

  //armrest sensor
  if (sensor0 > 800) {
    state0 = 1;

    if (prev0 == 0) {
      triggered0 = true;
    }
  } else {
    state0 = 0;
  }

  //cushion sensors
  if (sensor1 > 600) {
    state1 = 1;

    //check if this is new (did someone just put their head back?)
    if (prev1 == 0) {
      triggered1 = true;

      //            Serial.println("Sensor 1 triggered");

    } else {
      triggered1 = false;
    }

  } else {
    state1 = 0;
  }

  if (sensor2 > 100) {
    state2 = 1;

    //check if this is new (did someone just put their lean back?)
    if (prev2 == 0) {
      triggered2 = true;

      //            Serial.println("Sensor 2 triggered");

    } else {
      triggered2 = false;
    }

  } else {
    state2 = 0;
  }

  if (sensor3 > 800) {
    state3 = 1;

    //check if this is new (did someone just sit down?)
    if (prev3 == 0) {
      triggered3 = true;

      //            Serial.println("Sensor 3 triggered");

    } else {
      triggered3 = false;
    }

  } else {
    state3 = 0;
  }

  if (sensor4 > 700) {
    state4 = 1;

    //    Serial.println(sensor4);

    //check if this is new (did someone just put their knees up?)
    if (prev4 == 0) {
      triggered4 = true;

      //            Serial.println("Sensor 4 triggered");

    } else {
      triggered4 = false;
    }

  } else {
    state4 = 0;
  }

  if (sensor5 > 550) {
    state5 = 1;

    //check if this is new (did someone just put their feet up?)
    if (prev5 == 0) {
      triggered5 = true;

      //            Serial.println("Sensor 5 triggered");

    } else {
      triggered5 = false;
    }

  } else {
    state5 = 0;
  }

  //update sensor states
  prev0 = state0;
  prev1 = state1;
  prev2 = state2;
  prev3 = state3;
  prev4 = state4;
  prev5 = state5;

  //send genre trigger
//  if (triggered0) {
//    Serial.println(genre);
//
//    armrest_trig = true;
//  }

  //define positions

  //position A
    if (triggered4) {                                                     //just sat down
      if (state1 == 0 && state2 == 0 && state3 == 0 && state5 == 0) {     //no other sensors are being touched
        if (!posA_trig) {                                                 //this position hasn't already been sent
          Serial.println(posA);
          //        Serial.println("posA");
  
          //set trigger to true so it doesn't trigger again
          posA_trig = true;
  
          //set all other triggers to false so they can be triggered
          posB_trig = false;
          posC_trig = false;
          posD_trig = false;
          posE_trig = false;
          posF_trig = false;
          armrest_trig = false;
        }
      }
    }

  //position B
  if (state3 == 1 && state4 == 1) {
    if (triggered4) {                                                   //just sat down
      if (state1 == 0 && state2 == 0 && state5 == 0) {                  //no other sensors are being touched
        if (!posB_trig) {                                               //this position hasn't already been sent
          Serial.println(posB);
          //          Serial.println("posB");

          //set trigger to true so it doesn't trigger again
          posB_trig = true;

          //set all other triggers to false so they can be triggered
          posA_trig = false;
          posC_trig = false;
          posD_trig = false;
          posE_trig = false;
          posF_trig = false;
          armrest_trig = false;
        }
      }
    }
  }

  if (state3 == 1 && state4 == 1) {
    if (triggered3) {                                                   //just sat down
      if (state1 == 0 && state2 == 0 && state5 == 0) {                  //no other sensors are being touched
        if (!posB_trig) {                                               //this position hasn't already been sent
          Serial.println(posB);
          //          Serial.println("posB");

          //set trigger to true so it doesn't trigger again
          posB_trig = true;

          //set all other triggers to false so they can be triggered
          posA_trig = false;
          posC_trig = false;
          posD_trig = false;
          posE_trig = false;
          posF_trig = false;
          armrest_trig = false;
        }
      }
    }
  }

  //position C
  if (state2 == 1 & state3 == 1 && state4 == 1) {
    if (triggered4) {
      if (state1 == 0 && state5 == 0) {
        if (!posC_trig) {
          Serial.println(posC);
          //          Serial.println("posC");

          //set trigger to true so it doesn't trigger again
          posC_trig = true;

          //set all other triggers to false so they can be triggered
          posA_trig = false;
          posB_trig = false;
          posD_trig = false;
          posE_trig = false;
          posF_trig = false;
          armrest_trig = false;
        }
      }
    }
  }

  if (state2 == 1 & state3 == 1 && state4 == 1) {
    if (triggered2) {
      if (state1 == 0 && state5 == 0) {
        if (!posC_trig) {
          Serial.println(posC);
          //          Serial.println("posC");

          //set trigger to true so it doesn't trigger again
          posC_trig = true;

          //set all other triggers to false so they can be triggered
          posA_trig = false;
          posB_trig = false;
          posD_trig = false;
          posE_trig = false;
          posF_trig = false;
          armrest_trig = false;
        }
      }
    }
  }

  //position D
  if (state1 == 1 && state2 == 1 && state3 == 1 && state4 == 1) {
    if (triggered1) {
      if (state5 == 0) {
        if (!posD_trig) {
          Serial.println(posD);
          //          Serial.println("posD");

          //set trigger to true so it doesn't trigger again
          posD_trig = true;

          //set all other triggers to false so they can be triggered
          posA_trig = false;
          posB_trig = false;
          posC_trig = false;
          posE_trig = false;
          posF_trig = false;
          armrest_trig = false;
        }
      }
    }
  }

  if (state1 == 1 && state2 == 1 && state3 == 1 && state4 == 1) {
    if (triggered4) {
      if (state5 == 0) {
        if (!posD_trig) {
          Serial.println(posD);
          //          Serial.println("posD");

          //set trigger to true so it doesn't trigger again
          posD_trig = true;

          //set all other triggers to false so they can be triggered
          posA_trig = false;
          posB_trig = false;
          posC_trig = false;
          posE_trig = false;
          posF_trig = false;
          armrest_trig = false;
        }
      }
    }
  }

  //position E
  if (state2 == 1 & state3 == 1 && state4 == 1 && state5 == 1) {
    if (triggered5) {
      if (state1 == 0) {
        if (!posE_trig) {
          Serial.println(posE);
          //          Serial.println("posE");

          //set trigger to true so it doesn't trigger again
          posE_trig = true;

          //set all other triggers to false so they can be triggered
          posA_trig = false;
          posB_trig = false;
          posC_trig = false;
          posD_trig = false;
          posF_trig = false;
          armrest_trig = false;
        }
      }
    }
  }

  if (state2 == 1 & state3 == 1 && state4 == 1 && state5 == 1) {
    if (triggered4) {
      if (state1 == 0) {
        if (!posE_trig) {
          Serial.println(posE);
          //          Serial.println("posE");

          //set trigger to true so it doesn't trigger again
          posE_trig = true;

          //set all other triggers to false so they can be triggered
          posA_trig = false;
          posB_trig = false;
          posC_trig = false;
          posD_trig = false;
          posF_trig = false;
          armrest_trig = false;
        }
      }
    }
  }

  if (state2 == 1 & state3 == 1 && state4 == 1 && state5 == 1) {
    if (triggered2) {
      if (state1 == 0) {
        if (!posE_trig) {
          Serial.println(posE);
          //          Serial.println("posE");

          //set trigger to true so it doesn't trigger again
          posE_trig = true;

          //set all other triggers to false so they can be triggered
          posA_trig = false;
          posB_trig = false;
          posC_trig = false;
          posD_trig = false;
          posF_trig = false;
          armrest_trig = false;
        }
      }
    }
  }

  //position F
  if (state1 == 1 && state2 == 1 && state3 == 1 && state4 == 1 && state5 == 1) {
    if (triggered1) {
      if (!posF_trig) {
        Serial.println(posF);
        //        Serial.println("posF");

        //set trigger to true so it doesn't trigger again
        posF_trig = true;

        //set all other triggers to false so they can be triggered
        posA_trig = false;
        posB_trig = false;
        posC_trig = false;
        posD_trig = false;
        posE_trig = false;
        armrest_trig = false;
      }
    }
  }

  if (state1 == 1 && state2 == 1 && state3 == 1 && state4 == 1 && state5 == 1) {
    if (triggered4) {
      if (!posF_trig) {
        Serial.println(posF);
        //        Serial.println("posF");

        //set trigger to true so it doesn't trigger again
        posF_trig = true;

        //set all other triggers to false so they can be triggered
        posA_trig = false;
        posB_trig = false;
        posC_trig = false;
        posD_trig = false;
        posE_trig = false;
        armrest_trig = false;
      }
    }
  }

  if (state1 == 1 && state2 == 1 && state3 == 1 && state4 == 1 && state5 == 1) {
    if (triggered5) {
      if (!posF_trig) {
        Serial.println(posF);
        //        Serial.println("posF");

        //set trigger to true so it doesn't trigger again
        posF_trig = true;

        //set all other triggers to false so they can be triggered
        posA_trig = false;
        posB_trig = false;
        posC_trig = false;
        posD_trig = false;
        posE_trig = false;
        armrest_trig = false;
      }
    }
  }

  //the bigger the delay, the fewer values printed in monitor per second
  delay(500);

}
