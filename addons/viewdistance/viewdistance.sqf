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

waitUntil{!isNull (findDisplay 46) && !dialog};

_ObjVD = getObjectViewDistance;
HALV_viewdistance_values = [ViewDistance,_ObjVD select 0,_ObjVD select 1,35];

HALV_setsliderpos = compileFinal "
	_display = _this select 0;
	_ctrl = _display displayCtrl 6668;
	_ctrl sliderSetRange [199,10000];
	_ctrl sliderSetSpeed [1,3];
	_ctrl sliderSetPosition (HALV_viewdistance_values select 0);
	_ctrl = _display displayCtrl 6669;
	_ctrl ctrlSetText str(HALV_viewdistance_values select 0);
	_ctrl = _display displayCtrl 6670;
	_ctrl sliderSetRange [199,HALV_viewdistance_values select 0];
	_ctrl sliderSetSpeed [1,3];
	_ctrl sliderSetPosition (HALV_viewdistance_values select 1);
	_ctrl = _display displayCtrl 6671;
	_ctrl ctrlSetText str(HALV_viewdistance_values select 1);
	_ctrl = _display displayCtrl 6672;
	_ctrl sliderSetRange [199,HALV_viewdistance_values select 0];
	_ctrl sliderSetSpeed [1,3];
	_ctrl sliderSetPosition (HALV_viewdistance_values select 2);
	_ctrl = _display displayCtrl 6673;
	_ctrl ctrlSetText str(HALV_viewdistance_values select 2);
	_ctrl = _display displayCtrl 6674;
	_ctrl sliderSetRange [-1,35];
	_ctrl sliderSetSpeed [1, 1];
	_ctrl sliderSetPosition (HALV_viewdistance_values select 3);
	_ctrl = _display displayCtrl 6675;
	_ctrl ctrlSetText str(HALV_viewdistance_values select 3);
";

HALV_slideviewdistances = compileFinal "
	disableSerialization;
	_ctrl = _this select 0;
	_val = _this select 1;
	_msg = if(count _this > 2)then{_this select 2}else{true};
	_val = round _val;
	switch(str _ctrl)do{
		case 'Control #6668':{
			if(_val < 200)then{_val = -1;};
			HALV_viewdistance_values set [0,round _val];
			_txt = _val;
			if(_val < 200)then{_txt = 'Default';};
			if(_msg)then{hintSilent format['ViewDistance: %1',_txt];};
			_ctrl = findDisplay 6667 displayCtrl 6669;
			_ctrl ctrlSetText format['%1',_txt];
			_ctrl = findDisplay 6667 displayCtrl 6670;
			if(_val < 200)then{_ctrl sliderSetPosition 0;};
			_spos = sliderPosition _ctrl;
			_ctrl sliderSetRange [199,_val];
			if(_spos > _val)then{[_ctrl,_val,false]call HALV_slideviewdistances;};
			_ctrl = findDisplay 6667 displayCtrl 6672;
			if(_val < 200)then{_ctrl sliderSetPosition 0;};
			_spos = sliderPosition _ctrl;
			_ctrl sliderSetRange [199,_val];
			if(_spos > _val)then{[_ctrl,_val,false]call HALV_slideviewdistances;};
		};
		case 'Control #6670':{
			_txt = _val;
			if(_val < 200)then{_val = -1;};
			if(_val < 200)then{_txt = 'Default';};
			HALV_viewdistance_values set [1,_val];
			if(_msg)then{hintSilent format['ObjectViewDistance: %1',_txt];};
			_ctrl = findDisplay 6667 displayCtrl 6671;
			_ctrl ctrlSetText format['%1',_txt];
			_ctrl = findDisplay 6667 displayCtrl 6672;
			if(_val < 200)then{_ctrl sliderSetPosition 0;};
			_spos = sliderPosition _ctrl;
			_ctrl sliderSetRange [199,_val];
			if(_spos > _val)then{[_ctrl,_val,false]call HALV_slideviewdistances;};
		};
		case 'Control #6672':{
			_txt = _val;
			if(_val < 200)then{_val = -1;};
			if(_val < 200)then{_txt = 'Default';};
			HALV_viewdistance_values set [2,_val];
			if(_msg)then{hintSilent format['ObjectViewDistance (shadow): %1',_txt];};
			_ctrl = findDisplay 6667 displayCtrl 6673;
			_ctrl ctrlSetText format['%1',_txt];
		};
		case 'Control #6674':{
			if(_val < 0)then{_val = -1;};
			HALV_viewdistance_values set [3,_val];
			if(_val < 0)then{_val = 'Default';};
			hintSilent format['Terrain Grid: %1',_val];
			_ctrl = findDisplay 6667 displayCtrl 6675;
			_ctrl ctrlSetText format['%1',_val];
		};
	};
";

HALV_setviewdistances = {
	setViewDistance (HALV_viewdistance_values select 0);
	setObjectViewDistance [(HALV_viewdistance_values select 1),(HALV_viewdistance_values select 2)];
	setTerrainGrid (HALV_viewdistance_values select 3);
	_txt = parseText format["
		<t size='1.25'align='left'shadow='1'>View Distance: </t><t size='1.25'align='right'shadow='1'>%1m</t><br/>
		<t size='1.25'align='left'shadow='1'>Object View Distance: </t><t size='1.25'align='right'shadow='1'>%2m</t><br/>
		<t size='1.25'align='left'shadow='1'>Object View Distance (shadow): </t><t size='1.25'align='right'shadow='1'>%3m</t><br/>
		<t size='1.25'align='left'shadow='1'>Terrain Grid / Grass: </t><t size='1.25'align='right'shadow='1'>%4m</t>
		",
		(HALV_viewdistance_values select 0),
		(HALV_viewdistance_values select 1),
		(HALV_viewdistance_values select 2),
		(HALV_viewdistance_values select 3)
	];
	if(_this)then{
		profileNamespace setVariable ["Halv_viewdistance",HALV_viewdistance_values];
	};
	hint _txt;
	systemChat str _txt;
};

_preset = profileNamespace getVariable ["Halv_viewdistance",[]];
if !(_preset isEqualTo [])then{
	HALV_viewdistance_values = _preset;
//	false call HALV_setviewdistances;
};
