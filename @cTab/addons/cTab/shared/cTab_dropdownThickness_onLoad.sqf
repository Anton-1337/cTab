params ["_ctrl"];

lbClear _ctrl;

// Format: [Display Text, Procedural Color Texture, Value to save to global var]
private _thicknesses = [
    ["Thin",  "#(argb,8,8,3)color(0,0,0,1)", "16"],
	["Thick", "#(argb,8,8,3)color(0,0,0,1)", "32"]
];

{
    _x params ["_name", "_texture", "_thickness"];
    
    private _index = _ctrl lbAdd _name;              // Text label
    _ctrl lbSetTooltip [_index, _name];              // Shows thickness name on mouse hover
    // _ctrl lbSetPicture [_index, _texture];        // Renders the solid thickness rectangle
    // _ctrl lbSetPictureColor [_index, [1,1,1,1]];  // Keeps the texture at true brightness
    // _ctrl lbSetPictureColorSelected [_index, [1,1,1,1]];
    _ctrl lbSetData [_index, _thickness];
} forEach _thicknesses;

_ctrl lbSetCurSel 0; // Select thin thickness by default
