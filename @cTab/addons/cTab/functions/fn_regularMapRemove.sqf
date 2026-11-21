params [
	["_markerIndex", 0, [0]]
];

_markerName = [_markerIndex] call cTab_fnc_regularMapMarkerName;

deleteMarker _markerName;
