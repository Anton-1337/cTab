/*
	Name: cTab_fnc_drawUserMarkers
	
	Author(s):
		Gundy, Riouken

	Description:
		Draw userMarkers held in cTabUserMarkerList to map control
		
		List format:
			Index 0: ARRAY  - marker position
			Index 1: STRING - path to marker icon
			Index 2: STRING - path to marker size icon
			Index 3: STRING - direction of reported movement
			Index 4: ARRAY  - marker color
			Index 5: STRING - marker time
			Index 6: STRING - text alignment
	
	Parameters:
		0: OBJECT  - Map control to draw BFT icons on
		1: BOOLEAN - Highlight marker under cursor
	
	Returns:
		BOOLEAN - Always TRUE
	
	Example:
		[_ctrlScreen] call cTab_fnc_drawUserMarkers;
*/

// private ["_ctrlScreen","_arrowLength","_pos","_secondPos","_texture1","_texture2","_dir","_color","_text","_align","_cursorMarkerIndex","_markerData"];

// _ctrlScreen = _this select 0;
// _arrowLength = cTabUserMarkerArrowSize * ctrlMapScale _ctrlScreen;
// _cursorMarkerIndex = if (_this select 1) then {[_ctrlScreen,cTabMapCursorPos] call cTab_fnc_findUserMarker} else {-1};
// {
// 	_markerData = _x select 1;
// 	_pos = _markerData select 0;
// 	_texture1 = _markerData select 1;
// 	_texture2 = _markerData select 2;
// 	_dir = _markerData select 3;
// 	_color = if (_x select 0 != _cursorMarkerIndex) then {_markerData select 4} else {cTabTADhighlightColour};
// 	_text = "";
// 	if (_dir < 360) then {
// 		_secondPos = [_pos,_arrowLength,_dir] call BIS_fnc_relPos;
// 		_ctrlScreen drawArrow [_pos, _secondPos, _color];
// 	};
// 	if (cTabBFTtxt) then {_text = _markerData select 5;};
// 	_ctrlScreen drawIcon [_texture1,_color,_pos, cTabIconSize, cTabIconSize, 0, _text, 0, cTabTxtSize,"TahomaB",_markerData select 6];
// 	if (_texture2 != "") then {
// 		_ctrlScreen drawIcon [_texture2,_color,_pos, cTabGroupOverlayIconSize, cTabGroupOverlayIconSize, 0, "", 0, cTabTxtSize,"TahomaB","right"];
// 	};
// } count cTabUserMarkerList;

params ["_control", "_highlight"];

_playerEncryptionKey = call cTab_fnc_getPlayerEncryptionKey;
_cursorMarkerIndex = if (_highlight) then {[_control, cTabMapCursorPos] call cTab_fnc_findUserMarker} else {-1};

// Read the latest synced array every frame the map is visible
{
	// ["c",[0,[[2455,1459.73],1,2,4,"12:00",wpl]]]
	_x params ["_encryptionKey", "_data"];
	
	if (_encryptionKey == _playerEncryptionKey) then {
		/*
			_data: [_transactionId, _pos, _texture1, _texture2, _dir, _color, _text, _align]
			Index 0: SCALAR - transaction ID
			Index 1: ARRAY  - marker position
			Index 2: STRING - path to marker icon
			Index 3: STRING - path to marker size icon
			Index 4: STRING - direction of reported movement
			Index 5: ARRAY  - marker color
			Index 6: STRING - marker time
			Index 7: STRING - text alignment
		*/

		_transactionId = _data select 0;
		_markerData = _data select 1; // [[2441.46,1468.89],1,2,2,""12:00"",wpl,[0,0,0,1]]

		// _translatedUserMarker = [(_markerData select 0), (_markerData select 1), (_markerData select 2), (_markerData select 3), (_markerData select 4)] call cTab_fnc_translateUserMarker;
		_translatedUserMarker = [_markerData] call cTab_fnc_translateUserMarker;

		// [[2451.02,1484.02],"\A3\ui_f\data\map\markers\nato\o_mech_inf.paa","\A3\ui_f\data\map\markers\nato\group_1.paa",45,[0.5,0,0,1],"12:00","left"]
		_pos = _translatedUserMarker select 0;
		_texture1 = _translatedUserMarker select 1;
		_texture2 = _translatedUserMarker select 2;
		_dir = _translatedUserMarker select 3;
		_color = if (_transactionId != _cursorMarkerIndex) then {_translatedUserMarker select 4} else {cTabTADhighlightColour};
		_text = _translatedUserMarker select 5;
		_align = _translatedUserMarker select 6;
		
		// Draw the custom icon
		_control drawIcon [_texture1, _color, _pos, cTabIconSize, cTabIconSize, 0, _text, 0, cTabTxtSize, "TahomaB", _align];
		
		if (_texture2 != "") then {
			_control drawIcon [_texture2, _color, _pos, cTabGroupOverlayIconSize, cTabGroupOverlayIconSize, 0, "", 0, cTabTxtSize, "TahomaB", "right"];
		};
		
		if (_dir < 360) then {
			_arrowLength = cTabUserMarkerArrowSize * ctrlMapScale _control;
			_secondPos = [_pos, _arrowLength, _dir] call BIS_fnc_relPos;
			_control drawArrow [_pos, _secondPos, _color];
		};
	};
} forEach (missionNamespace getVariable ["cTab_queue_Markers", []]);

true