params ["_ctrl"];

lbClear _ctrl;

private _fnc_GetTexture = {
    params ["_color"];
    format ["#(argb,8,8,3)color(%1,%2,%3,%4)", _color select 0, _color select 1, _color select 2, _color select 3]
};

// Format: [Display Text, Procedural Color Texture, Value to save to global var]
private _colors = [
    ["BLUFOR", [cTabColorBlue] call _fnc_GetTexture, cTabColorBlue],
    ["OPFOR", [cTabColorRed] call _fnc_GetTexture, cTabColorRed],
    ["INDFOR", [cTabColorGreen] call _fnc_GetTexture, cTabColorGreen],
	["Civilian", [cTabColorGolCiv] call _fnc_GetTexture, cTabColorGolCiv],
    ["Black", [cTabColorGolBlack] call _fnc_GetTexture, cTabColorGolBlack],
    ["White", [cTabColorGolWhite] call _fnc_GetTexture, cTabColorGolWhite],
	["Blue", [cTabColorGolBlue] call _fnc_GetTexture, cTabColorGolBlue],
    ["Green", [cTabColorGolGreen] call _fnc_GetTexture, cTabColorGolGreen],
    ["Yellow", [cTabColorGolYellow] call _fnc_GetTexture, cTabColorGolYellow],
	["Orange", [cTabColorGolOrange] call _fnc_GetTexture, cTabColorGolOrange],
	["Red", [cTabColorGolRed] call _fnc_GetTexture, cTabColorGolRed]
];

{
    _x params ["_name", "_texture", "_colorData"];
    
    private _index = _ctrl lbAdd "";                 // Empty string hides the text label
    _ctrl lbSetTooltip [_index, _name];              // Shows colour name on mouse hover
    _ctrl lbSetPicture [_index, _texture];           // Renders the solid colour rectangle
    _ctrl lbSetPictureColor [_index, [1,1,1,1]];     // Keeps the texture at true brightness
    _ctrl lbSetPictureColorSelected [_index, [1,1,1,1]];
    _ctrl lbSetData [_index, str _colorData];
} forEach _colors;

_ctrl lbSetCurSel 0; // Select the first colour by default
