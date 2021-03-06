/**
 * Maniac Mansion: Retail
 *
 * Room Object Scripts
 */

 /** Events
  *
  * 00 = None
  * 01 = Open
  * 02 = Close
  * 03 = Give
  * 04 = Turn On
  * 05 = Turn Off
  * 06 = Fix
  * 07 = New Kid
  * 08 = Unlock
  * 09 = Push
  * 0A = Pull
  * 0B = Use
  * 0C = Read
  * 0D = Walk To
  * 0E = Pick Up
  * 0F = What Is
  * 10 = Lock
  *
  **/

/**
 * Room 1: Front of Mansion
 */


/** Stamps **/
roomobj-1-132.dmp

Pull.Pickup {
    [001C] pickupObject(0);                                                     // Pick object
    [001E] printEgo("Hmm, they're uncanceled.");
    [0036] Var[81] = 1;                                                         // Stamps Taken = Taken
    [0039] stopObjectCode();                                                    // --
}

Use {
    [003A] if (activeObject2 == 234) {                                          // if Use with Sealed Envelope (room7)
    [003E] } else {                                                             // -
    [0041]   unless (activeObject2 == 201) goto 0067;                           //  or Use with Sealed Envelope (room9)
    [0045] }
    [0045] if (Var[62] == 1) {                                                  // if Stamp Stickyness == Sticky
    [004A]   Var[64] = 1;                                                       //  Envelop Stamped = Yes
    [004D]   printEgo("They stick!");
    [0059]   startScript(79);                                                   //  start Envelope: Name
    [005B]   setOwnerOf(0,0);                                                   //  Remove Stamps
    [005E] } else {                                                             //  Use with other objects
    [0067]   printEgo("They won't stick.");
    [0078] }
    [0078] stopObjectCode();                                                    // --

}


/** Mailbox **/
roomobj-1-17.dmp

Open {
    [001D] setState08();                                                        // Open mailbox
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] clearState08();                                                      // Close mailbox
    [0020] stopObjectCode();                                                    // --
}

Use {
    [0021] doSentence(11,255,263);                                              // Use _cmdObject2 with Mailbox
    [0025] stopObjectCode();                                                    // --
}




/** Mailbox Flag **/
roomobj-1-18.dmp

Open {
    [001E] doSentence(1,254,255);                                               // Open _cmdObject with _cmdObject2
    [0022] stopObjectCode();                                                    // --
}

Close {
    [0023] doSentence(2,254,255);                                               // Close _cmdObject with _cmdObject2
    [0027] stopObjectCode();                                                    // --
}

Pull {
    [0028] setState08();                                                        // Raise Flag
    [0029] stopObjectCode();                                                    // --
}

Push {
    [002A] clearState08();                                                      // Lower Flag
    [002B] stopObjectCode();                                                    // --
}

Use {
    [002C] if (getState08(activeObject)) {                                      // If Flag Up
    [002F]   clearState08();                                                    //  Lower Flag
    [0030] } else {                                                             // -
    [0033]   setState08();                                                      //  Raise Flag
    [0034] }
    [0034] stopObjectCode();                                                    // --
}




/** Bushes **/
roomobj-1-19.dmp

Open.Pull.Pickup {
    [001C] setState08();                                                        // Remove Bushes
    [001D] stopObjectCode();                                                    // --
}




/** Grating **/
roomobj-1-20.dmp

Open {
    [0027] if (getState04(activeObject)) {                                      // Has grate been fixed?
    [002A]   VAR_RESULT = getActorBitVar(VAR_EGO,1);                            // No. Check Kid
    [002E]   if (VAR_RESULT == 1) {                                             // Kid has kActorMiscFlagStrong?
    [0033]     printEgo("Easy!");
    [003A]     goto 0062;
    [003D]   } else {                                                           // -
    [0040]     printEgo("I can't budge it. It's rusted shut.");
    [005F]   }
    [005F] } else {                                                             // -
    [0062]   setState08();                                                      // Grate is open
    [0063]   setState08(213);                                                   // Grate is open
    [0065]   startSound(8);                                                     // Sound Door Open
    [0067] }
    [0067] stopObjectCode();                                                    // --
}

Close {
    [0068] clearState08();                                                      // Grate is closed
    [0069] clearState08(213);                                                   // Grate is closed
    [006B] stopObjectCode();                                                    // --
}

Push.Pull {
    [006C] if (!getState08(activeObject)) {                                     // Push
    [006F]   doSentence(1,20,0);                                                //  Open Grating
    [0073] } else {                                                             // -
    [0076]   doSentence(2,20,0);                                                //  Close Grating
    [007A] }
    [007A] stopObjectCode();                                                    // --
}

Fix.Unlock.Use {
    [007B] if (activeObject2 == 119) {                                          // Use Tools with Grate
    [007F]   clearState04();                                                    // Grate can be opened by anyone
    [0080]   doSentence(1,20,0);
    [0084] }
    [0084] stopObjectCode();                                                    // --
}

WalkTo {
    [0085] if (getState08(activeObject)) {                                      // Walk To
    [0088]   loadRoomWithEgo(213,29);                                           // Enter room Underhouse
    [008B] }
    [008B] stopObjectCode();                                                    // --
}




/** Door mat **/
roomobj-1-21.dmp

Pull.Pickup {
    [001E] if (getState08(activeObject)) {                                      // Pull/Pickup
    [0021]   printEgo("I'll leave it here.");
    [0033] } else {                                                             // -
    [0036]   setState08();                                                      //  Move Doormat
    [0037] }
    [0037] stopObjectCode();                                                    // --
}

Push {
    [0038] clearState08();                                                      // Move doormat back
    [0039] stopObjectCode();                                                    // --
}



/** Front Door Key **/
roomobj-1-22.dmp

Pickup {
    [0017] pickupObject(0);                                                     // Pickup Key
    [0019] stopObjectCode();                                                    // --
}

Use {
    [001A] if (activeObject2 == 28) {                                           // Use key with Front Door
    [001E]   clearState04(28);                                                  //  Unlock Front Door
    [0020]   doSentence(1,28,0);                                                //  Open Front Door
    [0024] } else {                                                             // -
    [0027]   printEgo("It doesn't work.");
    [0037] }
    [0037] stopObjectCode();                                                    // --
}




/** Undeveloped Film **/
roomobj-1-23.dmp

Pickup {
    [002A] pickupObject(0);                                                     // Pickup Undeveloped Film
    [002C] stopObjectCode();                                                    // --
}

Open {
    [002D] VAR_RESULT = isScriptRunning(71);
    [0030] if (VAR_RESULT == 0) {                                               // is script Film: Expose not running
    [0035]   startScript(71);                                                   //  start Film: Expose
    [0037] }
    [0037] stopObjectCode();                                                    // --
}

Use {
    [0038] doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    [003C] stopObjectCode();                                                    // --
}

Read {
    [003D] if (Var[11] < 2) {                                                   // if Film Exposed < Ruined Prints
    [0042]   printEgo("Kodak.");
    [004A] } else {                                                             // -
    [004D]   printEgo("Looks like photographs of Ed's plans.");
    [006F] }
    [006F] stopObjectCode();                                                    // --
}

Give {
    [0070] if (VAR_ACTIVE_ACTOR < 8) {                                          // Give to Kid
    [0075]   setOwnerOf(0,VAR_ACTIVE_ACTOR);
    [0078] }
    [0078] if (VAR_ACTIVE_ACTOR == 11) {                                        // Give to Weird Ed?
    [007D]   if (Var[11] < 2) {                                                 //  if Film Exposed < Ruined Prints
    [0082]     print(11,"No! No! You have to develop it for me!");
    [00A3]   } else {                                                           // -
    [00A6]     startScript(88);                                                 //  start Weird Ed: Accepts Prints
    [00A8]   }
    [00A8] }
    [00A8] stopObjectCode();                                                    // --
}




/** Package **/
roomobj-1-24.dmp

Pickup {
    [0021] pickupObject(0);                                                     // Pickup Package
    [0023] if (Var[81] == 0) {                                                  // if Stamps Taken == No
    [0028]   pickupObject(132);                                                 //  Pickup Stamps
    [002A]   setOwnerOf(132,14);                                                //  Set owner of stamps to Green Tentacle
    [002D] }
    [002D] stopObjectCode();                                                    // --
}

Give {
    [002E] if (VAR_ACTIVE_ACTOR < 8) {                                          // Give
    [0033]   setOwnerOf(0,VAR_ACTIVE_ACTOR);                                    //  To Kid
    [0036] }
    [0036] if (VAR_ACTIVE_ACTOR == 11) {                                        //  To Weird Ed
    [003B]   startScript(87);                                                   //   start Weird Ed: Accept Commando Package
    [003D] }
    [003D] stopObjectCode();                                                    // --
}

Read {
    [003E] printEgo("To: Weird Ed");                                            // Read
    [004A] stopObjectCode();                                                    // --
}

Open.Pull {
    [004B] if (Var[81] == 0) {                                                  // if Stamps Taken == No
    [0050]   if (getState08(activeObject)) {                                    //  if Package available
    [0053]     setOwnerOf(132,VAR_EGO);                                         //   Kid owns Stamps
    [0056]   } else {                                                           // -
    [0059]     pickupObject(132);                                               // Pickup Package
    [005B]   }
    [005B]   printEgo("Some uncanceled stamps came off!");
    [0079]   Var[81] = 1;                                                       // Stamps Taken = Yes
    [007C] } else {                                                             // -
    [007F]   printEgo("That would be illegal.");
    [0094] }
    [0094] stopObjectCode();                                                    // --
}




/** Exit to Room 44 **/
roomobj-1-240.dmp

WalkTo {
    [0012] loadRoomWithEgo(241,44);                                             // Enter room 'Welcome to Mansion'
    [0015] stopObjectCode();                                                    // --
}




/** Envelope **/
roomobj-1-25.dmp

Read {
    [001C] if (Var[85] == 0) {                                                  // Envelope: Addressed == No
    [0021]   printEgo("It's a blank envelope.");
    [0036] } else {                                                             // -
    [0039]   printEgo("It's addressed to: 222 Skyscraper Way.");
    [005C] }
    [005C] stopObjectCode();                                                    // --
}

Pickup {
    [005D] setState02(25);                                                      // Hide Envelope
    [005F] clearState08(25);                                                    // Hide Envelope
    [0061] setOwnerOf(201,VAR_EGO);                                             // Sealed Envelope owned by kid
    [0064] stopObjectCode();                                                    // --
}



/** Mailbox **/
roomobj-1-263.dmp

Open {
    [001F] setState08(17);                                                      // Open
    [0021] stopObjectCode();                                                    // --
}

Close {
    [0022] clearState08(17);
    [0024] stopObjectCode();                                                    // --
}

Use {
    [0025] if (activeObject2 == 201) {                                          // Use Mailbox with Sealed Envelope
    [0029]   if (getState08(17)) {                                              // Is mailbox open
    [002D]     if (Var[85] == 0) {                                              // If Envelope: Addressed == No
    [0032]       printEgo("There is no address on it.");
    [0049]     } else if (Var[64] == 0) {                                       // or Envelope Stamped == No
    [0051]       printEgo("There's no stamp on it.");
    [0066]     } else {
    [0069]       setOwnerOf(201,14);                                            // Otherwise, Green Tentacle owners envelope
    [006C]       clearState02(25);                                              // Envelope Unavailable
    [006E]       setState08(25);                                                // Envelope Unavailable
    [0070]     }
    [0070]   }
    [0070] }
    [0070] stopObjectCode();                                                    // --
}

Read {
    [0071] printEgo("Solicitors will be eaten.");
    [0089] stopObjectCode();                                                    // --
}



/** Bushes **/
roomobj-1-264.dmp



/** Contract **/
roomobj-1-27.dmp

Pickup {
    [001E] pickupObject(0);
    [0020] clearState08();
    [0021] stopObjectCode();                                                    // --
}

Read {
    [0022] startScript(127);                                                    // start Contract: Read State
    [0024] stopObjectCode();                                                    // --
}

Give {
    [0025] startScript(105);                                                    // start Contract: Given to actor
    [0027] stopObjectCode();                                                    // --
}



/** Front Door **/
roomobj-1-28.dmp

Open {
    [0026] if (!getState04(activeObject)) {                                     // Is Door unlocked
    [0029]   startScript(4);                                                    //  start Door: Open
    [002B]   setState08(34);                                                    //  Open Front Door (from room 10)
    [002D] } else {                                                             // else
    [0030]   startScript(64);                                                   //  start Print "The door is locked"
    [0032] }
    [0032] stopObjectCode();                                                    // --
}

Close {
    [0033] startScript(5);                                                      // start Door: Close
    [0035] clearState08(34);                                                    // close Front Door (from room 10)
    [0037] stopObjectCode();                                                    // --
}

Unlock.Use {
    [0038] if (activeObject2 == 22) {                                           // if using Key
    [003C]   clearState04();                                                    //  Unlock Front door
    [003D]   doSentence(1,28,0);                                                //  Open Front Door
    [0041] } else {                                                             // -
    [0044]   startScript(66);                                                   // start Print "I can't unlock the door with this."
    [0046] }
    [0046] stopObjectCode();                                                    // --
}

Lock {
    [0047] setState04();                                                        //  Lock
    [0048] doSentence(2,28,0);                                                  //  Close Front Door
    [004C] stopObjectCode();                                                    // --
}

WalkTo {
    [004D] if (getState08(activeObject)) {                                      // if front-door is open
    [0050]   if (Var[122] == 0) {                                               //  if Dr. Fred / Sandy Cutscene #1 Triggered == 0
    [0055]     Var[122] = 1;                                                    //   Dr. Fred / Sandy Cutscene #1 Triggered = 1
    [0058]     startScript(143);                                                //   start Cutscene: Dr. Fred / Sandy #1
    [005A]     putActorInRoom(10,7);                                            //   Nurse Edna enters Kitchen
    [005D]     putActor(10,62,56);                                              //   Put Nurse Edna at Refridgerator
    [0061]     animateActor(10,7,1);                                            //   Nurse Edna faces away
    [0065]     setState08(56);                                                  //   Open Refridgerator
    [0067]     startScript(147);                                                //   start Nurse Edna: In Kitchen Monitor
    [0069]   }
    [0069]   loadRoomWithEgo(34,10);                                            //  Kid enters Room 10 at Front Door
    [006C] }
    [006C] stopObjectCode();                                                    // --
}




/** Tombstone **/
roomobj-1-29.dmp

Read {
    [001B] printEgo("And good riddance!");
    [002D] stopObjectCode();                                                    // --
}



/** Tombstone **/
roomobj-1-30.dmp

Read {
    [001B] printEgo("Another one bites the dust!");
    [0034] stopObjectCode();                                                    // --
}



/** Tombstone **/
roomobj-1-31.dmp



/** Doorbell **/
roomobj-1-386.dmp

Push.Use {
    [001E] startSound(39);
    [0020] if (Var[73] == 0) {                                                  // Door Bell Triggers Ed == Yes
    [0025]   VAR_RESULT = isScriptRunning(82);                                  // is Weird Ed: Leave Room running
    [0028]   if (VAR_RESULT == 0) {
    [002D]     VAR_RESULT = getActorRoom("Weird Ed");
    [0030]     if (VAR_RESULT == 26) {
    [0035]       Var[127] = 1;                                                  // Weird Ed Trigger = DoorBell
    [0038]       startScript(82);                                               // start Weird Ed: Leave Room running
    [003A]     }
    [003A]   } else {                                                           // -
    [003D]     startScript(92);                                                 // start Weird Ed: Respond to Door Bell
    [003F]   }
    [003F] }
    [003F] stopObjectCode();                                                    // --
}

Read {
    [0040] printEgo("This is the home of Dr. Fred,/Nurse Edna, Weird Ed, Dead Cousin Ted,/Green Tentacle and Purple Tentacle.");
    [009A] stopObjectCode();                                                    // --
}




/**
 * Room 2: Bottom of Pool
 */

/** Glowing Key **/
roomobj-2-108.dmp

Pickup {
    [001F] pickupObject(0);                                                     // Pickup Key
    [0021] stopObjectCode();                                                    // --
}

Use {
    [0022] doSentence(11,255,254);                                              // Use Key in _cmdOjbect2
    [0026] stopObjectCode();                                                    // --
}


/** Radio **/
roomobj-2-109.dmp

Pickup {
    [001D] pickupObject(0);                                                     // Pickup Radio
    [001F] pickupObject(134);                                                   // Pickup Batteries
    [0021] setOwnerOf(134,14);                                                  // Green Tentacle owns Batteries
    [0024] setState08(107);                                                     // Radio in Pool Area hidden
    [0026] setState02(107);                                                     // Radio in Pool Area hidden
    [0028] stopObjectCode();                                                    // --
}

Open {
    [0029] if (!getState08(109)) {                                              // Radio Not Taken?
    [002D]   doSentence(1,109,0);
    [0031]   doSentence(14,109,0);
    [0035] } else {                                                             // -
    [0038]   VAR_RESULT = getObjectOwner(134);
    [003B]   if (VAR_RESULT == 14) {                                            // If green tentacle still owns batteries
    [0040]     printEgo("Batteries!");
    [004C]     setOwnerOf(134,VAR_EGO);                                         // kid owns batteries
    [004F]     stopSound(20);
    [0051]   }
    [0051] }
    [0051] stopObjectCode();                                                    // --
}

TurnOn {
    [0052] VAR_RESULT = getObjectOwner(134);
    [0055] if (VAR_RESULT == 14) {                                              // if green tentacle still owns batties
    [005A]   startSound(20);                                                    //  turn on radio
    [005C] }
    [005C] stopObjectCode();                                                    // --
}

TurnOff {
    [005D] stopSound(20);                                                       // turn off radio
    [005F] stopObjectCode();                                                    // --
}


/** Batteries **/
roomobj-2-134.dmp

Use {
    [001B] if (activeObject2 == 51) {                                           // Flashlight?
    [001F]   Var[31] = 2;                                                       // Flashlight has Battery = Full
    [0022]   setOwnerOf(134,0);                                                 // Remove Batteries
    [0025] }
    [0025] stopObjectCode();                                                    // --
}



/** Ladder **/
roomobj-2-138.dmp

WalkTo {
    [0018] loadRoomWithEgo(139,6);                                              // Enter Pool Area at Ladder
    [001B] stopObjectCode();                                                    // --
}


/** Red Button **/
roomobj-2-275.dmp

Push.Use {
    [0020] startSound(27);                                                      // Beep
    [0022] startScript(57);                                                     // start Cutscene: Game Over
    [0024] stopObjectCode();                                                    // --
}

Read {
    [0025] printEgo("DO NOT PRESS UNDER ANY CIRCUMSTANCES!");                   // Read
    [0047] stopObjectCode();                                                    // --
}


/** Pool Chair **/
roomobj-2-326.dmp

Pickup {
    [001C] startScript(65);                                                     // start Print "Its too Heavy"
    [001E] stopObjectCode();                                                    // --
}



/** Drain **/
roomobj-2-327.dmp



/** Exposed cooling rods **/
roomobj-2-328.dmp

WalkTo {
    [0028] stopObjectCode();                                                    // --
}

WhatIs {
    [0029] printEgo("I'm not going to touch cooling rods!");                    // Walk To
    [0049] stopObjectCode();                                                    // --
}



/** Radioactive **/
roomobj-2-329.dmp

WhatIs {
    [0023] printEgo("I'm not going to touch that goo!");                        // What is
    [003F] stopObjectCode();                                                    // --
}




/**
 * Room 3: Downstairs Lounge Room
 */

/** Cassette Player **/
roomobj-3-207.dmp

TurnOn {
    [0025] if (!getState08(47)) {                                               // if Cassette Tape Not In Player
    [0029]   if (!getState08(124)) {                                            //  if Circuit Breaker == Power On
    [002D]     setState08(207);                                                 //   set Cassette Player has tape
    [002F]     startScript(104);                                                //   start Tape Player: Play Tape
    [0031]     if (Var[13] == 25) {                                             //   Tape Contents == Tentacle Mating Call
    [0036]       startScript(15);                                               //    start Cassette: Play, Break Windows/Free Key
    [0038]     }
    [0038]   }
    [0038] } else {                                                             // -
    [003B]   printEgo("There's no tape in the player.");
    [0056] }
    [0056] stopObjectCode();                                                    // --
}

TurnOff {
    [0057] if (getState08(207)) {                                               //   Cassette Player has tape?
    [005B]   clearState08(207);                                                 //    Remove Tape
    [005D]   stopSound(25);
    [005F]   stopSound(44);
    [0061]   stopMusic();                                                       //    stop music
    [0062]   stopScript(15);                                                    //    stop Cassette: Play, Break Windows/Free Key
    [0064] }
    [0064] stopObjectCode();                                                    // --
}

Use {
    [0065] if (activeObject2 == 156) {                                          // Use Cassette Tape with Cassette Player
    [0069]   setOwnerOf(156,14);                                                // Green Tentacle owns Tape
    [006C]   clearState08(47);                                                  // Tape Hidden
    [006E]   clearState02(47);                                                  // Tape Hidden
    [0070] }
    [0070] stopObjectCode();                                                    // --
}




/** Couch **/
roomobj-3-273.dmp

Push.Pull {
    [0019] printEgo("I can't budge it.");                                       // Push Couch
    [0029] stopObjectCode();                                                    // --
}



/** Door **/
roomobj-3-38.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(37);                                                      // Open Door (in room 10)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(37);                                                    // Close Door (in room 10)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // If Door Open
    [0027]   loadRoomWithEgo(37,10);                                            //  Enter Room 10 at Door
    [002A] }
    [002A] stopObjectCode();                                                    // --
}



/** Old Fashioned Radio **/
roomobj-3-39.dmp

Open {
    [002D] setState08();                                                        // Open Radio
    [002E] Var[29] = 0;
    [0031] stopSound(20);
    [0033] stopSound(29);
    [0035] stopObjectCode();                                                    // --
}

Close {
    [0036] clearState08();                                                      // Close Radio
    [0037] stopObjectCode();                                                    // --
}

Fix {
    [0038] if (activeObject2 == 40) {                                           // Fix Radio with Radio Tube
    [003C]   clearState08(40);                                                  //  Show radio tube
    [003E]   clearState02(40);                                                  //  Show radio tube
    [0040]   setOwnerOf(40,0);                                                  //  Radio tube has no owner
    [0043] } else if (getState08(40)) {
    [004A]   printEgo("That doesn't seem to work.");
    [0062] }
    [0062] stopObjectCode();                                                    // --
}

TurnOn {
    [0063] clearState08();                                                      // Close Radio
    [0064] if (!getState08(40)) {                                               // Radio Tube
    [0068]   if (!getState08(124)) {                                            // Power is on?
    [006C]     if (Var[29] == 0) {
    [0071]       Var[29] = 1;                                                   // Radio On
    [0074]       startSound(20);
    [0076]     }
    [0076]   }
    [0076] } else {                                                             // -
    [0079]   printEgo("I can't get it to work.");
    [008D] }
    [008D] stopObjectCode();                                                    // --
}

TurnOff {
    [008E] clearState08();
    [008F] if (Var[29] == 0) {                                                  // Radio == Off?
    [0094]   printEgo("It wasn't on.");
    [00A1] } else {                                                             // -
    [00A4]   Var[29] = 0;                                                       // Radio = Off
    [00A7]   stopSound(20);
    [00A9]   stopSound(29);
    [00AB] }
    [00AB] stopObjectCode();                                                    // --
}

Use {
    [00AC] clearState08();
    [00AD] if (Var[29] == 0) {                                                  // Radio == off
    [00B2]   printEgo("It's not turned on.");
    [00C4] } else {                                                             // -
    [00C7]   startSound(29);
    [00C9] }
    [00C9] stopObjectCode();                                                    // --
}




/** Radio Tube **/
roomobj-3-40.dmp

Pickup {
    [001E] if (VAR_EGO == 5) {                                                  // If kid == Bernard
    [0023]   pickupObject(0);                                                   //  Pickup
    [0025] } else {                                                             // -
    [0028]   printEgo("I don't know how this stuff works!");
    [0046] }
    [0046] stopObjectCode();                                                    // --
}

Use {
    [0047] doSentence(6,255,254);                                               // Fix _cmdObject with _cmdObject2
    [004B] stopObjectCode();                                                    // --
}




/** Glass Chandelier **/
roomobj-3-41.dmp



/** Broken Chandelier **/
roomobj-3-42.dmp



/** Old Rusty Key **/
roomobj-3-43.dmp

Pickup {
    [0021] pickupObject(0);                                                     // Pickup
    [0023] stopObjectCode();                                                    // --
}

Use {
    [0024] doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    [0028] stopObjectCode();                                                    // --
}



/** Cabinet Door **/
roomobj-3-44.dmp

Open {
    [0020] startScript(4);                                                      // start Door: Open
    [0022] stopObjectCode();                                                    // --
}

Close {
    [0023] startScript(5);                                                      // start Door: Close
    [0025] stopObjectCode();                                                    // --
}



/** Key **/
roomobj-3-445.dmp

Pull.Pickup {
    [0017] printEgo("I can't reach it.");
    [0027] stopObjectCode();                                                    // --
}



/** Window **/
roomobj-3-45.dmp



/** Window **/
roomobj-3-46.dmp



/** Cassette Tape **/
roomobj-3-47.dmp

Pickup {
    [0023] if (getState08(207)) {                                               // Cassette Player is playing?
    [0027]   printEgo("It's still playing!");
    [003A] } else {                                                             // -
    [003D]   setOwnerOf(156,VAR_EGO);                                           // Kid owns Tape
    [0040]   setState08();                                                      // Tape Taken
    [0041]   setState02();                                                      // Tape Taken
    [0042] }
    [0042] stopObjectCode();
}

