params ["_control"];

_targetRadius = cTabUserLineThickness * 2 * (ctrlMapScale _control) * cTabMapScaleFactor;

diag_log format ["[cTab_MapDrawing] - _targetRadius: %1", _targetRadius];

// Delete nearest line within max distance
getMousePosition params ["_mouseX", "_mouseY"];

private _worldPos = _control ctrlMapScreenToWorld [_mouseX, _mouseY];
private _foundStroke = false;

_maxDistance = _worldPos distanceSqr [(_worldPos select 0) + _targetRadius, (_worldPos select 1) + _targetRadius];

diag_log format ["[cTab_MapDrawing] - _worldPos: %1, _targetRadius: %2, _maxDistance: %3", _worldPos, _targetRadius, _maxDistance];

{
	_strokeIndex = _forEachIndex;

	{
		_x params ["_xPos", "_yPos"];

		// figure out radius around cursor box based on map zoom and scale
		_distance = _worldPos distanceSqr [_xPos, _yPos];
		
		diag_log format ["[cTab_MapDrawing] - _distance: %1", _distance];

		if (_distance <= _maxDistance) exitWith {
			[call cTab_fnc_getPlayerEncryptionKey, _strokeIndex] call cTab_fnc_deleteUserLine;
			_foundStroke = true;
		};
	} forEach (_x select 1 select 1);

	if (_foundStroke) exitWith {};
} forEach cTab_queue_Lines;
