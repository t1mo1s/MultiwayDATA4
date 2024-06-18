QT += quick

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Collect all the source files
SOURCES += \
    main.cpp \
    $$files(mvc/*.cpp) \
    $$files(viewElements/*.cpp) \
    $$files(utils/*.cpp) \

# Collect all the header files
HEADERS += \
    $$files(mvc/*.h) \
    $$files(viewElements/*.h) \
    $$files(utils/*.h) \
    utils/Type.h

# Resource files
RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Custom definitions and include paths
DEFINES += MY_CUSTOM_DEFINE
INCLUDEPATH += /path/to/custom/includes

# Extra compiler flags
QMAKE_CXXFLAGS += -Wall -g
