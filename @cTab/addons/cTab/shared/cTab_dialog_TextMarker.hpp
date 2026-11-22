class cTab_dialog_TextMarker {
    idd = 9900;
    movingEnable = 0;
    enableSimulation = 1; // Keep game running in background (set to 0 to pause)

    class controlsBackground {
        // Transparent black background
        class Background: cTab_RscText {
            idc = -1;
            x = QUOTE(0.35 * safezoneW + safezoneX);
            y = QUOTE(0.40 * safezoneH + safezoneY);
            w = QUOTE(0.30 * safezoneW);
            h = QUOTE(0.16 * safezoneH);
            colorBackground[] = {0, 0, 0, 0.5};
        };
    };

    class controls {
        // Label
        class cTab_dialog_TextMarker_Controls_PromptText: cTab_RscStructuredText {
            idc = 9901;
            text = "Marker text (leave blank for default):";
            x = QUOTE(0.36 * safezoneW + safezoneX);
            y = QUOTE(0.41 * safezoneH + safezoneY);
            w = QUOTE(0.28 * safezoneW);
            h = QUOTE(0.04 * safezoneH);
            colorBackground[] = {0, 0, 0, 0};
        };

        // Text input field
        class cTab_dialog_TextMarker_Controls_InputBox: cTab_RscEdit {
            idc = 9902;
            text = "";
            x = QUOTE(0.36 * safezoneW + safezoneX);
            y = QUOTE(0.46 * safezoneH + safezoneY);
            w = QUOTE(0.28 * safezoneW);
            h = QUOTE(0.04 * safezoneH);
            colorBackground[] = {0.1, 0.1, 0.1, 0.9};
            colorText[] = {1, 1, 1, 1};
        };

        // Cancel button
        class cTab_dialog_TextMarker_Controls_ButtonCancel: cTab_RscButton {
            idc = 9903;
            text = "Cancel";
            x = QUOTE(0.36 * safezoneW + safezoneX);
            y = QUOTE(0.51 * safezoneH + safezoneY);
            w = QUOTE(0.13 * safezoneW);
            h = QUOTE(0.04 * safezoneH);
            onButtonClick = "[] call cTab_fnc_dialogMarkerNameClickCancel;";
        };

        // OK button
        class cTab_dialog_TextMarker_Controls_ButtonOk: cTab_RscButton {
            idc = 9904;
            text = "OK";
            x = QUOTE(0.51 * safezoneW + safezoneX);
            y = QUOTE(0.51 * safezoneH + safezoneY);
            w = QUOTE(0.13 * safezoneW);
            h = QUOTE(0.04 * safezoneH);
            onButtonClick = "[] call cTab_fnc_dialogMarkerNameClickOK;";
        };
    };
};