TurnOn {
    [0043] if (!getState08(activeObject)) {                                     // If Casette Player Off
    [0046]   doSentence(4,207,0);                                               //  Turn On Cassette Player
    [004A] }
    [004A] stopObjectCode();
}

TurnOff {
    [004B] if (!getState08(activeObject)) {                                     // If Casette Player Off
    [004E]   doSentence(5,207,0);                                               //  Turn Off Cassette Player
    [0052] }
    [0052] stopObjectCode();                                                    // --
}



/** Door **/
roomobj-3-93.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(102);                                                     // Door Open (other side)
    [001E] stopObjectCode();
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(102);                                                   // Door Close (other side)
    [0023] stopObjectCode();
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // Door is open?
    [0027]   loadRoomWithEgo(102,5);                                            //  Kid enters Library at Door
    [002A] }
    [002A] stopObjectCode();                                                    // --
}




/**
 * Room 4: Dungeon
 */

/** Door **/
roomobj-4-126.dmp

Open {
    [0020] if (!getState08(activeObject)) {                                     // Door Locked?
    [0023]   startScript(64);                                                   //  start Print "The door is locked"
    [0025] }
    [0025] stopObjectCode();                                                    // --
}

Close {
    [0026] startScript(51);                                                     // start Dungeon: Close Entry Door
    [0028] stopObjectCode();                                                    // --
}

Unlock.Use {
    [0029] if (activeObject2 == 43) {                                           // Use Old Rusty Key with Door
    [002D]   startScript(4);                                                    // start Door: Open
    [002F]   setState08(122);                                                   // Open Door (Room8: Basement)
    [0031] } else {                                                             // -
    [0034]   startScript(66);                                                   // start Print "I can't unlock the door with this."
    [0036] }
    [0036] stopObjectCode();                                                    // --
}

WalkTo {
    [0037] if (getState08(activeObject)) {                                      // Door Unlocked?
    [003A]   clearState08(126);                                                 //  Close Door
    [003C]   clearState08(122);                                                 //  Close Door (Room8: Basement)
    [003E]   loadRoomWithEgo(122,8);                                            //  Enter Basement at Door
    [0041] }
    [0041] stopObjectCode();                                                    // --
}




/** Outer Door **/
roomobj-4-127.dmp

Open {
    [001E] if (!getState04(activeObject)) {                                     // Paddlocks unLocked?
    [0021]   startScript(4);                                                    //  start Door: Open
    [0023] } else {                                                             // -
    [0026]   startScript(64);                                                   //  start Print "The door is locked"
    [0028] }
    [0028] stopObjectCode();                                                    // --
}

Close {
    [0029] if (getState08(activeObject)) {                                      // If door open
    [002C]   clearState08();                                                    //  Close door
    [002D]   startSound(42);                                                    //  sound Steel Door
    [002F] }
    [002F] stopObjectCode();                                                    // --
}




/** Top Padlock **/
roomobj-4-128.dmp

Unlock.Use {
    [0023] if (activeObject2 == 108) {                                          // Use Glowing Key with Top Padlock
    [0027]   if (!getState08(activeObject)) {                                   //  Padlock locked?
    [002A]     setState08();                                                    //   Unlock Padlock
    [002B]     startSound(12);                                                  //   sound Light Switch
    [002D]   }
    [002D]   if (getState08(129)) {                                             // Is Bottom Padlock unlocked
    [0031]     clearState04(127);                                               //  Yes, Unlock the Outer Door
    [0033]   }
    [0033] } else {                                                             // -
    [0036]   startScript(66);                                                   //  start Print "I can't unlock the door with this."
    [0038] }
    [0038] stopObjectCode();                                                    // --
}

Close.Lock {
    [0039] if (getState08(activeObject)) {                                      // Padlock Unlocked?
    [003C]   clearState08();                                                    //   Lock Padlock
    [003D]   startSound(12);                                                    //   sound Light Switch
    [003F] }
    [003F] setState04(127);                                                     // Lock the Outer Door
    [0041] stopObjectCode();                                                    // --
}



/** Bottom Padlock **/
roomobj-4-129.dmp

Unlock.Use {
    [0026] if (activeObject2 == 108) {                                          // Use Glowing Key with Top Padlock
    [002A]   if (!getState08(activeObject)) {                                   //  Padlock locked?
    [002D]     setState08();                                                    //   Unlock Padlock
    [002E]     startSound(12);                                                  //   sound Light Switch
    [0030]   }
    [0030]   if (getState08(128)) {                                             // Is Top Padlock unlocked
    [0034]     clearState04(127);                                               //  Yes, Unlock the Outer Door
    [0036]   }
    [0036] } else {                                                             // -
    [0039]   startScript(66);                                                   //  start Print "I can't unlock the door with this."
    [003B] }
    [003B] stopObjectCode();                                                    // --
}

Lock.Close {
    [003C] if (getState08(activeObject)) {                                      // Padlock Unlocked?
    [003F]   clearState08();                                                    //   Lock Padlock
    [0040]   startSound(12);                                                    //   sound Light Switch
    [0042] }
    [0042] setState04(127);                                                     // Lock the Outer Door
    [0044] stopObjectCode();                                                    // --
}




/** Inner Door  **/
roomobj-4-130.dmp

Open.Unlock.Push.Pull.Use {
    [002A] startScript(40);                                                     // start Lab Entry Keypad Input
    [002C] stopObjectCode();                                                    // --
}

Lock {
    [002D] if (getState08(activeObject)) {                                      // If door is open
    [0030]   clearState08();                                                    //  Close Door
    [0031]   setState04();                                                      //  Door locked
    [0032]   clearState08(133);                                                 //  Close Door (Lab Entry)
    [0034]   startSound(42);                                                    //  sound Steel Door
    [0036] }                                                                    // --
    [0036] stopObjectCode();                                                    // --
}

WalkTo {
    [0037] if (getState08(activeObject)) {                                      // If door is open
    [003A]   putActorInRoom(14,0);                                              //  Green Tentacle Leaves
    [003D]   putActor(14,0,0);
    [0041]   putActorInRoom(9,30);                                              //  Dr. Fred Enters Lab: Zom-b-Matic
    [0044]   putActor(9,20,20);
    [0048]   if (Var[135] == 0) {                                               //  Purple chased out of lab == No
    [004D]     putActorInRoom(13,31);                                           //   Purple enters Lab: Entry
    [0050]     putActor(13,44,63);
    [0054]     startScript(112);                                                //   start Purple Tentacle: Check Actor X > 20; print "What are you doing here?"
    [0056]     loadScript(43);
    [0058]     lockScript(43);
    [005A]     loadSound(63);
    [005C]     lockSound(63);
    [005E]   }
    [005E]   cursorCommand( kModeNoNewKid )                                     // Disable New Kid verb
    [0060]   startScript(7);                                                    // start Game: Meltdown Stop
    [0062]   stopScript(131);                                                   // stop Meteor Police: Timer until arrival
    [0064]   stopScript(138);                                                   // stop Cutscene: Dr. Fred Play Meteor Mess Trigger
    [0066]   stopScript(96);                                                    // stop Dr Fred: Play Meteor Mess
    [0068]   loadRoomWithEgo(133,31);                                           // Enter Lab: Entry
    [006B] }
    [006B] stopObjectCode();                                                    // --
}




/** Badge **/
roomobj-4-193.dmp

Pickup {
    [001B] pickupObject(0);                                                     // Pickup
    [001D] stopObjectCode();                                                    // --
}

Read {
    [001E] printEgo("Meteor Police, badge number 714.");                        // Read
    [003C] stopObjectCode();                                                    // --
}

Give {
    [003D] if (VAR_ACTIVE_ACTOR == 13) {                                        // Give to Purple Tentacle?
    [0042]   startScript(154);                                                  // start Cutscene: Purple Tentacle reacts to police badge
    [0044] }
    [0044] stopObjectCode();                                                    // --
}



/** Skeleton **/
roomobj-4-340.dmp

WalkTo {
    [001C] stopObjectCode();                                                    // --
}

WhatIs {
    [001D] if (Var[101] == 0) {                                                 // What is, already spoke?
    [0022]   printEgo("I wonder if I know him.");
    [0036]   Var[101] = 1;                                                      //  Dungeon Skeleton 'Hovered Over' = Yes
    [0039] }
    [0039] stopObjectCode();                                                    // --
}



/** Barred Window **/
roomobj-4-341.dmp



/** Barred Window **/
roomobj-4-343.dmp



/** Candle Holder **/
roomobj-4-345.dmp



/** Loose Brick **/
roomobj-4-446.dmp

Push {
    [001D] startScript(132);                                                    // start Dungeon Door Opened via Loose Brick
    [001F] stopObjectCode();                                                    // --
}




/**
 * Room 5: Library
 */


/** Door **/
roomobj-5-102.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(93);                                                      // Open Door (Room 3)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(93);                                                    // Close Door (Room 3)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // If Door Open
    [0027]   loadRoomWithEgo(93,3);                                             //  Enter Room Downstairs Lounge Room
    [002A] }
    [002A] stopObjectCode();                                                    // --
}



/** Phone **/
roomobj-5-103.dmp

Use {
    [001B] if (getState04(activeObject)) {                                      // If phone not repaired
    [001E]   startScript(28);                                                   // start Phone: Disconnect if Kid walks too far away
    [0020]   printEgo("It seems to be broken.");
    [0034] } else {                                                             // -
    [0037]   startScript(27);                                                   // start Phone: Disconnect
    [0039]   startScript(24);                                                   // start Pin: Entry - Edna Phone Number
    [003B] }
    [003B] stopObjectCode();                                                    // --
}

Pickup {
    [003C] startScript(28);                                                     // start Phone: Disconnect if Kid walks too far away
    [003E] if (getState04(activeObject)) {                                      // If phone not repaired
    [0041]   printEgo("It seems to be broken.");                                //
    [0055] } else {                                                             // -
    [0058]   startScript(28);                                                   //  start Phone: Disconnect if Kid walks too far away
    [005A]   startSound(21);                                                    //  sound
    [005C] }
    [005C] stopObjectCode();                                                    // --
}

Fix {
    [005D] if (getState04(activeObject)) {                                      // If phone not repaired
    [0060]   if (VAR_EGO == 7) {                                                //  If Jeff
    [0065]   } else {                                                           //
    [0068]     unless (VAR_EGO == 5) goto 00A6;                                 //  or Bernard
    [006D]   }
    [006D]   if (activeObject2 == 119) {                                        //  And ActiveObject2 is Tools
    [0071]     clearState04();                                                  //   Phone repaired
    [0072]     printEgo("That should do it.");
    [0083]   } else {                                                           // -
    [0086]     printEgo("I need some tools or something?!");
    [00A3]   }
    [00A3]   goto 00CB;                                                         // --
    [00A6]   printEgo("I don't know anything about electronics!");              //  else Other Kids
    [00CB] }
    [00CB] stopObjectCode();                                                    // --
}




/** Cassette Tape **/
roomobj-5-156.dmp

Pickup {
    [0023] pickupObject(0);                                                     // Pickup Tape
    [0025] stopObjectCode();                                                    // --
}

Use {
    [0026] doSentence(11,255,254);                                              // Use Tape with _cmdObject2
    [002A] stopObjectCode();                                                    // --
}

Give {
    [002B] if (VAR_ACTIVE_ACTOR == 14) {                                        // Give to Green Tentacle
    [0030]   if (VAR_ROOM == 20) {                                              //  if current room is Green Tentacle's
    [0035]     startScript(102);                                                //   start Green Tentacle: Accepts Tape
    [0037]   }
    [0037] }
    [0037] if (VAR_ACTIVE_ACTOR < 8) {                                          // Give to Kid
    [003C]   setOwnerOf(0,VAR_ACTIVE_ACTOR);                                    //  Kid owns object
    [003F] }
    [003F] stopObjectCode();                                                    // --
}




/** Loose Panel **/
roomobj-5-236.dmp

Open {
    [0023] setState08();                                                        // Open Panel
    [0024] stopObjectCode();                                                    // --
}

Close {
    [0025] clearState08();                                                      // Close Panel
    [0026] stopObjectCode();                                                    // --
}

Push.Pull {
    [0027] if (getState08(activeObject)) {                                      // Is Panel Open
    [002A]   clearState08();                                                    //  Close Panel
    [002B] } else {                                                             // -
    [002E]   setState08();                                                      //  Open Panel
    [002F] }
    [002F] stopObjectCode();                                                    // --
}



/** Lamp **/
roomobj-5-315.dmp

TurnOn {
    [0018] startSound(12);                                                      // sound Light Switch
    [001A] setBitVar(VAR_ROOM,1,0);                                             // Room has light
    [001E] startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    [0020] Var[117] = 1;                                                        // Room light on
    [0023] stopObjectCode();                                                    // --
}

TurnOff {
    [0024] startSound(12);                                                      // sound Light Switch
    [0026] Var[117] = 0;                                                        // Room light off
    [0029] if (Var[118] == 0) {
    [002E]   setBitVar(VAR_ROOM,1,1);                                           // Room loses light
    [0032]   startScript(50);                                                   //  start Room Lights: Check for flashlight / room light status
    [0034] }
    [0034] stopObjectCode();                                                    // --
}



/** Lamp **/
roomobj-5-316.dmp

TurnOn {
    [0018] startSound(12);                                                      // sound Light Switch
    [001A] setBitVar(VAR_ROOM,1,0);                                             // Room has light
    [001E] startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    [0020] Var[118] = 1;                                                        // Room light on
    [0023] stopObjectCode();                                                    // --
}

TurnOff {
    [0024] startSound(12);                                                      // sound Light Switch
    [0026] Var[118] = 0;                                                        // Room light off
    [0029] if (Var[117] == 0) {
    [002E]   setBitVar(4,1,1);                                                  // Room loses light
    [0032]   startScript(50);                                                   //  start Room Lights: Check for flashlight / room light status
    [0034] }
    [0034] stopObjectCode();                                                    // --
}



/** Staircase **/
roomobj-5-318.dmp

WalkTo {
    [001F] printEgo("Staircase out of order.");                                 // Walk To
    [0035] stopObjectCode();                                                    // --
}

Fix.Use {
    [0036] printEgo("I can't fix the stairs with that.");                       // Fix/Use
    [0053] stopObjectCode();                                                    // --
}



/** Chuck the plant **/
roomobj-5-319.dmp



/** Chair **/
roomobj-5-320.dmp



/** Sign **/
roomobj-5-440.dmp

Read {
    [0018] printEgo("Staircase out of order.");                                 // Read
    [002E] stopObjectCode();                                                    // --
}

Fix {
    [002F] if (activeObject2 == 119) {                                          // Use tools with Sign
    [0033]   printEgo("I'm not a carpenter.");
    [0046] } else {                                                             // -
    [0049]   printEgo("That won't work.");
    [0059] }
    [0059] stopObjectCode();                                                    // --
}




/**
 * Room 6: Pool Area
 */


/** Door **/
roomobj-6-104.dmp

Open {
    [0020] if (!getState04(activeObject)) {                                     // If door is unlocked
    [0023]   startScript(4);                                                    //  start Door: Open
    [0025]   setState08(92);                                                    //  Open Door (Storage room)
    [0027] } else {                                                             // -
    [002A]   startScript(64);                                                   //  start Print "The door is locked"
    [002C] }
    [002C] stopObjectCode();                                                    // --
}

Close {
    [002D] startScript(5);                                                      // start Door: Close
    [002F] clearState08(92);                                                    // Close Door (Storage room)
    [0031] stopObjectCode();                                                    // --
}

Unlock.Use {
    [0032] if (activeObject2 == 125) {                                          // if Use Silver Key with Door
    [0036]   clearState04();                                                    //  Unlock Door
    [0037]   clearState04(92);                                                  //  Unlock Door (Storage room)
    [0039]   doSentence(1,104,0);                                               //  Execute Verb: "Open Door"
    [003D] } else {                                                             // -
    [0040]   startScript(66);                                                   //  start Print "I can't unlock the door with this."
    [0042] }
    [0042] stopObjectCode();                                                    // --
}

Lock {
    [0043] setState04();                                                        // Lock Door
    [0044] setState04(92);                                                      // Lock Door (Storage Room)
    [0046] doSentence(2,104,0);                                                 // Execute Verb: "Close Door"
    [004A] stopObjectCode();                                                    // --
}

WalkTo {
    [004B] if (getState08(activeObject)) {                                      // Is Door Open
    [004E]   loadRoomWithEgo(92,36);                                            //  Enter Storage / Leading out to pool
    [0051] }
    [0051] stopObjectCode();                                                    // --
}



/** Gate **/
roomobj-6-105.dmp

WalkTo {
    [001E] if (getState08(activeObject)) {
    [0021]   if (Var[136] == 1) {                                               // is Garage Destroyed?
    [0026]     loadRoomWithEgo(75,52);                                          //  Enter Garage Destroyed
    [0029]   } else {                                                           // -
    [002C]     loadRoomWithEgo(110,16);                                         //  Enter Garage
    [002F]   }
    [002F] }
    [002F] stopObjectCode();                                                    // --
}

Open {
    [0030] startScript(4);                                                      // start Door: Open
    [0032] setState08(110);                                                     // Open Gate (Garage)
    [0034] setState08(75);                                                      // Open Gate (Destroyed Garage)
    [0036] stopObjectCode();                                                    // --
}

Close.Push {
    [0037] startScript(5);                                                      // start Door: Close
    [0039] clearState08(110);                                                   // Open Gate (Garage)
    [003B] clearState08(75);                                                    // Open Gate (Destroyed Garage)
    [003D] stopObjectCode();                                                    // --
}




/** Swimming Pool **/
roomobj-6-106.dmp

WalkTo {
    [0021] if (!getState08(activeObject)) {                                     // If Pool Full
    [0024]   printEgo("I don't want to get wet!");
    [0039] } else {                                                             // -
    [003C]   printEgo("I'd better use the ladder.");
    [0054]   doSentence(13,139,0);                                              // Use Ladder Script
    [0058] }
    [0058] stopObjectCode();                                                    // --
}

Use {
    [0059] if (!getState08(activeObject)) {                                     // If Pool Full
    [005C]   if (activeObject2 == 90) {                                         //  if Sponge
    [0060]     Var[24] = 2;                                                     //   Spong Contents = Radioactive Water
    [0063]     startScript(75);                                                 //   start Sponge: Name
    [0065]   }
    [0065]   if (activeObject2 == 99) {                                         //  if Glass Jar
    [0069]     Var[22] = 2;                                                     //   Glass Jar Contents = Radioactive Water
    [006C]     startScript(74);                                                 //   start Glass Jar: Name
    [006E]   }
    [006E] }
    [006E] stopObjectCode();                                                    // --
}



/** Radio **/
roomobj-6-107.dmp

WhatIs {
    [0017] printEgo("I can't reach it.");                                       // Pickup
    [0027] stopObjectCode();                                                    // --
}



/** Ladder **/
roomobj-6-139.dmp

WalkTo {
    [0018] loadRoomWithEgo(138,2);                                              // Enter Room 2, Bottom of Pool
    [001B] stopObjectCode();                                                    // --
}



/** Ladder **/
roomobj-6-272.dmp

WalkTo {
    [0018] printEgo("I'M not going down there%/%it's full of water!");          // Walk To
    [0041] stopObjectCode();                                                    // --
}



/** Pool Chair **/
roomobj-6-323.dmp

WhatIs {
    [001C] printEgo("I can't reach it.");                                       // What Is
    [002C] stopObjectCode();                                                    // --
}



/** Old Tree **/
roomobj-6-324.dmp



/**
 * Room 7: Kitchen
 */


/** Old Batteries **/
roomobj-7-100.dmp

Pickup {
    [0021] pickupObject(0);                                                     // Pikcup
    [0023] doSentence(13,56,0);                                                 // Walk To Refridgerator
    [0027] stopObjectCode();                                                    // --
}

Use {
    [0028] if (activeObject2 == 51) {                                           // Flashlight
    [002C]   Var[31] = 1;                                                       // Flashlight has Battery = Yes
    [002F]   Var[126] = 60;                                                     // Flashlight Battery Charge
    [0032]   setOwnerOf(100,0);                                                 // Remove Old Batteries
    [0035] }
    [0035] stopObjectCode();                                                    // --
}



/** Sealed Envelope **/
roomobj-7-234.dmp

Open {
    [0026] doSentence(1,201,0);                                                 // Open Sealed Envelope
    [002A] doSentence(14,234,0);                                                // Pickup Sealed Envelope
    [002E] stopObjectCode();                                                    // --
}

Pickup {
    [002F] clearState08();
    [0030] setState02();
    [0031] setOwnerOf(201,VAR_EGO);                                             // Kid owns Sealed Envelope
    [0034] Var[66] -= 2;                                                        // Item in Microwave -= 2
    [0037] stopObjectCode();                                                    // --
}

Use {
    [0038] doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    [003C] startScript(76);                                                     // Jar / Envelop: Name
    [003E] stopObjectCode();                                                    // --
}



/** Window **/
roomobj-7-276.dmp



/** Very dull knives **/
roomobj-7-277.dmp

Pickup {
    [0022] printEgo("They're glued to the wall.");                              // Pickup
    [003A] stopObjectCode();                                                    // --
}



/** Stove **/
roomobj-7-279.dmp

Use {
    [001F] printEgo("I don't think that's a good idea.");                       // Use
    [003C] stopObjectCode();                                                    // --
}

Open.Close.TurnOn.TurnOff {
    [003D] printEgo("I'd rather use the microwave.");                           // Open/Close/Turn On/Turn Off
    [0058] stopObjectCode();                                                    // --
}



/** Blood **/
roomobj-7-280.dmp

WhatIs {
    [0017] printEgo("Yuck!");                                                   // What Is
    [001E] stopObjectCode();                                                    // --
}



/** Door **/
roomobj-7-48.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(35);                                                      // Open Door (Main Entry)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(35);                                                    // Close Door (Main Entry)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // If Door Open
    [0027]   loadRoomWithEgo(35,10);                                            //  Enter Main Entry
    [002A] }
    [002A] stopObjectCode();                                                    // --
}



/** Door **/
roomobj-7-49.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(62);                                                      // Open Door (Dining)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(62);                                                    // Close Door (Dining)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // If Door Open
    [0027]   loadRoomWithEgo(62,37);                                            // Enter Dining
    [002A] }
    [002A] stopObjectCode();                                                    // --
}



/** Jar of Water **/
roomobj-7-50.dmp

Pickup {
    [002A] VAR_RESULT = isScriptRunning(55);                                    // is Timer: 1 Minute running
    [002D] if (VAR_RESULT == 1) {
    [0032]   printEgo("Ouch! It's still too hot!");
    [0049] } else {                                                             // -
    [004C]   clearState08();                                                    // Invisible Glass Jar
    [004D]   setState02();                                                      // Lock Glass Jar
    [004E]   setOwnerOf(99,VAR_EGO);                                            // Pickup Glass Jar
    [0051]   Var[66] -= 4;                                                      // Item in Microwave -= 4
    [0054] }
    [0054] stopObjectCode();                                                    // --
}




/** Flashlight **/
roomobj-7-51.dmp

Pickup {
    [0028] pickupObject(0);                                                     // Pickup Flashlight
    [002A] stopObjectCode();                                                    // --
}

TurnOn {
    [002B] if (Var[31] >= 1) {                                                  // if Flashlight has Battery
    [0030]   Var[12] = 1;                                                       //  Flashlight Status = On
    [0033]   startScript(77);                                                   //  start Flashnight: Name
    [0035]   if (Var[31] == 1) {                                                //  if Flashlight has Battery == Old Battery
    [003A]     startScript(145);                                                //   start Flashlight: Check
    [003C]   }
    [003C] } else {                                                             // -
    [003F]   printEgo("It needs batteries.");
    [0052] }
    [0052] stopObjectCode();                                                    // --
}

TurnOff {
    [0053] if (Var[31] >= 1) {                                                  // if Flashlight has Battery
    [0058]   Var[12] = 0;                                                       //  Flashlight Status = Off
    [005B]   startScript(77);                                                   //  start Flashnight: Name
    [005D]   stopScript(145);                                                   //  stop Flashlight: Check
    [005F] }
    [005F] stopObjectCode();                                                    // --
}

Use {
    [0060] doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    [0064] stopObjectCode();                                                    // --
}

Give {
    [0065] if (VAR_ACTIVE_ACTOR < 8) {                                          // Player Kid?
    [006A]   doSentence(5,51,0);                                                //  Turn Off Flashlight
    [006E]   setOwnerOf(0,VAR_ACTIVE_ACTOR);                                    //  Give to kid
    [0071] }
    [0071] stopObjectCode();                                                    // --
}




/** Microwave Oven **/
roomobj-7-52.dmp

Open {
    [0028] if (!getState08(activeObject)) {                                     // If Microwave on
    [002B]   stopScript(11);                                                    //  stop Hamster: In Microwave
    [002D]   stopScript(53);                                                    //  stop Microwave
    [002F]   startScript(4);                                                    //  start Door: Open
    [0031]   if (getState08(54)) {                                              // if Exploded Hamster Microwaved
    [0035]     clearState02(54);
    [0037]   }
    [0037]   if (getState08(53)) {                                              // if Hamster Microwaved
    [003B]     clearState02(53);
    [003D]   }
    [003D]   if (getState08(50)) {                                              // if Jar of Water Microwaved
    [0041]     clearState02(50);
    [0043]     if (Var[22] == 4) {                                              // Glass Jar Contents == Microwaved Developer
    [0048]       printEgo("Argh! What a smell!!");
    [005B]     }
    [005B]     if (Var[22] == 2) {                                              // Glass Jar Contents == Radioactive Water
    [0060]       VAR_RESULT = isScriptRunning(55);
    [0063]       if (VAR_RESULT == 1) {                                         // if Timer: 1 Minute has not finished
    [0068]         Var[76] = 1;                                                 //  Death Method = Radioactive Steam
    [006B]         startScript(56);                                             //  Cutscene: Kid Dies
    [006D]       }
    [006D]     }
    [006D]   }
    [006D]   if (getState08(234)) {                                             // if Sealed Envelope Microwaved
    [0071]     clearState02(234);                                               //  Stamps Removed
    [0073]   }
    [0073] }
    [0073] stopObjectCode();                                                    // --
}

