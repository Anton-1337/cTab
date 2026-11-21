class MainSubmenu: cTab_RscControlsGroup
{
	#ifndef cTab_IS_TABLET
		#define cTab_MENU_MAX_ELEMENTS 5
	#else
		#define cTab_MENU_MAX_ELEMENTS 6
	#endif
	idc = 3300;
	x = QUOTE(MENU_X);
	y = QUOTE(MENU_Y);
	w = QUOTE(MENU_W);
	h = QUOTE(MENU_H(cTab_MENU_MAX_ELEMENTS));
	class controls
	{
		class mainbg: cTab_IGUIBack
		{
			idc = IDC_USRMN_MAINBG;
			x = 0;
			y = 0;
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_H(cTab_MENU_MAX_ELEMENTS));
		};
		class op4btn: cTab_MenuItem
		{
			idc = IDC_USRMN_OP4BTN;
			text = "Enemy SALUTE"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(1));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "[11] call cTab_fnc_userMenuSelect;";
		};
		class medbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_MEDBTN;
			text = "Medical"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(2));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "[21] call cTab_fnc_userMenuSelect;";
		};
		class genbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_GENBTN;
			text = "General"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(3));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "[31] call cTab_fnc_userMenuSelect;";
		};
		class golbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_GOLBTN;
			text = "GOL"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(4));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "[41] call cTab_fnc_userMenuSelect;";
		};
		#ifdef cTab_IS_TABLET
			class lockUavCam: cTab_MenuItem
			{
				idc = -1;
				text = "Lock UAV Cam"; //--- ToDo: Localize;
				toolTip = "Lock UAV Cam to this position, a UAV has to be previously selected";
				x = 0;
				y = QUOTE(MENU_elementY(5));
				w = QUOTE(MENU_W);
				h = QUOTE(MENU_elementH);
				sizeEx = QUOTE(MENU_sizeEx);
				action = "[2] call cTab_fnc_userMenuSelect;";
			};
		#endif
		class exit: cTab_MenuExit
		{
			idc = -1;
			text = "Exit"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(cTab_MENU_MAX_ELEMENTS));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "[0] call cTab_fnc_userMenuSelect;";
		};
	};
};

class EnemySub1: cTab_RscControlsGroup
{
	#define cTab_MENU_MAX_ELEMENTS 8
	idc = 3301;
	x = QUOTE(MENU_X);
	y = QUOTE(MENU_Y);
	w = QUOTE(MENU_W);
	h = QUOTE(MENU_H(cTab_MENU_MAX_ELEMENTS));
	class controls
	{
		class IGUIBack_2201: cTab_IGUIBack
		{
			idc = IDC_USRMN_IGUIBACK_2202;
			x = 0;
			y = 0;
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_H(cTab_MENU_MAX_ELEMENTS));
		};
		class infbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_INFBTN;
			text = "Infantry"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(1));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,0];[12] call cTab_fnc_userMenuSelect;";
		};
		class mecinfbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_MECINFBTN;
			text = "Mechanized Inf"; //--- ToDo: Localize;
			toolTip = "Equipped with APCs/IFVs";
			x = 0;
			y = QUOTE(MENU_elementY(2));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,1];[12] call cTab_fnc_userMenuSelect;";
		};

		class motrinfbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_MOTRINFBTN;
			text = "Motorized Inf"; //--- ToDo: Localize;
			toolTip = "Equipped with un-protected vehicles";
			x = 0;
			y = QUOTE(MENU_elementY(3));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,2];[12] call cTab_fnc_userMenuSelect;";
		};
		class amrbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_AMRBTN;
			text = "Armor"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(4));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,3];[12] call cTab_fnc_userMenuSelect;";
		};
		class helibtn: cTab_MenuItem
		{
			idc = IDC_USRMN_HELIBTN;
			text = "Helicopter"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(5));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,4];[12] call cTab_fnc_userMenuSelect;";
		};
		class plnbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_PLNBTN;
			text = "Plane"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(6));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,5];[12] call cTab_fnc_userMenuSelect;";
		};
		class uknbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_UKNBTN;
			text = "Unknown"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(7));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,6];[12] call cTab_fnc_userMenuSelect;";
		};
		class exit: cTab_MenuExit
		{
			idc = -1;
			text = "Exit"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(cTab_MENU_MAX_ELEMENTS));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "[0] call cTab_fnc_userMenuSelect;";
		};
	};
};

