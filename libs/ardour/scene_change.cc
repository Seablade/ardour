/*
    Copyright (C) 2014 Paul Davis

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

*/

#include "ardour/midi_scene_change.h"

#include "i18n.h"

using namespace PBD;
using namespace ARDOUR;

std::string SceneChange::xml_node_name = X_("SceneChange");

boost::shared_ptr<SceneChange>
SceneChange::factory (const XMLNode& node, int version)
{
	const XMLProperty* prop = node.property (X_("type"));

	if (prop->value() == X_("MIDI")) {
		return boost::shared_ptr<SceneChange> (new MIDISceneChange (node, version));
	}

	return boost::shared_ptr<SceneChange>();
}

void
SceneChange::set_time (framepos_t t)
{
	_time = t;
}