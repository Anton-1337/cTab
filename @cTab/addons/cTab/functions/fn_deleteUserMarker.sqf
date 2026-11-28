/*
	Name: cTab_fnc_deleteUserMarker
	
	Author(s):
		Gundy

	Description:
		Delete user placed marker at provided index and broadcast the result. This function is called on the server.

	Parameters:
		0: STRING  - Encryption Key for this marker
		1: INTEGER - Index position of marker to delete
	Optional:
		2: INTEGER - Transaction ID
	
	Returns:
		BOOLEAN - TRUE
	
	Example:
		// Client requesting marker deletion and server receiving request
		["bluefor",5] call cTab_fnc_deleteUserMarker;
		
		// Client receiving request for marker deletion (from server)
		["bluefor",5,158] call cTab_fnc_deleteUserMarker;
*/

private ["_encryptionKey","_markerIndex","_transactionId","_userMarkerList","_removeIndex"];

_encryptionKey = _this select 0;
_markerIndex = _this select 1;
_transactionId = _this select 2; // not set when initiated from client

call {
	// If received on the server
	if (isServer) exitWith {
		{
			// _x: ["c",[0,[[2435.89,1473.67],1,2,2,"12:00",wpl]]]
			if ((_x select 0) == _encryptionKey && (_x select 1 select 0) == _markerIndex) exitWith {
				cTab_queue_Markers deleteAt _forEachIndex;
			};
		} forEach cTab_queue_Markers;
		
		publicVariable "cTab_queue_Markers";
	};
	
	// If received on a client, to be sent to the server
	if (hasInterface) then {
		[_this,"cTab_fnc_deleteUserMarker",false,false,true] call bis_fnc_MP;
	};
};

true