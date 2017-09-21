/**
 * Maniac Mansion: Demo
 * 
 * Scripts
 */

/**
 * Script 1: Demo Mode Selection
 */Script-1 {                                                                                                                                                                                                                                                  
    [0000] cutscene();                                                          // Start Cutscene
    [0001] screenPrepare();
    [0002] loadSound(1);
    [0004] lockSound(1);
    [0006] loadSound(33);
    [0008] lockSound(33);
    [000A] loadSound(30);
    [000C] lockSound(30);
    
    [000E] Var[97] = 3;                                                         // Kid1 is Dave
    [0011] Var[98] = 5;                                                         // Kid2 is Bernard
    [0014] Var[99] = 2;                                                         // Kid3 is Razor
    
    [0017] loadRoom(45);                                                        // Load Demo Mode Selection
    [0019] Var[11] = 1;                                                         //
    [001C] cursorCommand(1);                                                    // Keypad Mode
    [001E] Var[91] = 0;                                                         // Clear 'Start' status
    [0021] delay(60);
    [0025] if (VAR_IS_SOUND_RUNNING == 0) {                                     // If no music playing
    [002A]   startMusic(30);                                                    //  sound MM Theme
    [002C]   Var[92] = 1;                                                       //  Play Music Count = Once More
    [002F] }
    
    [002F] breakHere();
    [0030] unless (VAR_IS_SOUND_RUNNING == 0) goto 002F;                        // Loop until music finishes
    
    [0035] if (Var[92] == 1) {                                                  // if Play Music Count == Once More
    [003A]   Var[92] = 0;                                                       //  Play Music Count = Start Intro
    [003D]   startMusic(30);                                                    //  sound MM Theme
    [003F]   goto 002F;                                                         //  Loop until music finishes
    [0042] }
    
    [0042] if (Var[91] != 0) {                                                  // Start?
    [0047]   delay(2);
    [004B]   startSound(29);                                                    // Play sound
    [004D]   delay(60);
    [0051] }
    
    [0051] endcutscene();                                                       // End Cutscene
    [0052] stopMusic();
    
    [0053] Var[11] = 0;
    [0056] cursorCommand(0);
    [0058] loadRoom(0);
    [005A] if (Var[91] == 0) {                                                  // Start Intro?
    [005F]   startScript(44);                                                   //  Cutscene: Intro: Comet / Mansion
    [0061]   breakHere();
    [0062]   VAR_RESULT = isScriptRunning(44);
    [0065]   unless (VAR_RESULT == 0) goto 0061;                                //  Sleep until Intro Cutscene finishes
    [006A]   goto 0017;                                            
    [006D] }
    
    [006D] unlockSound(1);
    [006F] unlockSound(33);
    [0071] unlockSound(30);
    [0073] unlockRoom(49);
    [0075] unlockCostume(22);
    [0077] unlockScript(45);
    
    [0079] setBitVar(44,2,1);                                                   // Room ?? Light Always On
    [007D] setBitVar(1,2,1);                                                    // Room Front of Mansion Light Always On
    [0081] setBitVar(6,2,1);                                                    // Room Pool Area Light Always On
    [0085] setBitVar(31,2,1);                                                   // Room Lab: Entry Light Always On
    [0089] setBitVar(8,1,1);                                                    // Room Basement Light Off
    [008D] setBitVar(5,1,1);                                                    // Room Library Light Off
    
    [0091] if (Var[91] == 2) {                                                  // is Hands-Off Mode?
    [0096]   startScript(6);                                                    //  start Demo: Hands-Off
    [0098]   stopScript(0);
    [009A] }
    
    [009A] putActorInRoom(Var[97],1);                                           // Put Dave outside Mansion
    [009D] putActor(Var[97],24,59);
    
    [00A1] putActorInRoom(Var[98],1);                                           // Put Kid 2 outside Mansion
    [00A4] putActor(Var[98],29,57);
    
    [00A8] putActorInRoom(Var[99],1);                                           // Put Kid 3 outside Mansion
    [00AB] putActor(Var[99],34,61);
    
    [00AF] animateActor(Var[97],6,1);                                           // Dave Face camera
    [00B3] animateActor(Var[98],6,1);                                           // Kid 2 Face camera
    [00B7] animateActor(Var[99],6,1);                                           // Kid 3 Face camera
    [00BB] loadRoom(1);
    
    [00BD] actorFollowCamera(3);
    [00BF] cursorCommand(3);
    [00C1] stopObjectCode();
}

 /**
  * Script 3: Verb: Defaults
  */
