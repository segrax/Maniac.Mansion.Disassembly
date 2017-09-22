/**
 * Maniac Mansion: Retail
 *
 * Scripts
 */

/**
 * Script 1: Intro: Kid Selection
 */
Script-1 {
    [0000] cutscene();                                                          // Start Cutscene
    [0001] cursorCommand( kModeKeypad )                                         // Keypad Mode
    [0003] loadSound(1);
    [0005] lockSound(1);
    [0007] loadSound(58);
    [0009] lockSound(58);
    [000B] Var[97] = 3;                                                         // Kid1 is Dave
    [000E] loadRoom(45);
    [0010] Var[91] = 0;                                                         // Clear 'Start' status

    [0013] delay(60);                                                           // Sleep 1 second
    [0017] print(255,"=1987 Lucasfilm Ltd. All rights reserved");               // 29 Year old copyright notice
    [003D] beginOverride();
    {
        [0041] Var[48] = getRandomNr(1);
        [0044] if (VAR_HAVE_MSG == 0) {                                             // if No Text
        [0049]   delay(120);                                                        //  Sleep 2 seconds

        [004D]   if (VAR_HAVE_MSG == 0) {                                           //  Still no text?
        [0052]     if (Var[92] == 1) {                                              //   if One Kid Selected
        [0057]       print(255,"      Please select two other kids.");
        [0076]     }
        [0076]     if (Var[92] == 2) {                                              //   if Two Kids Selected
        [007B]       print(255,"      Please select one other kid.");
        [0099]     }
        [0099]   }
        [0099] }
        [0099] breakHere();                                                     // Engine Tick
        [009A] unless (Var[91] == 1) goto 0041;                                 // Loop until start pressed

        [009F] if (Var[92] < 3) {                                               // Number of Selected Kids < 3?
        [00A4]   doSentence(9,395,0);                                           //  Yes, Press the start button (display message)
        [00A8]   goto 0013;                                                     //  Back to Start
        [00AB] }
    }
    [00AB] endcutscene();                                                       // End Cutscene
    [00AC] loadRoom(0);
    [00AE] cursorCommand( kModeCutscene )                                       // Cutscene Mode

    [00B0] if (Var[91] == 1) {                                                  // Start Pushed?
    [00B5]   startScript(115);                                                  //  Cutscene: Intro: Comet / Mansion
    [00B7]   breakHere();                                                       // Engine Tick
    [00B8]   VAR_RESULT = isScriptRunning(115);
    [00BB]   unless (VAR_RESULT == 0) goto 00B7;                                //  Sleep until Intro Cutscene finishes
    [00C0] }

    [00C0] unlockSound(1);
    [00C2] unlockSound(58);

    [00C4] putActorInRoom(Var[97],44);                                          // Put Dave outside Mansion fence
    [00C7] putActor(Var[97],24,59);

    [00CB] putActorInRoom(Var[98],44);                                          // Put Kid2 outside Mansion fence
    [00CE] putActor(Var[98],29,57);

    [00D2] putActorInRoom(Var[99],44);                                          // Put Kid3 outside Mansion fence
    [00D5] putActor(Var[99],34,61);

    [00D9] putActorInRoom(12,24);                                               // Put Dead Cousin Ted in Gym Bathroom
    [00DC] putActor(12,30,48);

    [00E0] putActorInRoom(11,26);                                               // Put Weird Ed in Weird Ed's room
    [00E3] putActor(11,10,52);
    [00E7] Var[20] = 1;                                                         // Telescope: Current Room = 34

    [00EA] setBitVar(44,2,1);                                                   // Welcome to Mansion: Light Always On
    [00EE] setBitVar(1,2,1);                                                    // Front of Mansion: Light Always On
    [00F2] setBitVar(4,2,1);                                                    // Dungeon: Light Always On
    [00F6] setBitVar(6,2,1);                                                    // Pool Area: Light Always On
    [00FA] setBitVar(2,2,1);                                                    // Bottom of Pool: Light Always On
    [00FE] setBitVar(16,2,1);                                                   // Garage: Light Always On
    [0102] setBitVar(30,2,1);                                                   // Lab: Zom-b-Matic: Light Always On
    [0106] setBitVar(31,2,1);                                                   // Lab: Entry: Light Always On
    [010A] setBitVar(51,2,1);                                                   // Lab: Meteor:  Light Always On

    [010E] setBitVar(8,1,1);                                                    // Basement: Light off
    [0112] setBitVar(5,1,1);                                                    // Library: Light off
    [0116] setBitVar(9,1,1);                                                    // Attic (Above Nurse Edna's Room): Light Off
    [011A] setBitVar(15,1,1);                                                   // Electrical Wiring: Light Off
    [011E] setBitVar(22,1,1);                                                   // Medical: Light off
    [0122] setBitVar(23,1,1);                                                   // DarkRoom: Light off

    [0126] Var[92] = getRandomNr(4);                                            // Randomise Edna's Phone Number
    [0129] if (Var[92] == 0) {
    [012E]   Var[32] = 5;                                                       //  Phone Number: 5235
    [0131]   Var[33] = 2;
    [0134]   Var[34] = 3;
    [0137]   Var[35] = 5;
    [013A] }
    [013A] if (Var[92] == 1) {
    [013F]   Var[32] = 1;                                                       //  Phone Number: 1547
    [0142]   Var[33] = 5;
    [0145]   Var[34] = 4;
    [0148]   Var[35] = 7;
    [014B]   setState08(86);                                                    //  Show Pin on wall behind Ted
    [014D] }
    [014D] if (Var[92] == 2) {
    [0152]   Var[32] = 2;                                                       //  Phone Number: 2275
    [0155]   Var[33] = 2;
    [0158]   Var[34] = 7;
    [015B]   Var[35] = 5;
    [015E]   setState08(87);                                                    //  Show Pin on wall behind Ted
    [0160] }
    [0160] if (Var[92] == 3) {
    [0165]   Var[32] = 3;                                                       //  Phone Number: 3444
    [0168]   Var[33] = 4;
    [016B]   Var[34] = 4;
    [016E]   Var[35] = 4;
    [0171]   setState08(88);                                                    //  Show Pin on wall behind Ted
    [0173] }
    [0173] if (Var[92] == 4) {
    [0178]   Var[32] = 7;                                                       //  Phone Number: 7537
    [017B]   Var[33] = 5;
    [017E]   Var[34] = 3;
    [0181]   Var[35] = 7;
    [0184]   setState08(89);                                                    //  Show Pin on wall behind Ted
    [0186] }

    [0186] Var[92] = getRandomNr(4);                                            // Randomise Ednas Attic Safe
    [0189] if (Var[92] == 0) {
    [018E]   Var[36] = 3;                                                       // Ednas Attic Safe: 3621
    [0191]   Var[37] = 6;
    [0194]   Var[38] = 2;
    [0197]   Var[39] = 1;
    [019A] }
    [019A] if (Var[92] == 1) {
    [019F]   Var[36] = 0;                                                       // Ednas Attic Safe: 0120
    [01A2]   Var[37] = 1;
    [01A5]   Var[38] = 2;
    [01A8]   Var[39] = 0;
    [01AB]   setState08(140);                                                   //  Show Pin on safe wall
    [01AD] }
    [01AD] if (Var[92] == 2) {
    [01B2]   Var[36] = 1;                                                       // Ednas Attic Safe: 1230
    [01B5]   Var[37] = 2;
    [01B8]   Var[38] = 3;
    [01BB]   Var[39] = 0;
    [01BE]   setState08(141);                                                   //  Show Pin on safe wall
    [01C0] }
    [01C0] if (Var[92] == 3) {
    [01C5]   Var[36] = 1;                                                       // Ednas Attic Safe: 1029
    [01C8]   Var[37] = 0;
    [01CB]   Var[38] = 2;
    [01CE]   Var[39] = 9;
    [01D1]   setState08(142);                                                   //  Show Pin on safe wall
    [01D3] }
    [01D3] if (Var[92] == 4) {
    [01D8]   Var[36] = 4;                                                       // Ednas Attic Safe: 4186
    [01DB]   Var[37] = 1;
    [01DE]   Var[38] = 8;
    [01E1]   Var[39] = 6;
    [01E4]   setState08(199);                                                   //  Show Pin on safe wall
    [01E6] }

    [01E6] Var[57] = getRandomNr(4);                                            // Randomise Telephone Number: Meteor Police (Active)
    [01E9] if (Var[57] == 0) {
    [01EE]   Var[58] = 3;                                                       // Meteor Police: 3412
    [01F1]   Var[59] = 4;
    [01F4]   Var[60] = 1;
    [01F7]   Var[61] = 2;
    [01FA] }
    [01FA] if (Var[57] == 1) {
    [01FF]   Var[58] = 1;                                                       // Meteor Police: 1138
    [0202]   Var[59] = 1;
    [0205]   Var[60] = 3;
    [0208]   Var[61] = 8;
    [020B] }
    [020B] if (Var[57] == 2) {
    [0210]   Var[58] = 9;                                                       // Meteor Police: 9111
    [0213]   Var[59] = 1;
    [0216]   Var[60] = 1;
    [0219]   Var[61] = 1;
    [021C] }
    [021C] if (Var[57] == 3) {
    [0221]   Var[58] = 1;                                                       // Meteor Police: 1977
    [0224]   Var[59] = 9;
    [0227]   Var[60] = 7;
    [022A]   Var[61] = 7;
    [022D] }
    [022D] if (Var[57] == 4) {
    [0232]   Var[58] = 0;                                                       // Meteor Police: 0525
    [0235]   Var[59] = 5;
    [0238]   Var[60] = 2;
    [023B]   Var[61] = 5;
    [023E] }
    [023E] startScript(126);                                                    // start Intro: Dave Welcome
    [0240] stopObjectCode();
}


 /**
  * Script 2: Game: Save/Load
  */
Script-2 {
    [0000] cutscene();                                                          // Start Cutscene
    [0001] cursorCommand( kModeKeypad )                                         // Keypad Mode
    [0003] setCameraAt(20);
    [0005] loadRoom(50);                                                        // SaveGame Room
    [0007] Var[108] = 0;                                                        // Game: Save/Load Status = Insert save-load disk

    [000A] beginOverride();
    {
        [000E] startScript(128);                                                    // start Game: Save/Load Disk Check Script
        [0010] Var[50] = 0;                                                         // SaveLoad: Button Pressed = Null
        [0013] breakHere();                                                         // Engine Tick
        [0014] unless (Var[50] != 0) goto 0013;                                     // Wait for button press

        [0019] breakHere();                                                         // Engine Tick
        [001A] VAR_RESULT = isSoundRunning(19);
        [001D] unless (VAR_RESULT == 0) goto 0019;                                  // Wait for light beep to finish

        [0022] if (Var[50] == 3) {                                                  // If 'Continue Playing' pressed
        [0027] } else {
        [002A]   if (Var[50] == 1) {
        [002F]     stopScript(128);                                                 // If 'Save Game' pressed
        [0031]     Var[90] = saveLoadGame(Var[50]);                                 // Save the game
        [0034]     if (Var[90] == 3) {
        [0039]       goto 0061;
        [003C]     }
        [003C]     startScript(128);                                                // start Game: Save/Load Disk Check Script
        [003E]   }
        [003E]   if (Var[50] == 2) {                                                // SaveLoad: Button Pressed = Load Game
        [0043]     Var[90] = saveLoadGame(Var[50]);                                 // Load the game
        [0046]   }
        [0046]   if (Var[90] == 0) {
        [004B]     Var[108] = 3;                                                    // Game: Save/Load Status = game was saved
        [004E]   }
        [004E]   if (Var[90] == 1) {
        [0053]     Var[108] = 1;                                                    // Game: Save/Load Status = game disk is still in drive
        [0056]   }
        [0056]   if (Var[90] == 2) {
        [005B]     Var[108] = 2;                                                    // Game: Save/Load Status = disk does not contain valid save game
        [005E]   }
        [005E]   goto 0010;
        [0061] }
        [0061] stopScript(128);
    }
    [0063] endcutscene();                                                       // End Cutscene
    [0064] stopObjectCode();
}


 /**
  * Script 3: Verb: Defaults
  */
Script-3 {
    [0000] if (VAR_ACTIVE_VERB == 1) {                                          // If Open Pressed
    [0005]   printEgo("It doesn't seem to open.");

    [001B] } else if (VAR_ACTIVE_VERB == 9) {                                   // If Push
    [0023]   goto 002E;

    [0026] } else if (VAR_ACTIVE_VERB == 10) {                                  //  or If Pull
    [002E]   printEgo("I can't move it.");

    [003D] } else if (VAR_ACTIVE_VERB == 12) {                                  // If Read
    [0045]   startScript(50);                                                   //  start Room Lights: Check for flashlight / room light status
    [0047]   if (Var[92] == 0) {                                                //  if Light off
    [004C]     printEgo("It's too dark to read.");
    [0060]   } else {                                                           //  else light on
    [0063]     printEgo("There's nothing to read on it.");
    [007E]   }

    [007E] } else if (VAR_ACTIVE_VERB == 14) {                                  // If Pickup
    [0086]   printEgo("I can't pick that up.");
    [0099] } else {
    [009C]   printEgo("That doesn't seem to work.");
    [00B4] }
    [00B4] stopObjectCode();
}


 /**
  * Script 4: Door: Open
  */
Script-4 {
    [0000] if (!getState08(activeObject)) {                                     // if door closed
    [0003]   setState08();                                                      // open door
    [0004]   startSound(8);                                                     // door open sound
    [0006] }
    [0006] stopObjectCode();
}


 /**
  * Script 5: Door: Close
  */
Script-5 {
    [0000] if (getState08(activeObject)) {                                      // If door is open
    [0003]   clearState08();                                                    // close door
    [0004]   startSound(9);                                                     // Sound Door Closing
    [0006] }
    [0006] stopObjectCode();
}


 /**
  * Script 6: Game: Meltdown Timer
  */
Script-6 {
    [0000] if (!getState08(130)) {                                              // if inner-door is closed
    [0004]   delay(300);                                                        //  Wait 5 seconds
    [0008]   if (VAR_ROOM != 6) {                                               //  Not in Pool Area
    [000D]     if (VAR_ROOM != 1) {                                             //   Not in Front of Mansion
    [0012]       if (VAR_ROOM != 44) {                                          //    Not in Welcome to Mansion
    [0017]         if (VAR_ROOM != 2) {                                         //     Not in Bottom of Pool
    [001C]           if (VAR_ROOM != 16) {                                      //      Not in Garage
    [0021]             startSound(32);                                          //       Sound Alarm 1
    [0023]             startSound(33);                                          //       Sound Alarm 2
    [0025]           }
    [0025]         }
    [0025]       }
    [0025]     }
    [0025]   }
    [0025]   delay(300);                                                        // Wait 5 seconds
    [0029]   stopSound(33);                                                     // Stop Alarm 2
    [002B]   startScript(41);                                                   // start Cutscene: Dr. Fred: Meltdown
    [002D]   delay(7200);                                                       // Sleep 2 minutes
    [0031]   stopSound(32);                                                     // Stop Alarm 1
    [0033]   delay(180);                                                        // Sleep 3 seconds
    [0037]   startScript(57);                                                   // Cutscene: Game Over
    [0039] }
    [0039] stopObjectCode();
}


 /**
  * Script 7: Game: Meltdown Stop
  */
Script-7 {
    [0000] stopScript(6);                                                       // stop Game: Meltdown Timer
    [0002] stopScript(42);                                                      // stop Cutscene: Purple Tentacle in Basement
    [0004] stopSound(32);                                                       // stop Sound Alarm 2
    [0006] stopSound(33);                                                       // stop Sound Alarm 2
    [0008] stopObjectCode();
}


 /**
  * Script 8: Garage Door Open
  */
Script-8 {
    [0000] Var[91] = VAR_CAMERA_POS_X;
    [0003] breakHere();                                                         // Engine Tick
    [0004] unless (Var[91] == VAR_CAMERA_POS_X) goto 0000;                      // Stopped Scrolling?

    [0009] startSound(40);                                                      // Sound Garage Door Open

    [000B] clearState08(111);                                                   //
    [000D] setState02(111);                                                     // Garage Door
    [000F] breakHere();                                                         // Engine Tick

    [0010] clearState08(112);
    [0012] setState02(112);                                                     // Garage Door
    [0014] breakHere();                                                         // Engine Tick

    [0015] clearState08(113);
    [0017] setState02(113);                                                     // Garage Door
    [0019] breakHere();                                                         // Engine Tick

    [001A] clearState08(114);
    [001C] setState02(114);                                                     // Garage Door
    [001E] breakHere();                                                         // Engine Tick

    [001F] clearState08(115);
    [0021] setState02(115);                                                     // Garage Door
    [0023] breakHere();                                                         // Engine Tick

    [0024] clearState08(116);
    [0026] setState02(116);                                                     // Garage Door
    [0028] breakHere();                                                         // Engine Tick

    [0029] breakHere();                                                         // Engine Tick
    [002A] stopSound(40);
    [002C] stopObjectCode();
}


 /**
  * Script 9: Memoir: Reading
  */
Script-9 {
    [0000] if (Var[16] == 0) {                                                  // if Memoir Quality == Terrible
    [0005]   printEgo("It looks like someone's memoir,/but the writing is terrible!/It's written by a meteor? How strange!");
    [005C] }
    [005C] if (Var[16] == 1) {                                                  // if Memoir Quality == Junk
    [0061]   printEgo("This is the worst junk I've ever read.");
    [0082] }
    [0082] if (Var[16] == 2) {                                                  // if Memoir Quality == Great
    [0087]   printEgo("This is great stuff!/The whole world should see it.");
    [00B4] }
    [00B4] stopObjectCode();
}

 /**
  * Script 10: Memoir: Writing
  */
Script-10 {
    [0000] startScript(108);                                                    // Typewriter: Actor Using
    [0002] breakHere();                                                         // Engine Tick
    [0003] VAR_RESULT = isScriptRunning(108);                                   // Sleep until 'Typewriter: Actor Using' Finishes
    [0006] unless (VAR_RESULT == 0) goto 0002;
    [000B] if (VAR_EGO == 6) {                                                  // If Wendy
    [0010]   Var[16] = 2;                                                       //  Memoir Quality = Great
    [0013]   printEgo("Ah! That's much better.");
    [0029] } else {
    [002C]   Var[16] = 1;                                                       //  Memoir Quality = Junk
    [002F]   printEgo("Whoops! I think I made it worse.");
    [004B] }
    [004B] stopObjectCode();
}


 /**
  * Script 11: Hamster: In Microwave
  */
Script-11 {
    [0000] loadSound(15);                                                       // Rotate
    [0002] loadSound(16);                                                       // Hamster Splat
    [0004] loadSound(14);                                                       // Microwave Bing
    [0006] startSound(15);                                                      // sound Rotate Sound
    [0008] delay(180);                                                          // Wait 3 seconds
    [000C] clearState08(53);                                                    // Clear kObjectState_08 on Hamster
    [000E] setState02(53);                                                      // Set kObjectStateUntouchable on Hamster
    [0010] setState08(54);                                                      // Set kObjectState_08 on Exploded Hamster
    [0012] startSound(16);                                                      // Hamster Splat
    [0014] delay(60);                                                           // Sleep 1 second
    [0018] stopSound(15);                                                       // Microwave Sound
    [001A] startSound(14);                                                      // Microwave Bing
    [001C] stopObjectCode();
}


 /**
  * Script 12: Ted: Open Curtain
  */
Script-12 {
    [0000] startSound(34);                                                      // Start Sound Show Curtain
    [0002] Var[21] = 1;                                                         // Ted: Bath Curtain Moving = Yes
    [0005] clearState08(84);                                                    // Shower Curtain
    [0007] setState02(84);                                                      // set Shower Curtain kObjectStateUntouchable
    [0009] breakHere();                                                         // Engine Tick
    [000A] clearState08(83);                                                    // Shower Curtain
    [000C] setState02(83);                                                      // set Shower Curtain kObjectStateUntouchable
    [000E] breakHere();                                                         // Engine Tick
    [000F] clearState08(82);                                                    // Shower Curtain
    [0011] setState02(82);                                                      // set Shower Curtain kObjectStateUntouchable
    [0013] breakHere();                                                         // Engine Tick
    [0014] breakHere();                                                         // Engine Tick
    [0015] Var[21] = 0;                                                         // Ted: Bath Curtain Moving = No
    [0018] stopSound(34);                                                       // Stop Sound Show Curtain
    [001A] stopObjectCode();
}


 /**
  * Script 13: Ted: Close Curtain
  */
Script-13 {
    [0000] startSound(34);                                                      // Start Sound Show Curtain
    [0002] Var[21] = 1;                                                         // Ted: Bath Curtain Moving = Yes
    [0005] setState08(82);                                                      // Shower Curtain
    [0007] clearState02(82);                                                    // clear Shower Curtain kObjectStateUntouchable
    [0009] breakHere();                                                         // Engine Tick
    [000A] setState08(83);                                                      // Shower Curtain
    [000C] clearState02(83);                                                    // clear Shower Curtain kObjectStateUntouchable
    [000E] breakHere();                                                         // Engine Tick
    [000F] setState08(84);                                                      // Shower Curtain
    [0011] clearState02(84);                                                    // clear Shower Curtain kObjectStateUntouchable
    [0013] breakHere();                                                         // Engine Tick
    [0014] breakHere();                                                         // Engine Tick
    [0015] Var[21] = 0;                                                         // Ted: Bath Curtain Moving = No
    [0018] stopSound(34);
    [001A] stopObjectCode();
}


 /**
  * Script 14: Record: Tentacle Mating Call
  */
Script-14 {
    [0000] loadSound(10);
    [0002] startSound(25);                                                      // start Tentacle Mating Call
    [0004] delay(300);                                                          // Wait 5 seconds
    [0008] if (!getState08(154)) {                                              // If vase not broken
    [000C]   startSound(10);                                                    //  sound Piggy Bank Break
    [000E]   setState08(154);                                                   //  Break Vase
    [0010] }
    [0010] delay(72000);                                                        // Wait 20 minutes
    [0014] stopSound(25);                                                       // stop Tentacle Mating Call
    [0016] Var[23] = 0;                                                         // Victrola Off
    [0019] stopObjectCode();
}


 /**
  * Script 15: Cassette: Play, Break Windows/Free Key
  */
Script-15 {
    [0000] delay(240);                                                          // Sleep 4 seconds

    [0004] if (getState08(45)) {                                                // if Window 1 Ok
    [0008]   startSound(26);                                                    //  sound Window Crack
    [000A]   clearState08(45);                                                  //  Crack Window 1
    [000C] }
    [000C] delay(60);                                                           // Sleep 1 second

    [0010] if (getState08(46)) {                                                // if Window 2 ok?
    [0014]   startSound(26);                                                    //  sound Window Crack
    [0016]   clearState08(46);                                                  //  Crack Window 2
    [0018] }
    [0018] delay(60);                                                           // Sleep 1 second

    [001C] if (!getState08(41)) {                                               // if Chandelleer not broken
    [0020]   startSound(26);                                                    //  sound Window Crack
    [0022]   setState08(41);                                                    //  Hide Glass Chandeleer
    [0024]   setState02(41);                                                    //  Hide Glass Chandeleer
    [0026]   clearState08(42);                                                  //  Show Broken Chandelleer
    [0028]   clearState02(42);                                                  //  Show Broken Chandelleer
    [002A]   clearState08(43);                                                  //  Show Old Rusty Key
    [002C]   clearState02(43);                                                  //  Show Old Rusty Key
    [002E] }
    [002E] delay(60);                                                           // Sleep 1 second

    [0032] Var[90] = 1;                                                         // Start at kid 1 ( Dave )
    [0035] VAR_RESULT = getActorRoom(Var[90]);
    [0038] if (VAR_RESULT == 3) {                                               // is Kid In Downstairs Lounge Room?
    [003D]   VAR_RESULT = getActorX(Var[90]);
    [0040]   if (VAR_RESULT > 33) {                                             //  is Kid X > 33?
    [0045]     VAR_RESULT = getActorX(Var[90]);
    [0048]     if (VAR_RESULT < 46) {                                           //   is Kid Y < 46?
    [004D]       printEgo("Gee, that was close!");                              //    talk some
    [0060]       goto 006A;                                                     //    break loop
    [0063]     }
    [0063]   }
    [0063] }
    [0063] Var[90]++;                                                           //
    [0065] unless (Var[90] == 8) goto 0035;                                     // Loop until Jeff is done

    [006A] delay(18000);                                                        // Sleep for 5 minutes
    [006E] stopSound(25);                                                       // stop Tentacle Mating Call
    [0070] clearState08(207);                                                   // Cassette Player
    [0072] stopObjectCode();
}


 /**
  * Script 16: Telescope: Rotate
  */
Script-16 {
    [0000] startSound(15);                                                      // Start Telescope Rotate Sound
    [0002] delay(60);                                                           // Sleep 1 second
    [0006] printEgo("It's rotating.");
    [0015] delay(180);                                                          // Sleep 3 seconds
    [0019] stopSound(15);                                                       // Stop Telescope Rotate Sound
    [001B] stopObjectCode();
}


 /**
  * Script 17: Telescope: Look
  */
Script-17 {
    [0000] breakHere();                                                         // Engine Tick
    [0001] cutscene();                                                          // Start Cutscene
    [0002] delay(60);                                                           // Sleep 1 second
    [0006] if (Var[20] == 0) {                                                  // if Telescope position 0
    [000B]   loadRoom(35);                                                      //  Load ALien Room
    [000D]   setCameraAt(20);                                                   //  Position camera to landscape
    [000F]   lights(2);                                                         //  Lights always on
    [0011]   delay(120);                                                        //  Sleep 3 seconds
    [0015]   if (Var[25] == 0) {                                                //  if Alien shown in telescope?
    [001A]     startSound(27);
    [001C]     setCameraAt(60);                                                 //   Position camera to alien
    [001E]     clearState08(206);                                               //   set alien frame 0
    [0020]     breakHere();                                                     // Engine Tick
    [0021]     Var[92] = 0;                                                     //

    [0024]     setState08(205);                                                 //   set alien frame 1
    [0026]     setState08(206);                                                 //   set alien frame 1
    [0028]     breakHere();                                                     // Engine Tick  //   Engine Tick
    [0029]     clearState08(205);                                               //   set alien frame 0
    [002B]     clearState08(206);                                               //   set alien frame 0
    [002D]     breakHere();                                                     // Engine Tick  //   Engine Tick
    [002E]     Var[92]++;                                                       //
    [0030]     unless (Var[92] == 4) goto 0024;                                 //   Loop until alien stops moving

    [0035]     Var[25] = 1;                                                     //   Alien shown in telescope = 1
    [0038]   } else {                                                           // --
    [003B]     delay(120);                                                      //   Sleep 3 seconds
    [003F]   }
    [003F] }

    [003F] if (Var[20] == 1) {                                                  // if Telescope position 1 (Wallsafe: Pin Visible)
    [0044]   loadRoom(34);
    [0046]   setCameraAt(100);                                                  //  Position Camera to Tree
    [0048]   lights(2);                                                         //  Lights always on
    [004A]   delay(240);                                                        //  sleep 4 seconds
    [004E] }

    [004E] if (Var[20] == 2) {                                                  // if Telesceope position 2 (Wallsafe: Pin Visible)
    [0053]   loadRoom(34);
    [0055]   setCameraAt(140);                                                  //  Position Camera to House Gutter
    [0057]   lights(2);                                                         //  Lights always on
    [0059]   delay(240);                                                        //  sleep 4 seconds
    [005D] }

    [005D] if (Var[20] == 3) {                                                  // if Telescope position 3
    [0062]   loadRoom(34);
    [0064]   if (getState08(197)) {                                             //  if painting open
    [0068]     setCameraAt(20);                                                 //    Position Camera to (Wallsafe: Pin Visible)
    [006A]   } else {                                                           // ---
    [006D]     setCameraAt(60);                                                 //    Position Camera to (Wallsafe: Pin Hidden)
    [006F]   }
    [006F]   delay(240);                                                        //  sleep 4 seconds
    [0073] }
    [0073] endcutscene();                                                       // End Cutscene
    [0074] stopObjectCode();
}


 /**
  * Script 18: Clock: Repeating Tick Sound
  */
Script-18 {
    [0000] delay(120);                                                          // Sleep 2 seconds

    [0004] startSound(28);                                                      // Play Clock Tick
    [0006] delay(90);                                                           // Sleep 1 1/2 seconds
    [000A] goto 0004;
    [000D] stopObjectCode();
}


 /**
  * Script 19: Power Off Check
  */
Script-19 {
    [0000] if (getState08(124)) {                                               // if Circuit Breaker off?
    [0004]   printEgo("The main power's off.");
    [0018] } else if (getState08(204)) {                                        // else if Wires Repaired
    [001F]   printEgo("It's already turned on.");
    [0035] } else {                                                             // else if Wires Broken
    [0038]   printEgo("I think it's on, but there's no power.");
    [0059] }
    [0059] stopObjectCode();
}


 /**
  * Script 20: It Looks off / cant find a switch
  */
Script-20 {
    [0000] if (getState08(124)) {                                               // if Circuit Breaker off?
    [0004] } else {
    [0007]   unless (!getState08(204)) goto 001F;                               // if Wires Broken
    [000B] }
    [000B] printEgo("It looks off to me.");
    [001C] goto 003E;
    [001F] printEgo("I can't find a switch to turn it off.");
    [003E] stopObjectCode();
}


 /**
  * Script 21: Video Game: Play
  */
Script-21 {
    [0000] if (getState08(124)) {                                               // Circuit Breaker off?
    [0004]   printEgo("The power must be off.");
    [0018] } else {
    [001B]   cursorCommand( kModeCutscene )                                     // Cutscene Mode
    [001D]   startSound(35);
    [001F]   delay(300);                                                        // Wait 5 seconds
    [0023]   cutscene();                                                        // Start Cutscene
    [0024]   beginOverride();
    {
        [0028]   loadRoom(39);                                                      // load Video Game: High Scores
        [002A]   setCameraAt(20);
        [002C]   delay(300);                                                        // Wait 5 seconds
    }
    [0030]   endcutscene();                                                     // End Cutscene
    [0031]   cursorCommand( kModeNormal )                                       // Cutscene Mode Normal
    [0033]   clearState08(173);
    [0035] }
    [0035] stopObjectCode();
}


 /**
  * Script 22:Video Game: Die Enemy Die
  */
Script-22 {
    [0000] setOwnerOf(200,14);                                                  // Quarter owned by Green Tentacle
    [0003] startSound(11);                                                      // sound coin
    [0005] if (getState08(124)) {                                               // If Circuit Breaker = Power Off
    [0009]   delay(60);                                                         //  Sleep 1 second
    [000D]   printEgo("The power's off.");
    [001D] } else {
    [0020]   cursorCommand( kModeCutscene )                                     // Cutscene Mode
    [0022]   delay(300);                                                        // Wait 5 seconds
    [0026]   printEgo("Pretty boring!");
    [0035]   cursorCommand( kModeNormal )                                       // Cutscene Mode Normal
    [0037]   clearState08(169);                                                 // Clear Video Fever
    [0039]   clearState08(170);                                                 // Clear Disco Crazy
    [003B]   clearState08(171);                                                 // Clear Alien Slime
    [003D]   clearState08(172);                                                 // Clear Die Enemy Die
    [003F]   clearState08(174);                                                 // Clear Kill Thrill
    [0041] }
    [0041] stopObjectCode();
}


 /**
  * Script 23: Gym: Get Stronger
  */
Script-23 {
    [0000] loadSound(30);
    [0002] loadSound(31);
    [0004] beginOverride();
    {
        [0008] cursorCommand( kModeCutscene )                                       // Cutscene Mode
        [000A] Var[92] = 5;                                                         // Repeat 5 times

        [000D] setState08(78);                                                      // Down Position: Hunk-O-Matic
        [000F] breakHere();                                                         // Engine Tick

        [0010] startSound(30);                                                      // sound Hunk-O-Matic Down
        [0012] delay(45);
        [0016] clearState08(78);                                                    // Up Position: Hunk-O-Matic
        [0018] breakHere();                                                         // Engine Tick

        [0019] startSound(31);                                                      // sound Hunk-O-Matic Up
        [001B] delay(45);

        [001F] Var[92] -= 1;
        [0022] unless (Var[92] == 0) goto 000D;                                     // Loop

        [0027] VAR_RESULT = getActorBitVar(VAR_EGO,1);                              // Does kid have kActorMiscFlagStrong
        [002B] if (VAR_RESULT == 0) {
        [0030]   setActorBitVar(VAR_EGO,1,1);                                       //  Kid now has kActorMiscFlagStrong
        [0034]   printEgo("Ah. I feel much stronger now!");
        [004E] } else {
        [0051]   printEgo("I've had enough!");
        [0061] }
    }
    [0061] cursorCommand( kModeNormal )                                         // Cutscene Mode Normal
    [0063] stopObjectCode();
}


 /**
  * Script 24: Pin: Entry - Edna Phone Number
  */
Script-24 {
    [0000] startScript(28);                                                     // Phone: Disconnect if Kid walks too far away
    [0002] startSound(21);                                                      // sound Dial Tone
    [0004] delay(120);                                                          // Sleep 3 seconds
    [0008] stopSound(21);                                                       // sound Dial Tone
    [000A] Var[44] = Var[32];                                                   // Pin1 = Telephone Number: Edna 1/4
    [000D] Var[45] = Var[33];                                                   // Pin2 = Telephone Number: Edna 2/4
    [0010] Var[46] = Var[34];                                                   // Pin3 = Telephone Number: Edna 3/4
    [0013] Var[47] = Var[35];                                                   // Pin4 = Telephone Number: Edna 4/4
    [0016] startScript(38);                                                     // start Keypad Input

    [0018] breakHere();                                                         // Engine Tick
    [0019] unless (Var[50] == 0) goto 0018;                                     // Wait for Keypad Input end

    [001E] if (Var[48] == 0) {                                                  // if Pin Entry is Correct
    [0023]   startScript(29);                                                   //  start Cutscene: Edna: Prank Phone Call
    [0025] } else {
    [0028]   startScript(26);                                                   //  start Phone: Busy Signal
    [002A] }
    [002A] stopObjectCode();
}


 /**
  * Script 25: Phone: Ringing
  */
Script-25 {
    [0000] if (VAR_ROOM == 5) {                                                 // if Room == Library
    [0005]   startSound(24);                                                    //  sound Library Phone Ring
    [0007] }

    [0007] if (VAR_ROOM == 19) {                                                // if Room == Nurse Edna's
    [000C]   startSound(23);                                                    //  sound Ednas Phone Ring
    [000E] }

    [000E] delay(240);                                                          // Sleep 4 seconds
    [0012] goto 0000;
    [0015] stopObjectCode();
}


 /**
  * Script 26: Phone: Busy Signal
  */
Script-26 {
    [0000] if (VAR_ROOM == 5) {                                                 // If Room == Library
    [0005]   startSound(22);                                                    //  Phone Busy
    [0007] }

    [0007] delay(30);
    [000B] goto 0000;
    [000E] stopObjectCode();
}


 /**
  * Script 27: Phone: Disconnect
  */
Script-27 {
    [0000] clearState08(103);                                                   // Phone
    [0002] stopScript(29);                                                      // stop Cutscene: Edna: Prank Phone Call
    [0004] Var[17] = 0;                                                         // Nurse Edna Disabled = 0

    [0007] stopScript(24);                                                      // stop Pin: Entry - Edna Phone Number
    [0009] stopSound(21);
    [000B] stopScript(26);                                                      // stop Phone: Busy Signal
    [000D] stopScript(25);                                                      // stop Phone: Ringing
    [000F] stopSound(24);                                                       // stop sound Library Phone Ring
    [0011] stopSound(23);                                                       // stop sound Ednas Phone Ring
    [0013] stopSound(22);                                                       // stop sound Library Phone Busy
    [0015] stopObjectCode();
}


 /**
  * Script 28: Phone: Disconnect if Kid walks too far away
  */
Script-28 {
    [0000] setState08(103);                                                     // Phone On Hook
    [0002] Var[51] = VAR_EGO;
    [0005] Var[52] = getActorX(Var[51]);                                        // Kid Start X
    [0008] Var[53] = getActorY(Var[51]);                                        // Kid Start Y
    [000B] breakHere();                                                         // Engine Tick

    [000C] VAR_RESULT = getActorX(Var[51]);                                     // Kid Current X
    [000F] if (VAR_RESULT == Var[52]) {
    [0014]   VAR_RESULT = getActorY(Var[51]);                                   // Kid Current Y

    [0017]   if (VAR_RESULT == Var[53]) {                                       //
    [001C]     goto 000B;                                                       //  Loop if kid hasn't moved
    [001F]   }
    [001F] }
    [001F] startScript(27);                                                     // start Phone: Disconnect
    [0021] stopObjectCode();
}


 /**
  * Script 29: Cutscene: Edna: Prank Phone Call
  */
