#include "\a3\ui_f\hpp\defineDIKCodes.inc"

params ["_control"];

_control setVariable ["cTab_MapDrawing_isDrawing", false];
_control setVariable ["cTab_MapDrawing_currentStroke", []];

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
        [call cTab_fnc_getPlayerEncryptionKey, _stroke, cTabDropdownSelectedMapDrawingColor, cTabDropdownSelectedMapDrawingThickness] call cTab_fnc_addUserLine;
    };

    _control setVariable ["cTab_MapDrawing_currentStroke", []];
}];

_control ctrlAddEventHandler ["Draw", {
    params ["_control"];
    
    {
        // 17:41:21 "[DRAW]: [""c"",[0,[[2431.51,1502.33],[2432.3,1500.74],[2434.69,1499.54],[2437.48,1497.95],[2440.66,1495.96],[2444.25,1494.77],[2449.02,1492.38],[2454.6,1490.39],[2460.97,1488.4],[2469.33,1484.41],[2478.09,1481.23],[2488.04,1477.25],[2500.38,1472.47],[2512.33,1467.29],[2525.87,1462.12],[2535.42,1457.34],[2548.56,1451.77],[2560.5,1445.79],[2569.66,1441.02],[2577.23,1436.64],[2583.6,1432.26],[2589.17,1428.28],[2593.15,1424.3],[2595.94,1421.91],[2598.73,1419.12],[2600.32,1416.73],[2601.91,1414.34],[2603.5,1412.75],[2604.3,1410.76],[2605.1,1409.56],[2605.89,1408.37],[2606.29,1407.97]],[0,0,1,1],32]]"

        private _pts = _x select 1 select 1;
        private _colour = _x select 1 select 2;
        private _thickness = _x select 1 select 3;
        
        for "_i" from 0 to (count _pts - 2) do {
            _control drawLine [_pts select _i, _pts select (_i + 1), _colour, _thickness];
        };
    } forEach cTab_queue_Lines;
}];
