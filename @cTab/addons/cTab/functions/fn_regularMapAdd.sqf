params [
	["_transactionId", 0, [0]],
	["_pos", [], [[]]],
	["_type", -1, [0]],
	["_text", "", [""]]
];

if (_type > -1) then {
	// Has valid marker type
	_markerColor = cTabColorRed;
	_markerType = call {
		if (_type == 0) exitWith {"o_inf"};
		if (_type == 1) exitWith {"o_mech_inf"};
		if (_type == 2) exitWith {"o_motor_inf"};
		if (_type == 3) exitWith {"o_armor"};
		if (_type == 4) exitWith {"o_air";};
		if (_type == 5) exitWith {"o_plane"};
		if (_type == 6) exitWith {"o_unknown"};
		if (_type == 7) exitWith {"o_inf"};
		if (_type == 8) exitWith {"o_inf"};
		if (_type == 9) exitWith {"o_inf"};
		if (_type == 10) exitWith {"o_inf"};
		if (_type == 11) exitWith {"o_inf"};
		if (_type == 12) exitWith {"o_inf"};
		if (_type == 13) exitWith {"o_inf"};
		_markerColor = cTabColorGreen;
		if (_type == 20) exitWith {"mil_join"};
		if (_type == 21) exitWith {"mil_circle"};
		if (_type == 22) exitWith {"loc_Hospital"};
		if (_type == 23) exitWith {"mil_warning"};
		_markerColor = cTabColorBlue;
		if (_type == 30) exitWith {"b_hq"};
		if (_type == 31) exitWith {"mil_end"};

		// GOL icons
		_markerColor = cTabColorRed;
		if (_type == 246) exitWith {"mil_destroy"};
		_markerColor = cTabColorBlue;
		if (_type == 248) exitWith {"mil_dot"};
		if (_type == 250) exitWith {"mil_end"};
		if (_type == 252) exitWith {"mil_flag"};
		if (_type == 254) exitWith {"mil_join"};
		if (_type == 256) exitWith {"mil_marker"};
		if (_type == 258) exitWith {"mil_objective"};
		if (_type == 260) exitWith {"mil_pickup"};
		if (_type == 262) exitWith {"mil_start"};
		if (_type == 264) exitWith {"mil_triangle"};
		_markerColor = cTabColorRed;
		if (_type == 266) exitWith {"mil_unknown"};
		if (_type == 268) exitWith {"mil_warning"};
		_markerColor = cTabColorGolRed;
		if (_type == 270) exitWith {"Minefield"};

		""
	};

	_markerName = [_transactionId] call cTab_fnc_regularMapMarkerName;
	createMarkerLocal [_markerName, _pos];
	_markerName setMarkerColorLocal format ["#(%1,%2,%3,%4)", (_markerColor select 0), (_markerColor select 1), (_markerColor select 2), (_markerColor select 3)];
	_markerName setMarkerShapeLocal "ICON";
	_markerName setMarkerTypeLocal _markerType;
	_markerName setMarkerText _text; // Using any global marker function will make the marker global
};
