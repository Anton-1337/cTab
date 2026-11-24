/*
	Name: cTab_fnc_addUserLine
	
	Author(s):
		Gundy
	
	Description:
		Add a new user line to the list and broadcast it. This function is called on the server.
	
	Parameters:
		0: STRING  - Encryption Key for this line
		1: ARRAY   - Strokes
	Optional:
		2: INTEGER - Transaction ID
	
	Returns:
		BOOLEAN - Always TRUE
	
	Example:
		// Client requesting line addition and server receiving request
		["bluefor",[21,[[1714.35,5716.82],[1713.12,5720.65]]]] call cTab_fnc_addUserLine;
		
		// Client receiving line addition (from server)
		["bluefor",[21,[[1714.35,5716.82],[1713.12,5720.65]]],157] call cTab_fnc_addUserLine;
*/

private ["_encryptionKey","_strokes","_transactionId"];

_encryptionKey = _this select 0;
_strokes = _this select 1;
_transactionId = _this select 2; // not set when initiated from client

call {
	// If received on the server
	if (isServer) exitWith {
		if (isNil "_transactionId") then {
			// Increase transaction ID
			cTab_userLinesTransactionId = cTab_userLinesTransactionId + 1;
			_transactionId = cTab_userLinesTransactionId;

			cTab_queue_Lines pushBack [_encryptionKey,[_transactionId,_strokes]];
			publicVariable "cTab_queue_Lines";
		};
	};

	// If received on a client, to be sent to the server
	if (hasInterface) then {
		[_this,"cTab_fnc_addUserLine",false,false,true] call bis_fnc_MP;
	};
};

true