Close {
    [0074] startScript(5);                                                      // start Door: Close
    [0076] setState02(54);                                                      // Exploded Hamster Microwaved
    [0078] setState02(53);                                                      // Hamster microwaved
    [007A] setState02(50);
    [007C] setState02(234);
    [007E] stopObjectCode();                                                    // --
}

Use {
    [007F] startScript(54);                                                     // start Microwave: Put item in
    [0081] stopObjectCode();                                                    // --
}

TurnOn {
    [0082] startScript(69);                                                     // start Microwave:
    [0084] stopObjectCode();                                                    // --
}

TurnOff {
    [0085] stopScript(11);                                                      // stop Hamster: In Microwave
    [0087] stopScript(53);                                                      // stop Microwave
    [0089] if (getState08(54)) {                                                // if Exploded Hamster Microwaved
    [008D]   printEgo("I think it's too late!");
    [00A1] }
    [00A1] stopObjectCode();                                                    // --
}



/** Hamster **/
roomobj-7-53.dmp

Pickup {
    [0019] clearState08();                                                      // Lock Hamster
    [001A] setState02();                                                        //
    [001B] setOwnerOf(1,VAR_EGO);                                               // Kid owns hamster
    [001E] Var[66] = 0;                                                         // Item in Microwave = Empty
    [0021] stopObjectCode();                                                    // --
}


/** Exploded Hamster **/
roomobj-7-54.dmp

Pickup {
    [0024] if (VAR_EGO <= 2) {                                                  //  Syd/Razor
    [0029]   printEgo("Yum! Should I take white or dark meat?");
    [004A] } else {                                                             // -
    [004D]   printEgo("How gross!");                                            //  Other Kids
    [0058] }
    [0058] pickupObject(0);                                                     // Pickup
    [005A] clearState08(54);                                                    // Hide Exploded Hamster
    [005C] setState02(54);
    [005E] Var[66] = 0;                                                         // Item in Microwave = Empty
    [0061] stopObjectCode();                                                    // --
}

Give {
    [0062] startScript(98);                                                     // start Give: Accept Item Check
    [0064] if (VAR_ACTIVE_ACTOR == 11) {                                        // if Giving To Weird Ed
    [0069]   Var[76] = 3;                                                       //  Death Method = Ed Kills you
    [006C]   startScript(56);                                                   //  Cutscene: Kid Dies
    [006E] }
    [006E] stopObjectCode();                                                    // --
}



/** Faucet **/
roomobj-7-55.dmp

TurnOn {
    [001C] clearState08();                                                      // Faucet is on
    [001D] startSound(17);                                                      //
    [001F] stopObjectCode();                                                    // --
}

TurnOff {
    [0020] setState08();                                                        // Faucet is off
    [0021] stopSound(17);
    [0023] stopObjectCode();                                                    // --
}

Use {
    [0024] if (!getState08(activeObject)) {                                     // if Faucet is on
    [0027]   startScript(73);                                                   //  start Facet: Fill Gar/Sponge with Water
    [0029]   startScript(76);                                                   //  start Jar / Envelop: Name
    [002B] }
    [002B] stopObjectCode();                                                    // --
}



/** Refridgerator **/
roomobj-7-56.dmp

Open.Pull {
    [0024] startScript(4);                                                      // start Door: Open
    [0026] if (Var[128] == 0) {                                                 // has Fridge has been opened?
    [002B]   Var[128] = 1;                                                      //  Fridge has been opened = Yes
    [002E]   Var[127] = 2;                                                      //  Weird Ed Trigger = Cheese
    [0031]   startScript(82);                                                   //  start Weird Ed: Leave Room
    [0033] }
    [0033] stopObjectCode();                                                    // --
}

Close.Push {
    [0034] startScript(5);                                                      // start Door: Close
    [0036] stopObjectCode();                                                    // --
}



/** Cheese **/
roomobj-7-57.dmp

Pickup {
    [001A] pickupObject(0);                                                     // Pickup Cheese
    [001C] doSentence(13,56,0);                                                 // Walk to Refridgerator
    [0020] stopObjectCode();                                                    // --
}

Give {
    [0021] startScript(98);                                                     // start Give: Accept Item Check
    [0023] stopObjectCode();                                                    // --
}




/** Lettuce **/
roomobj-7-58.dmp

Pickup {
    [001B] pickupObject(0);                                                     // Pick object
    [001D] doSentence(13,56,0);                                                 // Walk to Refridgerator
    [0021] stopObjectCode();                                                    // --
}

Give {
    [0022] startScript(98);                                                     // start Give: Accept Item Check
    [0024] stopObjectCode();                                                    // --
}




/** Broken Bottles **/
roomobj-7-59.dmp

Pickup {
    [002D] pickupObject(0);                                                     // Pick object
    [002F] doSentence(13,56,0);                                                 // Walk to Refridgerator
    [0033] stopObjectCode();                                                    // --
}

Give {
    [0034] startScript(98);                                                     // start Give: Accept Item Check
    [0036] stopObjectCode();                                                    // --
}




/** Can of Pepsi **/
roomobj-7-60.dmp

Pickup {
    [0024] pickupObject(0);                                                     // Pick object
    [0026] doSentence(13,56,0);                                                 // Walk to Refridgerator
    [002A] stopObjectCode();                                                    // --
}

Read {
    [002B] printEgo("12 fluid ounces (354 ml)");                                // Read
    [0041] stopObjectCode();                                                    // --
}

Use {
    [0042] doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    [0046] stopObjectCode();                                                    // --
}

Give {
    [0047] if (VAR_ACTIVE_ACTOR == 19) {                                        // If give to Plant
    [004C]   startScript(48);                                                   //  start Plant: Give Pepsi
    [004E] } else if (VAR_ACTIVE_ACTOR > 8) {                                   // -
    [0056]   print(VAR_ACTIVE_ACTOR,"No thanks, it makes me burp.");            //  Only kids take drink
    [0070] } else {                                                             // -
    [0073]   startScript(99);                                                   //  start Give: Accept Item Check 2
    [0075] }
    [0075] stopObjectCode();                                                    // --
}




/** Chainsaw **/
roomobj-7-61.dmp

Pickup {
    [001E] pickupObject(0);                                                     // Pick object
    [0020] stopObjectCode();                                                    // --
}

TurnOn.Use {
    [0021] printEgo("I think it's out of gas.");
    [0036] if (VAR_EGO == 1) {                                                  // If kid is Syd
    [003B]   printEgo("Let's go find some gas!");
    [0050] }
    [0050] stopObjectCode();                                                    // --
}



/**
 * Room 8: Basement
 */

 /** Stairs **/
roomobj-8-121.dmp

WalkTo {
    [0018] loadRoomWithEgo(36,10);                                              // Enter Main Entry
    [001B] stopObjectCode();                                                    // --
}



/** Door **/
roomobj-8-122.dmp

Open {
    [0020] if (!getState08(activeObject)) {                                     // Is door locked
    [0023]   startScript(64);                                                   // start Print "The door is locked"
    [0025] }
    [0025] stopObjectCode();                                                    // --
}

Close.Lock {
    [0026] startScript(51);                                                     // start Dungeon: Close Entry Door
    [0028] stopObjectCode();                                                    // --
}

Unlock.Use {
    [0029] if (activeObject2 == 43) {                                           // Use Old Rusty Key with Door
    [002D]   startScript(4);                                                    //  start Door: Open
    [002F]   setState08(126);                                                   //  Open Door (Main Entry)
    [0031] } else {                                                             // -
    [0034]   startScript(66);                                                   //  start Print "I can't unlock the door with this."
    [0036] }
    [0036] stopObjectCode();                                                    // --
}
WalkTo {
    [0037] if (getState08(activeObject)) {                                      // if door is open
    [003A]   doSentence(2,122,0);                                               //   Close Door
    [003E]   loadRoomWithEgo(126,4);                                            //   Enter Basement
    [0041] }
    [0041] stopObjectCode();                                                    // --
}




/** Fuse Box **/
roomobj-8-123.dmp

Open {
    [001C] setState08();                                                        // Open Fuse Box
    [001D] startSound(8);                                                       // Door Opening
    [001F] stopObjectCode();                                                    // --
}

Close {
    [0020] clearState08();                                                      // Close Fuse Box
    [0021] stopObjectCode();                                                    // --
}



/** Circuit Breaker **/
roomobj-8-124.dmp

TurnOn {
    [0028] VAR_RESULT = isScriptRunning(138);
    [002B] if (VAR_RESULT == 1) {                                               // if Cutscene: Dr. Fred Play Meteor Mess Trigger running
    [0030]   startSound(12);                                                    //  Sound Light Switch

    [0032] } else if (getState08(activeObject)) {                               // - If Power Off
    [0038]   clearState08();                                                    //  Power On
    [0039]   startSound(12);                                                    //  sound Light Switch
    [003B]   startScript(50);                                                   //  start Room Lights: Check for flashlight / room light status

    [003D]   if (!getState08(106)) {                                            //  if Swimming Pool is full
    [0041]     startScript(7);                                                  //   Game: Meltdown Stop
    [0043]   }
    [0043] }
    [0043] stopObjectCode();                                                    // --
}

TurnOff {
    [0044] if (!getState08(activeObject)) {                                     // If Power On
    [0047]   stopScript(138);                                                   //  stop Cutscene: Dr. Fred Play Meteor Mess Trigger
    [0049]   setState08();                                                      //  Power Off
    [004A]   startSound(12);                                                    //  sound Light Switch
    [004C]   startScript(50);                                                   //  start Room Lights: Check for flashlight / room light status
    [004E]   startScript(6);                                                    //  start Game: Meltdown Timer
    [0050]   stopScript(138);                                                   //  stop Cutscene: Dr. Fred Play Meteor Mess Trigger
    [0052]   Var[29] = 0;                                                       //  Radio = off
    [0055]   clearState08(207);                                                 //  Cassette Player = Off
    [0057]   clearState08(157);                                                 //  TV = Off
    [0059]   clearState08(158);                                                 //  Casette Recorder = Off
    [005B]   clearState08(131);                                                 //  Mondo Stereo = Off
    [005D]   stopScript(15);                                                    //  stop Cassette: Play, Break Windows/Free Key
    [005F]   clearState08(169);                                                 //  stop Video Fever
    [0061]   clearState08(170);                                                 //  stop Disco Crazy
    [0063]   clearState08(171);                                                 //  stop Alien Slime
    [0065]   clearState08(172);                                                 //  stop Die Enemy Die
    [0067]   clearState08(174);                                                 //  stop Kill Thrill
    [0069]   Var[28] = 0;                                                       //  Radio (Room 21) = Off
    [006C] }
    [006C] stopObjectCode();                                                    // --
}

Close {
    [006D] clearState08(123);                                                   // Close Fuse Box
    [006F] stopObjectCode();                                                    // --
}

Read {
    [0070] printEgo("MAIN POWER");                                              // Read
    [007B] stopObjectCode();                                                    // --
}



/** Silvey Key **/
roomobj-8-125.dmp

Pickup {
    [001E] pickupObject(0);                                                     // Pick object
    [0020] stopObjectCode();                                                    // --
}

Use {
    [0021] doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    [0025] stopObjectCode();                                                    // --
}




/** Light Switch **/
roomobj-8-325.dmp

TurnOn {
    [0020] startSound(12);                                                      // sound Light Switch
    [0022] setBitVar(VAR_ROOM,1,0);                                             // Light On
    [0026] startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    [0028] stopObjectCode();                                                    // --
}

TurnOff {
    [0029] startSound(12);                                                      // sound Light Switch
    [002B] setBitVar(VAR_ROOM,1,1);                                             // Light Off
    [002F] startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    [0031] stopObjectCode();                                                    // --
}



/** Radioactive**/
roomobj-8-337.dmp

WhatIs {
    [0023] printEgo("Yuck! I'm not touching that!");                            // What Is
    [003D] stopObjectCode();                                                    // --
}




/** Furnace **/
roomobj-8-338.dmp

WalkTo {
    [001B] stopObjectCode();                                                    // -- Walk To
}

WhatIs {
    [001C] printEgo("It's too hot!");                                           // What Is
    [0029] stopObjectCode();                                                    // --
}




/** Nuclear Reactor **/
roomobj-8-339.dmp

WalkTo {
    [0027] stopObjectCode();                                                    // --
}

TurnOff {
    [0028] printEgo("I don't want to start a melt down!");                      //
    [0045] stopObjectCode();                                                    // --
}

Read {
    [0046] printEgo("Made in Chernobyl");                                       //
    [0057] stopObjectCode();                                                    // --
}

WhatIs {
    [0058] printEgo("It's too hot!");                                           //
    [0065] stopObjectCode();                                                    // --
}




/**
 * Room 9: Attic (Above Nurse Edna's Room)
 */

 /** Hatch **/
roomobj-9-196.dmp

Open.Pickup {
    [001F] startScript(4);                                                      // start Door: Open
    [0021] stopObjectCode();                                                    // --
}

Close {
    [0022] startScript(5);                                                      // start Door: Close
    [0024] stopObjectCode();                                                    // --
}

Pull {
    [0025] if (getState08(activeObject)) {                                      // If hatch is open
    [0028]   startScript(5);                                                    // start Door: Close
    [002A] } else {                                                             // -
    [002D]   startScript(4);                                                    // start Door: Open
    [002F] }
    [002F] stopObjectCode();                                                    // --
}

WalkTo {
    [0030] if (getState08(activeObject)) {                                      // If hatch is open
    [0033]   if (Var[109] == 0) {
    [0038]     if (Var[17] == 0) {                                              //  If Nurse Edna Disabled = No
    [003D]       putActorInRoom(10,19);                                         //   Put Nurse Edna in room
    [0040]       putActor(10,34,64);
    [0044]       animateActor(10,6,1);                                          //   Nurse Edna Face camera
    [0048]       startScript(33);                                               //   start Nurse Edna: Leave Room
    [004A]     }
    [004A]   }
    [004A]   loadRoomWithEgo(210,19);                                           //  Enter Nurse Edna's at Ladder
    [004D] }
    [004D] stopObjectCode();                                                    // --
}




/** Painting **/
roomobj-9-197.dmp

Open {
    [001E] startScript(4);                                                      // start Door: Open
    [0020] stopObjectCode();                                                    // --
}

Close {
    [0021] startScript(5);                                                      // start Door: Close
    [0023] clearState08(198);                                                   // Close Wall Safe
    [0025] stopObjectCode();                                                    // --
}




/** Wall Safe **/
roomobj-9-198.dmp

Use {
    [001F] if (!getState08(activeObject)) {                                     // Is Closed
    [0022]   startScript(39);                                                   //  start Room9: Wallsafe Input
    [0024] }
    [0024] stopObjectCode();                                                    // --
}

Close {
    [0025] startScript(5);                                                      // start Door: Close
    [0027] clearState08(197);                                                   // Close Painting
    [0029] stopObjectCode();                                                    // --
}




/** Quarter **/
roomobj-9-200.dmp

Use {
    [0019] doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    [001D] stopObjectCode();                                                    // --
}




/** Sealed Envelope **/
roomobj-9-201.dmp

Pickup {
    [0032] pickupObject(0);                                                     // Pick object
    [0034] pickupObject(200);                                                   // Pick Quarter
    [0036] setOwnerOf(200,14);                                                  // Set Owner of Quarter to Green Tentacle
    [0039] stopObjectCode();                                                    // --
}

Use {
    [003A] startScript(81);                                                     // start Envelope: Use
    [003C] stopObjectCode();                                                    // --
}

Open {
    [003D] if (!getState08(201)) {                                              // if Sealed Envelope closed
    [0041]   doSentence(1,201,0);                                               //  Open Sealed Envelope
    [0045]   doSentence(14,201,0);                                              //  Pickup Sealed Envelope
    [0049] } else {                                                             // -
    [004C]   startScript(80);                                                   //  start Envelope: Open
    [004E] }
    [004E] stopObjectCode();                                                    // --
}

Read {
    [004F] if (Var[85] == 0) {                                                  // if Envelope: Addressed == No
    [0054]   printEgo("It's a blank envelope.");
    [0069] } else {                                                             // -
    [006C]   printEgo("It's addressed to: 222 Skyscraper Way.");
    [008F] }
    [008F] stopObjectCode();                                                    // --
}



/** Light Switch **/
roomobj-9-293.dmp

TurnOn {
    [001B] startSound(12);                                                      // sound Light Switch
    [001D] setBitVar(VAR_ROOM,1,0);                                             //
    [0021] startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    [0023] stopObjectCode();                                                    // --
}

TurnOff {
    [0024] startSound(12);                                                      // sound Light Switch
    [0026] setBitVar(VAR_ROOM,1,1);                                             // Light Off
    [002A] startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    [002C] stopObjectCode();                                                    // --
}

Pull {
    [002D] VAR_RESULT = getBitVar(VAR_ROOM,1);
    [0031] if (VAR_RESULT == 0) {                                               // Is light off
    [0036]   doSentence(5,37,0);                                                // Turn on Light Switch
    [003A] } else {                                                             // -
    [003D]   doSentence(4,37,0);                                                // Turn off Light Switch
    [0041] }
    [0041] stopObjectCode();                                                    // --
}




/** Scrawled Number **/
roomobj-9-414.dmp

Read {
    [0021] printEgo("It's too tiny to read!");                                  //
    [0035] stopObjectCode();                                                    // --
}




/**
 * Room 10: Main Entry
 */


/** Stairs **/
roomobj-10-209.dmp

WalkTo {
    [0018] loadRoomWithEgo(146,11);                                             // Enter Top of Main Entry
    [001B] stopObjectCode();                                                    // --
}




/** Grandfather Clock **/
roomobj-10-269.dmp

Read {
    [0023] printEgo("It's the correct time.");
    [0038] stopObjectCode();                                                    // --
}




/** Vase **/
roomobj-10-270.dmp



/** Vase **/
roomobj-10-271.dmp



/** Front Door **/
roomobj-10-321.dmp

Open {
    [0020] doSentence(1,34,0);                                                  // Open Door
    [0024] stopObjectCode();                                                    // --
}

Close {
    [0025] doSentence(2,34,0);                                                  // Close Door
    [0029] stopObjectCode();                                                    // --
}

WalkTo {
    [002A] doSentence(13,34,0);                                                 // Walk to Door
    [002E] stopObjectCode();                                                    // --
}




/** Door **/
roomobj-10-34.dmp

Open {
    [0020] startScript(4);                                                      // start Door: Open
    [0022] setState08(28);                                                      // Open Door (Outside Mansion)
    [0024] stopObjectCode();                                                    // --
}

Close {
    [0025] startScript(5);                                                      // start Door: Close
    [0027] clearState08(28);                                                    // Close Door (Outside Mansion)
    [0029] stopObjectCode();                                                    // --
}

WalkTo {
    [002A] if (getState08(activeObject)) {
    [002D]   loadRoomWithEgo(28,1);                                             // Enter Outside Mansion
    [0030] }
    [0030] stopObjectCode();                                                    // --
}




/** Gargoyle **/
roomobj-10-342.dmp

Push.Pull {
    [001C] startScript(144);                                                    // start Gargoyle: Open Basement Door
    [001E] stopObjectCode();                                                    // --
}




/** Gargoyle **/
roomobj-10-344.dmp



/** Door: Kitchen **/
roomobj-10-35.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(48);                                                      // Open Door (Kitchen)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(48);                                                    // Close Door (Kitchen)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // If Door is open
    [0027]   VAR_RESULT = isScriptRunning(147);                                 //
    [002A]   if (VAR_RESULT == 1) {                                             // if is running Nurse Edna: In Kitchen Monitor
    [002F]     startScript(148);                                                //  Nurse Edna: In Kitchen
    [0031]     loadScript(30);
    [0033]     lockScript(30);
    [0035]   }
    [0035]   loadRoomWithEgo(48,7);                                             // Enter Kitchen at Door
    [0038] }
    [0038] stopObjectCode();                                                    // --
}



/** Door: Basement **/
roomobj-10-36.dmp

Open.Close {
    [001A] printEgo("There's no handle here!");                                 // Open/Close
    [0030] stopObjectCode();
}

WalkTo {
    [0031] if (getState08(activeObject)) {                                      // If Door is open
    [0034]   loadRoomWithEgo(121,8);                                            //  Enter basement
    [0037]   startScript(149);                                                  //  start  -= Does Nothing =-
    [0039] }
    [0039] stopObjectCode();                                                    // --
}




/** Door **/
roomobj-10-37.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(38);                                                      // Open Door (Downstairs Lounge Room)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(38);                                                    // Close Door (Downstairs Lounge Room)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // If Door is open
    [0027]   loadRoomWithEgo(38,3);                                             //  Enter Downstairs Lounge Room
    [002A] }
    [002A] stopObjectCode();                                                    // --
}




/**
 * Room 11: Top of Main Entry
 */


/** Stairs **/
roomobj-11-146.dmp

WalkTo {
    [0018] loadRoomWithEgo(209,10);                                             // Enter Main Entry
    [001B] stopObjectCode();                                                    // --
}




/** Door **/
roomobj-11-147.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(164);                                                     // Open Door (Portrait Painting)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(164);                                                   // Close Door (Portrait Painting)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // if door is open
    [0027]   loadRoomWithEgo(164,14);                                           //  Enter Portrait Painting
    [002A] }
    [002A] stopObjectCode();                                                    // --
}




/** Door **/
roomobj-11-148.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(152);                                                     // Open Door (Music)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(152);                                                   // Close Door (Music)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // if door is open
    [0027]   loadRoomWithEgo(152,17);                                           //  Enter Music
    [002A] }
    [002A] stopObjectCode();                                                    // --
}




/** Door **/
roomobj-11-149.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(160);                                                     // Open Door (Level 2 Main Hallway)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(160);                                                   // Close Door (Door (Level 2 Main Hallway)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // Is Door Open
    [0027]   loadRoomWithEgo(160,13);                                           //  Enter Level 2 Main Hallway
    [002A] }
    [002A] stopObjectCode();                                                    // --
}




/** Painting of Fred **/
roomobj-11-150.dmp

Open.Pull {
    [0024] startScript(62);                                                     // start Print "Its firmly attached to the wall"
    [0026] stopObjectCode();                                                    // --
}



/** Painting of Edna **/
roomobj-11-151.dmp

Open.Pull {
    [0024] startScript(62);                                                     // start Print "Its firmly attached to the wall"
    [0026] stopObjectCode();                                                    // --
}




/** Wall Lamp **/
roomobj-11-354.dmp

TurnOn {
    [001D] startSound(12);                                                      // sound Light Switch
    [001F] setBitVar(VAR_ROOM,1,0);                                             // Light On
    [0023] startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    [0025] Var[120] = 0;                                                        // Wall Lamp 354 On
    [0028] stopObjectCode();                                                    // --
}

TurnOff {
    [0029] startSound(12);                                                      // sound Light Switch
    [002B] Var[120] = 1;                                                        // Wall Lamp 354 off
    [002E] if (Var[119] == 1) {                                                 // If Wall Lamp 355 Off
    [0033]   setBitVar(4,1,1);                                                  //  Light Off
    [0037]   startScript(50);                                                   //  start Room Lights: Check for flashlight / room light status
    [0039] }
    [0039] stopObjectCode();                                                    // --
}



/** Wall Lamp **/
roomobj-11-355.dmp

TurnOn {
    [001D] startSound(12);                                                      // sound Light Switch
    [001F] setBitVar(VAR_ROOM,1,0);                                             // Light On
    [0023] startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    [0025] Var[119] = 0;                                                        // Wall Lamp 355 On
    [0028] stopObjectCode();                                                    // --
}

TurnOff {
    [0029] startSound(12);                                                      // sound Light Switch
    [002B] Var[119] = 1;                                                        // Wall Lamp 355 Off
    [002E] if (Var[120] == 1) {                                                 // If Wall Lamp 354 Off
    [0033]   setBitVar(VAR_ROOM,1,1);                                           //  Light Off
    [0037]   startScript(50);                                                   //  start Room Lights: Check for flashlight / room light status
    [0039] }
    [0039] stopObjectCode();                                                    // --
}




/**
 * Room 12: Level 2 Stairs to Level 3
 */


/** Stairs **/
roomobj-12-179.dmp

WalkTo {
    [0018] Var[86] = 0;                                                         // Enter Level 2 Main Hallway From Level 2 Stairs to Level 3
    [001B] cursorCommand( kModeNormal )                                         // Cutscene Mode Normal
    [001D] loadRoomWithEgo(161,13);                                             // Enter Level 2 Main Hallway
    [0020] stopObjectCode();                                                    // --
}




/** Stairs **/
roomobj-12-180.dmp

WalkTo {
    [0018] if (Var[84] == 0) {                                                  // if Weird Ed has been actived by stairs in room 12
    [001D]   Var[84] = 1;                                                       //  Weird Ed has been actived by stairs in room 12 = Yes
    [0020]   startScript(106);                                                  //  start Door Bell
    [0022] }
    [0022] loadRoomWithEgo(208,38);                                             // Enter Level 3 Hallway
    [0025] stopObjectCode();                                                    // --
}




/** Door **/
roomobj-12-181.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(182);                                                     // Open Door (Level 2 Stairs to Level 3)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(182);                                                   // Close Door (Level 2 Stairs to Level 3)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // if door is open
    [0027]   loadRoomWithEgo(182,23);                                           //  Enter Darkroom
    [002A] }
    [002A] stopObjectCode();                                                    // --
}