Script-29 {
    [0000] startScript(25);                                                     // start Phone: Ringing
    [0002] delay(420);                                                          // Sleep 7 seconds

    [0006] breakHere();                                                         // Engine Tick
    [0007] VAR_RESULT = getActorRoom(10);                                       // Get Nurse Edna's current Room number
    [000A] unless (VAR_RESULT == 19) goto 0006;                                 //  Loop until Nurse Edna is in her room

    [000F] cutscene();                                                          // Start Cutscene
    [0010] stopScript(30);                                                      // Stop Nurse Edna: Check for close actors
    [0012] stopScript(33);                                                      // Stop Nurse Edna: Leave Room
    [0014] Var[17] = 1;                                                         // Nurse Edna Disabled = 1

    [0017] beginOverride();
    {
        [001B] animateActor(10,6,1);                                                // Nurse Edna face Camera
        [001F] startScript(25);                                                     // Start Phone: Ringing
        [0021] loadRoom(19);                                                        // Enter Nurse Ednas Room
        [0023] setCameraAt(20);
        [0025] delay(120);                                                          // Sleep 2 seconds

        [0029] if (Var[55] == 0) {                                                  // Nurse Edna called on phone?
        [002E]   print(10,"Now who could that be?");                                //  No. Talk
        [0043]   delay(180);                                                        //  Sleep 3 seconds
        [0047] }

        [0047] walkActorToObject(10,72);                                            // Walk Edna to Phone
        [004A] breakHere();                                                         // Engine Tick
        [004B] VAR_RESULT = getActorMoving(10);
        [004E] unless (VAR_RESULT == 2) goto 004A;                                  // Wait for Edna

        [0053] animateActor(10,7,1);                                                // Edna face Away
        [0057] breakHere();                                                         // Engine Tick

        [0058] setState08(72);                                                      // Phone Off Hook
        [005A] stopScript(25);                                                      // Stop Phone: Ringing
        [005C] breakHere();                                                         // Engine Tick

        [005D] if (Var[55] == 0) {                                                  // if Nurse Edna Called hasn't been called
        [0062]   print(10,"Hello?/Hello? Who's there?/Is this a prank phone call?/It doesn't sound like a prank phone call/%there's no heavy breathing./Here, let me show you how to do it%");
        [00EC] } else {                                                             // --
        [00EF]   print(10,"Hello?  Is this you again?");
        [0108] }
        [0108] breakHere();                                                         // Engine Tick
        [0109] unless (VAR_HAVE_MSG == 0) goto 0108;                                // Wait for talking

        [010E] putActorInRoom(10,19);                                               // Edna enters room?
        [0111] putActor(10,15,52);
        [0115] animateActor(10,7,1);                                                // Edna Face Away

        [0119] stopScript(25);                                                      // Stop Phone: Ringing
        [011B] setState08(72);                                                      // Phone Off Hook

        [011D] endcutscene();                                                       // End Cutscene
        [011E] Var[55] = 1;                                                         // Nurse Edna Called
        [0121] delay(1200);                                                         // sleep 20 seconds

        [0125] VAR_RESULT = getActorRoom(VAR_EGO);
        [0128] if (VAR_RESULT == 19) {                                              // If Kids Room == Nurse Ednas
        [012D]   print(10,"If you're not going to do it right,/then good bye!");
        [0159]   breakHere();                                                       // Engine Tick
        [015A]   unless (VAR_HAVE_MSG == 0) goto 0159;                              // Wait for talking
        [015F] }

        [015F] clearState08(72);                                                    // Phone on hook
        [0161] VAR_RESULT = getActorRoom(VAR_EGO);
        [0164] if (VAR_RESULT == 5) {                                               // If Kid == Bernard
        [0169]   printEgo("She just hung up.");
        [0179]   startSound(21);                                                    // sound Dial Tone
        [017B] }
    }

    [017B] Var[17] = 0;                                                         // Nurse Edna Disabled = No
    [017E] VAR_RESULT = isScriptRunning(30);
    [0181] if (VAR_RESULT == 0) {
    [0186]   startScript(33);                                                   // If not running, start Nurse Edna: Check for close actors
    [0188] }
    [0188] stopObjectCode();
}


 /**
  * Script 30: Nurse Edna: Check for close actors
  */
Script-30 {
    [0000] Var[110] = 0;                                                        // Nurse Edna: Should leave her room = No
    [0003] if (Var[17] == 0) {                                                  // if Nurse Edna Disabled == No

    [0008]   Var[54] = getClosestObjActor7(10);                                 //  Find actor near Edna
    [000B]   if (Var[54] != 255) {                                              //  if actor is near Edna
    [0010]     Var[110] = 1;                                                    //   Nurse Edna: Should leave her room = Yes

    [0013]     VAR_RESULT = isScriptRunning(29);                                //
    [0016]     if (VAR_RESULT == 1) {                                           //   If script Cutscene: Edna: Prank Phone Call running

    [001B]       VAR_RESULT = getActorRoom(10);
    [001E]       if (VAR_RESULT == 19) {                                        //    If Edna in her room
    [0023]         goto 0080;                                                   //     Loop
    [0026]       }
    [0026]     }

    [0026]     VAR_RESULT = getActorRoom(10);                                   //
    [0029]     if (VAR_RESULT != VAR_ROOM) {                                    //  if Edna in current room
    [002E]     } else {                                                         // --

    [0031]       if (Var[103] == 1) {                                           //   if Edna Waiting in room
    [0036]         print(10,"Oh! An unwelcome visitor!");
    [004F]       }
    [004F]       if (Var[103] == 2) {                                           //   if Edna returning to room
    [0054]         print(10,"Come to me, cutie!");
    [0066]       }

    [0066]       Var[103] = 0;                                                  //   Edna not waiting
    [0069]       walkActorToActor(10,Var[54],2);                                //   Walk Edna to kid
    [006D]       VAR_RESULT = getDist(10,Var[54]);                              //   Distance between kid and Edna
    [0071]       unless (VAR_RESULT <= 2) goto 0080;                            //   If distance < 2, Kid caught
    [0076]     }

    [0076]     stopScript(33);                                                  //  stop Nurse Edna: Leave Room
    [0078]     stopScript(34);                                                  //  stop Nurse Edna: Return to room
    [007A]     stopScript(148);                                                 //  stop Nurse Edna: In Kitchen
    [007C]     startScript(31);                                                 //  start Nurse Edna: Take kid to Dungeon
    [007E]     stopScript(0);                                                   //  stop this script
    [0080]   }
    [0080] }

    [0080] breakHere();                                                         // Engine Tick
    [0081] goto 0000;                                                           // Loop Script
    [0084] stopObjectCode();
}


 /**
  * Script 31: Nurse Edna: Take kid to Dungeon
  */
Script-31 {
    [0000] cutscene();                                                          // Start Cutscene
    [0001] animateActor(Var[54],255,1);                                         // Caught Kid Stopped
    [0005] setActorBitVar(Var[54],64,1);                                        // Set kActorMiscFlagFreeze
    [0009] breakHere();                                                         // Engine Tick
    [000A] breakHere();                                                         // Engine Tick

    [000B] animateActor(Var[54],6,1);                                           // Kid face camera
    [000F] animateActor(10,6,1);                                                // Edna face camera
    [0013] breakHere();                                                         // Engine Tick

    [0014] VAR_RESULT = getActorRoom(10);
    [0017] if (VAR_RESULT == VAR_ROOM) {                                        // If edna in current room
    [001C]   print(10,"I got you!");
    [0027]   breakHere();                                                       //  Engine Tick
    [0028]   unless (VAR_HAVE_MSG == 0) goto 0027;                              //  wait for edna

    [002D]   delay(60);                                                         //  sleep 1 second
    [0031] }
    [0031] setState08(126);                                                     // Dungeon Door open

    [0033] Var[90] = Var[54];                                                   // Caught Kid
    [0036] startScript(141);                                                    // start Dungeon: Calculate Kid Position

    [0038] putActorInRoom(Var[54],4);                                           // caught kid enteres Dungeon
    [003B] putActor(Var[54],Var[91],63);                                        //
    [003F] animateActor(Var[54],5,1);                                           // caught kid face right

    [0043] putActorInRoom(10,4);                                                // Edna enters dungeon
    [0046] putActor(10,58,63);                                                  //  At door
    [004A] animateActor(10,4,1);                                                // Edna face left

    [004E] loadRoom(4);                                                         // Load Dungeon
    [0050] setCameraAt(90);                                                     // Camera to far right of dungeon
    [0052] beginOverride();
    {
        [0056] delay(120);                                                          // Sleep 2 seconds
        [005A] if (Var[54] == 6) {                                                  // If caught kid == Wendy
        [005F] } else {
        [0062]   unless (Var[54] == 2) goto 00A1;                                   //  or caught kid == Razor
        [0067] }
        [0067] print(10,"You're lucky you're not a boy%/%or you'd be in BIG trouble now!");
        [009E] goto 00CC;                                                           //
        [00A1] print(10,"How silly of me!/I should have tied you to my bed!");
        [00CC] breakHere();                                                         // Engine Tick
        [00CD] unless (VAR_HAVE_MSG == 0) goto 00CC;                                // Wait for Edna

        [00D2] walkActorToObject(10,126);                                           // Walk to door
        [00D5] breakHere();                                                         // Engine Tick
        [00D6] VAR_RESULT = getActorMoving(10);
        [00D9] unless (VAR_RESULT == 2) goto 00D5;                                  // Wait for Edna
    }

    [00DE] setActorBitVar(Var[54],64,0);                                        // remove caught kid kActorMiscFlagFreeze
    [00E2] print(255," ");

    [00E6] putActorInRoom(10,0);                                                // Edna leaves
    [00E9] putActor(10,0,0);

    [00ED] startScript(51);                                                     // start Dungeon: Close Entry Door
    [00EF] delay(120);                                                          // sleep 2 seconds
    [00F3] endcutscene();                                                       // End Cutscene
    [00F4] startScript(32);                                                     // start Nurse Edna: Return to Room
    [00F6] stopObjectCode();
}


 /**
  * Script 32: Nurse Edna: Return to Room (Level 3 Hallway)
  */
Script-32 {
    [0000] putActorInRoom(10,0);                                                // Edna leaves
    [0003] putActor(10,0,0);
    [0007] delay(900);                                                          // Sleep 15 seconds
    [000B] putActorInRoom(10,38);                                               // Edna enters Level 3 Hallway
    [000E] putActorAtObject(10,208);                                            // Edna at stairs
    [0011] animateActor(10,5,1);                                                // Edna face right
    [0015] startScript(34);                                                     // start Nurse Edna: Return to room (Enter Room)
    [0017] stopObjectCode();
}


 /**
  * Script 33: Nurse Edna: Leave Room
  */
Script-33 {
    [0000] breakHere();                                                         // Engine Tick
    [0001] Var[109] = 1;                                                        // Nurse Edna: Out of room = Yes
    [0004] Var[103] = 1;                                                        // Nurse Edna: Waiting = in Room
    [0007] startScript(30);                                                     // Nurse Edna: Check for close actors
    [0009] breakHere();                                                         // Engine Tick

    [000A] unless (Var[17] == 0) goto 0009;                                     // If Nurse Edna Disabled, wait
    [000F] breakHere();                                                         // Engine Tick

    [0010] unless (Var[110] == 0) goto 000F;                                    // Should Nurse Edna Leave her room?
    [0015] breakHere();                                                         // Engine Tick

    [0016] VAR_RESULT = getActorRoom("Weird Ed");                               // If Weird Ed
    [0019] unless (VAR_RESULT != 38) goto 0015;                                 //  is in the Level 3 Hallway, wait
    [001E] delay(120);

    [0022] if (!getState08(185)) {                                              // Door: Nurse Edna not open?
    [0026]   setState08(185);                                                   //  Hall Open
    [0028]   setState08(70);                                                    //  In-Room Open
    [002A]   if (VAR_ROOM == 38) {                                              //  If current-room is Level 3 Hallway
    [002F]     startSound(8);                                                   //  sound Door Opening
    [0031]   }
    [0031] }
    [0031] delay(60);                                                           // Sleep 1 second

    [0035] breakHere();                                                         // Engine Tick
    [0036] VAR_RESULT = getActorRoom("Weird Ed");                               // If Weird Ed
    [0039] unless (VAR_RESULT != 38) goto 0035;                                 //  is in the Level 3 Hallway, wait

    [003E] putActorInRoom(10,38);                                               // Put Nurse Edna into hall way
    [0041] putActor(10,31,52);
    [0045] animateActor(10,6,1);                                                // Nurse Edna face Left
    [0049] startScript(34);                                                     // start Nurse Edna: Return to room (Enter Room)
    [004B] stopObjectCode();
}


 /**
  * Script 34: Nurse Edna: Return to room (Enter Room)
  */
Script-34 {
    [0000] Var[109] = 1;                                                        // Nurse Edna out of room
    [0003] Var[103] = 2;                                                        // Nurse Edna: Waiting = Returning to room
    [0006] startScript(30);                                                     // start Nurse Edna: Check for close actors
    [0008] breakHere();                                                         // Engine Tick
    [0009] unless (Var[17] == 0) goto 0008;                                     // If Nurse Edna Disabled, wait

    [000E] breakHere();                                                         // Engine Tick
    [000F] unless (Var[110] == 0) goto 000E;                                    // Should Nurse Edna Leave her room?

    [0014] putActor(10,30,52);
    [0018] animateActor(10,7,1);                                                // Nurse Edna face Away

    [001C] if (!getState08(185)) {                                              // if Door: Nurse Edna not open?
    [0020]   setState08(185);                                                   //   Hall Open
    [0022]   setState08(70);                                                    //   In-Room Open
    [0024]   if (VAR_ROOM == 19) {                                              //  If current-room is Edna's room
    [0029]     startSound(8);
    [002B]   }
    [002B] }

    [002B] delay(180);                                                          // Sleep 3 seconds
    [002F] unless (Var[110] == 0) goto 0008;                                    //  Loop until Nurse Edna: Should leave her room

    [0034] putActorInRoom(10,19);                                               // Put Nurse Edna into her room
    [0037] putActor(10,4,52);
    [003B] animateActor(10,5,1);                                                // Nurse Edna Face right
    [003F] delay(60);                                                           // Sleep 1 second
    [0043] clearState08(185);                                                   //  Hall    Door Close
    [0045] clearState08(70);                                                    //  In-Room Door Close
    [0047] if (VAR_ROOM == 19) {                                                // If current-room is Edna's room
    [004C]   startSound(9);
    [004E] }

    [004E] breakHere();                                                         // Engine Tick
    [004F] unless (Var[17] == 0) goto 004E;                                     // If Nurse Edna Disabled, wait

    [0054] if (Var[110] == 1) {                                                 //  if Should Nurse Edna Leave her room?
    [0059]   startScript(33);                                                   //   start Nurse Edna: Leave Room
    [005B] }
    [005B] Var[109] = 0;                                                        // Nurse Edna in room
    [005E] stopScript(30);                                                      // stop Nurse Edna: Check for close actors
    [0060] stopObjectCode();
}


 /**
  * Script 35: Pin: Entry - Radio (Meteor Police)
  */
Script-35 {
    [0000] Var[44] = Var[58];                                                   // Telephone Number: Meteor Police 1/4
    [0003] Var[45] = Var[59];                                                   // Telephone Number: Meteor Police 2/4
    [0006] Var[46] = Var[60];                                                   // Telephone Number: Meteor Police 3/4
    [0009] Var[47] = Var[61];                                                   // Telephone Number: Meteor Police 4/4
    [000C] startScript(38);                                                     // start Keypad Input
    [000E] breakHere();                                                         // Engine Tick
    [000F] unless (Var[50] == 0) goto 000E;                                     // Wait for Keypad entry

    [0014] startSound(29);
    [0016] if (Var[48] == 0) {                                                  // if Pin Entry Wrong?
    [001B]   startScript(36);                                                   //  start Cutscene: Meteor Police
    [001D] }
    [001D] stopObjectCode();
}


 /**
  * Script 36: Cutscene: Meteor Police
  */
Script-36 {
    [0000] delay(240);
    [0004] cutscene();                                                          // Start Cutscene
    [0005] lockCostume(15);
    [0007] beginOverride();
    {
        [000B] putActorInRoom(15,32);                                               // Meteor police enters Meteor Police
        [000E] putActor(15,50,64);
        [0012] animateActor(15,6,1);                                                // Meteor police face camera
        [0016] loadRoom(32);
        [0018] if (Var[56] == 0) {                                                  // if Meteor Police Called Count == 0
        [001D]   setCameraAt(20);
        [001F]   delay(120);
        [0023]   panCameraTo(60);
        [0025]   breakHere();                                                       //  Engine Tick
        [0026]   unless (VAR_CAMERA_POS_X == 60) goto 0025;                         //  Wait for pan

        [002B]   print(15,"This is the Meteor Police.");
        [0044]   breakHere();                                                       //  Engine Tick
        [0045]   unless (VAR_HAVE_MSG == 0) goto 0044;                              //  Wait for meteor police

        [004A]   delay(120);                                                        //  sleep 2 seconds
        [004E]   print(15,"Uh huh%");
        [0057]   breakHere();                                                       //  Engine Tick
        [0058]   unless (VAR_HAVE_MSG == 0) goto 0057;                              //  Wait for meteor police

        [005D]   delay(60);                                                         //  Sleep 1 second
        [0061]   print(15,"You found the murderous purple meteor?/I'll be there in 5 minutes!/Oh, make sure the lab is unlocked.");
        [00B9]   breakHere();                                                       //  Engine Tick
        [00BA]   unless (VAR_HAVE_MSG == 0) goto 00B9;                              //  Wait for meteor police

        [00BF]   animateActor(15,5,1);                                              //  Meteor Police face right
        [00C3]   delay(60);                                                         //  Sleep 1 second
        [00C7]   print(15,"As for you%/%keep it under lightspeed!");
        [00EB] }

        [00EB] setCameraAt(60);
        [00ED] delay(120);
        [00F1] if (Var[56] == 1) {                                                  // Meteor Police Called Count == 1
        [00F6]   print(15,"Ok, I'll come back,/but this time unlock the lab!");
        [0122] }

        [0122] if (Var[56] == 2) {                                                  // Meteor Police Called Count == 2
        [0127]   print(15,"Enough! I'll come back one more time!");
        [0149] }

        [0149] if (Var[56] == 3) {                                                  // Meteor Police Called Count == 3
        [014E]   print(15,"Forget it!");
        [015A] }
        [015A] breakHere();                                                         // Engine Tick
        [015B] unless (VAR_HAVE_MSG == 0) goto 015A;                                // Wait for Meteor Police
        [0160] delay(120);                                                          // sleep 2 seconds
    }

    [0164] if (VAR_OVERRIDE == 1) {
    [0169]   loadRoom(0);
    [016B] }

    [016B] print(255," ");
    [016F] endcutscene();                                                       // End Cutscene
    [0170] setState08(203);                                                     // Meteor Police Room ??
    [0172] Var[56]++;
    [0174] if (Var[56] == 4) {                                                  // If Meteor Police Called Count More than 3?
    [0179]   Var[56] = 3;                                                       //  Meteor Police Called Count = 3
    [017C] } else {                                                             // --
    [017F]   startScript(131);                                                  //  start Meteor Police: Timer until arrival
    [0181] }

    [0181] stopObjectCode();
}


 /**
  * Script 37: Cutscene: Meteor Police Arrived in Dungeon
  */
Script-37 {
    [0000] loadSound(27);
    [0002] lockSound(27);
    [0004] loadCostume(15);
    [0006] lockCostume(15);

    [0008] cutscene();                                                          // Start Cutscene
    [0009] loadRoom(4);                                                         // Load Dungeon
    [000B] setCameraAt(35);
    [000D] delay(180);                                                          // Sleep 3 seconds
    [0011] startSound(27);
    [0013] breakHere();                                                         // Engine Tick
    [0014] putActorInRoom(15,4);                                                // Meteor police enter Dungeon
    [0017] putActor(15,35,63);
    [001B] clearState08(193);                                                   // Badge
    [001D] clearState02(193);                                                   // Badge
    [001F] animateActor(15,6,1);                                                // Meteor police face camera
    [0023] actorFollowCamera(15);                                               // Camera follows Meteor police
    [0025] delay(180);                                                          // Sleep 3 seconds

    [0029] Var[90] = getClosestObjActor7(15);                                   // if Meteor police find nearby actor
    [002C] if (Var[90] != 255) {

    [0031]   VAR_RESULT = getActorX(Var[90]);                                   //  if Actor X <= 55?
    [0034]   if (VAR_RESULT <= 55) {
    [0039]     walkActorToActor(15,Var[90],5);                                  //   Meteor Police Walk to Kid
    [003D]     breakHere();                                                     //   Engine Tick
    [003E]     breakHere();                                                     //   Engine Tick
    [003F]     VAR_RESULT = getActorMoving(15);
    [0042]     unless (VAR_RESULT == 2) goto 003E;                              //   Wait for Meteor Police

    [0047]     animateActor(15,6,1);                                            //   Meteor Police face camera
    [004B]     print(15,"All right! Let's go get 'em!");
    [0065]     breakHere();                                                     //   Engine Tick
    [0066]     unless (VAR_HAVE_MSG == 0) goto 0065;                            //   Wait for Meteor Police
    [006B]   }
    [006B] }

    [006B] walkActorToObject(15,127);                                           // Walk Meteor Police to Outer Door
    [006E] breakHere();                                                         // Engine Tick
    [006F] VAR_RESULT = getActorMoving(15);
    [0072] unless (VAR_RESULT == 2) goto 006E;                                  // Wait for Meteor Police

    [0077] if (!getState08(127)) {                                              // Outter Door Open?
    [007B] } else {
    [007E]   unless (!getState08(130)) goto 00EA;                               // Inner Door Open?
    [0082] }

    [0082] print(15,"How am I supposed to get in there?");                      // Nope; Inner Door Closed
    [00A0] breakHere();                                                         // Engine Tick
    [00A1] unless (VAR_HAVE_MSG == 0) goto 00A0;                                // Wait for Meteor Police

    [00A6] print(15,"Oh well, maybe next time.");
    [00BE] walkActorTo(15,35,63);
    [00C2] breakHere();                                                         // Engine Tick
    [00C3] unless (VAR_HAVE_MSG == 0) goto 00C2;                                // Wait for Meteor Police

    [00C8] breakHere();                                                         // Engine Tick
    [00C9] VAR_RESULT = getActorMoving(15);
    [00CC] unless (VAR_RESULT == 2) goto 00C8;                                  // Wait for Meteor Police

    [00D1] animateActor(15,6,1);                                                // Meteor Police face Camera
    [00D5] delay(60);                                                           // Sleep 1 second
    [00D9] startSound(27);
    [00DB] breakHere();                                                         // Engine Tick
    [00DC] putActorInRoom(15,0);                                                // Meteor Police leave
    [00DF] putActor(15,0,0);
    [00E3] delay(120);
    [00E7] goto 0237;                                                           // Goto End of Cutscene

                                                                                // Inner Door Open
    [00EA] putActorInRoom(15,31);                                               // Meteor Police enter Lab: Entry
    [00ED] putActor(15,7,52);
    [00F1] putActorInRoom(9,30);                                                // Dr Fred enters Lab: Lab: Zom-b-Matic
    [00F4] putActor(9,38,66);
    [00F8] putActorInRoom(13,31);                                               // Purple enters Lab: Entry
    [00FB] putActor(13,45,63);
    [00FF] loadRoom(31);
    [0101] actorFollowCamera(15);                                               // Camera follow Meteor police
    [0103] walkActorToActor(15,13,5);                                           // Meteor police walk to purple
    [0107] walkActorToActor(13,15,5);                                           // Purple walks to meteor police
    [010B] breakHere();                                                         // Engine Tick
    [010C] breakHere();                                                         // Engine Tick
    [010D] VAR_RESULT = getDist(15,13);
    [0111] unless (VAR_RESULT <= 5) goto 010C;                                  // Wait for purple and meteor police

    [0116] animateActor(13,255,1);
    [011A] print(15,"Don't bug me, sucker-face!");
    [0134] breakHere();                                                         // Engine Tick
    [0135] unless (VAR_HAVE_MSG == 0) goto 0134;                                // Wait for meteor police

    [013A] walkActorToObject(15,135);
    [013D] breakHere();                                                         // Engine Tick
    [013E] VAR_RESULT = getActorMoving(15);
    [0141] unless (VAR_RESULT == 2) goto 013D;                                  // Wait for meteor police

    [0146] setState08(135);                                                     // Open Lab: Zom-B-Matic door
    [0148] setState08(136);                                                     // Open Lab: Zom-B-Matic door
    [014A] startSound(8);
    [014C] delay(60);                                                           // Sleep 1 second
    [0150] loadRoom(0);
    [0152] loadCostume("DrFred");
    [0154] lockCostume("DrFred")
    [0156] putActorInRoom(15,30);                                               // Meteor Police enter Lab: Zom-B-Matic
    [0159] putActor(15,9,60);
    [015D] loadRoom(30);
    [015F] actorFollowCamera(15);                                               // Camera follows Meteor Police
    [0161] breakHere();                                                         // Engine Tick
    [0162] walkActorToObject(15,237);                                           // Walk to Meteor Door
    [0165] walkActorToActor(9,15,5);                                            // Walk Dr. Fred to Meteor Police

    [0169] delay(120);
    [016D] print(15,"Stand aside!");
    [017B] breakHere();                                                         // Engine Tick
    [017C] VAR_RESULT = getActorMoving(15);
    [017F] unless (VAR_RESULT == 2) goto 017B;                                  // Wait for Meteor Police

    [0184] setState08(237);                                                     // Open Meteor Door
    [0186] setState08(251);                                                     // Open Meteor Door
    [0188] startSound(8);
    [018A] delay(60);                                                           // Sleep 1 second
    [018E] putActorInRoom(15,51);                                               // Meteor Police enter Meteor Room
    [0191] putActor(15,6,60);
    [0195] loadRoom(51);
    [0197] actorFollowCamera(15);                                               // Camera follow Meteor Police
    [0199] breakHere();                                                         // Engine Tick
    [019A] walkActorTo(15,36,54);                                               // Walk Meteor Police
    [019E] delay(120);
    [01A2] print(15,"Sooo, it's you, slimy purple meteor.");
    [01C4] breakHere();                                                         // Engine Tick
    [01C5] unless (VAR_HAVE_MSG == 0) goto 01C4;                                // Wait for Meteor Police

    [01CA] breakHere();                                                         // Engine Tick
    [01CB] VAR_RESULT = getActorMoving(15);
    [01CE] unless (VAR_RESULT == 2) goto 01CA;                                  // Wait for Meteor Police

    [01D3] print(255,"Oh no! You found me!");
    [01E6] animateActor(16,1,255);
    [01EA] breakHere();                                                         // Engine Tick
    [01EB] unless (VAR_HAVE_MSG == 0) goto 01EA;                                // Wait for meteor

    [01F0] print(15,"You're coming with me crater-head!");
    [0211] breakHere();                                                         // Engine Tick
    [0212] unless (VAR_HAVE_MSG == 0) goto 0211;                                // wait for meteor police

    [0217] delay(120);
    [021B] startSound(27);
    [021D] breakHere();                                                         // Engine Tick
    [021E] setCameraAt(38);                                                     // Move Camera
    [0220] putActorInRoom(15,0);                                                // Meteor Police leave
    [0223] putActor(15,0,0);
    [0227] putActorInRoom(16,0);                                                // Meteor Leave
    [022A] putActor(16,0,0);
    [022E] setState02(252);                                                     // Meteor = Hidden
    [0230] Var[18] = 3;                                                         // Meteor Location = Gone
    [0233] delay(120);
    [0237] endcutscene();                                                       // End Cutscene
    [0238] unlockSound(27);
    [023A] unlockCostume(15);
    [023C] unlockCostume("DrFred")
    [023E] clearState08(135);                                                   // Close Lab: Zom-B-Matic door
    [0240] clearState08(136);                                                   // Close Lab: Zom-B-Matic door
    [0242] clearState08(237);                                                   // Close Meteor Door
    [0244] clearState08(251);                                                   // Close Meteor Door
    [0246] stopObjectCode();
}


 /**
  * Script 38: Keypad Input
  */
Script-38 {
    [0000] Var[50] = 1;                                                         // Keypad Input Open = Yes
    [0003] Var[48] = 0;                                                         // Pin Entry Wrong = No
    [0006] breakHere();                                                         // Engine Tick
    [0007] cursorCommand( kModeKeypad )                                         // Keypad Mode
    [0009] loadRoom(43);                                                        // Enter Keypad room
    [000B] setCameraAt(20);
    [000D] Var[49] = 255;
    [0010] breakHere();                                                         // Engine Tick
    [0011] unless (Var[49] != 255) goto 0010;                                   // Wait for keypad input
    [0016] if (Var[49] != Var[44]) {                                            // Pin Match?
    [001B]   Var[48] = 1;                                                       //  Pin Entry Wrong = Yes
    [001E] }

    [001E] Var[49] = 255;
    [0021] breakHere();                                                         // Engine Tick
    [0022] unless (Var[49] != 255) goto 0021;                                   // Wait for keypad input
    [0027] if (Var[49] != Var[45]) {                                            // Pin Match?
    [002C]   Var[48] = 1;                                                       //  Pin Entry Wrong = Yes
    [002F] }

    [002F] Var[49] = 255;
    [0032] breakHere();                                                         // Engine Tick
    [0033] unless (Var[49] != 255) goto 0032;                                   // Wait for keypad input
    [0038] if (Var[49] != Var[46]) {                                            // Pin Match?
    [003D]   Var[48] = 1;                                                       //  Pin Entry Wrong = Yes
    [0040] }

    [0040] Var[49] = 255;
    [0043] breakHere();                                                         // Engine Tick
    [0044] unless (Var[49] != 255) goto 0043;                                   // Wait for keypad input
    [0049] if (Var[49] != Var[47]) {                                            // Pin Match?
    [004E]   Var[48] = 1;                                                       //  Pin Entry Wrong = Yes
    [0051] }

    [0051] Var[50] = 0;                                                         // Keypad Input Open = No
    [0054] cursorCommand( kModeNormal )                                         // Cutscene Mode Normal
    [0056] actorFollowCamera(VAR_EGO);
    [0058] stopObjectCode();
}


 /**
  * Script 39: Room9: Wallsafe Input
  */
Script-39 {
    [0000] Var[44] = Var[36];                                                   // Room9: Wall Safe Pin 1/4
    [0003] Var[45] = Var[37];                                                   // Room9: Wall Safe Pin 2/4
    [0006] Var[46] = Var[38];                                                   // Room9: Wall Safe Pin 3/4
    [0009] Var[47] = Var[39];                                                   // Room9: Wall Safe Pin 4/4
    [000C] startScript(38);                                                     // start Keypad Input

    [000E] breakHere();                                                         // Engine Tick
    [000F] unless (Var[50] == 0) goto 000E;                                     // Wait for Keypad Input Open

    [0014] if (Var[48] == 0) {                                                  // Pin Entry Wrong?
    [0019]   setState08(198);                                                   //  Wall Safe Open
    [001B]   startSound(8);
    [001D]   if (Var[114] == 0) {                                               // is Dr. Fred / Nurse Edna Trigger Enabled?
    [0022]     Var[114] = 1;                                                    //  Dr. Fred / Nurse Edna Trigger Enabled = Yes
    [0025]     startScript(136);                                                //  start Cutscene: Dr. Fred / Nurse Edna Trigger #1
    [0027]   }
    [0027] } else {
    [002A]   delay(60);                                                         // Wrong Pin
    [002E]   printEgo("That didn't work.");
    [003F] }
    [003F] stopObjectCode();
}


 /**
  * Script 40: Lab Entry Keypad Input
  */
Script-40 {
    [0000] Var[44] = Var[40];                                                   // The Lab: Pin 1/4
    [0003] Var[45] = Var[41];                                                   // The Lab: Pin 2/4
    [0006] Var[46] = Var[42];                                                   // The Lab: Pin 3/4
    [0009] Var[47] = Var[43];                                                   // The Lab: Pin 4/4

    [000C] startScript(38);                                                     // start Keypad Input
    [000E] breakHere();                                                         // Engine Tick
    [000F] unless (Var[50] == 0) goto 000E;                                     // Wait for keypad

    [0014] if (Var[48] == 0) {                                                  // Pin Entry Wrong?
    [0019]   clearState04(130);
    [001B]   setState08(130);                                                   //  Inner Door Open
    [001D]   setState08(133);                                                   //  Inner Door Open
    [001F]   startSound(13);                                                    //  Lab Door Opens Sound
    [0021] } else {
    [0024]   startScript(64);                                                   // start Print "The door is locked"
    [0026] }
    [0026] stopObjectCode();
}


 /**
  * Script 41: Cutscene: Dr. Fred: Meltdown
  */
Script-41 {
    [0000] breakHere();                                                         // Engine Tick
    [0001] cutscene();                                                          // Start Cutscene
    [0002] Var[106] = Var[105];
    [0005] beginOverride();
    {
        [0009] putActorInRoom(9,31);                                                // Dr Fred enters Lab Entry
        [000C] putActor(9,20,63);

        [0010] putActorInRoom(13,31);                                               // Purple Tentacle enters Lab Entry
        [0013] putActor(13,45,63);

        [0017] loadSound(63);
        [0019] lockSound(63);
        [001B] loadRoom(31);                                                        // Enter Lab Entry
        [001D] setCameraAt(20);
        [001F] breakHere();                                                         // Engine Tick

        [0020] if (Var[106] == 3) {                                                 // Dr. Fred: Pool/Power Out
        [0025]   print(9,"Not again!");
        [0031] } else {

        [0034]   if (getState08(124)) {                                             // Circuit Break off?

        [0038]     if (Var[106] != 1) {                                             // Already occured?
        [003D]       print(9,"Oh great, someone shut the power off!");
        [005F]       Var[105] += 1;
        [0062]     } else {
        [0065]       goto 0025;
        [0068]     }
        [0068]   } else if (Var[106] != 2) {                                        // Pool Emptied?

        [0070]     print(9,"Oh no!/The pool is empty again!");
        [008D]     Var[105] += 2;
        [0090]   } else {
        [0093]     goto 0025;
        [0096]   }
        [0096]   breakHere();                                                       // Engine Tick
        [0097]   unless (VAR_HAVE_MSG == 0) goto 0096;

        [009C]   print(9,"We're going to have another meltdown!!");
        [00C0] }

        [00C0] walkActorToObject(9,160);                                            // Walk Dr. Fred
        [00C3] breakHere();                                                         // Engine Tick
        [00C4] unless (VAR_HAVE_MSG == 0) goto 00C3;                                // Wait for Dr.Fred to finish speaking

        [00C9] if (Var[106] == 0) {
        [00CE]   print(9,"How can I take over the world%/%when I'm on a budget?/I always get stuck with cheap equipment./Boy is the meteor going to be pissed.");
        [013E] } else {
        [0141]   print(9,"How will I ever take over the world%/%when things like this keep happening?");
        [0183] }
        [0183] breakHere();                                                         // Engine Tick

        [0184] walkActorTo(9,10,63);                                                // Walk Dr. Fred
        [0188] breakHere();                                                         // Engine Tick
        [0189] VAR_RESULT = getActorMoving(9);
        [018C] unless (VAR_RESULT == 2) goto 0188;                                  // Wait for Dr. Fred

        [0191] if (VAR_HAVE_MSG == 0) {
        [0196] } else {
        [0199]   walkActorTo(9,30,63);                                              // Walk Dr. Fred
        [019D]   breakHere();                                                       // Engine Tick

        [019E]   VAR_RESULT = getActorMoving(9);
        [01A1]   unless (VAR_RESULT == 2) goto 019D;                                // Wait for Dr. Fred to finish walking
        [01A6]   unless (VAR_HAVE_MSG == 0) goto 0183;                              // Wait for Dr. Fred to finish talking
        [01AB] }

        [01AB] walkActorTo(9,20,63);                                                // Walk Dr. Fred
        [01AF] breakHere();                                                         // Engine Tick
        [01B0] VAR_RESULT = getActorMoving(9);
        [01B3] unless (VAR_RESULT == 2) goto 01AF;                                  // Wait for Dr. Fred

        [01B8] walkActorTo(9,21,63);                                                // Walk Dr. Fred
        [01BC] print(9,"TENTACLE!!! FRONT AAAAAAAND CENTER!");
        [01DF] breakHere();                                                         // Engine Tick
        [01E0] unless (VAR_HAVE_MSG == 0) goto 01DF;                                // wait for Dr. Fred to finish speaking

        [01E5] walkActorTo(13,25,63);                                               // Walk Purple to Dr. Fred
        [01E9] breakHere();                                                         // Engine Tick
        [01EA] VAR_RESULT = getActorMoving(13);
        [01ED] unless (VAR_RESULT == 2) goto 01E9;                                  // Wait for purple

        [01F2] if (Var[106] == 0) {                                                 // Dr. Fred: Pool/Power Out
        [01F7]   print(13,"Yes sir, Dr. Fred sir,/Purple Tentacle at your disposal, sir.");
        [022E]   breakHere();                                                       // Engine Tick
        [022F]   unless (VAR_HAVE_MSG == 0) goto 022E;                              // Wait for purple

        [0234]   print(9,"Quick! Go check out the reactor.");
        [0252] } else {
        [0255]   print(13,"Here I am!");
        [0260]   breakHere();                                                       // Engine Tick
        [0261]   unless (VAR_HAVE_MSG == 0) goto 0260;                              // Wait for purple

        [0266]   print(9,"We've got problems again!");
        [027F] }
        [027F] breakHere();                                                         // Engine Tick
        [0280] unless (VAR_HAVE_MSG == 0) goto 027F;                                // wait for text finish

        [0285] print(13,"Yes sir!");
        [028F] delay(120);
        [0293] walkActorToObject(13,133);                                           // Walk purple to Door
        [0296] walkActorToObject(9,160);                                            // Walk dr. fred

        [0299] breakHere();                                                         // Engine Tick
        [029A] VAR_RESULT = getActorMoving(13);
        [029D] unless (VAR_RESULT == 2) goto 0299;                                  // Wait for purple

        [02A2] setState08(133);                                                     // Open Door
        [02A4] delay(60);                                                           // Sleep 1 second
    }

    [02A8] clearState08(133);                                                   // Close Door
    [02AA] endcutscene();                                                       // End Cutscene
    [02AB] startScript(42);                                                     // start Cutscene: Purple Tentacle in Basement
    [02AD] stopObjectCode();
}


 /**
  * Script 42: Cutscene: Purple Tentacle in Basement
  */
