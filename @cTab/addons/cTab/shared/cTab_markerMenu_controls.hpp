class MainSubmenu: cTab_RscControlsGroup
{
	#ifndef cTab_IS_TABLET
		#define cTab_MENU_MAX_ELEMENTS 6
	#else
		#define cTab_MENU_MAX_ELEMENTS 7
	#endif
	idc = IDC_USRMN_IGUI_MAIN;
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
		class op1btn: cTab_MenuItem
		{
			idc = IDC_USRMN_OPF1BTN;
			text = "Enemy forces"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(1));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			onMouseButtonClick = "[3301,(_this select 5)] call cTab_fnc_userMenuSelect;";
		};
    class op2btn: cTab_MenuItem
		{
			idc = IDC_USRMN_OPF2BTN;
			text = "Enemy support"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(2));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			onMouseButtonClick = "[3302,(_this select 5)] call cTab_fnc_userMenuSelect;";
		};
		class medbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_MEDBTN;
			text = "Medical"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(3));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			onMouseButtonClick = "[3303,(_this select 5)] call cTab_fnc_userMenuSelect;";
		};
		class genbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_GENBTN;
			text = "General"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(4));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			onMouseButtonClick = "[3304,(_this select 5)] call cTab_fnc_userMenuSelect;";
		};
		class dotbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_DOTBTN;
			text = "Dot (text)"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(5));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			onMouseButtonClick = "cTabUserSelIcon set [1,40];[1,true] call cTab_fnc_userMenuSelect;";
		};
		#ifdef cTab_IS_TABLET
			class lockUavCam: cTab_MenuItem
			{
				idc = -1;
				text = "Lock UAV Cam"; //--- ToDo: Localize;
				toolTip = "Lock UAV Cam to this position, a UAV has to be previously selected";
				x = 0;
				y = QUOTE(MENU_elementY(6));
				w = QUOTE(MENU_W);
				h = QUOTE(MENU_elementH);
				sizeEx = QUOTE(MENU_sizeEx);
				onMouseButtonClick = "[2,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "[0,(_this select 5)] call cTab_fnc_userMenuSelect;";
		};
	};
};

class EnemyForces: cTab_RscControlsGroup
{
	#define cTab_MENU_MAX_ELEMENTS 8
	idc = IDC_USRMN_IGUI_FORCES;
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
			onMouseButtonClick = "cTabUserSelIcon set [1,0];[3311,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "cTabUserSelIcon set [1,1];[3311,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "cTabUserSelIcon set [1,2];[3311,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "cTabUserSelIcon set [1,3];[3311,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "cTabUserSelIcon set [1,4];[3311,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "cTabUserSelIcon set [1,5];[3311,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "cTabUserSelIcon set [1,6];[3311,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "[0,(_this select 5)] call cTab_fnc_userMenuSelect;";
		};
	};
};

class EnemySupport: cTab_RscControlsGroup
{
	#define cTab_MENU_MAX_ELEMENTS 6
	idc = IDC_USRMN_IGUI_SUPPORT;
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
		// class rifle_btn: cTab_MenuItem
		// {
		// 	idc = -1;
		// 	text = "Rifle"; //--- ToDo: Localize;
		// 	x = 0;
		// 	y = QUOTE(MENU_elementY(1));
		// 	w = QUOTE(MENU_W);
		// 	h = QUOTE(MENU_elementH);
		// 	sizeEx = QUOTE(MENU_sizeEx);
		// 	onMouseButtonClick = "cTabUserSelIcon set [1,7];[3312,(_this select 5)] call cTab_fnc_userMenuSelect;";
		// };
		// class lmg_btn: cTab_MenuItem
		// {
		// 	idc = -1;
		// 	text = "MG"; //--- ToDo: Localize;
		// 	x = 0;
		// 	y = QUOTE(MENU_elementY(1));
		// 	w = QUOTE(MENU_W);
		// 	h = QUOTE(MENU_elementH);
		// 	sizeEx = QUOTE(MENU_sizeEx);
		// 	onMouseButtonClick = "cTabUserSelIcon set [1,8];[3312,(_this select 5)] call cTab_fnc_userMenuSelect;";
		// };
		// class at_btn: cTab_MenuItem
		// {
		// 	idc = -1;
		// 	text = "AT"; //--- ToDo: Localize;
		// 	x = 0;
		// 	y = QUOTE(MENU_elementY(2));
		// 	w = QUOTE(MENU_W);
		// 	h = QUOTE(MENU_elementH);
		// 	sizeEx = QUOTE(MENU_sizeEx);
		// 	onMouseButtonClick = "cTabUserSelIcon set [1,9];[3312,(_this select 5)] call cTab_fnc_userMenuSelect;";
		// };
		class static_mg_btn: cTab_MenuItem
		{
			idc = -1;
			text = "Static MG"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(1));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			onMouseButtonClick = "cTabUserSelIcon set [1,10];[1,(_this select 5)] call cTab_fnc_userMenuSelect;";
		};
		class static_at_btn: cTab_MenuItem
		{
			idc = -1;
			text = "Static AT"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(2));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			onMouseButtonClick = "cTabUserSelIcon set [1,11];[1,(_this select 5)] call cTab_fnc_userMenuSelect;";
		};
		class static_aa_btn: cTab_MenuItem
		{
			idc = -1;
			text = "Static AA"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(3));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			onMouseButtonClick = "cTabUserSelIcon set [1,13];[1,(_this select 5)] call cTab_fnc_userMenuSelect;";
		};
		class static_mortar_btn: cTab_MenuItem
		{
			idc = -1;
			text = "Mortar"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(4));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			onMouseButtonClick = "cTabUserSelIcon set [1,12];[1,(_this select 5)] call cTab_fnc_userMenuSelect;";
		};
    class roadblock_btn: cTab_MenuItem
		{
			idc = -1;
			text = "Roadblock"; //--- ToDo: Localize;
			x = 0;
			y = QUOTE(MENU_elementY(5));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			onMouseButtonClick = "cTabUserSelIcon set [1,14];[1,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "[0,(_this select 5)] call cTab_fnc_userMenuSelect;";
		};
	};
};