/** Lowly plant **/
roomobj-12-378.dmp



/** Window **/
roomobj-12-379.dmp



/** Window **/
roomobj-12-380.dmp



/** Window **/
roomobj-12-381.dmp



/**
 * Room 13: Level 2 Main Hallway
 */


/** Door **/
roomobj-13-160.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(149);                                                     // Open Door (Top of Main Entry)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(149);                                                   // Close Door (Top of Main Entry)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // If Door Open
    [0027]   loadRoomWithEgo(149,11);                                           //  Enter Top of Main Entry
    [002A] }
    [002A] stopObjectCode();                                                    // --
}




/** Stairs **/
roomobj-13-161.dmp

WalkTo {
    [0018] if (Var[86] == 1) {                                                  // if Kid is in Level 2 - Level 3 hallway == Yes
    [001D]   printEgo("I'm not going up there%/%that monster's got my fri!");
    [004D]   walkActorTo(VAR_EGO,78,69);                                        // Walk actor away
    [0051] } else {                                                             // -
    [0054]   loadRoomWithEgo(179,12);                                           // Enter Level 2 Stairs to Level 3
    [0057] }
    [0057] stopObjectCode();                                                    // --
}




/** Door **/
roomobj-13-162.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(175);                                                     // Open Door (Medical)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(175);                                                   // Close Door (Medical)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // if door is open
    [0027]   loadRoomWithEgo(175,22);                                           // Enter Medical
    [002A] }
    [002A] stopObjectCode();                                                    // --
}




/** Door **/
roomobj-13-163.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(168);                                                     // Open Door (Video Game)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(168);                                                   // Close Door (Video Game)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // if door open
    [0027]   loadRoomWithEgo(168,18);                                           //  Enter Video Game
    [002A] }
    [002A] stopObjectCode();                                                    // --
}




/** Statue **/
roomobj-13-360.dmp

Push.Pull.Pickup {
    [001E] printEgo("It's too heavy to move.");                                 // Push/Pull
    [0033] stopObjectCode();                                                    // --
}

Read {
    [0034] printEgo("Maybe there's a plaque somewhere.");                       // Read
    [0053] stopObjectCode();                                                    // --
}




/** Plaque on statue **/
roomobj-13-361.dmp

Read {
    [0022] printEgo("Si trouve, envoyez-le au Louvre,/poste paye.");            // Read "If found, s to the Louvre, postage paid."
    [004B] stopObjectCode();                                                    // --
}




/**
 * Room 14: Portrait Painting
 */


/** Door **/
roomobj-14-164.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(147);                                                     // Open Door (Top of Main Entry)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(147);                                                   // Close Door (Top of Main Entry)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // If door is open
    [0027]   loadRoomWithEgo(147,11);                                           //  Enter Top of Main Entry
    [002A] }
    [002A] stopObjectCode();                                                    // --
}




/** Bowl of wax fruit **/
roomobj-14-165.dmp

Pickup {
    [0025] pickupObject(0);                                                     // Pick object
    [0027] stopObjectCode();                                                    // --
}

Give {
    [0028] Var[107] = 165;                                                      // Give Script: Object-ID = Bowl of Wax Fruit
    [002B] startScript(98);                                                     // start Give: Accept Item Check
    [002D] stopObjectCode();                                                    // --
}




/** Paint Brush **/
roomobj-14-166.dmp

Pickup {
    [001D] pickupObject(0);                                                     // Pick object
    [001F] stopObjectCode();                                                    // --
}




/** Paint Brush **/
roomobj-14-167.dmp

Pickup {
    [0023] pickupObject(0);                                                     // Pick object
    [0025] stopObjectCode();                                                    // --
}

Use {
    [0026] setOwnerOf(0,14);                                                    // Use Paintbrush, Set owner to Green Tentacle
    [0029] if (activeObject2 == 68) {                                           // if object2 == Paint Blotch
    [002D]   setState08(68);                                                    //  Hide Paint Blotch
    [002F]   setState02(68);                                                    //  Hide Paint Blotch
    [0031] } else {                                                             // -
    [0034]   printEgo("That sure was a waste.");
    [0048] }
    [0048] stopObjectCode();                                                    // --
}

Give {
    [0049] if (VAR_ACTIVE_ACTOR == 14) {                                        // Give to Green Tentacle
    [004E]   printEgo("Yech! No thanks.");
    [005E] } else if (VAR_ACTIVE_ACTOR < 8) {
    [0066]   setOwnerOf(0,VAR_ACTIVE_ACTOR);                                    // Give to Kid
    [0069] }
    [0069] stopObjectCode();                                                    // --
}




/** Easel **/
roomobj-14-362.dmp



/** Unfinished Painting **/
roomobj-14-363.dmp



/** Cafe **/
roomobj-14-364.dmp



/** Dried Purple Slime **/
roomobj-14-365.dmp

WhatIs {
    [0024] printEgo("I'M not going to touch that slime!");                      // What is
    [0042] stopObjectCode();                                                    // --
}




/** Sketch **/
roomobj-14-366.dmp



/**
 * Room 15: Electrical Wiring
 */

/** Hatch **/
roomobj-15-202.dmp

Open {
    [001F] startScript(4);                                                      // start Door: Open
    [0021] setState08(69);                                                      // Open Door (Typewriter)
    [0023] stopObjectCode();                                                    // --
}

Close {
    [0024] startScript(5);                                                      // start Door: Close
    [0026] clearState08(69);                                                    // Close Door (Typewriter)
    [0028] stopObjectCode();                                                    // --
}

Pull {
    [0029] if (getState08(activeObject)) {                                      // If Door open
    [002C]   startScript(5);                                                    //  start Door: Close
    [002E] } else {                                                             // -
    [0031]   startScript(4);                                                    //  start Door: Open
    [0033] }
    [0033] stopObjectCode();                                                    // --
}

WalkTo {
    [0034] if (getState08(activeObject)) {                                      // If Door Open
    [0037]   loadRoomWithEgo(69,27);                                            //  Enter Typewriter
    [003A] }
    [003A] stopObjectCode();                                                    // --
}




/** Wires **/
roomobj-15-204.dmp

Fix.Use {
    [0027] if (!getState08(activeObject)) {                                     // If Wires Broken
    [002A]   if (getState08(124)) {                                             //  If Power Off
    [002E]     if (activeObject2 == 119) {                                      //   if using with Tools
    [0032]       VAR_RESULT = getObjectOwner(51);
    [0035]       if (VAR_RESULT == VAR_EGO) {                                   //    if Player owns Flashlight?
    [003A]         if (Var[12] == 1) {                                          //     if Flashlight Status == On
    [003F]           setState08();                                              //      Wires fixed
    [0040]           printEgo("There, that should do it.");
    [0057]           startScript(96);                                           //      start Dr Fred: Play Meteor Mess
    [0059]         } else {                                                     // -
    [005F]           goto 0086;
    [0062]         }
    [0062]       }
    [0062]       printEgo("It's kind of dark,/but I think I fixed it.");
    [0086]     }
    [0086]   } else {                                                           // -
    [0089]     doSentence(1,204,0);                                             // Open Wires
    [008D]   }
    [008D] }
    [008D] stopObjectCode();                                                    // --
}

Open.Close.TurnOn.TurnOff.Push.Pull.Pickup {
    [008E] if (!getState08(activeObject)) {                                     // If wires broken
    [0091]   if (!getState08(124)) {                                            //  If power on
    [0095]     printEgo("YOWL!!!");
    [009E]     startSound(27);                                                  //   Sound Zapp
    [00A0]   } else {                                                           // -
    [00A3]     printEgo("I can't fix it with my bare hands!");
    [00C0]   }
    [00C0] }
    [00C0] stopObjectCode();                                                    // --
}




/** Boarded up Window **/
roomobj-15-399.dmp
Events:
  Open - 0029
   Fix - 0040
  Pull - 0029
   Use - 0040

Open.Pull {
    [0029] printEgo("The boards won't budge.");                                 //
    [003F] stopObjectCode();                                                    // --
}

Fix.Use {
    [0040] if (activeObject2 == 119) {                                          // If use with Tools
    [0044]   printEgo("Hmm. I don't have the right tool.");
    [0061] }
    [0061] stopObjectCode();                                                    // --
}



/** Light **/
roomobj-15-401.dmp

TurnOn {
    [0019] startSound(12);                                                      // sound Light Switch
    [001B] setBitVar(VAR_ROOM,1,0);                                             // Light On
    [001F] startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    [0021] stopObjectCode();                                                    // --
}

TurnOff {
    [0022] startSound(12);                                                      // sound Light Switch
    [0024] setBitVar(VAR_ROOM,1,1);                                             // Light Off
    [0028] startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    [002A] stopObjectCode();                                                    // --
}



/** Wires **/
roomobj-15-415.dmp




/**
 * Room 16: Garage
 */


/** < Unnamed > **/
roomobj-16-101.dmp



/** Gate **/
roomobj-16-110.dmp

Open.Pull {
    [001E] if (!getState04(activeObject)) {                                     // If gate is unlocked
    [0021]   startScript(116);                                                  //  start Verb: Generic: Open Door
    [0023]   setState08(105);                                                   //  Open Gate (Pool Area)
    [0025] } else {                                                             // -
    [0028]   printEgo("It's locked.");
    [0035] }
    [0035] stopObjectCode();                                                    // --
}

Close.Push {
    [0036] startScript(117);                                                    // start Verb: Generic: Close Door
    [0038] clearState08(105);                                                   // Close Gate (Pool Area)
    [003A] stopObjectCode();                                                    // --
}

WalkTo {
    [003B] if (getState08(activeObject)) {                                      // If gate is open
    [003E]   loadRoomWithEgo(105,6);                                            // Enter Pool Area
    [0041] }
    [0041] stopObjectCode();                                                    // --
}



/** Garage Door **/
roomobj-16-111.dmp

Open.Pull {
    [0021] Var[90] = getActorBitVar(VAR_EGO,1);                                 // Current Actor Flag kActorMiscFlagStrong
    [0025] if (Var[90] == 1) {                                                  // Kid is strong?
    [002A]   startScript(8);                                                    //  start Garage Door Open
    [002C] } else {                                                             // -
    [002F]   printEgo("Ugh! I can't budge it!");
    [0043] }
    [0043] stopObjectCode();                                                    // --
}

Unlock {
    [0044] printEgo("It's stuck.");                                             // Unlock
    [0050] stopObjectCode();                                                    // --
}




/** Garage Door **/
roomobj-16-112.dmp

Open.Pull {
    [0021] doSentence(1,111,0);                                                 // Open Garage Door
    [0025] stopObjectCode();                                                    // --
}

Unlock {
    [0026] doSentence(8,111,0);                                                 // Unlock Garage Door
    [002A] stopObjectCode();                                                    // --
}




/** Garage Door **/
roomobj-16-113.dmp

Open {
    [0021] doSentence(1,111,0);                                                 // Open Garage Door
    [0025] stopObjectCode();                                                    // --
}

Unlock {
    [0026] doSentence(8,111,0);                                                 // Unlock Garage Door
    [002A] stopObjectCode();                                                    // --
}




/** Garage Door **/
roomobj-16-114.dmp

Open.Pull {
    [0021] doSentence(1,111,0);                                                 // Open Garage Door
    [0025] stopObjectCode();                                                    // --
}

Unlock {
    [0026] doSentence(8,111,0);                                                 // Unlock Garage Door
    [002A] stopObjectCode();                                                    // --
}




/** Garage Door **/
roomobj-16-115.dmp

Open.Pull {
    [0021] doSentence(1,111,0);                                                 // Open Garage Door
    [0025] stopObjectCode();                                                    // --
}

Unlock {
    [0026] doSentence(8,111,0);                                                 // Unlock Garage Door
    [002A] stopObjectCode();                                                    // --
}




/** Garage Door **/
roomobj-16-116.dmp

Open.Pull {
    [0021] doSentence(1,111,0);                                                 // Open Garage Door
    [0025] stopObjectCode();                                                    // --
}

Unlock {
    [0026] doSentence(8,111,0);                                                 // Unlock Garage Door
    [002A] stopObjectCode();                                                    // --
}




/** Garage Door **/
roomobj-16-117.dmp

Open {
    [0023] if (getState08(116)) {                                               // If Door Open
    [0027]   doSentence(1,111,0);                                               //  Open Garage Door
    [002B] } else {                                                             // -
    [002E]   printEgo("It's already opened.");
    [0042] }
    [0042] stopObjectCode();                                                    // --
}

Close {
    [0043] if (!getState08(116)) {                                              // If Door is open
    [0047]   printEgo("It's too high to reach.");
    [005C] } else {                                                             // -
    [005F]   printEgo("It's already closed.");
    [0073] }
    [0073] stopObjectCode();                                                    // --
}

Pull {
    [0074] if (getState08(116)) {                                               // If door is closed
    [0078]   doSentence(1,111,0);                                               //  Open Garage Door
    [007C] } else {                                                             // -
    [007F]   printEgo("It's too high to reach.");
    [0094] }
    [0094] stopObjectCode();                                                    // --
}

Unlock {
    [0095] doSentence(8,111,0);                                                 // Unlock Garage Door
    [0099] stopObjectCode();                                                    // --
}




/** Trunk **/
roomobj-16-118.dmp

Open {
    [001F] if (!getState08(activeObject)) {                                     // If trunk locked
    [0022]   printEgo("The trunk is locked.");
    [0035] }
    [0035] stopObjectCode();                                                    // --
}

Close.Lock {
    [0036] clearState08();                                                      // Lock Trunk
    [0037] stopSound(68);
    [0039] startSound(9);                                                       // sound Door Closing
    [003B] stopObjectCode();                                                    // --
}

Unlock {
    [003C] if (!getState08(activeObject)) {                                     // If trunk locked
    [003F]   if (activeObject2 == 194) {                                        //  if use with Yellow Key
    [0043]     setState08();                                                    //  Unlock Trunk
    [0044]     startSound(8);                                                   //  sound Door Opening
    [0046]     if (Var[18] == 2) {                                              //  if Meteor Location == Edsel
    [004B]       startScript(123);                                              //   start Meteor: Fire Radiation
    [004D]     }
    [004D]   } else {                                                           // -
    [0050]     printEgo("It doesn't work.");
    [0060]   }
    [0060] }
    [0060] stopObjectCode();                                                    // --
}

Use {
    [0061] if (activeObject2 == 252) {                                          // if use with Meteor
    [0065]   stopScript(129);                                                   //  stop Radiation Suit: Enable Speaking Flag
    [0067]   animateActor(VAR_EGO,253,1);                                       //  Open Mouth of actor
    [006B]   setOwnerOf(252,0);                                                 //  Meteor owned by no-one
    [006E]   setState08(12);                                                    //  Meteor locked
    [0070]   clearState02(12);                                                  //  Meteor Hidden
    [0072]   Var[18] = 2;                                                       //  Meteor Location == Edsel
    [0075]   startSound(68);
    [0077] } else {                                                             // -
    [007A]   doSentence(8,118,255);                                             // Unlock Trunk
    [007E] }
    [007E] stopObjectCode();                                                    // --
}



/** Tools **/
roomobj-16-119.dmp

Pickup {
    [0019] pickupObject(0);                                                     // Pick object
    [001B] stopObjectCode();                                                    // --
}

Use {
    [001C] if (activeObject2 == 103) {                                          // Use with Phone
    [0020]   doSentence(6,103,119);                                             // Fix Phone with Tools
    [0024] } else {                                                             // -
    [0027]   doSentence(11,255,254);                                            // Use _cmdObject2 with _cmdObject
    [002B] }
    [002B] stopObjectCode();                                                    // --
}



/** Meteor **/
roomobj-16-12.dmp

Pickup {
    [0018] printEgo("No way!");                                                 // Pick-up Meteor
    [0020] stopObjectCode();                                                    // --
}



/** Water Faucet **/
roomobj-16-120.dmp

Pickup {
    [0027] pickupObject(0);                                                     // Pick object
    [0029] stopObjectCode();                                                    // --
}

Use {
    [002A] doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    [002E] stopObjectCode();                                                    // --
}



/** < Not Named > **/
roomobj-16-153.dmp



/** Cement Slab **/
roomobj-16-26.dmp

Open.Pull {
    [0023] printEgo("It won't budge.");                                         // Open
    [0032] stopObjectCode();                                                    // --
}

Close {
    [0033] if (!getState08(activeObject)) {                                     // If Cement Slab closed
    [0036]   printEgo("It's already closed.");
    [004A] } else {                                                             // -
    [004D]   printEgo("I can't.");
    [0056] }
    [0056] stopObjectCode();                                                    // --
}

WalkTo {
    [0057] if (getState08(activeObject)) {                                      // If Cement Slab opened
    [005A]   loadRoomWithEgo(144,51);                                           //  Enter Lab: Meteor
    [005D] }
    [005D] stopObjectCode();                                                    // --
}




/** License Plate **/
roomobj-16-268.dmp

Read {
    [001F] printEgo("THX 1138");                                                // Read
    [0028] stopObjectCode();                                                    // --
}




/** Weird Edsel **/
roomobj-16-330.dmp

Use {
    [001D] if (activeObject2 == 194) {                                          // use with Yellow Key
    [0021]   if (getState08(118)) {                                             // If trunk is open
    [0025]     printEgo("I'd better close the trunk first.");                   //
    [0043]     doSentence(11,74,194);                                           //  Use Weird Edsel with Yellow Key
    [0047]     doSentence(2,118,0);                                             //  Close Trunk
    [004B]   } else {                                                           // -
    [004E]     if (getState08(12)) {                                            // If Meteor Locked
    [0052]       stopScript(118);                                               //  stop Nuclear Meltdown Countdown
    [0054]     }
    [0054]     startScript(125);                                                // start Edsel: Active Rocket Engine
    [0056]   }
    [0056] } else {                                                             // -
    [0059]   printEgo("I can't start it with that.");
    [0071] }
    [0071] stopObjectCode();                                                    // --
}




/** Modified Rocket Engine **/
roomobj-16-331.dmp

Use {
    [0028] doSentence(11,74,255);                                               // Use Weird Edsel with _cmdObject2
    [002C] stopObjectCode();                                                    // --
}




/** Modified Rocket Engine **/
roomobj-16-332.dmp

Use {
    [0028] doSentence(11,74,255);                                               // Use Weird Edsel with _cmdObject2
    [002C] stopObjectCode();                                                    // --
}




/** Sign **/
roomobj-16-333.dmp

Read {
    [0016] printEgo("Tentacle on board!");                                      // Read
    [0028] stopObjectCode();                                                    // --
}




/** Bumper Sticker **/
roomobj-16-334.dmp

Read {
    [0020] printEgo("I heart Weird Ed.");                                       // Read
    [0030] stopObjectCode();                                                    // --
}




/** Shelf **/
roomobj-16-335.dmp




/**
 * Room 17: Music
 */


/** Door **/
roomobj-17-152.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(148);                                                     // Open Door (Top of Main Entry)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(148);                                                   // Close Door (Top of Main Entry)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // If door open
    [0027]   loadRoomWithEgo(148,11);                                           //  Enter Top of Main Entry
    [002A] }
    [002A] stopObjectCode();                                                    // --
}



/** Vase **/
roomobj-17-154.dmp

Pickup {
    [0016] if (!getState08(activeObject)) {                                     // If not broken
    [0019]   printEgo("I'd better not%/%it's obviously a valuable antique!");
    [0048] } else {                                                             // -
    [004B]   printEgo("Ouch!");                                                 //
    [0052] }
    [0052] stopObjectCode();                                                    // --
}



/** Old Record **/
roomobj-17-155.dmp

Pickup {
    [001E] pickupObject(0);                                                     // Pick object
    [0020] stopObjectCode();                                                    // --
}

Use {
    [0021] doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    [0025] stopObjectCode();                                                    // --
}



/** TV **/
roomobj-17-157.dmp

TurnOn.Use {
    [0018] if (!getState08(124)) {                                              // Is Power On
    [001C]   if (!getState08(activeObject)) {                                   //  Is Tv Off
    [001F]     setState08();                                                    //   TV On
    [0020]     startScript(107);                                                //   3 Guys who Pub Anything: TV Commercial
    [0022]   }
    [0022] } else {                                                             // -
    [0025]   printEgo("The power is off.");
    [0035] }
    [0035] stopObjectCode();                                                    // --
}

TurnOff {
    [0036] if (getState08(activeObject)) {                                      // Is Tv On
    [0039]   clearState08();                                                    //  Tv Off
    [003A] }
    [003A] stopObjectCode();                                                    // --
}



/** Cassette Recorder **/
roomobj-17-158.dmp

TurnOn {
    [0027] if (!getState08(159)) {                                              // Is Recorder off
    [002B]   if (!getState08(124)) {                                            //  Is Power On
    [002F]     setState08();                                                    //   Recorder On
    [0030]     printEgo("Ok, it's recording.");
    [0043]     if (Var[23] == 1) {                                              //   if Victrola Playing
    [0048]       Var[13] = Var[75];                                             //    Tape Contents = Record on Victrola
    [004B]     }
    [004B]   }
    [004B] } else {                                                             // -
    [004E]   printEgo("There's no tape in the recorder.");
    [006B] }
    [006B] stopObjectCode();                                                    // --
}

TurnOff {
    [006C] if (getState08(activeObject)) {                                      // If Recording
    [006F]   printEgo("It stopped recording.");
    [0084]   clearState08(158);                                                 //  Stop Recording
    [0086] }
    [0086] stopObjectCode();                                                    // --
}

Use {
    [0087] if (activeObject2 == 156) {                                          // if use with Cassette Tape
    [008B]   if (Var[13] == 52) {                                               //  if Tape Contents == 52 = Green Tentacle
    [0090]     printEgo("I can't record on this tape.");
    [00A9]   } else {                                                           // -
    [00AC]     clearState08(159);                                               // Stop Recorder
    [00AE]     clearState02(159);                                               // Stop Recorder
    [00B0]     setOwnerOf(156,14);                                              // Set owner of tape to Green Tentacle
    [00B3]   }
    [00B3] }
    [00B3] stopObjectCode();                                                    // --
}



/** Cassette Tape **/
roomobj-17-159.dmp

Pickup {
    [0023] if (getState08(158)) {                                               // if Recorder On
    [0027]   printEgo("It's still recording!");
    [003C] } else {                                                             // -
    [003F]   setOwnerOf(156,VAR_EGO);                                           // Take Cassette Tape
    [0042]   setState08();                                                      // Tape locked
    [0043]   setState02();                                                      // Tape Locked
    [0044] }
    [0044] stopObjectCode();                                                    // --
}

TurnOn {
    [0045] if (!getState08(activeObject)) {                                     // If Tape unlocked
    [0048]   doSentence(4,158,0);                                               //  Turn on Recorder
    [004C] }
    [004C] stopObjectCode();                                                    // --
}

TurnOff {
    [004D] if (!getState08(activeObject)) {                                     // If Tape unlocked
    [0050]   doSentence(5,158,0);                                               // Turn off Recorder
    [0054] }
    [0054] stopObjectCode();                                                    // --
}




/** Record on Victrola **/
roomobj-17-231.dmp

Pickup {
    [001C] if (Var[23] == 1) {                                                  // if Victrola On
    [0021]   printEgo("It's still playing!");
    [0034] } else {                                                             // -
    [0037]   setState08(231);                                                   // Victrola On
    [0039]   setState02(231);                                                   // Victrola On
    [003B]   if (Var[75] == 25) {                                               // If Record on Victrola
    [0040]     setOwnerOf(235,VAR_EGO);                                         //  Kid owns record
    [0043]   } else {                                                           // -
    [0046]     setOwnerOf(155,VAR_EGO);                                         //  Kid owns Old Record
    [0049]   }
    [0049] }
    [0049] stopObjectCode();                                                    // --
}

TurnOn {
    [004A] if (!getState08(activeObject)) {                                     // If Victrola Off
    [004D]   doSentence(4,102,0);                                               //  Turn On Victrola
    [0051] }
    [0051] stopObjectCode();                                                    // --
}

TurnOff {
    [0052] if (!getState08(activeObject)) {                                     // If Victrola Off
    [0055]   doSentence(5,102,0);                                               //  Turn Off Victrola
    [0059] }
    [0059] stopObjectCode();                                                    // --
}



/** Piano Bench **/
roomobj-17-356.dmp



/** Piano **/
roomobj-17-357.dmp

Use {
    [0017] if (VAR_EGO <= 2) {                                                  // if Syd Or Razor
    [001C]   startScript(95);                                                   //  start Play Piano
    [001E] } else {                                                             // -
    [0021]   printEgo("I can't play that thing!");
    [0037] }
    [0037] stopObjectCode();                                                    // --
}



/** Victrola **/
roomobj-17-358.dmp

TurnOn {
    [001E] if (!getState08(231)) {                                              // if Record On Victrola
    [0022]   if (Var[23] == 0) {                                                //  If Victrola Not Playing
    [0027]     Var[23] = 1;                                                     //   Victrola Playing
    [002A]     if (getState08(158)) {                                           //   State of Casette Recorder
    [002E]       Var[13] = Var[75];                                             //    Tape Contents = Record on Victrola
    [0031]     }
    [0031]     if (Var[75] == 25) {                                             // If Record on Victrola is Tentacle Mating Call
    [0036]       startScript(14);                                               //  start Record: Tentacle Mating Call
    [0038]     } else {                                                         // -
    [003B]       startSound(44);                                                // sound
    [003D]     }
    [003D]   }
    [003D] } else {                                                             // -
    [0040]   printEgo("There's no record on the Victrola.");
    [005F] }
    [005F] stopObjectCode();                                                    // --
}

TurnOff {
    [0060] Var[23] = 0;                                                         // Victrola = Off
    [0063] stopSound(25);
    [0065] stopSound(44);
    [0067] stopScript(14);                                                      // start Record: Tentacle Mating Call
    [0069] stopObjectCode();                                                    // --
}

