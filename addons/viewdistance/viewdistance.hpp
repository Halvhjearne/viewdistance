/*
	viewdistance control for arma 3

	Copyright (C) 2015  Halvhjearne

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.

	Contact : halvhjearne@gmail.com
*/

class HALV_veiwdialog
{
	idd=6667;
	moveingenabled=true;
	onLoad = "_this call HALV_setsliderpos;";
	class controls
	{
		class HALV_viewdistance_back: HALV_IGUIBack
		{
			idc = -1;
			x = 0.293726 * safezoneW + safezoneX;
			y = 0.356949 * safezoneH + safezoneY;
			w = 0.412548 * safezoneW;
			h = 0.418149 * safezoneH;
		};
		class HALV_viewdistance_frame: HALV_RscFrame
		{
			idc = -1;
			text = "View Distance settings by Halv"; //--- ToDo: Localize;
			x = 0.293726 * safezoneW + safezoneX;
			y = 0.356949 * safezoneH + safezoneY;
			w = 0.412548 * safezoneW;
			h = 0.418149 * safezoneH;
		};

		class HALV_viewdistance_text1frame: HALV_RscFrame
		{
			idc = -1;
			x = 0.30404 * safezoneW + safezoneX;
			y = 0.378957 * safezoneH + safezoneY;
			w = 0.391921 * safezoneW;
			h = 0.0330118 * safezoneH;
		};
		class HALV_viewdistance_text2frame: HALV_RscFrame
		{
			idc = -1;
			x = 0.649549 * safezoneW + safezoneX;
			y = 0.422973 * safezoneH + safezoneY;
			w = 0.0464117 * safezoneW;
			h = 0.0330118 * safezoneH;
		};
		class HALV_viewdistance_text3frame: HALV_RscFrame
		{
			idc = -1;
			x = 0.304039 * safezoneW + safezoneX;
			y = 0.466988 * safezoneH + safezoneY;
			w = 0.391921 * safezoneW;
			h = 0.0330118 * safezoneH;
		};
		class HALV_viewdistance_text4frame: HALV_RscFrame
		{
			idc = -1;
			x = 0.649549 * safezoneW + safezoneX;
			y = 0.511004 * safezoneH + safezoneY;
			w = 0.0464117 * safezoneW;
			h = 0.0330118 * safezoneH;
		};
		class HALV_viewdistance_text5frame: HALV_RscFrame
		{
			idc = -1;
			x = 0.304039 * safezoneW + safezoneX;
			y = 0.55502 * safezoneH + safezoneY;
			w = 0.391921 * safezoneW;
			h = 0.0330118 * safezoneH;
		};

		class HALV_viewdistance_text6frame: HALV_RscFrame
		{
			idc = -1;
			x = 0.649548 * safezoneW + safezoneX;
			y = 0.599035 * safezoneH + safezoneY;
			w = 0.0464117 * safezoneW;
			h = 0.0330118 * safezoneH;
		};
		class HALV_viewdistance_text7frame: HALV_RscFrame
		{
			idc = -1;
			x = 0.30404 * safezoneW + safezoneX;
			y = 0.643051 * safezoneH + safezoneY;
			w = 0.391921 * safezoneW;
			h = 0.0330118 * safezoneH;
		};
		class HALV_viewdistance_text8frame: HALV_RscFrame
		{
			idc = -1;
			x = 0.649548 * safezoneW + safezoneX;
			y = 0.687067 * safezoneH + safezoneY;
			w = 0.0464117 * safezoneW;
			h = 0.0330118 * safezoneH;
		};
		class HALV_viewdistance_text1: HALV_RscStructuredText
		{
			idc = -1;
			text = "View Distance Settings"; //--- ToDo: Localize;
			x = 0.30404 * safezoneW + safezoneX;
			y = 0.378957 * safezoneH + safezoneY;
			w = 0.391921 * safezoneW;
			h = 0.0330118 * safezoneH;
		};
		class HALV_viewdistance_text2: HALV_RscStructuredText
		{
			idc = 6669;
			text = "0"; //--- ToDo: Localize;
			x = 0.649549 * safezoneW + safezoneX;
			y = 0.422973 * safezoneH + safezoneY;
			w = 0.0464117 * safezoneW;
			h = 0.0330118 * safezoneH;
		};

		class HALV_viewdistance_text3: HALV_RscStructuredText
		{
			idc = -1;
			text = "Object View Distance"; //--- ToDo: Localize;
			x = 0.304039 * safezoneW + safezoneX;
			y = 0.466988 * safezoneH + safezoneY;
			w = 0.391921 * safezoneW;
			h = 0.0330118 * safezoneH;
		};
		class HALV_viewdistance_text4: HALV_RscStructuredText
		{
			idc = 6671;
			text = "0"; //--- ToDo: Localize;
			x = 0.649549 * safezoneW + safezoneX;
			y = 0.511004 * safezoneH + safezoneY;
			w = 0.0464117 * safezoneW;
			h = 0.0330118 * safezoneH;
		};
		class HALV_viewdistance_text5: HALV_RscStructuredText
		{
			idc = -1;
			text = "Object View Distance (Shadow)"; //--- ToDo: Localize;
			x = 0.304039 * safezoneW + safezoneX;
			y = 0.55502 * safezoneH + safezoneY;
			w = 0.391921 * safezoneW;
			h = 0.0330118 * safezoneH;
		};

