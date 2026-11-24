#include "\a3\ui_f\hpp\defineDIKCodes.inc"

params ["_control"];

_control setVariable ["cTab_MapDrawing_isDrawing", false];
_control setVariable ["cTab_MapDrawing_currentStroke", []];
_control setVariable ["cTab_MapDrawing_drawColor", [0, 1, 0, 1]];

_control ctrlAddEventHandler ["MouseButtonDown", {
    params ["_control", "_button", "_xPos", "_yPos", "_shift", "_ctrl", "_alt"];

    if (_button != 0) exitWith {}; // Left click only
    
    if (!_ctrl) exitWith {};

    private _worldPos = _control ctrlMapScreenToWorld [_xPos, _yPos];

    _control setVariable ["cTab_MapDrawing_isDrawing", true];
    _control setVariable ["cTab_MapDrawing_currentStroke", [_worldPos]];
}];

_control ctrlAddEventHandler ["MouseMoving", {
    params ["_control", "_xPos", "_yPos"];

    if !(_control getVariable ["cTab_MapDrawing_isDrawing", false]) exitWith {};

    private _stroke = _control getVariable ["cTab_MapDrawing_currentStroke", []];
    private _worldPos = _control ctrlMapScreenToWorld [_xPos, _yPos];
    
    // Distance threshold to prevent creating many redundant points
    _targetRadius = ((ctrlMapScale _control) * cTabMapScaleFactor * 2);
    _minDistance = _worldPos distanceSqr [((_worldPos select 0) + _targetRadius), ((_worldPos select 1) + _targetRadius)];
    
    if ((_stroke select (count _stroke - 1)) distance2D _worldPos >= _minDistance) then {
        _stroke pushBack _worldPos;
    };
}];

_control ctrlAddEventHandler ["MouseButtonUp", {
    params ["_control", "_button"];

    if (_button != 0) exitWith {};

    if !(_control getVariable ["cTab_MapDrawing_isDrawing", false]) exitWith {};

    _control setVariable ["cTab_MapDrawing_isDrawing", false];

    private _stroke = _control getVariable ["cTab_MapDrawing_currentStroke", []];

    if (count _stroke > 1) then {
        [call cTab_fnc_getPlayerEncryptionKey, _stroke] call cTab_fnc_addUserLine;
    };

    _control setVariable ["cTab_MapDrawing_currentStroke", []];
}];

_control ctrlAddEventHandler ["Draw", {
    params ["_control"];

    private _lineColor = _control getVariable ["cTab_MapDrawing_drawColor", [0, 1, 0, 1]];

    {
        private _pts = _x select 1 select 1;
        
        for "_i" from 0 to (count _pts - 2) do {
            _control drawLine [_pts select _i, _pts select (_i + 1), _lineColor, cTabUserLineThickness];
        };
    } forEach cTab_queue_Lines;
}];
