
// Add the marker without any custom text
[call cTab_fnc_getPlayerEncryptionKey,cTabUserSelIcon] call cTab_fnc_addUserMarker;

// Close the pop-up (1 = OK, 2 = Cancel)
(findDisplay 9900) closeDisplay 2;