Script-42 {
    [0000] delay(1200);
    [0004] putActorInRoom(13,8);                                                // Purple Tentacle enters basement
    [0007] putActor(13,72,12);

    [000B] VAR_RESULT = getClosestObjActor7(13);                                // Find any actors near Purple
    [000E] if (VAR_RESULT == 255) {                                             // None?

    [0013]   cutscene();                                                        //  Start Cutscene
    [0014]   beginOverride();
    {
        [0018]   loadRoom(8);                                                       // Enter Basement
        [001A]   actorFollowCamera(13);                                             // Camera follow Purple

        [001C]   walkActorToObject(13,69);                                          // Walk Purple to Light Switch (object #325)
        [001F]   breakHere();                                                       // Engine Tick
        [0020]   VAR_RESULT = getActorMoving(13);
        [0023]   unless (VAR_RESULT == 2) goto 001F;                                // Wait for Purple

        [0028]   startSound(12);                                                    // Sound Light Switch
        [002A]   setBitVar(VAR_ROOM,1,0);                                           // Turn light on
        [002E]   startScript(50);                                                   // start Room Lights: Check for flashlight / room light status
        [0030]   delay(120);

        [0034]   print(13,"Hmm. There's no one here!");
        [004C]   breakHere();                                                       // Engine Tick
        [004D]   unless (VAR_HAVE_MSG == 0) goto 004C;                              // Wait for purple

        [0052]   startSound(12);                                                    // Sound Light Switch
        [0054]   setBitVar(VAR_ROOM,1,1);                                           // Turn light off
        [0058]   startScript(50);                                                   // start Room Lights: Check for flashlight / room light status
        [005A]   delay(60);                                                         // Sleep 1 second

        [005E]   walkActorTo(13,72,12);                                             // Walk up stairs
        [0062]   breakHere();                                                       // Engine Tick
        [0063]   VAR_RESULT = getActorMoving(13);
        [0066]   unless (VAR_RESULT == 2) goto 0062;                                // Wait for purple

        [006B]   putActorInRoom(13,31);                                             // Purple enters Lab: Entry
        [006E]   putActor(13,45,63);
        [0072]   delay(60);                                                         // Sleep 1 second
    }

    [0076]   if (VAR_OVERRIDE == 1) {
    [007B]     loadRoom(0);
    [007D]   }

    [007D]   putActorInRoom(13,31);                                             // Purple enters Lab: Entry
    [0080]   putActor(13,45,63);
    [0084]   setBitVar(8,1,1);
    [0088]   endcutscene();                                                     // End Cutscene
    [0089] } else {
    [008C]   delay(60);                                                         // Sleep 1 second
    [0090]   print(13,"I'll get you!");
    [009E]   startScript(43);                                                   // start Purple Tentacle: Check for close actors
    [00A0] }

    [00A0] unlockSound(63);
    [00A2] stopObjectCode();
}


 /**
  * Script 43: Purple Tentacle: Check for close actors
  */
Script-43 {
    [0000] loadSound(36);

    [0002] breakHere();                                                         // Engine Tick
    [0003] Var[93] = getClosestObjActor7(13);                                   // Get actors near Purple Tentacle
    [0006] if (Var[93] == 255) {                                                // None?
    [000B]   putActorInRoom(13,31);                                             //  Purple enters Room 31: Lab Entry
    [000E]   putActor(13,45,63);
    [0012]   stopScript(0);                                                     //  Stop Script
    [0014] }

    [0014] walkActorToActor(13,Var[93],2);                                      // Walk Purple to kid
    [0018] VAR_RESULT = getDist(13,Var[93]);
    [001C] unless (VAR_RESULT <= 2) goto 0002;                                  // wait for purple

    [0021] startSound(36);
    [0023] animateActor(Var[93],255,1);                                         // Freeze kid
    [0027] animateActor(Var[93],6,1);                                           // Kid face camera
    [002B] setActorBitVar(Var[93],64,1);                                        // Kid Frozen

    [002F] print(13,"Ah hah!/I caught you sneaking around our house!/To the dungeon, intruder!");
    [0071] breakHere();                                                         // Engine Tick
    [0072] unless (VAR_HAVE_MSG == 0) goto 0071;                                // Wait for purple

    [0077] delay(60);                                                           // Sleep 1 second
    [007B] setActorBitVar(Var[93],64,0);                                        // Unfreeze kid

    [007F] VAR_RESULT = getObjectOwner(193);
    [0082] if (VAR_RESULT != Var[93]) {                                         // Kid does not owns badge?

    [0087]   VAR_RESULT = getObjectOwner(27);
    [008A]   if (VAR_RESULT != Var[93]) {                                       // kid does not own contract?

    [008F]     if (VAR_ROOM == 31) {                                            // Current room is Lab: Entry

    [0094]       VAR_RESULT = getActorBitVar(Var[93],2);                        // Kid has kActorMiscFlagGTFriend ?
    [0098]       if (VAR_RESULT == 1) {
    [009D]         loadCostume(14);                                             //
    [009F]         startScript(110);                                            //  start Green Tentacle: Storm Dr. Freds Lab
    [00A1]         stopScript(0);                                               // ---
    [00A3]       }

    [00A3]       if (Var[74] == 1) {                                            // Weird Ed: Should storm lab == Yes?
    [00A8]         loadCostume(11);
    [00AA]         startScript(94);                                             // start Weird Ed: Storm Dr. Freds Lab
    [00AC]         stopScript(0);
    [00AE]       }
    [00AE]     }
    [00AE]   } else if (Var[82] != 1) {                                         // Contract: Accept Content == 1
    [00B6]     goto 008F;
    [00B9]   }
    [00B9] }
    [00B9] cutscene();                                                          // Start Cutscene
    [00BA] beginOverride();
    {
        [00BE] setState08(126);                                                     // Open Dungeon Door
        [00C0] Var[90] = Var[93];                                                   //
        [00C3] startScript(141);                                                    // start Dungeon: Calculate Kid Position
        [00C5] putActorInRoom(Var[93],4);                                           // Kid enters dundgeon
        [00C8] putActor(Var[93],Var[91],63);
        [00CC] animateActor(Var[93],5,1);                                           // Kid face right
        [00D0] putActorInRoom(13,4);                                                // Purple enters dungeon
        [00D3] putActor(13,61,63);
        [00D7] loadRoom(4);                                                         // Enter Dungeon
        [00D9] setCameraAt(90);
        [00DB] delay(120);
        [00DF] print(13,"I hope you rot!");

        [00EE] if (getState08(130)) {                                               // Inner Door open?
        [00F2]   print(13,"And this time%/%I'll make sure you won't get out!");
        [011E]   breakHere();                                                       // Engine Tick
        [011F]   unless (VAR_HAVE_MSG == 0) goto 011E;                              // wait for purple

        [0124]   startScript(96);
        [0126] }
        [0126] delay(120);
        [012A] startScript(51);                                                     // start Dungeon: Close Entry Door

        [012C] walkActorTo(13,10,63);                                               // Walk purple
        [0130] breakHere();                                                         // Engine Tick
        [0131] VAR_RESULT = getActorMoving(13);
        [0134] unless (VAR_RESULT == 2) goto 0130;                                  // wait for purple
    }

    [0139] putActorInRoom(13,31);                                               // Purple enterse Lab Entry
    [013C] putActor(13,45,63);
    [0140] endcutscene();                                                       // End Cutscene

    [0141] setState04(130);                                                     // Close Door
    [0143] clearState08(130);                                                   // Close inner door
    [0145] clearState08(133);                                                   // close inner door (lab side)
    [0147] clearState02(80);                                                    // close ?
    [0149] clearState08(128);                                                   // close top padlock
    [014B] clearState08(129);                                                   // close bottom padlock
    [014D] setState04(127);                                                     // close outer door
    [014F] clearState08(127);                                                   // close outer door
    [0151] cursorCommand( kModeNormal )                                         // Cutscene Mode Normal
    [0153] stopObjectCode();
}


 /**
  * Script 44:  -= NOT USED =-
  */
Script-44 {
    [0000] stopObjectCode();
    [0001] stopObjectCode();
    [0002] setState02(211);                                                     // Man-eating plant
    [0004] setState02(67);                                                      // Man-eating plant
    [0006] stopScript(0);
    [0008] goto FFFFFFD0;
    [000B] stopObjectCode();
    [000C] VAR_EGO = getActorBitVar(0,0);
}


 /**
  * Script 45: Green Tentacle: Block until player feeds
  */
Script-45 {
    [0000] if (Var[86] == 1) {                                                  // Already running?
    [0005]   delay(60);                                                         // wait 1 second
    [0009] }
    [0009] Var[95] = VAR_EGO;
    [000C] startScript(158);                                                    // Green Tentacle: Block player passing
    [000E] loadSound(36);
    [0010] Var[86] = 1;
    [0013] setActorBitVar(Var[95],64,0);

    [0017] if (Var[95] == 5) {                                                  // is actor Bernard
    [001C]   VAR_RESULT = getDist(5,14);                                        //  Distance between Bernard and Green Tentacle < 10?

    [0020]   if (VAR_RESULT < 10) {
    [0025]     cursorCommand( kModeCutscene )                                   // Cutscene Mode
    [0027]     breakHere();                                                     // Engine Tick
    [0028]     animateActor(5,255,1);                                           //  Stop Bernard Moving
    [002C]     Var[115] = 1;
    [002F]     printEgo("AAAAAAAAAAAAAAAAAAAEEEEEEEEEEEEEEE!");

    [0054]     doSentence(13,179,0);                                            //  Walk to Down Stairs
    [0058]     breakHere();                                                     // Engine Tick //  Sleep until Kid leaves
    [0059]     unless (VAR_ROOM != 12) goto 0058;                               //   Level 2 Stairs to Level 3

    [005E]     goto 00BE;
    [0061]   }
    [0061] }

    [0061] breakHere();                                                         // Engine Tick
    [0062] VAR_RESULT = getDist(14,Var[95]);                                    // Distance between Kid and Green Tentacle
    [0066] unless (VAR_RESULT <= 3) goto 0017;                                  //  sleep until distance < 3

    [006B] if (Var[79] < 7) {                                                   // Green Tentacle: Has been Fed?
    [0070]   print(14,"You can't pass until you feed me!");
    [008E] } else if (Var[80] == 0) {                                           // Green Tentacle: Has drank?
    [0096]   print(14,"Where's my drink!");
    [00A8] }

    [00A8] breakHere();                                                         // Engine Tick
    [00A9] if (Var[79] >= 7) {                                                  // Green Tentacle: Has been Fed
    [00AE]   if (Var[80] == 1) {                                                // Green Tentacle: Has drank?
    [00B3]     goto 00BE;
    [00B6]   }
    [00B6] }

    [00B6] VAR_RESULT = getActorRoom(Var[95]);                                  // Get Kid Room
    [00B9] unless (VAR_RESULT != 12) goto 00A8;                                 // Delay until kid leaves room "Level 2 Stairs to Level 3"

    [00BE] stopScript(158);                                                     // Stop "Green Tentacle: Block player until Fed"
    [00C0] Var[86] = 0;
    [00C3] walkActorTo(14,17,52);                                               // Walk Green Tentacle to corner
    [00C7] breakHere();                                                         // Engine Tick

    [00C8] VAR_RESULT = getActorMoving(14);
    [00CB] unless (VAR_RESULT == 2) goto 00C7;                                  // Wait until Green finishes moving

    [00D0] stopObjectCode();
}


 /**
  * Script 46: Plant Size
  */
Script-46 {
    [0000] breakHere();                                                         // Engine Tick
    [0001] animateActor(19,254,1);                                              // Plant Mouth Open

    [0005] breakHere();                                                         // Engine Tick
    [0006] animateActor(19,253,1);                                              // Plant Mouth Closed

    [000A] breakHere();                                                         // Engine Tick
    [000B] if (Var[30] == 0) {
    [0010]   animateActor(19,4,1);                                              // Plant Small
    [0014] }

    [0014] if (Var[30] == 1) {
    [0019]   animateActor(19,5,1);                                              // Plant Mid
    [001D] }

    [001D] if (Var[30] == 2) {                                                  // Plant Full
    [0022]   animateActor(19,6,1);
    [0026] }

    [0026] if (Var[30] == 255) {                                                // Plant Dead
    [002B]   putActorInRoom(19,0);                                              // Plant leaves room
    [002E]   putActor(19,0,0);
    [0032]   setState02(211);                                                   // Man-eating plant locked
    [0034]   setState02(67);                                                    // Man-eating plant locked
    [0036]   stopScript(0);
    [0038] }

    [0038] goto 0000;
    [003B] stopObjectCode();
}


 /**
  * Script 47: Meteor Police Poster (Read Number)
  */
Script-47 {
    [0000] printEgo("WANTED: For terrible acts of violence%/%one murderous purple slimy meteor.");
    [0043] breakHere();                                                         // Engine Tick
    [0044] unless (VAR_HAVE_MSG == 0) goto 0043;
    [0049] if (Var[57] == 0) {                                                  // Telephone Number: Meteor Police (Active) == Pin0
    [004E]   printEgo("If found, call 3412.");
    [0061] }
    [0061] if (Var[57] == 1) {                                                  // Telephone Number: Meteor Police (Active) == Pin1
    [0066]   printEgo("If found, call 1138.");
    [0079] }
    [0079] if (Var[57] == 2) {                                                  // Telephone Number: Meteor Police (Active) == Pin2
    [007E]   printEgo("If found, call 9111.");
    [0091] }
    [0091] if (Var[57] == 3) {                                                  // Telephone Number: Meteor Police (Active) == Pin3
    [0096]   printEgo("If found, call 1977.");
    [00A9] }
    [00A9] if (Var[57] == 4) {                                                  // Telephone Number: Meteor Police (Active) == Pin4
    [00AE]   printEgo("If found, call 0525.");
    [00C1] }
    [00C1] breakHere();                                                         // Engine Tick
    [00C2] unless (VAR_HAVE_MSG == 0) goto 00C1;                                // Wait for text
    [00C7] stopObjectCode();
}


 /**
  * Script 48: Plant: Give Pepsi
  */
Script-48 {
    [0000] breakHere();                                                         // Engine Tick
    [0001] setOwnerOf(60,0);                                                    // Remove Can of Pepsi
    [0004] stopScript(46);                                                      // stop Plant Size
    [0006] if (Var[30] == 2) {                                                  // Plant Full Size
    [000B]   setState02(211);                                                   // Man-eating plant Locked
    [000D] }
    [000D] startScript(49);                                                     // start Plant: Burp
    [000F] delay(360000);                                                       // Sleep 100 minutes
    [0013] goto 000F;
    [0016] stopObjectCode();
}


 /**
  * Script 49: Plant: Burp
  */
Script-49 {
    [0000] animateActor(19,253,1);                                              // Plant Mouth Closed
    [0004] delay(240);                                                          // Wait 4 Seconds
    [0008] animateActor(19,254,1);                                              // Plant Mouth Open
    [000C] breakHere();                                                         // Engine Tick
    [000D] if (VAR_HAVE_MSG == 0) {                                             // If no-one is speaking
    [0012]   print(255,"Burp!");
    [001A] }
    [001A] delay(30);
    [001E] animateActor(19,253,1);                                              // Plant Mouth Closed
    [0022] delay(600);                                                          // Sleep 10 seconds
    [0026] goto 0008;
    [0029] stopObjectCode();
}


 /**
  * Script 50: Room Lights: Check for flashlight / room light status
  */
Script-50 {
    [0000] Var[92] = 0;
    [0003] Var[90] = getObjectOwner(51);                                        // Get owner of Flashlight
    [0006] VAR_RESULT = getActorRoom(Var[90]);
    [0009] if (VAR_RESULT == VAR_ROOM) {                                        // Flashlight owner in current room?
    [000E]   if (Var[12] == 1) {                                                //  Fliashlight on?
    [0013]     Var[92] = 1;                                                     //  Light level
    [0016]   }
    [0016] }
    [0016] if (!getState08(124)) {                                              // Circuit Breaker On?
    [001A]   VAR_RESULT = getBitVar(VAR_ROOM,1);                                //
    [001E]   if (VAR_RESULT == 0) {                                             //  Light On?
    [0023]     Var[92] = 2;                                                     //   Light On
    [0026]   }
    [0026] }
    [0026] VAR_RESULT = getBitVar(VAR_ROOM,2);                                  //
    [002A] if (VAR_RESULT == 1) {                                               //  Light always on?
    [002F]   Var[92] = 2;
    [0032] } else {
    [0035]   lights(Var[92]);
    [0037] }
    [0037] stopObjectCode();
}


 /**
  * Script 51: Dungeon: Close Entry Door
  */
Script-51 {
    [0000] if (getState08(126)) {                                               // Door is open?
    [0004]   clearState08(126);                                                 // Close Dungeon Door
    [0006]   clearState08(122);                                                 // Close Dungeon Door
    [0008]   startSound(42);                                                    // Close Steel Door
    [000A] }
    [000A] stopObjectCode();
}


 /**
  * Script 52: Repeat Outside Sound
  */
Script-52 {
    [0000] breakHere();                                                         // Engine Tick
    [0001] unless (VAR_IS_SOUND_RUNNING == 0) goto 0000;                        // Wait until sound finishes
    [0006] startSound(38);                                                      // Play outside noise
    [0008] delay(360);                                                          // Sleep 6 seconds
    [000C] goto 0006;
    [000F] stopObjectCode();
}


 /**
  * Script 53: Microwave
  */
Script-53 {
    [0000] loadSound(15);
    [0002] loadSound(14);
    [0004] startSound(15);                                                      // Rotate Sound
    [0006] delay(240);
    [000A] stopSound(15);                                                       // Stop Rotate Sound
    [000C] startSound(14);                                                      // Play Microwave Bing
    [000E] if (Var[66] == 6) {                                                  // Items in Microwave
    [0013]   Var[62] = 1;                                                       // Stamp is Sticky
    [0016]   startScript(79);                                                   // start Envelope: Name
    [0018]   startScript(76);                                                   // start Jar / Envelop: Name
    [001A] }
    [001A] if (getState08(50)) {                                                // Jar of water
    [001E]   startScript(55);                                                   //  < Delays 3600 then Stops >
    [0020]   if (Var[22] == 3) {                                                // If Glass Jar Contents == Developer
    [0025]     Var[22] = 4;                                                     // Glass Jar Contents = Microwaved Developer
    [0028]   }
    [0028] }
    [0028] stopObjectCode();
}


 /**
  * Script 54: Microwave: Put item in
  */
Script-54 {
Events:
  18 - 0000
  48 - 0042
    [0000] stopCurrentScript();
    [0001] stopObjectCode();
    [0002] stopObjectCode();
    [0003] stopObjectCode();

    [0004] if (activeObject2 == 1) {                                            // Is ActiveObject Hamster?

    [0008]   if (VAR_EGO <= 2) {                                                //  Syd or Razor
    [000D]     if (getState08(activeObject)) {                                  //   Is Microwave door open?

    [0010]       if (Var[66] == 0) {                                            //    Microwave has nothing in it?
    [0015]         setOwnerOf(1,14);                                            //     Set owner of Hamster to Green Tentacle ( yes... why? )
    [0018]         setState08(53);                                              //     Set 08 on Hamster
    [001A]         clearState02(53);                                            //     Clear 02 on Hamster
    [001C]         Var[66] = 1;                                                 //     Item in Microwave is Hamster
    [001F]       } else {
    [0022]         printEgo_c64("< ");
    [0025]       }
    [0025]     } else {
    [0028]       startScript(63);                                               //     start Print "The door is closed"
    [002A]     }
    [002A]   } else {
    [002D]     printEgo("How sick!");
    [0037]   }

    [0037] } else if (activeObject2 == 201) {                                   // Is ActiveObject Sealed Envelope

    [003E]   if (getState08(activeObject)) {                                    //  Is Microwave door open?
    [0041]     if (Var[66] != 1) {                                              //   Item in Microwave is not Hamster
    [0046]       if (Var[62] == 0) {                                            //    Is Stamp not sticky
    [004B]         setOwnerOf(201,14);                                          //     Set owner of Sealed Envelope to Green Tentacle ( yes... why? )
    [004E]         setState08(234);                                             //
    [0050]         clearState02(234);                                           //     clear kObjectStateUntouchable on Sealed Envelope
    [0052]         Var[66] += 2;
    [0055]       }
    [0055]       if (Var[62] == 2) {                                            //    Stamp Ripped?
    [005A]         printEgo("It's too late for that!");
    [006F]       }
    [006F]       if (Var[62] == 1) {                                            //    Stamp Sticky
    [0074]         printEgo("Not again!");
    [007F]       }
    [007F]     } else {
    [0082]       printEgo_c64("\\");
    [0085]     }
    [0085]   } else {
    [0088]     startScript(63);                                                 // start Print "The door is closed"
    [008A]   }

    [008A] } else if (activeObject2 == 99) {                                    // Is ActiveObject Glass Jar
    [0091]   if (getState08(activeObject)) {                                    //  Is Microwave door open?
    [0094]     if (Var[66] != 1) {                                              //   Item in Microwave is not Hamster
    [0099]       if (Var[22] == 0) {                                            //    Is Glass Jar Empty
    [009E]         printEgo("I'd better fill it first.");
    [00B5]       } else {
    [00B8]         setOwnerOf(99,14);                                           //     Set owner of GlassJar to Green Tentacle
    [00BB]         setState08(50);                                              //     Set Jar of Water
    [00BD]         clearState02(50);                                            //     Clear kObjectStateUntouchable on jar of water
    [00BF]         Var[66] += 4;
    [00C2]       }
    [00C2]     } else {
    [00C5]       printEgo_c64("");
    [00C8]     }
    [00C8]   } else {
    [00CB]     startScript(63);                                                 // start Print "The door is closed"
    [00CD]   }
    [00CD] } else {
    [00D0]   printEgo("I'd better not.");
    [00DF] }
    [00DF] stopScript(0);                                                       // -----
    [00E1] stopCurrentScript();
    [00E2] Var[39] = getDist(115,Var[32]);
    [00E6] putActor(108,Var[114],Var[101]);
    [00EA] putActor(100,Var[121],Var[32]);
    [00EE] Var[117] = getClosestObjActor25(108);
    [00F1] stopCurrentScript();
    [00F2] print_c64(0,"  ");
}


 /**
  * Script 55: Timer: 1 Minute
  */
Script-55 {
    [0000] delay(3600);                                                         // Sleep 1 minute
    [0004] stopObjectCode();
}


 /**
  * Script 56: Cutscene: Kid Dies
  */
Script-56 {
    [0000] breakHere();                                                         // Engine Tick
    [0001] cutscene();                                                          // Start Cutscene
    [0002] if (Var[76] == 1) {                                                  // Death by Radioactive Steam?
    [0007]   printEgo("Oh no! Radioactive steam! Ahheeeeeeee%");
    [002B]   animateActor(VAR_EGO,4,1);                                         //  Face Left
    [002F]   breakHere();                                                       // Engine Tick
    [0030]   animateActor(VAR_EGO,6,1);                                         //  Face Camera
    [0034]   breakHere();                                                       // Engine Tick
    [0035]   animateActor(VAR_EGO,5,1);                                         //  Face Right
    [0039]   breakHere();                                                       // Engine Tick
    [003A]   animateActor(VAR_EGO,7,1);                                         //  Face Away
    [003E]   breakHere();                                                       // Engine Tick
    [003F]   Var[52] = getRandomNr(70);                                         //  Random X
    [0042]   Var[53] = getRandomNr(12);                                         //  Random Y
    [0045]   Var[53] += 56;
    [0048]   walkActorTo(VAR_EGO,Var[52],Var[53]);
    [004C]   unless (VAR_HAVE_MSG == 0) goto 002B;                              //  Repeat until speach finishes
    [0051]   Var[77] = VAR_EGO;
    [0054] }
    [0054] if (Var[76] == 2) {                                                  // Death by Pool?
    [0059]   loadRoom(6);                                                       //  Enter Pool Area
    [005B]   setCameraAt(41);                                                   //  Look to right of pool
    [005D]   delay(120);
    [0061]   print(255,"Glug! Glug! Glug! Glug!");
    [0078]   breakHere();                                                       // Engine Tick
    [0079]   unless (VAR_HAVE_MSG == 0) goto 0078;                              //  wait for text
    [007E]   delay(180);                                                        //  Sleep 3 seconds
    [0082] }
    [0082] if (Var[76] == 3) {                                                  // Death by Weird Ed?
    [0087]   stopScript(83);                                                    //  stop Weird Ed: Check for hostile actors
    [0089]   breakHere();                                                       // Engine Tick
    [008A]   unless (VAR_HAVE_MSG == 0) goto 0089;                              //  Wait for Ed
    [008F]   print(11,"Wait! What IS that?");
    [00A2]   breakHere();                                                       // Engine Tick
    [00A3]   unless (VAR_HAVE_MSG == 0) goto 00A2;                              //  Wait for Ed
    [00A8]   print(11,"It has bits of fur like my hamster's!");
    [00C9]   breakHere();                                                       // Engine Tick
    [00CA]   unless (VAR_HAVE_MSG == 0) goto 00C9;                              //  Wait for Ed
    [00CF]   print(11,"Oh no!!! What did you do!!! Argh!!!");
    [00EF]   breakHere();                                                       // Engine Tick
    [00F0]   unless (VAR_HAVE_MSG == 0) goto 00EF;                              //  Wait for Ed
    [00F5]   Var[77] = VAR_EGO;
    [00F8] }
    [00F8] if (Var[76] == 6) {                                                  // Death by Plant?
    [00FD]   Var[77] = VAR_EGO;
    [0100]   loadRoom(27);                                                      //  Enter Plant Room
    [0102]   setCameraAt(28);                                                   //  Camera to right of room
    [0104]   delay(120);                                                        //  Sleep 2 seconds
    [0108]   print(255,"YUM!!");
    [0110]   delay(180);                                                        //  Sleep 3 seconds
    [0114] }
    [0114] if (Var[76] == 4) {                                                  // Death by Tentacle?
    [0119]   breakHere();                                                       // Engine Tick
    [011A]   unless (VAR_HAVE_MSG == 0) goto 0119;                              //  Sleep until talking finishes
    [011F]   Var[77] = VAR_EGO;
    [0122] }
    [0122] setActorBitVar(Var[77],128,1);                                       // kActorMiscFlagHide: Kid is invisible (dead or in radiation suit)
    [0126] setActorBitVar(Var[77],64,1);                                        // kActorMiscFlagFreeze Kid Stop moving
    [012A] Var[90] = 253;                                                       // Radiation Suit
    [012D] VAR_RESULT = getObjectOwner(Var[90]);                                // Get owner of object
    [0130] if (VAR_RESULT == Var[77]) {                                         // Owned by current kid?
    [0135]   setOwnerOf(Var[90],0);                                             //  Set owner of item to no-one
    [0138] }
    [0138] Var[90] -= 1;
    [013B] unless (Var[90] == 0) goto 012D;                                     // Loop all pickup-able items
    [0140] Var[78]++;
    [0142] if (Var[77] == 3) {                                                  // Kid is Dave
    [0147]   Var[96] = 1;                                                       //  Is Dave Dead = Yes
    [014A] }
    [014A] if (Var[78] == 1) {                                                  // Kid Death Count == 1
    [014F]   clearState08(29);                                                  // Show Tombstone 1
    [0151]   clearState02(29);                                                  // Show Tombstone 1
    [0153]   putActorInRoom(Var[77],1);
    [0156]   putActor(Var[77],106,60);
    [015A] }
    [015A] if (Var[78] == 2) {                                                  // Kid Death Count == 2
    [015F]   clearState08(30);                                                  // Show Tombstone 2
    [0161]   clearState02(30);                                                  // Show Tombstone 2
    [0163]   putActorInRoom(Var[77],1);
    [0166]   putActor(Var[77],114,60);
    [016A] }
    [016A] if (Var[78] == 3) {                                                  // Kid Death Count == All Died
    [016F]   clearState08(31);                                                  // Show Tombstone 3
    [0171]   clearState02(31);                                                  // Show Tombstone 3
    [0173]   putActorInRoom(Var[77],1);
    [0176]   putActor(Var[77],122,60);
    [017A] }
    [017A] Var[90] = getActorX(Var[77]);                                        // Get Kid X
    [017D] loadRoom(1);                                                         // Enter Outside
    [017F] setCameraAt(Var[90]);                                                // Camera to Actor X
    [0181] delay(360);
    [0185] endcutscene();                                                       // End Cutscene
    [0186] if (Var[78] == 3) {                                                  // Kid Death Count == All Died
    [018B]   startScript(57);                                                   //  start Cutscene: Game Over
    [018D] }
    [018D] cursorCommand( kModeNormal )                                         // Cutscene Mode Normal
    [018F] stopObjectCode();
}


 /**
  * Script 57: Cutscene: Game Over
  */
Script-57 {
    [0000] stopSound(32);
    [0002] delay(60);                                                           // Sleep 1 second
    [0006] unlockCostume("DrFred")
    [0008] unlockSound(60);
    [000A] unlockCostume(20);
    [000C] unlockScript(105);
    [000E] cutscene();                                                          // Start Cutscene
    [000F] loadRoom(47);                                                        // enter Mansion At Distance (Lights On)
    [0011] loadSound(1);
    [0013] loadSound(55);
    [0015] setCameraAt(20);                                                     // Move camera
    [0017] beginOverride();
    {
        [001B] if (Var[78] != 3) {                                                  // All kids not dead?
        [0020]   delay(240);                                                        //  Wait 3 seconds
        [0024]   startSound(69);
        [0026]   setState08(13);                                                    //  Exploded 1
        [0028]   breakHere();                                                       // Engine Tick
        [0029]   setState08(14);                                                    //  Exploded 2
        [002B]   breakHere();                                                       // Engine Tick
        [002C]   setState08(15);                                                    //  Exploded 3
        [002E]   breakHere();                                                       // Engine Tick
        [002F]   clearState08(15);
        [0031]   clearState08(14);
        [0033]   setState08(16);                                                    //  Exploded 4
        [0035]   delay(240);
        [0039] }

        [0039] startMusic(55);                                                      // Start Theme music
        [003B] delay(120);

        [003F] if (Var[78] == 3) {                                                  // Kid Death Count == All Died
        [0044]   print(255,"        All the kids have died./     The rescue attempt has failed./     Sandy is doomed to zombiehood.");
        [0098]   breakHere();                                                       // Engine Tick
        [0099]   unless (VAR_HAVE_MSG == 0) goto 0098;
        [009E]   print(255,"Dr. Fred, still under the evil meteor's%/%influence, is destined to take over the%/%world and a small part of the galaxy./Hope you like purple...heh, heh, heh");
        [0127] } else {
        [012A]   print(255,"         The house and everyone%/         within a 5 mile radius%/           have been destroyed%/       in a massive nuclear meltdown.");
        [0194] }

        [0194] breakHere();                                                         // Engine Tick
        [0195] unless (VAR_HAVE_MSG == 0) goto 0194;

        [019A] Var[90] = 0;
        [019D] if (VAR_IS_SOUND_RUNNING == 0) {
        [01A2]   startMusic(55);                                                    // sound MM Theme
        [01A4] }

        [01A4] delay(300);                                                          // Wait 5 seconds
        [01A8] print(255,"            THE GAME IS OVER");
        [01BE] delay(300);                                                          // Wait 5 seconds
        [01C2] print(255,"        Press f7 to play again.");
        [01DC] unless (Var[90] == 1) goto 019D;                                     // Sleep until F7 pressed
    }

    [01E1] loadRoom(0);
    [01E3] stopMusic();
    [01E4] restart();                                                           // Restart
    [01E5] endcutscene();                                                       // End Cutscene
    [01E6] stopObjectCode();
}


 /**
  * Script 58: Cutscene: Win Game
  */
Script-58 {
    [0000] unlockSound(60);
    [0002] unlockCostume(20);
    [0004] unlockScript(105);
    [0006] unlockScript(3);
    [0008] unlockSound(8);
    [000A] unlockSound(9);
    [000C] putActorInRoom(8,0);                                                 // Radiation Suit leaves
    [000F] putActor(8,0,0);
    [0013] cutscene();                                                          // Start Cutscene
    [0014] beginOverride();
    {
        [0018] loadRoom(0);
        [001A] loadSound(1);
        [001C] lockSound(1);
        [001E] loadSound(55);
        [0020] lockSound(55);

        [0022] Var[90] = 8;                                                         // All kids are leaving the room
        [0025] putActorInRoom(Var[90],0);                                           //  Kid leaves room
        [0028] putActor(Var[90],0,0);
        [002C] Var[90] -= 1;                                                        //  next kid
        [002F] unless (Var[90] == 0) goto 0025;                                     // Loop all kids

        [0034] Var[91] = 253;
        [0037] VAR_RESULT = getObjectOwner(Var[91]);                                //  Get Owner of Object
        [003A] if (VAR_RESULT != 15) {                                              //  if not Meteor police
        [003F]   setOwnerOf(Var[91],0);                                             //   clear owner
        [0042] }
        [0042] Var[91] -= 1;
        [0045] unless (Var[91] == 0) goto 0037;                                     // Loop all objects

        [004A] breakHere();                                                         // Engine Tick
        [004B] breakHere();                                                         // Engine Tick
        [004C] breakHere();                                                         // Engine Tick

        [004D] if (Var[96] == 0) {                                                  // Is Dave Dead
        [0052]   Var[100] = 3;                                                      //  No, Kid = Dave
        [0055] }

        [0055] setActorBitVar(Var[100],128,0);                                      // Clear kActorMiscFlagHide
        [0059] if (Var[82] == 4) {                                                  // if Contract: Accept Content == Given
        [005E]   startScript(119);                                                  //  start Talk Show:  Talking to Meteor

        [0060]   breakHere();                                                       // Engine Tick
        [0061]   VAR_RESULT = isScriptRunning(119);
        [0064]   unless (VAR_RESULT == 0) goto 0060;                                //  sleep until Talk Show:  Talking to Meteor ends

        [0069] } else {

        [006C]   animateActor(9,6,1);                                               // Dr. Fred face camera

        [0070]   if (Var[96] == 1) {                                                // is Is Dave Dead?
        [0075]     putActorInRoom(Var[100],1);                                      //  Yes. Put Kid in Room Front of Mansion
        [0078]     putActor(Var[100],98,64);
        [007C]     animateActor(Var[100],6,1);                                      //  Kid face camera
        [0080]     animateActor(24,6,1);                                            //  Sandy face camera
        [0084]     putActorInRoom(24,1);                                            //  Sandy enters room
        [0087]     putActor(24,94,62);
        [008B]     putActorInRoom(9,1);                                             //  Dr. Fred enters room
        [008E]     putActor(9,86,60);
        [0092]   } else {
        [0095]     putActorInRoom(Var[100],1);                                      //  Kid enters room Front of Mansion
        [0098]     putActor(Var[100],55,40);
        [009C]     animateActor(Var[100],6,1);                                      //  Kid faces camera
        [00A0]     animateActor(24,6,1);                                            //  Sandy faces camera
        [00A4]     putActorInRoom(24,1);                                            //  Sand enters room
        [00A7]     putActor(24,58,40);
        [00AB]     putActorInRoom(9,1);                                             //  Dr Fred enters room
        [00AE]     putActor(9,62,40);
        [00B2]   }
        [00B2]   loadRoom(1);                                                       // Enter Room 1
        [00B4]   actorFollowCamera(Var[100]);                                       // Camera follows Kid

        [00B6]   if (Var[96] == 1) {                                                // is Is Dave Dead?
        [00BB]     delay(120);                                                      //  Yes
        [00BF]     walkActorTo(9,88,60);                                            //  Dr. Fred walks

        [00C3]     print(9,"I'm sorry my mad, insane plan%/%cost your boyfriend his life./How can I repay you for what I've done?");
        [011A]     breakHere();                                                     // Engine Tick
        [011B]     unless (VAR_CHARCOUNT > 30) goto 011A;                           //  Wait til partial text complete
        [0120]     animateActor(Var[100],4,1);                                      //  Kid faces left
        [0124]     breakHere();                                                     // Engine Tick
        [0125]     unless (VAR_HAVE_MSG == 0) goto 0124;                            //  Wait for Dr. Fred to finish

        [012A]     animateActor(24,4,1);                                            //  Sandy Faces Left
        [012E]     delay(120);

        [0132]     print(9,"Hey!! Wait, I could build a machine%/%that would bring him back to life!");
        [0171]     breakHere();                                                     // Engine Tick
        [0172]     unless (VAR_CHARCOUNT > 60) goto 0171;                           //  Wait for partial text
        [0177]     animateActor(24,6,1);                                            //  Sandy face camera
        [017B]     animateActor(Var[100],6,1);                                      //  Kid faces camera
        [017F]     breakHere();                                                     // Engine Tick
        [0180]     unless (VAR_HAVE_MSG == 0) goto 017F;                            //  Wait for text finish

        [0185]     walkActorTo(9,86,80);                                            //  Dr. Fred walks
        [0189]     breakHere();                                                     // Engine Tick
        [018A]     VAR_RESULT = getActorMoving(9);
        [018D]     unless (VAR_RESULT == 2) goto 0189;                              //  Wait for Dr. Fred

        [0192]     print(9,"But that's another story./Ha, ha, ha, ha, ha, ha!!");
        [01BF]     breakHere();                                                     // Engine Tick
        [01C0]     unless (VAR_CHARCOUNT > 28) goto 01BF;                           //  Wait for partial text
        [01C5]     walkActorTo(9,40,80);                                            //  Dr. Fred Walks
        [01C9]     breakHere();                                                     // Engine Tick
        [01CA]     unless (VAR_HAVE_MSG == 0) goto 01C9;                            //  Wait for Dr. Fred speach

        [01CF]     delay(60);                                                       // Sleep 1 second
        [01D3]     print(24,"Great.");                                              //  Sandy not happy
        [01DC]     startMusic(55);                                                  //  MM Theme Start
        [01DE]     delay(120);
        [01E2]   } else {
        [01E5]     delay(60);                                                       // Sleep 1 second
        [01E9]     animateActor(9,4,1);                                             //  Dr. Fred faces left
        [01ED]     print(9,"I'm sorry my mad, insane plan%/%caused you so much trouble./How can I ever repay you for your help?");
        [0242]     breakHere();                                                     // Engine Tick
        [0243]     unless (VAR_CHARCOUNT > 30) goto 0242;                           //  Wait for partial text
        [0248]     animateActor(Var[100],5,1);                                      //  Kid faces right
        [024C]     delay(60);                                                       // Sleep 1 second
        [0250]     animateActor(24,5,1);                                            //  Sandy faces right
        [0254]     breakHere();                                                     // Engine Tick
        [0255]     unless (VAR_HAVE_MSG == 0) goto 0254;                            //  Wait for text

        [025A]     print(Var[100],"Cash would be nice!!");
        [026E]     breakHere();                                                     // Engine Tick
        [026F]     unless (VAR_HAVE_MSG == 0) goto 026E;                            //  Wait for Kid

        [0274]     print(9,"Don't be a tuna head!");
        [0288]     delay(30);
        [028C]     animateActor(Var[100],6,1);                                      //  Kid faces camera
        [0290]     delay(30);
        [0294]     animateActor(24,6,1);                                            //  Sandy faces camera
        [0298]     startMusic(55);                                                  //  MM Theme Start
        [029A]     breakHere();                                                     // Engine Tick
        [029B]     unless (VAR_HAVE_MSG == 0) goto 029A;                            //  Wait for text

        [02A0]     animateActor(9,6,1);                                             //  Dr. Fred faces camera
        [02A4]     delay(60);                                                       // Sleep 1 second
        [02A8]   }
        [02A8] }

        [02A8] loadRoom(0);                                                         // Load room 0
        [02AA] dummyEE();
        [02AB] Var[90] = 0;                                                         // F7 pressed = 0

        [02AE] if (VAR_IS_SOUND_RUNNING == 0) {                                     // Has sound finished?
        [02B3]   startMusic(55);                                                    //  Yes, Start MM Theme
        [02B5] }
        [02B5] print(255,"   Congratulations! You won the game!");
        [02D8] delay(300);                                                          // Wait 5 seconds
        [02DC] print(255,"        Press f7 to play again.");
        [02F6] delay(300);                                                          // Wait 5 seconds
        [02FA] unless (Var[90] == 1) goto 02AE;                                     // Wait for F7
    }
    [02FF] endcutscene();                                                       // End Cutscene
    [0300] stopMusic();
    [0301] restart();
    [0302] stopObjectCode();
}


 /**
  * Script 59: Print "It seems to be turned off"
  */
