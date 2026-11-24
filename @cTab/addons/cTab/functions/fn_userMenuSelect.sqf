/*
	Name: cTab_fnc_userMenuSelect
	
	Author(s):
		Gundy, Riouken
	
	Description:
		Process user menu select events, initiated by "\cTab\shared\cTab_markerMenu_controls.hpp"
		
	
	Parameters:
		0: INTEGER - Type of user menu select event - if this doesn't match a valid type it will be considered to be an IDC
	
	Returns:
		BOOLEAN - TRUE
	
	Example:
		[1] call cTab_fnc_userMenuSelect;
*/

#include "\cTab\shared\cTab_gui_macros.hpp"
#include "\a3\ui_f\hpp\defineDIKCodes.inc"

private ["_type","_displayName","_display","_idcToShow","_control","_controlPos","_screenPos","_screenEdgeX","_screenEdgeY","_controlEdgeX","_controlEdgeY","_ctrlIsHeld"];

disableSerialization;

_type = _this select 0;
_ctrlIsHeld = _this select 1;
_displayName = cTabIfOpen select 1;
_display = (uiNamespace getVariable _displayName);

_idcToShow = 0;

call {
	// send cTabUserSelIcon to server
	if (_type == 1) exitWith {
		cTabUserSelIcon pushBack cTab_player;
		
		if (_ctrlIsHeld) then {
			// Ctrl is held down, so we want to show the marker text pop-up for custom text input

			// Hide all menu controls
			{ctrlShow [_x,false];} forEach [
				IDC_USRMN_IGUI_MAIN,

				IDC_USRMN_IGUI_FORCES,
				IDC_USRMN_IGUI_SUPPORT,
				IDC_USRMN_IGUISUB_MED,
				IDC_USRMN_IGUISUB_GEN,

				IDC_USRMN_IGUISUB_SIZE,
				IDC_USRMN_IGUISUB_DIR,

				IDC_USRMN_IGUISUB_DONE
			];
			
			// Show the marker text pop-up (cTab_dialog_TextMarker)
			// private _popupDisplay = (findDisplay 46) createDisplay "cTab_dialog_TextMarker";

			if !(createDialog "cTab_dialog_TextMarker") exitWith {};

			private _popupDisplay = findDisplay 9900;
			
			// Trigger confirm when Enter or Numpad Enter is pressed
			private _ctrlTextBox = _popupDisplay displayCtrl 9902;

			_ctrlTextBox ctrlAddEventHandler ["KeyDown", {
				params ["_control", "_key"];
				
				if (_key in [DIK_RETURN, DIK_NUMPADENTER]) exitWith {
					[] call cTab_fnc_dialogMarkerNameClickOK;
					true; // Consume the keypress
				};

				if (_key == DIK_ESCAPE) exitWith {
					[] call cTab_fnc_dialogMarkerNameClickCancel;
					true; // Consume the keypress
				};

				false
			}];
			
			// Automatically focus the text box so the player can start typing immediately
			ctrlSetFocus _ctrlTextBox;
		} else {
			// Ctrl is not held down, so create the marker without any custom marker text
			[call cTab_fnc_getPlayerEncryptionKey,cTabUserSelIcon] call cTab_fnc_addUserMarker;
		};
	};
	
	// Lock UAV cam to clicked position
	if (_type == 2) exitWith {
		[cTabUserSelIcon select 0] call cTab_fnc_lockUavCamTo;
	};

	_idcToShow = _type;
};

// Hide all menu controls
{ctrlShow [_x,false];} forEach [
	IDC_USRMN_IGUI_MAIN,

	IDC_USRMN_IGUI_FORCES,
	IDC_USRMN_IGUI_SUPPORT,
	IDC_USRMN_IGUISUB_MED,
	IDC_USRMN_IGUISUB_GEN,

	IDC_USRMN_IGUISUB_SIZE,
	IDC_USRMN_IGUISUB_DIR,

	IDC_USRMN_IGUISUB_DONE
];

// Bring the menu control we want to show into position and show it
if (_idcToShow != 0) then {
	_control = _display displayCtrl _idcToShow;
	if !(isNull _control) then {
		_controlPos = ctrlPosition _control;
		
		// figure out screen edge positions and where the edges of the control would be if we were just to move it blindly to cTabUserPos
		_screenPos = ctrlPosition (_display displayCtrl IDC_CTAB_LOADINGTXT);
		_screenEdgeX = (_screenPos select 0) + (_screenPos select 2);
		_screenEdgeY = (_screenPos select 1) + (_screenPos select 3);
		_controlEdgeX = (cTabUserPos select 0) + (_controlPos select 2);
		_controlEdgeY = (cTabUserPos select 1) + (_controlPos select 3);
		
		// if control would be clipping the right edge, correct control position
		if (_controlEdgeX > _screenEdgeX) then {
			_controlPos set [0,_screenEdgeX - (_controlPos select 2)];
		} else {
			_controlPos set [0,cTabUserPos select 0];
		};
		// if control would be clipping the bottom edge, correct control position
		if (_controlEdgeY > _screenEdgeY) then {
			_controlPos set [1,_screenEdgeY - (_controlPos select 3)];
		} else {
			_controlPos set [1,cTabUserPos select 1];
		};
		
		// move to position and show
		_control ctrlSetPosition _controlPos;
		_control ctrlCommit 0;
		_control ctrlShow true;
		ctrlSetFocus _control;
	};
};

true