Use {
    [006A] if (!getState08(231)) {                                              // If Record On Victrola
    [006E]   printEgo("There's already a record here.");
    [008A] } else {                                                             // -
    [008D]   if (activeObject2 == 235) {                                        // use with Record
    [0091]     clearState08(231);                                               //  Lock Record
    [0093]     clearState02(231);                                               //  Lock Record
    [0095]     setOwnerOf(235,14);                                              //  Green Tentacle owns record
    [0098]     Var[75] = 25;                                                    //  Record on Victrola = Tentacle Mating Call
    [009B]   }
    [009B]   if (activeObject2 == 155) {                                        // use with Old Record
    [009F]     clearState08(231);                                               //  Lock Record
    [00A1]     clearState02(231);                                               //  Lock Record
    [00A3]     setOwnerOf(155,14);                                              //  Green Tentacle owns Record
    [00A6]     Var[75] = 44;                                                    //  Record on Victrola = Melody Stinks
    [00A9]   }
    [00A9] }
    [00A9] stopObjectCode();                                                    // --
}




/** Speaker **/
roomobj-17-359.dmp



/**
 * Room 18: Video Game
 */


/** Door **/
roomobj-18-168.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(163);                                                     // Open Door (Level 2 Main Hallway)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(163);                                                   // Close Door (Level 2 Main Hallway)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // if Door Open
    [0027]   loadRoomWithEgo(163,13);                                           // Enter Level 2 Main Hallway
    [002A] }
    [002A] stopObjectCode();                                                    // --
}




/** Video Fever **/
roomobj-18-169.dmp

Use {
    [0026] if (activeObject2 == 200) {                                          // if use with Quarter
    [002A]   doSentence(11,175,200);                                            //  Use Game with Quater                                    //  Use Game with Quater
    [002E] }
    [002E] stopObjectCode();                                                    // --
}

TurnOn {
    [002F] startScript(19);                                                     // start Power Off??
    [0031] stopObjectCode();                                                    // --
}

TurnOff {
    [0032] startScript(20);                                                     // start It Looks off / cant find a switch
    [0034] stopObjectCode();                                                    // --
}




/** Disco Crazy **/
roomobj-18-170.dmp

Use {
    [0026] if (activeObject2 == 200) {                                          // if use with Quarter
    [002A]   doSentence(11,176,200);                                            //  Use Game with Quater                                    //  Use Game with Quater
    [002E] }
    [002E] stopObjectCode();                                                    // --
}

TurnOn {
    [002F] startScript(19);                                                     // start Power Off??
    [0031] stopObjectCode();                                                    // --
}

TurnOff {
    [0032] startScript(20);                                                     // start It Looks off / cant find a switch
    [0034] stopObjectCode();                                                    // --
}



/** Alien Slime **/
roomobj-18-171.dmp

Use {
    [0026] if (activeObject2 == 200) {                                          // if use with Quarter
    [002A]   doSentence(11,177,200);                                            //  Use Game with Quater                                    //  Use Game with Quater
    [002E] }
    [002E] stopObjectCode();                                                    // --
}

TurnOn {
    [002F] startScript(19);                                                     // start Power Off??
    [0031] stopObjectCode();                                                    // --
}

TurnOff {
    [0032] startScript(20);                                                     // start It Looks off / cant find a switch
    [0034] stopObjectCode();                                                    // --
}



/** Die Enemy Die **/
roomobj-18-172.dmp

Use {
    [0028] if (activeObject2 == 200) {                                          // if use with Quarter
    [002C]   doSentence(11,178,200);                                            //  Use Game with Quater
    [0030] }
    [0030] stopObjectCode();                                                    // --
}

TurnOn {
    [0031] startScript(19);                                                     // start Power Off??
    [0033] stopObjectCode();                                                    // --
}

TurnOff {
    [0034] startScript(20);                                                     // start It Looks off / cant find a switch
    [0036] stopObjectCode();                                                    // --
}




/** Meteor Mess **/
roomobj-18-173.dmp

Use {
    [0026] if (activeObject2 == 200) {                                          // if use with Quarter
    [002A]   doSentence(11,179,200);                                            //  Use Game with Quater
    [002E] }
    [002E] stopObjectCode();                                                    // --
}

TurnOn {
    [002F] startScript(19);                                                     // start Power Off??
    [0031] stopObjectCode();                                                    // --
}

TurnOff {
    [0032] startScript(20);                                                     // start It Looks off / cant find a switch
    [0034] stopObjectCode();                                                    // --
}




/** Kil Thrill **/
roomobj-18-174.dmp

Use {
    [0026] if (activeObject2 == 200) {                                          // if use with Quarter
    [002A]   doSentence(11,180,200);                                            //  Use Game with Quater
    [002E] }
    [002E] stopObjectCode();                                                    // --
}

TurnOn {
    [002F] startScript(19);                                                     // start Power Off??
    [0031] stopObjectCode();                                                    // --
}

TurnOff {
    [0032] startScript(20);                                                     // start It Looks off / cant find a switch
    [0034] stopObjectCode();                                                    // --
}



/** Coin Box **/
roomobj-18-215.dmp

Pickup {
    [0024] if (!getState08(221)) {                                              // If Quarter in coinbox
    [0028]   doSentence(14,221,0);                                              //  Pickup Quater
    [002C] } else {                                                             // -
    [002F]   startScript(20);                                                   // start It Looks off / cant find a switch
    [0031] }
    [0031] stopObjectCode();                                                    // --
}

Use {
    [0032] if (activeObject2 == 200) {                                          // if use with Quarter
    [0036]   doSentence(11,175,200);                                            //  Use Game with Quater
    [003A] }
    [003A] if (activeObject2 == 74) {                                           // Use with small key
    [003E]   doSentence(8,215,74);                                              //  unlock coinbox with small key                                       // unlock coinbox with small key                                        //
    [0042] }
    [0042] stopObjectCode();                                                    // --
}

Open {
    [0043] if (!getState08(activeObject)) {                                     // if game is locked
    [0046]   startScript(60);                                                   //  Print "The machine is locked"
    [0048] }
    [0048] stopObjectCode();                                                    // --
}

Close.Lock {
    [0049] if (getState08(activeObject)) {                                      // if game is unlocked
    [004C]   clearState08();                                                    //  Lock Game
    [004D]   setState04();                                                      //  Lock Game
    [004E] }
    [004E] stopObjectCode();                                                    // --
}

Unlock {
    [004F] if (activeObject2 == 74) {                                           // if use with small key
    [0053]   clearState04();                                                    //  Lock Game
    [0054]   setState08();                                                      //  Lock Gmae
    [0055] } else {                                                             // -
    [0058]   startScript(61);                                                   //  start Print "It must require a special key"
    [005A] }
    [005A] stopObjectCode();                                                    // --
}




/** Coin Box **/
roomobj-18-216.dmp

Pickup {
    [0024] if (!getState08(222)) {                                              // If Quarter in coinbox
    [0028]   doSentence(14,222,0);                                              //  Pickup Quater
    [002C] } else {                                                             // -
    [002F]   startScript(20);                                                   // start It Looks off / cant find a switch
    [0031] }
    [0031] stopObjectCode();                                                    // --
}

Use {
    [0032] if (activeObject2 == 200) {                                          // if use with Quarter
    [0036]   doSentence(11,176,200);                                            //  Use Game with Quater
    [003A] }
    [003A] if (activeObject2 == 74) {                                           // Use with small key
    [003E]   doSentence(8,216,74);                                              //  unlock coinbox with small key
    [0042] }
    [0042] stopObjectCode();                                                    // --
}

Open {
    [0043] if (!getState08(activeObject)) {                                     // if game is locked
    [0046]   startScript(60);                                                   //  Print "The machine is locked"
    [0048] }
    [0048] stopObjectCode();                                                    // --
}

Close {
    [0049] if (getState08(activeObject)) {                                      // if game is unlocked
    [004C]   clearState08();                                                    //  Lock Game
    [004D]   setState04();                                                      //  Lock Game
    [004E] }
    [004E] stopObjectCode();                                                    // --
}

Unlock {
    [004F] if (activeObject2 == 74) {                                           // if use with small key
    [0053]   clearState04();                                                    //  Lock Game
    [0054]   setState08();                                                      //  Lock Gmae
    [0055] } else {                                                             // -
    [0058]   startScript(61);                                                   //  start Print "It must require a special key"
    [005A] }
    [005A] stopObjectCode();                                                    // --
}



/** Coin Box **/
roomobj-18-217.dmp

Pickup {
    [0024] if (!getState08(223)) {                                              // If Quarter in coinbox
    [0028]   doSentence(14,223,0);                                              //  Pickup Quater
    [002C] } else {                                                             // -
    [002F]   startScript(20);                                                   // start It Looks off / cant find a switch
    [0031] }
    [0031] stopObjectCode();                                                    // --
}

Use {
    [0032] if (activeObject2 == 200) {                                          // if use with Quarter
    [0036]   doSentence(11,177,200);                                            //  Use Game with Quater
    [003A] }
    [003A] if (activeObject2 == 74) {                                           // Use with small key
    [003E]   doSentence(8,217,74);                                              //  unlock coinbox with small key
    [0042] }
    [0042] stopObjectCode();                                                    // --
}

Open {
    [0043] if (!getState08(activeObject)) {                                     // if game is locked
    [0046]   startScript(60);                                                   //  Print "The machine is locked"
    [0048] }
    [0048] stopObjectCode();                                                    // --
}

Close.Lock {
    [0049] if (getState08(activeObject)) {                                      // if game is unlocked
    [004C]   clearState08();                                                    //  Lock Game
    [004D]   setState04();                                                      //  Lock Game
    [004E] }
    [004E] stopObjectCode();                                                    // --
}
Unlock {
    [004F] if (activeObject2 == 74) {                                           // if use with small key
    [0053]   clearState04();                                                    //  Lock Game
    [0054]   setState08();                                                      //  Lock Gmae
    [0055] } else {                                                             // -
    [0058]   startScript(61);                                                   //  start Print "It must require a special key"
    [005A] }
    [005A] stopObjectCode();                                                    // --
}




/** Coin Box **/
roomobj-18-218.dmp

Pickup {
    [0024] if (!getState08(224)) {                                              // If Quarter in coinbox
    [0028]   doSentence(14,224,0);                                              //  Pickup Quater
    [002C] } else {                                                             // -
    [002F]   startScript(20);                                                   // start It Looks off / cant find a switch
    [0031] }
    [0031] stopObjectCode();                                                    // --
}

Use {
    [0032] if (activeObject2 == 200) {                                          // if use with Quarter
    [0036]   doSentence(11,178,200);                                            //  Use Game with Quater
    [003A] }
    [003A] if (activeObject2 == 74) {                                           // Use with small key
    [003E]   doSentence(8,218,74);                                              //  unlock coinbox with small key
    [0042] }
    [0042] stopObjectCode();                                                    // --
}

Open {
    [0043] if (!getState08(activeObject)) {                                     // if game is locked
    [0046]   startScript(60);                                                   //  Print "The machine is locked"
    [0048] }
    [0048] stopObjectCode();                                                    // --
}

Close {
    [0049] if (getState08(activeObject)) {                                      // if game is unlocked
    [004C]   clearState08();                                                    //  Lock Game
    [004D]   setState04();                                                      //  Lock Game
    [004E] }
    [004E] stopObjectCode();                                                    // --
}

Unlock {
    [004F] if (activeObject2 == 74) {                                           // if use with small key
    [0053]   clearState04();                                                    //  Lock Game
    [0054]   setState08();                                                      //  Lock Gmae
    [0055] } else {                                                             // -
    [0058]   startScript(61);                                                   //  start Print "It must require a special key"
    [005A] }
    [005A] stopObjectCode();                                                    // --
}



/** Coin Box **/
roomobj-18-219.dmp

Pickup {
    [0024] if (!getState08(225)) {                                              //   // If Quarter in coinbox
    [0028]   doSentence(14,225,0);                                              // Pickup Quater
    [002C] } else {                                                             //
    [002F]   startScript(20);                                                   //  start It Looks off / cant find a switch
    [0031] }                                                                    //
    [0031] stopObjectCode();                                                    //  --
}

Use {
    [0032] if (activeObject2 == 200) {                                          //  if use with Quarter
    [0036]   doSentence(11,179,200);                                            //   Use Game with Quater
    [003A] }                                                                    //
    [003A] if (activeObject2 == 74) {                                           //  Use with small key
    [003E]   doSentence(8,219,74);                                              //   unlock coinbox with small key
    [0042] }                                                                    //
    [0042] stopObjectCode();                                                    //  --
}

Open {
    [0043] if (!getState08(activeObject)) {                                     //  if game is locked
    [0046]   startScript(60);                                                   //   Print "The machine is locked"
    [0048] }                                                                    //
    [0048] stopObjectCode();                                                    //  --
}

Close {
    [0049] if (getState08(activeObject)) {                                      //  if game is unlocked
    [004C]   clearState08();                                                    //   Lock Game
    [004D]   setState04();                                                      //   Lock Game
    [004E] }                                                                    //
    [004E] stopObjectCode();                                                    //  --
}

Unlock {
    [004F] if (activeObject2 == 74) {                                           //  if use with small key
    [0053]   clearState04();                                                    //   Lock Game
    [0054]   setState08();                                                      //   Lock Gmae
    [0055] } else {                                                             //  -
    [0058]   startScript(61);                                                   //   start Print "It must require a special key"
    [005A] }                                                                    //
    [005A] stopObjectCode();                                                    //    --
}



/** Coin Box **/
roomobj-18-220.dmp

Pickup {
    [0024] if (!getState08(226)) {                                              // If Quarter in coinbox
    [0028]   doSentence(14,226,0);                                              //  Pickup Quater
    [002C] } else {                                                             // -
    [002F]   startScript(20);                                                   // start It Looks off / cant find a switch
    [0031] }
    [0031] stopObjectCode();                                                    // --
}

Use {
    [0032] if (activeObject2 == 200) {                                          // if use with Quarter
    [0036]   doSentence(11,180,200);                                            //  Use Game with Quater
    [003A] }
    [003A] if (activeObject2 == 74) {                                           // Use with small key
    [003E]   doSentence(8,220,74);                                              //  unlock coinbox with small key
    [0042] }
    [0042] stopObjectCode();                                                    // --
}

Open {
    [0043] if (!getState08(activeObject)) {                                     // if game is locked
    [0046]   startScript(60);                                                   //  Print "The machine is locked"
    [0048] }
    [0048] stopObjectCode();                                                    // --
}

Close {
    [0049] if (getState08(activeObject)) {                                      // if game is unlocked
    [004C]   clearState08();                                                    //  Lock Game
    [004D]   setState04();                                                      //  Lock Game
    [004E] }
    [004E] stopObjectCode();                                                    // --
}

Unlock {
    [004F] if (activeObject2 == 74) {                                           // if use with small key
    [0053]   clearState04();                                                    //  Lock Game
    [0054]   setState08();                                                      //  Lock Gmae
    [0055] } else {                                                             // -
    [0058]   startScript(61);                                                   //  start Print "It must require a special key"
    [005A] }
    [005A] stopObjectCode();                                                    // --
}




/** Quater **/
roomobj-18-221.dmp

Pickup {
    [0019] setOwnerOf(200,VAR_EGO);                                             // Kid owns Quarter
    [001C] setState02(221);                                                     // Coin Locked
    [001E] setState08(221);                                                     // Coin Locked
    [0020] stopObjectCode();                                                    // --
}



/** Quater **/
roomobj-18-222.dmp

Pickup {
    [0019] setOwnerOf(200,VAR_EGO);                                             // Kid owns Quarter
    [001C] setState02(222);                                                     // Coin Locked
    [001E] setState08(222);                                                     // Coin Locked
    [0020] stopObjectCode();                                                    // --
}




/** Quater **/
roomobj-18-223.dmp

Pickup {
    [0019] setOwnerOf(200,VAR_EGO);                                             // Kid owns Quarter
    [001C] setState02(223);                                                     // Coin Locked
    [001E] setState08(223);                                                     // Coin Locked
    [0020] stopObjectCode();                                                    // --
}



/** Quater **/
roomobj-18-224.dmp

Pickup {
    [0019] setOwnerOf(200,VAR_EGO);                                             // Kid owns Quarter
    [001C] setState02(224);                                                     // Coin Locked
    [001E] setState08(224);                                                     // Coin Locked
    [0020] stopObjectCode();                                                    // --
}




/** Quater **/
roomobj-18-225.dmp

Pickup {
    [0019] setOwnerOf(200,VAR_EGO);                                             // Kid owns Quarter
    [001C] setState02(225);                                                     // Coin Locked
    [001E] setState08(225);                                                     // Coin Locked
    [0020] stopObjectCode();                                                    // --
}




/** Quater **/
roomobj-18-226.dmp

Pickup {
    [0019] setOwnerOf(200,VAR_EGO);                                             // Kid owns Quarter
    [001C] setState02(226);                                                     // Coin Locked
    [001E] setState08(226);                                                     // Coin Locked
    [0020] stopObjectCode();                                                    // --
}




/** Air Hockey Table **/
roomobj-18-367.dmp

Use {
    [0022] printEgo("This game is broken.");                                    // use
    [0035] stopObjectCode();                                                    // --
}




/** Star Wars Poster **/
roomobj-18-368.dmp

Read {
    [0022] printEgo("A Lucasfilm Ltd. Production.");                            // Read
    [003D] stopObjectCode();                                                    // --
}



/** Video Fever **/
roomobj-18-431.dmp

Use {
    [0026] if (activeObject2 == 200) {                                          // if use with Quarter
    [002A]   if (getState08(204)) {                                             //  if Wires Fixed
    [002E]     setState08(169);                                                 //   Video Game On
    [0030]     clearState02(221);                                               //   Quater Gone
    [0032]     clearState08(221);                                               //    Quater Gone
    [0034]     startScript(22);                                                 //    start Video Game: Die Enemy Die
    [0036]   } else {                                                           // -
    [0039]     startScript(59);                                                 //  Print "It seems to be turned off"
    [003B]   }
    [003B] }
    [003B] stopObjectCode();                                                    // --
}

TurnOn {
    [003C] startScript(19);                                                     // start Power Off??
    [003E] stopObjectCode();                                                    // --
}

TurnOff {
    [003F] startScript(20);                                                     // start It Looks off / cant find a switch
    [0041] stopObjectCode();                                                    // --
}




/** Disco Crazy **/
roomobj-18-432.dmp
Events:
TurnOn - 003C
TurnOff- 003F
   Use - 0026

Use {
    [0026] if (activeObject2 == 200) {                                          // if use with Quarter
    [002A]   if (getState08(204)) {                                             //  if Wires Fixed
    [002E]     setState08(170);                                                 //   Video Game On
    [0030]     clearState02(222);                                               //   Quater Gone
    [0032]     clearState08(222);                                               //    Quater Gone
    [0034]     startScript(22);                                                 //    start Video Game: Die Enemy Die
    [0036]   } else {                                                           // -
    [0039]     startScript(59);                                                 //  Print "It seems to be turned off"
    [003B]   }
    [003B] }
    [003B] stopObjectCode();                                                    // --
}

TurnOn {
    [003C] startScript(19);                                                     // start Power Off??
    [003E] stopObjectCode();                                                    // --
}

TurnOff {
    [003F] startScript(20);                                                     // start It Looks off / cant find a switch
    [0041] stopObjectCode();                                                    // --
}




/** Alien Slime **/
roomobj-18-433.dmp

Use {
    [0026] if (activeObject2 == 200) {                                          // if use with Quarter
    [002A]   if (getState08(204)) {                                             //  if Wires Fixed
    [002E]     setState08(171);                                                 //   Video Game On
    [0030]     clearState02(223);                                               //   Quater Gone
    [0032]     clearState08(223);                                               //    Quater Gone
    [0034]     startScript(22);                                                 //    start Video Game: Die Enemy Die
    [0036]   } else {                                                           // -
    [0039]     startScript(59);                                                 //  Print "It seems to be turned off"
    [003B]   }
    [003B] }
    [003B] stopObjectCode();                                                    // --
}

TurnOn {
    [003C] startScript(19);                                                     // start Power Off??
    [003E] stopObjectCode();                                                    // --
}

TurnOff {
    [003F] startScript(20);                                                     // start It Looks off / cant find a switch
    [0041] stopObjectCode();                                                    // --
}




/** Die Enemy Die **/
roomobj-18-434.dmp

Use {
    [0028] if (activeObject2 == 200) {                                          // if use with Quarter
    [002C]   if (getState08(204)) {                                             //  if Wires Fixed
    [0030]     setState08(172);                                                 //   Video Game On
    [0032]     clearState02(224);                                               //   Quater Gone
    [0034]     clearState08(224);                                               //    Quater Gone
    [0036]     startScript(22);                                                 //    start Video Game: Die Enemy Die
    [0038]   } else {                                                           // -
    [003B]     startScript(59);                                                 //  Print "It seems to be turned off"
    [003D]   }
    [003D] }
    [003D] stopObjectCode();                                                    // --
}

TurnOn {
    [003E] startScript(19);                                                     // start Power Off??
    [0040] stopObjectCode();                                                    // --
}

TurnOff {
    [0041] startScript(20);                                                     // start It Looks off / cant find a switch
    [0043] stopObjectCode();                                                    // --
}




/** Meteor Mess **/
roomobj-18-435.dmp

Use {
    [0026] if (activeObject2 == 200) {                                          // if use with Quarter
    [002A]   if (getState08(204)) {                                             //  if Wires Fixed
    [002E]     setState08(173);                                                 //   Video Game On
    [0030]     clearState02(225);                                               //   Quater Gone
    [0032]     clearState08(225);                                               //    Quater Gone
    [0034]     setOwnerOf(200,14);                                              //    start Video Game: Die Enemy Die
    [0037]     startSound(11);                                                  // Sound CoinSlot                                         // -
    [0039]     startScript(21);                                                 //  Print "It seems to be turned off"
    [003B]   } else {
    [003E]     startScript(59);
    [0040]   }                                                                  // --
    [0040] }                                                                    // start Power Off??
    [0040] stopObjectCode();                                                    // --
}

TurnOn {
    [0041] startScript(19);                                                     // start It Looks off / cant find a switch
    [0043] stopObjectCode();                                                    // --
}

TurnOff {
    [0044] startScript(20);
    [0046] stopObjectCode();
}



/** Kill Thrill **/
roomobj-18-436.dmp

Use {
    [0026] if (activeObject2 == 200) {                                          // if use with Quarter
    [002A]   if (getState08(204)) {                                             //  if Wires Fixed
    [002E]     setState08(174);                                                 //   Video Game On
    [0030]     clearState02(226);                                               //   Quater Gone
    [0032]     clearState08(226);                                               //    Quater Gone
    [0034]     startScript(22);                                                 //    start Video Game: Die Enemy Die
    [0036]   } else {                                                           // -
    [0039]     startScript(59);                                                 //  Print "It seems to be turned off"
    [003B]   }
    [003B] }
    [003B] stopObjectCode();                                                    // --
}

TurnOn {
    [003C] startScript(19);                                                     // start Power Off??
    [003E] stopObjectCode();                                                    // --
}

TurnOff {
    [003F] startScript(20);                                                     // start It Looks off / cant find a switch
    [0041] stopObjectCode();                                                    // --
}




/**
 * Room 19: Nurse Edna's
 */


/** Door **/
roomobj-19-210.dmp

WalkTo {
    [0018] setState08(196);                                                     // Open Hatch
    [001A] loadRoomWithEgo(196,9);                                              // Enter Attic (Above Nurse Edna's Room)
    [001D] stopObjectCode();                                                    // --
}




/** Desk **/
roomobj-19-294.dmp



/** Cracked Mirro **/
roomobj-19-295.dmp



/** Mirror **/
roomobj-19-296.dmp



/** Light **/
roomobj-19-297.dmp

TurnOn {
    [0019] startSound(12);                                                      // sound Light Switch
    [001B] setBitVar(VAR_ROOM,1,0);                                             // Light On
    [001F] startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    [0021] stopObjectCode();                                                    // --
}

TurnOff {
    [0022] startSound(12);                                                      // sound Light Switch
    [0024] setBitVar(VAR_ROOM,1,1);                                             // Light Off
    [0028] startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    [002A] stopObjectCode();                                                    // --
}



/** Bed **/
roomobj-19-298.dmp

Use {
    [0015] printEgo("No way!!!");
    [001F] stopObjectCode();                                                    // --
}




/** Picture of Dr. Fred **/
roomobj-19-299.dmp

Open.Pull {
    [0027] startScript(62);                                                     // start Print "Its firmly attached to the wall"
    [0029] stopObjectCode();                                                    // --
}




/** Plant **/
roomobj-19-301.dmp



/** Plant **/
roomobj-19-302.dmp



/** Perfume **/
roomobj-19-437.dmp



/** Pillow **/
roomobj-19-438.dmp



/** Door **/
roomobj-19-70.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(185);                                                     // Open Door (Door: Nurse Edna)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(185);                                                   // Close Door (Door: Nurse Edna)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {
    [0027]   loadRoomWithEgo(185,38);                                           // Enter Level 3 Hallway
    [002A]   cursorCommand( kModeNormal )                                       // Cutscene Mode Normal
    [002C] }
    [002C] stopObjectCode();                                                    // --
}



/** Phone **/
roomobj-19-72.dmp



/** Small Key **/
roomobj-19-74.dmp

Pickup {
    [001D] pickupObject(0);                                                     // Pick object
    [001F] stopObjectCode();                                                    // --
}

Use {
    [0020] doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    [0024] stopObjectCode();                                                    // --
}




/**
 * Room 20: Green Tentacle's
 */


/** Mondo Stereo **/
roomobj-20-131.dmp

