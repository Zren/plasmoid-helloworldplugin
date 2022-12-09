import QtQuick 2.4
import org.kde.plasma.components 3.0 as PlasmaComponents3
import org.kde.plasma.plasmoid 2.0

import com.github.zren.widgetname 1.0 as WidgetName

Item {
	id: widget

	WidgetName.WidgetItem {
		id: widgetItem
		number: 123
	}
	Plasmoid.fullRepresentation: PlasmaComponents3.Button {
		text: widgetItem.number
		onClicked: widgetItem.randomize()
	}
}