Script-59 {
    [0000] printEgo("It seems to be turned off.");
    [0017] stopObjectCode();
}


 /**
  * Script 60: Print "The machine is locked"
  */
Script-60 {
    [0000] printEgo("The machine is locked.");
    [0015] stopObjectCode();
}


 /**
  * Script 61: Print "It must require a special key"
  */
Script-61 {
    [0000] printEgo("It must require a special key.");
    [001B] stopObjectCode();
}


 /**
  * Script 62: Print "Its firmly attached to the wall"
  */
Script-62 {
    [0000] printEgo("It's firmly attached to the wall.");
    [001E] stopObjectCode();
}


 /**
  * Script 63: Print "The door is closed"
  */
Script-63 {
    [0000] printEgo("The door is closed.");
    [0012] stopObjectCode();
}


 /**
  * Script 64: Print "The door is locked"
  */
Script-64 {
    [0000] printEgo("The door is locked.");
    [0012] stopObjectCode();
}


 /**
  * Script 65: Print "Its too Heavy"
  */
Script-65 {
    [0000] printEgo("It's too heavy!");
    [000F] stopObjectCode();
}


 /**
  * Script 66: Print "I can't unlock the door with this."
  */
Script-66 {
    [0000] printEgo("I can't unlock the door with this.");
    [001E] stopObjectCode();
}


 /**
  * Script 67: ?? Incomplete/Corrupted ??
  */
Script-67 {
    [0000] setOwnerOf(114,Var[229]);
    [0003] putActor(Var[115],Var[112],Var[101]);
    [0007] stopCurrentScript();
    [0008] setOwnerOf(97,Var[236]);
    [000B] setActorBitVar(101,Var[121],Var[46]);
    [000F] stopObjectCode();
    [0010] stopObjectCode();
    [0011] stopCurrentScript();
    [0012] stopObjectCode();
    [0013] stopObjectCode();
    [0014] setOwnerOf(117,Var[73]);
    [0017] Var[39] = getDist(243,Var[102]);
    [001B] setOwnerOf(114,Var[109]);
    [001E] stopCurrentScript();
    [001F] stopCurrentScript();
    [0020] putActor(116,Var[116],Var[97]);
    [0024] stopCurrentScript();
    [0025] Var[101] = isScriptRunning(228);
    [0028] Var[239] = getDist(116,Var[104]);
    [002C] loadRoomWithEgo(119,97);
    [002F] stopCurrentScript();
    [0030] stopCurrentScript();
    [0031] print_c64(0,"  ");
    [0036] stopObjectCode();
    [0037] stopSound(117);
    [0039] setObjectName(104,"\xE5doo\xF2i\xF3closed.");
    [004A] stopObjectCode();
    [004B] clearState08(0);
    [004D] stopObjectCode();
    [004E] unknown2(117);
    [0050] setObjectName(104,"\xE5doo\xF2i\xF3locked.");
    [0061] stopObjectCode();
    [0062] print(0,"");
    [0065] stopCurrentScript();
    [0066] printEgo("It's too heavy!");
    [0075] stopObjectCode();
    [0076] stopCurrentScript();
    [0077] stopObjectCode();
    [0078] stopObjectCode();
    [0079] walkActorToObject(Var[117],201);
    [007C] stopCurrentScript();
    [007D] putActor(110,Var[39],Var[244]);
    [0081] printEgo("nlock the door with this.");
    [0098] stopObjectCode();
    [0099] animateActor(0,0,103);
    [009D] printEgo("It's empty.");
    [00A9] stopObjectCode();
    [00AA] restart();
    [00AB] stopObjectCode();
    [00AC] stopObjectCode();
    [00AD] unless (!getState04(42)) goto FFFFD680;
    [00B1] unless (getState02(activeObject)) goto FFFFEFDE;
    [00B4] Var[255] = getBitVar(Var[26],Var[112]);
    [00B8] putActor(26,111,18);
    [00BC] startScript(133);
    [00BE] Var[111] = 13;
    [00C1] startScript(133);
    [00C3] Var[111] = 19;
    [00C6] startScript(133);
    [00C8] Var[111] = 26;
    [00CB] startScript(133);
    [00CD] unless (Var[112] == 1) goto 00B2;
    [00D2] if (getState08(124)) {
    [00D6]   goto 00B2;
    [00D9] }
    [00D9] cutscene();                                                          // Start Cutscene
    [00DA] putActorInRoom(9,18);
    [00DD] putActor(9,51,56);
    [00E1] loadRoom(18);
    [00E3] actorFollowCamera(9);
    [00E5] animateActor(9,7,1);
    [00E9] if (!getState08(204)) {
    [00ED]   beginOverride();
    [00F1]   delay(180);                                                        // Sleep 3 seconds
    [00F5]   walkActorToObject(9,168);
    [00F8]   print(9,"I guess the power's out.");
    [010F]   breakHere();                                                       // Engine Tick
    [0110]   unless (VAR_HAVE_MSG == 0) goto 010F;
    [0115]   delay(120);
    [0119] } else {
    [011C]   beginOverride();
    [0120]   startSound(35);
    [0122]   setState08(173);
    [0124]   delay(300);                                                        // Wait 5 seconds
    [0128]   if (VAR_OVERRIDE == 1) {
    [012D]     loadRoom(0);
    [012F]   }
    [012F]   startScript(97);
    [0131] }
    [0131] clearState08(173);
    [0133] print(255," ");
    [0137] stopSound(35);
    [0139] putActorInRoom(9,0);
    [013C] putActor(9,0,0);
    [0140] endcutscene();                                                       // End Cutscene
    [0141] stopObjectCode();
    [0142] printEgo("");
    [0144] stopObjectCode();
    [0145] print(100,"\x02a");
    [014A] stopObjectCode();
    [014B] stopObjectCode();
    [014C] putActorInRoom(0,40);
    [014F] panCameraTo(0);
    [0151] stopObjectCode();
    [0152] stopObjectCode();
    [0153] VAR_EGO = getDist(16,45);
    [0157] stopObjectCode();
    [0158] unless (!Var[18]) goto 015C;
    [015C] stopObjectCode();
    [015D] VAR_EGO = getDist(16,45);
    [0161] stopObjectCode();
    [0162] unless (!Var[18]) goto 0166;
    [0166] stopObjectCode();
    [0167] VAR_EGO = getDist(16,45);
    [016B] stopObjectCode();
    [016C] unless (!Var[18]) goto 0170;
    [0170] stopObjectCode();
    [0171] VAR_EGO = getDist(16,45);
    [0175] stopObjectCode();
    [0176] cutscene();                                                          // Start Cutscene
    [0177] startSound(0);
    [0179] loadCostume(52);
    [017B] setOwnerOf(0,32);
    [017E] putActorInRoom(0,64);
    [0181] stopCurrentScript();
    [0182] stopObjectCode();
    [0183] clearState04();
    [0184] clearState04();
    [0185] stopMusic();
    [0186] pickupObject(16);
    [0188] stopCurrentScript();
    [0189] stopSound(1);
    [018B] putActorInRoom(0,96);
    [018E] doSentence(0,55,119);
    [0192] stopMusic();
    [0193] pickupObject(32);
    [0195] putActorInRoom(0,2);
    [0198] stopCurrentScript();
    [0199] stopObjectCode();
    [019A] stopObjectCode();
    [019B] stopObjectCode();
    [019C] breakHere();                                                         // Engine Tick
    [019D] cursorCommand(Var[32]);
    [019F] stopMusic();
    [01A0] stopObjectCode();
    [01A1] startMusic(0);
    [01A3] stopObjectCode();
    [01A4] stopObjectCode();
    [01A5] putActorInRoom(0,4);
    [01A8] nop();
    [01A9] putActor(0,0,48);
    [01AD] stopScript(16);
    [01AF] breakHere();                                                         // Engine Tick
    [01B0] if (Var[16] <= 0) {
    [01B5]   startMusic(0);
    [01B7]   stopObjectCode();
    [01B8]   stopObjectCode();
    [01B9]   stopObjectCode();
    [01BA]   stopObjectCode();
    [01BB]   stopObjectCode();
    [01BC]   stopObjectCode();
    [01BD]   stopObjectCode();
    [01BE]   stopObjectCode();
    [01BF]   stopObjectCode();
    [01C0]   stopObjectCode();
    [01C1]   stopObjectCode();
    [01C2]   stopObjectCode();
    [01C3]   stopObjectCode();
    [01C4]   stopObjectCode();
    [01C5]   stopObjectCode();
    [01C6]   stopObjectCode();
    [01C7]   stopObjectCode();
    [01C8]   stopObjectCode();
    [01C9]   stopObjectCode();
    [01CA]   stopObjectCode();
    [01CB]   stopObjectCode();
    [01CC]   stopObjectCode();
    [01CD]   stopObjectCode();
    [01CE]   stopObjectCode();
    [01CF]   stopObjectCode();
    [01D0]   stopObjectCode();
    [01D1]   stopObjectCode();
    [01D2]   stopObjectCode();
    [01D3]   stopObjectCode();
    [01D4]   stopObjectCode();
    [01D5] }
    [01D5] stopObjectCode();
                                                                                //<SNIP>
    [656D] stopObjectCode();
}


 /**
  * Script 68: Print "Its Empty"
  */
Script-68 {
    [0000] printEgo("It's empty.");
    [000C] stopObjectCode();
}


 /**
  * Script 69: Microwave:
  */
Script-69 {
    [0000] if (getState08(activeObject)) {
    [0003]   clearState08();
    [0004] }
    [0004] if (getState08(124)) {                                               // Circuit Breaker
    [0008]   printEgo("The power's off.");
    [0018] } else if (getState08(54)) {                                         // Hamster is exploded
    [001F]   printEgo("It's already cooked!");
    [0033] } else {
    [0036]   if (Var[66] == 0) {                                                // Empty Microwave
    [003B]     printEgo("I shouldn't turn on an empty microwave.");
    [005E]   }
    [005E]   if (Var[66] == 1) {                                                // Hamster in Microwave
    [0063]     startScript(11);                                                 // start Hamster: In Microwave
    [0065]   }
    [0065]   if (Var[66] == 2) {                                                // Envelope in, but no liquid
    [006A]     printEgo("I need some liquid in here first.");
    [0087]   }
    [0087]   if (Var[66] > 2) {                                                 // Envelope + Water
    [008C]     startScript(53);                                                 // start Microwave
    [008E]   }
    [008E] }
    [008E] stopObjectCode();
}


 /**
  * Script 70: Pool Water Valve
  */
Script-70 {
    [0000] cursorCommand( kModeNoNewKid )                                       // Disable New Kid verb
    [0002] startSound(43);                                                      // Sound Water Drain
    [0004] delay(120);                                                          // Wait 2 seconds
    [0008] cursorCommand( kModeNormal )                                         // Cutscene Mode Normal
    [000A] startSound(17);
    [000C] if (getState08(33)) {                                                // if valve is open
    [0010]   setState08(106);                                                   // Game: Meltdown Timer
    [0012]   clearState02(139);                                                 // Pool-Ladder remove kObjectStateUntouchable
    [0014]   VAR_RESULT = isScriptRunning(6);                                   // is Game: Meltdown Timer running?
    [0017]   if (VAR_RESULT == 0) {
    [001C]     startScript(6);                                                  // start Game: Meltdown Timer
    [001E]   }
    [001E] } else {
    [0021]   clearState08(106);                                                 // Pool is full
    [0023]   if (!getState08(124)) {                                            // if power on
    [0027]     startScript(7);                                                  //  start Game: Meltdown Stop
    [0029]   }
    [0029]   setState02(139);                                                   // Pool-Ladder add kObjectStateUntouchable
    [002B]   Var[77] = 7;                                                       // Find all kids in Bottom of Pool
    [002E]   VAR_RESULT = getActorRoom(Var[77]);
    [0031]   if (VAR_RESULT == 2) {                                             // is kid at Bottom of Pool
    [0036]     Var[76] = 2;                                                     //  Killed by pool
    [0039]     startScript(56);                                                 //  Cutscene: Kid Dies
    [003B]   }
    [003B]   breakHere();                                                       // Engine Tick
    [003C]   VAR_RESULT = isScriptRunning(56);
    [003F]   unless (VAR_RESULT == 0) goto 003B;                                // Wait for script 56 to finish
    [0044]   Var[77] -= 1;
    [0047]   unless (Var[77] == 0) goto 002E;                                   // Loop for all kids
    [004C] }
    [004C] delay(300);                                                          // Wait 5 seconds
    [0050] stopSound(17);
    [0052] stopObjectCode();
}


 /**
  * Script 71: Film: Expose
  */
Script-71 {
    [0000] if (Var[11] == 1) {                                                  // if Film Exposed == Yes
    [0005]   printEgo("It's already opened.");
    [0019] }
    [0019] if (Var[11] == 0) {                                                  // if Film Exposed == No
    [001E]   printEgo("Ok, it's opened.");
    [002E]   breakHere();                                                       // Engine Tick
    [002F]   unless (VAR_HAVE_MSG == 0) goto 002E;                              // Sleep while talking
    [0034]   Var[90] = getObjectOwner(23);                                      // Owner of Undeveloped Film
    [0037]   if (Var[90] == 0) {
    [003C]     stopScript(0);                                                   // Stop if no owner
    [003E]   }
    [003E]   Var[91] = getActorRoom(Var[90]);                                   // Get owner of film room
    [0041]   VAR_RESULT = getBitVar(Var[91],1);                                 //  is Dark Room ??
    [0045]   if (VAR_RESULT == 0) {                                             //
    [004A]     if (!getState08(124)) {                                          //   Power On?
    [004E]       if (VAR_ROOM == Var[91]) {                                     //    room == kid current room?
    [0053]         printEgo("I think I just exposed the film.");
    [006F]       }
    [006F]       Var[11] = 1;
    [0072]     }
    [0072]   }
    [0072]   delay(900);                                                        // Sleep 15 seconds
    [0076]   unless (Var[11] != 0) goto 0034;                                   // Sleep until current room == film owner room
    [007B] }
    [007B] stopObjectCode();
}


 /**
  * Script 72: Film: Develop
  */
Script-72 {
    [0000] if (getState08(124)) {                                               // Power is off?
    [0004]   printEgo("The power's off.");
    [0014] } else if (VAR_EGO == 4) {                                           // Kid is Michael?
    [001C]   if (Var[27] >= 3) {                                                // if Developer Tray Contents == Developer
    [0021]     cursorCommand( kModeCutscene )                                   // Cutscene Mode
    [0023]     if (getState08(182)) {                                           // Is door open?
    [0027]       walkActorToObject(VAR_EGO,182);                                // Walk Michael to door
    [002A]       breakHere();                                                   // Engine Tick
    [002B]       VAR_RESULT = getActorMoving(VAR_EGO);
    [002E]       unless (VAR_RESULT == 2) goto 002A;                            // Wait for Michael
    [0033]       clearState08(182);                                             // Close door
    [0035]       startSound(9);                                                 // sound Door closing
    [0037]       breakHere();                                                   // Engine Tick
    [0038]     }
    [0038]     walkActorToObject(VAR_EGO,127);                                  // Walk Michael to Developer Tray
    [003B]     breakHere();                                                     // Engine Tick
    [003C]     VAR_RESULT = getActorMoving(VAR_EGO);
    [003F]     unless (VAR_RESULT == 2) goto 003B;                              // Wait for Michael
    [0044]     Var[90] = 2;
    [0047]     startSound(41);                                                  // start sound Liquid
    [0049]     delay(120);
    [004D]     stopSound(41);                                                   // stop sound Liquid
    [004F]     walkActorToObject(VAR_EGO,126);                                  // Walk Michael to Enlarger
    [0052]     breakHere();                                                     // Engine Tick
    [0053]     VAR_RESULT = getActorMoving(VAR_EGO);
    [0056]     unless (VAR_RESULT == 2) goto 0052;                              // Wait for Michael
    [005B]     animateActor(VAR_EGO,6,1);                                       // Michael faces camera
    [005F]     delay(120);
    [0063]     walkActorToObject(VAR_EGO,127);                                  // Michael walks to Developer Tray
    [0066]     breakHere();                                                     // Engine Tick
    [0067]     VAR_RESULT = getActorMoving(VAR_EGO);
    [006A]     unless (VAR_RESULT == 2) goto 0066;
    [006F]     animateActor(VAR_EGO,6,1);                                       // Michael faces camera
    [0073]     breakHere();                                                     // Engine Tick
    [0074]     Var[90] -= 1;
    [0077]     unless (Var[90] == 0) goto 0047;                                 // Repeat 3 times
    [007C]     setObjectName(23,"prints");                                      // Undeveloped Film becomes prints
    [0085]     if (Var[11] == 1) {                                              // if Film Exposed
    [008A]       goto 0095;
    [008D]     } else if (Var[27] == 4) {                                       // or Developer Ruined
    [0095]       printEgo("Nobody's going to want ruined prints!");
    [00B7]       Var[11] = 2;                                                   // Film Exposed = Prints Ruined
    [00BA]     } else {                                                         // Otherwise
    [00BD]       printEgo("Perfect!");
    [00C7]       Var[11] = 3;                                                   // Film Exposed = Prints Perfect
    [00CA]     }
    [00CA]     cursorCommand( kModeNormal )                                     // Cutscene Mode Normal
    [00CC]   } else if (Var[27] == 0) {                                         // Developer Tray Contents == Empty
    [00D4]     printEgo("I need some developer solution first.");
    [00F6]   } else {                                                           // Developer Tray Contents == Water
    [00F9]     printEgo("Water's not going to work!");
    [0111]   }
    [0111] } else {                                                             // Not Michael?
    [0114]   printEgo("I don't know how.");
    [0124] }
    [0124] stopObjectCode();
}


 /**
  * Script 73: Facet: Fill Gar/Sponge with Water
  */
Script-73 {
    [0000] if (activeObject2 == 90) {                                           // if Sponge
    [0004]   Var[24] = 1;                                                       // Sponge Contents = water
    [0007]   startScript(75);                                                   // start Glass Jar: Name
    [0009] }
    [0009] if (activeObject2 == 99) {                                           // if Glass Jar
    [000D]   Var[22] = 1;                                                       // Glass Jar Contents = water
    [0010]   startScript(74);                                                   // start Sponge: Name
    [0012] }
    [0012] stopObjectCode();
}


 /**
  * Script 74: Glass Jar: Name
  */
Script-74 {
    [0000] if (Var[22] == 0) {                                                  // Glass Jar Contents == Empty
    [0005]   setObjectName(99,"glass jar");
    [0011] }
    [0011] if (Var[22] == 2) {                                                  // Glass Jar Contents == water
    [0016] } else {
    [0019]   unless (Var[22] == 1) goto 002D;
    [001E] }
    [001E] setObjectName(99,"jar of water");
    [002D] if (Var[22] == 3) {                                                  // Glass Jar Contents == Developer
    [0032]   setObjectName(99,"jar of developer");
    [0045] }
    [0045] stopObjectCode();
}


 /**
  * Script 75: Sponge: Name
  */
Script-75 {
    [0000] if (Var[24] == 0) {                                                  // Sponge Contents == Empty
    [0005]   setObjectName(90,"sponge");
    [000E] }
    [000E] if (Var[24] == 2) {                                                  // Sponge Contents == water
    [0013] } else {
    [0016]   unless (Var[24] == 1) goto 002F;
    [001B] }
    [001B] setObjectName(90,"sponge with water");
    [002F] if (Var[24] == 3) {                                                  // Sponge Contents == Developer
    [0034]   setObjectName(90,"sponge with developer");
    [004C] }
    [004C] stopObjectCode();
}


 /**
  * Script 76: Jar / Envelop: Name
  */
Script-76 {
    [0000] if (Var[22] == 2) {                                                  // Glass Jar Contents == water
    [0005] } else {
    [0008]   unless (Var[22] == 1) goto 001C;
    [000D] }
    [000D] setObjectName(50,"jar of water");
    [001C] if (Var[22] == 3) {                                                  // Glass Jar Contents == Developer
    [0021]   setObjectName(50,"jar of developer");
    [0034] }
    [0034] if (Var[62] == 1) {                                                  // Stamp Stickyness == Sticky
    [0039]   setObjectName(234,"envelope");
    [0044] }
    [0044] if (Var[64] == 1) {                                                  // Envelop Stamped == Stamped
    [0049]   setObjectName(234,"stamped envelope");
    [005C] }
    [005C] stopObjectCode();
}


 /**
  * Script 77: Flashlight: Name
  */
Script-77 {
    [0000] if (Var[12] == 1) {                                                  // if Flashlight Status == On
    [0005]   setObjectName(51,"lit flashlight");
    [0016] } else {
    [0019]   setObjectName(51,"flashlight");
    [0026] }
    [0026] startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    [0028] stopObjectCode();
}


 /**
  * Script 78: DeveloperTray: Name
  */
Script-78 {
    [0000] if (Var[27] == 0) {                                                  // Developer Tray Contents == Empty
    [0005]   setObjectName(127,"developer tray");
    [0016] }
    [0016] if (Var[27] == 2) {                                                  // Developer Tray Contents == water
    [001B] } else {
    [001E]   unless (Var[27] == 1) goto 0033;
    [0023] }
    [0023] setObjectName(127,"tray of water");
    [0033] if (Var[27] == 3) {                                                  // Developer Tray Contents == Developer
    [0038]   setObjectName(127,"tray of developer");
    [004C] }
    [004C] stopObjectCode();
}


 /**
  * Script 79: Envelope: Name
  */
Script-79 {
    [0000] if (Var[62] == 2) {                                                  // if Stamp Stickyness == Ripped
    [0005]   setObjectName(201,"ripped envelope");
    [0017] }
    [0017] if (Var[62] == 1) {                                                  // Stamp Stickyness == Sticky
    [001C]   setObjectName(201,"envelope");
    [0027]   if (Var[63] == 1) {                                                // Envelop Contents == Memoir
    [002C]     setObjectName(201,"memoir in envelope");
    [0041]     if (Var[64] == 1) {                                              // Envelop Stamped == Yes
    [0046]       setObjectName(201,"memoir in stamped envelope");
    [0063]     }
    [0063]   } else if (Var[63] >= 2) {                                         // Envelop Contents == Tape
    [006B]     setObjectName(201,"tape in envelope");
    [007E]     if (Var[64] == 1) {                                              // Enveloped Stamped == Yes
    [0083]       setObjectName(201,"tape in stamped envelope");
    [009E]     }
    [009E]   } else if (Var[64] == 1) {                                         // Enveloped Stamped == Yes
    [00A6]     setObjectName(201,"stamped envelope");
    [00B9]   }
    [00B9] }
    [00B9] stopObjectCode();
}


 /**
  * Script 80: Envelope: Open
  */
Script-80 {
    [0000] if (Var[63] == 1) {                                                  // Envelop Contents == Memoir
    [0005]   printEgo("The manuscript is sealed inside.");
    [0023] } else if (Var[63] >= 2) {                                           // Envelop Contents == Tape
    [002B]   printEgo("The cassette is sealed inside.");
    [0047] } else if (Var[65] == 1) {                                           // Envelop Opened == Yes
    [004F]   printEgo("It was already opened.");
    [0064] } else {
    [0067]   if (Var[62] == 0) {                                                // if Stamp Stickyness == Not Sticky
    [006C]     Var[62] = 2;                                                     // Stamp Stickyness = Ripped
    [006F]   }
    [006F]   Var[65] = 1;                                                       // Envelop Opened = Yes
    [0072]   startScript(79);                                                   // start Envelope: Name
    [0074]   delay(60);                                                         // Sleep 1 second
    [0078]   setOwnerOf(200,VAR_EGO);                                           // Set owner of Quater to Kid
    [007B]   printEgo("There was a quarter inside the envelope.");
    [009F] }
    [009F] stopObjectCode();
}


 /**
  * Script 81: Envelope: Use
  */
Script-81 {
    [0000] if (activeObject2 == 177) {                                          // Use with Manuscript or Cassette Tape
    [0004] } else {
    [0007]   unless (activeObject2 == 156) goto 006F;                           //
    [000B] }
    [000B] if (Var[65] == 1) {                                                  // Envelop Opened?
    [0010]   if (Var[62] == 2) {                                                //  Ripped?
    [0015]     printEgo("The envelope's unusable.");
    [002D]   } else if (Var[63] == 0) {                                         // Envelop Contents == Empty
    [0035]     if (activeObject2 == 177) {                                      //  Use with Manuscript?
    [0039]       Var[63] = 1;                                                   //   Envelop Contents = Memoir
    [003C]       setOwnerOf(177,0);                                             //   Remove manuscript
    [003F]     } else if (activeObject2 == 156) {                               //  Use with Cassette Tape
    [0046]       Var[63] = 2;                                                   //   Envelop Contents = Tape
    [0049]       setOwnerOf(156,0);                                             //   Remove Tape
    [004C]     }
    [004C]     startScript(79);                                                 // start Envelope: Name
    [004E]   } else {
    [0051]     startScript(80);                                                 // start Envelope: Open
    [0053]   }
    [0053] } else {
    [0056]   printEgo("The envelope is closed.");
    [006C] }
    [006C] goto 0073;
    [006F] doSentence(11,255,254);                                              // Verb 11
    [0073] stopObjectCode();
}


 /**
  * Script 82: Weird Ed: Leave Room
  */
Script-82 {
    [0000] delay(180);                                                          // Sleep 3 seconds
    [0004] if (Var[127] == 2) {                                                 // if Weird Ed Trigger == Cheese
    [0009]   delay(3600);                                                       //  Sleep 1 minute
    [000D]   if (Var[80] == 1) {                                                //  Green Tentacle: Has drank == Yes
    [0012]     stopScript(0);                                                   //   Stop
    [0014]   }
    [0014]   VAR_RESULT = getActorRoom("Weird Ed");
    [0017]   unless (VAR_RESULT == 26) goto 0009;                               // Wait for Ed to be in his room
    [001C] }
    [001C] cutscene();                                                          // Start Cutscene
    [001D] loadRoom(26);                                                        // Enter Weird Ed's Room
    [001F] setCameraAt(25);                                                     // Set Camera
    [0021] breakHere();                                                         // Engine Tick
    [0022] beginOverride();
    {
        [0026] if (Var[127] != 2) {                                                 // if Weird Ed Trigger != Cheese
        [002B]   if (Var[68] == 0) {                                                //  if Weird Ed: Has responded to Door Bell == No
        [0030]     print(11,"Oh, the doorbell!");
        [0042]     breakHere();                                                     // Engine Tick
        [0043]     unless (VAR_HAVE_MSG == 0) goto 0042;                            //  Wait for Weird Ed
        [0048]     walkActorToObject(11,6);                                         //  Walk Weird Ed to door
        [004B]     print(11,"I wonder if that's my package?");
        [0067]     Var[68] = 1;                                                     //  Weird Ed: Has responded to Door Bell = Yes
        [006A]   } else {
        [006D]     print(11,"Again?");
        [0076]   }
        [0076] } else {
        [0079]   print(11,"Gee, I'm hungry!");
        [008A] }
        [008A] walkActorToObject(11,6);                                             // Walk Weird Ed to DOor
        [008D] breakHere();                                                         // Engine Tick
        [008E] VAR_RESULT = getActorMoving(11);
        [0091] unless (VAR_RESULT == 2) goto 008D;                                  // Wait for Weird Ed

        [0096] animateActor(11,7,1);                                                // Weird Ed face away
        [009A] breakHere();                                                         // Engine Tick
        [009B] breakHere();                                                         // Engine Tick
        [009C] unless (VAR_HAVE_MSG == 0) goto 009B;                                // Wait for Weird Ed

        [00A1] if (!getState08(6)) {                                                // Door closed?
        [00A5]   setState08(6);                                                     //  Open Door
        [00A7]   startSound(8);                                                     //  Sound Door Open
        [00A9]   delay(60);                                                         // Sleep 1 second
        [00AD] }
    }

    [00AD] if (VAR_OVERRIDE == 1) {
    [00B2]   loadRoom(0);
    [00B4] }

    [00B4] VAR_RESULT = getActorRoom(10);
    [00B7] if (VAR_RESULT == 38) {                                              // Nurse Edna in Level3 Hallway?
    [00BC]   stopScript(34);                                                    //  stop Nurse Edna: Return to room (Enter Room)
    [00BE]   putActorInRoom(10,19);                                             //  Nurse Edna enteres Nurse Ednas room
    [00C1]   putActor(10,4,52);
    [00C5] }

    [00C5] print(255," ");

    [00C9] putActorInRoom(11,38);                                               // Weird Ed enters Level 3 Hallway
    [00CC] putActor(11,44,52);

    [00D0] Var[69] = 44;                                                        // Weird Ed: ? = Level 3 Hallway
    [00D3] Var[70] = 52;                                                        // Weird Ed: ? = Level 3 Hallway

    [00D6] if (VAR_OVERRIDE == 0) {
    [00DB]   startSound(9);
    [00DD] }

    [00DD] clearState08(6);                                                     // Close Weird Ed door
    [00DF] clearState08(186);                                                   // Close Weird Ed door

    [00E1] if (VAR_OVERRIDE == 0) {
    [00E6]   delay(90);
    [00EA] }
    [00EA] endcutscene();                                                       // End Cutscene

    [00EB] startScript(86);                                                     // start Weird Ed: Check for friendly actors
    [00ED] Var[71] = 7;                                                         //  Target X
    [00F0] Var[72] = 60;                                                        //  Target Y
    [00F3] delay(300);                                                          // Wait 5 seconds
    [00F7] breakHere();                                                         // Engine Tick
    [00F8] unless (Var[102] == 0) goto 00F7;                                    // Until Weird Ed: Actor found nearby == No

    [00FD] putActorInRoom(11,12);                                               // Weird Ed enters Level 2 Stairs to Level 3
    [0100] putActor(11,9,8);
    [0104] Var[69] = 9;
    [0107] Var[70] = 8;
    [010A] Var[71] = 53;                                                        //  Target X
    [010D] Var[72] = 56;                                                        //  Target Y
    [0110] delay(300);                                                          // Wait 5 seconds
    [0114] breakHere();                                                         // Engine Tick
    [0115] unless (Var[102] == 0) goto 0114;                                    // Until Weird Ed: Actor found nearby == No

    [011A] putActorInRoom(11,13);                                               // Weird Ed enters Level 2 Main Hallway
    [011D] putActor(11,70,12);
    [0121] Var[69] = 70;
    [0124] Var[70] = 12;
    [0127] Var[71] = 15;                                                        //  Target X
    [012A] Var[72] = 52;                                                        //  Target Y
    [012D] delay(300);                                                          // Wait 5 seconds
    [0131] breakHere();                                                         // Engine Tick
    [0132] unless (Var[102] == 0) goto 0131;                                    // Until Weird Ed: Actor found nearby == No

    [0137] setState08(160);
    [0139] setState08(149);
    [013B] putActorInRoom(11,11);                                               // Weird Ed enters Top of Main Entry
    [013E] putActor(11,36,48);
    [0142] Var[69] = 36;
    [0145] Var[70] = 48;
    [0148] Var[71] = 39;                                                        //  Target X
    [014B] Var[72] = 64;                                                        //  Target Y
    [014E] delay(300);                                                          // Wait 5 seconds
    [0152] breakHere();                                                         // Engine Tick
    [0153] unless (Var[102] == 0) goto 0152;                                    // Until Weird Ed: Actor found nearby == No

    [0158] putActorInRoom(11,10);                                               // Weird Ed enters Main Entry
    [015B] putActor(11,41,8);
    [015F] Var[69] = 41;
    [0162] Var[70] = 8;
    [0165] if (Var[127] == 1) {                                                 // if Weird Ed Trigger == DoorBell
    [016A]   Var[71] = 6;                                                       //  Target X
    [016D]   Var[72] = 60;                                                      //  Target Y
    [0170]   delay(300);                                                        // Wait 5 seconds
    [0174]   breakHere();                                                       // Engine Tick
    [0175]   unless (Var[102] == 0) goto 0174;                                  // Until Weird Ed: Actor found nearby == No

    [017A]   startScript(90);                                                   // start Weird Ed: Check Front Door
    [017C] } else {
    [017F]   startScript(146);                                                  // start Weird Ed: Check Fridge
    [0181] }
    [0181] stopScript(92);                                                      // stop Weird Ed: Help Find Plans
    [0183] stopObjectCode();
}


 /**
  * Script 83: Weird Ed: Check for hostile actors
  */
Script-83 {
    [0000] VAR_RESULT = getActorRoom("Weird Ed");
    [0003] if (VAR_RESULT == 12) {                                              // Weird Ed in Level 2 Stairs to Level 3?
    [0008]   Var[86] = 0;
    [000B]   stopScript(45);                                                    // stop Green Tentacle: Block until player feeds
    [000D] }

    [000D] VAR_RESULT = getActorRoom(Var[94]);
    [0010] if (VAR_RESULT == VAR_ROOM) {                                        // Kid in current room

    [0015]   VAR_RESULT = getActorBitVar(Var[94],8);
    [0019]   if (VAR_RESULT == 1) {                                             // Kid has kActorMiscFlagEdsEnemy
    [001E]     print(11,"You have some nerve%/%coming back here again!");
    [0048]   } else {
    [004B]     print(11,"Intruder, halt!");
    [005C]   }

    [005C]   breakHere();                                                       // Engine Tick
    [005D]   Var[94] = getClosestObjActor7(11);                                 // Get closest actor
    [0060]   if (Var[94] == 255) {                                              //  None?
    [0065]     startScript(93);                                                 //  Weird Ed: Walk Hallway
    [0067]     stopScript(0);                                                   //  stop
    [0069]   }
    [0069]   walkActorToActor(11,Var[94],2);                                    // Walk to kid
    [006D]   VAR_RESULT = getDist(11,Var[94]);
    [0071]   unless (VAR_RESULT <= 2) goto 005C;                                // Wait until < 2 distance

    [0076]   animateActor(Var[94],255,1);                                       // Kid mouth open
    [007A]   animateActor(Var[94],6,1);                                         // Kid face camera
    [007E]   setActorBitVar(Var[94],64,1);                                      // Kid has kActorMiscFlagFreeze
    [0082]   breakHere();                                                       // Engine Tick
    [0083]   unless (VAR_HAVE_MSG == 0) goto 0082;                              // Wait for Weird Ed

    [0088]   breakHere();                                                       // Engine Tick
    [0089]   VAR_RESULT = getActorMoving(11);
    [008C]   unless (VAR_RESULT == 2) goto 0088;                                // wait for Weird Ed

    [0091]   animateActor(11,6,1);                                              // Weird Ed face camera
    [0095]   print(11,"What are you doing in my house?/Are you an agent of the evil meteor%/%or are you here to help me defeat him?");
    [00EF]   breakHere();                                                       // Engine Tick
    [00F0]   unless (VAR_HAVE_MSG == 0) goto 00EF;                              // wait for Weird Ed

    [00F5]   print(11,"Not talking, eh?/Well to the dungeon, spy!");
    [011C]   breakHere();                                                       // Engine Tick
    [011D]   unless (VAR_HAVE_MSG == 0) goto 011C;                              // wait for Weird Ed

    [0122]   delay(120);
    [0126] } else {
    [0129]   breakHere();                                                       // Engine Tick
    [012A]   cutscene();                                                        // Start Cutscene
    [012B]   Var[92] = getActorRoom(Var[94]);                                   // Get Kid room
    [012E]   loadRoom(Var[92]);                                                 // enter room
    [0130]   actorFollowCamera(11);                                             // camera follows Weird Ed

    [0132]   walkActorToActor(11,Var[94],2);                                    // Walk Weird Ed to Kid
    [0136]   breakHere();                                                       // Engine Tick
    [0137]   breakHere();                                                       // Engine Tick
    [0138]   VAR_RESULT = getActorMoving(11);
    [013B]   unless (VAR_RESULT == 2) goto 0137;                                // Wait for Weird Ed

    [0140]   animateActor(11,6,1);                                              // Weird Ed face camera
    [0144]   animateActor(Var[94],6,1);                                         // Kid face camera
    [0148]   print(11,"I got you! To the dungeon, intruder!");
    [0169]   breakHere();                                                       // Engine Tick
    [016A]   unless (VAR_HAVE_MSG == 0) goto 0169;                              // wait for text

    [016F]   delay(60);                                                         // Sleep 1 second
    [0173]   endcutscene();                                                     // End Cutscene
    [0174] }
    [0174] startScript(84);                                                     // start Weird Ed: Check for hostile actors
    [0176] stopObjectCode();
}


 /**
  * Script 84: Weird Ed: Take kid to dungeon
  */