TurnOn {
    [0022] if (!getState08(124)) {                                              // if Power On
    [0026]   setState08(131);                                                   //  Mondo Stereo = On
    [0028]   if (!getState08(195)) {                                            //   Cassette Tape not playing
    [002C]     startScript(104);                                                //    start Tape Player: Play Tape
    [002E]   } else {                                                           // -
    [0031]     startSound(20);                                                  //
    [0033]   }
    [0033] }
    [0033] stopObjectCode();                                                    // --
}

TurnOff {
    [0034] if (getState08(131)) {                                               // If stereo on
    [0038]   clearState08(131);                                                 //  Stereo turn off
    [003A]   stopSound(25);                                                     //
    [003C]   stopSound(20);                                                     //
    [003E]   stopSound(44);                                                     //
    [0040]   stopMusic();                                                       // Stop Music
    [0041] }
    [0041] stopObjectCode();                                                    // --
}

TurnOn {
    [0042] if (activeObject2 == 156) {                                          // if Cassette Tape
    [0046]   clearState08(195);                                                 //  Free Tape
    [0048]   clearState02(195);                                                 //  Free Tape
    [004A]   setOwnerOf(156,14);                                                //  Tape owned by Green Tentac;e
    [004D]   stopSound(20);
    [004F]   if (getState08(131)) {
    [0053]     doSentence(4,131,0);                                             // Turn On Mondo Stereo
    [0057]   }
    [0057] }
    [0057] if (activeObject2 == 155) {                                          // use with Old Record
    [005B] } else {                                                             // -
    [005E]   unless (activeObject2 == 235) goto 0076;                           // or Record
    [0062] }
    [0062] printEgo("Hey, it's a CD player!");
    [0076] stopObjectCode();                                                    // --
}




/** Hatch **/
roomobj-20-192.dmp

Open.Pickup {
    [001F] startScript(4);                                                      // start Door: Open
    [0021] stopObjectCode();                                                    // --
}

Close {
    [0022] startScript(5);                                                      // start Door: Close
    [0024] stopObjectCode();                                                    // --
}

Pull {
    [0025] if (getState08(activeObject)) {
    [0028]   startScript(5);                                                    // start Door: Close
    [002A] } else {                                                             // -
    [002D]   startScript(4);                                                    // start Door: Open
    [002F] }
    [002F] stopObjectCode();                                                    // --
}

WalkTo {
    [0030] if (getState08(activeObject)) {                                      // If door open
    [0033]   loadRoomWithEgo(214,21);                                           // Enter Radio
    [0036] }
    [0036] stopObjectCode();                                                    // --
}




/** Yellow Key **/
roomobj-20-194.dmp

Pickup {
    [001E] pickupObject(0);                                                     // Pick object
    [0020] stopObjectCode();                                                    // --
}

Use {
    [0021] doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    [0025] stopObjectCode();                                                    // --
}




/** Cassette Tape **/
roomobj-20-195.dmp

Pickup {
    [0023] if (getState08(131)) {                                               // if Mondo Stereo on
    [0027]   stopSound(25);                                                     //  stop sound
    [0029]   stopMusic();                                                       //  stop music
    [002A]   startSound(20);
    [002C] }
    [002C] setOwnerOf(156,VAR_EGO);                                             // Kid owns Tape
    [002F] setState08();
    [0030] setState02();
    [0031] stopObjectCode();                                                    // --
}

TurnOn {
    [0032] if (!getState08(activeObject)) {                                     // playing?
    [0035]   doSentence(4,131,0);                                               //  Turn on Mondo Stereo
    [0039] }
    [0039] stopObjectCode();                                                    // --
}

TurnOff {
    [003A] if (!getState08(activeObject)) {                                     // playing?
    [003D]   doSentence(5,131,0);                                               // Turn off Mondo Stereo
    [0041] }
    [0041] stopObjectCode();                                                    // --
}




/** Record **/
roomobj-20-235.dmp

Pickup {
    [001C] pickupObject(0);                                                     // Pick object
    [001E] stopObjectCode();                                                    // --
}

Use {
    [001F] doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    [0023] stopObjectCode();                                                    // --
}

Read {
    [0024] printEgo("Tentacle mating calls.");
    [003A] stopObjectCode();                                                    // --
}




/** Demo Tape **/
roomobj-20-238.dmp

Pickup {
    [001B] setState08();                                                        // Tape Locked
    [001C] setState02();                                                        // Tape Hidden
    [001D] setOwnerOf(156,VAR_EGO);                                             // Tape owned by Kid
    [0020] setObjectName(156,"demo tape");
    [002C] Var[13] = 52;                                                        // Tape Contents = Green Tentacle
    [002F] stopObjectCode();                                                    // --
}




/** Left Speaker **/
roomobj-20-393.dmp

Read {
    [001E] printEgo("THX Sound");                                               // Read
    [0028] stopObjectCode();                                                    // --
    }




/** Right Speaker **/
roomobj-20-394.dmp

Read {
    [001F] printEgo("THX Sound");                                               // Read
    [0029] stopObjectCode();                                                    // --
}



/** Poster **/
roomobj-20-396.dmp

Read {
    [0018] printEgo("See Ron Gilbert Live at the Forum!");                      // Read
    [0036] stopObjectCode();                                                    // --
}




/** Poster **/
roomobj-20-397.dmp



/** Bed **/
roomobj-20-398.dmp



/** Picture **/
roomobj-20-439.dmp

Read {
    [0019] printEgo("To my slimiest son, love MOM");                            // Read
    [0032] stopObjectCode();                                                    // --
}




/**
 * Room 21: Radio
 */


/** Door **/
roomobj-21-189.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(184);                                                     // Open Door (Level 3 Hallway)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(184);                                                   // Close Door (Level 3 Hallway)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // is door open
    [0027]   loadRoomWithEgo(184,38);                                           //  Enter Level 3 Hallway
    [002A] }
    [002A] stopObjectCode();                                                    // --
}




/** Dime **/
roomobj-21-190.dmp

Pickup {
    [0018] pickupObject(0);                                                     // Pick object
    [001A] stopObjectCode();                                                    // --
}

Use {
    [001B] doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    [001F] stopObjectCode();                                                    // --
}




/** Radio Tube **/
roomobj-21-191.dmp

Pickup {
    [001C] setOwnerOf(40,VAR_EGO);                                              // Kid owns Radio Tube
    [001F] setState08();                                                        // Lock Tube
    [0020] setState02();                                                        // Hide Tube
    [0021] Var[28] = 0;                                                         // Radio (Room 21) = off
    [0024] stopSound(20);
    [0026] stopSound(29);
    [0028] stopObjectCode();                                                    // --
}



/** Ladder **/
roomobj-21-214.dmp

WalkTo {
    [0018] setState08(192);                                                     // Open Hatch
    [001A] loadRoomWithEgo(192,20);                                             // Enter Green Tentacle's
    [001D] stopObjectCode();                                                    // --
}




/** Picture of Nurse Edna **/
roomobj-21-388.dmp

Open.Pull {
    [0029] startScript(62);                                                     // start Print "Its firmly attached to the wall"
    [002B] stopObjectCode();                                                    // --
}




/** Water Poster **/
roomobj-21-389.dmp

Read {
    [001F] startScript(47);                                                     // start Meteor Police Poster (Read Number)
    [0021] stopObjectCode();                                                    // --
}




/** Tube Socket **/
roomobj-21-390.dmp

Fix.Use {
    [001F] if (VAR_EGO == 5) {                                                  // If Bernard
    [0024]   if (activeObject2 == 40) {                                         //  if use with Radio Tube
    [0028]     setOwnerOf(40,14);                                               //   Green Tentacle owns tube
    [002B]     clearState08(191);                                               //   Clear State
    [002D]     clearState02(191);                                               //   Clear State
    [002F]   } else if (getState08(191)) {
    [0036]     printEgo("That doesn't seem to work.");
    [004E]   }
    [004E] } else {                                                             // -
    [0051]   printEgo("I don't know how!");
    [0061] }
    [0061] stopObjectCode();                                                    // --
}



/** Radio **/
roomobj-21-391.dmp

Fix {
    [001D] if (activeObject2 == 40) {                                           // Fix with Radio Tube
    [0021]   doSentence(6,134,0);                                               // use tube with Tube Socket
    [0025] }
    [0025] stopObjectCode();                                                    // --
}

TurnOn {
    [0026] if (!getState08(191)) {                                              //  is Radio Tube in
    [002A]   if (!getState08(124)) {                                            //   is power on
    [002E]     if (Var[28] == 0) {                                              //    if Radio (Room 21) == off
    [0033]       Var[28] = 1;                                                   //     Radio (Room 21) = on
    [0036]       startSound(20);                                                //     sound radio static
    [0038]     }
    [0038]   }
    [0038] } else if (VAR_EGO == 5) {                                           // is Bernard
    [0040]   printEgo("It's missing a type W-88 vacuum tube.");
    [0061] } else {                                                             // -
    [0064]   printEgo("I can't get it to work./It might be missing a part.");
    [008F] }
    [008F] stopObjectCode();                                                    // --
}

TurnOff {
    [0090] if (Var[28] == 0) {                                                  // if Radio (Room 21) == off
    [0095]   printEgo("It wasn't on.");                                         //
    [00A2] } else {                                                             // -
    [00A5]   Var[28] = 0;                                                       //  Radio = Off
    [00A8]   stopSound(20);                                                     //  stop sound radio static
    [00AA]   stopSound(29);                                                     //  stop sound
    [00AC] }
    [00AC] stopObjectCode();                                                    // --
}

Use {
    [00AD] if (Var[28] == 0) {                                                  // Radio (Room 21) == off
    [00B2]   printEgo("It's not turned on.");
    [00C4] } else if (Var[18] == 3) {                                           // Meteor Location == Gone
    [00CC]   printEgo("The meteor was already picked up.");
    [00EA] } else {                                                             // -
    [00ED]   VAR_RESULT = isScriptRunning(131);
    [00F0]   if (VAR_RESULT == 0) {                                             // Script Meteor Police: Timer until arrival not running
    [00F5]     startScript(35);                                                 //  start Pin: Entry - Radio (Meteor Police)
    [00F7]   } else {                                                           // -
    [00FA]     printEgo("The police are on their way.");
    [0113]   }
    [0113] }
    [0113] stopObjectCode();                                                    // --



/** Bed **/
roomobj-21-392.dmp



/**
 * Room 22: Medical
 */


/** Door **/
roomobj-22-175.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(162);                                                     // Open Door (Level 2 Main Hallway)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(162);                                                   // Close Door (Level 2 Main Hallway)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // If door open
    [0027]   loadRoomWithEgo(162,13);                                           //  Enter Level 2 Main Hallway
    [002A] }
    [002A] stopObjectCode();                                                    // --
}




/** Desk **/
roomobj-22-176.dmp

Open.Pull {
    [001C] setState08();                                                        // Open Draw
    [001D] stopObjectCode();                                                    // --
}

Close.Push {
    [001E] clearState08();                                                      // Close Draw
    [001F] stopObjectCode();                                                    // --
}




/** Manuscript **/
roomobj-22-177.dmp

Fix {
    [0022] if (activeObject2 == 153) {                                          // Use with Typewriter
    [0026]   startScript(10);                                                   //  start Memoir: Writing
    [0028] } else {                                                             // -
    [002B]   printEgo("I can't fix it with that!");
    [0041] }
    [0041] stopObjectCode();                                                    // --
}

Pickup {
    [0042] pickupObject(0);                                                     // Pick object
    [0044] stopObjectCode();                                                    // --
}

Read {
    [0045] startScript(9);                                                      //  start Memoir: Reading
    [0047] stopObjectCode();                                                    // --
}

Use {
    [0048] if (activeObject2 == 153) {
    [004C]   doSentence(6,177,153);                                             // Use with Typewriter
    [0050] } else {                                                             // -
    [0053]   doSentence(11,255,254);                                            // Use _cmdObject2 with _cmdObject
    [0057] }
    [0057] stopObjectCode();                                                    // --
}



/** Mail-A-Med Degree **/
roomobj-22-369.dmp

Read {
    [0024] printEgo("Presented to Doctor Fred.");
    [003C] stopObjectCode();                                                    // --
}



/** Docs 'R Us Diploma **/
roomobj-22-370.dmp

Read {
    [0024] printEgo("Degree for mumifying and bandaging.");
    [0045] stopObjectCode();                                                    // --
}




/** Desk Lamp **/
roomobj-22-371.dmp

TurnOn {
    [001D] startSound(12);                                                      // sound Light Switch
    [001F] setBitVar(VAR_ROOM,1,0);                                             // Light On
    [0023] startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    [0025] stopObjectCode();                                                    // --
}

TurnOff {
    [0026] startSound(12);                                                      // sound Light Switch
    [0028] setBitVar(VAR_ROOM,1,1);                                             // Light Off
    [002C] startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    [002E] stopObjectCode();                                                    // --
}




/** Desk **/
roomobj-22-372.dmp

Open {
    [0018] setState08(176);                                                     // Open Draw
    [001A] stopObjectCode();                                                    // --
}

Close {
    [001B] clearState08(176);                                                   // Open Draw
    [001D] stopObjectCode();                                                    // --
}




/** Black Board **/
roomobj-22-373.dmp

Read {
    [001D] printEgo("It looks like formulas%/%describing the structure of a meteor!/That's strange.");
    [0064] stopObjectCode();                                                    // --
}




/** Examination **/
roomobj-22-374.dmp

Push.Pull {
    [0025] startScript(65);                                                     // start Print "Its too Heavy"
    [0027] stopObjectCode();                                                    // --
}




/** Real Skeleton **/
roomobj-22-375.dmp

WhatIs {
    [001F] printEgo("Oooh! That's scary!");
    [0032] stopObjectCode();                                                    // --
}




/** Medical Diagram **/
roomobj-22-376.dmp

Read {
    [0021] printEgo("Chewy carmel center.");
    [0035] stopObjectCode();                                                    // --
}




/** Medical Cabinet **/
roomobj-22-377.dmp

Open.Unlock {
    [0023] startScript(61);                                                     // start Print "It must require a special key"
    [0025] stopObjectCode();                                                    // --
}




/** Medical Chart **/
roomobj-22-412.dmp

Read {
    [001F] if (VAR_EGO == 2) {                                                  // if Razor
    [0024]   printEgo("WOW! That's neat!!");
    [0036] } else {                                                             // -
    [0039]   printEgo("Yuck. That's disgusting!");
    [0051] }
    [0051] stopObjectCode();                                                    // --
}





/**
 * Room 23: Darkroom
 */


/** Door **/
roomobj-23-182.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(181);                                                     // Open Door (Level 2 Stairs to Level 3)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(181);                                                   // Close Door (Level 2 Stairs to Level 3)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // If Door Open
    [0027]   loadRoomWithEgo(181,12);                                           //  Enter Level 2 Stairs to Level 3
    [002A] }
    [002A] stopObjectCode();                                                    // --
}




/** Enlarger **/
roomobj-23-382.dmp



/** Developer Tray **/
roomobj-23-383.dmp

Use {
    [0023] if (activeObject2 == 23) {                                           // if Undeveloped Film
    [0027]   startScript(72);                                                   //  start Film: Develop
    [0029] } else {                                                             // -
    [002C]   if (activeObject2 == 90) {                                         // if Sponge
    [0030]     if (Var[27] == 0) {                                              //  if Developer Tray Contents == Empty
    [0035]       Var[27] = Var[24];                                             //   Developer Tray Contents = Sponge Contents
    [0038]       Var[24] = 0;                                                   //   Sponge Contents = empty
    [003B]     } else {                                                         //  -
    [003E]       Var[24] = Var[27];                                             //   Sponge Contents = Developer Tray Contents
    [0041]       Var[27] = 0;                                                   //   Developer Tray Contents = empty
    [0044]     }
    [0044]     startScript(75);                                                 //  start Sponge: Name
    [0046]   }
    [0046]   if (activeObject2 == 99) {                                         // if Glass Jar
    [004A]     startSound(41);                                                  //  sound Liquid - Developer Tray
    [004C]     if (Var[27] == 0) {                                              //  if Developer Tray Contents == Empty
    [0051]       Var[27] = Var[22];                                             //   Developer Tray Contents = Glass Jar Contents
    [0054]       Var[22] = 0;                                                   //   Glass Jar Contents = Empty
    [0057]     } else if (Var[22] == 0) {                                       //  -
    [005F]       Var[22] = Var[27];                                             //   Glass Jar Contents = Developer Tray Contents
    [0062]       Var[27] = 0;                                                   //   Developer Tray Contents = Empty
    [0065]     } else {                                                         // -
    [0068]       stopSound(41);
    [006A]       printEgo("The tray is already full.");
    [0081]     }
    [0081]     startScript(74);                                                 // start Glass Jar: Name
    [0083]   }
    [0083]   startScript(78);                                                   // start DeveloperTray: Name
    [0085] }
    [0085] stopObjectCode();                                                    // --
}



/** Desk **/
roomobj-23-384.dmp



/** File Drawers **/
roomobj-23-385.dmp

Open {
    [0020] printEgo("They're locked.");
    [0030] stopObjectCode();                                                    // --
}

Unlock {
    [0031] printEgo("I don't have a key for this.");
    [0049] stopObjectCode();                                                    // --
}




/** Red Light **/
roomobj-23-413.dmp

TurnOn {
    [001D] startSound(12);                                                      // sound Light Switch
    [001F] setBitVar(VAR_ROOM,1,0);                                             // Light On
    [0023] startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    [0025] stopObjectCode();                                                    // --
}

TurnOff {
    [0026] startSound(12);                                                      // sound Light Switch
    [0028] setBitVar(VAR_ROOM,1,1);                                             // Light Off
    [002C] startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    [002E] stopObjectCode();                                                    // --
}




/**
 * Room 24: Gym Bathroom
 */


/** Water Faucet **/
roomobj-24-212.dmp

Use {
    [0017] if (!getState08(activeObject)) {                                     // Tap turned on?
    [001A]   startScript(73);                                                   //  start Facet: Fill Gar/Sponge with Water
    [001C] }
    [001C] stopObjectCode();                                                    // --
}




/** Sink **/
roomobj-24-233.dmp

TurnOn {
    [001A] clearState08();                                                      // Turn On
    [001B] startSound(17);                                                      // Sound Sink On
    [001D] stopObjectCode();                                                    // --
}

TurnOff {
    [001E] setState08();                                                        // Turn off
    [001F] stopSound(17);                                                       // Sound Sink Off
    [0021] stopObjectCode();                                                    // --
}

Use {
    [0022] if (!getState08(activeObject)) {                                     // Sink turned on?
    [0025]   startScript(73);                                                   //  start Facet: Fill Gar/Sponge with Water
    [0027] }
    [0027] stopObjectCode();                                                    // --
}




/** <No Name> **/
roomobj-24-239.dmp



/** Shower Curtain **/
roomobj-24-266.dmp

Open {
    [0024] startScript(12);                                                     // start Ted: Open Curtain
    [0026] stopObjectCode();                                                    // --
}

Close {
    [0027] startScript(13);                                                     // start Ted: Close Curtain
    [0029] stopObjectCode();                                                    // --
}

Pull {
    [002A] if (getState08(82)) {                                                // if Shower Curtain closed
    [002E]   startScript(12);                                                   //  start Ted: Open Curtain
    [0030] } else {                                                             // -
    [0033]   startScript(13);                                                   //  start Ted: Close Curtain
    [0035] }
    [0035] stopObjectCode();                                                    // --
}



/** Cracked Mirror **/
roomobj-24-309.dmp



/** Toilet **/
roomobj-24-311.dmp

Open {
    [001C] doSentence(1,81,0);                                                  // Open Toilet Lid
    [0020] stopObjectCode();                                                    // --
}

Close {
    [0021] doSentence(2,81,0);                                                  // Close Toilet Lid
    [0025] stopObjectCode();                                                    // --
}

Use {
    [0026] animateActor(VAR_EGO,6,1);                                           // kid face Camera
    [002A] printEgo("I'd like a little more privacy for that!");
    [004D] stopObjectCode();                                                    // --
}




/** Pull Chain **/
roomobj-24-312.dmp

Pull.Use {
    [001E] startSound(7);                                                       // sound Toilet Flush
    [0020] stopObjectCode();                                                    // --
}




/** Toilet **/
roomobj-24-313.dmp



/** Door **/
roomobj-24-80.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(79);                                                      // Open Door (Gym)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(79);                                                    // Close Door (Gym)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // If Door Open
    [0027]   loadRoomWithEgo(79,25);                                            //  Enter Gym
    [002A] }
    [002A] stopObjectCode();                                                    // --
}



/** Toilet Lid **/
roomobj-24-81.dmp

Open {
    [001E] setState08();                                                        // Open Lid
    [001F] stopObjectCode();                                                    // --
}

Close {
    [0020] clearState08();                                                      // Close Lid
    [0021] stopObjectCode();                                                    // --
}




/** Shower Curtain **/
roomobj-24-82.dmp

Open.Pull {
    [0024] startScript(12);                                                     // start Ted: Open Curtain
    [0026] stopObjectCode();                                                    // --
}

Close {
    [0027] startScript(13);                                                     // stop Ted: Close Curtain
    [0029] stopObjectCode();                                                    // --
}




/** Shower Curtain **/
roomobj-24-83.dmp

Open.Pull {
    [0024] startScript(12);                                                     // start Ted: Open Curtain
    [0026] stopObjectCode();                                                    // --
}

Close {
    [0027] startScript(13);                                                     // stop Ted: Close Curtain
    [0029] stopObjectCode();                                                    // --
}



/** Shower Curtain **/
roomobj-24-84.dmp

Open.Pull {
    [0024] startScript(12);                                                     // start Ted: Open Curtain
    [0026] stopObjectCode();                                                    // --
}

CLose {
    [0027] startScript(13);                                                     // stop Ted: Close Curtain
    [0029] stopObjectCode();                                                    // --
}




/** Water Faucet **/
roomobj-24-85.dmp

Open.TurnOn {
    [0028] if (!getState08(activeObject)) {                                     // If Faucet Has Handle
    [002B]   startSound(18);                                                    // Sound Shower
    [002D]   setState08(212);                                                   // Water Faucet Off
    [002F]   clearState02(212);                                                 // Lock Water Faucet
    [0031]   clearState08(239);                                                 // Hide <no name> (Running Water)
    [0033]   walkActorTo(12,24,48);                                             // Dead Cousin Ted
    [0037]   if (Var[116] == 0) {                                               // if Ednas Phone Number has not been exposed
    [003C]     Var[116] = 1;                                                    //  Ednas Phone Number exposed = Yes
    [003F]     startScript(139);                                                //  start Cutscene: Weird Ed & Dr. Fred Trigger #1
    [0041]   }
    [0041] } else {                                                             // -
    [0044]   printEgo("The handle's missing.");
    [0059] }
    [0059] stopObjectCode();                                                    // --
}

Close.TurnOff {
    [005A] if (!getState08(activeObject)) {
    [005D]   stopSound(18);                                                     // stop Sound Shower
    [005F]   clearState08(212);                                                 // Water Faucet On
    [0061]   setState02(212);                                                   // UnLock Water Faucet
    [0063] }
    [0063] stopObjectCode();                                                    // --
}
Fix.Use {
    [0064] if (activeObject2 == 120) {                                          // if Water Faucet Handle
    [0068]   clearState08();                                                    //  Facet Has Handle
    [0069]   setOwnerOf(120,0);                                                 //  Facet Handle has no owner
    [006C] } else {                                                             // -
    [006F]   printEgo("That doesn't make sense.");
    [0086] }
    [0086] stopObjectCode();                                                    // --
}



/** <No Name> **/
roomobj-24-86.dmp



/** <No Name> **/
roomobj-24-87.dmp



/** <No Name> **/
roomobj-24-88.dmp



/** <No Name> **/
roomobj-24-89.dmp



/** Sponge **/
roomobj-24-90.dmp

Pickup {
    [002B] pickupObject(0);                                                     // Pick object
    [002D] stopObjectCode();                                                    // --
}

Use {
    [002E] if (activeObject2 == 99) {                                           // use with Glass Jar
    [0032]   Var[24] = Var[22];                                                 //  Sponge Contents = Glass Jar Contents
    [0035]   Var[22] = 0;                                                       //  Glass Jar Contents = 0
    [0038]   startScript(75);                                                   //  Sponge: Name
    [003A]   startScript(74);                                                   //  Glass Jar: Name
    [003C] } else {                                                             // -
    [003F]   doSentence(11,255,254);                                            //  Use _cmdObject2 with _cmdObject
    [0043] }
    [0043] stopObjectCode();                                                    // --
}

Give {
    [0044] if (VAR_ACTIVE_ACTOR == 19) {                                        // Give to Plant
    [0049]   doSentence(11,36,90);                                              //  Use  with Plant
    [004D] }
    [004D] if (VAR_ACTIVE_ACTOR < 8) {
    [0052]   setOwnerOf(0,VAR_ACTIVE_ACTOR);                                    // Give to Kid
    [0055] }
    [0055] stopObjectCode();                                                    // --
}



/**
 * Room 25: Gym
 */


/** TV **/
roomobj-25-304.dmp

TurnOn {
    [0014] if (VAR_EGO == 5) {                                                  // If Bernard
    [0019]   printEgo("It doesn't work, cable's not hooked up.");
    [003C] } else {                                                             // -
    [003F]   printEgo("All I get is fuzz.");
    [004F] }
    [004F] stopObjectCode();                                                    // --
}



/** Pillow **/
roomobj-25-305.dmp



/** Playboy Calar **/
roomobj-25-306.dmp

Read {
    [0026] printEgo("May 1972, and Ted's Deathday is circled!");                // Read
    [004A] stopObjectCode();                                                    // --
}

Pull.Pickup {
    [004B] printEgo("It's nailed, stapled,/and glued to the wall.");            // Pull/Pick Up
    [0073] stopObjectCode();                                                    // --
}




