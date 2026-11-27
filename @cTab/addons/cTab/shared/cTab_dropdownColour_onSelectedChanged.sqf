params ["_ctrl", "_selectedIndex"];

private _dataString = _ctrl lbData _selectedIndex;
if (_dataString isEqualTo "") exitWith {};

// Sets your global variable to the RGBA array (e.g., [1,0,0,1])
cTabDropdownSelectedMapDrawingColor = parseSimpleArray _dataString;