Script-84 {
    [0000] cutscene();                                                          // Start Cutscene
    [0001] beginOverride();
    {
        [0005] setState08(126);                                                     // Open dungeon door
        [0007] Var[90] = Var[94];
        [000A] startScript(141);                                                    // start Dungeon: Calculate Kid Position

        [000C] putActorInRoom(Var[94],4);                                           // Put kid in dungeon
        [000F] putActor(Var[94],Var[91],63);
        [0013] animateActor(Var[94],5,1);                                           // Kid faces right

        [0017] putActorInRoom(11,4);                                                // Put Weird Ed in dungeon
        [001A] putActor(11,61,63);
        [001E] animateActor(11,4,1);                                                // Weird Ed faces left
        [0022] loadRoom(4);                                                         // Enter Dungeon
        [0024] setCameraAt(90);
        [0026] delay(120);

        [002A] print(11,"Too bad you weren't on my side!");
        [0046] breakHere();                                                         // Engine Tick
        [0047] unless (VAR_HAVE_MSG == 0) goto 0046;                                // Wait for Weird Ed

        [004C] walkActorToObject(11,126);                                           // Walk Weird Ed to door
        [004F] breakHere();                                                         // Engine Tick
        [0050] VAR_RESULT = getActorMoving(11);
        [0053] unless (VAR_RESULT == 2) goto 004F;                                  // Wait for Weird Ed

        [0058] print(255," ");
    }
    [005C] putActorInRoom(11,0);                                                // Weird Ed leaves
    [005F] putActor(11,0,0);

    [0063] startScript(51);                                                     // start Dungeon: Close Entry Door
    [0065] delay(120);

    [0069] endcutscene();                                                       // End Cutscene
    [006A] startScript(93);                                                     // start Weird Ed: Walk Hallway
    [006C] stopObjectCode();
}


 /**
  * Script 85: Weird Ed: Thanks for package
  */
Script-85 {
    [0000] breakHere();                                                         // Engine Tick
    [0001] unless (VAR_HAVE_MSG == 0) goto 0000;                                // Wait for Weird Ed

    [0006] breakHere();                                                         // Engine Tick
    [0007] Var[94] = getClosestObjActor7(11);                                   // Find nearby Kid
    [000A] VAR_RESULT = getDist(11,Var[94]);
    [000E] unless (VAR_RESULT < 20) goto 0006;                                  // Wait while distance >= 20

    [0013] print(11,"Thanks for delivering my package!");
    [0033] stopObjectCode();
}


 /**
  * Script 86: Weird Ed: Check for friendly actors
  */
Script-86 {
    [0000] Var[121] = 0;
    [0003] loadScript(83);
    [0005] Var[102] = 0;                                                        // Weird Ed: Actor found nearby = No
    [0008] Var[94] = getClosestObjActor7(11);
    [000B] if (Var[94] != 255) {
    [0010]   Var[102] = 1;                                                      // Weird Ed: Actor found nearby = Yes
    [0013]   VAR_RESULT = getActorRoom("Weird Ed");
    [0016]   if (VAR_RESULT == VAR_ROOM) {
    [001B]     Var[94] = VAR_EGO;                                               //
    [001E]   }
    [001E]   if (Var[73] == 1) {                                                // Door Bell Triggers Ed == Yes
    [0023]     VAR_RESULT = getActorBitVar(Var[94],8);                          //
    [0027]     if (VAR_RESULT == 0) {
    [002C]       VAR_RESULT = getActorRoom("Weird Ed");
    [002F]       if (VAR_RESULT == VAR_ROOM) {                                  // Weird Ed in current room?
    [0034]         if (Var[121] != VAR_ROOM) {
    [0039]           Var[121] = VAR_ROOM;
    [003C]           breakHere();                                               // Engine Tick
    [003D]           walkActorToActor(11,Var[94],6);                            // Walk Weird Ed to kid
    [0041]           delay(60);                                                 // Sleep 1 second
    [0045]           print(11,"Hello.");
    [004E]           breakHere();                                               // Engine Tick
    [004F]           unless (VAR_HAVE_MSG == 0) goto 004E;                      // Wait for Weird Ed

    [0054]           if (Var[74] == 0) {                                        // if Weird Ed: Should storm lab == No
    [0059]             print(11,"Come see me when you have the plans.");
    [0079]           } else {
    [007C]             print(11,"Getting ready for the big raid?");
    [0099]           }
    [0099]         }
    [0099]       }

    [0099]       VAR_RESULT = isScriptRunning(82);                              // is Weird Ed: Leave Room running
    [009C]       if (VAR_RESULT == 0) {
    [00A1]         Var[102] = 0;                                                // Weird Ed: Actor found nearby = No

    [00A4]         VAR_RESULT = isScriptRunning(93);                            // is Weird Ed: Walk Hallway running
    [00A7]         if (VAR_RESULT == 0) {
    [00AC]           startScript(93);                                           // start Weird Ed: Walk Hallway
    [00AE]         }
    [00AE]         stopScript(0);                                               // --
    [00B0]       }
    [00B0]       breakHere();                                                   // Engine Tick
    [00B1]       unless (VAR_HAVE_MSG == 0) goto 00B0;                          // Wait for Weird Ed

    [00B6]       walkActorTo(11,Var[71],Var[72]);                               // Walk Weird Ed to next target
    [00BA]       breakHere();                                                   // Engine Tick
    [00BB]       VAR_RESULT = getActorMoving(11);
    [00BE]       unless (VAR_RESULT == 2) goto 00BA;                            // Wait for Weird Ed

    [00C3]       Var[102] = 0;                                                  // Weird Ed: Actor found nearby = No
    [00C6]       breakHere();                                                   // Engine Tick
    [00C7]       goto 0005;
    [00CA]     }
    [00CA]   }
    [00CA]   breakHere();                                                       // Engine Tick
    [00CB]   stopScript(82);                                                    // stop Weird Ed: Leave Room
    [00CD]   stopScript(93);                                                    // stop Weird Ed: Walk Hallway
    [00CF]   stopScript(92);                                                    // stop Weird Ed: Respond to Door Bell
    [00D1]   stopScript(146);                                                   // stop Weird Ed: Check Fridge
    [00D3]   startScript(83);                                                   // start Weird Ed: Check for hostile actors
    [00D5]   stopScript(0);                                                     // --
    [00D7] }
    [00D7] breakHere();                                                         // Engine Tick
    [00D8] goto 0005;                                                           // Loop check for actors
    [00DB] stopObjectCode();
}


 /**
  * Script 87: Weird Ed: Accept Commando Package
  */
Script-87 {
    [0000] cursorCommand( kModeCutscene )                                       // Cutscene Mode
    [0002] setActorBitVar(VAR_EGO,8,0);                                         // kActorMiscFlagEdsEnemy = OFF
    [0006] stopScript(83);                                                      // stop Weird Ed: Check for hostile actors
    [0008] stopScript(86);                                                      // stop Weird Ed: Check for friendly actors
    [000A] stopScript(111);                                                     // stop Weird Ed. Handle Object Interactions

    [000C] Var[94] = VAR_EGO;                                                   // tmp = Current Kid
    [000F] Var[73] = 1;                                                         // Door Bell Triggers Ed == Ignore Doorbell

    [0012] setOwnerOf(24,0);                                                    // Remove Package
    [0015] clearState08(23);                                                    // Package invisible
    [0017] clearState02(23);                                                    // Package untouchable

    [0019] print(11,"Oh! My commando package!");
    [0031] animateActor(11,6,1);                                                // Weird Ed face camera
    [0035] animateActor(VAR_EGO,6,1);                                           // Kid face camera
    [0039] breakHere();                                                         // Engine Tick
    [003A] unless (VAR_HAVE_MSG == 0) goto 0039;                                // Wait for Weird Ed

    [003F] startScript(91);                                                     // start Weird Ed: Help Find Plans
    [0041] stopObjectCode();
}


 /**
  * Script 88: Weird Ed: Accepts Prints
  */
Script-88 {
    [0000] cursorCommand( kModeCutscene )                                       // Cutscene Mode
    [0002] setActorBitVar(VAR_EGO,8,0);
    [0006] stopScript(83);                                                      // stop Weird Ed: Check for hostile actors
    [0008] stopScript(86);                                                      // stop Weird Ed: Check for friendly actors
    [000A] stopScript(111);                                                     // stop Weird Ed. Handle Object Interactions
    [000C] Var[74] = 1;                                                         // Weird Ed: Should storm lab = 1
    [000F] setOwnerOf(23,0);                                                    // Remove Prints
    [0012] animateActor(11,6,1);                                                // Weird Ed faces camera
    [0016] animateActor(VAR_EGO,6,1);                                           // Kid faces camera

    [001A] print(11,"Great, you developed my prints!");
    [0038] breakHere();                                                         // Engine Tick
    [0039] unless (VAR_HAVE_MSG == 0) goto 0038;                                // Wait for Weird Ed

    [003E] if (Var[11] == 2) {
    [0043]   print(11,"Oh no! You ruined them! Now all is lost,/the meteor will take over the world!");
    [0085] } else {
    [0088]   print(11,"Now we can overthrow the meteor!/Meet me in the lab in 10 minutes./We'll storm it together!");
    [00D7] }
    [00D7] startScript(93);                                                     // start Weird Ed: Walk Hallway
    [00D9] stopObjectCode();
}


 /**
  * Script 89: Give Hamster
  */
Script-89 {
    [0000] if (VAR_ACTIVE_ACTOR < 8) {                                          // Given to kid
    [0005]   setOwnerOf(0,VAR_ACTIVE_ACTOR);
    [0008]   print(VAR_ACTIVE_ACTOR,"Oh, how cute!");
    [0016] }
    [0016] if (VAR_ACTIVE_ACTOR == 14) {                                        // Given to Green Tentacle
    [001B]   print(VAR_ACTIVE_ACTOR,"How disgusting! I don't eat live food!");
    [003E] }
    [003E] if (VAR_ACTIVE_ACTOR == 19) {                                        // Given to Plant
    [0043]   startScript(98);
    [0045] }
    [0045] if (VAR_ACTIVE_ACTOR == 11) {                                        // Given to Weird Ed
    [004A]   cursorCommand(0);                                                  // Cutscene Mode
    [004C]   breakHere();                                                       // Engine Tick
    [004D]   setActorBitVar(VAR_EGO,8,0);                                       // kActorMiscFlagEdsEnemy = OFF
    [0051]   stopScript(83);                                                    // stop Weird Ed: Check for hostile actors
    [0053]   stopScript(86);                                                    // stop Weird Ed: Check for friendly actors
    [0055]   stopScript(111);                                                   // stop Weird Ed. Handle Object Interactions
    [0057]   setOwnerOf(1,0);                                                   // Remove Hamster
    [005A]   print(11,"Oh! My poor little hamster!");
    [0074]   breakHere();                                                       // Engine Tick
    [0075]   unless (VAR_HAVE_MSG == 0) goto 0074;                              // Wait for Weird Ed

    [007A]   print(11,"Thank you soooo much!");
    [008F]   if (VAR_ROOM == 26) {                                              // In Weird Ed's Room?

    [0094]     walkActorTo(11,21,52);                                           // walk Weird Ed
    [0098]     breakHere();                                                     // Engine Tick
    [0099]     VAR_RESULT = getActorMoving(11);
    [009C]     unless (VAR_RESULT == 2) goto 0098;                              // wait for Weird Ed

    [00A1]     animateActor(11,7,1);                                            // Weird Ed Faces Away
    [00A5]     delay(60);                                                       // Sleep 1 second
    [00A9]   }
    [00A9]   clearState08(1);                                                   // Hamster Visible
    [00AB]   clearState02(1);                                                   // Hamster Touchable
    [00AD]   breakHere();                                                       // Engine Tick
    [00AE]   unless (VAR_HAVE_MSG == 0) goto 00AD;                              // wait for Weird Ed

    [00B3]   if (Var[73] == 0) {                                                // Door Bell Triggers Ed == Yes
    [00B8]     print(11,"I hope my package comes soon!");
    [00D3]   } else if (Var[74] == 0) {                                         // Weird Ed: Should storm lab == No
    [00DB]     print(11,"C'mon, help me find my plans!");
    [00F6]   }
    [00F6]   startScript(93);                                                   // start Weird Ed: Walk Hallway
    [00F8] }
    [00F8] stopObjectCode();
}


 /**
  * Script 90: Weird Ed: Check Front Door
  */
Script-90 {
    [0000] stopScript(86);                                                      // stop Weird Ed: Check for friendly actors
    [0002] breakHere();                                                         // Engine Tick
    [0003] cutscene();                                                          // Start Cutscene
    [0004] beginOverride();
    {
        [0008] loadCostume(11);
        [000A] lockCostume(11);
        [000C] loadRoom(1);                                                         // Enter front of mansion
        [000E] setCameraAt(59);
        [0010] breakHere();                                                         // Engine Tick
        [0011] unless (VAR_CAMERA_POS_X == 59) goto 0010;                           // Wait for camera
        [0016] delay(60);                                                           // Sleep 1 second
        [001A] if (!getState08(28)) {                                               // Front door closed?
        [001E]   setState08(34);                                                    // Open Front door
        [0020]   setState08(28);                                                    // Open Front door
        [0022]   startSound(8);                                                     // sound Door open
        [0024] }
        [0024] startScript(52);                                                     // start Repeat Outside Sound
        [0026] delay(30);
        [002A] putActorInRoom(11,1);                                                // Weird Ed Enters
        [002D] putActor(11,59,43);
        [0031] delay(60);                                                           // Sleep 1 second

        [0035] if (!getState08(24)) {                                               // Package available?
        [0039]   actorFollowCamera(11);                                             //  Camera follow actor
        [003B]   walkActorToObject(11,24);                                          //  Walk Weird Ed to Package

        [003E]   print(11,"My package is here!");
        [0051]   startScript(85);                                                   //  start Weird Ed: Thanks for package

        [0053]   breakHere();                                                       //  Engine Tick
        [0054]   VAR_RESULT = getActorMoving(11);
        [0057]   unless (VAR_RESULT == 2) goto 0053;                                //  wait for Weird Ed

        [005C]   delay(60);
        [0060]   setState08(24);                                                    //  remove package
        [0062]   setState02(24);                                                    //  remove package
        [0064]   Var[73] = 2;                                                       //  Door Bell Triggers Ed = Ed has Package
        [0067]   delay(60);                                                         //  Sleep 1 second

        [006B]   walkActorToObject(11,28);                                          //  Walk Weird Ed to front door
        [006E]   breakHere();                                                       //  Engine Tick
        [006F]   VAR_RESULT = getActorMoving(11);
        [0072]   unless (VAR_RESULT == 2) goto 006E;                                //  Wait for Weird Ed

        [0077]   setCameraAt(59);
        [0079] } else {
        [007C]   Var[94] = getClosestObjActor7(11);                                 //  Find nearby actor
        [007F]   VAR_RESULT = getDist(11,Var[94]);
        [0083]   if (VAR_RESULT > 25) {                                             //  If kid > 25 away from door
        [0088]     print(11,"Someone playing tricks on me, eh?/I'll get them next time!");
        [00BC]   } else {
        [00BF]     walkActorToActor(11,Var[94],4);                                  //   walk to kid
        [00C3]     breakHere();                                                     //   Engine Tick
        [00C4]     breakHere();                                                     //   Engine Tick
        [00C5]     animateActor(11,255,1);                                          //   Weird Ed open mouth
        [00C9]     print(11,"Can't you read the sign?/NOW GET OUT OF HERE!");
        [00F1]   }
        [00F1]   breakHere();                                                       //  Engine Tick
        [00F2]   unless (VAR_HAVE_MSG == 0) goto 00F1;                              //  Wait for Weird Ed

        [00F7]   animateActor(11,4,1);                                              //  Weird Ed face left
        [00FB]   breakHere();                                                       //  Engine Tick
        [00FC]   animateActor(11,7,1);                                              //  Weird Ed face away
        [0100]   breakHere();                                                       //  Engine Tick
        [0101] }
    }

    [0101] print(255," ");
    [0105] stopScript(85);                                                      // stop Weird Ed: Thanks for package
    [0107] unlockCostume(11);
    [0109] if (!getState08(24)) {                                               // package available?
    [010D]   setState08(24);                                                    //  remove package
    [010F]   setState02(24);                                                    //  remove package
    [0111]   Var[73] = 2;
    [0114] }
    [0114] putActorInRoom(11,0);                                                // Weird Ed leaves
    [0117] putActor(11,0,0);
    [011B] clearState08(34);                                                    // Close front door
    [011D] clearState08(28);                                                    // Close front door
    [011F] setState04(28);                                                      // Lock front door
    [0121] if (VAR_OVERRIDE == 0) {
    [0126]   startSound(9);                                                     // Close door sound
    [0128]   delay(60);                                                         // Sleep 1 second
    [012C] }
    [012C] startScript(93);
    [012E] endcutscene();                                                       // End Cutscene
    [012F] stopObjectCode();
}


 /**
  * Script 91: Weird Ed: Help Find Plans
  */
Script-91 {
    [0000] if (VAR_ROOM != 26) {                                                // Not in eds room
    [0005]   print(11,"Come up to my room with me.");
    [001D]   breakHere();                                                       // Engine Tick
    [001E]   unless (VAR_HAVE_MSG == 0) goto 001D;                              // Wait for Weird Ed
    [0023]   putActorInRoom(11,26);                                             // Weird Ed enters Weird Eds room
    [0026]   putActor(11,10,52);
    [002A]   putActorInRoom(Var[94],26);                                        // Kid enters Weird Ed's room
    [002D]   putActor(Var[94],14,52);
    [0031]   loadRoom(26);                                                      // Enter Weird Ed's room
    [0033]   animateActor(11,5,1);                                              // Weird Ed faces right
    [0037]   animateActor(Var[94],4,1);                                         // Weird Ed faces left
    [003B]   delay(120);
    [003F] }
    [003F] setActorBitVar(Var[94],64,0);                                        // Kid has kActorMiscFlagFreeze
    [0043] cursorCommand( kModeNormal )                                         // Cutscene Mode Normal
    [0045] print(11,"Now you have to find me my plans./I lost them somewhere!");
    [0076] breakHere();                                                         // Engine Tick
    [0077] unless (VAR_HAVE_MSG == 0) goto 0076;                                // wait for Weird Ed

    [007C] animateActor(11,7,1);                                                // Weird Ed faces away
    [0080] Var[87] = 1;                                                         // Weird Ed: Looking for plans = yes
    [0083] print(11,"You see, the evil meteor%/%has turned my father into a madman./I must break into the lab and save him./I need my commando package and plans%/%but I lost them.");
    [0109] breakHere();                                                         // Engine Tick
    [010A] unless (VAR_HAVE_MSG == 0) goto 0109;                                // wait for Weird Ed

    [010F] print(11,"Come back when you have what I need!");
    [012F] breakHere();                                                         // Engine Tick
    [0130] unless (VAR_HAVE_MSG == 0) goto 012F;                                // wait for Weird Ed

    [0135] walkActorTo(11,21,52);                                               // Walk Weird Ed
    [0139] if (getState08(1)) {                                                 // Hamster  not in room
    [013D]   print(11,"By the way, have you seen my hamster?");
    [015E] } else {
    [0161]   print(11,"Hello, my cute little hamster.");
    [017E] }
    [017E] breakHere();                                                         // Engine Tick
    [017F] VAR_RESULT = getActorMoving(11);
    [0182] unless (VAR_RESULT == 2) goto 017E;                                  // Wait for Weird Ed

    [0187] animateActor(11,7,1);
    [018B] delay(300);                                                          // Wait 5 seconds
    [018F] walkActorToObject(11,4);                                             // Walk Weird Ed to Strategic Plan
    [0192] breakHere();                                                         // Engine Tick
    [0193] VAR_RESULT = getActorMoving(11);
    [0196] unless (VAR_RESULT == 2) goto 0192;                                  // Wait for Weird Ed

    [019B] animateActor(11,7,1);                                                // Weird Ed faces away
    [019F] Var[87] = 0;
    [01A2] stopObjectCode();
}


 /**
  * Scrip 92: Weird Ed: Respond to Door Bell
  */
Script-92 {
    [0000] delay(180);                                                          // Sleep 3 seconds
    [0004] cutscene();                                                          // Start Cutscene
    [0005] Var[94] = getActorRoom("Weird Ed");
    [0008] loadRoom(Var[94]);                                                   // Enter Room with Weird Ed
    [000A] actorFollowCamera(11);                                               // Camera follow Weird Ed

    [000C] walkActorTo(11,Var[71],Var[72]);                                     // Walk Weird Ed
    [0010] delay(120);
    [0014] print(11,"I'm coming, I'm coming!");
    [002B] breakHere();                                                         // Engine Tick
    [002C] unless (VAR_HAVE_MSG == 0) goto 002B;                                // Wait for Weird Ed

    [0031] endcutscene();                                                       // End Cutscene
    [0032] stopObjectCode();
}


 /**
  * Script 93: Weird Ed: Walk Hallway
  */
Script-93 {
    [0000] cursorCommand( kModeNormal )                                         // Cutscene Mode Normal
    [0002] setActorBitVar(Var[94],64,0);
    [0006] breakHere();                                                         // Engine Tick
    [0007] unless (VAR_HAVE_MSG == 0) goto 0006;                                // Wait for Weird Ed

    [000C] Var[90] = getActorRoom("Weird Ed");
    [000F] if (Var[90] == 26) {                                                 // Weird ed in his room?
    [0014] } else {
    [0017]   if (Var[90] == 38) {                                               // Weird Ed in Level 3 Hallway?
    [001C]   } else {
    [001F]     putActorInRoom(11,0);                                            // Weird Ed leaves room
    [0022]     putActor(11,0,0);
    [0026]     delay(1500);                                                     // Wait 25 seconds
    [002A]     putActorInRoom(11,38);                                           // Weird Ed enters Level 3 Hallway
    [002D]     putActorAtObject(11,208);
    [0030]     animateActor(11,5,1);                                            // Weird Ed faces right
    [0034]     startScript(86);
    [0036]     delay(300);                                                      // Wait 5 seconds
    [003A]     breakHere();                                                     // Engine Tick
    [003B]     unless (Var[102] == 0) goto 003A;                                // Until Weird Ed: Actor found nearby == No
    [0040]     unless (VAR_ROOM == 38) goto 0054;                               // Until Weird Ed in Level 3 Hallway
    [0045]   }

    [0045]   walkActorToObject(11,186);                                         // Weird Ed walks to Door: Weird Ed
    [0048]   breakHere();                                                       // Engine Tick

    [0049]   VAR_RESULT = getActorMoving(11);
    [004C]   unless (VAR_RESULT == 2) goto 0048;                                // Wait for Weird Ed
    [0051]   goto 0059;                                                         // --

    [0054]   if (VAR_ROOM == 26) {                                              // Weird Ed is in his room?
    [0059]     if (!getState08(6)) {                                            //  Door is closed?
    [005D]       setState08(6);                                                 //  Open Door
    [005F]       setState08(186);                                               //  open hall door
    [0061]       startSound(8);                                                 //  sound door open
    [0063]       delay(60);                                                     // Sleep 1 second
    [0067]     }
    [0067]   }

    [0067]   putActorInRoom(11,26);                                             // Weird Ed enters his room
    [006A]   putActorAtObject(11,6);
    [006D]   animateActor(11,6,1);                                              // Weird Ed faces camera
    [0071]   delay(60);                                                         // Sleep 1 second
    [0075]   startScript(86);                                                   // start Weird Ed: Check for friendly actors
    [0077]   clearState08(6);                                                   // close door
    [0079]   clearState08(186);                                                 // close hall door

    [007B]   if (VAR_ROOM == 38) {                                              // Current room == Level3 Hall?
    [0080]   } else {
    [0083]     unless (VAR_ROOM == 26) goto 008E;                               // or Current room == Weird Eds Room
    [0088]   }

    [0088]   startSound(9);                                                     // sound door close
    [008A]   delay(60);                                                         // Sleep 1 second
    [008E]   breakHere();                                                       // Engine Tick
    [008F]   unless (Var[102] == 0) goto 008E;                                  // Until Weird Ed: Actor found nearby = No

    [0094]   breakHere();                                                       // Engine Tick
    [0095]   unless (VAR_HAVE_MSG == 0) goto 0094;                              // Wait for Weird Ed
    [009A] }
    [009A] walkActorTo(11,10,52);                                               // Walk Weird Ed
    [009E] breakHere();                                                         // Engine Tick
    [009F] VAR_RESULT = getActorMoving(11);
    [00A2] unless (VAR_RESULT == 2) goto 009E;                                  // wait for Weird Ed

    [00A7] animateActor(11,7,1);                                                // Weird Ed faces away
    [00AB] stopScript(86);
    [00AD] stopObjectCode();
}


 /**
  * Script 94: Weird Ed: Storm Dr. Freds Lab
  */
Script-94 {
    [0000] stopScript(36);                                                      // Stop Cutscene: Meteor Police
    [0002] Var[104] = 1;
    [0005] cutscene();                                                          // Start Cutscene
    [0006] setState08(130);                                                     // Open Inner Door
    [0008] setState08(133);                                                     // Open Inner Door
    [000A] beginOverride();
    {
        [000E] putActorInRoom(11,31);                                               // Put Weird Ed in Lab: Entry
        [0011] putActorAtObject(11,133);
        [0014] animateActor(11,6,1);                                                // Ed Face Camera
        [0018] actorFollowCamera(11);                                               // Camera follow Ed
        [001A] delay(120);
        [001E] print(11,"All right, slime-ball! The game's up.");
        [0041] walkActorToActor(11,13,4);                                           // Walk Ed to Purple Tentacle
        [0045] breakHere();                                                         // Engine Tick
        [0046] VAR_RESULT = getDist(11,13);
        [004A] unless (VAR_RESULT < 8) goto 0045;                                   // Wait for distance < 8

        [004F] startScript(157);                                                    // start Weird Ed: Walk around the Lab Entry
        [0051] print(13,"oh no%");
        [0059] walkActorTo(13,47,57);                                               // walk Purple Tentacle
        [005D] breakHere();                                                         // Engine Tick
        [005E] VAR_RESULT = getActorMoving(13);
        [0061] unless (VAR_RESULT == 2) goto 005D;                                  // Wait for Purple Tentacle

        [0066] print(11,"Come here%");
        [0072] walkActorTo(13,45,66);                                               // Walk Purple Tentacle
        [0076] breakHere();                                                         // Engine Tick
        [0077] VAR_RESULT = getActorMoving(13);
        [007A] unless (VAR_RESULT == 2) goto 0076;                                  // Wait for Purple Tentacle

        [007F] print(13,"You'll never get me%");
        [0093] walkActorTo(13,12,66);                                               // Walk Purple
        [0097] breakHere();                                                         // Engine Tick
        [0098] VAR_RESULT = getActorMoving(13);
        [009B] unless (VAR_RESULT == 2) goto 0097;                                  // Wait for Purple Tentacle

        [00A0] print(13,"I'm getting out of here.");
        [00B7] walkActorToObject(13,133);                                           // Walk Purple to inner door
        [00BA] stopScript(157);                                                     // stop Weird Ed: Walk around the Lab Entry
        [00BC] walkActorToObject(11,133);                                           // Walk Weird Ed to inner door
        [00BF] breakHere();                                                         // Engine Tick
        [00C0] VAR_RESULT = getActorMoving(13);
        [00C3] unless (VAR_RESULT == 2) goto 00BF;                                  // Wait for Purple Tentacle

        [00C8] putActorInRoom(13,0);                                                // Purple leaves
        [00CB] putActor(13,0,0);
        [00CF] breakHere();                                                         // Engine Tick
        [00D0] VAR_RESULT = getActorMoving(11);
        [00D3] unless (VAR_RESULT == 2) goto 00CF;                                  // Wait for Weird Ed

        [00D8] Var[90] = getActorX(11);
        [00DB] VAR_RESULT = getActorX(VAR_EGO);
        [00DE] if (VAR_RESULT < Var[90]) {                                          // If Weird Ed to the right of Kid
        [00E3]   animateActor(11,4,1);                                              // Weird Ed face left
        [00E7]   animateActor(VAR_EGO,5,1);
        [00EB] } else {
        [00EE]   animateActor(11,5,1);                                              // Weird Ed face Right
        [00F2]   animateActor(VAR_EGO,4,1);
        [00F6] }
        [00F6] print(11,"I'll take care of sucker face%/%you get the meteor.");
        [0124] breakHere();                                                         // Engine Tick
        [0125] unless (VAR_HAVE_MSG == 0) goto 0124;                                // Wait for Weird Ed

        [012A] animateActor(11,7,1);                                                // Weird ed face away
        [012E] breakHere();                                                         // Engine Tick
        [012F] breakHere();                                                         // Engine Tick
    }

    [0130] putActorInRoom(13,0);                                                // Purple Leaves
    [0133] putActor(13,0,0);
    [0137] putActorInRoom(11,0);                                                // Weird Ed leaves
    [013A] putActor(11,0,0);

    [013E] endcutscene();                                                       // End Cutscene
    [013F] cursorCommand( kModeNoNewKid )                                       // Disable New Kid verb
    [0141] Var[135] = 1;                                                        // Purple chased out of lab?
    [0144] stopObjectCode();
}


 /**
  * Script 95: Play Piano
  */
Script-95 {
    [0000] cutscene();                                                          // Start Cutscene
    [0001] if (Var[23] == 1) {                                                  // if Victrola Playing == Yes
    [0006]   delay(60);                                                         //  Sleep 1 second
    [000A]   printEgo("I have to turn off the Victrola first.");
    [002B]   doSentence(5,102,0);
    [002F]   breakHere();                                                       //  Engine Tick
    [0030]   unless (Var[23] == 0) goto 002F;                                   //  Wait

    [0035]   delay(60);                                                         //  Sleep 1 second
    [0039]   walkActorToObject(VAR_EGO,101);                                    //  Walk kid to Piano
    [003C]   breakHere();                                                       //  Engine Tick
    [003D]   VAR_RESULT = getActorMoving(VAR_EGO);
    [0040]   unless (VAR_RESULT == 2) goto 003C;                                //  Wait for kid

    [0045]   animateActor(VAR_EGO,5,1);                                         //  Kid faces right
    [0049] }

    [0049] delay(60);                                                           // Sleep 1 second
    [004D] startMusic(50);                                                      // Play
    [004F] beginOverride();
    {
        [0053] breakHere();                                                         // Engine Tick
        [0054] unless (VAR_IS_SOUND_RUNNING == 0) goto 0053;                        // wait until finished playing
        [0059] stopMusic();
    }

    [005A] endcutscene();                                                       // End Cutscene
    [005B] if (getState08(158)) {                                               // Casette Recorder == On
    [005F]   Var[13] = 50;                                                      // Tape Contents = Good
    [0062]   Var[67] = VAR_EGO;                                                 // Contract: Who its For (Actor ID) = Kid
    [0065] }
    [0065] stopObjectCode();
}


 /**
  * Script 96: Dr Fred: Play Meteor Mess
  */
Script-96 {
    [0000] delay(10800);                                                        // Sleep 3 minutes
    [0004] delay(3600);                                                         // Sleep 1 minute
    [0008] Var[112] = 1;                                                        // Check for kids in Video Games, Level 2 Main Hall, Nurse Ednas, Weird Ed's
    [000B] Var[111] = 18;                                                       //   Check for Kid in room 18 (Video Games)
    [000E] startScript(133);                                                    //
    [0010] Var[111] = 13;                                                       //   Check for Kid in room 13 (Level 2 Main Hallway)
    [0013] startScript(133);                                                    //
    [0015] Var[111] = 19;                                                       //   Check for Kid in room 19 (Nurse Edna's)
    [0018] startScript(133);                                                    //
    [001A] Var[111] = 26;                                                       //   Check for Kid in room 26 (Weird Ed's)
    [001D] startScript(133);
    [001F] unless (Var[112] == 1) goto 0004;                                    //  Loop until no kids in rooms

    [0024] if (getState08(124)) {                                               //  If Power Off
    [0028]   goto 0004;                                                         //   Loop
    [002B] }

    [002B] cutscene();                                                          // Start Cutscene
    [002C] putActorInRoom(9,18);                                                // Dr. Fred Enters
    [002F] putActor(9,51,56);
    [0033] loadRoom(18);                                                        // Load Room 'Video Games'
    [0035] actorFollowCamera(9);
    [0037] animateActor(9,7,1);                                                 // Dr. Fred Looks Right

    [003B] if (!getState08(204)) {                                              // Wires Not Fixed?

    [003F]   beginOverride();
    {
    [0043]   delay(180);                                                            //  Sleep 3 seconds
    [0047]   walkActorToObject(9,168);                                              //  Walk Dr. Fred to Door
    [004A]   print(9,"I guess the power's out.");
    [0061]   breakHere();                                                           // Engine Tick
    [0062]   unless (VAR_HAVE_MSG == 0) goto 0061;                                  // Wait until speaking finished
    [0067]   delay(120);
    }

    [006B] } else {

    [006E]   beginOverride();
    {
    [0072]   startSound(35);
    [0074]   setState08(173);                                                       // Meteor Mess On
    [0076]   delay(300);                                                            // Wait 5 seconds
    }

    [007A]   if (VAR_OVERRIDE == 1) {
    [007F]     loadRoom(0);
    [0081]   }
    [0081]   startScript(97);                                                   //  start Script 97: The Lab: Set Pin
    [0083] }

    [0083] clearState08(173);                                                   // Meteor Mess Off
    [0085] print(255," ");
    [0089] stopSound(35);
    [008B] putActorInRoom(9,0);                                                 // Dr. Fred leaves room
    [008E] putActor(9,0,0);
    [0092] endcutscene();                                                       // End Cutscene
    [0093] stopObjectCode();
}


 /**
  * Script 97: The Lab: Set Pin
  */
Script-97 {
    [0000] Var[92] = getRandomNr(3);
    [0003] clearState08(227);                                                   // Hide Highscore: Pin1
    [0005] clearState08(228);                                                   // Hide Highscore: Pin2
    [0007] clearState08(229);                                                   // Hide Highscore: Pin3
    [0009] clearState08(230);                                                   // Hide Highscore: Pin4
    [000B] if (Var[92] == 0) {
    [0010]   Var[40] = 7;                                                       // The Lab: Pin 1/4
    [0013]   Var[41] = 5;                                                       // The Lab: Pin 2/4
    [0016]   Var[42] = 7;                                                       // The Lab: Pin 3/4
    [0019]   Var[43] = 2;                                                       // The Lab: Pin 4/4
    [001C]   setState08(227);                                                   // Visible Highscore: Pin1
    [001E] }
    [001E] if (Var[92] == 1) {
    [0023]   Var[40] = 5;                                                       // The Lab: Pin 1/4
    [0026]   Var[41] = 8;                                                       // The Lab: Pin 2/4
    [0029]   Var[42] = 5;                                                       // The Lab: Pin 3/4
    [002C]   Var[43] = 8;                                                       // The Lab: Pin 4/4
    [002F]   setState08(228);                                                   // Visible Highscore: Pin1
    [0031] }
    [0031] if (Var[92] == 2) {
    [0036]   Var[40] = 3;                                                       // The Lab: Pin 1/4
    [0039]   Var[41] = 3;                                                       // The Lab: Pin 2/4
    [003C]   Var[42] = 0;                                                       // The Lab: Pin 3/4
    [003F]   Var[43] = 1;                                                       // The Lab: Pin 4/4
    [0042]   setState08(229);                                                   // Visible Highscore: Pin1
    [0044] }
    [0044] if (Var[92] == 3) {
    [0049]   Var[40] = 8;                                                       // The Lab: Pin 1/4
    [004C]   Var[41] = 6;                                                       // The Lab: Pin 2/4
    [004F]   Var[42] = 4;                                                       // The Lab: Pin 3/4
    [0052]   Var[43] = 0;                                                       // The Lab: Pin 4/4
    [0055]   setState08(230);                                                   // Visible Highscore: Pin1
    [0057] }
    [0057] stopObjectCode();
}


 /**
  * Script 98: Give: Accept Item Check
  */
Script-98 {
    [0000] if (VAR_ACTIVE_ACTOR < 8) {
    [0005]   setOwnerOf(0,VAR_ACTIVE_ACTOR);                                    // Giving item to kid
    [0008]   Var[107] = 0;                                                      // Give ObjectID = 0
    [000B] } else if (VAR_ACTIVE_ACTOR == 14) {                                 // Giving to Green Tentacle
    [0013]   Var[79]++;                                                         // Green Tentacle: Has been Fed += 1
    [0015]   setOwnerOf(0,0);
    [0018]   if (Var[107] == 165) {                                             // Give ObjectID == Bowl of wax fruit
    [001D]     Var[107] = 0;                                                    // Give ObjectID = 0
    [0020]     print(14,"WOW! My favorite! THAT's what I wanted!");
    [0044]     Var[79] = 7;                                                     // Green Tentacle: Has been Fed = 7
    [0047]     breakHere();                                                     // Engine Tick
    [0048]     unless (VAR_HAVE_MSG == 0) goto 0047;                            // Wait for Green
    [004D]   }
    [004D]   if (Var[79] < 7) {                                                 // Green Tentacle: Has been Fed < 7
    [0052]     print(14,"Thanks. More food!");
    [0065]   } else if (Var[80] == 0) {                                         // Green Tentacle: Has drank == No
    [006D]     print(14,"Now I'm thirsty!");
    [007E]   }
    [007E] } else if (VAR_ACTIVE_ACTOR == 19) {                                 // Giving to the plant
    [0086]   print(19,"Yum yum!");
    [0090]   setOwnerOf(0,0);                                                   // Set owner to no-one
    [0093] } else if (VAR_ACTIVE_ACTOR == 11) {                                 // Giving to Weird Ed
    [009B]   print(VAR_ACTIVE_ACTOR,"No thanks.");
    [00A7] } else {                                                             // Everyone else
    [00AA]   print(VAR_ACTIVE_ACTOR,"No thanks. I'm not hungry.");
    [00C3] }
    [00C3] stopObjectCode();
}


 /**
  * Script 99: Give: Accept Item Check 2
  */
Script-99 {
    [0000] if (VAR_ACTIVE_ACTOR < 8) {                                          //
    [0005]   setOwnerOf(0,VAR_ACTIVE_ACTOR);                                    // Kid now owns Item
    [0008] } else if (VAR_ACTIVE_ACTOR == 14) {                                 // Give to Green Tentacle?
    [0010]   if (Var[134] == 1) {                                               //
    [0015]     Var[134] = 0;                                                    //
    [0018]     Var[22] = 0;                                                     //  Glass Jar Contents = Empty
    [001B]     startScript(74);                                                 //  start Glass Jar: Name
    [001D]   } else {
    [0020]     setOwnerOf(0,0);                                                 // item removed
    [0023]   }
    [0023]   if (Var[79] < 7) {                                                 // Green Tentacle: Has been Fed?
    [0028]     print(14,"Thanks! More food!");
    [003B]   } else {
    [003E]     Var[80] = 1;                                                     // Green Tentacle: Has drank = Yes
    [0041]     print(14,"Thanks!");
    [004B]   }
    [004B] } else if (VAR_ACTIVE_ACTOR == 19) {                                 // Give to Plant?
    [0053]   setOwnerOf(0,0);                                                   // Item Removed
    [0056] } else {
    [0059]   print(VAR_ACTIVE_ACTOR,"I'm not thirsty.");
    [006A] }
    [006A] stopObjectCode();
}


 /**
  * Script 100: Cutscene: 3 Guys Who Pub Anything: Receive Mail Trigger
  */