/** Poster **/
roomobj-25-307.dmp

Read {
    [0018] printEgo("Miss Mummy of 982 BC.");                                   // Read
    [002B] stopObjectCode();                                                    // --
}




/** Surplus Body **/
roomobj-25-308.dmp

WhatIs {
    [0024] printEgo("Yuck!");                                                   // What Is
    [002B] stopObjectCode();                                                    // --
}




/** Door **/
roomobj-25-76.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(187);                                                     // Open Door (Level 3 Hallway)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(187);                                                   // Close Door (Level 3 Hallway)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // if Door open
    [0027]   loadRoomWithEgo(187,38);                                           //  Enter Level 3 Hallway
    [002A] }
    [002A] stopObjectCode();                                                    // --
}




/** Sarcophagus **/
roomobj-25-77.dmp

Open {
    [001F] setState08();                                                        // Open
    [0020] stopObjectCode();                                                    // --
}

Close {
    [0021] clearState08();                                                      // Close
    [0022] stopObjectCode();                                                    // --
}




/** Hunk-O-Matic **/
roomobj-25-78.dmp

Use {
    [002B] startScript(23);                                                     // start Gym: Get Stronger
    [002D] stopObjectCode();                                                    // --
}




/** Door **/
roomobj-25-79.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(80);                                                      // Open Door (Gym Bathroom)
    [001E] stopObjectCode();                                                    // --
}
Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(80);                                                    // Close Door (Gym Bathroom)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // If Door Open
    [0027]   if (!getState08(212)) {                                            //  if Water Faucet Off
    [002B]     putActorInRoom(12,24);                                           //   Put Ted in front of phone number
    [002E]     putActor(12,30,48);
    [0032]   } else {                                                           // -
    [0035]     putActorInRoom(12,24);                                           //   Put Ted to left of phone number
    [0038]     putActor(12,24,48);
    [003C]   }
    [003C]   loadRoomWithEgo(80,24);                                            //  Enter Gym Bathroom
    [003F] }
    [003F] stopObjectCode();                                                    // --
}



/**
 * Room 26: Weird Ed's
 */


 /** Hamster **/
roomobj-26-1.dmp

Pickup {
    [001D] Var[87] = 0;                                                         // Weird Ed: Looking for plans = 0
    [0020] startScript(111);                                                    // start Weird Ed. Handle Object Interactions
    [0022] stopObjectCode();                                                    // --
}
Use {
    [0023] doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    [0027] stopObjectCode();                                                    // --
}

Give {
    [0028] startScript(89);                                                     // start Give Hamster
    [002A] stopObjectCode();                                                    // --
}




/** Piggy Bank **/
roomobj-26-2.dmp

Pickup {
    [0022] if (getState08(activeObject)) {                                      // If Piggy Bank broken
    [0025]   printEgo("Ouch!");
    [002C]   Var[107] = 2;                                                      //  Give Script: Object-ID = Piggy Bank
    [002F]   startScript(111);                                                  //  start Weird Ed. Handle Object Interactions
    [0031] } else {                                                             // -
    [0034]   printEgo("It's nailed and glued to the table.");                   //
    [0053] }
    [0053] stopObjectCode();                                                    // --
}

Open {
    [0054] if (!getState08(activeObject)) {                                     // If Pibby Bank Not broken
    [0057]   Var[107] = 2;                                                      //  Give Script: Object-ID
    [005A]   startScript(111);                                                  //  start Weird Ed. Handle Object Interactions
    [005C] }
    [005C] stopObjectCode();                                                    // --
}

Close.Fix {
    [005D] if (getState08(activeObject)) {                                      // If Piggy Bank Broken
    [0060]   printEgo("It looks hopeless!");
    [0072]   Var[107] = 2;                                                      // Give Script: Object-ID
    [0075]   startScript(111);                                                  // start Weird Ed. Handle Object Interactions
    [0077] }
    [0077] stopObjectCode();                                                    // --
}




/** Penant **/
roomobj-26-257.dmp

Read {
    [0019] printEgo("L.F.L.U. Rah!");                                           // Read
    [0027] stopObjectCode();                                                    // --
}




/** Fighter Jet **/
roomobj-26-258.dmp



/** X-Wing Model **/
roomobj-26-259.dmp



/** Strategic Plan **/
roomobj-26-260.dmp

Read {
    [002A] printEgo("Hmm. It doesn't make any sense.");                         // Read
    [0046] stopObjectCode();                                                    // --
}




/** Bed **/
roomobj-26-261.dmp



/** Window **/
roomobj-26-262.dmp



/** Dime **/
roomobj-26-3.dmp

Pickup {
    [0018] startScript(111);                                                    // start Weird Ed. Handle Object Interactions
    [001A] stopObjectCode();                                                    // --
}
Use {
    [001B] doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    [001F] stopObjectCode();                                                    // --
}



/** Dime **/
roomobj-26-4.dmp

Pickup {
    [0018] startScript(111);                                                    // start Weird Ed. Handle Object Interactions
    [001A] stopObjectCode();                                                    // --
}

Use {
    [001B] doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    [001F] stopObjectCode();                                                    // --
}




/** Dime **/
roomobj-26-5.dmp

Pickup {
[0018] startScript(111);                                                        // start Weird Ed. Handle Object Interactions
[001A] stopObjectCode();                                                        // --
}

Use {
[001B] doSentence(11,255,254);                                                  // Use _cmdObject2 with _cmdObject
[001F] stopObjectCode();                                                        // --
}




/** Door **/
roomobj-26-6.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(186);                                                     // Open Door (Level 3 Hallway)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(186);                                                   // Close Door (Level 3 Hallway)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // If Door Open
    [0027]   loadRoomWithEgo(186,38);                                           //  Enter Level 3 Hallway
    [002A]   cursorCommand( kModeNormal )                                       //  Cutscene Mode Normal
    [002C] }
    [002C] stopObjectCode();                                                    // --
}




/** Card Key **/
roomobj-26-71.dmp

Pickup {
    [001E] pickupObject(0);                                                     // Pick object
    [0020] stopObjectCode();                                                    // --
}

Read {
    [0021] printEgo("This side up.");                                           // Read
    [002E] stopObjectCode();                                                    // --
}

Use {
    [002F] doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    [0033] stopObjectCode();                                                    // --
}




/**
 * Room 27: Typewriter
 */


/** Door **/
roomobj-27-211.dmp

Use {
    [0024] doSentence(11,36,255);                                               // Use Pot for plant with _cmdObject2
    [0028] stopObjectCode();                                                    // --
}

WhatIs {
    [0029] printEgo("It bit me!");                                              //
    [0033] stopObjectCode();                                                    // --
}




/** Fireplace **/
roomobj-27-290.dmp



/** Family Portrait **/
roomobj-27-291.dmp

Open.Pull {
    [0023] startScript(62);
    [0025] stopObjectCode();                                                    // --
}




/** Pot for plant **/
roomobj-27-292.dmp

Use {
    [001F] if (activeObject2 == 90) {                                           // Use with Sponge
    [0023]   if (Var[24] == 2) {                                                //  if Sponge Contents == Radioactive water
    [0028]     Var[24] = 0;                                                     //   Sponge Contents = Empty
    [002B]     Var[30]++;                                                       //   Plant Size++
    [002D]   }
    [002D]   if (Var[24] == 3) {                                                //  if Sponge Contents == Developer
    [0032]     Var[24] = 0;                                                     //   Sponge Contents = Empty
    [0035]     Var[30] = 255;                                                   //   Plant Size = Dead
    [0038]   }
    [0038]   startScript(75);                                                   // start Sponge: Name
    [003A] }
    [003A] if (activeObject2 == 99) {                                           // Use with Jar
    [003E]   if (Var[22] == 2) {                                                //  if Jar Contents == Radioactive water
    [0043]     Var[22] = 0;                                                     //   Jar Contents = Empty
    [0046]     Var[30] += 2;                                                    //   Plant Size+=2
    [0049]   }
    [0049]   if (Var[22] == 3) {                                                //  if Jar Contents == Developer
    [004E]     Var[22] = 0;                                                     //   Jar Contents = Empty
    [0051]     Var[30] = 255;                                                   //   Plant Size = Dead
    [0054]   }
    [0054]   startScript(74);                                                   // start Sponge: Name
    [0056] }
    [0056] if (Var[30] == 255) {                                                // if Plant Size == Dead
    [005B]   printEgo("I killed it!");
    [0067] } else if (Var[30] >= 3) {                                           // -
    [006F]   Var[30] = 2;                                                       //  Plant Size = Full Size
    [0072] }
    [0072] if (activeObject2 == 60) {
    [0076]   startScript(48);
    [0078] }
    [0078] stopObjectCode();                                                    // --
}



/** Typewriter **/
roomobj-27-409.dmp

Fix {
    [001E] if (activeObject2 == 177) {                                          // Fix with Manuscript
    [0022]   startScript(10);                                                   // start Memoir: Writing
    [0024] } else {                                                             // -
    [0027]   printEgo("That's ridiculous!");
    [003A] }
    [003A] stopObjectCode();                                                    // --
}

Use {
    [003B] if (activeObject2 == 177) {                                          // Use with manuscript
    [003F]   startScript(10);                                                   // start Memoir: Writing
    [0041] }
    [0041] if (activeObject2 == 201) {                                          // Use with Sealed Envelope
    [0045]   VAR_RESULT = getActorBitVar(VAR_EGO,4);
    [0049]   if (VAR_RESULT == 1) {                                             // if kid has kActorMiscFlagWatchedTV
    [004E]     if (Var[85] == 0) {                                              //  if Envelope: Addressed == 0
    [0053]       printEgo("Ok, I'll type the publisher's address.");
    [0076]       startScript(108);                                              //   start Typewriter: Actor Using
    [0078]       Var[85] = 1;                                                   //   Envelope: Addressed = 1
    [007B]     } else {                                                         // -
    [007E]       printEgo("It's already addressed.");
    [0095]     }
    [0095]   } else {                                                           // -
    [0098]     printEgo("I don't know what to type on it!");
    [00B3]   }
    [00B3] }
    [00B3] stopObjectCode();                                                    // --
}



/** Desk **/
roomobj-27-410.dmp



/** Plant **/
roomobj-27-411.dmp



/** Door **/
roomobj-27-66.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(188);                                                     // Open Door (Typewriter)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(188);                                                   // Close Door (Typewriter)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // If door open
    [0027]   loadRoomWithEgo(188,38);                                           //  Enter Level 3 Hallway
    [002A] }
    [002A] stopObjectCode();                                                    // --
}




/** Man-eating plant **/
roomobj-27-67.dmp

Use {
    [0024] doSentence(11,36,255);                                               // Use Pot for plant with _cmdObject2
    [0028] stopObjectCode();                                                    // --
}
WalkTo {
    [0029] loadRoomWithEgo(232,28);                                             // Enter Telescope
    [002C] stopObjectCode();                                                    // --
}




/** Paint Blotch **/
roomobj-27-68.dmp

Use {
    [001E] if (activeObject2 == 167) {                                          // if Use with Paint Remover
    [0022]   setOwnerOf(167,14);                                                //  Green owns paint Remover
    [0025]   setState08(68);                                                    //  Lock Blotch
    [0027]   setState02(68);                                                    //  Hide Blotch
    [0029] }
    [0029] stopObjectCode();                                                    // --
}



/** Door **/
roomobj-27-69.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(202);                                                     // Open Door (Electrical Wiring)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(202);                                                   // Close Door (Electrical Wiring)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // if hatch open
    [0027]   loadRoomWithEgo(202,15);                                           //  Enter Electrical Wiring
    [002A] }
    [002A] stopObjectCode();                                                    // --
}




/**
 * Room 28: Telescope
 */


/** Hole **/
roomobj-28-232.dmp

WalkTo {
    [0016] if (Var[30] == 255) {                                                // if Plant Size == Dead
    [001B]   printEgo("The plant's gone. I'm stuck here!");
    [0039] } else {                                                             // -
    [003C]   VAR_RESULT = isScriptRunning(48);
    [003F]   if (VAR_RESULT == 0) {                                             // If script Plant: Give Pepsi not running
    [0044]     Var[76] = 6;                                                     //  Death Method = Eaten by plant
    [0047]     startScript(56);                                                 //  Cutscene: Kid Dies
    [0049]   } else {                                                           // -
    [004C]     loadRoomWithEgo(67,27);                                          //  Enter Typewriter
    [004F]   }
    [004F] }
    [004F] stopObjectCode();                                                    // --
}



/** Astronomy Chart **/
roomobj-28-402.dmp

Read {
    [0021] printEgo("It shows the trajectory of a meteorite%/%impacting Earth.");
    [0055] stopObjectCode();                                                    // --
}



/** Control Panel **/
roomobj-28-403.dmp

Read {
    [001F] printEgo("Insert dime.");                                            // Read
    [002C] stopObjectCode();                                                    // --
}


/** Left Button **/
roomobj-28-404.dmp

Read {
    [001F] printEgo("Rotate left.");                                            // Read
    [002C] stopObjectCode();                                                    // --
}

Push {
    [002D] if (Var[26] != 0) {                                                  // if Telescope: Dimes Available
    [0032]   Var[20] -= 1;                                                      //  Move Screen Left
    [0035]   if (Var[20] == 255) {                                              //  Overflow?
    [003A]     startSound(12);                                                  //   sound Light Switch
    [003C]     Var[20] = 0;                                                     //   Screen 0
    [003F]   } else {                                                           // -
    [0042]     Var[26] -= 1;                                                    // Telescope: Dimes Available -= 1
    [0045]     startScript(16);                                                 // start Telescope: Rotate
    [0047]   }
    [0047] } else {                                                             // -
    [004A]   printEgo("It's not rotating.");
    [005C]   startSound(11);                                                    // Sound CoinSlot
    [005E] }
    [005E] stopObjectCode();                                                    // --
  }


/** Right Button **/
roomobj-28-405.dmp

Read {
    [0020] printEgo("Rotate right.");
    [002E] stopObjectCode();                                                    // --
}

Push {
    [002F] if (Var[26] != 0) {                                                  // if Telescope: Dimes Available
    [0034]   Var[20]++;                                                         //  Telescope Room ++
    [0036]   if (Var[20] == 4) {                                                //  if Telescope Room reached max?
    [003B]     startSound(12);                                                  //   sound Light Switch
    [003D]     Var[20] = 3;                                                     //   Back to previous
    [0040]   } else {                                                           // -
    [0043]     Var[26] -= 1;                                                    //  Telescope: Dimes Available -= 1
    [0046]     startScript(16);                                                 //  start Telescope: Rotate
    [0048]   }
    [0048] } else {                                                             // -
    [004B]   printEgo("It's not rotating.");
    [005D]   startSound(11);                                                    // Sound CoinSlot
    [005F] }
    [005F] stopObjectCode();                                                    // --
}



/** Really Powerful Telescope **/
roomobj-28-406.dmp

Use {
    [002B] startScript(17);                                                     // start Telescope: Look
    [002D] stopObjectCode();                                                    // --
}



/** Coin Slot **/
roomobj-28-407.dmp

Read {
    [001D] printEgo("Donations kindly accepted.");
    [0037] stopObjectCode();                                                    // --
}

Use {
    [0038] if (activeObject2 == 3) {                                            // if Dime
    [003C]   setOwnerOf(3,0);                                                   //  Remove Dime
    [003F]   goto 0066;
    [0042] } else if (activeObject2 == 4) {                                     // if Dime
    [0049]   setOwnerOf(4,0);                                                   //  Remove Dime
    [004C]   goto 0066;
    [004F] } else if (activeObject2 == 5) {                                     // if Dime
    [0056]   setOwnerOf(5,0);                                                   //  Remove Dime
    [0059]   goto 0066;
    [005C] } else if (activeObject2 == 190) {                                   // if Dime
    [0063]   setOwnerOf(190,0);                                                 //  Remove Dime
    [0066]   Var[26]++;                                                         // ++Telescope: Dimes Available
    [0068]   startSound(11);                                                    // Sound CoinSlot
    [006A] } else {                                                             // -
    [006D]   printEgo("It doesn't fit.");
    [007C] }
    [007C] stopObjectCode();                                                    // --
}



/**
 * Room 29: Underhouse
 */

/** Grate **/
roomobj-29-213.dmp

Open.Pull {
    [001F] setState08();                                                        // Open
    [0020] setState08(20);                                                      // Open Grating (Front of Mansion)
    [0022] stopObjectCode();                                                    // --
}

Close.Push {
    [0023] clearState08();                                                      // Close Grating
    [0024] clearState08(20);                                                    // Close Grating (Front of mansion)
    [0026] stopObjectCode();                                                    // --
}

WalkTo {
    [0027] if (getState08(activeObject)) {                                      // if open
    [002A]   loadRoomWithEgo(20,1);                                             //  Enter Front of Mansion
    [002D] }
    [002D] stopObjectCode();                                                    // --
}



/** Floor Grating **/
roomobj-29-267.dmp

WhatIs {
    [001F] printEgo("I can't reach it.");                                       // What Is
    [002F] stopObjectCode();                                                    // --
}




/** Puddle of Developer **/
roomobj-29-32.dmp

Pickup {
    [0027] printEgo("I don't have anything to put it in.");
    [0045] stopObjectCode();                                                    // --
}

Use {
    [0046] if (activeObject2 == 90) {                                           // use with Sponge
    [004A]   setState08();                                                      //  Hide Puddle
    [004B]   setState02();                                                      //  Lock Puddle
    [004C]   Var[24] = 3;                                                       //  Sponge Contents = Developer
    [004F]   startScript(75);                                                   //  start Sponge: Name
    [0051] }
    [0051] if (activeObject2 == 99) {                                           // use with jar
    [0055]   printEgo("I can't get it in the jar.");
    [006B] }
    [006B] stopObjectCode();                                                    // --
}



/** Water Valve **/
roomobj-29-33.dmp


Open.TurnOn {
    [0023] if (!getState08(activeObject)) {                                     // if Closed
    [0026]   setState08();                                                      //  Open
    [0027]   startScript(70);                                                   //  start Pool Water Valve
    [0029] }
    [0029] stopObjectCode();                                                    // --
}

Close.TurnOff {
    [002A] if (getState08(activeObject)) {                                      // if Open
    [002D]   clearState08();                                                    //  Close
    [002E]   startScript(70);                                                   //  start Pool Water Valve
    [0030] }
    [0030] stopObjectCode();                                                    // --
}




/**
 * Room 30: Lab: Zom-b-Matic
 */


/** Door **/
roomobj-30-136.dmp

Open.WalkTo {
    [0018] printEgo("It's sealed shut!");                                       // Open
    [0029] stopObjectCode();                                                    // --
}




/** Locker **/
roomobj-30-137.dmp

Open {
    [001A] setState08();                                                        // Open
    [001B] stopObjectCode();                                                    // --
}

Close {
    [001C] clearState08();                                                      // Close
    [001D] stopObjectCode();                                                    // --
}




/** Cold Can of Pepsi **/
roomobj-30-145.dmp

Open {
    [0029] printEgo("Ok, it's open.");                                          // Open
    [0037] stopObjectCode();                                                    // --
}

Use {
    [0038] printEgo("That was refreshing.");                                    // use
    [004C] stopObjectCode();                                                    // --
}

Pickup {
    [004D] pickupObject(0);                                                     // Pick object
    [004F] stopObjectCode();                                                    // --
}

Read {
    [0050] printEgo("12 fluid ounces (354 ml)");
    [0066] stopObjectCode();                                                    // --
}




/** Door **/
roomobj-30-237.dmp

Open {
    [0020] if (!getState04(activeObject)) {                                     // if door unlocked
    [0023]   startScript(116);                                                  //  start Verb: Generic: Open Door
    [0025]   setState08(251);                                                   //  Open Door (Lab: Meteor))
    [0027] } else {                                                             // -
    [002A]   printEgo("It's locked.");
    [0037] }
    [0037] stopObjectCode();                                                    // --
}

Close {
    [0038] startScript(117);                                                    // start Verb: Generic: Close Door
    [003A] clearState08(251);                                                   // Close Door (Lab: Meteor)
    [003C] setState04();                                                        // Lock Door
    [003D] stopObjectCode();                                                    // --
}

WalkTo {
    [003E] if (getState08(activeObject)) {                                      // if door open
    [0041]   loadRoomWithEgo(251,51);                                           //  Enter Lab: Meteor
    [0044] }
    [0044] stopObjectCode();                                                    // --
}

Unlock.Use.Lock {
    [0045] doSentence(11,152,255);                                              // Use Card Slot
    [0049] stopObjectCode();                                                    // --
}




/** Radiation Suit **/
roomobj-30-253.dmp

Use.Pickup {
    [0022] putActorInRoom(8,30);                                                // Radiation Suit enters Lab: Zom-b-Matic
    [0025] putActor(8,65,56);
    [0029] VAR_EGO = 8;                                                         // Kid = Radiation Suit
    [002C] animateActor(VAR_EGO,253,1);                                         // No Meteor
    [0030] putActorInRoom(Var[100],0);                                          // Old Kid leaves room
    [0033] putActor(Var[100],0,0);
    [0037] Var[90] = 253;                                                       // Radiation Suit
    [003A] VAR_RESULT = getObjectOwner(Var[90]);
    [003D] if (VAR_RESULT == Var[100]) {                                        // Does previous kid own object
    [0042]   setOwnerOf(Var[90],8);                                             //  Radiation suit now owns object
    [0045] }
    [0045] Var[90] -= 1;
    [0048] unless (Var[90] == 0) goto 003A;                                     // Loop all objects
    [004D] cursorCommand( kModeNoNewKid )                                       // Disable New Kid verb
    [004F] Var[97] = 0;
    [0052] Var[98] = 0;
    [0055] Var[99] = 0;
    [0058] Var[90] = 7;
    [005B] setActorBitVar(Var[90],128,1);
    [005F] putActorInRoom(Var[90],0);
    [0062] putActor(Var[90],0,0);
    [0066] Var[91] = 253;                                                       // Radiation Suit
    [0069] VAR_RESULT = getObjectOwner(Var[91]);
    [006C] if (VAR_RESULT == Var[90]) {
    [0071]   setOwnerOf(Var[91],0);                                             // object owned by no-one
    [0074] }
    [0074] Var[91] -= 1;
    [0077] unless (Var[91] == 0) goto 0069;                                     // loop all objects
    [007C] Var[90] -= 1;
    [007F] unless (Var[90] == 0) goto 005B;                                     // loop all kids
    [0084] setState08();                                                        // Lock
    [0085] setState02();                                                        // Lock
    [0086] actorFollowCamera(VAR_EGO);                                          // Camera follow radiation suit
    [0088] stopObjectCode();                                                    // --
}




/** Pepsi Machine **/
roomobj-30-349.dmp

Read {
    [0021] printEgo("Please insert one quarter.");
    [003A] stopObjectCode();                                                    // --
}

Use {
    [003B] if (activeObject2 == 200) {                                          // if use with Quarter
    [003F]   startSound(54);                                                    // sound Keypad Buttons
    [0041]   clearState08(145);                                                 // Unlock Cold can of Pepsi
    [0043]   clearState02(145);                                                 // Unlock Cold can of Pepsi
    [0045]   setOwnerOf(200,0);
    [0048] } else {                                                             // -
    [004B]   printEgo("It doesn't work.");
    [005B] }
    [005B] stopObjectCode();                                                    // --
}




/** Zom-B-matic **/
roomobj-30-350.dmp

Read {
    [001D] printEgo("Please insert one kid.");
    [0032] stopObjectCode();                                                    // --
}




/** Girl Zombie **/
roomobj-30-351.dmp



/** Boy Zombie **/
roomobj-30-352.dmp



/** Card Slot **/
roomobj-30-408.dmp

Read {
    [0021] printEgo("Insert card key to unlock door.");
    [003D] stopObjectCode();                                                    // --
}

Unlock.Use.Lock {
    [003E] if (activeObject2 == 71) {                                           // if Card Key
    [0042]   clearState04(237);                                                 //  Open Door (Lab: Zom-b-Matic)
    [0044]   startSound(54);                                                    // sound Keypad Buttons
    [0046]   doSentence(1,237,0);                                               // Open Door
    [004A] } else {                                                             // -
    [004D]   printEgo("It doesn't fit.");
    [005C] }
    [005C] stopObjectCode();                                                    // --
}



/** Control Panel **/
roomobj-30-417.dmp

Read {
    [001F] printEgo("To initiate destruct sequence:/Press buttons in proper order.");
    [0057] stopObjectCode();                                                    // --
}




/** Button 1 **/
roomobj-30-418.dmp

Push {
    [001A] printEgo("Button 1 pushed.");                                        // Push
    [002A] startSound(54);                                                      // sound Keypad Buttons
    [002C] doSentence(13,161,0);                                                // Walk to Control Panel
    [0030] stopObjectCode();                                                    // --
}




/** Button 2 **/
roomobj-30-419.dmp

Push {
    [001A] printEgo("Button 2 pushed.");                                        // Push
    [002A] startSound(54);                                                      // sound Keypad Buttons
    [002C] doSentence(13,161,0);                                                // Walk to Control Panel
    [0030] stopObjectCode();                                                    // --
}




/** Button 3 **/
roomobj-30-420.dmp

Push {
    [001A] printEgo("Button 3 pushed.");                                        // Push
    [002A] startSound(54);                                                      // sound Keypad Buttons
    [002C] doSentence(13,161,0);                                                // Walk to Control Panel
    [0030] stopObjectCode();                                                    // --
}




/** Button 4 **/
roomobj-30-421.dmp

Push {
    [001A] printEgo("Button 4 pushed.");                                        // Push
    [002A] startSound(54);                                                      // sound Keypad Buttons
    [002C] doSentence(13,161,0);                                                // Walk to Control Panel
    [0030] stopObjectCode();                                                    // --
}