class EnemySub2: cTab_RscControlsGroup
{
	#define cTab_MENU_MAX_ELEMENTS 6
	idc = 3303;
	x = QUOTE(MENU_X);
	y = QUOTE(MENU_Y);
	w = QUOTE(MENU_W);
	h = QUOTE(MENU_H(cTab_MENU_MAX_ELEMENTS));
	class controls
	{
		class IGUIBack_2202: cTab_IGUIBack
		{
			idc = IDC_USRMN_IGUIBACK_2202;
			x = 0;
			y = 0;
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_H(cTab_MENU_MAX_ELEMENTS));
		};
		class ftbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_FTBTN;
			text = "Singular"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(1));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "[14] call cTab_fnc_userMenuSelect;";
		};
		class patbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_PATBTN;
			text = "Patrol"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(2));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [2,1];[13] call cTab_fnc_userMenuSelect;";
		};
		class sqdbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_SQDBTN;
			text = "Squad"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(3));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [2,2];[13] call cTab_fnc_userMenuSelect;";
		};
		class sctbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_SCTBTN;
			text = "Section"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(4));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [2,3];[13] call cTab_fnc_userMenuSelect;";
		};
		class pltnbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_PLTNBTN;
			text = "Platoon"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(5));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [2,4];[13] call cTab_fnc_userMenuSelect;";
		};
		class exit: cTab_MenuExit
		{
			idc = -1;
			text = "Exit"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(cTab_MENU_MAX_ELEMENTS));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "[0] call cTab_fnc_userMenuSelect;";
		};
	};
};

class EnemySub3: cTab_RscControlsGroup
{
	#define cTab_MENU_MAX_ELEMENTS 10
	idc = 3304;
	x = QUOTE(MENU_X);
	y = QUOTE(MENU_Y);
	w = QUOTE(MENU_W);
	h = QUOTE(MENU_H(cTab_MENU_MAX_ELEMENTS));
	class controls
	{
		class IGUIBack_2203: cTab_IGUIBack
		{
			idc = IDC_USRMN_IGUIBACK_2203;
			x = 0;
			y = 0;
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_H(cTab_MENU_MAX_ELEMENTS));
		};
		class stnbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_STNBTN;
			text = "Stationary"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(1));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "[1] call cTab_fnc_userMenuSelect;";
		};
		class nthbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_NTHBTN;
			text = "N"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(2));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [3,1];[1] call cTab_fnc_userMenuSelect;";
		};
		class nebtn: cTab_MenuItem
		{
			idc = IDC_USRMN_NEBTN;
			text = "NE"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(3));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [3,2];[1] call cTab_fnc_userMenuSelect;";
		};
		class ebtn: cTab_MenuItem
		{
			idc = IDC_USRMN_EBTN;
			text = "E"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(4));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [3,3];[1] call cTab_fnc_userMenuSelect;";
		};
		class sebtn: cTab_MenuItem
		{
			idc = IDC_USRMN_SEBTN;
			text = "SE"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(5));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [3,4];[1] call cTab_fnc_userMenuSelect;";
		};
		class sbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_SBTN;
			text = "S"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(6));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [3,5];[1] call cTab_fnc_userMenuSelect;";
		};
		class swbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_SWBTN;
			text = "SW"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(7));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [3,6];[1] call cTab_fnc_userMenuSelect;";
		};
		class wbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_WBTN;
			text = "W"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(8));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [3,7];[1] call cTab_fnc_userMenuSelect;";
		};
		class RscText_1022: cTab_MenuItem
		{
			idc = IDC_USRMN_RSCTEXT_1022;
			text = "NW"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(9));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [3,8];[1] call cTab_fnc_userMenuSelect;";
		};
		class exit: cTab_MenuExit
		{
			idc = -1;
			text = "Exit"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(cTab_MENU_MAX_ELEMENTS));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "[0] call cTab_fnc_userMenuSelect;";
		};
	};
};