Script-100 {
    [0000] delay(3600);                                                         // Sleep 60 Seconds
    [0004] delay(1800);                                                         // Sleep 30 Seconds
    [0008] unless (VAR_ROOM != 1) goto 0004;                                    //  If player is in room1, sleep
    [000D] if (!getState08(25)) {
    [0011]   stopScript(0);
    [0013] }
    [0013] clearState08(25);
    [0015] setState02(25);
    [0017] clearState08(18);
    [0019] setOwnerOf(201,0);                                                   // Sealed Envelope has no owner
    [001C] delay(10800);
    [0020] cutscene();                                                          // Start Cutscene
    [0021] loadRoom(0);
    [0023] startScript(101);                                                    // Cutscene: 3 Guys Who Pub Anything: Receive Mail
    [0025] breakHere();                                                         // Engine Tick
    [0026] VAR_RESULT = isScriptRunning(101);
    [0029] unless (VAR_RESULT == 0) goto 0025;
    [002E] endcutscene();                                                       // End Cutscene
    [002F] delay(18000);                                                        // Sleep for 5 minutes
    [0033] if (Var[82] > 0) {                                                   // 3 Guys Who Pub Anything: Accepted ?
    [0038]   delay(1800);
    [003C]   unless (VAR_ROOM != 1) goto 0038;                                  // Sleep until not in room 1
    [0041]   setState08(27);                                                    // Contract +08
    [0043]   clearState02(27);                                                  // Contract -02
    [0045]   startSound(39);
    [0047] }
    [0047] stopObjectCode();
}


 /**
  * Script 101: Cutscene: 3 Guys Who Pub Anything: Receive Mail
  */
Script-101 {
    [0000] putActorInRoom(17,41);                                               // Mark Eteer in Room '3 Guys who publish anything (Office)'
    [0003] putActor(17,34,64);
    [0007] animateActor(17,7,1);                                                // Mark Eteer face camera
    [000B] loadRoom(41);
    [000D] delay(60);                                                           // Sleep 1 second

    [0011] if (Var[63] == 1) {                                                  // If Envelope Contents == Memoir

    [0016]   print(17,"Ah! A manuscript! Let's see%");
    [0031]   breakHere();                                                       // Engine Tick
    [0032]   unless (VAR_HAVE_MSG == 0) goto 0031;

    [0037]   delay(60);                                                         // Sleep 1 second
    [003B]   if (Var[16] == 2) {                                                // If Memoir Quality == Great
    [0040]     print(17,"Wow!/This is hot stuff!/It will sell millions%/%maybe even BILLIONS!!/I'm going to make Mr. Meteor%/%a million dollar offer!");
    [00AF]     Var[82] = 1;                                                     // Contract: Accept Content = Contract for Meteor
    [00B2]   } else {
    [00B5]     print(17,"What is this garbage!/I wouldn't even use it to start a fire.");
    [00EA]   }

    [00EA]   animateActor(17,4,1);                                              // Mark Eteer face left
    [00EE]   breakHere();                                                       // Engine Tick
    [00EF]   animateActor(17,6,1);                                              // Mark Eteer face camera
    [00F3]   delay(120);

    [00F7]   walkActorTo(17,10,64);
    [00FB]   breakHere();                                                       // Engine Tick
    [00FC]   VAR_RESULT = getActorMoving(17);
    [00FF]   unless (VAR_RESULT == 2) goto 00FB;

    [0104]   walkActorTo(17,30,64);
    [0108]   breakHere();                                                       // Engine Tick
    [0109]   VAR_RESULT = getActorMoving(17);
    [010C]   unless (VAR_RESULT == 2) goto 0108;
    [0111]   unless (VAR_HAVE_MSG == 0) goto 00F7;
    [0116]   animateActor(17,6,1);                                              // Mark Eteer face camera
    [011A]   delay(30);

    [011E]   walkActorToObject(17,242);
    [0121]   breakHere();                                                       // Engine Tick
    [0122]   breakHere();                                                       // Engine Tick
    [0123]   breakHere();                                                       // Engine Tick
    [0124]   VAR_RESULT = getActorMoving(17);
    [0127]   unless (VAR_RESULT == 2) goto 0123;
    [012C] }

    [012C] if (Var[63] >= 2) {                                                  // If Envelope Contents >= Tape
    [0131]   print(17,"A cassette tape!/Now, where's the play button?");

    [015C]   walkActorToObject(17,18);                                          // Mark Eteer walk to ?
    [015F]   breakHere();                                                       // Engine Tick
    [0160]   breakHere();                                                       // Engine Tick
    [0161]   breakHere();                                                       // Engine Tick
    [0162]   VAR_RESULT = getActorMoving(17);                                   // Mark Eteer finished walking?
    [0165]   unless (VAR_RESULT == 2) goto 0161;

    [016A]   animateActor(17,6,1);                                              // Mark Eteer face Camera
    [016E]   breakHere();                                                       // Engine Tick
    [016F]   unless (VAR_HAVE_MSG == 0) goto 016E;
    [0174]   delay(60);                                                         // Sleep 1 second

    [0178]   walkActorTo(17,9,56);                                              // Mark Eteer Walk to Stereo
    [017C]   breakHere();                                                       // Engine Tick
    [017D]   breakHere();                                                       // Engine Tick
    [017E]   breakHere();                                                       // Engine Tick
    [017F]   VAR_RESULT = getActorMoving(17);
    [0182]   unless (VAR_RESULT == 2) goto 017E;

    [0187]   animateActor(17,6,1);                                              // Mark face stereo
    [018B]   delay(60);                                                         // Sleep 1 second

    [018F]   if (Var[13] == 0) {                                                // Tape Quality == Blank
    [0194]     delay(180);                                                      // Sleep 3 seconds
    [0198]     print(17,"A blank tape? Is this a joke?");

    [01B2]   } else {
    [01B5]     if (Var[13] == 25) {                                             // Tape Quality == Tentacle mating Call
    [01BA]       startSound(47);
    [01BC]       delay(300);                                                    // Wait 5 seconds
    [01C0]       startSound(53);
    [01C2]       setState08(242);
    [01C4]       delay(60);                                                     // Sleep 1 second

    [01C8]       walkActorToObject(17,242);                                     // Mark walks to object ?
    [01CB]       breakHere();                                                   // Engine Tick
    [01CC]       breakHere();                                                   // Engine Tick
    [01CD]       breakHere();                                                   // Engine Tick
    [01CE]       VAR_RESULT = getActorMoving(17);                               // Mark Finished Walking?
    [01D1]       unless (VAR_RESULT == 2) goto 01CD;

    [01D6]       animateActor(17,7,1);                                          // Mark turn away
    [01DA]       breakHere();                                                   // Engine Tick
    [01DB]       print(17,"Oh, Great!");
    [01E7]     }

    [01E7]     if (Var[13] == 44) {                                             // Tape Quality == Melody Stinks
    [01EC]       startSound(48);
    [01EE]       delay(420);
    [01F2]       print(17,"I like the beat, but the melody stinks!");
    [0215]     }

    [0215]     if (Var[13] == 50) {                                             // Tape Quality == Good
    [021A]       startMusic(49);
    [021C]       Var[82] = 2;                                                   // 3 Guys Who Pub Anything: Accepted  = Contract for Player
    [021F]     } else {
    [0222]       unless (Var[13] == 52) goto 0282;
    [0227]       startMusic(51);
    [0229]       Var[82] = 3;                                                   // 3 Guys Who Pub Anything: Accepted  = Contract for Green
    [022C]     }

    [022C]     delay(300);                                                      // Wait 5 seconds
    [0230]     print(17,"Wonderful!/Outrageous!/AWESOME!!/This will be a MEGAHIT!/I've got to sign them right now!");
    [0282]   }
    [0282] }
    [0282] breakHere();                                                         // Engine Tick
    [0283] unless (VAR_HAVE_MSG == 0) goto 0282;

    [0288] delay(120);
    [028C] stopSound(47);
    [028E] stopSound(48);
    [0290] stopMusic();
    [0291] stopObjectCode();
}


 /**
  * Script 102: Green Tentacle: Accepts Tape
  */
Script-102 {
    [0000] stopScript(103);                                                     // Green Tentacle: So Depressed
    [0002] breakHere();                                                         // Engine Tick

    [0003] if (Var[138] == 1) {                                                 // if Green Tentacle Heard tape playing
    [0008]   Var[138] = 0;                                                      //  Green Tentacle Heard tape playing = No
    [000B]   cursorCommand( kModeCutscene )                                     //  Cutscene Mode
    [000D]   walkActorToObject(14,131);                                         //  Walk Green to Mondo Stereo

    [0010]   walkActorToObject(VAR_EGO,439);                                    //  Walk Kid to Picture
    [0013]   breakHere();                                                       // Engine Tick
    [0014]   VAR_RESULT = getActorMoving(VAR_EGO);
    [0017]   unless (VAR_RESULT == 2) goto 0013;                                //  Wait for Kid
    [001C]   animateActor(VAR_EGO,4,1);                                         //  Turn Kid

    [0020]   breakHere();                                                       // Engine Tick
    [0021]   VAR_RESULT = getActorMoving(14);
    [0024]   unless (VAR_RESULT == 2) goto 0020;                                //  Wait for Green

    [0029]   actorFollowCamera(14);                                             //  Camera follow green
    [002B] } else {

    [002E]   if (Var[13] == 52) {                                               // Tape Contents == Green Tentacle
    [0033]     printEgo("I don't want my tape back - it's awful!");
    [0054]     goto 0228;
    [0057]   }
    [0057]   cursorCommand( kModeCutscene )                                     // Cutscene Mode
    [0059]   setOwnerOf(156,14);                                                // green owns Cassette Tape
    [005C]   print(14,"You made a demo tape? Let's hear it!");
    [007C]   actorFollowCamera(14);

    [007E]   walkActorToObject(14,131);                                         // Walk Green to Mondo Stereo
    [0081]   breakHere();                                                       // Engine Tick
    [0082]   VAR_RESULT = getActorMoving(14);
    [0085]   unless (VAR_RESULT == 2) goto 0081;                                // Wait for Green

    [008A]   animateActor(VAR_EGO,4,1);
    [008E]   clearState08(195);                                                 // Cassette Tape
    [0090]   clearState02(195);                                                 // Cassette Tape
    [0092]   delay(60);                                                         // Sleep 1 second
    [0096]   setState08(131);                                                   // Stereo has Tape
    [0098]   startScript(104);                                                  // Tape Player: Play Tape
    [009A]   delay(300);                                                        // Wait 5 seconds
    [009E] }

    [009E] if (Var[13] == 50) {                                                 // Tape Contents == Good
    [00A3]   print(14,"Hey, this is great stuff!");
    [00BB]   breakHere();                                                       // Engine Tick
    [00BC]   unless (VAR_HAVE_MSG == 0) goto 00BB;                              // Wait for Green to finish speaking

    [00C1]   print(14,"I could use someone like you in my band!");
    [00E4]   walkActorToActor(14,VAR_EGO,5);
    [00E8]   breakHere();                                                       // Engine Tick
    [00E9]   breakHere();                                                       // Engine Tick
    [00EA]   unless (VAR_HAVE_MSG == 0) goto 00E9;                              // Wait for Green to finish speaking

    [00EF]   print(14,"I have a demo tape, but it's no use./I'll never get a recording contract,/even if we get a band together.");
    [0148]   walkActorToObject(14,238);                                         //
    [014B]   breakHere();                                                       // Engine Tick
    [014C]   VAR_RESULT = getActorMoving(14);
    [014F]   unless (VAR_RESULT == 2) goto 014B;                                // Wait for Green

    [0154]   clearState08(238);                                                 // Demo Tape Visible
    [0156]   clearState02(238);                                                 // Demo Tape Unlocked
    [0158]   clearState08(131);                                                 // Mondo Stereo Has no Tape
    [015A]   delay(60);                                                         // Sleep 1 second

    [015E]   walkActorToObject(14,131);                                         // Green Tentacle move to Mondo Stereo
    [0161]   breakHere();                                                       // Engine Tick
    [0162]   VAR_RESULT = getActorMoving(14);
    [0165]   unless (VAR_RESULT == 2) goto 0161;                                // Wait for Green Tentacle to stop moving

    [016A]   setState08(195);                                                   // Cassette Tape Hidden
    [016C]   setState02(195);                                                   // Cassette Tape Locked
    [016E]   stopMusic();
    [016F]   delay(60);                                                         // Sleep 1 second
    [0173] }

    [0173] if (Var[13] == 0) {                                                  // Tape Contents == Blank
    [0178]   print(14,"Not very good!/I think you need some work%/%on your dynamic range.");
    [01B3]   delay(120);
    [01B7] }

    [01B7] if (Var[13] == 25) {                                                 // Tape Contents == Tentacle Mating Call
    [01BC]   printEgo("THE TENTACLE MATING CALL!!/AGGGGGGGGGGGG!!");

    [01E5]   walkActorToActor(14,VAR_EGO,4);                                    // Walk Green to Active Kid
    [01E9]   breakHere();                                                       // Engine Tick
    [01EA]   VAR_RESULT = getActorMoving(14);
    [01ED]   unless (VAR_RESULT == 2) goto 01E9;                                // Wait for Green to finish moving

    [01F2]   loadRoom(0);
    [01F4]   Var[76] = 4;                                                       // Death Method = By Tentacle
    [01F7]   startScript(56);                                                   // Cutscene: Kid Dies                                           // Cutscene: Kid Dies
    [01F9] }

    [01F9] if (Var[13] == 44) {                                                 // Tape Contents == Melody Stinks
    [01FE]   print(14,"Not bad./It needs a bit more work, though.");
    [0224]   delay(120);
    [0228] }

    [0228] walkActorTo(14,68,58);
    [022C] breakHere();                                                         // Engine Tick
    [022D] VAR_RESULT = getActorMoving(14);
    [0230] unless (VAR_RESULT == 2) goto 022C;                                  // Wait for Green Tentacle to stop

    [0235] cursorCommand( kModeNormal )                                         // Cutscene Mode Normal
    [0237] actorFollowCamera(VAR_EGO);
    [0239] stopObjectCode();
}


 /**
  * Script 103: Green Tentacle: So Depressed
  */
Script-103 {
    [0000] putActorInRoom(14,20);                                               // Put Green Tentacle in Green Tentacle's Room
    [0003] putActor(14,68,58);

    [0007] breakHere();                                                         // Engine Tick
    [0008] VAR_RESULT = getActorX(VAR_EGO);
    [000B] unless (VAR_RESULT > 15) goto 0007;                                  // Sleep until Kid > x 15

    [0010] walkActorToActor(14,VAR_EGO,5);                                      // Walk actor to Kid
    [0014] breakHere();                                                         // Engine Tick
    [0015] VAR_RESULT = getActorMoving(14);
    [0018] unless (VAR_RESULT == 2) goto 0010;                                  // Sleep until Green is not moving

    [001D] if (Var[83] == 0) {                                                  // has Green Tentacle: Has had whinge?
    [0022]   startScript(156);                                                  //  Green Tentacle: Walk to current kid
    [0024]   print(14,"Oh I'm so depressed./I'm never going to get my band started!/My life is going nowhere./I'm never going to amount to anything./Eating all that food didn't even help.");
    [00B1]   breakHere();                                                       // Engine Tick
    [00B2]   unless (VAR_HAVE_MSG == 0) goto 00B1;

    [00B7]   Var[83] = 1;                                                       // Green Tentacle: Has had whinge = 1
    [00BA]   stopScript(156);                                                   // Stop 'Green Tentacle: Walk to current kid'
    [00BC] } else {

    [00BF]   if (Var[137] == 1) {                                               // Green Tentacle: Is a friend?
    [00C4]     printEgo("Hi!");
    [00C9]   } else {
    [00CC]     print(14,"I'm soooooooooooo depressed.");
    [00E9]   }

    [00E9]   breakHere();                                                       // Engine Tick
    [00EA]   unless (VAR_HAVE_MSG == 0) goto 00E9;                              // Wait for green talking
    [00EF] }

    [00EF] walkActorTo(14,68,58);                                               // Walk to corner
    [00F3] stopObjectCode();
}


 /**
  * Script 104: Tape Player: Play Tape
  */
Script-104 {
    [0000] breakHere();                                                         // Engine Tick
    [0001] if (Var[13] == 0) {                                                  // Tape is blank
    [0006]   printEgo("It's blank.");
    [0012] }
    [0012] if (Var[13] == 25) {                                                 // Tentacle Mating Call
    [0017]   startSound(25);
    [0019] }
    [0019] if (Var[13] == 44) {                                                 // Melody Stinks
    [001E]   startSound(44);
    [0020] }
    [0020] if (Var[13] == 50) {                                                 // Good
    [0025]   startMusic(50);
    [0027]   if (VAR_ROOM == 20) {                                              // Green Tentacle's Room?

    [002C]     VAR_RESULT = getActorRoom(14);
    [002F]     if (VAR_RESULT == 20) {                                          // Green Tentacle in room?

    [0034]       VAR_RESULT = isScriptRunning(102);
    [0037]       if (VAR_RESULT == 0) {                                         // Accept Tape script running?
    [003C]         Var[138] = 1;                                                // Green Tentacle heard tape playing
    [003F]         startScript(102);                                            // Green Tentacle: Accepts Tape
    [0041]       }
    [0041]     }
    [0041]   }
    [0041] }
    [0041] if (Var[13] == 52) {                                                 // 52 = Green Tentacle
    [0046]   startMusic(52);
    [0048] }
    [0048] stopObjectCode();
}


 /**
  * Script 105: Contract: Given to actor
  */
Script-105 {
    [0000] if (VAR_ACTIVE_ACTOR < 8) {                                          // One of the kids?
    [0005]   setOwnerOf(0,VAR_ACTIVE_ACTOR);                                    //  Set them as the owner

    [0008] } else {

    [000B]   if (VAR_ACTIVE_ACTOR == 14) {                                      // If Green Tentacle
    [0010]     stopScript(103);                                                 //  Stop Green Tentacle: So Depressed
    [0012]     setOwnerOf(0,0);

    [0015]     if (Var[82] == 2) {                                              //  Contract: Accept Content == Contract for Player
    [001A]       cursorCommand( kModeCutscene )                                 //   Cutscene Mode
    [001C]       print(14,"Oh, so you got a contract for yourself?");
    [003F]       breakHere();                                                   // Engine Tick
    [0040]       unless (VAR_HAVE_MSG == 0) goto 003F;

    [0045]       print(14,"Thanks alot! I think I'll kill myself!");
    [0068]       breakHere();                                                   // Engine Tick
    [0069]       unless (VAR_HAVE_MSG == 0) goto 0068;

    [006E]       delay(120);
    [0072]       print(14,"On second thought%");
    [0085]     } else {

    [0088]       if (Var[82] == 3) {                                            //  Contract: Accept Content == Contract for Green
    [008D]         Var[137] = 1;                                                //  Green Tentacle: Is a friend
    [0090]         startScript(156);                                            //  Green Tentacle: Walk to current kid
    [0092]         setActorBitVar(VAR_EGO,kActorMiscFlagGTFriend,1);            //  Kid is green tentacle's friend (recording contract)

    [0096]         print(14,"A recording contract for ME??");
    [00B2]         breakHere();                                                 // Engine Tick
    [00B3]         unless (VAR_HAVE_MSG == 0) goto 00B2;

    [00B8]         delay(120);

    [00BC]         print(14,"This is GREAT!/We'll call our band%/%`GT and the Suction Cups.`/We'll be on MTV and everything!/And don't forget%/%I'll protect you no matter what!");
    [013D]         breakHere();                                                 // Engine Tick
    [013E]         unless (VAR_HAVE_MSG == 0) goto 013D;

    [0143]         print(14,"Now all we have to do is get rid of%/%that meteor.");
    [016E]       }
    [016E]       unless (Var[82] == 1) goto 01B1;                               // Contract: Accept Content != Contract for Meteor

    [0173]       cursorCommand( kModeCutscene )                                 // Cutscene Mode
    [0175]       print(14,"A contract for the evil meteor?/You're on IT'S side! GRRRR.");
    [01AA]     }

    [01AA]     Var[76] = 4;                                                     // Killed by Tentacle
    [01AD]     startScript(56);                                                 // Cutscene: Kid Dies
    [01AF]     stopScript(0);
    [01B1]   }

    [01B1]   if (VAR_ACTIVE_ACTOR == 13) {
    [01B6]     startScript(114);                                                // Purple Tentacle: Given Contract
    [01B8]   }

    [01B8]   if (VAR_ACTIVE_ACTOR == 16) {
    [01BD]     startScript(113);                                                // Meteor: Given Contract
    [01BF]   }
    [01BF] }
    [01BF] stopObjectCode();
}


 /**
  * Script 106: Door Bell
  */
Script-106 {
    [0000] delay(18000);                                                        // Sleep for 5 minutes
    [0004] delay(300);                                                          // Sleep for 5 seconds

    [0008] if (VAR_ROOM != 1) {                                                 // Not currently in Front of mansion

    [000D]   if (VAR_ROOM != 26) {                                              // Not currently in Weird Ed's Room

    [0012]     VAR_RESULT = getActorRoom("Weird Ed");
    [0015]     if (VAR_RESULT == 26) {                                          // If Weird Ed not in room, loop
    [001A]       goto 0020;
    [001D]     }
    [001D]   }
    [001D] }
    [001D] goto 0004;

    [0020] startSound(39);                                                      // Door Bell
    [0022] clearState08(24);                                                    // Package
    [0024] clearState02(24);                                                    // Package

    [0026] delay(480);                                                          // Sleep 8 seconds
    [002A] VAR_RESULT = getActorRoom("Weird Ed");
    [002D] unless (VAR_RESULT == 26) goto 0026;                                 // Wait for Weird Ed to enter room

    [0032] if (VAR_ROOM != 1) {                                                 // Not at front of the mansion?
    [0037]   startSound(39);                                                    //  Ring Door Bell again
    [0039] }

    [0039] stopScript(111);                                                     // Room: Weird Ed. Handle Object Interactions
    [003B] Var[127] = 1;                                                        // Weird Ed Trigger = Door Bell
    [003E] startScript(82);                                                     // Weird Ed: Leave Room
    [0040] stopObjectCode();
}


 /**
  * Script 107: 3 Guys who Pub Anything: TV Commercial
  */
Script-107 {
    [0000] cutscene();                                                          // Start Cutscene
    [0001] delay(120);
    [0005] beginOverride();
    {
        [0009] loadRoom(40);
        [000B] putActorInRoom(17,40);                                               // Put Mark Eteer in 3 Guys who publish anything (TV)
        [000E] putActor(17,17,52);
        [0012] animateActor(17,6,1);                                                // Mark Face Camera
        [0016] delay(60);                                                           // Sleep 1 second

        [001A] print(17,"Hi all you budding writers, musicians,/and game designers!/I'm Mark Eteer and my company%/%will publish ANYTHING!/Just mail it to the address shown below.");
        [00A2] delay(30);                                                           // Sleep 1/2 second
        [00A6] clearState08(249);                                                   //
        [00A8] delay(60);                                                           // Sleep 1 second
        [00AC] setState08(249);
        [00AE] unless (VAR_HAVE_MSG == 0) goto 00A2;

        [00B3] print(17,"Don't forget the stamp!");
        [00CA] delay(120);
    }
    [00CE] setActorBitVar(VAR_EGO,kActorMiscFlagWatchedTV,1);                   // Actor has publisher's address (watched TV)
    [00D2] endcutscene();                                                       // End Cutscene
    [00D3] clearState08(157);
    [00D5] stopObjectCode();
}


 /**
  * Script 108: Typewriter: Actor Using
  */
Script-108 {
    [0000] startSound(45);                                                      // Start Typing
    [0002] cursorCommand( kModeCutscene )                                       // Cutscene Mode
    [0004] delay(300);                                                          // Wait 5 seconds
    [0008] cursorCommand( kModeNormal )                                         // Cutscene Mode Normal
    [000A] stopSound(45);                                                       // Stop Typing
    [000C] stopObjectCode();
}


 /**
  * Script 109: Intro: Kid Selection: Update Var States
  */
Script-109 {
    [0000] startSound(54);

    [0002] if (getState08(activeObject)) {
    [0005]   clearState08();                                                    // Unselect Kid
    [0006]   Var[92] -= 1;                                                      // Number Selected -= 1

    [0009]   if (Var[92] == 2) {                                                // if 2 kids selected
    [000E]     if (Var[90] != Var[99]) {                                        //      and the third kid was not de-selected
    [0013]       Var[98] = Var[99];                                             //          Kid2 = Kid3
    [0016]     }
    [0016]   }
    [0016]   print(255," ");

    [001A] } else if (Var[92] < 3) {                                            // Select Kid: Less than 3 selected?
    [0022]   Var[92]++;                                                         // Number Selected += 1
    [0024]   setState08();

    [0025]   if (Var[92] == 2) {
    [002A]     Var[98] = Var[90];                                               // Kid2 = Kid icon pushed
    [002D]   }

    [002D]   if (Var[92] == 3) {
    [0032]     Var[99] = Var[90];                                               // Kid3 = Kid icon pushed
    [0035]   }
    [0035] }
    [0035] stopObjectCode();
}


 /**
  * Script 110: Green Tentacle: Storm Dr. Freds Lab
  */
Script-110 {
    [0000] stopScript(36);                                                      // Stop Cutscene: Meteor Police
    [0002] Var[104] = 1;

    [0005] if (VAR_ROOM == 8) {                                                 // In Basement?
    [000A]   putActorAtObject(14,121);                                          // Put Green Tentacle on the Basement Stairs
    [000D] } else {
    [0010]   setState08(130);
    [0012]   setState08(133);
    [0014]   putActorInRoom(14,31);                                             // Put Green Tentacle in the Lab: Entry
    [0017]   putActorAtObject(14,133);                                          // Put Green Tentacle at the door of the Lab
    [001A] }

    [001A] actorFollowCamera(14);                                               // Camera follows Green Tentacle
    [001C] print(13,"ooops!");                                                  // Purple Tentacle Speaks

    [0025] walkActorToActor(14,13,5);                                           // Green walks to Purple
    [0029] breakHere();                                                         // Engine Tick
    [002A] breakHere();                                                         // Engine Tick
    [002B] VAR_RESULT = getActorMoving(14);
    [002E] unless (VAR_RESULT == 2) goto 002A;                                  // Sleep until Green arrives

    [0033] actorFollowCamera(VAR_EGO);                                          // Camera follow player
    [0035] print(14,"What are you doing to MY friend!!/I've warned you%/%don't mess around with my band members!/NOW GET OUT OF HERE!");
    [0096] breakHere();                                                         // Engine Tick
    [0097] unless (VAR_HAVE_MSG == 0) goto 0096;                                // Sleep until talking finished

    [009C] Var[92] = 13;
    [009F] if (VAR_ROOM == 8) {
    [00A4]   walkActorToObject(Var[92],121);                                    // Walk Purple Tentacle to Basement Stairs
    [00A7] } else {
    [00AA]   walkActorToObject(Var[92],133);                                    // Walk Purple Tentacle to Lab Entry Door
    [00AD] }

    [00AD] delay(60);                                                           // Sleep 1 second
    [00B1] if (Var[92] == 13) {
    [00B6]   print(14,"That'll take care of him!");                             // Green Speaks
    [00CE] }

    [00CE] breakHere();                                                         // Engine Tick
    [00CF] VAR_RESULT = getActorMoving(Var[92]);                                // Wait until Purple stops moving
    [00D2] unless (VAR_RESULT == 2) goto 00CE;

    [00D7] delay(60);                                                           // Sleep 1 second
    [00DB] putActorInRoom(Var[92],0);                                           // Purple exits to room 0
    [00DE] putActor(Var[92],0,0);
    [00E2] Var[92]++;
    [00E4] unless (Var[92] == 15) goto 009F;

    [00E9] cursorCommand( kModeNoNewKid )                                       // Disable New Kid verb
    [00EB] Var[135] = 1;                                                        // Purple chased out of lab = Yes
    [00EE] stopObjectCode();
}


 /**
  * Script 111: Weird Ed. Handle Object Interactions
  */
Script-111 {
    [0000] if (Var[107] == 2) {                                                 // Is Piggy Bank
    [0005]   if (!getState08(2)) {
    [0009]     startSound(10);                                                  // Piggy Bank Break
    [000B]     setState08();                                                    // Set Broken
    [000C]     delay(60);                                                       // Sleep 1 second
    [0010]     printEgo("Damn! I broke it!");
    [0020]     breakHere();                                                     // Engine Tick
    [0021]     unless (VAR_HAVE_MSG == 0) goto 0020;                            // Wait for talking
    [0026]   }
    [0026] }

    [0026] if (Var[87] == 1) {
    [002B]   goto 0039;
    [002E] } else {
    [0031]   VAR_RESULT = getActorRoom("Weird Ed");
    [0034]   if (VAR_RESULT != 26) {                                            // Weird Ed out of his room
    [0039]     if (Var[107] != 2) {                                             //  Not Piggy Bank?
    [003E]       pickupObject(0);                                               //   Take the object
    [0040]     }
    [0040]     Var[107] = 0;
    [0043]   } else {
    [0046]     cursorCommand( kModeNoNewKid )                                   // Disable New Kid verb
    [0048]     Var[94] = VAR_EGO;
    [004B]     setActorBitVar(Var[94],8,1);                                     // Current kid is Eds' Enemy (kActorMiscFlagEdsEnemy)
    [004F]     stopScript(91);                                                  // stop Weird Ed: Help Find Plans
    [0051]     stopScript(86);                                                  // stop Weird Ed: Check for friendly actors
    [0053]     stopScript(83);                                                  // stop Weird Ed: Check for hostile actors
    [0055]     print(11,"What are you doing!!!/You're not supposed to touch that!");

    [0088]     walkActorToActor(11,Var[94],2);                                  // Walk Weird Ed to current kid
    [008C]     breakHere();                                                     // Engine Tick
    [008D]     VAR_RESULT = getDist(11,Var[94]);
    [0091]     unless (VAR_RESULT <= 2) goto 0088;                              // Wait until distance <= 2
    [0096]     setActorBitVar(Var[94],64,1);                                    // Kid kActorMiscFlagFreeze
    [009A]     animateActor(Var[94],255,1);
    [009E]     breakHere();                                                     // Engine Tick
    [009F]     unless (VAR_HAVE_MSG == 0) goto 009E;                            // Wait until talking finishes

    [00A4]     delay(60);                                                       // Sleep 1 second
    [00A8]     startScript(84);                                                 // start Weird Ed: Take kid to dungeon
    [00AA]     cursorCommand( kModeNormal )                                     // Cutscene Mode Normal
    [00AC]   }
    [00AC] }
    [00AC] Var[107] = 0;
    [00AF] stopObjectCode();
}


 /**
  * Script 112: Purple Tentacle: Check Actor X > 20; print "What are you doing here?"
  */
Script-112 {
    [0000] loadScript(43);
    [0002] breakHere();                                                         // Engine Tick
    [0003] VAR_RESULT = getActorX(VAR_EGO);
    [0006] unless (VAR_RESULT >= 20) goto 0002;                                 // Wait until actor x >= 20

    [000B] print(13,"What are YOU doing here?");
    [0022] startScript(43);                                                     // Purple Tentacle: Check for close actors
    [0024] stopObjectCode();
}


 /**
  * Script 113: Meteor: Given Contract
  */
Script-113 {
    [0000] setOwnerOf(27,0);
    [0003] unlockScript(105);
    [0005] if (Var[82] == 1) {                                                  // if Contract for Meteor
    [000A]   cursorCommand( kModeCutscene )                                     //  Cutscene Mode
    [000C]   stopScript(121);                                                   //  stop Dr Fred: Machine Turned Off
    [000E]   Var[89] = 2;                                                       //  Meteor Loose
    [0011]   Var[82] = 4;                                                       //  Contract Given
    [0014]   print(255,"Wow! A lucrative publishing contract!");
    [0038]   animateActor(16,1,255);                                            //  Meteor
    [003C]   startSound(67);
    [003E]   stopScript(118);                                                   //  stop Nuclear Meltdown Countdown
    [0040]   stopScript(123);                                                   //  stop Meteor: Fire Radiation
    [0042]   unlockCostume(20);
    [0044]   putActorInRoom(20,0);                                              //  Meteor Radiation Leaves room
    [0047]   putActor(20,0,0);
    [004B]   breakHere();                                                       // Engine Tick
    [004C]   unless (VAR_HAVE_MSG == 0) goto 004B;                              //  Wait for finish talking

    [0051]   print(255,"I'm going to be famous!/I don't have to be evil anymore.");
    [0082]   startSound(67);
    [0084]   breakHere();                                                       // Engine Tick
    [0085]   unless (VAR_HAVE_MSG == 0) goto 0084;                              //  Wait for finish talking

    [008A]   print(255,"Dr. Fred%/%release the women, all the women./We're going to be rich!");
    [00C7]   startSound(67);
    [00C9]   breakHere();                                                       // Engine Tick
    [00CA]   unless (VAR_CHARCOUNT > 33) goto 00C9;

    [00CF]   startSound(66);
    [00D1]   breakHere();                                                       // Engine Tick
    [00D2]   unless (VAR_HAVE_MSG == 0) goto 00D1;                              //  Wait for finish talking

    [00D7]   animateActor(16,0,1);
    [00DB]   startSound(67);
    [00DD]   delay(120);
    [00E1]   stopSound(67);
    [00E3]   startScript(58);
    [00E5] } else {
    [00E8]   print(255,"I don't want that! Prepare to die!!!");
    [0109]   startSound(66);
    [010B]   animateActor(16,1,255);
    [010F]   breakHere();                                                       // Engine Tick
    [0110]   unless (VAR_HAVE_MSG == 0) goto 010F;                              //  Wait for finish talking

    [0115]   animateActor(16,0,1);                                              //  Meteor
    [0119] }
    [0119] stopObjectCode();
}


 /**
  * Script 114: Purple Tentacle: Given Contract
  */
Script-114 {
    [0000] cutscene();                                                          // Start Cutscene
    [0001] if (Var[82] == 1) {                                                  // if Contract for Meteor ?
    [0006]   stopScript(112);                                                   //  Stop Purple Tentacle: Check Actor X > 20; print "What are you doing here?"
    [0008]   stopScript(43);                                                    //  Stop Purple Tentacle: Check for close actors
    [000A]   stopScript(36);                                                    //  Stop Cutscene: Meteor Police
    [000C]   beginOverride();
    {
        [0010]   print(13,"A publishing contract for the meteor?/It'll be happy to see that!/Sorry I bothered you!/Move along, move along.");
        [0072]   breakHere();                                                       // Engine Tick
        [0073]   unless (VAR_HAVE_MSG == 0) goto 0072;                              //  Wait for finish talking

        [0078]   Var[135] = 1;                                                      //  Purple chased out of lab = Yes
        [007B]   walkActorTo(13,40,52);                                             //  Walk Purple Tentacle
        [007F]   print(255," ");
        [0083]   setActorBitVar(VAR_EGO,64,0);                                      //  Actor Stop
        [0087]   stopScript(36);                                                    //  Stop Cutscene: Meteor Police
        [0089] } else {
        [008C]   print(13,"Hah! I don't want that!");
        [00A2]   breakHere();                                                       // Engine Tick
        [00A3]   unless (VAR_HAVE_MSG == 0) goto 00A2;                              //  Wait for finish talking
        [00A8] }
    }
    [00A8] endcutscene();                                                       // End Cutscene
    [00A9] stopObjectCode();
}


 /**
  * Script 115: Cutscene: Intro: Comet / Mansion
  */
Script-115 {
    [0000] cutscene();                                                          // Start Cutscene
    [0001] beginOverride();
    {
        [0005] loadCostume(22);
        [0007] lockCostume(22);
        [0009] loadRoom_c64(49);                                                    // "MANIAC MANSION" Scrolling
        [000B] lockRoom(49);
        [000D] loadScript(130);
        [000F] lockScript(130);
        [0011] loadSound(57);
        [0013] loadRoom(33);                                                        // Mansion At Distance (Lights Off)
        [0015] setCameraAt(60);                                                     // Camera at right of room
        [0017] startSound(56);                                                      // Comet
        [0019] delay(120);
        [001D] print(255,"Twenty years ago today...");
        [0036] delay(180);                                                          // Sleep 3 seconds
        [003A] startScript(130);                                                    // Start Intro: Comet: Fly and Crash

        [003C] breakHere();                                                         // Engine Tick
        [003D] VAR_RESULT = isScriptRunning(130);
        [0040] unless (VAR_RESULT == 0) goto 003C;                                  // Sleep until 'Intro: Comet: Fly and Crash' finishes

        [0045] delay(60);                                                           // Sleep 1 second
        [0049] startMusic(58);                                                      // MM Intro Music

        [004B] setState08(11);                                                      // Mansion Lights on
        [004D] breakHere();                                                         // Engine Tick

        [004E] setState08(10);                                                      // Mansion Lights on
        [0050] breakHere();                                                         // Engine Tick

        [0051] setState08(9);                                                       // Mansion Lights on
        [0053] breakHere();                                                         // Engine Tick

        [0054] setState08(8);                                                       // Mansion Lights on
        [0056] breakHere();                                                         // Engine Tick

        [0057] setState08(7);                                                       // Mansion Lights on

        [0059] delay(180);                                                          // Sleep 3 seconds
        [005D] print(255,"      A Lucasfilm Games Production");
        [007C] delay(180);                                                          // Sleep 3 seconds
        [0080] print(255,"        Designed and written by");
        [009B] delay(120);
        [009F] print(255,"      Ron Gilbert and Gary Winnick");
        [00BD] delay(240);
        [00C1] print(255,"             Programmed by");
        [00D7] delay(120);
        [00DB] print(255,"  Ron Gilbert, David Fox, and Carl Mey");
        [00FD] delay(240);
        [0101] print(255,"   Art and animation by Gary Winnick");
        [0122] delay(180);                                                          // Sleep 3 seconds
        [0126] print(255,"      Sound effects by Chris Grigg");
        [0144] delay(180);                                                          // Sleep 3 seconds
        [0148] print(255,"           Original music by");
        [0160] delay(120);
        [0164] print(255,"     Chris Grigg and David Lawrence");
        [0184] delay(180);                                                          // Sleep 3 seconds
        [0188] print(255," ");

        [018C] loadRoom(49);                                                        // "MANIAC MANSION" Scrolling
        [018E] setCameraAt(20);                                                     // Set camera to left of room

        [0190] panCameraTo(220);                                                    // Pan camera to right of room
        [0192] breakHere();                                                         // Engine Tick
        [0193] unless (VAR_CAMERA_POS_X == 180) goto 0192;                          // Sleep until camera finishes pan
    }

    [0198] stopScript(130);                                                     // Stop Intro: Comet: Fly and Crash
    [019A] unlockRoom(49);
    [019C] unlockCostume(22);
    [019E] unlockScript(130);
    [01A0] endcutscene();                                                       // End Cutscene
    [01A1] stopObjectCode();
}


 /**
  * Script 116: Verb: Generic: Open Door
  */
