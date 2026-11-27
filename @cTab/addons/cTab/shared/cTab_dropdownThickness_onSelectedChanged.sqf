params ["_ctrl", "_selectedIndex"];

private _dataString = _ctrl lbData _selectedIndex;
if (_dataString isEqualTo "") exitWith {};

// Sets your global variable to the thickness value (e.g., "16")
cTabDropdownSelectedMapDrawingThickness = parseNumber _dataString;