class EnemySubSize: cTab_RscControlsGroup
{
	#define cTab_MENU_MAX_ELEMENTS 6
	idc = IDC_USRMN_IGUISUB_SIZE;
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
			onMouseButtonClick = "[3312,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "cTabUserSelIcon set [2,1];[3312,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "cTabUserSelIcon set [2,2];[3312,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "cTabUserSelIcon set [2,3];[3312,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "cTabUserSelIcon set [2,4];[3312,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "[0,(_this select 5)] call cTab_fnc_userMenuSelect;";
		};
	};
};

class EnemySubDirection: cTab_RscControlsGroup
{
	#define cTab_MENU_MAX_ELEMENTS 10
	idc = IDC_USRMN_IGUISUB_DIR;
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
			onMouseButtonClick = "[1,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "cTabUserSelIcon set [3,1];[1,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "cTabUserSelIcon set [3,2];[1,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "cTabUserSelIcon set [3,3];[1,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "cTabUserSelIcon set [3,4];[1,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "cTabUserSelIcon set [3,5];[1,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "cTabUserSelIcon set [3,6];[1,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "cTabUserSelIcon set [3,7];[1,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "cTabUserSelIcon set [3,8];[1,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "[0,(_this select 5)] call cTab_fnc_userMenuSelect;";
		};
	};
};

class CasulSub1: cTab_RscControlsGroup
{
	#define cTab_MENU_MAX_ELEMENTS 5
	idc = IDC_USRMN_IGUISUB_MED;
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
			onMouseButtonClick = "cTabUserSelIcon set [1,20];[1,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "cTabUserSelIcon set [1,21];[1,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "cTabUserSelIcon set [1,22];[1,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "cTabUserSelIcon set [1,23];[1,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "[0,(_this select 5)] call cTab_fnc_userMenuSelect;";
		};
	};
};

class GenSub1: cTab_RscControlsGroup
{
	#define cTab_MENU_MAX_ELEMENTS 7
	idc = IDC_USRMN_IGUISUB_GEN;
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
			onMouseButtonClick = "cTabUserSelIcon set [1,30];[1,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "cTabUserSelIcon set [1,31];[1,(_this select 5)] call cTab_fnc_userMenuSelect;";
		};
		class rpbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_RPBTN;
			text = "RP"; //--- ToDo: Localize;
			toolTip = "Rally point";
			x = 0;
			y = QUOTE(MENU_elementY(3));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			onMouseButtonClick = "cTabUserSelIcon set [1,32];[1,(_this select 5)] call cTab_fnc_userMenuSelect;";
		};
		class wpbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_WPBTN;
			text = "WP"; //--- ToDo: Localize;
			toolTip = "Waypoint";
			x = 0;
			y = QUOTE(MENU_elementY(4));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			onMouseButtonClick = "cTabUserSelIcon set [1,33];[1,(_this select 5)] call cTab_fnc_userMenuSelect;";
		};
		class objbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_OBJBTN;
			text = "Objective"; //--- ToDo: Localize;
			toolTip = "Objective";
			x = 0;
			y = QUOTE(MENU_elementY(5));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
			onMouseButtonClick = "cTabUserSelIcon set [1,34];[1,(_this select 5)] call cTab_fnc_userMenuSelect;";
		};
		class minefieldbtn: cTab_MenuItem
		{
			idc = IDC_USRMN_MINEBTN;
			text = "Minefield"; //--- ToDo: Localize;
			toolTip = "Minefield";
			x = 0;
			y = QUOTE(MENU_elementY(6));
			w = QUOTE(MENU_W);
			h = QUOTE(MENU_elementH);
			sizeEx = QUOTE(MENU_sizeEx);
      onMouseButtonClick = "cTabUserSelIcon set [1,35];[1,(_this select 5)] call cTab_fnc_userMenuSelect;";
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
			onMouseButtonClick = "[0,(_this select 5)] call cTab_fnc_userMenuSelect;";
		};
	};
};