Script-116 {
    [0000] if (!getState08(activeObject)) {                                     // Is Door closed
    [0003]   setState08();                                                      //  Open It
    [0004]   startSound(8);                                                     //  Open Door Sound
    [0006] }
    [0006] stopObjectCode();
}


 /**
  * Script 117: Verb: Generic: Close Door
  */
Script-117 {
    [0000] if (getState08(activeObject)) {                                      // Is Door open
    [0003]   clearState08();                                                    //  Close It
    [0004]   startSound(9);                                                     //  Close Door Sound
    [0006] }
    [0006] stopObjectCode();
}


 /**
  * Script 118: Nuclear Meltdown Countdown
  */
Script-118 {
    [0000] loadSound(60);
    [0002] lockSound(60);
    [0004] delay(120);
    [0008] breakHere();                                                         // Engine Tick
    [0009] unless (VAR_HAVE_MSG == 0) goto 0008;                                // Sleep until text finished

    [000E] startSound(60);                                                      // Beep Sound                                               // Beep Sound
    [0010] print(255,"Time remaining:/2:00 minutes until meltdown%");
    [003B] delay(900);                                                          // Sleep 15 seconds
    [003F] startSound(60);                                                      // Beep Sound
    [0041] if (VAR_HAVE_MSG == 0) {
    [0046]   print(255,"1:45 minutes%");
    [0055] }
    [0055] delay(900);                                                          // Sleep 15 seconds

    [0059] startSound(60);                                                      // Beep Sound
    [005B] if (VAR_HAVE_MSG == 0) {
    [0060]   print(255,"1:30 minutes%");
    [006F] }
    [006F] delay(900);                                                          // Sleep 15 seconds

    [0073] startSound(60);                                                      // Beep Sound
    [0075] if (VAR_HAVE_MSG == 0) {
    [007A]   print(255,"1:15 minutes%");
    [0089] }
    [0089] delay(900);                                                          // Sleep 15 seconds

    [008D] startSound(60);                                                      // Beep Sound
    [008F] if (VAR_HAVE_MSG == 0) {
    [0094]   print(255,"1:00 minute%");
    [00A2] }
    [00A2] delay(900);                                                          // Sleep 15 seconds

    [00A6] startSound(60);                                                      // Beep Sound
    [00A8] if (VAR_HAVE_MSG == 0) {
    [00AD]   print(255,"45 seconds%");
    [00BA] }
    [00BA] delay(900);                                                          // Sleep 15 seconds

    [00BE] startSound(60);                                                      // Beep Sound
    [00C0] if (VAR_HAVE_MSG == 0) {
    [00C5]   print(255,"30 seconds%");
    [00D2] }
    [00D2] delay(900);                                                          // Sleep 15 seconds

    [00D6] startSound(60);                                                      // Beep Sound
    [00D8] if (VAR_HAVE_MSG == 0) {
    [00DD]   print(255,"15 seconds%");
    [00EA] }
    [00EA] delay(300);                                                          // Wait 5 seconds

    [00EE] startSound(60);                                                      // Beep Sound
    [00F0] if (VAR_HAVE_MSG == 0) {
    [00F5]   print(255,"10 seconds%");
    [0102] }
    [0102] delay(300);                                                          // Wait 5 seconds

    [0106] startSound(60);                                                      // Beep Sound
    [0108] print(255,"5");
    [010C] delay(60);                                                           // Sleep 1 second

    [0110] startSound(60);                                                      // Beep Sound
    [0112] print(255,"4");
    [0116] delay(60);                                                           // Sleep 1 second

    [011A] startSound(60);                                                      // Beep Sound
    [011C] print(255,"3");
    [0120] delay(60);                                                           // Sleep 1 second

    [0124] startSound(60);                                                      // Beep Sound
    [0126] print(255,"2");
    [012A] delay(60);                                                           // Sleep 1 second

    [012E] startSound(60);                                                      // Beep Sound
    [0130] print(255,"1");
    [0134] delay(60);                                                           // Sleep 1 second

    [0138] startSound(60);                                                      // Beep Sound
    [013A] unlockSound(60);
    [013C] print(255,"0 seconds, self-destruct commencing.");
    [0160] delay(180);                                                          // Sleep 3 seconds

    [0164] startScript(57);                                                     // Start Cutscene: Game Over
    [0166] stopScript(0);
    [0168] stopObjectCode();
}


 /**
  * Script 119: Talk Show:  Talking to Meteor
  */
Script-119 {
Events:
  30 - 0012
  13 - 0012
   8 - 0038
    [0012] if (Var[56] != 0) {
    [0017]   loadCostume(15);
    [0019]   lockCostume(15);
    [001B] }
    [001B] loadSound(51);
    [001D] lockSound(51);
    [001F] putActorInRoom(18,42);                                               // Enters Talkshow Host
    [0022] putActor(18,59,61);

    [0026] putActorInRoom(16,42);                                               // Enters Meteor
    [0029] putActor(16,46,62);

    [002D] putActorInRoom(Var[100],42);                                         // Enters Kid
    [0030] putActor(Var[100],10,60);
    [0034] animateActor(Var[100],5,1);

    [0038] putActorInRoom(23,42);                                               // Enters Sandy (Cut-Scene)
    [003B] putActor(23,13,60);

    [003F] loadRoom(42);
    [0041] setCameraAt(50);                                                     // Camera to X 50
    [0043] delay(120);
    [0047] animateActor(18,6,1);                                                // Talkshow Host
    [004B] animateActor(16,0,1);                                                // Meteor

    [004F] print(18,"Welcome back from our break./We've been talking with the celebrity%/%rock who gave up a life of crime for%/%a career as a writer.");
    [00BE] breakHere();                                                         // Engine Tick
    [00BF] unless (VAR_HAVE_MSG == 0) goto 00BE;                                // Sleep until talking finishes

    [00C4] animateActor(18,4,1);                                                // Talkshow Host
    [00C8] breakHere();                                                         // Engine Tick

    [00C9] print(18,"So, Mr. Meteor, how does it feel%/%to be famous instead of infamous?");
    [0105] breakHere();                                                         // Engine Tick
    [0106] unless (VAR_HAVE_MSG == 0) goto 0105;                                // Sleep until talking finishes

    [010B] print(255,"Well, Wink, it feels great./But, I couldn't have done it alone%");
    [0143] startSound(67);
    [0145] animateActor(16,1,255);                                              // Meteor
    [0149] delay(180);                                                          // Sleep 3 seconds
    [014D] stopSound(67);

    [014F] panCameraTo(20);                                                     // Camera pans left
    [0151] animateActor(16,0,1);
    [0155] breakHere();                                                         // Engine Tick
    [0156] unless (VAR_CAMERA_POS_X == 20) goto 0155;                           // Wait for camera pan

    [015B] breakHere();                                                         // Engine Tick
    [015C] unless (VAR_HAVE_MSG == 0) goto 015B;                                // Wait for text

    [0161] if (Var[56] != 0) {                                                  // Meteor Police Called?
    [0166]   putActorInRoom(18,0);                                              //  Talkshow Host leaves
    [0169]   putActor(18,0,0);
    [016D]   delay(120);
    [0171]   startSound(60);                                                    //  Beep Sound
    [0173]   putActorInRoom(15,42);                                             //  Meteor police enters
    [0176]   putActor(15,4,64);
    [017A]   walkActorTo(15,42,64);

    [017E]   delay(60);                                                         //  Sleep 1 second
    [0182]   print(15,"I don't care if you've reformed%/%you're still coming with me!");
    [01BA]   panCameraTo(37);                                                   //  Pan Camera

    [01BC]   breakHere();                                                       // Engine Tick
    [01BD]   VAR_RESULT = getActorMoving(15);                                   //  Wait for Meteor police to finish walking
    [01C0]   unless (VAR_RESULT == 2) goto 01BC;

    [01C5]   breakHere();                                                       // Engine Tick
    [01C6]   unless (VAR_HAVE_MSG == 0) goto 01C5;                              //  Wait for text to finish

    [01CB]   startSound(60);                                                    //  Beep Sound
    [01CD]   putActorInRoom(15,0);                                              //  Meteor police leaves
    [01D0]   putActor(15,0,0);
    [01D4]   putActorInRoom(16,0);                                              //  Meteor leaves
    [01D7]   putActor(16,0,0);
    [01DB]   delay(60);                                                         //  Sleep 1 second
    [01DF] }
    [01DF] startMusic(51);
    [01E1] delay(180);                                                          // Sleep 3 seconds
    [01E5] stopObjectCode();
}


 /**
  * Script 120: Dr Fred: Entered Lab
  */
Script-120 {
    [0000] delay(60);                                                           // Sleep 1 second
    [0004] clearState08(136);                                                   // Close Door
    [0006] startSound(9);                                                       // Sound Door
    [0008] delay(60);

    [000C] walkActorTo(9,32,66);                                                // Walk Dr. Fred
    [0010] print(9,"Purple Tentacle! Invaders!!");
    [002C] breakHere();                                                         // Engine Tick
    [002D] unless (VAR_HAVE_MSG == 0) goto 002C;                                // Wait For Text To Finish
    [0032] delay(120);

    [0036] walkActorTo(9,26,66);                                                // Walk Dr. Fred
    [003A] print(9,"PURPLE TENTACLE!!");
    [004D] delay(360);                                                          // Sleep 5 seconds
    [0051] VAR_RESULT = getActorX(VAR_EGO);
    [0054] unless (VAR_RESULT >= 20) goto 003A;                                 // Wait until Dr. Fred's X >= 20

    [0059] print(9,"So%/%you've gotten past all my safeguards!/There's only one thing left to do!");

    [009E] walkActorToObject(9,162);                                            // Walk Dr. Fred to Buttons
    [00A1] breakHere();                                                         // Engine Tick
    [00A2] VAR_RESULT = getActorMoving(9);
    [00A5] unless (VAR_RESULT == 2) goto 00A1;                                  // Wait for Dr. Fred to finish walking

    [00AA] animateActor(9,7,1);                                                 // Dr. Fred Face Away
    [00AE] breakHere();                                                         // Engine Tick
    [00AF] VAR_RESULT = getActorX(VAR_EGO);
    [00B2] unless (VAR_RESULT >= 37) goto 00AE;                                 // Dr. Fred X must be >= 37

    [00B7] breakHere();                                                         // Engine Tick
    [00B8] unless (VAR_HAVE_MSG == 0) goto 00B7;                                // Wait For Text To Finish

    [00BD] print(9,"I'm arming the self-destruct mechanism./Only I know the secret code to stop it!");
    [0103] Var[92] = 12;                                                        // Push 12 buttons

    [0106] delay(30);
    [010A] startSound(54);                                                      // Sound Keypad Buttons
    [010C] Var[92] -= 1;
    [010F] unless (Var[92] == 0) goto 0106;                                     // Loop until Button sounded 12 times

    [0114] breakHere();                                                         // Engine Tick
    [0115] unless (VAR_HAVE_MSG == 0) goto 0114;                                // Wait For Text To Finish

    [011A] print(9,"There!/The house will blow up in 2 minutes./Heh heh heh!");
    [014C] startScript(118);                                                    // Start Nuclear Meltdown Countdown

    [014E] animateActor(9,5,1);                                                 // Dr. Fred Faces Right
    [0152] breakHere();                                                         // Engine Tick
    [0153] animateActor(9,6,1);                                                 // Dr. Fred Face Camera

    [0157] startScript(122);                                                    // Start Dr Fred: Walk back and forth
    [0159] stopObjectCode();
}


 /**
  * Script 121: Dr Fred: Free of machines control
  */
Script-121 {
    [0000] delay(300);                                                          // Wait 5 seconds
    [0004] Var[89] = 3;
    [0007] cutscene();                                                          // Start Cutscene
    [0008] loadRoom(30);
    [000A] Var[89] = 2;                                                         // Meteor Lock Switch On
    [000D] actorFollowCamera(9);                                                // Follow Dr. Fred
    [000F] delay(120);
    [0013] animateActor(9,6,1);                                                 // Dr. Fred Face Camera

    [0017] print(9,"Oh...what happened?/I feel much better now!/I'm free of this machine's control!");
    [005F] breakHere();                                                         // Engine Tick
    [0060] unless (VAR_HAVE_MSG == 0) goto 005F;                                // Wait For Text To Finish

    [0065] print(9,"But wait!/The self-destruct sequence was initated!/I'll try to turn it off.");

    [00A9] walkActorToObject(9,162);                                            // Walk Dr. Fred to Buttons
    [00AC] breakHere();                                                         // Engine Tick
    [00AD] VAR_RESULT = getActorMoving(9);
    [00B0] unless (VAR_RESULT == 2) goto 00AC;                                  // Wait for Dr. Fred to finish moving

    [00B5] Var[92] = 12;                                                        // Push button 12 times
    [00B8] delay(30);
    [00BC] startSound(54);
    [00BE] Var[92] -= 1;
    [00C1] unless (Var[92] == 0) goto 00B8;                                     // Button Sound 12 times

    [00C6] animateActor(9,5,1);                                                 // Dr. Fred Faces Right
    [00CA] breakHere();                                                         // Engine Tick
    [00CB] walkActorTo(9,54,64);                                                // Dr. Fred Walk toward camera

    [00CF] if (Var[18] != 3) {                                                  // if Meteor != Gone
    [00D4]   print(9,"I can't disable it!/The meteor must have control%/%of the entire system!");
    [0115]   breakHere();                                                       // Engine Tick
    [0116]   unless (VAR_HAVE_MSG == 0) goto 0115;                              // Wait For Text To Finish

    [011B]   VAR_RESULT = getActorRoom(VAR_EGO);
    [011E]   if (VAR_RESULT != 30) {                                            // Current kid not in room 30?
    [0123]     animateActor(9,5,1);                                             // Dr. Fred Faces Right
    [0127]   } else {
    [012A]     walkActorToActor(9,VAR_EGO,5);                                   // Dr. Fred walks to kid
    [012E]   }

    [012E]   print(9,"Hey kid!/You've got to help me!/We have to get rid of that meteor%/%once and for all!");
    [0177]   breakHere();                                                       // Engine Tick
    [0178]   unless (VAR_HAVE_MSG == 0) goto 0177;                              // Wait For Text To Finish

    [017D]   startScript(122);                                                  // Dr Fred: Walk back and forth
    [017F]   delay(120);
    [0183] } else {
    [0186]   stopScript(118);                                                   // Stop Nuclear Meltdown Countdown
    [0188]   print(9,"I did it!");
    [0192]   breakHere();                                                       // Engine Tick
    [0193]   unless (VAR_HAVE_MSG == 0) goto 0192;                              // Wait For Text To Finish

    [0198]   animateActor(9,254,255);
    [019C]   delay(180);                                                        // Sleep 3 seconds
    [01A0]   startScript(58);                                                   // Cutscene: Win Game
    [01A2]   stopScript(0);
    [01A4] }

    [01A4] Var[89] = 2;                                                         // Meteor Loose
    [01A7] endcutscene();                                                       // End Cutscene
    [01A8] stopObjectCode();
}


 /**
  * Script 122: Dr Fred: Walk back and forth
  */
Script-122 {
    [0000] walkActorTo(9,15,64);                                                // Dr. Fred walk to the left
    [0004] breakHere();                                                         // Engine Tick
    [0005] VAR_RESULT = getActorMoving(9);
    [0008] unless (VAR_RESULT == 2) goto 0004;                                  // Sleep until finished walking

    [000D] walkActorTo(9,45,64);                                                // Dr. Fred walk to the right
    [0011] breakHere();                                                         // Engine Tick
    [0012] VAR_RESULT = getActorMoving(9);
    [0015] unless (VAR_RESULT == 2) goto 0011;                                  // Sleep until finished walking

    [001A] goto 0000;                                                           // Repeat
    [001D] stopObjectCode();
}


 /**
  * Script 123: Meteor: Fire Radiation
  */
Script-123 {
    [0000] delay(120);                                                          // Sleep 2 seconds
    [0004] delay(60);                                                           // Sleep 1 second
    [0008] VAR_RESULT = getDist(16,VAR_EGO);
    [000C] unless (VAR_RESULT > 3) goto 0004;                                   // Sleep until distance between Meteor and Kid is > 3

    [0011] stopSound(62);                                                       // Stop Radiation sound
    [0013] startSound(62);                                                      // Start Radiation sound
    [0015] startSound(66);
    [0017] putActorInRoom(20,51);                                               // Meteor Radiation in Lab: Meteor room
    [001A] putActor(20,41,50);

    [001E] walkActorToActor(20,VAR_EGO,1);                                      // Walk Radiation to Kid
    [0022] breakHere();                                                         // Engine Tick
    [0023] VAR_RESULT = getDist(20,VAR_EGO);
    [0027] unless (VAR_RESULT <= 1) goto 001E;                                  // Sleep until distance is <= 1

    [002C] putActorInRoom(20,0);                                                // Radiation leaves room
    [002F] putActor(20,0,0);
    [0033] stopSound(62);                                                       // Stop sound
    [0035] startSound(62);                                                      // Start sound
    [0037] breakHere();                                                         // Engine Tick
    [0038] if (getState08(253)) {                                               // Radiation Suit in use?
    [003C]   goto 0004;                                                         //  Yes
    [003F] }
    [003F] cursorCommand( kModeCutscene )                                       // Cutscene Mode
    [0041] printEgo("YOWL!");
    [0048] animateActor(VAR_EGO,255,1);                                         // Freeze Kid
    [004C] delay(60);                                                           // Sleep 1 second
    [0050] startScript(57);                                                     // Start Cutscene: Game Over
    [0052] stopObjectCode();
}


 /**
  * Script 124: Wait for actor finish walk. Activate sandy
  */
Script-124 {
    [0000] delay(60);                                                           // Sleep 1 second
    [0004] VAR_RESULT = getActorMoving(VAR_EGO);
    [0007] if (VAR_RESULT == 2) {                                               // If kid has stopped
    [000C]   animateActor(23,1,1);                                              // Animate Sandy (Cut-Scene)
    [0010] }
    [0010] goto 0000;
    [0013] stopObjectCode();
}


 /**
  * Script 125: Edsel: Active Rocket Engine
  */
Script-125 {
    [0000] breakHere();                                                         // Engine Tick
    [0001] cutscene();                                                          // Start Cutscene
    [0002] Var[136] = 1;                                                        // Garage Destroyed = Yes
    [0005] startSound(64);
    [0007] delay(60);                                                           // Sleep 1 second
    [000B] setState08(101);                                                     // Edsel?
    [000D] setState08(153);                                                     // Edsel?
    [000F] delay(300);                                                          // Wait 5 seconds
    [0013] stopSound(64);
    [0015] loadRoom(0);
    [0017] putActorInRoom(21,46);                                               // Put Edsel (small, outro) in Top of mansion (Edsel)
    [001A] putActor(21,19,68);
    [001E] animateActor(21,5,1);                                                // "left" animation
    [0022] loadCostume(16);
    [0024] lockCostume(16);
    [0026] loadRoom_c64(48);
    [0028] lockRoom(48);
    [002A] loadRoom(46);                                                        // Top of mansion (Edsel)
    [002C] setCameraAt(20);
    [002E] startSound(65);                                                      //
    [0030] delay(300);                                                          // Wait 5 seconds

    [0034] walkActorTo(21,19,1);                                                // Edsel go up screen
    [0038] breakHere();                                                         // Engine Tick
    [0039] VAR_RESULT = getActorMoving(21);
    [003C] unless (VAR_RESULT == 2) goto 0038;                                  // Wait to Edsel finishes moving

    [0041] putActorInRoom(21,0);                                                // Edsel leaves
    [0044] putActor(21,0,0);
    [0048] delay(180);                                                          // Sleep 3 seconds
    [004C] if (Var[18] == 2) {                                                  // Meteor in Edsel?
    [0051]   putActorInRoom(16,48);                                             //  Meteor in 'Edsel in Space'
    [0054]   putActor(16,24,42);
    [0058]   loadRoom(48);                                                      //  Start Edsel in Space
    [005A]   setCameraAt(20);                                                   //
    [005C]   delay(60);                                                         //  Sleep 1 second
    [0060]   print(255,"Wheeeee!");
    [006B]   delay(180);                                                        //  Sleep 3 seconds
    [006F] }
    [006F] stopSound(65);
    [0071] Var[77] = 8;                                                         // Loop all actors from Radiation Suit to Dave
    [0074] VAR_RESULT = getActorRoom(Var[77]);
    [0077] if (VAR_RESULT == 16) {                                              // If Actor is in Garage
    [007C]   putActorInRoom(Var[77],52);                                        //  Put Actor in Destroyed Garage
    [007F]   putActor(Var[77],Var[77],60);
    [0083] }
    [0083] Var[77] -= 1;
    [0086] unless (Var[77] == 0) goto 0074;                                     // Dave Moved?

    [008B] endcutscene();                                                       // End Cutscene
    [008C] unlockCostume(16);
    [008E] unlockRoom(48);
    [0090] if (Var[18] == 2) {                                                  // Meteor in Edsel?
    [0095]   startScript(58);                                                   //  Start Cutscene: Win Game
    [0097]   stopScript(0);
    [0099] }
    [0099] stopObjectCode();
}


 /**
  * Script 126: Intro: Dave Welcome
  */
Script-126 {
    [0000] Var[40] = 100;
    [0003] loadSound(6);
    [0005] loadSound(8);
    [0007] loadSound(9);
    [0009] loadSound(38);
    [000B] loadRoom(44);
    [000D] lockScript(3);
    [000F] cutscene();                                                          // Start Cutscene
    [0010] startScript(52);                                                     // Repeat Outside Sound
    [0012] beginOverride();
    {
        [0016] animateActor(3,5,1);                                                 // Dave Face Right
        [001A] animateActor(Var[98],4,1);                                           // Kid 2 Face Left
        [001E] animateActor(Var[99],4,1);                                           // Kid 3 Face Left

        [0022] delay(60);                                                           // Sleep 1 second
        [0026] print(3,"Ok! This looks like the old mansion.");
        [0047] delay(60);                                                           // Sleep 1 second

        [004B] walkActorTo(3,18,60);                                                // Dave Walks to the left
        [004F] breakHere();                                                         // Engine Tick
        [0050] unless (VAR_HAVE_MSG == 0) goto 004F;                                // Wait for Dave to finish talking

        [0055] print(3,"I'm sure I saw Dr. Fred take Sandy here./It's up to us to get her out.");
        [008F] delay(120);
        [0093] walkActorTo(3,24,59);                                                // Dave walks back to the right
        [0097] breakHere();                                                         // Engine Tick
        [0098] unless (VAR_HAVE_MSG == 0) goto 0097;                                // Wait for Dave to finish talking

        [009D] print(3,"This could be real dangerous./If anyone wants to back out%");
        [00D1] breakHere();                                                         // Engine Tick
        [00D2] unless (VAR_HAVE_MSG == 0) goto 00D1;                                // Wait for Dave to finish talking

        [00D7] if (getState08(246)) {                                               // If Kid Select: Bernard
        [00DB]   print(5,"Ok, I'm outta here!");
        [00EE]   Var[52] = getActorX(5);                                            // Keep Bernards position
        [00F1]   Var[53] = getActorY(5);
        [00F4]   walkActorTo(5,38,64);                                              // Bernard walks to the very right

        [00F8]   if (Var[98] == 5) {                                                // Turn Bernard to the camera
        [00FD]     animateActor(Var[99],6,1);
        [0101]   } else {
        [0104]     animateActor(Var[98],6,1);
        [0108]   }
        [0108]   breakHere();                                                       // Engine Tick
        [0109]   VAR_RESULT = getActorMoving(5);
        [010C]   unless (VAR_RESULT == 2) goto 0108;                                // Wait for Bernard to finish walking

        [0111]   animateActor(5,5,1);                                               // Turn Bernard to the right
        [0115]   breakHere();                                                       // Engine Tick
        [0116]   unless (VAR_HAVE_MSG == 0) goto 0115;                              // Wait for any speaking to finish

        [011B]   print(3,"BERNARD! Don't be a tuna head!/It's Sandy we're talking about!");
        [0153]   breakHere();                                                       // Engine Tick
        [0154]   unless (VAR_CHARCOUNT > 28) goto 0153;                             //

        [0159]   animateActor(5,6,1);                                               // Bernard Face Camera
        [015D]   breakHere();                                                       // Engine Tick
        [015E]   animateActor(5,4,1);                                               // Bernard Face Left

        [0162]   breakHere();                                                       // Engine Tick
        [0163]   unless (VAR_HAVE_MSG == 0) goto 0162;                              // Wait for Dave to finish talking

        [0168]   delay(120);
        [016C]   print(5,"Ok.");

        [0172]   walkActorTo(5,Var[52],Var[53]);                                    // Return Bernard to original position
        [0176]   breakHere();                                                       // Engine Tick
        [0177]   breakHere();                                                       // Engine Tick
        [0178]   VAR_RESULT = getActorMoving(5);
        [017B]   unless (VAR_RESULT == 2) goto 0177;                                // Wait for Bernard to finish walking

        [0180]   animateActor(5,6,1);                                               // Bernard face camera
        [0184] }

        [0184] if (getState08(244)) {                                               // if Kid Select: Razor
        [0188]   print(2,"I heard Dr. Fred was kinda cute.");
        [01A5]   breakHere();                                                       // Engine Tick
        [01A6]   unless (VAR_HAVE_MSG == 0) goto 01A5;                              // Wait for Razor to finish talking
        [01AB] }

        [01AB] if (getState08(243)) {                                               // if Kid Select: Syd
        [01AF]   print(1,"Let's do it.");
        [01BC]   breakHere();                                                       // Engine Tick
        [01BD]   unless (VAR_HAVE_MSG == 0) goto 01BC;                              // Wait for Syd to finish talking
        [01C2] }

        [01C2] if (getState08(248)) {                                               // if Kid Select: Jeff
        [01C6]   print(7,"I thought we were going to the beach!");
        [01E7]   breakHere();                                                       // Engine Tick
        [01E8]   unless (VAR_HAVE_MSG == 0) goto 01E7;                              // Wait for Jeff to finish talking
        [01ED] }

        [01ED] if (getState08(245)) {                                               // if Kid Select: Michael
        [01F1]   print(4,"Did any of you guys see that movie?/Four kids went into this strange house/and...uh...never mind.");
        [0247]   breakHere();                                                       // Engine Tick
        [0248]   unless (VAR_HAVE_MSG == 0) goto 0247;                              // Wait for Michael to finish talking
        [024D] }

        [024D] delay(60);                                                           // Sleep 1 second
        [0251] print(3,"Ok, let's go rescue Sandy!");
        [026A] delay(60);                                                           // Sleep 1 second
    }

    [026E] animateActor(3,6,1);                                                 // Dave Face Camera
    [0272] breakHere();                                                         // Engine Tick

    [0273] animateActor(Var[98],6,1);                                           // Kid 2 Face Camera
    [0277] breakHere();                                                         // Engine Tick

    [0278] animateActor(Var[99],6,1);                                           // Kid 3 Face Camera
    [027C] endcutscene();                                                       // End Cutscene
    [027D] cursorCommand( kModeNormal )                                         // Cutscene Mode Normal
    [027F] stopObjectCode();
}


 /**
  * Script 127: Contract: Read State
  */
Script-127 {
    [0000] if (Var[82] == 2) {                                                  // if Contract: Accept Content == Contract for Player

    [0005]   if (Var[67] == VAR_EGO) {                                          // Contract: Who its For (Actor ID)
    [000A]     printEgo("Wow! It's a recording contract for ME!");

    [002C]   } else if (Var[67] == 1) {                                         // Contract: Who its For (Actor ID) == Syd
    [0034]     printEgo("It's a recording contract for Syd.");

    [0053]   } else {
    [0056]     printEgo("It's a recording contract for Razor.");                // Contract: Who its For (Actor ID) == Razor
    [0077]   }

    [0077] } else if (Var[82] == 3) {                                           // if Contract: Accept Content == Green Tentacle
    [007F]   printEgo("It's a recording contract%/%for Green Tentacle.");

    [00AB] } else {
    [00AE]   printEgo("It's a book publishing contract,/and it's worth MILLIONS!");
    [00E2] }
    [00E2] stopObjectCode();
}


 /**
  * Script 128: Game: Save/Load Disk Check Script
  */
Script-128 {
    [0000] breakHere();                                                         // Engine Tick
    [0001] unless (VAR_HAVE_MSG == 0) goto 0000;                                // Wait until no text

    [0006] if (Var[108] == 1) {                                                 // Game: Save/Load Status == Game Disk
    [000B]   print(255,"  The game disk is still in the drive.");
    [002C] }

    [002C] if (Var[108] == 2) {                                                 // No valid save game
    [0031]   print(255,"Disk doesn't contain a valid saved game.");
    [0056] }

    [0056] if (Var[108] == 3) {                                                 // Success
    [005B]   print(255,"           The game was saved.");
    [0074] }

    [0074] if (Var[108] == 0) {                                                 // Insert save-load disk
    [0079]   print(255,"      Put in a save-load game disk.");
    [0097] }

    [0097] delay(240);
    [009B] goto 0000;
    [009E] stopObjectCode();
}


 /**
  * Script 129: Radiation Suit: Enable Speaking Flag
  */
Script-129 {
    [0000] animateActor(8,254,1);                                               // Radiation Suit 'talking' (shows holding meteor)
    [0004] breakHere();                                                         // Engine Tick
    [0005] goto 0000;
    [0008] stopObjectCode();
}


 /**
  * Script 130: Intro: Comet: Fly and Crash
  */
Script-130 {
    [0000] putActorInRoom(22,33);                                               // Meteor enters
    [0003] putActor(22,80,5);
    [0007] actorFollowCamera(22);                                               // Camera follows Meteor

    [0009] walkActorTo(22,29,52);                                               // Meteor 'walks' to the hill
    [000D] breakHere();                                                         // Engine Tick
    [000E] breakHere();                                                         // Engine Tick
    [000F] VAR_RESULT = getActorMoving(22);
    [0012] unless (VAR_RESULT == 2) goto 000E;                                  // Wait for Meteor to arrive

    [0017] panCameraTo(20);                                                     // Pan camera to mansion
    [0019] putActor(22,80,0);                                                   // Meteor goes off screen
    [001D] stopSound(56);
    [001F] startSound(57);                                                      // Explosion
    [0021] breakHere();                                                         // Engine Tick
    [0022] putActor(22,29,52);                                                  // Meteor returns to hill

    [0026] Var[90] = 10;                                                        // 10 engine ticks
    [0029] breakHere();                                                         // Engine Tick
    [002A] Var[90] -= 1;
    [002D] unless (Var[90] == 0) goto 0029;                                     // loop

    [0032] putActorInRoom(22,0);                                                // Meteor leaves room
    [0035] putActor(22,0,0);
    [0039] stopObjectCode();
}


 /**
  * Script 131: Meteor Police: Timer until arrival
  */
Script-131 {
    [0000] delay(18000);                                                        // Sleep for 5 minutes

    [0004] startSound(37);                                                      // Sound Meteor Police
    [0006] delay(600);                                                          // Sleep for 10 seconds

    [000A] startScript(37);                                                     // start Cutscene: Meteor Police Arrived in Dungeon
    [000C] stopObjectCode();
}


 /**
  * Script 132: Dungeon Door Opened via Loose Brick
  */
Script-132 {
    [0000] if (!getState08(126)) {                                              // Is Entry Door open
    [0004]   startSound(8);
    [0006]   setState08(126);                                                   // Open Inside of Dungeon Entry Door
    [0008]   setState08(122);                                                   // Open Outside of Dungeon Entry Door
    [000A] }
    [000A] delay(180);                                                          // Wait 3 seeconds
    [000E] startScript(51);                                                     // Dungeon: Close Entry Door
    [0010] stopObjectCode();
}


 /**
  * Script 133: Find Kid in Room
  */
Script-133 {
    [0000] Var[90] = 7;                                                         // Loop from Jeff
    [0003] VAR_RESULT = getActorRoom(Var[90]);
    [0006] if (VAR_RESULT == Var[111]) {                                        // Is kid in room Var[111]
    [000B]   Var[112] = 0;                                                      //  Yes. Var[112] = 0
    [000E] }
    [000E] Var[90] -= 1;                                                        // Next Kid
    [0011] unless (Var[90] == 0) goto 0003;                                     // Until Null Actor
    [0016] stopObjectCode();
}


 /**
  * Script 134: Cutscene: Weird Ed & Nurse Edna Trigger #1
  *
  * Check if Weird Ed is in his room
  *
  * Check if a kid is in Weird Ed's Room
  * Check if a kid is in the level 3 hallway
  * Check if a kid is in Nurse Edna's Room
  *
  * Check if Nurse Edna is in her room
  * Check if Nurse Edna's Light is on
  *
  */
Script-134 {
    [0000] delay(25200);                                                        // Sleep 7 Minutes
    [0004] delay(1800);                                                         // Sleep 30 Seconds
    [0008] Var[112] = 1;                                                        // Can start Cutscene
    [000B] VAR_RESULT = getActorRoom("Weird Ed");
    [000E] if (VAR_RESULT != 26) {
    [0013]   Var[112] = 0;                                                      // Can start Cutscene = false; Ed has to be in his room
    [0016] }
    [0016] Var[111] = 26;                                                       // Is a kid in Weird Ed's Room
    [0019] startScript(133);                                                    //

    [001B] Var[111] = 38;                                                       // Is a kid in Level 3 Hallway
    [001E] startScript(133);                                                    //

    [0020] Var[111] = 19;                                                       // Is a kid in Nurse Edna's Room
    [0023] startScript(133);                                                    //

    [0025] VAR_RESULT = getActorRoom(10);
    [0028] if (VAR_RESULT != 19) {                                              // Is Nurse Edna in her room
    [002D]   Var[112] = 0;                                                      //  Can start Cutscene = false
    [0030] }

    [0030] VAR_RESULT = getBitVar(19,1);                                        // Nurse Ednas Room Light Off?
    [0034] if (VAR_RESULT != 0) {
    [0039]   Var[112] = 0;                                                      //  Can start Cutscene = false
    [003C] }
    [003C] unless (Var[112] == 1) goto 0004;                                    // Loop until
    [0041] startScript(135);                                                    // Start Cutscene: Weird Ed & Nurse Edna  #1
    [0043] stopObjectCode();
}


 /**
  * Script 135: Cutscene: Weird Ed & Nurse Edna  #1
  */
Script-135 {
    [0000] cutscene();                                                          // Start Cutscene
    [0001] setState08(70);                                                      // Open Inside Nurse Edna's Door
    [0003] putActorInRoom(11,19);                                               // Weird Ed enters Nurse Edna's Room
    [0006] putActor(11,18,64);
    [000A] putActorInRoom(10,19);                                               // Nurse Edna enters Nurse Edna's Room
    [000D] putActor(10,24,64);
    [0011] animateActor(11,5,1);                                                // Weird Ed Faces Right
    [0015] animateActor(10,4,1);                                                // Nurse Edna Faces Left
    [0019] loadRoom(19);
    [001B] setCameraAt(20);                                                     //

    [001D] beginOverride();
    {
        [0021] delay(60);                                                           // Sleep 1 second
        [0025] print(11,"Daddy's been acting very strangely ever%/%since his secret project in the lab%");
        [006B] breakHere();                                                         // Engine Tick
        [006C] unless (VAR_HAVE_MSG == 0) goto 006B;                                // Wait for Weird Ed to finish talking

        [0071] print(10,"YEAH SO!!!");
        [007D] breakHere();                                                         // Engine Tick
        [007E] unless (VAR_HAVE_MSG == 0) goto 007D;                                // Wait for Nurse Edna to finish talking

        [0083] print(11,"Well, Mommy, I'm worried about him./He hasn't been at dinner for 5 years%");
        [00C3] breakHere();                                                         // Engine Tick
        [00C4] unless (VAR_HAVE_MSG == 0) goto 00C3;                                // Wait for Weird Ed to finish talking

        [00C9] print(10,"YEAH, SO!!!");
        [00D6] breakHere();                                                         // Engine Tick
        [00D7] unless (VAR_HAVE_MSG == 0) goto 00D6;                                // Wait for Nurse Edna to finish talking

        [00DC] print(11,"%and he's been bringing those bodies%/%down into the basement late at night.");
        [0120] breakHere();                                                         // Engine Tick
        [0121] unless (VAR_HAVE_MSG == 0) goto 0120;                                // Wait for Weird Ed to finish talking

        [0126] print(10,"WHAT'S YOUR POINT ED?!/I'M A VERY BUSY LADY!");
        [014E] breakHere();                                                         // Engine Tick
        [014F] unless (VAR_HAVE_MSG == 0) goto 014E;                                // Wait for Nurse Edna to finish talking

        [0154] delay(120);
        [0158] animateActor(11,6,1);                                                // Weird Ed Faces Camera
        [015C] delay(120);
        [0160] animateActor(11,5,1);                                                // Weird Ed Faces Right

        [0164] print(11,"never mind.");
        [0171] breakHere();                                                         // Engine Tick
        [0172] unless (VAR_HAVE_MSG == 0) goto 0171;                                // Wait for Weird Ed to finish talking

        [0177] walkActorToObject(11,70);                                            // Walk Weird Ed to Door
        [017A] breakHere();                                                         // Engine Tick
        [017B] VAR_RESULT = getActorMoving(11);
        [017E] unless (VAR_RESULT == 2) goto 017A;                                  // Wait for Weird Ed to finish Walking
    }

    [0183] if (VAR_OVERRIDE == 1) {
    [0188]   loadRoom(0);
    [018A] }
    [018A] print(255," ");
    [018E] putActorInRoom(11,26);                                               // Weird Ed enters Weird Ed's Room
    [0191] putActor(11,10,52);
    [0195] clearState08(70);                                                    // Close Inside Nurse Edna's Door
    [0197] clearState08(185);                                                   // Close Hallway Nurse Edna's Door

    [0199] if (VAR_OVERRIDE == 0) {                                             // Didnt skip cutscene?
    [019E]   startSound(9);                                                     //  Sound Door Close
    [01A0]   delay(120);
    [01A4] }
    [01A4] endcutscene();                                                       // End Cutscene
    [01A5] stopObjectCode();
}


 /**
  * Script 136: Cutscene: Dr. Fred / Nurse Edna Trigger #1
  *
  * Check if a kid in level 3 hallway
  * Check if a kid in Nurse Ednas room
  * Check if Nurse Edna in her room
  * Check if Nurse Edna disabled
  * Check if Nurse Edna's Room Light is on
  *
  */
