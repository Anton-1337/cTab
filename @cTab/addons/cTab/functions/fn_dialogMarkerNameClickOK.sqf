// cTabUserSelIcon definition:
// cTabUserSelIcon = [[],0,0,0,""];

// 1. Get text from the pop-up's input box
private _popupDisplay = findDisplay 9900;
private _text = ctrlText (_popupDisplay displayCtrl 9902);

if (_text != "") then {
	// Update marker with new text (prepend a space to to push the text out from the marker a little)
	cTabUserSelIcon set [4, format [" %1", _text]];
};

// Send cTabUserSelIcon to server
[call cTab_fnc_getPlayerEncryptionKey,cTabUserSelIcon] call cTab_fnc_addUserMarker;

// Close the pop-up (1 = OK, 2 = Cancel)
_popupDisplay closeDisplay 1;