Script-3 {                                                                                                                                                                                                                                                  
    [0000] if (VAR_ACTIVE_VERB == 1) {                                          // If Open Pressed
    [0005]   printEgo("It doesn't seem to open.");                 
    
    [001B] } else if (VAR_ACTIVE_VERB == 9) {                                   // If Push
    [0023]   goto 002E;                                            
    [0026] } else if (VAR_ACTIVE_VERB == 10) {                                  // If Pull
    [002E]   printEgo("I can't move it.");                         
    
    [003D] } else if (VAR_ACTIVE_VERB == 12) {                                  // If Read
    [0045]   startScript(19);          
    
    [0047]   if (Var[92] == 0) {                                                // 
    [004C]     printEgo("It's too dark to read.");                 
    [0060]   } else {                                              
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
    [0004]   startSound(7);                                                     // door open sound
    [0006] }
    [0006] stopObjectCode();
}

 /**
  * Script 5: Door: Close
  */
Script-5 {                                                                                                                                                                                                                                                  
    [0000] if (getState08(activeObject)) {                                      // If door is open
    [0003]   clearState08();                                                    // close door
    [0004]   startSound(8);                                                     // Sound Door Closing
    [0006] }
    [0006] stopObjectCode();
}

 /**
  * Script 6: Hands-Off Demo
  */
Script-6 {                                                                                                                                                                                                                                                  
    [0000] cutscene();                                             
    [0001] loadSound(7);
    [0003] lockSound(7);
    [0005] loadSound(8);
    [0007] lockSound(8);
    [0009] loadScript(4);
    [000B] lockScript(4);
    [000D] loadScript(5);
    [000F] lockScript(5);
    
    [0011] putActorInRoom(3,1);                                                 // Dave Enters Outside Mansion
    [0014] putActor(3,18,58);
    [0018] loadRoom(1);
    [001A] actorFollowCamera(3);                                                // Camera Follow Dave
    [001C] animateActor(3,6,1);                                                 // Dave face camera
    
    [0020] Var[11] = 1;                                                         // Cutscene playing
    [0023] cursorCommand(0);
    [0025] delay(120);
    [0029] walkActorTo(3,18,70);                                                // Dave walk toward camera
    [002D] breakHere();
    [002E] VAR_RESULT = getActorMoving(3);
    [0031] unless (VAR_RESULT == 2) goto 002D;                                  // Wait for Dave
    
    [0036] print(3,"Hello, and welcome to Maniac Mansion,/a new type of story game from Lucasfilm./I'm Dave Miller, your personal guide/and one of the stars of the adventure.");
    [00BB] breakHere();
    [00BC] unless (VAR_HAVE_MSG == 0) goto 00BB;                                // Let Dave Talk
    
    [00C1] walkActorTo(3,59,58);
    [00C5] print(3,"Here's where Sandy was held captive,/and where we rescued her from Dr. Fred.");
    [0108] breakHere();
    [0109] VAR_RESULT = getActorMoving(3);
    [010C] unless (VAR_RESULT == 2) goto 0108;                                  // Wait for Dave
    
    [0111] animateActor(3,5,1);                                                 // Dave face Right
    [0115] breakHere();
    [0116] animateActor(3,6,1);                                                 // Dave face Camera
    [011A] breakHere();
    [011B] unless (VAR_HAVE_MSG == 0) goto 011A;                                // Let Dave Talk
    
    [0120] print(3,"Let's go inside.");
    [0131] breakHere();
    [0132] unless (VAR_HAVE_MSG == 0) goto 0131;                                // Let Dave Talk
    
    [0137] walkActorToObject(3,28);                                             // Walk Dave to Front Door
    [013A] breakHere();
    [013B] VAR_RESULT = getActorMoving(3); 
    [013E] unless (VAR_RESULT == 2) goto 013A;                                  // Wait for Dave
    
    [0143] clearState04(28);                                                    // Unlock Front Door
    [0145] doSentence(1,28,0);                                                  // Open Front Door
    [0149] delay(90);
    [014D] setCameraAt(VAR_CAMERA_POS_X);                                       // Set Camera at Camera Pos?
    
    [014F] putActorInRoom(3,10);                                                // Dave enters Mansion Entry
    [0152] putActor(3,6,60);
    [0156] animateActor(3,5,1);                                                 // Dave Face Right
    
    [015A] delay(60);
    [015E] loadRoom(10);                                                        // Enter Mansion
    
    [0160] actorFollowCamera(3);                                                // Camera Follow Dave
    [0162] delay(60);
    [0166] animateActor(3,6,1);                                                 // Dave Face Camera
    [016A] delay(15);
    
    [016E] print(3,"I've arranged for the occupants to be/gone during our `tour.`/We shouldn't have any problems.");
    [01C1] breakHere();
    [01C2] unless (VAR_HAVE_MSG == 0) goto 01C1;                                // Let Dave Talk
    
    [01C7] animateActor(3,4,1);                                                 // Dave Face Away
    [01CB] delay(20);
    [01CF] doSentence(2,34,0);                                                  // Close Front Door
    [01D3] delay(60);
    [01D7] animateActor(3,6,1);                                                 // Dave face camera
    
    [01DB] delay(60);
    [01DF] Var[11] = 0;        
    [01E2] cursorCommand(0);                                                    //
    [01E4] loadRoom(0);                                                         // Black screen
    
    [01E6] dummyEE();
    [01E7] print(255,"Meanwhile, in a tiny room downstairs...");
    [020C] breakHere();
    [020D] unless (VAR_HAVE_MSG == 0) goto 020C;                                // Wait for messabe
    
    [0212] screenPrepare();    
    [0213] startScript(7);                                                      // start Edison Family Cutscene
    
    [0215] breakHere();
    [0216] VAR_RESULT = isScriptRunning(7);
    [0219] unless (VAR_RESULT == 0) goto 0215;                                  // Wait for Edison Family Cutscene to finish
    
    [021E] loadSound(27);
    [0220] lockSound(27);
    [0222] loadSound(1);
    [0224] lockSound(1);
    [0226] loadSound(32);
    [0228] lockSound(32);
    [022A] loadSound(24);
    [022C] lockSound(24);
    [022E] loadRoom(10);                                                        // Back to Main Entry
    [0230] Var[11] = 1;
    [0233] cursorCommand(0);
    [0235] actorFollowCamera(3);                                                // Camera Follow Dave
    [0237] delay(90);
    [023B] print(3,"Oh. That was a `cut-scene.` They happen/from time to time to let you know what's/happening elsewhere in the mansion.");
    [02A0] breakHere();
    [02A1] unless (VAR_HAVE_MSG == 0) goto 02A0;                                // Let Dave Talk
    
    [02A6] delay(60);
    [02AA] print(3,"All these tours make me hungry.");
    [02C7] breakHere();
    [02C8] unless (VAR_HAVE_MSG == 0) goto 02C7;                                // Let Dave Talk
    
    [02CD] print(3,"Here's the kitchen.");
    [02E1] walkActorToObject(3,35);
    [02E4] breakHere();
    [02E5] VAR_RESULT = getActorMoving(3);
    [02E8] unless (VAR_RESULT == 2) goto 02E4;                                  // Let Dave Talk
    
    [02ED] doSentence(1,35,0);                                                  // Open Kitchen Door
    [02F1] delay(180);
    [02F5] animateActor(3,5,1);                                                 // Face Right
    
    [02F9] breakHere();
    [02FA] animateActor(3,6,1);                                                 // Dave face camera
    [02FE] print(3,"I see they haven't cleaned up the, er,/uh, um... the mess yet.");
    [0334] breakHere();
    [0335] unless (VAR_HAVE_MSG == 0) goto 0334;                                // Let Dave Talk
     
    [033A] animateActor(3,4,1);                                                 // Face Left
    [033E] breakHere();
    [033F] animateActor(3,7,1);                                                 // Face Away
    [0343] delay(180);
    
    [0347] print(3,"I think I just lost my appetite.");
    [0364] doSentence(2,35,0);                                                  // Close Kitchen Door
    [0368] delay(20);
    [036C] animateActor(3,4,1);                                                 // Face Left
    [0370] breakHere();
    [0371] animateActor(3,6,1);                                                 // Dave face camera
    [0375] breakHere();
    [0376] unless (VAR_HAVE_MSG == 0) goto 0375;                                // Let Dave Talk
    
    [037B] delay(120);
    [037F] print(3,"I know, let's go to my favorite room,/the basement.");
    [03AD] delay(60);
    [03B1] walkActorTo(3,56,58);
    [03B5] breakHere();
    [03B6] VAR_RESULT = getActorMoving(3);
    [03B9] unless (VAR_RESULT == 2) goto 03B5;                                  // Wait for Dave
    
    [03BE] breakHere();
    [03BF] unless (VAR_HAVE_MSG == 0) goto 03BE;                                // Let Dave Talk
    
    [03C4] animateActor(3,7,1);                                                 // Face Away
    [03C8] breakHere();
    [03C9] print(3,"Oh yes, no handle.");
    [03DB] breakHere();
    [03DC] unless (VAR_HAVE_MSG == 0) goto 03DB;                                // Let Dave Talk
    
    [03E1] animateActor(3,5,1);                                                 // Face Right
    [03E5] breakHere();
    [03E6] animateActor(3,6,1);                                                 // Face camera
    [03EA] breakHere();
    [03EB] print(3,"Now how did I open this door last time?/Push it?");
    [0415] breakHere();
    [0416] unless (VAR_HAVE_MSG == 0) goto 0415;                                // Let Dave Talk
    
    [041B] walkActorTo(3,56,40);
    [041F] breakHere();
    [0420] VAR_RESULT = getActorMoving(3);
    [0423] unless (VAR_RESULT == 2) goto 041F;                                  // Wait for Dave
    
    [0428] delay(120);
    [042C] print(3,"Nope. Maybe I need a running start.");
    [044C] walkActorTo(3,56,70);
    [0450] breakHere();
    [0451] VAR_RESULT = getActorMoving(3);
    [0454] unless (VAR_RESULT == 2) goto 0450;                                  // Wait for Dave
    
    [0459] breakHere();
    [045A] unless (VAR_HAVE_MSG == 0) goto 0459;                                // Let Dave Talk
    
    [045F] walkActorTo(3,56,40);
    [0463] breakHere();
    [0464] VAR_RESULT = getActorMoving(3);
    [0467] unless (VAR_RESULT == 2) goto 0463;                                  // Wait for Dave
    
    [046C] startSound(32);
    [046E] animateActor(3,254,1);                                               // 
    [0472] print(255,"Owwwwwwwwwwwwwwwwwww!   ");
    
    [048B] animateActor(3,4,1);                                                 // Dave Face Left
    [048F] breakHere();
    [0490] animateActor(3,6,1);                                                 // Dave face camera
    [0494] breakHere();
    [0495] animateActor(3,5,1);                                                 // Face Right
    [0499] breakHere();
    [049A] animateActor(3,7,1);                                                 // Face Away
    [049E] breakHere();
    [049F] Var[52] = getRandomNr(112);                                          // Random X
    [04A2] Var[53] = getRandomNr(12);                                           // Random Y
    [04A5] Var[53] += 52;
    [04A8] walkActorTo(3,Var[52],Var[53]);
    [04AC] unless (VAR_HAVE_MSG == 0) goto 048B;                                // Spin Dave until he finishes talking
    
    [04B1] breakHere();
    [04B2] animateActor(3,255,1);                                               // Stop Moving
    [04B6] delay(60);
    [04BA] animateActor(3,253,1);
    [04BE] breakHere();
    [04BF] animateActor(3,6,1);                                                 // Dave face right
    [04C3] delay(120);
    [04C7] print(3,"Oh well, I'll let you figure it out.");
    [04E7] delay(120);
    [04EB] walkActorToObject(3,37);                                             // Walk dave to lounge entry door
    [04EE] breakHere();
    [04EF] VAR_RESULT = getActorMoving(3);
    [04F2] unless (VAR_RESULT == 2) goto 04EE;                                  // Wait for Dave
    
    [04F7] doSentence(1,37,0);                                                  // Open lounge entry door
    [04FB] unlockSound(32);
    [04FD] delay(60);
    [0501] breakHere();
    [0502] unless (VAR_HAVE_MSG == 0) goto 0501;                                // Wait for Dave to talk
    
    [0507] setCameraAt(VAR_CAMERA_POS_X);
    
    [0509] putActorInRoom(3,3);                                                 // Dave enters Lounge Entry
    [050C] putActor(3,7,60);
    [0510] delay(60);
    
    [0514] putActorInRoom(24,3);                                                // Sandy enterse Lounge Entry
    [0517] putActor(24,24,56);
    [051B] animateActor(24,7,1);                                                // Sandy Face Away
    [051F] animateActor(3,5,1);                                                 // Dave Face Right
    [0523] loadRoom(3);                                                         //
    
    [0525] startMusic(27);                                                      // Play Sandys music
    [0527] actorFollowCamera(3);
    [0529] setState08(207);                                                     // Turn on Stereo
    [052B] clearState08(47);                                                    // 
    [052D] delay(180);
    
    [0531] print(3,"Hi Sandy, could you turn the music down?");
    [0555] breakHere();
    [0556] unless (VAR_HAVE_MSG == 0) goto 0555;                                // Let Dave Talk
    
    [055B] delay(180);
    [055F] print(3,"Sandy, the music's too loud!");
    [057A] breakHere();
    [057B] unless (VAR_HAVE_MSG == 0) goto 057A;                                // Let Dave Talk
    
    [0580] delay(120);
    [0584] walkActorTo(3,9,60);
    [0588] print(3,"SANDY, TURN OFF THE MUSIC!");
    [05A1] breakHere();
    [05A2] unless (VAR_HAVE_MSG == 0) goto 05A1;                                // Let Dave Talk
    
    [05A7] animateActor(24,4,1);                                                // Sandy Face Left
    [05AB] delay(60);
    [05AF] print(24,"Oh!");
    [05B5] delay(120);
    [05B9] walkActorToObject(24,44);                                            // Walk Sandy to Stereo
    [05BC] breakHere();
    [05BD] VAR_RESULT = getActorMoving(24);
    [05C0] unless (VAR_RESULT == 2) goto 05BC;                                  // Wait for Sandy
    
    [05C5] animateActor(24,7,1);                                                // Sandy
    [05C9] delay(15);
    [05CD] setState08(44);                                                      // Open Stereo Cupboard
    [05CF] delay(60);
    [05D3] clearState08(207);                                                   // Turn off Stereo
    [05D5] breakHere();
    [05D6] stopMusic();
    
    [05D7] delay(30);
    [05DB] clearState08(44);                                                    // Close Stereo Cupboard
    [05DD] breakHere();
    [05DE] startSound(8);
    [05E0] delay(30);
    [05E4] unlockSound(27);
    [05E6] walkActorToActor(24,3,4);                                            // 
    [05EA] animateActor(24,4,1);                                                //
    [05EE] print(24,"I'm sorry Dave, I couldn't hear you,/the music was too loud.");
    [0623] breakHere();
    [0624] unless (VAR_HAVE_MSG == 0) goto 0623;                                // Let Sandy Talk
    
    [0629] animateActor(3,254,1);                                               // 'Speaking' enabled, but not switching
    [062D] delay(120);
    [0631] animateActor(3,6,1);                                                 // Dave face camera
    [0635] delay(120);
    [0639] animateActor(3,253,1);
    [063D] breakHere();
    [063E] animateActor(3,5,1);                                                 // Face Right
    [0642] delay(120);
    [0646] print(3,"I was just giving a tour to all these/future game players. Want to come?");
    [0684] breakHere();
    [0685] unless (VAR_HAVE_MSG == 0) goto 0684;                                // Let Dave Talk
    
    [068A] print(24,"Sure Dave, I'll go anywhere with you!");
    [06AC] breakHere();
    [06AD] unless (VAR_HAVE_MSG == 0) goto 06AC;                                // Let Sandy Talk
    
    [06B2] walkActorToObject(3,93);                                             // Walk Dave to Library Door
    [06B5] delay(30);
    [06B9] walkActorToObject(24,93);                                            // Walk Sandy to Library Door
    [06BC] print(3,"Oh yes, in Maniac Mansion,/you not only direct my actions,/but the actions of two of my friends.");
    [070F] breakHere();
    [0710] VAR_RESULT = getActorMoving(3);
    [0713] unless (VAR_RESULT == 2) goto 070F;                                  // Wait for Dave
    
    [0718] animateActor(24,255,1);                                              // Stop Moving
    [071C] breakHere();
    [071D] unless (VAR_HAVE_MSG == 0) goto 071C;                                // Let Dave Talk
    
    [0722] doSentence(1,93,0);                                                  // Open Library Door
    [0726] setCameraAt(VAR_CAMERA_POS_X);
    [0728] delay(60);
    [072C] putActorInRoom(3,5);                                                 // Dave enters Library
    [072F] putActor(3,13,56);                  
    [0733] walkActorTo(24,73,60);                                               // Sandy walk to door
    [0737] breakHere();
    [0738] breakHere();
    [0739] VAR_RESULT = getActorMoving(24);
    [073C] unless (VAR_RESULT == 2) goto 0738;                                  // Wait for Sandy
    
    [0741] breakHere();
    [0742] putActorInRoom(24,5);                                                // Sandy enters library
    [0745] putActor(24,9,56);
    [0749] delay(60);
    [074D] Var[11] = 0;
    [0750] cursorCommand(0);
    [0752] loadRoom(0);
    [0754] loadSound(34);
    [0756] lockSound(34);
    [0758] loadSound(11);
    [075A] lockSound(11);
    [075C] loadScript(10);
    [075E] lockScript(10);
    [0760] loadScript(9);
    [0762] lockScript(9);
    [0764] lockScript(19);
    [0766] loadCostume(13);
    [0768] lockCostume(13);
    [076A] loadRoom(5);                                                         // Enter Library
    [076C] actorFollowCamera(3);                                                // Camera follows Dave
    [076E] Var[11] = 1;
    [0771] cursorCommand(0);
    [0773] walkActorTo(24,12,52);                                               // Walk Sandy to bookshelf
    [0777] breakHere();
    [0778] VAR_RESULT = getActorMoving(24);
    [077B] unless (VAR_RESULT == 2) goto 0777;                                  // Wait for Sandy
    
    [0780] print(3,"This is the library.");
    [0794] breakHere();
    [0795] unless (VAR_HAVE_MSG == 0) goto 0794;                                // Let Dave talk
    
    [079A] setBitVar(VAR_ROOM,1,0);                                             // Library Turn Light On
    [079E] startScript(19);                                                     // start Room Lights: Check for flashlight / room light status
    [07A0] breakHere();
    [07A1] startSound(11);
    [07A3] delay(30);
    [07A7] startScript(9);                                                      // start Sandy: Walk to lamp
    
    [07A9] print(3,"It's one of the many rooms in the game.");
    [07CB] walkActorTo(3,38,66);
    [07CF] breakHere();
    [07D0] VAR_RESULT = getActorMoving(3);
    [07D3] unless (VAR_RESULT == 2) goto 07CF;                                  // Wait for Dave
    
    [07D8] animateActor(3,6,1);                                                 // Dave face right
    [07DC] breakHere();
    [07DD] unless (VAR_HAVE_MSG == 0) goto 07DC;                                // Let Dave talk
    
    [07E2] startScript(13);
    [07E4] print(3,"And there are more than 450 objects...");
    [0807] breakHere();
    [0808] unless (VAR_HAVE_MSG == 0) goto 0807;                                // Let Dave talk
    
    [080D] animateActor(3,5,1);                                                 // Face Right
    [0811] panCameraTo(50);
    [0813] delay(120);
    [0817] animateActor(3,6,1);                                                 // Dave face right
    [081B] breakHere();
    [081C] print(3,"...that you can use to solve over...");
    [083D] breakHere();
    [083E] unless (VAR_HAVE_MSG == 0) goto 083D;                                // Let Dave talk
    
    [0843] animateActor(3,5,1);                                                 // Face Right
    [0847] delay(120);
    [084B] animateActor(3,6,1);                                                 // Dave face right
    [084F] breakHere();
    [0850] print(3,"Just a second.");
    [085F] breakHere();
    [0860] unless (VAR_HAVE_MSG == 0) goto 085F;                                // Let Dave talk
    
    [0865] walkActorTo(3,50,64);
    [0869] breakHere();
    [086A] VAR_RESULT = getActorX(3);
    [086D] unless (VAR_RESULT > 48) goto 0869;                                  // Walk for Dave to be > 48
    
    [0872] walkActorTo(3,65,64);
    [0876] breakHere();
    [0877] VAR_RESULT = getActorMoving(3);
    [087A] unless (VAR_RESULT == 2) goto 0876;                                  // Wait for Dave
    
    [087F] animateActor(3,7,1);                                                 // Face Away
    [0883] breakHere();
    [0884] setState08(103);                                                     // Phone off hook
    [0886] stopScript(13);
    [0888] stopSound(19);
    [088A] delay(30);
    [088E] print(3,"Hello?");
    [0897] delay(180);
    
    [089B] animateActor(3,5,1);                                                 // Dave face right
    [089F] print(3,"Hello, who's there?");
    [08B3] putActorInRoom(13,5);                                                // Purple Tentacle enters
    [08B6] putActor(13,10,60);
    [08BA] startScript(10);                                                     // start Purple Tentacle walk to Sandy
    [08BC] delay(120);
    
    [08C0] animateActor(24,4,1);                                                // Sandy turn left
    [08C4] breakHere();
    [08C5] animateActor(24,254,1);                                              // Sandy mouth open
    [08C9] breakHere();
    [08CA] breakHere();
    [08CB] walkActorTo(24,10,50);                                               // Sandy Walk to bottom left (around stairs)
    [08CF] delay(180);
    [08D3] print(3,"Is this a prank phone call?");
    [08EC] breakHere();
    [08ED] VAR_RESULT = getActorX(13);
    [08F0] unless (VAR_RESULT <= 28) goto 08EC;                                 // Wait for Purple to be <= 28
    
    [08F5] stopScript(10);                                                      // stop Purple Tentacle walk to Sandy
    [08F7] startSound(24);
    [08F9] delay(30);
    [08FD] animateActor(3,7,1);                                                 // Dave face away
    [0901] breakHere();
    [0902] clearState08(103);                                                   // Phone on hook
    [0904] breakHere();
    [0905] startSound(8);
    [0907] delay(30);
    [090B] animateActor(3,4,1);                                                 // Dave face left
    [090F] breakHere();    
    [0910] print(3,"Sandy?");
    [0919] delay(180);                                                          // Wait 3 seconds
    [091D] print(3,"SANDY!");
    [0926] delay(180);                                                          // Wait 3 seconds
    [092A] actorFollowCamera(3);
    [092C] animateActor(3,6,1);                                                 // Dave face camera
    [0930] breakHere();
    [0931] print(3,"Oh great! Not again!!/Time to round up the Gang.");
    [095C] breakHere();
    [095D] unless (VAR_HAVE_MSG == 0) goto 095C;                                // Let Dave Talk
    
    [0962] delay(180);
    [0966] Var[11] = 0;
    [0969] cursorCommand(0);
    [096B] endcutscene();                                                       // End Cutscene
    [096C] restart();                                                           // Restart Engine
    [096D] stopObjectCode();
}

/**
 * Script 7: Edison Family Cutscene
 **/
Script-7 {                                                                                                                                                                                                                                                  
    [0000] loadSound(34);
    [0002] lockSound(34);
    [0004] loadScript(8);
    
    [0006] putActorInRoom(9,31);                                                // Dr. Fred Enters
    [0009] putActor(9,20,63);
    
    [000D] putActorInRoom(10,31);                                               // Nurse Edna enters
    [0010] putActor(10,4,68);
    
    [0014] putActorInRoom(11,31);                                               // Weird Ed enters
    [0017] putActor(11,34,50);
    
    [001B] putActorInRoom(13,31);                                               // Purple Tentacle enters
    [001E] putActor(13,45,63);
    
    [0022] lockCostume(13);
    [0024] animateActor(10,5,1);                                                // Nurse Edna face right
    [0028] animateActor(11,7,1);                                                // Weird Ed face away
    [002C] loadRoom(31);
    [002E] Var[11] = 1;
    [0031] cursorCommand(0);
    [0033] setCameraAt(20);                        
    [0035] startScript(8);                                                      // start Dr Fred: Walk back and forth (Lab Entry)
    [0037] delay(300);
    
    [003B] print(10,"How long do we have to stay down here?");
    [005C] breakHere();
    [005D] unless (VAR_HAVE_MSG == 0) goto 005C;                                // Let Nurse Edna talk
    
    [0062] delay(60);
    [0066] stopScript(8);                                                       // stop Dr Fred: Walk back and forth (Lab Entry)
    [0068] walkActorTo(9,15,63);                                   
    [006C] breakHere();
    [006D] VAR_RESULT = getActorMoving(9);
    [0070] unless (VAR_RESULT == 2) goto 006C;                                  // Wait for Dr. Fred
    
    [0075] breakHere();
    [0076] animateActor(9,6,1);                                                 // Dr. Fred Face camera
    [007A] delay(120);
    [007E] animateActor(9,4,1);                                                 // Dr. Fred Face Left
    [0082] print(9,"Shh... I think I hear something!");
    [00A0] breakHere();
    [00A1] unless (VAR_HAVE_MSG == 0) goto 00A0;                                // Let Dr. Fred talk
    
    [00A6] animateActor(11,4,1);                                                // Weird Ed Face Left
    [00AA] print(11,"I miss my hamster.");
    [00BC] breakHere();
    [00BD] unless (VAR_HAVE_MSG == 0) goto 00BC;
    
    [00C2] walkActorToActor(9,11,5);                                            // Walk Dr. Fred to Weird Ed
    [00C6] breakHere();
    [00C7] breakHere();
    [00C8] animateActor(9,255,1);                                               // Stop Moving
    [00CC] breakHere();
    [00CD] animateActor(9,5,1);                                                 // Dr. Fred Face Right
    [00D1] print(9,"Quiet! I think I hear someone upstairs!");
    [00F5] breakHere();
    [00F6] unless (VAR_HAVE_MSG == 0) goto 00F5;                                // Wait for Dr. Fred
    
    [00FB] walkActorToActor(10,11,4);                                           // Walk Nurse Edna
    [00FF] print(10,"Oh great! Who forgot to lock the door?");
    [0121] breakHere();
    [0122] unless (VAR_HAVE_MSG == 0) goto 0121;
    
    [0127] animateActor(11,7,1);                                                // Weird Ed Face Away
    [012B] delay(60);
    [012F] walkActorToActor(9,13,5);                                            // Dr. Fred Walk to Purple Tentacle
    [0133] print(9,"PURPLE TENTACLE!");
    [0145] breakHere();
    [0146] breakHere();
    [0147] animateActor(9,255,1);                                               // Stop Moving
    [014B] breakHere();
    [014C] unless (VAR_HAVE_MSG == 0) goto 014B;                                // Let Dr. Fred Talk
    
    [0151] walkActorToActor(13,9,4);                                            // Walk Purple to Dr. Fred
    [0155] breakHere();
    [0156] VAR_RESULT = getActorMoving(13);
    [0159] unless (VAR_RESULT == 2) goto 0155;                                  // Wait for Purple Tentacle
    
    [015E] print(13,"Yes sir, Dr. Fred SIR!");
    [0173] breakHere();
    [0174] unless (VAR_HAVE_MSG == 0) goto 0173;                                // Let Purple Tentacle Talk
    
    [0179] print(9,"Go upstairs and check it out!");
    [0194] breakHere();
    [0195] unless (VAR_HAVE_MSG == 0) goto 0194;                                // Let Purple Tentacle Talk
    
    [019A] print(13,"Yes sir!");
    [01A4] startScript(8);                                                      // start Dr Fred: Walk back and forth (Lab Entry)
    [01A6] walkActorToObject(13,133);                                           // Walk Purple to Lab Door
    [01A9] breakHere();
    [01AA] VAR_RESULT = getActorMoving(13);
    [01AD] unless (VAR_RESULT == 2) goto 01A9;                                  // Wait for Purple Tentacle
    
    [01B2] setState08(133);                                                     // Open Lab Door
    [01B4] startSound(4);
    [01B6] delay(60);
    
    [01BA] putActorInRoom(13,0);                                                // Purple Tentacle leaves room
    [01BD] putActor(13,0,0);
    [01C1] clearState08(133);                                                   // Close Lab Door
    [01C3] startSound(8);
    [01C5] walkActorTo(11,34,70);                                               // Walk Weird Ed to Camera
    [01C9] actorFollowCamera(11);                                               // Camera Follow Weird Ed
    [01CB] delay(60);
    
    [01CF] animateActor(10,6,1);                                                // Nurse Edna Face camera
    [01D3] breakHere();
    [01D4] VAR_RESULT = getActorMoving(11);
    [01D7] unless (VAR_RESULT == 2) goto 01D3;                                  // Wait for Weird Ed
    
    [01DC] print(11,"I really DO miss my hamster!");
    [01F6] breakHere();
    [01F7] unless (VAR_HAVE_MSG == 0) goto 01F6;                                // Let Weird Ed Talk
    
    [01FC] delay(60);
    [0200] Var[11] = 0;
    [0203] cursorCommand(0);
    [0205] loadRoom(0);
    [0207] stopScript(8);                                                       // stop Dr Fred: Walk back and forth (Lab Entry)
    [0209] stopObjectCode();
}

/**
 * Script 8: Dr Fred: Walk back and forth (Lab Entry)
 */
Script-8 {                                                                                                                                                                                                                                                  
    [0000] walkActorTo(9,30,63);                                                // Walk Dr. Fred to Right
    [0004] breakHere();
    [0005] breakHere();
    [0006] VAR_RESULT = getActorMoving(9);
    [0009] unless (VAR_RESULT == 2) goto 0005;                                  // Wait for Dr. Fred
    
    [000E] animateActor(9,6,1);                                                 // Dr. Fred Face camera
    [0012] breakHere();
    [0013] walkActorTo(9,10,63);                                                // Walk Dr. Fred to Left
    [0017] breakHere();
    [0018] breakHere();
    [0019] VAR_RESULT = getActorMoving(9);
    [001C] unless (VAR_RESULT == 2) goto 0018;                                  // Wait for Dr. Fred
    
    [0021] animateActor(9,7,1);                                                 // Dr. Fred Face Away
    [0025] breakHere();
    [0026] goto 0000;
    [0029] stopObjectCode();
}

/**
 * Script 9: Sandy walks to lamp
 **/
Script-9 {                                                                                                                                                                                                                                                  
    [0000] Var[92] = 4;
    [0003] Var[52] = 17;
    [0006] walkActorTo(24,Var[52],50);                                          // Walk Sandy to lamp
    [000A] breakHere();
    [000B] VAR_RESULT = getActorMoving(24);
    [000E] unless (VAR_RESULT == 2) goto 000A;                                  // Wait for Sandy
    
    [0013] animateActor(24,7,1);                                                // Sandy Face Away
    [0017] Var[52] += 5;
    [001A] Var[92] -= 1;
    [001D] delay(240);
    [0021] unless (Var[92] == 0) goto 0006;                                     // Loop
    
    [0026] stopObjectCode();
}
/**
 * Script 10: Purple Tentacle walk to Sandy
 */Script-10 {                                                                                                                                                                                                                                                 
    [0000] breakHere();
    [0001] walkActorToActor(13,24,2);                                           // Walk Purple Tentacle to Sandy
    [0005] goto 0000;
    [0008] stopObjectCode();
}
/**
 * Script 11: Clock: Repeating Tick Sound
 */Script-11 {                                                                                                                                                                                                                                                 
    [0000] delay(120);
    [0004] startSound(22);
    [0006] delay(90);
    [000A] goto 0004;
    [000D] stopObjectCode();
}

/**
 * Script 12: Pin: Entry - Phone LucasFilm
 */Script-12 {                                                                                                                                                                                                                                                 
    [0000] startScript(16);                                                     // Phone: Disconnect if Kid walks too far away
    [0002] startSound(17);
    [0004] delay(120);
    [0008] stopSound(17);
    [000A] Var[44] = 1;                                                         // Pin1 = Telephone Number: Edna 1/4
    [000D] Var[45] = 1;                                                         // Pin2 = Telephone Number: Edna 2/4
    [0010] Var[46] = 3;                                                         // Pin3 = Telephone Number: Edna 3/4
    [0013] Var[47] = 8;                                                         // Pin4 = Telephone Number: Edna 4/4
    [0016] startScript(18);                                                     // start Keypad Input
    [0018] breakHere();
    [0019] unless (Var[50] == 0) goto 0018;    
    
    [001E] if (Var[48] == 0) {                                                  // Correct Number?
    [0023]   loadScript(48);                                                    // load Phone LucasFilm
    [0025]   startScript(13);                                                   // start Phone: Ringing
    [0027]   delay(360);                                   
    [002B]   stopScript(13);                                                    // 
    [002D]   startScript(48);                                                   // start Demo: Advertisement Recording
    [002F]   Var[136] = 1;                                                      // On Phone = true
    [0032] } else {
    [0035]   startScript(14);                                                   //  start Phone: Busy Signal
    [0037] }
    [0037] stopObjectCode();
}

 /**
  * Script 13: Phone: Ringing
  */Script-13 {                                                                                                                                                                                                                                                 
    [0000] if (VAR_ROOM == 5) {
    [0005]   startSound(19);
    [0007] }
    [0007] delay(240);
    [000B] goto 0000;
    [000E] stopObjectCode();
}

 /**
  * Script 14: Phone: Busy Signal
  */Script-14 {                                                                                                                                                                                                                                                 
    [0000] if (VAR_ROOM == 5) {
    [0005]   startSound(18);
    [0007] }
    [0007] delay(30);
    [000B] goto 0000;
    [000E] stopObjectCode();
}

 /**
  * Script 15: Phone: Disconnect
  */Script-15 {                                                                                                                                                                                                                                                 
    [0000] clearState08(103);                                                   // Phone
    [0002] Var[17] = 0;                                                         //
    [0005] stopScript(12);                                                      //  stop Pin: Entry - Phone LucasFilm
    [0007] if (Var[136] == 1) {                                                 // on Phone?
    [000C]   stopScript(48);                                                    // stop Phone LucasFilm
    [000E]   Var[136] = 0;                                                      // On Phone = no
    [0011]   print(255," ");                                                    // 
    [0015] }                                                                    // 
    [0015] stopSound(17);                                                       // 
    [0017] stopScript(14);                                                      // 
    [0019] stopSound(18);
    [001B] stopScript(13);
    [001D] stopScript(17);
    [001F] stopObjectCode();
}

 /**
  * Script 16: Phone: Disconnect if Kid walks too far away
  */Script-16 {                                                                                                                                                                                                                                                 
    [0000] setState08(103);
    [0002] Var[51] = VAR_EGO;
    [0005] Var[52] = getActorX(Var[51]);
    [0008] Var[53] = getActorY(Var[51]);
    [000B] breakHere();
    [000C] VAR_RESULT = getActorX(Var[51]);
    [000F] if (VAR_RESULT == Var[52]) {
    [0014]   VAR_RESULT = getActorY(Var[51]);
    [0017]   if (VAR_RESULT == Var[53]) {
    [001C]     goto 000B;
    [001F]   }
    [001F] }
    [001F] startScript(15);
    [0021] stopObjectCode();
}

/**
 * Script 17: Phone: Ringing
 */Script-17 {                                                                                                                                                                                                                                                 
    [0000] if (VAR_ROOM == 5) {
    [0005]   startSound(20);
    [0007] }
    [0007] delay(240);
    [000B] goto 0000;
    [000E] stopObjectCode();
}

/**
 * Script 18: Keypad Input
 **/Script-18 {                                                                                                                                                                                                                                                 
    [0000] Var[50] = 1;
    [0003] Var[48] = 0;                                                         // Pin Entry is Correct
    [0006] breakHere();                                              
    [0007] cursorCommand(1);                                                    // Keypad Mode
    [0009] loadRoom(43);                                                        // Enter Keypad room
    [000B] setCameraAt(20);                                          
    [000D] Var[49] = 255;                                            
    [0010] breakHere();                                              
    [0011] unless (Var[49] != 255) goto 0010;                                   // Wait for keypad input
    
    [0016] if (Var[49] != Var[44]) {                                            // Pin Match?
    [001B]   Var[48] = 1;                                            
    [001E] }                                                         
    [001E] Var[49] = 255;                                            
    [0021] breakHere();                                              
    [0022] unless (Var[49] != 255) goto 0021;                                   // Wait for keypad input
    
    [0027] if (Var[49] != Var[45]) {                                            // Pin Match?
    [002C]   Var[48] = 1;                                            
    [002F] }                                                         
    [002F] Var[49] = 255;                                            
    [0032] breakHere();                                              
    [0033] unless (Var[49] != 255) goto 0032;                                   // Wait for keypad input
    
    [0038] if (Var[49] != Var[46]) {                                            // Pin Match?
    [003D]   Var[48] = 1;                                            
    [0040] }                                                         
    [0040] Var[49] = 255;                                            
    [0043] breakHere();                                              
    [0044] unless (Var[49] != 255) goto 0043;                                   // Wait for keypad input
    
    [0049] if (Var[49] != Var[47]) {                                            // Pin Match?
    [004E]   Var[48] = 1;                                            
    [0051] }                                                         
    [0051] Var[50] = 0;                                              
    [0054] cursorCommand(3);                                                    // Cutscene Mode Normal
    [0056] actorFollowCamera(VAR_EGO);
    [0058] stopObjectCode();
}

 /**
  * Script 19: Room Lights: Check for flashlight / room light status
  */Script-19 {                                                                                                                                                                                                                                                 
    [0000] Var[92] = 0;
    [0003] Var[90] = getObjectOwner(51);                                        // Get owner of Flashlight
    [0006] VAR_RESULT = getActorRoom(Var[90]);                       
    [0009] if (VAR_RESULT == VAR_ROOM) {                                        // Flashlight owner in current room?
    [000E]   if (Var[12] == 1) {                                                //  Fliashlight on?
    [0013]     Var[92] = 1;                                                     //  Light level
    [0016]   }                                                       
    [0016] }                                                         
    [0016] if (!getState08(124)) {                                              // Circuit Breaker On?
    [001A]   VAR_RESULT = getBitVar(VAR_ROOM,1);                                //  Current Room Light On?
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
 * Script 20: Repeat Outside Sound
 **/Script-20 {                                                                                                                                                                                                                                                 
    [0000] breakHere();
    [0001] unless (VAR_IS_SOUND_RUNNING == 0) goto 0000;                        //  Wait for sound to finish
    
    [0006] startSound(25);                                                      //  Play sound
    [0008] delay(360);
    [000C] goto 0006;                                                           // Loop forever
    [000F] stopObjectCode();
}

/** 
 * Script 21: Microwave
 */Script-21 {                                                                                                                                                                                                                                                 
    [0000] loadSound(13);
    [0002] loadSound(12);
    [0004] startSound(13);                                                      // Rotate Sound
    [0006] delay(240);
    [000A] stopSound(13);                                                       // Stop Rotate Sound
    [000C] startSound(12);                                                      // Play Microwave Bing
    [000E] if (getState08(50)) {                                                // Jar of water
    [0012]   startScript(23);                                                   //  < Delays 3600 then Stops >
    [0014] }
    [0014] stopObjectCode();
}

/**
 * Script 22: Microwave: Put item in
 */Script-22 {                                                                                                                                                                                                                                                 
    [0000] if (activeObject2 == 99) {                                           // Is ActiveObject Glass Jar
    [0004]   if (getState08(activeObject)) {                                    //  Is Microwave door open?
    [0007]     if (Var[66] != 1) {                                              //   Item in Microwave is not Hamster
    [000C]       if (Var[22] == 0) {                                            //    Is Glass Jar Empty
    [0011]         printEgo("I'd better fill it first.");
    [0028]       } else {
    [002B]         setOwnerOf(99,14);                                           //     Set owner of GlassJar to Green Tentacle
    [002E]         setState08(50);                                              //     Set Jar of Water
    [0030]         clearState02(50);                                            //     Clear kObjectStateUntouchable on jar of water
    [0032]         Var[66] += 4;
    [0035]       }
    [0035]     } else {
    [0038]       printEgo_c64("");
    [003B]     }
    [003B]   } else {
    [003E]     startScript(30);                                                 // start Print "The door is closed"
    [0040]   }
    [0040] } else {
    [0043]   printEgo("I'd better not.");
    [0052] }
    [0052] stopScript(0);
    [0054] stopCurrentScript();
    
    [0055] Var[39] = getDist(115,Var[32]);
    [0059] putActor(108,Var[114],Var[101]);
    [005D] putActor(100,Var[121],Var[32]);
    [0061] Var[117] = getClosestObjActor25(108);
    [0064] stopCurrentScript();
    [0065] print_c64(0,"  ");
}
 /**
  * Script 23: Timer: 1 Minute
  */Script-23 {                                                                                                                                                                                                                                                 
    [0000] delay(3600);
    [0004] stopObjectCode();
}

 /**
  * Script 24: Cutscene: Kid Dies
  */Script-24 {                                                                                                                                                                                                                                                 
    [0000] breakHere();
    [0001] cutscene();                                                          // Start Cutscene
    [0002] if (Var[76] == 1) {                                                  // Death Method == Radioactive Steam
    [0007]   printEgo("Oh no! Radioactive steam! Ahheeeeeeee%");                //
    [002B]   animateActor(VAR_EGO,4,1);                                         // Kid Face Left
    [002F]   breakHere();  
    [0030]   animateActor(VAR_EGO,6,1);                                         // Kid Face camera
    [0034]   breakHere();  
    [0035]   animateActor(VAR_EGO,5,1);                                         // Kid Face Right
    [0039]   breakHere();  
    [003A]   animateActor(VAR_EGO,7,1);                                         // Kid Face Away
    [003E]   breakHere();  
    [003F]   Var[52] = getRandomNr(70);    
    [0042]   Var[53] = getRandomNr(12);    
    [0045]   Var[53] += 56;    
    [0048]   walkActorTo(VAR_EGO,Var[52],Var[53]); 
    [004C]   unless (VAR_HAVE_MSG == 0) goto 002B;                              // Loop kid spinning
    
    [0051]   Var[77] = VAR_EGO;    
    [0054] }   
    [0054] setActorBitVar(Var[77],128,1);  
    [0058] setActorBitVar(Var[77],64,1);   
    [005C] Var[90] = 253;                                                       // Radiation Suit
    [005F] VAR_RESULT = getObjectOwner(Var[90]);   
    [0062] if (VAR_RESULT == Var[77]) {                                         // 
    [0067]   setOwnerOf(Var[90],0);                                             // object owner by no-one
    [006A] }   
    [006A] Var[90] -= 1;                                                        // Next object
    [006D] unless (Var[90] == 0) goto 005F;                                     // Loop all objects, remove ones owned by kid
    
    [0072] Var[78]++;                                                           // Kid Death Count + 1
    [0074] if (Var[77] == 3) {                                                  // Is Kid Dave
    [0079]   Var[96] = 1;                                                       //  Dave is dead
    [007C] }
    [007C] if (Var[78] == 1) {                                                  // Is one kid dead
    [0081]   clearState08(29);                                                  //  Show Tombstone 1
    [0083]   clearState02(29);                                                  //  Show Tombstone 1
    [0085]   putActorInRoom(Var[77],1);
    [0088]   putActor(Var[77],106,60);
    [008C] }
    [008C] if (Var[78] == 2) {                                                  // Are two kids dead
    [0091]   clearState08(30);                                                  //  Show Tombstone 2
    [0093]   clearState02(30);                                                  //  Show Tombstone 2
    [0095]   putActorInRoom(Var[77],1);
    [0098]   putActor(Var[77],114,60);
    [009C] }
    [009C] if (Var[78] == 3) {                                                  // Are three kids dead
    [00A1]   clearState08(31);                                                  //  Show Tombstone 3
    [00A3]   clearState02(31);                                                  //  Show Tombstone 3
    [00A5]   putActorInRoom(Var[77],1);
    [00A8]   putActor(Var[77],122,60);
    [00AC] }
    [00AC] Var[90] = getActorX(Var[77]);                                        // 
    [00AF] loadRoom(1);                                                         // Load Front of Mansion
    [00B1] setCameraAt(Var[90]);                                                // Set camera to kid x
    [00B3] delay(360);
    [00B7] endcutscene();                                                       // end Cutscene
    [00B8] if (Var[78] == 3) {                                                  // If three kids are dead
    [00BD]   startScript(25);                                                   //  start Cutscene: Game Over
    [00BF] }
    [00BF] cursorCommand(3);
    [00C1] stopObjectCode();
}

 /**
  * Script 25: Cutscene: Game Over
  */Script-25 {                                                                                                                                                                                                                                                 
    [0000] cutscene();                                                          // Start Cutscene
    [0001] startMusic(30);
    [0003] delay(120);
    [0007] print(255,"        All the kids have died./     The rescue attempt has failed./Lucky this isn't a real game,/or Sandy would be doomed to zombiehood!");
    [0079] breakHere();
    [007A] unless (VAR_HAVE_MSG == 0) goto 0079;                                // Wait for text
    
    [007F] Var[90] = 0;
    [0082] delay(300);
    [0086] print(255,"            THE GAME IS OVER");
    [009C] delay(300);
    [00A0] print(255,"        Press f7 to play again.");
    [00BA] unless (VAR_IS_SOUND_RUNNING == 0) goto 0082;                        // Wait for music
    
    [00BF] loadRoom(0);
    [00C1] stopMusic();
    [00C2] restart();                                                           // Restart
    [00C3] endcutscene();                                                       // Start Cutscene
    [00C4] stopObjectCode();
}

/**
 * Script 30: Print "The door is closed"
 */
Script-30 {
    [0000] printEgo("The door is closed.");
    [0012] stopObjectCode();
}
/**
 * Script 31: Print "The door is locked"
 */Script-31 {                                                                                                                                                                                                                                                 
    [0000] printEgo("The door is locked.");
    [0012] stopObjectCode();
}

/**
 * Script 33: Print "I can't unlock the door with this."
 */
Script-33 {
    [0000] printEgo("I can't unlock the door with this.");
    [001E] stopObjectCode();
}

/**
 * Script 36: Microwave
 */Script-36 {                                                                                                                                                                                                                                                 
    [0000] if (getState08(activeObject)) {                                      //
    [0003]   clearState08();                                                    //
    [0004] }
    [0004] if (getState08(124)) {                                               // If Circuit breaker off
    [0008]   printEgo("The power's off.");
    [0018] } else {
    [001B]   if (Var[66] == 0) {                                                //  If Microwave contents = Empty
    [0020]     printEgo("I shouldn't turn on an empty microwave.");
    [0043]   }
    [0043]   if (Var[66] > 2) {                                                 //  if contents >= Liquid 
    [0048]     startScript(21);
    [004A]   }
    [004A] }
    [004A] stopObjectCode();
}
/**
 * Script 37: Facet: Fill Gar/Sponge with Water
 */
Script-37 {
    [0000] if (activeObject2 == 99) {                                           // if Glass Jar
    [0004]   Var[22] = 1;                                                       // Glass Jar Contents = water
    [0007]   startScript(38);                                                   // start Sponge: Name
    [0009] }
    [0009] stopObjectCode();
}

/**
 * Script 38: Glass Jar: Name
 */Script-38 {                                                                                                                                                                                                                                                 
    [0000] if (Var[22] == 0) {                                                  // if Glass Jar Contents == Empty
    [0005]   setObjectName(355,"glass jar");
    [0011] }
    [0011] if (Var[22] == 2) {                                                  // if Glass Jar Contents == Developer
    [0016] } else {
    [0019]   unless (Var[22] == 1) goto 002D;                                   // if Glass Jar Contents == water
    
    [001E] }
    [001E] setObjectName(355,"jar of water");
    [002D] stopObjectCode();
}

 /**
  * Script 39: Sponge: Name
  */Script-39 {                                                                                                                                                                                                                                                 
    [0000] if (Var[22] == 2) {                                                  // if Glass Jar Contents == Developer
    [0005] } else {
    [0008]   unless (Var[22] == 1) goto 001C;                                   // if Glass Jar Contents == water
    
    [000D] }
    [000D] setObjectName(306,"jar of water");
    [001C] stopObjectCode();
}

 /**
  * Script 40: Flashlight: Name
  */
Script-40 {
    [0000] if (Var[12] == 1) {                                                  // if Flashlight on
    [0005]   setObjectName(307,"lit flashlight");
    [0016] } else {
    [0019]   setObjectName(307,"flashlight");
    [0026] }
    [0026] startScript(19);                                                     // start Room Lights: Check for flashlight / room light status
    [0028] stopObjectCode();
}

 /**
  * Script 41: Cutscene: Dr. Fred & Weird Ed (Doorbell)
  */Script-41 {                                                                                                                                                                                                                                                 
    [0000] cutscene();                                                          // Start Cutscene
    [0001] loadScript(8);
    [0003] putActorInRoom(9,31);                                                // Dr. Fred Enters
    [0006] putActor(9,20,63);
    
    [000A] putActorInRoom(11,31);                                               // Weird Ed Enters
    [000D] putActor(11,34,50);
    
    [0011] animateActor(11,7,1);                                                // Weird Ed Face Away
    [0015] loadRoom(31);                                                        // Enter Lab: Entry
    
    [0017] setCameraAt(22);                                        
    [0019] startScript(8);                                                      // start Dr Fred: Walk back and forth (Lab Entry)
    [001B] delay(60);
    [001F] animateActor(11,4,1);                                                // Weird Ed Face Left
    [0023] breakHere();
    [0024] animateActor(11,6,1);                                                // Weird Ed Face camera
    [0028] breakHere();
    [0029] if (Var[68] == 0) {                                                  // if DoorBell Count == 0
    [002E]   print(11,"Oh no! It's the doorbell!");
    [0046]   breakHere();
    [0047]   unless (VAR_HAVE_MSG == 0) goto 0046;                              //  Wait for Ed
    
    [004C]   walkActorTo(11,34,63);                                             //  Walk Weird Ed
    [0050]   breakHere();
    [0051]   VAR_RESULT = getActorMoving(11);
    [0054]   unless (VAR_RESULT == 2) goto 0050;                                //  Wait for Weird Ed
    
    [0059]   animateActor(11,4,1);                                              //  Weird Ed Face Left
    [005D]   breakHere();
    [005E]   print(11,"Daddy, can I go see who it is?");
    [0078]   breakHere();
    [0079]   unless (VAR_HAVE_MSG == 0) goto 0078;                              //  Let Weird Ed Talk
    
    [007E]   stopScript(8);                                                     //  stop Dr Fred: Walk back and forth (Lab Entry)
    [0080]   animateActor(9,255,1);                                             //  Stop Moving
    [0084]   breakHere();
    [0085]   walkActorToActor(9,11,4);                                          //  Dr. Fred walk
    [0089]   breakHere();
    [008A]   breakHere();
    
    [008B]   animateActor(9,255,1);                                             //  Dr. Fred Stop Moving
    [008F]   print(9,"No. We have to stay downstairs%/%until they buy the game!");
    [00C2]   breakHere();
    [00C3]   unless (VAR_HAVE_MSG == 0) goto 00C2;
    
    [00C8]   startScript(8);                                                    //  start Dr Fred: Walk back and forth (Lab Entry)
    [00CA]   animateActor(11,6,1);                                              //  Weird Ed Face camera
    [00CE]   delay(60);
    [00D2]   print(11,"Better go buy it!");
    [00E3]   breakHere();
    [00E4]   unless (VAR_HAVE_MSG == 0) goto 00E3;                              //  Let Weird Ed Talk
    
    [00E9] } else {
    [00EC]   print(11,"Daddy!!! They rang it again!");
    [0107]   breakHere();
    [0108]   unless (VAR_HAVE_MSG == 0) goto 0107;;                             //  Let Weird Ed Talk
    
    [010D]   walkActorTo(11,34,63);
    [0111]   breakHere();
    [0112]   VAR_RESULT = getActorMoving(11);
    [0115]   unless (VAR_RESULT == 2) goto 0111;                                //  Wait for Weird Ed
    
    [011A]   animateActor(11,4,1);                                              //  Weird Ed Face Left
    [011E]   breakHere();
    [011F]   if (Var[68] == 1) {                                                //  if Second Ring of Doorbell?
    [0124]     print(11,"Please let me go, Daddy.");
    [013B]     breakHere();
    [013C]     unless (VAR_HAVE_MSG == 0) goto 013B;;                           //   Let Weird Ed Talk
    
    [0141]     stopScript(8);                                                   //   stop Dr Fred: Walk back and forth (Lab Entry)
    [0143]     animateActor(9,255,1);                                           //   Stop Moving
    [0147]     print(11,"Please, please, please?");
    [015F]     breakHere();
    [0160]     unless (VAR_HAVE_MSG == 0) goto 015F;
    
    [0165]     delay(60);
    [0169]     animateActor(9,6,1);                                             //   Dr. Fred Face camera
    [016D]     delay(60);
    [0171]     print(9,"Listen,/I can't take much more of his whining./You'd better go buy the game!");
    [01B4]     breakHere();
    [01B5]     unless (VAR_HAVE_MSG == 0) goto 01B4;                            //   Let Dr. Fred talk
    
    [01BA]   } else {                                                           //  Third Ring of Doorbell?
    [01BD]     print(11,"D A D D Y Y Y Y!!!!!!!!");
    [01D0]     breakHere();
    [01D1]     unless (VAR_HAVE_MSG == 0) goto 01D0;;                           //   Let Weird Ed Talk
    
    [01D6]     stopScript(8);                                                   //   stop Dr Fred: Walk back and forth (Lab Entry)
    [01D8]     animateActor(9,255,1);                                           //   Dr. Fred Stop Moving
    [01DC]     breakHere();
    [01DD]     animateActor(9,6,1);                                             //   Face camera
    [01E1]     delay(120);
    [01E5]     animateActor(9,254,1);                                           //   Dr. Fred mouth open
    [01E9]     breakHere();
    [01EA]     print(255,"Grrrrrrrrr!!!");
    [01FA]     breakHere();
    [01FB]     unless (VAR_HAVE_MSG == 0) goto 01FA;                            //   Let Dr. Fred Growl
    
    [0200]     animateActor(9,253,1);                                           //   Dr. Fred mouth closed
    [0204]   }
    [0204] }
    [0204] delay(120);
    [0208] stopScript(8);                                                       // stop Dr Fred: Walk back and forth (Lab Entry)
    [020A] endcutscene();                                                       // end Cutscene
    [020B] Var[68] += 1;                                                        // Doorbell count + 1
    [020E] if (Var[68] > 2) {
    [0213]   Var[68] = 2;                                                       // Max of 2
    [0216] }
    [0216] stopObjectCode();
}

/**
 * Script 44: Cutscene: Intro: Comet / Mansion
 */Script-44 {                                                                                                                                                                                                                                                 
    [0000] cutscene();                                                          // Start Cutscene
    [0001] clearState08(11);                                       
    [0003] clearState08(10);                                       
    [0005] clearState08(9);                                        
    [0007] clearState08(8);                                        
    [0009] clearState08(7);                                        
    [000B] loadCostume(22);                                        
    [000D] lockCostume(22);                                        
    [000F] loadRoom_c64(49);                                                    // "MANIAC MANSION" Scrolling
    [0011] lockRoom(49);                                          
    [0013] loadScript(45);                                                      // Camera at right of room
    [0015] lockScript(45);                                                      // Comet
    [0017] loadSound(32);                                          
    [0019] loadRoom(33);                                                        // Mansion At Distance (Lights Off)
    [001B] setCameraAt(60);                                                     // Camera at right of room
    [001D] Var[11] = 1;                                            
    [0020] cursorCommand(0);                                       
    [0022] startSound(31);                                                      // Comet
    [0024] delay(120);                                             
    [0028] print(255,"Twenty years ago today...");                 
    [0041] delay(180);                                             
    [0045] startScript(45);                                                     // Start Intro: Comet: Fly and Crash
    [0047] breakHere();                                            
    [0048] VAR_RESULT = isScriptRunning(45);                       
    [004B] unless (VAR_RESULT == 0) goto 0047;                                  // Sleep until 'Intro: Comet: Fly and Crash' finishes
    
    [0050] delay(60);                                              
    [0054] startMusic(33);  
    
    [0056] setState08(11);                                                      // Lights on
    [0058] breakHere();                                            
    
    [0059] setState08(10);                                                      // Lights on
    [005B] breakHere();                                            
    
    [005C] setState08(9);                                                       // Lights on
    [005E] breakHere();                                            
    
    [005F] setState08(8);                                                       // Lights on
    [0061] breakHere();                                            
    
    [0062] setState08(7);                                                       // Lights on
    [0064] delay(180);                                                          // Sleep 3 seconds
    [0068] print(255,"      A Lucasfilm Games Production");        
    [0087] delay(180);                                                          // Sleep 3 seconds
    [008B] print(255,"        Designed and written by");
    [00A6] delay(120);
    [00AA] print(255,"      Ron Gilbert and Gary Winnick");
    [00C8] delay(240);
    [00CC] print(255,"             Programmed by");
    [00E2] delay(120);
    [00E6] print(255,"  Ron Gilbert, David Fox, and Carl Mey");
    [0108] delay(240);
    [010C] print(255,"   Art and animation by Gary Winnick");
    [012D] delay(180);                                                          // Sleep 3 seconds
    [0131] print(255,"      Sound effects by Chris Grigg");        
    [014F] delay(180);                                                          // Sleep 3 seconds
    [0153] print(255,"           Original music by");              
    [016B] delay(120);                                             
    [016F] print(255,"     Chris Grigg and David Lawrence");       
    [018F] delay(180);                                                          // Sleep 3 seconds
    [0193] print(255," ");                                         
    [0197] loadRoom(49);                                                        // "MANIAC MANSION" Scrolling
    [0199] setCameraAt(20);                                                     // Set camera to left of room
    
    [019B] panCameraTo(220);                                                    // Pan camera to right of room
    [019D] breakHere();                                            
    [019E] unless (VAR_CAMERA_POS_X == 180) goto 019D;                          // Sleep until camera finishes pan
    
    [01A3] Var[11] = 0;                                            
    [01A6] cursorCommand(1);                                       
    [01A8] endcutscene();                                                       // End Cutscene
    [01A9] stopObjectCode();                                       
END                                                                 


/**
 * Script 45: Intro: Comet: Fly and Crash
 */Script-45 {                                                                                                                                                                                                                                                 
    [0000] putActorInRoom(22,33);                                               // Meteor enters
    [0003] putActor(22,80,5);                                     
    [0007] actorFollowCamera(22);                                               // Camera follows Meteor
    
    [0009] walkActorTo(22,29,52);                                               // Meteor 'walks' to the hill
    [000D] breakHere();                                           
    [000E] breakHere();                                           
    [000F] VAR_RESULT = getActorMoving(22);                       
    [0012] unless (VAR_RESULT == 2) goto 000E;                                  // Wait for Meteor to arrive
    
    [0017] panCameraTo(20);                                                     // Pan camera to mansion
    [0019] putActor(22,80,0);                                                   // Meteor goes off screen
    [001D] stopSound(31);                                         
    [001F] startSound(32);                                                      // Explosion
    [0021] breakHere();                                           
    
    [0022] putActor(22,29,52);                                                  // Meteor returns to hill
    [0026] Var[90] = 10;                                          
    [0029] breakHere();                                           
    [002A] Var[90] -= 1;                                          
    [002D] unless (Var[90] == 0) goto 0029;                                     // 10 sleeps...
    
    [0032] putActorInRoom(22,0);                                                // Meteor leaves room
    [0035] putActor(22,0,0);
    [0039] stopObjectCode();
}

/**
 * Script 46: Gargoyle: Open Basement Door
 */Script-46 {                                                                                                                                                                                                                                                 
    [0000] if (!getState08(36)) {                                               // Get state of basement door
    [0004]   setState08(36);                                                    // Open basement door
    [0006]   startSound(7);                                       
    [0008] }                                                      
    [0008] Var[123] = VAR_EGO;                                                  // Current Actor
    [000B] Var[124] = getActorX(Var[123]);                                      // Store Current Actor X
    [000E] Var[125] = getActorY(Var[123]);                                      // Store Current Actor Y
    [0011] breakHere();                                           
    
    [0012] VAR_RESULT = getActorX(Var[123]);                      
    [0015] if (VAR_RESULT == Var[124]) {                                        // X Match?
    [001A]   VAR_RESULT = getActorY(Var[123]);                    
    [001D]   if (VAR_RESULT == Var[125]) {                                      // Y Match?
    [0022]     goto 0011;                                                       // Wait for Actor to move
    [0025]   }                                                    
    [0025] }                                                      
    [0025] startSound(8);                                                       // Actor has moved
    [0027] clearState08(36);                                                    // Close basement door
    [0029] stopObjectCode();
}

/**
 * Script 48: Demo: Advertisement Recording
 */
Script-48 {
    [0000] delay(120);
    [0004] print(255,"This is a recording...");
    [001A] breakHere();
    [001B] unless (VAR_HAVE_MSG == 0) goto 001A;                                // Wait for text
    
    [0020] delay(60);
    [0024] print(255,"Lucasfilm Games presents Maniac Mansion,/a new type of story game./A sweet young cheerleader named Sandy/is being held captive by weird Dr. Fred,/and your goal is to rescue her.");
    [00BD] breakHere();
    [00BE] unless (VAR_HAVE_MSG == 0) goto 00BD;                                // Wait for text
    
    [00C3] print(255,"As you direct a trio of teenagers in/exploration of this unusual mansion,/deeper and stranger plots are uncovered./Play again and again with/different twists and laughs every time.");
    [0161] breakHere();
    [0162] unless (VAR_HAVE_MSG == 0) goto 0161;                                // Wait for text
    
    [0167] delay(30);
    [016B] print(255,"If you can't find Maniac Mansion at your/local retailer, call 1-800-227-6900/to order by mail. That's 1-800-227-6900.");
    [01D4] breakHere();
    [01D5] unless (VAR_HAVE_MSG == 0) goto 01D4;                                // Wait for text
    
    [01DA] delay(60);
    [01DE] print(255,"This recorded message will repeat...");
    [0201] breakHere();
    [0202] unless (VAR_HAVE_MSG == 0) goto 0201;                                // Wait for text
    
    [0207] goto 0000;
    [020A] stopObjectCode();
}

/**
 * Script 49: Handle Doorbell 
 */Script-49 {                                                                                                                                                                                                                                                 
    [0000] startSound(26);                                                      // sound doorbell
    [0002] delay(180);
    [0006] loadRoom(0);
    [0008] startScript(41);                                                     // Start Cutscene: Dr. Fred & Weird Ed (Doorbell)
    [000A] stopObjectCode();
}