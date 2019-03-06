QT += core gui

greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets

HEADERS += \
    data_types.h \
    employee_data.h \
    data_table_model.h \
    style_delegate.h

SOURCES += \
    employee_data.cpp \
    data_table_model.cpp \
    main_table_view.cpp \
    style_delegate.cpp