/**
 * Room 31: Lab: Entry
 */


/** Door **/
roomobj-31-133.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(130);                                                     // Open Door (Dungeon)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(130);                                                   // Close Door (Dungeon)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // if door open
    [0027]   cursorCommand( kModeNormal )                                       //  Cutscene Mode Normal
    [0029]   loadRoomWithEgo(130,4);                                            //  Enter Dungeon
    [002C] }
    [002C] stopObjectCode();                                                    // --
}




/** Door **/
roomobj-31-135.dmp

Open {
    [001A] VAR_RESULT = isScriptRunning(43);                                    // Purple Tentacle: Check for close actors
    [001D] if (VAR_RESULT == 0) {                                               //  Purple not looking for actors?
    [0022]   startScript(4);                                                    //   Door: Open
    [0024]   setState08(136);
    [0026] } else {                                                             // -
    [0029]   printEgo("It's stuck!");                                           //   Door is stuck
    [0035] }
    [0035] stopObjectCode();                                                    // --
}

Close {
    [0036] startScript(5);                                                      // Door: Close
    [0038] clearState08(136);
    [003A] stopObjectCode();                                                    // --
}

WalkTo {
    [003B] if (getState08(activeObject)) {
    [003E]   startScript(142);                                                  // Secret Lab: Enter Room
    [0040] }
    [0040] stopObjectCode();                                                    // --
}




/** Control Panel **/
roomobj-31-347.dmp



/** Periscope **/
roomobj-31-348.dmp

Use {
    [001B] printEgo("I see a heart-shaped bed.");                               // Use
    [0032] stopObjectCode();                                                    // --
}




/** Map of House **/
roomobj-31-416.dmp



/**
 * Room 32: Meteor Police
 */


/** <No Name> **/
roomobj-32-203.dmp



/**
 * Room 33: Mansion At Distance (Lights Off)
 */


/** <No Name> **/
roomobj-33-10.dmp



/** <No Name> **/
roomobj-33-11.dmp



/** <No Name> **/
roomobj-33-7.dmp



/** <No Name> **/
roomobj-33-73.dmp



/** <No Name> **/
roomobj-33-8.dmp



/** <No Name> **/
roomobj-33-9.dmp



/**
 * Room 34: Telescope looking into Room 9
 */


/** <No Name> **/
roomobj-34-140.dmp



/** <No Name> **/
roomobj-34-141.dmp



/** <No Name> **/
roomobj-34-142.dmp



/** <No Name> **/
roomobj-34-199.dmp



/**
 * Room 35: Telescope looking at Alien
 */


/** <No Name> **/
roomobj-35-205.dmp



roomobj-35-206.dmp



/**
 * Room 36: Storage / Leading out to pool
 */


/** Shelves **/
roomobj-36-314.dmp



/** Door **/
roomobj-36-91.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(65);                                                      // Open Door (Dining)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(65);                                                    // Close Door (Dining)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // if Door open
    [0027]   if (Var[113] == 0) {                                               //  if Storage Room Not Entered
    [002C]     Var[113] = 1;                                                    //   Storage Room Entered
    [002F]     startScript(134);                                                //   start Cutscene: Weird Ed & Nurse Edna Trigger #1
    [0031]   }
    [0031]   loadRoomWithEgo(65,37);                                            //  Enter Dining
    [0034] }
    [0034] stopObjectCode();                                                    // --
}




/** Door **/
roomobj-36-92.dmp

Open {
    [0020] if (!getState04(activeObject)) {                                     // if door unlocked
    [0023]   startScript(4);                                                    //  start Door: Open
    [0025]   setState08(104);                                                   //  Open Door (Pool Area)
    [0027] } else {                                                             // -
    [002A]   startScript(64);                                                   //  start Print "The door is locked"
    [002C] }
    [002C] stopObjectCode();                                                    // --
}

Close {
    [002D] startScript(5);                                                      // start Door: Close
    [002F] clearState08(104);                                                   // Close Door (Pool Area)
    [0031] stopObjectCode();                                                    // --
}

Unlock.Use {
    [0032] if (activeObject2 == 125) {                                          // if use with Silver Key
    [0036]   clearState04();                                                    //  Unlock Door
    [0037]   clearState04(104);                                                 //  Unlock Door (Pool Area)
    [0039]   doSentence(1,92,0);                                                //  Open Door
    [003D] } else {                                                             // -
    [0040]   startScript(66);                                                   // start Print "I can't unlock the door with this."
    [0042] }
    [0042] stopObjectCode();                                                    // --
}

Lock {
    [0043] setState04();                                                        // Lock Door
    [0044] setState04(104);                                                     // Lock Door (Pool Area)
    [0046] doSentence(2,92,0);                                                  // Close Door
    [004A] stopObjectCode();                                                    // --
}

WalkTo {
    [004B] if (getState08(activeObject)) {                                      // If Door Open
    [004E]   loadRoomWithEgo(104,6);                                            //  Enter Pool Area
    [0051] }
    [0051] stopObjectCode();                                                    // --
}




/** Bottle of Developer **/
roomobj-36-94.dmp

Pickup {
    [0025] clearState08(98);                                                    // Grate
    [0027] clearState08(32);                                                    // Show Puddle of Developer (underhouse)
    [0029] clearState02(32);                                                    // Unlock Puddle of Developer (underhouse)
    [002B] setState08();                                                        // Lock Bottle
    [002C] setState02();                                                        // Hide Bottle
    [002D] startSound(10);                                                      // sound Piggy Bank Break
    [002F] printEgo("Whoops!");
    [0038] stopObjectCode();                                                    // --
}



/** Tentacle Chow **/
roomobj-36-95.dmp

Pickup {
    [0021] pickupObject(0);                                                     // Pick object
    [0023] stopObjectCode();                                                    // --
}

Give {
    [0024] startScript(98);                                                     // start Give: Accept Item Check
    [0026] stopObjectCode();                                                    // --
}




/** Canned Goods **/
roomobj-36-96.dmp

Pickup {
    [0020] pickupObject(0);                                                     // Pick object
    [0022] stopObjectCode();                                                    // --
}

Give {
    [0023] startScript(98);                                                     // start Give: Accept Item Check
    [0025] stopObjectCode();                                                    // --
}




/** Fruit Drinks **/
roomobj-36-97.dmp

Pickup {
    [0020] pickupObject(0);                                                     // Pick object
    [0022] stopObjectCode();                                                    // --
}

Give {
    [0023] startScript(99);
    [0025] stopObjectCode();                                                    // --
}




/** Grate **/
roomobj-36-98.dmp

Open.Pull.Pickup {
    [001B] if (!getState08(activeObject)) {                                     // if develeper smashed
    [001E]   printEgo("Yech, broken glass!");
    [0031] } else {                                                             // -
    [0034]   printEgo("It's welded into the floor.");
    [004D] }
    [004D] stopObjectCode();                                                    // --
}




/** Glass Jar **/
roomobj-36-99.dmp

Pickup {
    [0026] pickupObject(0);                                                     // Pick object
    [0028] stopObjectCode();                                                    // --
}

Use {
    [0029] doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    [002D] stopObjectCode();                                                    // --
}

Give {
    [002E] if (VAR_ACTIVE_ACTOR == 19) {                                        // Give to Plant
    [0033]   doSentence(11,36,99);                                              //  Use Pot for plant with Glass Jar
    [0037] } else if (VAR_ACTIVE_ACTOR < 8) {                                   // -
    [003F]   setOwnerOf(0,VAR_ACTIVE_ACTOR);                                    //  Give to kid
    [0042] } else if (Var[22] > 0) {                                            // Glass Jar Contents != Empty
    [004A]   Var[134] = 1;                                                      //  Glass Jar has content = 1
    [004D]   startScript(99);                                                   //  Give: Accept Item Check 2
    [004F] }
    [004F] stopObjectCode();                                                    // --
}



/**
 * Room 37: Dining
 */


/** Chair **/
roomobj-37-281.dmp



/** Chair **/
roomobj-37-282.dmp



/** Candle **/
roomobj-37-283.dmp

Pickup {
    [0018] startScript(65);                                                     // start Print "Its too Heavy"
    [001A] stopObjectCode();                                                    // --
}




/** Candle **/
roomobj-37-284.dmp

Pickup {
    [0018] startScript(65);                                                     // start Print "Its too Heavy"
    [001A] stopObjectCode();                                                    // --
}




/** Candle **/
roomobj-37-285.dmp

Pickup {
    [0018] startScript(65);                                                     // start Print "Its too Heavy"
    [001A] stopObjectCode();                                                    // --
}



/** Light **/
roomobj-37-286.dmp

TurnOn.TurnOff.Use {
    [001B] printEgo("I can't reach it.");
    [002B] stopObjectCode();                                                    // --
}




/** Gravy Stain **/
roomobj-37-441.dmp

Pickup {
    [001D] printEgo("I don't do table cloths.");
    [0033] stopObjectCode();                                                    // --
}




/** Door **/
roomobj-37-62.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(49);                                                      // Door Open (Kitchen)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(49);                                                    // Door Close (Kitchen)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // if door open
    [0027]   loadRoomWithEgo(49,7);                                             //  enter kitchen
    [002A] }
    [002A] stopObjectCode();                                                    // --
}




/** Old Rotting Turkey **/
roomobj-37-63.dmp

Pickup {
    [0026] pickupObject(63);                                                    // Pickup
    [0028] stopObjectCode();                                                    // --
}

Give {
    [0029] startScript(98);                                                     // start Give: Accept Item Check
    [002B] stopObjectCode();                                                    // --
}




/** Week old Roast **/
roomobj-37-64.dmp

Pickup {
    [0022] pickupObject(64);                                                    // Pickup
    [0024] stopObjectCode();                                                    // --
}

Give {
    [0025] startScript(98);                                                     // start Give: Accept Item Check
    [0027] stopObjectCode();                                                    // --
}




/** Door **/
roomobj-37-65.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(91);                                                      // Open Door (storage)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(91);                                                    // Close Door (storage)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // if door open
    [0027]   loadRoomWithEgo(91,36);                                            //  enter storage
    [002A] }
    [002A] stopObjectCode();                                                    // --
}




/**
 * Room 38: Level 3 Hallway
 */


/** Door: Radio Room **/
roomobj-38-184.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(189);
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(189);
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {
    [0027]   loadRoomWithEgo(189,21);
    [002A] }
    [002A] stopObjectCode();                                                    // --
}




/** Door: Nurse Edna **/
roomobj-38-185.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(70);
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(70);
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // If Door Open
    [0027]   VAR_RESULT = getActorRoom("Nurse Edna");                           //
    [002A]   if (VAR_RESULT == 19) {                                            //  If Nurse Edna in her bedroom
    [002F]     if (Var[109] == 0) {                                             //   if Purple chased out of lab == No
    [0034]       VAR_RESULT = isScriptRunning(29);                              //
    [0037]       if (VAR_RESULT == 0) {                                         //    if Cutscene: Edna: Prank Phone Call not running
    [003C]         putActorInRoom(10,19);                                       //      Put Nurse Edna in bedroom
    [003F]         putActor(10,34,64);                                          //
    [0043]         animateActor(10,6,1);                                        //       Nurse Edna Face left
    [0047]       }
    [0047]       startScript(33);                                               //      start Nurse Edna: Return to Room (Level 3 Hallway)
    [0049]     }
    [0049]   }
    [0049]   loadRoomWithEgo(70,19);                                            // Actor enters room
    [004C] }
    [004C] stopObjectCode();                                                    // --
}



/** Door: Weird Ed **/
roomobj-38-186.dmp
Events:
  Open - 001A
 Close - 001F
WalkTo - 0024

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(6);                                                       //
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(6);
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {
    [0027]   VAR_RESULT = getActorRoom("Weird Ed");
    [002A]   if (VAR_RESULT == 26) {
    [002F]     startScript(86);                                                 // start Weird Ed: Check for frily actors
    [0031]   }
    [0031]   loadRoomWithEgo(6,26);                                             // Actor enters room
    [0034] }
    [0034] stopObjectCode();                                                    // --
}




/** Door: Gym **/
roomobj-38-187.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(76);
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(76);
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {
    [0027]   loadRoomWithEgo(76,25);
    [002A] }
    [002A] stopObjectCode();                                                    // --
}




/** Door: Typewriter Room **/
roomobj-38-188.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(66);                                                      // Open Door (Typewriter Room)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(66);                                                    // Close Door (Typewriter Room)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // if door open
    [0027]   loadRoomWithEgo(66,27);                                            //  Enter typewriter room
    [002A] }
    [002A] stopObjectCode();                                                    // --
}




/** Stairs **/
roomobj-38-208.dmp

WalkTo {
    [0018] loadRoomWithEgo(180,12);                                             // Enter Level 2 Stairs to Level 3
    [001B] stopObjectCode();                                                    // --
}




/** Plant **/
roomobj-38-300.dmp



/** Plant **/
roomobj-38-303.dmp



/** Plant **/
roomobj-38-310.dmp



/**
 * Room 39: Video Game: High Scores
 */


/** Highscore: Pin1 **/
roomobj-39-227.dmp



/** Highscore: Pin1 **/
roomobj-39-228.dmp



/** Highscore: Pin1 **/
roomobj-39-229.dmp



/** Highscore: Pin1 **/
roomobj-39-230.dmp



/**
 * Room 40: 3 Guys who publish anything (TV)
 */


/** <No Name> **/
roomobj-40-249.dmp



/**
 * Room 41: 3 Guys who publish anything (Office)
 */


 /** <No Name> **/
roomobj-41-242.dmp



/** <No Name> **/
roomobj-41-274.dmp



/**
 * Room 43: Keypad
 */


/** * **/
roomobj-43-287.dmp

WhatIs {
    [0012] startSound(19);                                                      // sound Light Beep
    [0014] Var[49] = 10;                                                        // Keypad Input = 10
    [0017] print(255,"*");
    [001B] stopObjectCode();                                                    // --
}




/** 0 **/
roomobj-43-288.dmp

WhatIs {
    [0012] startSound(19);                                                      // sound Light Beep
    [0014] Var[49] = 0;                                                         // Keypad Input = 0
    [0017] print(255,"0");
    [001B] stopObjectCode();                                                    // --
}



/** # **/
roomobj-43-289.dmp

WhatIs {
    [0012] startSound(19);                                                      // sound Light Beep
    [0014] Var[49] = 11;                                                        // Keypad Input = 11
    [0017] print(255,"#");
    [001B] stopObjectCode();                                                    // --
}



/** 1 **/
roomobj-43-422.dmp

WhatIs {
    [0012] startSound(19);                                                      // sound Light Beep
    [0014] Var[49] = 1;                                                         // Keypad Input = 1
    [0017] print(255,"1");
    [001B] stopObjectCode();                                                    // --
}



/** 2 **/
roomobj-43-423.dmp

WhatIs {
    [0012] startSound(19);                                                      // sound Light Beep
    [0014] Var[49] = 2;                                                         // Keypad Input = 2
    [0017] print(255,"2");
    [001B] stopObjectCode();                                                    // --
}



/** 3 **/
roomobj-43-424.dmp

WhatIs {
    [0012] startSound(19);                                                      // sound Light Beep
    [0014] Var[49] = 3;                                                         // Keypad Input = 3
    [0017] print(255,"3");
    [001B] stopObjectCode();                                                    // --
}



/** 4 **/
roomobj-43-425.dmp

WhatIs {
    [0012] startSound(19);                                                      // sound Light Beep
    [0014] Var[49] = 4;                                                         // Keypad Input = 4
    [0017] print(255,"4");
    [001B] stopObjectCode();                                                    // --
}



/** 5 **/
roomobj-43-426.dmp

WhatIs {
    [0012] startSound(19);                                                      // sound Light Beep
    [0014] Var[49] = 5;                                                         // Keypad Input = 5
    [0017] print(255,"5");
    [001B] stopObjectCode();                                                    // --
}



/** 6 **/
roomobj-43-427.dmp

WhatIs {
    [0013] startSound(19);                                                      // sound Light Beep
    [0015] Var[49] = 6;                                                         // Keypad Input = 6
    [0018] print(255,"6");
    [001C] stopObjectCode();                                                    // --
}



/** 7 **/
roomobj-43-428.dmp

WhatIs {
    [0012] startSound(19);                                                      // sound Light Beep
    [0014] Var[49] = 7;                                                         // Keypad Input = 7
    [0017] print(255,"7");
    [001B] stopObjectCode();                                                    // --
}



/** 8 **/
roomobj-43-429.dmp

WhatIs {
    [0012] startSound(19);                                                      // sound Light Beep
    [0014] Var[49] = 8;                                                         // Keypad Input = 8
    [0017] print(255,"8");
    [001B] stopObjectCode();                                                    // --
}



/** 9 **/
roomobj-43-430.dmp

WhatIs {
    [0012] startSound(19);                                                      // sound Light Beep
    [0014] Var[49] = 9;                                                         // Keypad Input = 9
    [0017] print(255,"9");
    [001B] stopObjectCode();                                                    // --
}



/**
 * Room 44: Welcome to Mansion
 */


 /** ( Exit to room 1 ) **/
roomobj-44-241.dmp

WalkTo {
    [0012] loadRoomWithEgo(240,1);                                              // Enter Front of Mansion
    [0015] stopObjectCode();                                                    // --
}




/** Sign **/
roomobj-44-265.dmp

Read {
    [0016] printEgo("WARNING!!/Trespassers will be horribly mutilated.");
    [0045] stopObjectCode();                                                    // --
}




/**
 * Room 45: Kid Selection
 */


/** Syd **/
roomobj-45-243.dmp

WhatIs {
    [0012] Var[90] = 1;                                                         // Kid Selected = Syd
    [0015] print(255,"Syd - an aspiring musician%/%trying to start his own new-wave band.");
    [0051] startScript(109);                                                    // Intro: Kid Selection: Update Var States
    [0053] stopObjectCode();                                                    // --
}



/** Razor **/
roomobj-45-244.dmp

WhatIs {
    [0012] Var[90] = 2;                                                         // Kid Selected = Razor
    [0015] print(255,"Razor - lead singer for the punk band,/`Razor and the Scummettes.`");
    [0050] startScript(109);                                                    // Intro: Kid Selection: Update Var States
    [0052] stopObjectCode();                                                    // --
}



/** Michael **/
roomobj-45-245.dmp

WhatIs {
    [0012] Var[90] = 4;                                                         // Kid Selected = Michael
    [0015] print(255,"Michael - award winning photographer%/%for the college newspaper.");
    [0052] startScript(109);                                                    // Intro: Kid Selection: Update Var States
    [0054] stopObjectCode();                                                    // --
}



/** Bernard **/
roomobj-45-246.dmp

WhatIs {
    [0012] Var[90] = 5;                                                         // Kid Selected = Bernard
    [0015] print(255,"Bernard - president of the physics club%/%and winner of the college's Geek Award.");
    [005D] startScript(109);                                                    // Intro: Kid Selection: Update Var States
    [005F] stopObjectCode();                                                    // --
}



/** Wy **/
roomobj-45-247.dmp

WhatIs {
    [0012] Var[90] = 6;                                                         // Kid Selected = Wy
    [0015] print(255,"Wy - wants to be a famous novelist%/%and is waiting for a big break.");
    [0052] startScript(109);                                                    // Intro: Kid Selection: Update Var States
    [0054] stopObjectCode();                                                    // --
}



/** Jeff **/
roomobj-45-248.dmp

WhatIs {
    [0012] Var[90] = 7;                                                         // Kid Selected = Jeff
    [0015] print(255,"Jeff - usually hangs out on the beach,/responds to the name, Surfer Dude.");
    [0055] startScript(109);                                                    // Intro: Kid Selection: Update Var States
    [0057] stopObjectCode();                                                    // --
}



/** Dave **/
roomobj-45-387.dmp

WhatIs {
    [0012] startSound(54);                                                      // sound Keypad Buttons
    [0014] print(255,"Dave - Sandy's boyfri./Organizer of the rescue effort.");
    [0049] stopObjectCode();                                                    // --
}



/** Start **/
roomobj-45-395.dmp

WhatIs {
    [0012] startSound(54);                                                      // sound Keypad Buttons
    [0014] if (Var[92] < 3) {                                                   // if Kids Slected < 3
    [0019]   print(255,"  Please select two kids besides Dave.");               //
    [003C] } else {                                                             // -
    [003F]   Var[91] = 1;                                                       // Kid Select: Game can Start = yes
    [0042] }
    [0042] stopObjectCode();                                                    // --
}



/**
 * Room 47: Mansion At Distance (Lights On)
 */


/** <No Name> **/
roomobj-47-13.dmp



/** <No Name> **/
roomobj-47-14.dmp



/** <No Name> **/
roomobj-47-15.dmp



/** <No Name> **/
roomobj-47-16.dmp



/**
 * Room 50: Load / Save Screen
 */


/** Load Game **/
roomobj-50-442.dmp

WhatIs {
    [0012] Var[50] = 2;                                                         // SaveLoad: Button Pressed = Load Game
    [0015] startSound(19);                                                      // Beep
    [0017] stopObjectCode();                                                    // --
}



/** Save Game **/
roomobj-50-443.dmp

WhatIs {
    [0012] Var[50] = 1;                                                         // SaveLoad: Button Pressed = Save Game
    [0015] startSound(19);                                                      // Beep
    [0017] stopObjectCode();                                                    // --
}



/** Continue Playing **/
roomobj-50-444.dmp

WhatIs {
    [0012] Var[50] = 3;                                                         // SaveLoad: Button Pressed = Continue Playing
    [0015] startSound(19);                                                      // Beep
    [0017] stopObjectCode();                                                    // --
}



/**
 * Room 51: Lab: Meteor
 */


/** Switch **/
roomobj-51-143.dmp

TurnOff.Push.Pull.Use {
    [001E] if (!getState08(activeObject)) {                                     // if not switched
    [0021]   setState08();                                                      //  Switch
    [0022]   stopScript(120);                                                   //  stop Dr Fred: Entered Lab
    [0024]   stopSound(59);
    [0026]   startSound(61);                                                    //  start Print "It must require a special key"
    [0028]   startScript(121);                                                  //  start Dr Fred: Free of machines control
    [002A] }
    [002A] stopObjectCode();                                                    // --
}



/** Door **/
roomobj-51-144.dmp

Open {
    [001A] startScript(116);                                                    // Open Door
    [001C] setState08(26);                                                      // Hide Cement Slab
    [001E] stopObjectCode();                                                    // --
}

CLose {
    [001F] startScript(117);                                                    // Close Door
    [0021] stopObjectCode();                                                    // --
}

WalkTo {
    [0022] if (getState08(activeObject)) {                                      // If Door open
    [0025]   if (Var[136] == 1) {                                               //  if Garage Destroyed
    [002A]     loadRoomWithEgo(75,52);                                          //   Enter 'Garage Destroyed'
    [002D]   } else {                                                           // -
    [0030]     setOwnerOf(120,15);                                              //   Medical Diagram owned by Meteor Police ??
    [0033]     loadRoomWithEgo(120,16);                                         //   Enter 'Garage'
    [0036]   }
    [0036] }
    [0036] stopObjectCode();                                                    // --
}



/** Door **/
roomobj-51-251.dmp

Open {
    [001A] startScript(116);                                                    // Open Door
    [001C] setState08(237);                                                     // Open Door (Lab: Zom-b-Matic)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(117);                                                    // Close Door
    [0021] clearState08(237);                                                   // Close Door (Lab: Zom-b-Matic)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // if door open
    [0027]   loadRoomWithEgo(237,30);                                           //  Enter Lab: Zom-b-Matic
    [002A] }
    [002A] stopObjectCode();                                                    // --

}



/** Meteor **/
roomobj-51-252.dmp

Pickup {
    [001A] if (Var[89] == 2) {                                                  // Meteor Loose?
    [001F]   pickupObject(0);                                                   // Pick object
    [0021]   clearState08();
    [0022]   setState02();
    [0023]   Var[18] = 1;                                                       // Meteor Location = Kids Hands
    [0026]   startScript(129);                                                  // start Radiation Suit: Enable Speaking Flag
    [0028]   putActorInRoom(16,0);                                              // Meteor Leaves
    [002B]   putActor(16,0,0);
    [002F]   stopScript(123);                                                   // stop Meteor: Fire Radiation
    [0031]   putActorInRoom(20,0);                                              // Meteor Radiation Leaves
    [0034]   putActor(20,0,0);
    [0038] } else {                                                             // -
    [003B]   printEgo("I can't get it loose!");
    [004E] }
    [004E] stopObjectCode();                                                    // --
}
Use {
    [004F] doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    [0053] stopObjectCode();                                                    // --
}




/** Purple Slime **/
roomobj-51-353.dmp

WhatIs {
    [001E] printEgo("I'm not going to touch that slime!");                      // What is
    [003C] stopObjectCode();                                                    // --
}



/**
 * Room 52: Garage Destroyed
 */

 /** Gate **/
roomobj-52-75.dmp

Open.Pull {
    [001E] if (!getState04(activeObject)) {                                     // If unlocked
    [0021]   startScript(116);                                                  //  start Verb: Generic: Open Door
    [0023]   setState08(105);                                                   //  Open Gate (Pool Area)
    [0025] } else {                                                             // -
    [0028]   printEgo("It's locked");
    [0034] }
    [0034] stopObjectCode();                                                    // --
}

Close.Push {
    [0035] startScript(117);                                                    // start Verb: Generic: Close Door
    [0037] clearState08(105);                                                   // Close Gate (Pool Area)
    [0039] stopObjectCode();                                                    // --
}

WalkTo {
    [003A] if (getState08(activeObject)) {                                      // If gate open
    [003D]   loadRoomWithEgo(105,6);                                            //  Enter Pool Area
    [0040] }
    [0040] stopObjectCode();                                                    // --
}

