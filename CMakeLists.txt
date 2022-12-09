cmake_minimum_required(VERSION 3.16)

project(plasmoid-widgetname)

find_package(ECM 1.4.0 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${ECM_MODULE_PATH})

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)

find_package(Qt5 REQUIRED COMPONENTS
	Core
	Qml
)

find_package(KF5 REQUIRED COMPONENTS
	Plasma # Required for cmake plasma_install_package()
	# I18n
)

plasma_install_package(package com.github.zren.widgetname)

add_definitions(-DTRANSLATION_DOMAIN=\"plasma_applet_com.github.zren.widgetname\")

set(widgetnameplugin_SRCS
	plugin/widgetitem.cpp
	plugin/widgetnameplugin.cpp
)

add_library(widgetnameplugin SHARED ${widgetnameplugin_SRCS})

target_link_libraries(widgetnameplugin
	Qt::Core
	Qt::Qml
	# KF5::Plasma
	# KF5::I18n
)

install(TARGETS widgetnameplugin DESTINATION ${KDE_INSTALL_QMLDIR}/com/github/zren/widgetname)
install(FILES plugin/qmldir DESTINATION ${KDE_INSTALL_QMLDIR}/com/github/zren/widgetname)