		class HALV_viewdistance_text6: HALV_RscStructuredText
		{
			idc = 6673;
			text = "0"; //--- ToDo: Localize;
			x = 0.649548 * safezoneW + safezoneX;
			y = 0.599035 * safezoneH + safezoneY;
			w = 0.0464117 * safezoneW;
			h = 0.0330118 * safezoneH;
		};
		class HALV_viewdistance_text7: HALV_RscStructuredText
		{
			idc = -1;
			text = "Terrain Grid / Grass"; //--- ToDo: Localize;
			x = 0.30404 * safezoneW + safezoneX;
			y = 0.643051 * safezoneH + safezoneY;
			w = 0.391921 * safezoneW;
			h = 0.0330118 * safezoneH;
		};
		class HALV_viewdistance_text8: HALV_RscStructuredText
		{
			idc = 6675;
			text = "35"; //--- ToDo: Localize;
			x = 0.649548 * safezoneW + safezoneX;
			y = 0.687067 * safezoneH + safezoneY;
			w = 0.0464117 * safezoneW;
			h = 0.0330118 * safezoneH;
		};
		class HALV_viewdistance_Default: HALV_RscButton
		{
			idc = -1;
			text = "Default Settings"; //--- ToDo: Localize;
			x = 0.432961 * safezoneW + safezoneX;
			y = 0.731082 * safezoneH + safezoneY;
			w = 0.134078 * safezoneW;
			h = 0.0330118 * safezoneH;
			action = "[]spawn{HALV_viewdistance_values = HALV_viewdistance_Defaults;closeDialog 0;sleep 0.2;createDialog 'HALV_veiwdialog'};";
		};
		class HALV_viewdistance_Accept: HALV_RscButton
		{
			idc = -1;
			text = "Accept settings"; //--- ToDo: Localize;
			x = 0.30404 * safezoneW + safezoneX;
			y = 0.731082 * safezoneH + safezoneY;
			w = 0.123764 * safezoneW;
			h = 0.0330118 * safezoneH;
			action = "call HALV_setviewdistances;";
		};
		class HALV_viewdistance_Exit: HALV_RscButton
		{
			idc = -1;
			text = "Cancel / Exit"; //--- ToDo: Localize;
			x = 0.572196 * safezoneW + safezoneX;
			y = 0.731082 * safezoneH + safezoneY;
			w = 0.123764 * safezoneW;
			h = 0.0330118 * safezoneH;
			action = "closeDialog 0;";
		};
		class HALV_viewdistance_slider1: HALV_RscSlider
		{
			idc = 6668;
			x = 0.309197 * safezoneW + safezoneX;
			y = 0.422973 * safezoneH + safezoneY;
			w = 0.335195 * safezoneW;
			h = 0.0330118 * safezoneH;
			onSliderPosChanged = "_this call HALV_slideviewdistances;false";
			tooltip = "Slide to set view distance"; //--- ToDo: Localize;
		};
		class HALV_viewdistance_slider2: HALV_RscSlider
		{
			idc = 6670;
			x = 0.309197 * safezoneW + safezoneX;
			y = 0.511004 * safezoneH + safezoneY;
			w = 0.335195 * safezoneW;
			h = 0.0330118 * safezoneH;
			tooltip = "Slide to set Object view distance"; //--- ToDo: Localize;
			onSliderPosChanged = "_this call HALV_slideviewdistances;false";
		};
		class HALV_viewdistance_slider3: HALV_RscSlider
		{
			idc = 6672;
			x = 0.309197 * safezoneW + safezoneX;
			y = 0.599035 * safezoneH + safezoneY;
			w = 0.335195 * safezoneW;
			h = 0.0330118 * safezoneH;
			tooltip = "Slide to set Object (shadow) view distance"; //--- ToDo: Localize;
			onSliderPosChanged = "_this call HALV_slideviewdistances;false";
		};
		class HALV_viewdistance_slider4: HALV_RscSlider
		{
			idc = 6674;
			x = 0.309197 * safezoneW + safezoneX;
			y = 0.687067 * safezoneH + safezoneY;
			w = 0.335195 * safezoneW;
			h = 0.0330118 * safezoneH;
			tooltip = "Slide to set Terrain Grid"; //--- ToDo: Localize;
			onSliderPosChanged = "_this call HALV_slideviewdistances;false";
		};
	};
};
