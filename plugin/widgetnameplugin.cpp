#include "widgetnameplugin.h"
#include "widgetitem.h"

void WidgetNamePlugin::registerTypes(const char *uri)
{
	Q_ASSERT(QLatin1String(uri) == QLatin1String("com.github.zren.widgetname"));

	qmlRegisterType<WidgetItem>(uri, 1, 0, "WidgetItem");
}