Script-136 {
    [0000] delay(18000);                                                        // Sleep for 5 minutes
    [0004] delay(1800);                                                         // Sleep for 30 seconds
    [0008] Var[112] = 1;

    [000B] Var[111] = 38;                                                       // In Level 3 Hallway?
    [000E] startScript(133);                                                    //

    [0010] Var[111] = 19;                                                       // In Nurse Edna's Room?
    [0013] startScript(133);                                                    //

    [0015] VAR_RESULT = getActorRoom(10);
    [0018] if (VAR_RESULT != 19) {                                              // Nurse Edna not in her room?
    [001D]   Var[112] = 0;
    [0020] }

    [0020] if (Var[17] == 1) {                                                  // is Nurse Edna Disabled?
    [0025]   Var[112] = 0;
    [0028] }

    [0028] VAR_RESULT = getBitVar(19,1);                                        // Is Nurse Edna's Room light on?
    [002C] if (VAR_RESULT != 0) {
    [0031]   Var[112] = 0;
    [0034] }
    [0034] unless (Var[112] == 1) goto 0004;                                    // Loop until conditions met

    [0039] startScript(137);                                                    // Start Cutscene: Dr. Fred / Nurse Edna #1
    [003B] stopObjectCode();
}


 /**
  * Script 137: Cutscene: Dr. Fred / Nurse Edna #1
  */
Script-137 {
    [0000] cutscene();                                                          // Start Cutscene
    [0001] setState08(70);
    [0003] putActorInRoom(9,19);                                                // Dr Fred enters Nurse Ednas Room
    [0006] putActor(9,2,52);
    [000A] putActorInRoom(10,19);                                               // Nurse Edna enters Nurse Ednas Room
    [000D] putActor(10,35,64);
    [0011] animateActor(9,5,1);                                                 // Dr. Fred Faces Right
    [0015] animateActor(10,5,1);                                                // Nurse Edna Faces Right
    [0019] loadRoom(19);
    [001B] setCameraAt(20);

    [001D] beginOverride();
    {
        [0021] breakHere();                                                         // Engine Tick
        [0022] walkActorToActor(9,10,8);                                            // Walk Dr.Fred to Nurse Edna
        [0026] delay(120);
        [002A] print(9,"Edna%/I'm having trouble with the Zom-B-Matic./I need to shut down the power./It'll be off for 5 or 6 minutes.");
        [0089] breakHere();                                                         // Engine Tick
        [008A] unless (VAR_HAVE_MSG == 0) goto 0089;                                // Wait for Dr. Fred to finish talking

        [008F] walkActorToActor(10,9,4);                                            // Walk Nurse Edna to Dr. Fred
        [0093] breakHere();                                                         // Engine Tick
        [0094] breakHere();                                                         // Engine Tick
        [0095] breakHere();                                                         // Engine Tick
        [0096] print(10,"Is this all you have to say to me?/You've been in the basement%/%for the past 5 years?/Sometimes I think you like that meteor%/%more than me!");
        [010E] breakHere();                                                         // Engine Tick
        [010F] unless (VAR_HAVE_MSG == 0) goto 010E;                                // Wait for Nnurse Edna to finish talking

        [0114] print(9,"Don't worry my little Beauty Queen%/%soon everything will be different.");
        [0155] breakHere();                                                         // Engine Tick
        [0156] unless (VAR_HAVE_MSG == 0) goto 0155;                                // Wait for Dr. Fred to finish talking

        [015B] walkActorToObject(9,70);                                             // Walk Dr. Fred to the Door
        [015E] animateActor(10,6,1);                                                // Nurse Edna faces camera
        [0162] delay(60);                                                           // Sleep 1 second
        [0166] print(10,"Sure.");
        [016E] delay(120);
        [0172] breakHere();                                                         // Engine Tick
        [0173] VAR_RESULT = getActorMoving(9);
        [0176] unless (VAR_RESULT == 2) goto 0172;                                  // Wait until Dr. Fred finishes walking

        [017B] putActorInRoom(9,0);                                                 // Dr. Fred leaves
        [017E] putActor(9,0,0);
        [0182] clearState08(70);                                                    // Close Nurse Ednas Door
        [0184] clearState08(185);                                                   // Close Nurse Ednas Door
    }

    [0186] if (VAR_OVERRIDE == 1) {
    [018B]   loadRoom(0);
    [018D] } else {
    [0190]   startSound(9);                                                     // Close door sound
    [0192]   delay(60);                                                         // Sleep 1 second
    [0196] }

    [0196] print(255," ");
    [019A] putActorInRoom(9,0);
    [019D] putActor(9,0,0);
    [01A1] startScript(138);                                                    // Start Cutscene: Dr. Fred Play Meteor Mess Trigger
    [01A3] endcutscene();                                                       // End Cutscene
    [01A4] stopObjectCode();
}


 /**
  * Script 138: Cutscene: Dr. Fred Play Meteor Mess Trigger
  */
Script-138 {
    [0000] delay(14400);                                                        // Sleep 4 minutes

    [0004] if (getState08(124)) {                                               // If power off
    [0008]   stopScript(0);
    [000A] }

    [000A] if (getState08(106)) {                                               // If pool empty
    [000E]   stopScript(0);
    [0010] }

    [0010] setState08(124);                                                     // Power Off
    [0012] startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    [0014] delay(18000);                                                        // Sleep for 5 minutes

    [0018] clearState08(124);                                                   // Power On
    [001A] startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    [001C] startScript(96);                                                     // Start Dr Fred: Play Meteor Mess
    [001E] stopObjectCode();
}


 /**
  * Script 139: Cutscene: Weird Ed & Dr. Fred Trigger #1
  */
Script-139 {
    [0000] delay(36000);                                                        // Sleep 10 minutes
    [0004] delay(1800);                                                         // Sleep 30 seconds
    [0008] Var[112] = 1;

    [000B] Var[111] = 38;                                                       // Find Kid in Level 3 Hallway
    [000E] startScript(133);
    [0010] Var[111] = 26;                                                       // Find Kid in Gym
    [0013] startScript(133);
    [0015] VAR_RESULT = getActorRoom("Weird Ed");
    [0018] if (VAR_RESULT != 26) {
    [001D]   Var[112] = 0;                                                      // Weird Ed not in his room
    [0020] }
    [0020] VAR_RESULT = getBitVar(26,1);
    [0024] if (VAR_RESULT != 0) {                                               // Light off in Weird Ed's room?
    [0029]   Var[112] = 0;
    [002C] }
    [002C] unless (Var[112] == 1) goto 0004;                                    // Wait for conditions

    [0031] startScript(140);                                                    // Start Cutscene: Weird Ed & Dr. Fred #1
    [0033] stopObjectCode();
}


 /**
  * Script 140: Cutscene: Weird Ed & Dr. Fred #1
  */
Script-140 {
    [0000] cutscene();                                                          // Start Cutscene
    [0001] putActorInRoom(11,26);                                               // Weird Ed enters his room
    [0004] putActor(11,6,66);
    [0008] beginOverride();
    {
        [000C] animateActor(11,6,1);                                                // Weird Ed faces Camera
        [0010] clearState08(6);
        [0012] loadCostume("DrFred");
        [0014] loadRoom(26);                                                        // Load Weird Ed's Room
        [0016] setCameraAt(21);
        [0018] delay(120);
        [001C] setState08(6);                                                       // Door Opens
        [001E] startSound(8);                                                       // Door opens
        [0020] delay(60);                                                           // Sleep 1 second

        [0024] putActorInRoom(9,26);                                                // Dr. Fred Enters
        [0027] putActorAtObject(9,6);
        [002A] animateActor(9,6,1);                                                 // Dr. Fred faces camera

        [002E] animateActor(11,5,1);                                                // Weird Ed faces right
        [0032] breakHere();                                                         // Engine Tick
        [0033] animateActor(11,7,1);                                                // Weird Ed fcaes away
        [0037] breakHere();                                                         // Engine Tick

        [0038] walkActorToActor(9,11,6);                                            // Dr. Fred walkts to Weird Ed
        [003C] print(9,"Hey Ed%/%the meteor wants to borrow%/%your hamster and electric cattle prod.");
        [0081] breakHere();                                                         // Engine Tick
        [0082] breakHere();                                                         // Engine Tick
        [0083] VAR_RESULT = getActorMoving(9);
        [0086] unless (VAR_RESULT == 2) goto 0082;                                  // Wait until Dr. Fred finishes walking

        [008B] animateActor(9,4,1);                                                 // Dr. Fred faces left
        [008F] animateActor(11,5,1);                                                // Weird Ed faces Right
        [0093] breakHere();                                                         // Engine Tick
        [0094] unless (VAR_HAVE_MSG == 0) goto 0093;                                // Wait until Dr. Fred finishes talking

        [0099] print(11,"My hamster!! NOBODY touches my HAMSTER!");
        [00BE] breakHere();                                                         // Engine Tick
        [00BF] unless (VAR_HAVE_MSG == 0) goto 00BE;                                // Wait until Weird Ed finishes talking

        [00C4] print(9,"Better watch it, Ed%/%you're going to piss-off the meteor./It already thinks you stole%/%my purple card key.");
        [0124] breakHere();                                                         // Engine Tick
        [0125] unless (VAR_HAVE_MSG == 0) goto 0124;                                // Wait until Dr. Fred finishes talking

        [012A] print(11,"Er%/I don't know what you're talking about!");
        [0152] breakHere();                                                         // Engine Tick
        [0153] unless (VAR_HAVE_MSG == 0) goto 0152;                                // Wait until Weird Ed finishes talking

        [0158] print(9,"I can't get to the meteor without it.");
        [0179] delay(120);
        [017D] walkActorToObject(9,6);                                              // Dr. Fred walks to the door
        [0180] delay(60);                                                           // Sleep 1 second
        [0184] animateActor(11,6,1);                                                // Dr. Fred faces camera
        [0188] breakHere();                                                         // Engine Tick
        [0189] unless (VAR_HAVE_MSG == 0) goto 0188;                                // Wait until Dr. Fred finishes talking

        [018E] print(11,"Oh, really?");
        [019B] breakHere();                                                         // Engine Tick
        [019C] VAR_RESULT = getActorMoving(9);
        [019F] unless (VAR_RESULT == 2) goto 019B;                                  // Wait until Dr. Fred finishes walking

        [01A4] animateActor(9,6,1);
        [01A8] breakHere();                                                         // Engine Tick
        [01A9] unless (VAR_HAVE_MSG == 0) goto 01A8;                                // Wait until Weird Ed  finishes talking

        [01AE] print(9,"Shape up, kid!");
        [01BD] breakHere();                                                         // Engine Tick
        [01BE] unless (VAR_HAVE_MSG == 0) goto 01BD;                                // Wait until Dr. Fred finishes talking

        [01C3] animateActor(9,5,1);                                                 // Dr. Fred Faces Right
        [01C7] breakHere();                                                         // Engine Tick
        [01C8] animateActor(9,7,1);                                                 // Dr. Fred faces away
        [01CC] breakHere();                                                         // Engine Tick
    }

    [01CD] putActorInRoom(9,0);                                                 // Dr. Fred leaves
    [01D0] putActor(9,0,0);

    [01D4] clearState08(6);                                                     // Door closes
    [01D6] clearState08(186);                                                   // Hall Door closes

    [01D8] startSound(9);
    [01DA] delay(120);
    [01DE] clearState08(6);                                                     // Door closes again
    [01E0] clearState08(186);                                                   // Hall Door closes again

    [01E2] print(255," ");
    [01E6] putActorInRoom(9,0);                                                 // Dr. Fred leaves again
    [01E9] putActor(9,0,0);
    [01ED] endcutscene();                                                       // End Cutscene
    [01EE] startScript(96);                                                     // Start Dr Fred: Play Meteor Mess
    [01F0] stopObjectCode();
}


 /**
  * Script 141: Dungeon: Calculate Kid Position
  */
Script-141 {
    [0000] Var[91] = 2;

    [0003] if (Var[90] == Var[97]) {                                            // is Kid 1
    [0008]   Var[91] = 0;
    [000B] }

    [000B] if (Var[90] == Var[98]) {                                            // is Kid 2
    [0010]   Var[91] = 1;
    [0013] }
    [0013] Var[91] += 52;
    [0016] stopObjectCode();
}


 /**
  * Script 142: Secret Lab: Enter Room
  */
Script-142 {
    [0000] Var[100] = VAR_EGO;
    [0003] breakHere();                                                         // Engine Tick

    [0004] if (Var[96] == 1) {                                                  // If Dave is Dead
    [0009]   loadCostume(Var[100]);

    [000B]   if (Var[100] == 4) {                                               //  Michael
    [0010]     lockCostume(4);
    [0012]   }

    [0012]   if (Var[100] == 6) {                                               //  Wendy
    [0017]     lockCostume(6);
    [0019]   }

    [0019]   if (Var[100] == 1) {                                               //  Syd
    [001E]     lockCostume(1);
    [0020]   }

    [0020]   if (Var[100] == 2) {                                               //  Razor
    [0025]     lockCostume(2);
    [0027]   }

    [0027]   if (Var[100] == 7) {                                               //  Jeff
    [002C]     lockCostume(7);
    [002E]   }

    [002E]   if (Var[100] == 5) {                                               //  Bernard
    [0033]     lockCostume(5);
    [0035]   }

    [0035] } else {
    [0038]   loadCostume(3);
    [003A]   lockCostume(3);
    [003C] }

    [003C] loadRoom(0);
    [003E] clearState08(110);                                                   // Close Gate
    [0040] setState04(110);                                                     // Lock Gate
    [0042] loadCostume("DrFred");                                               // Load Dr Fred costume
    [0044] lockCostume("DrFred")

    [0046] VAR_RESULT = getObjectOwner(27);                                     // Who has contract?
    [0049] if (VAR_RESULT == VAR_EGO) {                                         //  Does kid have the Contract?
    [004E]   loadScript(105);                                                   //   Load Contract: Given to actor
    [0050]   lockScript(105);                                                   //   Lock Contract: Given to actor
    [0052] }
    [0052] loadRoomWithEgo(136,30);                                             // Enter Lab: Hunk o Matic
    [0055] stopObjectCode();
}


 /**
  * Script 143: Cutscene: Dr. Fred / Sandy #1
  */
Script-143 {
    [0000] delay(3600);                                                         // Sleep 1 minute
    [0004] cutscene();                                                          // Start Cutscene
    [0005] beginOverride();
    {
        [0009] setState08(135);                                                     // Open Door
        [000B] putActorInRoom(9,31);                                                // Dr. Fred Enters
        [000E] putActor(9,15,58);
        [0012] putActorInRoom(24,31);                                               // Sandy Enters
        [0015] putActor(24,25,58);
        [0019] animateActor(9,5,1);                                                 // Dr. Fred Faces Right
        [001D] animateActor(24,4,1);                                                // Sandy Faces Left
        [0021] loadRoom(31);                                                        // Lab: Entry
        [0023] setCameraAt(20);
        [0025] delay(60);                                                           // Sleep 1 second

        [0029] print(9,"Well, my dear. Hope you're having fun!/Within minutes it'll all be over./You'll be hooked up to my machine%/%getting your pretty brains sucked out.");
        [00A9] walkActorToActor(9,24,5);                                            // Dr. Fred walks toward Sandy
        [00AD] breakHere();                                                         // Engine Tick
        [00AE] unless (VAR_CHARCOUNT > 66) goto 00AD;                               // Wait until number of chars have been said

        [00B3] animateActor(24,6,1);                                                // Sandy Faces Camera
        [00B7] animateActor(24,254,1);                                              // Sandy opens mouth
        [00BB] breakHere();                                                         // Engine Tick
        [00BC] unless (VAR_HAVE_MSG == 0) goto 00BB;                                // Wait until text finishes

        [00C1] print(24,"You'll never get away with this!/Dave and his friends will rescue me!/You and your meteor can eat slime!");
        [011B] breakHere();                                                         // Engine Tick
        [011C] unless (VAR_CHARCOUNT > 45) goto 011B;                               // Wait until number of chars have been said

        [0121] animateActor(24,4,1);                                                // Sandy Faces Left
        [0125] breakHere();                                                         // Engine Tick
        [0126] unless (VAR_HAVE_MSG == 0) goto 0125;                                // Wait Sandy finishes talking

        [012B] Var[90] = getActorX(9);
        [012E] walkActorTo(9,Var[90],68);                                           // Dr. Fred walks toward camera
        [0132] delay(60);                                                           // Sleep 1 second
        [0136] print(9,"That's what she thinks!");
        [014D] breakHere();                                                         // Engine Tick
        [014E] unless (VAR_HAVE_MSG == 0) goto 014D;                                // Wait Dr. Fred finishes talking

        [0153] walkActorToObject(9,135);                                            // Dr. Fred walks to door
        [0156] print(9,"Heh, heh, heh.");
        [0165] breakHere();                                                         // Engine Tick
        [0166] VAR_RESULT = getActorMoving(9);
        [0169] unless (VAR_RESULT == 2) goto 0165;                                  // Wait until Dr. Fred finishes walking

        [016E] putActorInRoom(9,0);                                                 // Dr. Fred leaves room
        [0171] putActor(9,0,0);
        [0175] clearState08(135);                                                   // Door closes
        [0177] startSound(9);

        [0179] walkActorToObject(24,133);                                           // Walk sandy to security door
        [017C] breakHere();                                                         // Engine Tick
        [017D] VAR_RESULT = getActorMoving(24);
        [0180] unless (VAR_RESULT == 2) goto 017C;                                  // Wait until Sandy finishes

        [0185] animateActor(24,7,1);                                                // Sandy faces away
        [0189] print(24,"Help, help, HELP!");
        [019B] breakHere();                                                         // Engine Tick
        [019C] unless (VAR_HAVE_MSG == 0) goto 019B;                                // Wait until Sandy finishes talking

        [01A1] delay(60);                                                           // Sleep 1 second
        [01A5] print(255," ");
    }

    [01A9] clearState08(135);                                                   // Door closes
    [01AB] endcutscene();                                                       // End Cutscene
    [01AC] putActorInRoom(24,0);                                                // Sandy leaves room
    [01AF] putActor(24,0,0);
    [01B3] startScript(151);                                                    // start Cutscene: Purple Tentacle chases Sandy Trigger
    [01B5] stopObjectCode();
}


 /**
  * Script 144: Gargoyle: Open Basement Door
  */
Script-144 {
    [0000] if (!getState08(36)) {                                               // Get state of basement door
    [0004]   setState08(36);                                                    // Open basement door
    [0006]   startSound(8);
    [0008] }

    [0008] Var[123] = VAR_EGO;                                                  // Current Actor
    [000B] Var[124] = getActorX(Var[123]);                                      // Store Current Actor X
    [000E] Var[125] = getActorY(Var[123]);                                      // Store Current Actor Y

    [0011] breakHere();                                                         // Engine Tick
    [0012] VAR_RESULT = getActorX(Var[123]);
    [0015] if (VAR_RESULT == Var[124]) {                                        // X Not Changed?
    [001A]   VAR_RESULT = getActorY(Var[123]);
    [001D]   if (VAR_RESULT == Var[125]) {                                      // Y Not Changed?
    [0022]     goto 0011;                                                       // Wait for Actor to move
    [0025]   }
    [0025] }

    [0025] startSound(9);                                                       // Door close sound
    [0027] clearState08(36);                                                    // Close basement door
    [0029] stopObjectCode();
}


 /**
  * Script 145: Flashlight: Check
  */
Script-145 {
    [0000] delay(60);                                                           // Sleep 1 second
    [0004] Var[126] -= 1;                                                       // Flashlight Battery --
    [0007] Var[90] = getObjectOwner(51);                                        // Who owns flash light

    [000A] VAR_RESULT = getActorRoom(Var[90]);                                  // Room of the owner
    [000D] if (VAR_RESULT == 15) {                                              // if Room == Electrical Wiring
    [0012]   Var[126] = 0;
    [0015] }
    [0015] unless (Var[126] == 0) goto 0000;                                    // Loop until battery runs out, or room is electrical

    [001A] if (Var[90] == 15) {                                                 // Flash light owned by Meteor Police ??
    [001F]   stopScript(0);
    [0021] }

    [0021] breakHere();                                                         // Engine Tick
    [0022] VAR_RESULT = getObjectOwner(51);
    [0025] unless (VAR_RESULT == VAR_EGO) goto 0021;                            // Sleep until owner is current actor

    [002A] Var[12] = 0;                                                         // Flashlight Status = Off
    [002D] startScript(77);                                                     // start Flashnight: Name

    [002F] Var[31] = 0;                                                         // Flashlight has no battery
    [0032] delay(120);
    [0036] printEgo("Looks like the batteries went dead./Maybe I can find some others.");
    [006F] stopObjectCode();
}


 /**
  * Script 146: Weird Ed: Check Fridge
  */
Script-146 {
    [0000] Var[71] = 20;                                                        // Weird Ed Target X
    [0003] Var[72] = 52;                                                        // Weird Ed Target Y
    [0006] delay(300);                                                          // Wait 5 seconds
    [000A] setState08(35);                                                      // Kitchen Door Opens
    [000C] setState08(48);                                                      // Kitchen In-Door Opens
    [000E] delay(60);                                                           // Sleep 1 second

    [0012] breakHere();                                                         // Engine Tick
    [0013] unless (Var[102] == 0) goto 0012;                                    // Until Weird Ed: Actor found nearby = No

    [0018] putActorInRoom(11,7);                                                // Weird Ed enters Kitchen
    [001B] putActorAtObject(11,48);
    [001E] delay(120);

    [0022] stopScript(86);                                                      // Stop Weird Ed: Check for friendly actors
    [0024] breakHere();                                                         // Engine Tick
    [0025] cutscene();                                                          // Start Cutscene

    [0026] beginOverride();
    {
        [002A] loadRoom(7);
        [002C] actorFollowCamera(11);                                               // Camera follows Weird Ed
        [002E] walkActorToObject(11,56);                                            // Weird Ed walks to fridge

        [0031] delay(60);                                                           // Sleep 1 second
        [0035] print(11,"Tum te tum. Dum de dum.");

        [004A] breakHere();                                                         // Engine Tick
        [004B] VAR_RESULT = getActorMoving(11);
        [004E] unless (VAR_RESULT == 2) goto 004A;                                  // Wait until Weird Ed arrives

        [0053] animateActor(11,7,1);                                                // Weird Ed face away
        [0057] breakHere();                                                         // Engine Tick

        [0058] if (!getState08(56)) {                                               // Fridge Open?
        [005C]   setState08(56);                                                    //  Open Fridge
        [005E]   startSound(8);
        [0060] }
        [0060] delay(60);                                                           // Sleep 1 second

        [0064] if (getState08(57)) {                                                // Cheese Taken?
        [0068]   print(11,"Where's the cheese!?");
        [007D] } else {
        [0080]   setState08(57);
        [0082]   print(11,"Oh boy! Cheese for my hamster and me!");
        [00A3] }

        [00A3] breakHere();                                                         // Engine Tick
        [00A4] unless (VAR_HAVE_MSG == 0) goto 00A3;                                // Wait for Weird Ed to stop talking

        [00A9] clearState08(56);                                                    // Close Fridge
        [00AB] startSound(9);

        [00AD] walkActorToObject(11,48);                                            // Walk Actor to left-door
        [00B0] breakHere();                                                         // Engine Tick
        [00B1] VAR_RESULT = getActorX(11);
        [00B4] unless (VAR_RESULT < 25) goto 00B0;                                  // Wait until Weird Ed arrives
    }
    [00B9] setState08(57);                                                      // Take Cheese
    [00BB] putActorInRoom(11,0);                                                // Weird Ed leaves
    [00BE] putActor(11,0,0);

    [00C2] clearState08(35);                                                    // Close Kitchen Door
    [00C4] clearState08(48);                                                    // Close Kitchen In-Door
    [00C6] clearState08(56);                                                    // Close Fridge

    [00C8] endcutscene();                                                       // End Cutscene

    [00C9] startScript(93);                                                     // Start Weird Ed: Walk Hallway
    [00CB] stopObjectCode();
}


 /**
  * Script 147: Nurse Edna: In Kitchen Monitor
  */
Script-147 {
    [0000] delay(18000);                                                        // Sleep for 5 minutes

    [0004] breakHere();                                                         // Engine Tick     // While: Nurse Edna: In Kitchen {
    [0005] VAR_RESULT = isScriptRunning(148);                                   //  delay(1)
    [0008] unless (VAR_RESULT == 0) goto 0004;                                  // }

    [000D] clearState08(56);                                                    // Close Refridgerator

    [000F] startScript(32);                                                     // Nurse Edna: Return to Room
    [0011] stopObjectCode();
}


 /**
  * Script 148: Nurse Edna: In Kitchen
  */
Script-148 {
    [0000] breakHere();                                                         // Engine Tick

    [0001] VAR_RESULT = getClosestObjActor7(10);                                // Find Actors near Nurse Edna
    [0004] if (VAR_RESULT == 255) {
    [0009]   stopScript(0);                                                     //  Stop if none
    [000B] }
    [000B] unless (VAR_CAMERA_POS_X >= 47) goto 0000;                           // Until Camera Position is very right of room

    [0010] Var[103] = 0;                                                        // Nurse Edna Waiting = Not Waiting

    [0013] stopScript(147);                                                     // Stop Nurse Edna: In Kitchen Monitor
    [0015] startScript(30);                                                     // Start Nurse Edna: Check for close actors
    [0017] clearState08(56);                                                    // Close Fridge
    [0019] startSound(9);                                                       // Door Close sound
    [001B] breakHere();                                                         // Engine Tick
    [001C] print(10,"Want some food? Come here dearie!");

    [003B] breakHere();                                                         // Engine Tick
    [003C] unless (Var[110] == 0) goto 003B;                                    // Sleep until Nurse Edna: Check for close actors starts...

    [0041] stopScript(30);                                                      // Stop Nurse Edna: Check for close actors
    [0043] startScript(32);                                                     // Start Nurse Edna: Return to Room
    [0045] stopObjectCode();
}


 /**
  * Script 149:  -= Does Nothing =-
  */
Script-149 {
    [0000] stopObjectCode();
}


 /**
  * Script 150: Cutscene: Purple Tentacle chases Sandy
  */
Script-150 {
    [0000] cutscene();                                                          // Start Cutscene
    [0001] beginOverride();
    {
        [0005] putActorInRoom(9,31);                                                // Dr Fred enters Lab: Entry
        [0008] putActor(9,50,62);
        [000C] putActorInRoom(24,31);                                               // Sandy enters
        [000F] putActor(24,30,62);
        [0013] putActorInRoom(13,31);                                               // Purple Tentacle enters
        [0016] putActor(13,40,62);

        [001A] animateActor(24,6,1);                                                // Sandy face camera
        [001E] loadRoom(31);
        [0020] setCameraAt(20);                                                     //
        [0022] delay(60);                                                           // Sleep 1 second

        [0026] walkActorToActor(13,24,3);                                           // Purple walks to Sandy
        [002A] breakHere();                                                         // Engine Tick
        [002B] VAR_RESULT = getActorMoving(13);
        [002E] unless (VAR_RESULT == 2) goto 002A;                                  // wait for Purple to finish

        [0033] animateActor(24,4,1);                                                // Sandy Faces Left
        [0037] print(24,"Get away from me you purple slime geek.");
        [005A] walkActorTo(24,5,50);                                                // Walk Sandy to wall
        [005E] breakHere();                                                         // Engine Tick
        [005F] breakHere();                                                         // Engine Tick

        [0060] walkActorTo(13,5,50);                                                // Walk Purple to sandy
        [0064] breakHere();                                                         // Engine Tick
        [0065] VAR_RESULT = getActorMoving(24);
        [0068] unless (VAR_RESULT == 2) goto 0064;                                  // wait for sandy

        [006D] walkActorTo(24,25,45);                                               // Sandy moves
        [0071] print(24,"Don't touch me!");
        [0081] breakHere();                                                         // Engine Tick
        [0082] VAR_RESULT = getActorMoving(13);
        [0085] unless (VAR_RESULT == 2) goto 0081;                                  // Wait for Purple

        [008A] walkActorTo(13,21,50);                                               // Walk Purple
        [008E] breakHere();                                                         // Engine Tick
        [008F] VAR_RESULT = getActorMoving(24);
        [0092] unless (VAR_RESULT == 2) goto 008E;                                  // Wait for sandy

        [0097] walkActorTo(9,30,50);                                                // Walk Purple
        [009B] breakHere();                                                         // Engine Tick

        [009C] VAR_RESULT = getActorMoving(9);
        [009F] unless (VAR_RESULT == 2) goto 009B;                                  // Wait for dr. fred

        [00A4] animateActor(9,4,1);                                                 // Dr. Fred faces left
        [00A8] print(9,"PURPLE TENTACLE!!/Stop playing with the lab experiments./Bring her, the machine is ready./Heh, heh, heh.");
        [0106] breakHere();                                                         // Engine Tick
        [0107] unless (VAR_CHARCOUNT > 90) goto 0106;                               // Wait for partial text finish

        [010C] walkActorTo(9,60,50);                                                // Walk Dr. Fred
        [0110] breakHere();                                                         // Engine Tick
        [0111] unless (VAR_HAVE_MSG == 0) goto 0110;                                // Wait for text

        [0116] animateActor(24,6,1);                                                // Sandy face camera
        [011A] print(24,"EEEEEEEEEK!!!!");
        [012B] animateActor(24,254,1);                                              // Sandy mouth open
        [012F] breakHere();                                                         // Engine Tick
        [0130] unless (VAR_HAVE_MSG == 0) goto 012F;                                // Wait for text

        [0135] delay(60);                                                           // Sleep 1 second
    }
    [0139] print(255," ");
    [013D] endcutscene();                                                       // End Cutscene
    [013E] putActorInRoom(24,0);                                                // Sandy leaves
    [0141] putActor(24,0,0);
    [0145] stopObjectCode();
}


 /**
  * Script 151: Cutscene: Purple Tentacle chases Sandy Trigger
  */
Script-151 {
    [0000] delay(162000);                                                       // Sleep 45 minutes

    [0004] startScript(150);                                                    // Start Cutscene: Purple Tentacle chases Sandy
    [0006] stopObjectCode();
}


 /**
  * Script 154: Cutscene: Purple Tentacle reacts to police badge
  */
Script-154 {
    [0000] cutscene();                                                          // Start Cutscene
    [0001] actorFollowCamera(13);                                               // Follow Purple
    [0003] stopScript(112);                                                     // stop Purple Tentacle: Check Actor X > 20; print "What are you doing here?"
    [0005] stopScript(43);                                                      // stop Purple Tentacle: Check for close actors
    [0007] stopScript(36);                                                      // stop Cutscene: Meteor Police

    [0009] beginOverride();
    {
        [000D] print(13,"You're with the Meteor Police!!/Dr. Fred made me do it%/%he forced me to go along with his plan!");
        [005F] breakHere();                                                         // Engine Tick
        [0060] unless (VAR_CHARCOUNT > 40) goto 005F;                               // Wait for partial text
        [0065] startScript(155);                                                    // start Purple Tentacle: Move between points
        [0067] breakHere();                                                         // Engine Tick
        [0068] unless (VAR_HAVE_MSG == 0) goto 0067;                                // Wait for text

        [006D] print(13,"It's all his fault, I'm innocent!/He's right in there%/%get him % arrest him % kill him.");
        [00B9] breakHere();                                                         // Engine Tick
        [00BA] unless (VAR_HAVE_MSG == 0) goto 00B9;                                // Wait for text

        [00BF] print(13,"He's mad % I'll help you./I'm your friend, you can trust me.");
        [00F3] breakHere();                                                         // Engine Tick
        [00F4] unless (VAR_HAVE_MSG == 0) goto 00F3;                                // Wait for text

        [00F9] stopScript(36);                                                      // stop Cutscene: Meteor Police
        [00FB] stopScript(155);                                                     // stop Purple Tentacle: Move between points

        [00FD] walkActorToObject(13,133);                                           // walk Purple to door
        [0100] print(13,"AGGGGGGGG!!!!");
        [0110] setActorBitVar(VAR_EGO,64,0);                                        // Disable kid kActorMiscFlagFreeze
        [0114] breakHere();                                                         // Engine Tick
        [0115] VAR_RESULT = getActorMoving(13);
        [0118] unless (VAR_RESULT == 2) goto 0114;                                  // Wait for purple to finish moving
    }

    [011D] putActorInRoom(13,0);                                                // Purple leaves
    [0120] putActor(13,0,0);
    [0124] Var[135] = 1;                                                        // Purple chased out of lab = Yes
    [0127] endcutscene();                                                       // End Cutscene
    [0128] stopObjectCode();
}


 /**
  * Script 155: Purple Tentacle: Move between points
  */
Script-155 {
    [0000] walkActorTo(13,45,70);                                               // Walk Purple to 45, 70
    [0004] breakHere();                                                         // Engine Tick

    [0005] VAR_RESULT = getActorMoving(13);
    [0008] unless (VAR_RESULT == 2) goto 0004;                                  // Wait for purple

    [000D] walkActorTo(13,39,70);                                               // Walk Purple to 39, 70
    [0011] breakHere();                                                         // Engine Tick
    [0012] VAR_RESULT = getActorMoving(13);
    [0015] unless (VAR_RESULT == 2) goto 0011;                                  // Wait for purple

    [001A] goto 0000;
    [001D] stopObjectCode();
}


 /**
  * Script 156: Green Tentacle: Walk to current kid
  */
Script-156 {
    [0000] walkActorToActor(14,VAR_EGO,3);                                      // Walk Green Tentacle to Kid
    [0004] delay(60);                                                           // Sleep 1 second
    [0008] VAR_RESULT = getActorRoom(VAR_EGO);
    [000B] unless (VAR_RESULT != 20) goto 0000;                                 // Loop while kid in Green Tentacle's Room

    [0010] stopObjectCode();
}


 /**
  * Script 157: Weird Ed: Walk around the Lab Entry
  */
Script-157 {
    [0000] breakHere();                                                         // Engine Tick
    [0001] breakHere();                                                         // Engine Tick
    [0002] VAR_RESULT = getActorMoving(11);
    [0005] unless (VAR_RESULT == 2) goto 0001;                                  // Wait for Weird Ed

    [000A] breakHere();                                                         // Engine Tick
    [000B] VAR_RESULT = getDist(11,13);
    [000F] unless (VAR_RESULT > 8) goto 000A;                                   // Sleep while Distance between Weird Ed and Purple Tentacle is > 8

    [0014] walkActorTo(11,47,57);                                               // Walk Weird Ed
    [0018] breakHere();                                                         // Engine Tick
    [0019] breakHere();                                                         // Engine Tick
    [001A] VAR_RESULT = getActorMoving(11);
    [001D] unless (VAR_RESULT == 2) goto 0019;                                  // Wait for Weird Ed

    [0022] walkActorTo(11,45,66);                                               // Walk Weird Ed
    [0026] breakHere();                                                         // Engine Tick
    [0027] breakHere();                                                         // Engine Tick
    [0028] VAR_RESULT = getActorMoving(11);
    [002B] unless (VAR_RESULT == 2) goto 0027;                                  // Wait for Weird Ed

    [0030] walkActorTo(11,12,66);                                               // Walk Weird Ed
    [0034] stopObjectCode();
}


 /**
  * Script 158: Green Tentacle: Block player passing
  */
Script-158 {
    [0000] Var[53] = getActorY(Var[95]);                                        // Get Kid Y
    [0003] Var[90] = getActorX(14);                                             // Get Green Tentacle X
    [0006] Var[90] += 2;                                                        // X += 2
    [0009] VAR_RESULT = getActorX(Var[95]);                                     // Get Kid X

    [000C] if (VAR_RESULT <= Var[90]) {                                         // If KidX < (Green Tentacle X + 2)
    [0011]   Var[52] = 35;
    [0014]   Var[52] += 3;

    [0017]   setActorBitVar(Var[95],64,1);                                      // Enable Kid kActorMiscFlagFreeze
    [001B]   walkActorTo(Var[95],Var[52],Var[53]);                              // Walk kid to 38, Y

    [001F]   startSound(36);
    [0021]   if (VAR_HAVE_MSG == 0) {                                           // If not talking
    [0026]     printEgo("Oomph!");
    [002E]   }

    [002E]   breakHere();                                                       // Engine Tick
    [002F]   VAR_RESULT = getActorMoving(Var[95]);
    [0032]   unless (VAR_RESULT == 2) goto 002E;                                // Wait for kid to stop

    [0037]   animateActor(Var[95],6,1);                                         // Kid Face Camera
    [003B]   breakHere();                                                       // Engine Tick
    [003C]   animateActor(Var[95],4,1);                                         // Kid Face Left
    [0040]   setActorBitVar(Var[95],64,0);                                      // Disable Kid kActorMiscFlagFreeze
    [0044] }
    [0044] walkActorTo(14,32,Var[53]);
    [0048] breakHere();                                                         // Engine Tick
    [0049] goto 0000;
    [004C] stopObjectCode();
}
