/*
	Name: cTab_fnc_addUserMarker
	
	Author(s):
		Gundy
	
	Description:
		Add a new user marker to the list and broadcast it. This function is called on the server.
	
	Parameters:
		0: STRING  - Encryption Key for this marker
		1: ARRAY   - markerData
	Optional:
		2: INTEGER - Transaction ID
	
	Returns:
		BOOLEAN - Always TRUE
	
	Example:
		// Client requesting marker addition and server receiving request
		["bluefor",[[1714.35,5716.82],0,0,0,"12:00",player]]call cTab_fnc_addUserMarker;
		
		// Client receiving marker addition (from server)
		["bluefor",[21,[[1714.35,5716.82],0,0,0,"12:00",player]],157]call cTab_fnc_addUserMarker;
*/

private ["_encryptionKey","_markerData","_transactionId"];

_encryptionKey = _this select 0;
_markerData = _this select 1;
_transactionId = _this select 2; // not set when initiated from client

call {
	// If received on the server
	if (isServer) exitWith {
		if (isNil "_transactionId") then {
			// Increase transaction ID
			cTab_userMarkerTransactionId = cTab_userMarkerTransactionId + 1;
			_transactionId = cTab_userMarkerTransactionId;

			cTab_queue_Markers pushBack [_encryptionKey,[_transactionId,_markerData]];
			publicVariable "cTab_queue_Markers";
		};
	};
	
	// If received on a client, to be sent to the server
	if (hasInterface) then {
		[_this,"cTab_fnc_addUserMarker",false,false,true] call bis_fnc_MP;
	};
};

true