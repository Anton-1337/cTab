/*
	Name: cTab_fnc_deleteUserLine
	
	Author(s):
		Gundy

	Description:
		Delete user placed line at provided index and broadcast the result. This function is called on the server.

	Parameters:
		0: STRING  - Encryption Key for this line
		1: INTEGER - Index position of line to delete
	Optional:
		2: INTEGER - Transaction ID
	
	Returns:
		BOOLEAN - TRUE
	
	Example:
		// Client requesting line deletion and server receiving request
		["bluefor",5] call cTab_fnc_deleteUserLine;
		
		// Client receiving request for line deletion (from server)
		["bluefor",5,158] call cTab_fnc_deleteUserLine;
*/

private ["_encryptionKey","_lineIndex","_transactionId"];

diag_log format ["[cTab_fnc_deleteUserLine] - _this: %1", _this];

_encryptionKey = _this select 0;
_lineIndex = _this select 1;
_transactionId = _this select 2; // not set when initiated from client

diag_log format ["[cTab_fnc_deleteUserLine] - _encryptionKey: %1, _lineIndex: %2, _transactionId: %3", _encryptionKey, _lineIndex, _transactionId];

call {
	// If received on the server
	if (isServer) exitWith {
		{
			// _x: ["c",[0,[[2435.89,1473.67],1,2,2,"12:00",wpl]]]
			if ((_x select 0) == _encryptionKey && _forEachIndex == _lineIndex) exitWith {
				cTab_queue_Lines deleteAt _forEachIndex;
			};
		} forEach cTab_queue_Lines;
		
		publicVariable "cTab_queue_Lines";
	};
	
	// If received on a client, to be sent to the server
	if (hasInterface) then {
		[_this,"cTab_fnc_deleteUserLine",false,false,true] call bis_fnc_MP;
	};
};

true