class EnemySub4: cTab_RscControlsGroup
{
	#define cTab_MENU_MAX_ELEMENTS 8
	idc = 3307;
	x = QUOTE(MENU_X);
	y = QUOTE(MENU_Y);
	w = QUOTE(MENU_W);
	h = QUOTE(MENU_H(cTab_MENU_MAX_ELEMENTS));
	class controls
	{
		class IGUIBack_2202: cTab_IGUIBack
		{
			idc = IDC_USRMN_IGUIBACK_2202;
			x = 0;
			y = 0;
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_H(cTab_MENU_MAX_ELEMENTS));
		};
		class rifle_btn: cTab_MenuItem
		{
			idc = -1;
			text = "Rifle"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(1));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,7];[13] call cTab_fnc_userMenuSelect;";
		};
		class lmg_btn: cTab_MenuItem
		{
			idc = -1;
			text = "MG"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(2));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,8];[13] call cTab_fnc_userMenuSelect;";
		};
		class at_btn: cTab_MenuItem
		{
			idc = -1;
			text = "AT"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(3));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,9];[13] call cTab_fnc_userMenuSelect;";
		};
		class mmg_btn: cTab_MenuItem
		{
			idc = -1;
			text = "Static MG"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(4));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,10];[13] call cTab_fnc_userMenuSelect;";
		};
		class mat_btn: cTab_MenuItem
		{
			idc = -1;
			text = "Static AT"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(5));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,11];[13] call cTab_fnc_userMenuSelect;";
		};
		class aa_btn: cTab_MenuItem
		{
			idc = -1;
			text = "Static AA"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(6));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,13];[13] call cTab_fnc_userMenuSelect;";
		};
		class mmortar_btn: cTab_MenuItem
		{
			idc = -1;
			text = "Mortar"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(7));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,12];[13] call cTab_fnc_userMenuSelect;";
		};
		class exit: cTab_MenuExit
		{
			idc = -1;
			text = "Exit"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(cTab_MENU_MAX_ELEMENTS));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "[0] call cTab_fnc_userMenuSelect;";
		};
	};
};

class CasulSub1: cTab_RscControlsGroup
{
	#define cTab_MENU_MAX_ELEMENTS 5
	idc = 3305;
	x = QUOTE(MENU_X);
	y = QUOTE(MENU_Y);
	w = QUOTE(MENU_W);
	h = QUOTE(MENU_H(cTab_MENU_MAX_ELEMENTS));
	class controls
	{
		class IGUIBack_2204: cTab_IGUIBack
		{
			idc = IDC_USRMN_IGUIBACK_2204;
			x = 0;
			y = 0;
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_H(cTab_MENU_MAX_ELEMENTS));
		};
		class casltybtn: cTab_MenuItem
		{
			idc = IDC_USRMN_CASLTYBTN;
			text = "Casualty"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(1));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,20];[1] call cTab_fnc_userMenuSelect;";
		};
		class ccpbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_CCPBTN;
			text = "CCP"; //--- ToDo: Localize;
			toolTip = "Casualty Collection Point";
			x = 0;
			y = QUOTE(MENU_elementY(2));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,21];[1] call cTab_fnc_userMenuSelect;";
		};
		class basbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_BASBTN;
			text = "BAS"; //--- ToDo: Localize;
			toolTip = "Battalion Aid Station";
			x = 0;
			y = QUOTE(MENU_elementY(3));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,22];[1] call cTab_fnc_userMenuSelect;";
		};
		// Mass Casualty Incident
		class mcibtn: cTab_MenuItem
		{
			idc = IDC_USRMN_MCIBTN;
			text = "MCI"; //--- ToDo: Localize;
			toolTip = "Mass Casualty Incident";
			x = 0;
			y = QUOTE(MENU_elementY(4));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,23];[1] call cTab_fnc_userMenuSelect;";
		};
		class exit: cTab_MenuExit
		{
			idc = -1;
			text = "Exit"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(cTab_MENU_MAX_ELEMENTS));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "[0] call cTab_fnc_userMenuSelect;";
		};
	};
};

class GenSub1: cTab_RscControlsGroup
{
	#define cTab_MENU_MAX_ELEMENTS 3
	idc = 3306;
	x = QUOTE(MENU_X);
	y = QUOTE(MENU_Y);
	w = QUOTE(MENU_W);
	h = QUOTE(MENU_H(cTab_MENU_MAX_ELEMENTS));
	class controls
	{
		class IGUIBack_2205: cTab_IGUIBack
		{
			idc = IDC_USRMN_IGUIBACK_2205;
			x = 0;
			y = 0;
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_H(cTab_MENU_MAX_ELEMENTS));
		};
		class hqbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_HQBTN;
			text = "HQ"; //--- ToDo: Localize;
			toolTip = "Headquarters";
			x = 0;
			y = QUOTE(MENU_elementY(1));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,30];[1] call cTab_fnc_userMenuSelect;";
		};
		class lzbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_LZBTN;
			text = "LZ"; //--- ToDo: Localize;
			toolTip = "Landing Zone";
			x = 0;
			y = QUOTE(MENU_elementY(2));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,31];[1] call cTab_fnc_userMenuSelect;";
		};
		class exit: cTab_MenuExit
		{
			idc = -1;
			text = "Exit"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(cTab_MENU_MAX_ELEMENTS));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "[0] call cTab_fnc_userMenuSelect;";
		};
	};
};

