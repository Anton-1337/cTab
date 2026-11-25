params [
	["_transactionId", 0, [0]],
	["_pos", [], [[]]],
	["_type", -1, [0]],
	["_text", "", [""]]
];

private ["_markerName","_markerType","_markerSize","_markerColor"];

if (_type > -1) then {
	// Has valid marker type
	_markerType = call {
		if (_type == 0) exitWith {"o_inf"};
		if (_type == 1) exitWith {"o_mech_inf"};
		if (_type == 2) exitWith {"o_motor_inf"};
		if (_type == 3) exitWith {"o_armor"};
		if (_type == 4) exitWith {"o_air";};
		if (_type == 5) exitWith {"o_plane"};
		if (_type == 6) exitWith {"o_unknown"};
		if (_type == 7) exitWith {"o_inf_rifle"};
		if (_type == 8) exitWith {"o_inf_mg"};
		if (_type == 9) exitWith {"o_inf_at"};
		if (_type == 10) exitWith {"o_inf_mmg"};
		if (_type == 11) exitWith {"o_inf_mat"};
		if (_type == 12) exitWith {"o_inf_mmortar"};
		if (_type == 13) exitWith {"o_inf_aa"};
		if (_type == 14) exitWith {"mil_triangle_noShadow"};

		if (_type == 20) exitWith {"mil_join"};
		if (_type == 21) exitWith {"mil_circle"};
		if (_type == 22) exitWith {"loc_Hospital"};
		if (_type == 23) exitWith {"mil_warning"};

		if (_type == 30) exitWith {"b_hq"};
		if (_type == 31) exitWith {"mil_end"};
		if (_type == 32) exitWith {"mil_join"};
		if (_type == 33) exitWith {"mil_flag"};
		if (_type == 34) exitWith {"mil_objective"};
		if (_type == 35) exitWith {"Minefield"};

		""
	};

	_markerSize = call {
		// if (_type == 14 || _type == 22) exitWith {[0.8, 0.8]};

		[0.7, 0.7]
	};

	_markerColor = call {
		if (_type < 20) exitWith {"ColorEAST"};
		if (_type < 30) exitWith {"ColorGreen"};
		if (_type == 35) exitWith {"ColorRed"};
		if (_type < 40) exitWith {"ColorWEST"};

		""
	};

	_markerName = [_transactionId] call cTab_fnc_regularMapMarkerName;
	createMarkerLocal [_markerName, _pos];
	_markerName setMarkerShapeLocal "ICON";
	_markerName setMarkerTypeLocal _markerType;
	_markerName setMarkerSizeLocal _markerSize;
	_markerName setMarkerColorLocal _markerColor;
	_markerName setMarkerText _text; // Using any global marker function will make the marker global
};