class GolSub1: cTab_RscControlsGroup
{
	#define cTab_MENU_MAX_ELEMENTS 13
	idc = 3340;
	x = QUOTE(MENU_X);
	y = QUOTE(MENU_Y);
	w = QUOTE(MENU_W);
	h = QUOTE(MENU_H(cTab_MENU_MAX_ELEMENTS));
	class controls
	{
		class IGUIBack_2206: cTab_IGUIBack
		{
			idc = IDC_USRMN_IGUIBACK_2206;
			x = 0;
			y = 0;
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_H(cTab_MENU_MAX_ELEMENTS));
		};
		class goldestroybtn: cTab_MenuItem
		{
			idc = IDC_USRMN_GOLDESTROYBTN;
			text = "Destroy"; //--- ToDo: Localize;
			toolTip = "Destroy";
			x = 0;
			y = QUOTE(MENU_elementY(1));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,246];[1] call cTab_fnc_userMenuSelect;";
		};
		class goldotbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_GOLDOTBTN;
			text = "Dot"; //--- ToDo: Localize;
			toolTip = "Dot";
			x = 0;
			y = QUOTE(MENU_elementY(2));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,248];[1] call cTab_fnc_userMenuSelect;";
		};
		class golendbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_GOLENDBTN;
			text = "End"; //--- ToDo: Localize;
			toolTip = "End";
			x = 0;
			y = QUOTE(MENU_elementY(3));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,250];[1] call cTab_fnc_userMenuSelect;";
		};
		class golflagbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_GOLFLAGBTN;
			text = "Flag"; //--- ToDo: Localize;
			toolTip = "Flag";
			x = 0;
			y = QUOTE(MENU_elementY(4));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,252];[1] call cTab_fnc_userMenuSelect;";
		};
		class goljoinbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_GOLJOINBTN;
			text = "Join"; //--- ToDo: Localize;
			toolTip = "Join";
			x = 0;
			y = QUOTE(MENU_elementY(5));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,254];[1] call cTab_fnc_userMenuSelect;";
		};
		class golmarkerbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_GOLMARKERBTN;
			text = "Marker"; //--- ToDo: Localize;
			toolTip = "Marker";
			x = 0;
			y = QUOTE(MENU_elementY(6));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,256];[1] call cTab_fnc_userMenuSelect;";
		};
		class golobjectivebtn: cTab_MenuItem
		{
			idc = IDC_USRMN_GOLOBJECTIVEBTN;
			text = "Objective"; //--- ToDo: Localize;
			toolTip = "Objective";
			x = 0;
			y = QUOTE(MENU_elementY(7));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,258];[1] call cTab_fnc_userMenuSelect;";
		};
		class golpickupbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_GOLPICKUPBTN;
			text = "Pickup"; //--- ToDo: Localize;
			toolTip = "Pickup";
			x = 0;
			y = QUOTE(MENU_elementY(8));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,260];[1] call cTab_fnc_userMenuSelect;";
		};
		class golstartbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_GOLSTARTBTN;
			text = "Start"; //--- ToDo: Localize;
			toolTip = "Start";
			x = 0;
			y = QUOTE(MENU_elementY(9));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,262];[1] call cTab_fnc_userMenuSelect;";
		};
		class goltrianglebtn: cTab_MenuItem
		{
			idc = IDC_USRMN_GOLTRIANGLEBTN;
			text = "Triangle"; //--- ToDo: Localize;
			toolTip = "Triangle";
			x = 0;
			y = QUOTE(MENU_elementY(10));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,264];[1] call cTab_fnc_userMenuSelect;";
		};
		class golunknownbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_GOLUNKNOWNBTN;
			text = "Unknown"; //--- ToDo: Localize;
			toolTip = "Unknown";
			x = 0;
			y = QUOTE(MENU_elementY(11));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,266];[1] call cTab_fnc_userMenuSelect;";
		};
		class golwarningbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_GOLWARNINGBTN;
			text = "Warning"; //--- ToDo: Localize;
			toolTip = "Warning";
			x = 0;
			y = QUOTE(MENU_elementY(12));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,268];[1] call cTab_fnc_userMenuSelect;";
		};
		class golminefieldbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_GOLMINEFIELDBTN;
			text = "Minefield"; //--- ToDo: Localize;
			toolTip = "Minefield";
			x = 0;
			y = QUOTE(MENU_elementY(13));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "cTabUserSelIcon set [1,270];[1] call cTab_fnc_userMenuSelect;";
		};
		class exit: cTab_MenuExit
		{
			idc = -1;
			text = "Exit"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(14));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			action = "[0] call cTab_fnc_userMenuSelect;";
		};
	};
};