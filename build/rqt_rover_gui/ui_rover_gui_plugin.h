/********************************************************************************
** Form generated from reading UI file 'rover_gui_plugin.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROVER_GUI_PLUGIN_H
#define UI_ROVER_GUI_PLUGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>
#include "BWTabWidget.h"
#include "CameraFrame.h"
#include "IMUFrame.h"
#include "MapFrame.h"
#include "USFrame.h"

QT_BEGIN_NAMESPACE

class Ui_RoverGUI
{
public:
    BWTabWidget *tab_widget;
    QWidget *sensor_display_tab;
    rqt_rover_gui::IMUFrame *imu_frame;
    rqt_rover_gui::MapFrame *map_frame;
    rqt_rover_gui::USFrame *us_frame;
    rqt_rover_gui::CameraFrame *camera_frame;
    QCheckBox *gps_checkbox;
    QCheckBox *ekf_checkbox;
    QCheckBox *encoder_checkbox;
    QRadioButton *map_manual_radio_button;
    QRadioButton *map_auto_radio_button;
    QPushButton *map_popout_button;
    QWidget *simulation_parameters_tab;
    QFrame *setup_group;
    QGroupBox *target_distribution_group_box;
    QRadioButton *uniform_distribution_radio_button;
    QRadioButton *powerlaw_distribution_radio_button;
    QRadioButton *clustered_distribution_radio_button;
    QRadioButton *custom_distribution_radio_button;
    QPushButton *custom_world_path_button;
    QGroupBox *round_type_button_group;
    QRadioButton *joystick_radio_button;
    QRadioButton *final_radio_button;
    QLabel *label_5;
    QComboBox *texture_combobox;
    QLabel *custom_world_path;
    QCheckBox *override_num_rovers_checkbox;
    QComboBox *custom_num_rovers_combobox;
    QComboBox *simulation_timer_combo_box;
    QLabel *simulation_timer_label;
    QLabel *label_7;
    QLabel *rover_image_label;
    QPushButton *build_simulation_button;
    QFrame *frame_2;
    QLabel *label_39;
    QLabel *label_40;
    QLabel *label_41;
    QLabel *label_42;
    QLabel *label_43;
    QLabel *label_44;
    QLabel *sonar_range_res;
    QLabel *sonar_max_angle;
    QLabel *sonar_min_angle;
    QLabel *sonar_max;
    QLabel *sonar_min;
    QLabel *sonar_horz_res;
    QLabel *label_65;
    QLabel *sonar_gaussian_noise;
    QPushButton *clear_simulation_button;
    QLabel *label_11;
    QFrame *frame_4;
    QLabel *label_23;
    QLabel *label_22;
    QLabel *label_24;
    QLabel *label_26;
    QLabel *gps_update_rate;
    QLabel *gps_ref_lat;
    QLabel *gps_ref_long;
    QLabel *gps_ref_heading;
    QLabel *label_49;
    QLabel *label_50;
    QLabel *label_51;
    QLabel *gps_drift;
    QLabel *gps_drift_freq;
    QLabel *gps_noise;
    QLabel *label_52;
    QLabel *gps_ref_alt;
    QLabel *label_12;
    QFrame *frame_5;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *label_37;
    QLabel *label_38;
    QLabel *imu_update_rate;
    QLabel *imu_rate_drift;
    QLabel *imu_rate_noise;
    QLabel *imu_heading_drift;
    QLabel *imu_heading_noise;
    QLabel *imu_accel_drift;
    QLabel *imu_accel_noise;
    QLabel *imu_rpy_offsets;
    QLabel *imu_noise;
    QLabel *label_63;
    QLabel *label_64;
    QLabel *label_17;
    QFrame *frame_6;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *camera_update_rate;
    QLabel *camera_width;
    QLabel *camera_height;
    QLabel *camera_format;
    QLabel *label_25;
    QLabel *camera_noise_mean;
    QLabel *label_45;
    QLabel *camera_noise_stdev;
    QPushButton *visualize_simulation_button;
    QLabel *label_10;
    QWidget *stats_tab;
    QLabel *label_6;
    QLabel *num_targets_detected_label;
    QLabel *label_8;
    QLabel *num_targets_collected_label;
    QLabel *label_9;
    QLabel *perc_of_time_avoiding_obstacles;
    QLabel *currentSimulationTimeLabel;
    QLabel *simulationTimerStartLabel;
    QLabel *simulationTimerStopLabel;
    QLabel *currentSimulationTimeTitle;
    QLabel *simulationTimerStartTitle;
    QLabel *simulationTimerStopTitle;
    QFrame *Simulation_Timer_Frame;
    QLabel *simulation_timer_frame_label;
    QFrame *control_frame;
    QGroupBox *control_group_box;
    QRadioButton *autonomous_control_radio_button;
    QRadioButton *joystick_control_radio_button;
    QPushButton *all_stop_button;
    QPushButton *all_autonomous_button;
    QFrame *joystick_frame;
    QLCDNumber *joy_lcd_drive_forward;
    QLCDNumber *joy_lcd_drive_left;
    QLCDNumber *joy_lcd_drive_right;
    QLCDNumber *joy_lcd_drive_back;
    QLCDNumber *joy_lcd_gripper_up;
    QLCDNumber *joy_lcd_gripper_open;
    QLCDNumber *joy_lcd_gripper_close;
    QLCDNumber *joy_lcd_gripper_down;
    QLabel *drive_label;
    QLabel *gripper_label;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *version_number_label;
    QLabel *rover_name;
    BWTabWidget *log_tab;
    QWidget *info_log_tab;
    QTextBrowser *info_log;
    QWidget *diag_log_tab;
    QTextBrowser *diag_log;
    QFrame *Rover_frame;
    QListWidget *rover_diags_list;
    QListWidget *rover_list;
    QListWidget *map_selection_list;
    QLabel *label_13;
    QLabel *map_list_label;
    QLabel *gps_numSV_label;
    QButtonGroup *rover_control_button_group;
    QButtonGroup *map_display_button_group;

    void setupUi(QWidget *RoverGUI)
    {
        if (RoverGUI->objectName().isEmpty())
            RoverGUI->setObjectName(QString::fromUtf8("RoverGUI"));
        RoverGUI->resize(1100, 725);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RoverGUI->sizePolicy().hasHeightForWidth());
        RoverGUI->setSizePolicy(sizePolicy);
        RoverGUI->setMinimumSize(QSize(1100, 725));
        RoverGUI->setMaximumSize(QSize(1100, 725));
        RoverGUI->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"border-color: rgb(255, 255, 255);"));
        tab_widget = new BWTabWidget(RoverGUI);
        tab_widget->setObjectName(QString::fromUtf8("tab_widget"));
        tab_widget->setGeometry(QRect(330, 10, 761, 551));
        sizePolicy.setHeightForWidth(tab_widget->sizePolicy().hasHeightForWidth());
        tab_widget->setSizePolicy(sizePolicy);
        tab_widget->setStyleSheet(QString::fromUtf8("QTabWidget::pane { /* The tab widget frame */\n"
"    border-top: 2px solid #FFFFFF;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    left: 5px; /* move to the right by 5px */\n"
"}\n"
"\n"
"/* Style the tab using the tab sub-control. Note that\n"
"    it reads QTabBar _not_ QTabWidget */\n"
"QTabBar::tab {\n"
"    background: #000000;\n"
"    border: 2px solid #FFFFFF;\n"
"    border-bottom-color: #FFFFFF; /* same as the pane color */\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"    min-width: 8ex;\n"
"    padding: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:selected, QTabBar::tab:hover {\n"
"    background:  #000000;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background: #000000;\n"
"    border-color: #FFFFFF;\n"
"    border-bottom-color: #FFFFFF; /* same as pane color */\n"
"}\n"
"\n"
"QTabBar::tab:!selected {\n"
"    margin-top: 2px; /* make non-selected tabs look smaller */\n"
"}\n"
"\n"
"/* make use of negative margins for overlapping tabs */\n"
"QTabBar::tab:selected {\n"
"    /* "
                        "expand/overlap to the left and right by 4px */\n"
"    margin-left: -4px;\n"
"    margin-right: -4px;\n"
"}\n"
"\n"
"QTabBar::tab:first:selected {\n"
"    margin-left: 0; /* the first selected tab has nothing to overlap with on the left */\n"
"}\n"
"\n"
"QTabBar::tab:last:selected {\n"
"    margin-right: 0; /* the last selected tab has nothing to overlap with on the right */\n"
"}\n"
"\n"
"QTabBar::tab:only-one {\n"
"    margin: 0; /* if there is only one tab, we don't want overlapping margins */\n"
"}\n"
""));
        sensor_display_tab = new QWidget();
        sensor_display_tab->setObjectName(QString::fromUtf8("sensor_display_tab"));
        sensor_display_tab->setStyleSheet(QString::fromUtf8(""));
        imu_frame = new rqt_rover_gui::IMUFrame(sensor_display_tab);
        imu_frame->setObjectName(QString::fromUtf8("imu_frame"));
        imu_frame->setGeometry(QRect(350, 290, 281, 191));
        sizePolicy.setHeightForWidth(imu_frame->sizePolicy().hasHeightForWidth());
        imu_frame->setSizePolicy(sizePolicy);
        imu_frame->setFrameShape(QFrame::StyledPanel);
        imu_frame->setFrameShadow(QFrame::Raised);
        map_frame = new rqt_rover_gui::MapFrame(sensor_display_tab);
        map_frame->setObjectName(QString::fromUtf8("map_frame"));
        map_frame->setGeometry(QRect(350, 10, 320, 271));
        map_frame->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);"));
        map_frame->setFrameShape(QFrame::StyledPanel);
        map_frame->setFrameShadow(QFrame::Raised);
        map_frame->setLineWidth(1);
        us_frame = new rqt_rover_gui::USFrame(sensor_display_tab);
        us_frame->setObjectName(QString::fromUtf8("us_frame"));
        us_frame->setGeometry(QRect(50, 290, 281, 191));
        us_frame->setFrameShape(QFrame::StyledPanel);
        us_frame->setFrameShadow(QFrame::Raised);
        camera_frame = new rqt_rover_gui::CameraFrame(sensor_display_tab);
        camera_frame->setObjectName(QString::fromUtf8("camera_frame"));
        camera_frame->setGeometry(QRect(10, 10, 320, 271));
        camera_frame->setFrameShape(QFrame::StyledPanel);
        camera_frame->setFrameShadow(QFrame::Raised);
        gps_checkbox = new QCheckBox(sensor_display_tab);
        gps_checkbox->setObjectName(QString::fromUtf8("gps_checkbox"));
        gps_checkbox->setGeometry(QRect(670, 50, 81, 22));
        gps_checkbox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        gps_checkbox->setChecked(false);
        ekf_checkbox = new QCheckBox(sensor_display_tab);
        ekf_checkbox->setObjectName(QString::fromUtf8("ekf_checkbox"));
        ekf_checkbox->setGeometry(QRect(670, 10, 91, 22));
        ekf_checkbox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        ekf_checkbox->setChecked(true);
        encoder_checkbox = new QCheckBox(sensor_display_tab);
        encoder_checkbox->setObjectName(QString::fromUtf8("encoder_checkbox"));
        encoder_checkbox->setGeometry(QRect(670, 30, 81, 22));
        encoder_checkbox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        encoder_checkbox->setChecked(false);
        map_manual_radio_button = new QRadioButton(sensor_display_tab);
        map_display_button_group = new QButtonGroup(RoverGUI);
        map_display_button_group->setObjectName(QString::fromUtf8("map_display_button_group"));
        map_display_button_group->addButton(map_manual_radio_button);
        map_manual_radio_button->setObjectName(QString::fromUtf8("map_manual_radio_button"));
        map_manual_radio_button->setEnabled(true);
        map_manual_radio_button->setGeometry(QRect(670, 85, 117, 20));
        map_manual_radio_button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        map_manual_radio_button->setChecked(false);
        map_auto_radio_button = new QRadioButton(sensor_display_tab);
        map_display_button_group->addButton(map_auto_radio_button);
        map_auto_radio_button->setObjectName(QString::fromUtf8("map_auto_radio_button"));
        map_auto_radio_button->setEnabled(true);
        map_auto_radio_button->setGeometry(QRect(670, 110, 171, 16));
        map_auto_radio_button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        map_auto_radio_button->setChecked(true);
        map_popout_button = new QPushButton(sensor_display_tab);
        map_popout_button->setObjectName(QString::fromUtf8("map_popout_button"));
        map_popout_button->setEnabled(true);
        map_popout_button->setGeometry(QRect(680, 140, 61, 22));
        map_popout_button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-color: rgb(255, 255, 255);\n"
"border: 1px solid white; \n"
""));
        tab_widget->addTab(sensor_display_tab, QString());
        simulation_parameters_tab = new QWidget();
        simulation_parameters_tab->setObjectName(QString::fromUtf8("simulation_parameters_tab"));
        setup_group = new QFrame(simulation_parameters_tab);
        setup_group->setObjectName(QString::fromUtf8("setup_group"));
        setup_group->setGeometry(QRect(10, 60, 301, 306));
        setup_group->setFrameShape(QFrame::StyledPanel);
        setup_group->setFrameShadow(QFrame::Raised);
        target_distribution_group_box = new QGroupBox(setup_group);
        target_distribution_group_box->setObjectName(QString::fromUtf8("target_distribution_group_box"));
        target_distribution_group_box->setGeometry(QRect(10, 10, 141, 161));
        target_distribution_group_box->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-color: rgb(255, 255, 255);"));
        uniform_distribution_radio_button = new QRadioButton(target_distribution_group_box);
        uniform_distribution_radio_button->setObjectName(QString::fromUtf8("uniform_distribution_radio_button"));
        uniform_distribution_radio_button->setEnabled(true);
        uniform_distribution_radio_button->setGeometry(QRect(30, 30, 91, 22));
        uniform_distribution_radio_button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        uniform_distribution_radio_button->setChecked(false);
        powerlaw_distribution_radio_button = new QRadioButton(target_distribution_group_box);
        powerlaw_distribution_radio_button->setObjectName(QString::fromUtf8("powerlaw_distribution_radio_button"));
        powerlaw_distribution_radio_button->setEnabled(true);
        powerlaw_distribution_radio_button->setGeometry(QRect(30, 90, 101, 22));
        powerlaw_distribution_radio_button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        clustered_distribution_radio_button = new QRadioButton(target_distribution_group_box);
        clustered_distribution_radio_button->setObjectName(QString::fromUtf8("clustered_distribution_radio_button"));
        clustered_distribution_radio_button->setEnabled(true);
        clustered_distribution_radio_button->setGeometry(QRect(30, 60, 91, 22));
        clustered_distribution_radio_button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        clustered_distribution_radio_button->setChecked(false);
        custom_distribution_radio_button = new QRadioButton(target_distribution_group_box);
        custom_distribution_radio_button->setObjectName(QString::fromUtf8("custom_distribution_radio_button"));
        custom_distribution_radio_button->setEnabled(true);
        custom_distribution_radio_button->setGeometry(QRect(30, 120, 117, 22));
        custom_distribution_radio_button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        custom_distribution_radio_button->setChecked(true);
        custom_world_path_button = new QPushButton(setup_group);
        custom_world_path_button->setObjectName(QString::fromUtf8("custom_world_path_button"));
        custom_world_path_button->setEnabled(false);
        custom_world_path_button->setGeometry(QRect(140, 130, 70, 25));
        custom_world_path_button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-color: rgb(255, 255, 255);\n"
"border: 1px solid white; \n"
""));
        round_type_button_group = new QGroupBox(setup_group);
        round_type_button_group->setObjectName(QString::fromUtf8("round_type_button_group"));
        round_type_button_group->setGeometry(QRect(160, 30, 121, 91));
        round_type_button_group->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-color: rgb(255, 255, 255);"));
        joystick_radio_button = new QRadioButton(round_type_button_group);
        joystick_radio_button->setObjectName(QString::fromUtf8("joystick_radio_button"));
        joystick_radio_button->setEnabled(true);
        joystick_radio_button->setGeometry(QRect(10, 30, 161, 22));
        joystick_radio_button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        joystick_radio_button->setChecked(true);
        final_radio_button = new QRadioButton(round_type_button_group);
        final_radio_button->setObjectName(QString::fromUtf8("final_radio_button"));
        final_radio_button->setEnabled(true);
        final_radio_button->setGeometry(QRect(10, 60, 117, 22));
        final_radio_button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_5 = new QLabel(setup_group);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 190, 111, 20));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_5->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        texture_combobox = new QComboBox(setup_group);
        texture_combobox->setObjectName(QString::fromUtf8("texture_combobox"));
        texture_combobox->setGeometry(QRect(150, 190, 131, 27));
        texture_combobox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-color: rgb(255, 255, 255);\n"
"border: 1px solid white; \n"
"padding: 1px 0px 1px 3px; /*This makes text colour work*/\n"
""));
        custom_world_path = new QLabel(setup_group);
        custom_world_path->setObjectName(QString::fromUtf8("custom_world_path"));
        custom_world_path->setGeometry(QRect(68, 162, 200, 20));
        custom_world_path->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        override_num_rovers_checkbox = new QCheckBox(setup_group);
        override_num_rovers_checkbox->setObjectName(QString::fromUtf8("override_num_rovers_checkbox"));
        override_num_rovers_checkbox->setEnabled(true);
        override_num_rovers_checkbox->setGeometry(QRect(20, 230, 181, 22));
        override_num_rovers_checkbox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        override_num_rovers_checkbox->setChecked(false);
        custom_num_rovers_combobox = new QComboBox(setup_group);
        custom_num_rovers_combobox->setObjectName(QString::fromUtf8("custom_num_rovers_combobox"));
        custom_num_rovers_combobox->setEnabled(false);
        custom_num_rovers_combobox->setGeometry(QRect(210, 230, 71, 27));
        custom_num_rovers_combobox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-color: rgb(255, 255, 255);\n"
"border: 1px solid white; \n"
"padding: 1px 0px 1px 3px; /*This makes text colour work*/\n"
""));
        simulation_timer_combo_box = new QComboBox(setup_group);
        simulation_timer_combo_box->setObjectName(QString::fromUtf8("simulation_timer_combo_box"));
        simulation_timer_combo_box->setEnabled(true);
        simulation_timer_combo_box->setGeometry(QRect(150, 270, 131, 23));
        simulation_timer_combo_box->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-color: rgb(255, 255, 255);\n"
"border: 1px solid white; \n"
"padding: 1px 0px 1px 3px; /*This makes text colour work*/\n"
""));
        simulation_timer_combo_box->setEditable(false);
        simulation_timer_combo_box->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        simulation_timer_combo_box->setMinimumContentsLength(0);
        simulation_timer_combo_box->setIconSize(QSize(4, 4));
        simulation_timer_label = new QLabel(setup_group);
        simulation_timer_label->setObjectName(QString::fromUtf8("simulation_timer_label"));
        simulation_timer_label->setGeometry(QRect(20, 270, 130, 20));
        simulation_timer_label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        simulation_timer_label->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        label_7 = new QLabel(simulation_parameters_tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(80, 50, 121, 20));
        rover_image_label = new QLabel(simulation_parameters_tab);
        rover_image_label->setObjectName(QString::fromUtf8("rover_image_label"));
        rover_image_label->setGeometry(QRect(290, 20, 501, 427));
        rover_image_label->setPixmap(QPixmap(QString::fromUtf8("../resources/rover.png")));
        build_simulation_button = new QPushButton(simulation_parameters_tab);
        build_simulation_button->setObjectName(QString::fromUtf8("build_simulation_button"));
        build_simulation_button->setGeometry(QRect(80, 370, 161, 27));
        build_simulation_button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-color: rgb(255, 255, 255);\n"
"border: 1px solid white; \n"
""));
        frame_2 = new QFrame(simulation_parameters_tab);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(510, 330, 191, 161));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_39 = new QLabel(frame_2);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(10, 10, 71, 17));
        label_39->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_40 = new QLabel(frame_2);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(10, 70, 71, 17));
        label_40->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_41 = new QLabel(frame_2);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(10, 90, 71, 17));
        label_41->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_42 = new QLabel(frame_2);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(10, 50, 71, 17));
        label_42->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_43 = new QLabel(frame_2);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(10, 30, 71, 17));
        label_43->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_44 = new QLabel(frame_2);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(10, 110, 131, 17));
        label_44->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        sonar_range_res = new QLabel(frame_2);
        sonar_range_res->setObjectName(QString::fromUtf8("sonar_range_res"));
        sonar_range_res->setGeometry(QRect(140, 110, 41, 17));
        sonar_range_res->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        sonar_max_angle = new QLabel(frame_2);
        sonar_max_angle->setObjectName(QString::fromUtf8("sonar_max_angle"));
        sonar_max_angle->setGeometry(QRect(140, 90, 41, 17));
        sonar_max_angle->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        sonar_min_angle = new QLabel(frame_2);
        sonar_min_angle->setObjectName(QString::fromUtf8("sonar_min_angle"));
        sonar_min_angle->setGeometry(QRect(140, 70, 41, 17));
        sonar_min_angle->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        sonar_max = new QLabel(frame_2);
        sonar_max->setObjectName(QString::fromUtf8("sonar_max"));
        sonar_max->setGeometry(QRect(140, 50, 41, 17));
        sonar_max->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        sonar_min = new QLabel(frame_2);
        sonar_min->setObjectName(QString::fromUtf8("sonar_min"));
        sonar_min->setGeometry(QRect(140, 30, 41, 17));
        sonar_min->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        sonar_horz_res = new QLabel(frame_2);
        sonar_horz_res->setObjectName(QString::fromUtf8("sonar_horz_res"));
        sonar_horz_res->setGeometry(QRect(140, 10, 41, 17));
        sonar_horz_res->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_65 = new QLabel(frame_2);
        label_65->setObjectName(QString::fromUtf8("label_65"));
        label_65->setGeometry(QRect(10, 130, 121, 17));
        label_65->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        sonar_gaussian_noise = new QLabel(frame_2);
        sonar_gaussian_noise->setObjectName(QString::fromUtf8("sonar_gaussian_noise"));
        sonar_gaussian_noise->setGeometry(QRect(140, 130, 41, 17));
        sonar_gaussian_noise->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        clear_simulation_button = new QPushButton(simulation_parameters_tab);
        clear_simulation_button->setObjectName(QString::fromUtf8("clear_simulation_button"));
        clear_simulation_button->setEnabled(true);
        clear_simulation_button->setGeometry(QRect(80, 400, 161, 27));
        clear_simulation_button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-color: rgb(255, 255, 255);\n"
"border: 1px solid white; \n"
""));
        label_11 = new QLabel(simulation_parameters_tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(360, 310, 31, 17));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        frame_4 = new QFrame(simulation_parameters_tab);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(350, 320, 151, 181));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        label_23 = new QLabel(frame_4);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(10, 30, 61, 17));
        label_23->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_22 = new QLabel(frame_4);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 10, 61, 17));
        label_22->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_24 = new QLabel(frame_4);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(10, 50, 71, 17));
        label_24->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_26 = new QLabel(frame_4);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(10, 70, 71, 17));
        label_26->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        gps_update_rate = new QLabel(frame_4);
        gps_update_rate->setObjectName(QString::fromUtf8("gps_update_rate"));
        gps_update_rate->setGeometry(QRect(90, 10, 51, 17));
        gps_update_rate->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        gps_ref_lat = new QLabel(frame_4);
        gps_ref_lat->setObjectName(QString::fromUtf8("gps_ref_lat"));
        gps_ref_lat->setGeometry(QRect(90, 30, 51, 17));
        gps_ref_lat->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        gps_ref_long = new QLabel(frame_4);
        gps_ref_long->setObjectName(QString::fromUtf8("gps_ref_long"));
        gps_ref_long->setGeometry(QRect(90, 50, 51, 17));
        gps_ref_long->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        gps_ref_heading = new QLabel(frame_4);
        gps_ref_heading->setObjectName(QString::fromUtf8("gps_ref_heading"));
        gps_ref_heading->setGeometry(QRect(90, 70, 51, 17));
        gps_ref_heading->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_49 = new QLabel(frame_4);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setGeometry(QRect(10, 110, 71, 17));
        label_49->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_50 = new QLabel(frame_4);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setGeometry(QRect(10, 130, 71, 17));
        label_50->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_51 = new QLabel(frame_4);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setGeometry(QRect(10, 150, 71, 17));
        label_51->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        gps_drift = new QLabel(frame_4);
        gps_drift->setObjectName(QString::fromUtf8("gps_drift"));
        gps_drift->setGeometry(QRect(90, 110, 51, 17));
        gps_drift->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        gps_drift_freq = new QLabel(frame_4);
        gps_drift_freq->setObjectName(QString::fromUtf8("gps_drift_freq"));
        gps_drift_freq->setGeometry(QRect(90, 130, 51, 17));
        gps_drift_freq->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        gps_noise = new QLabel(frame_4);
        gps_noise->setObjectName(QString::fromUtf8("gps_noise"));
        gps_noise->setGeometry(QRect(90, 150, 51, 17));
        gps_noise->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_52 = new QLabel(frame_4);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setGeometry(QRect(10, 90, 71, 17));
        label_52->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        gps_ref_alt = new QLabel(frame_4);
        gps_ref_alt->setObjectName(QString::fromUtf8("gps_ref_alt"));
        gps_ref_alt->setGeometry(QRect(90, 90, 51, 17));
        gps_ref_alt->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_12 = new QLabel(simulation_parameters_tab);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(360, 130, 31, 17));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        frame_5 = new QFrame(simulation_parameters_tab);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(350, 140, 271, 171));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        label_27 = new QLabel(frame_5);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(130, 10, 61, 17));
        label_27->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_28 = new QLabel(frame_5);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(10, 30, 91, 17));
        label_28->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_29 = new QLabel(frame_5);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(10, 50, 61, 17));
        label_29->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_30 = new QLabel(frame_5);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(10, 100, 81, 17));
        label_30->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_31 = new QLabel(frame_5);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(130, 30, 91, 17));
        label_31->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_32 = new QLabel(frame_5);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(130, 50, 91, 17));
        label_32->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_33 = new QLabel(frame_5);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(10, 10, 61, 17));
        label_33->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_34 = new QLabel(frame_5);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(130, 100, 91, 17));
        label_34->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_35 = new QLabel(frame_5);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(130, 120, 91, 17));
        label_35->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_36 = new QLabel(frame_5);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(130, 80, 91, 17));
        label_36->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_37 = new QLabel(frame_5);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(10, 80, 81, 17));
        label_37->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_38 = new QLabel(frame_5);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(10, 130, 81, 17));
        label_38->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        imu_update_rate = new QLabel(frame_5);
        imu_update_rate->setObjectName(QString::fromUtf8("imu_update_rate"));
        imu_update_rate->setGeometry(QRect(180, 10, 41, 17));
        imu_update_rate->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        imu_rate_drift = new QLabel(frame_5);
        imu_rate_drift->setObjectName(QString::fromUtf8("imu_rate_drift"));
        imu_rate_drift->setGeometry(QRect(220, 30, 41, 17));
        imu_rate_drift->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        imu_rate_noise = new QLabel(frame_5);
        imu_rate_noise->setObjectName(QString::fromUtf8("imu_rate_noise"));
        imu_rate_noise->setGeometry(QRect(220, 50, 41, 17));
        imu_rate_noise->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        imu_heading_drift = new QLabel(frame_5);
        imu_heading_drift->setObjectName(QString::fromUtf8("imu_heading_drift"));
        imu_heading_drift->setGeometry(QRect(220, 100, 41, 17));
        imu_heading_drift->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        imu_heading_noise = new QLabel(frame_5);
        imu_heading_noise->setObjectName(QString::fromUtf8("imu_heading_noise"));
        imu_heading_noise->setGeometry(QRect(180, 120, 41, 17));
        imu_heading_noise->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        imu_accel_drift = new QLabel(frame_5);
        imu_accel_drift->setObjectName(QString::fromUtf8("imu_accel_drift"));
        imu_accel_drift->setGeometry(QRect(60, 30, 41, 16));
        imu_accel_drift->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        imu_accel_noise = new QLabel(frame_5);
        imu_accel_noise->setObjectName(QString::fromUtf8("imu_accel_noise"));
        imu_accel_noise->setGeometry(QRect(60, 50, 41, 16));
        imu_accel_noise->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        imu_rpy_offsets = new QLabel(frame_5);
        imu_rpy_offsets->setObjectName(QString::fromUtf8("imu_rpy_offsets"));
        imu_rpy_offsets->setGeometry(QRect(70, 100, 41, 17));
        imu_rpy_offsets->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        imu_noise = new QLabel(frame_5);
        imu_noise->setObjectName(QString::fromUtf8("imu_noise"));
        imu_noise->setGeometry(QRect(70, 130, 51, 17));
        imu_noise->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_63 = new QLabel(frame_5);
        label_63->setObjectName(QString::fromUtf8("label_63"));
        label_63->setGeometry(QRect(20, 150, 151, 17));
        label_63->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_64 = new QLabel(frame_5);
        label_64->setObjectName(QString::fromUtf8("label_64"));
        label_64->setGeometry(QRect(180, 150, 51, 17));
        label_64->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_17 = new QLabel(simulation_parameters_tab);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(520, 0, 51, 17));
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        frame_6 = new QFrame(simulation_parameters_tab);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(510, 10, 151, 131));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        label_18 = new QLabel(frame_6);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 10, 61, 17));
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_19 = new QLabel(frame_6);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 30, 61, 17));
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_20 = new QLabel(frame_6);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 50, 61, 17));
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_21 = new QLabel(frame_6);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(10, 70, 61, 17));
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        camera_update_rate = new QLabel(frame_6);
        camera_update_rate->setObjectName(QString::fromUtf8("camera_update_rate"));
        camera_update_rate->setGeometry(QRect(80, 10, 51, 17));
        camera_update_rate->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        camera_width = new QLabel(frame_6);
        camera_width->setObjectName(QString::fromUtf8("camera_width"));
        camera_width->setGeometry(QRect(80, 30, 51, 17));
        camera_width->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        camera_height = new QLabel(frame_6);
        camera_height->setObjectName(QString::fromUtf8("camera_height"));
        camera_height->setGeometry(QRect(80, 50, 51, 17));
        camera_height->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        camera_format = new QLabel(frame_6);
        camera_format->setObjectName(QString::fromUtf8("camera_format"));
        camera_format->setGeometry(QRect(80, 70, 51, 17));
        camera_format->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_25 = new QLabel(frame_6);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(10, 90, 81, 17));
        label_25->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        camera_noise_mean = new QLabel(frame_6);
        camera_noise_mean->setObjectName(QString::fromUtf8("camera_noise_mean"));
        camera_noise_mean->setGeometry(QRect(100, 90, 41, 17));
        camera_noise_mean->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_45 = new QLabel(frame_6);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(50, 110, 41, 17));
        label_45->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        camera_noise_stdev = new QLabel(frame_6);
        camera_noise_stdev->setObjectName(QString::fromUtf8("camera_noise_stdev"));
        camera_noise_stdev->setGeometry(QRect(100, 110, 41, 17));
        camera_noise_stdev->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_19->raise();
        label_20->raise();
        label_21->raise();
        label_18->raise();
        camera_update_rate->raise();
        camera_width->raise();
        camera_height->raise();
        camera_format->raise();
        label_25->raise();
        camera_noise_mean->raise();
        label_45->raise();
        camera_noise_stdev->raise();
        visualize_simulation_button = new QPushButton(simulation_parameters_tab);
        visualize_simulation_button->setObjectName(QString::fromUtf8("visualize_simulation_button"));
        visualize_simulation_button->setEnabled(true);
        visualize_simulation_button->setGeometry(QRect(80, 430, 161, 27));
        visualize_simulation_button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-color: rgb(255, 255, 255);\n"
"border: 1px solid white; \n"
""));
        label_10 = new QLabel(simulation_parameters_tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(520, 320, 81, 17));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        tab_widget->addTab(simulation_parameters_tab, QString());
        rover_image_label->raise();
        setup_group->raise();
        label_7->raise();
        build_simulation_button->raise();
        frame_2->raise();
        clear_simulation_button->raise();
        frame_4->raise();
        label_11->raise();
        frame_5->raise();
        label_12->raise();
        frame_6->raise();
        label_17->raise();
        visualize_simulation_button->raise();
        label_10->raise();
        stats_tab = new QWidget();
        stats_tab->setObjectName(QString::fromUtf8("stats_tab"));
        label_6 = new QLabel(stats_tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(100, 60, 201, 17));
        num_targets_detected_label = new QLabel(stats_tab);
        num_targets_detected_label->setObjectName(QString::fromUtf8("num_targets_detected_label"));
        num_targets_detected_label->setGeometry(QRect(310, 60, 67, 17));
        label_8 = new QLabel(stats_tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(100, 90, 201, 17));
        num_targets_collected_label = new QLabel(stats_tab);
        num_targets_collected_label->setObjectName(QString::fromUtf8("num_targets_collected_label"));
        num_targets_collected_label->setGeometry(QRect(310, 90, 67, 17));
        label_9 = new QLabel(stats_tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(100, 150, 181, 17));
        perc_of_time_avoiding_obstacles = new QLabel(stats_tab);
        perc_of_time_avoiding_obstacles->setObjectName(QString::fromUtf8("perc_of_time_avoiding_obstacles"));
        perc_of_time_avoiding_obstacles->setGeometry(QRect(310, 150, 67, 17));
        currentSimulationTimeLabel = new QLabel(stats_tab);
        currentSimulationTimeLabel->setObjectName(QString::fromUtf8("currentSimulationTimeLabel"));
        currentSimulationTimeLabel->setGeometry(QRect(210, 250, 250, 17));
        simulationTimerStartLabel = new QLabel(stats_tab);
        simulationTimerStartLabel->setObjectName(QString::fromUtf8("simulationTimerStartLabel"));
        simulationTimerStartLabel->setGeometry(QRect(210, 280, 250, 17));
        simulationTimerStopLabel = new QLabel(stats_tab);
        simulationTimerStopLabel->setObjectName(QString::fromUtf8("simulationTimerStopLabel"));
        simulationTimerStopLabel->setGeometry(QRect(210, 310, 250, 17));
        currentSimulationTimeTitle = new QLabel(stats_tab);
        currentSimulationTimeTitle->setObjectName(QString::fromUtf8("currentSimulationTimeTitle"));
        currentSimulationTimeTitle->setGeometry(QRect(100, 250, 100, 17));
        currentSimulationTimeTitle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        simulationTimerStartTitle = new QLabel(stats_tab);
        simulationTimerStartTitle->setObjectName(QString::fromUtf8("simulationTimerStartTitle"));
        simulationTimerStartTitle->setGeometry(QRect(100, 280, 100, 17));
        simulationTimerStartTitle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        simulationTimerStopTitle = new QLabel(stats_tab);
        simulationTimerStopTitle->setObjectName(QString::fromUtf8("simulationTimerStopTitle"));
        simulationTimerStopTitle->setGeometry(QRect(100, 310, 100, 17));
        simulationTimerStopTitle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Simulation_Timer_Frame = new QFrame(stats_tab);
        Simulation_Timer_Frame->setObjectName(QString::fromUtf8("Simulation_Timer_Frame"));
        Simulation_Timer_Frame->setEnabled(true);
        Simulation_Timer_Frame->setGeometry(QRect(90, 220, 400, 120));
        Simulation_Timer_Frame->setFrameShape(QFrame::StyledPanel);
        Simulation_Timer_Frame->setFrameShadow(QFrame::Raised);
        simulation_timer_frame_label = new QLabel(stats_tab);
        simulation_timer_frame_label->setObjectName(QString::fromUtf8("simulation_timer_frame_label"));
        simulation_timer_frame_label->setGeometry(QRect(100, 210, 310, 25));
        simulation_timer_frame_label->setStyleSheet(QString::fromUtf8("color: white;\n"
"border: 1px solid white;\n"
"padding: 1px;"));
        simulation_timer_frame_label->setAlignment(Qt::AlignCenter);
        tab_widget->addTab(stats_tab, QString());
        Simulation_Timer_Frame->raise();
        label_6->raise();
        num_targets_detected_label->raise();
        label_8->raise();
        num_targets_collected_label->raise();
        label_9->raise();
        perc_of_time_avoiding_obstacles->raise();
        currentSimulationTimeLabel->raise();
        simulationTimerStartLabel->raise();
        simulationTimerStopLabel->raise();
        currentSimulationTimeTitle->raise();
        simulationTimerStartTitle->raise();
        simulationTimerStopTitle->raise();
        simulation_timer_frame_label->raise();
        control_frame = new QFrame(RoverGUI);
        control_frame->setObjectName(QString::fromUtf8("control_frame"));
        control_frame->setEnabled(true);
        control_frame->setGeometry(QRect(600, 560, 201, 141));
        control_frame->setFrameShape(QFrame::StyledPanel);
        control_frame->setFrameShadow(QFrame::Raised);
        control_group_box = new QGroupBox(control_frame);
        control_group_box->setObjectName(QString::fromUtf8("control_group_box"));
        control_group_box->setGeometry(QRect(10, 10, 181, 121));
        control_group_box->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        autonomous_control_radio_button = new QRadioButton(control_group_box);
        rover_control_button_group = new QButtonGroup(RoverGUI);
        rover_control_button_group->setObjectName(QString::fromUtf8("rover_control_button_group"));
        rover_control_button_group->addButton(autonomous_control_radio_button);
        autonomous_control_radio_button->setObjectName(QString::fromUtf8("autonomous_control_radio_button"));
        autonomous_control_radio_button->setEnabled(false);
        autonomous_control_radio_button->setGeometry(QRect(10, 40, 171, 30));
        autonomous_control_radio_button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        joystick_control_radio_button = new QRadioButton(control_group_box);
        rover_control_button_group->addButton(joystick_control_radio_button);
        joystick_control_radio_button->setObjectName(QString::fromUtf8("joystick_control_radio_button"));
        joystick_control_radio_button->setEnabled(false);
        joystick_control_radio_button->setGeometry(QRect(10, 25, 117, 20));
        joystick_control_radio_button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        joystick_control_radio_button->setChecked(true);
        all_stop_button = new QPushButton(control_group_box);
        all_stop_button->setObjectName(QString::fromUtf8("all_stop_button"));
        all_stop_button->setEnabled(true);
        all_stop_button->setGeometry(QRect(10, 95, 150, 22));
        all_stop_button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-color: rgb(255, 255, 255);\n"
"border: 1px solid white; \n"
""));
        all_autonomous_button = new QPushButton(control_group_box);
        all_autonomous_button->setObjectName(QString::fromUtf8("all_autonomous_button"));
        all_autonomous_button->setEnabled(true);
        all_autonomous_button->setGeometry(QRect(10, 70, 150, 22));
        all_autonomous_button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-color: rgb(255, 255, 255);\n"
"border: 1px solid white; \n"
""));
        joystick_frame = new QFrame(RoverGUI);
        joystick_frame->setObjectName(QString::fromUtf8("joystick_frame"));
        joystick_frame->setGeometry(QRect(810, 590, 191, 111));
        joystick_frame->setFrameShape(QFrame::StyledPanel);
        joystick_frame->setFrameShadow(QFrame::Raised);
        joy_lcd_drive_forward = new QLCDNumber(joystick_frame);
        joy_lcd_drive_forward->setObjectName(QString::fromUtf8("joy_lcd_drive_forward"));
        joy_lcd_drive_forward->setGeometry(QRect(110, 40, 41, 16));
        QFont font;
        font.setPointSize(18);
        joy_lcd_drive_forward->setFont(font);
        joy_lcd_drive_left = new QLCDNumber(joystick_frame);
        joy_lcd_drive_left->setObjectName(QString::fromUtf8("joy_lcd_drive_left"));
        joy_lcd_drive_left->setGeometry(QRect(90, 60, 41, 16));
        joy_lcd_drive_left->setFont(font);
        joy_lcd_drive_right = new QLCDNumber(joystick_frame);
        joy_lcd_drive_right->setObjectName(QString::fromUtf8("joy_lcd_drive_right"));
        joy_lcd_drive_right->setGeometry(QRect(130, 60, 41, 16));
        joy_lcd_drive_right->setFont(font);
        joy_lcd_drive_back = new QLCDNumber(joystick_frame);
        joy_lcd_drive_back->setObjectName(QString::fromUtf8("joy_lcd_drive_back"));
        joy_lcd_drive_back->setGeometry(QRect(110, 80, 41, 16));
        joy_lcd_drive_back->setFont(font);
        joy_lcd_gripper_up = new QLCDNumber(joystick_frame);
        joy_lcd_gripper_up->setObjectName(QString::fromUtf8("joy_lcd_gripper_up"));
        joy_lcd_gripper_up->setGeometry(QRect(30, 40, 41, 16));
        joy_lcd_gripper_up->setFont(font);
        joy_lcd_gripper_open = new QLCDNumber(joystick_frame);
        joy_lcd_gripper_open->setObjectName(QString::fromUtf8("joy_lcd_gripper_open"));
        joy_lcd_gripper_open->setGeometry(QRect(50, 60, 41, 16));
        joy_lcd_gripper_open->setFont(font);
        joy_lcd_gripper_close = new QLCDNumber(joystick_frame);
        joy_lcd_gripper_close->setObjectName(QString::fromUtf8("joy_lcd_gripper_close"));
        joy_lcd_gripper_close->setGeometry(QRect(10, 60, 41, 16));
        joy_lcd_gripper_close->setFont(font);
        joy_lcd_gripper_down = new QLCDNumber(joystick_frame);
        joy_lcd_gripper_down->setObjectName(QString::fromUtf8("joy_lcd_gripper_down"));
        joy_lcd_gripper_down->setGeometry(QRect(30, 80, 41, 16));
        joy_lcd_gripper_down->setFont(font);
        drive_label = new QLabel(joystick_frame);
        drive_label->setObjectName(QString::fromUtf8("drive_label"));
        drive_label->setGeometry(QRect(120, 10, 67, 17));
        drive_label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        gripper_label = new QLabel(joystick_frame);
        gripper_label->setObjectName(QString::fromUtf8("gripper_label"));
        gripper_label->setGeometry(QRect(40, 10, 67, 17));
        gripper_label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label = new QLabel(RoverGUI);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 111, 16));
        label_2 = new QLabel(RoverGUI);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 51, 17));
        label_3 = new QLabel(RoverGUI);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 30, 121, 16));
        label_4 = new QLabel(RoverGUI);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 50, 67, 17));
        version_number_label = new QLabel(RoverGUI);
        version_number_label->setObjectName(QString::fromUtf8("version_number_label"));
        version_number_label->setGeometry(QRect(80, 50, 91, 17));
        rover_name = new QLabel(RoverGUI);
        rover_name->setObjectName(QString::fromUtf8("rover_name"));
        rover_name->setGeometry(QRect(10, 330, 191, 20));
        log_tab = new BWTabWidget(RoverGUI);
        log_tab->setObjectName(QString::fromUtf8("log_tab"));
        log_tab->setGeometry(QRect(10, 510, 571, 211));
        log_tab->setStyleSheet(QString::fromUtf8("QTabWidget::pane { /* The tab widget frame */\n"
"    border-top: 2px solid #FFFFFF;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    left: 5px; /* move to the right by 5px */\n"
"}\n"
"\n"
"/* Style the tab using the tab sub-control. Note that\n"
"    it reads QTabBar _not_ QTabWidget */\n"
"QTabBar::tab {\n"
"    background: #000000;\n"
"    border: 2px solid #FFFFFF;\n"
"    border-bottom-color: #FFFFFF; /* same as the pane color */\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"    min-width: 8ex;\n"
"    padding: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:selected, QTabBar::tab:hover {\n"
"    background:  #000000;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background: #000000;\n"
"    border-color: #FFFFFF;\n"
"    border-bottom-color: #FFFFFF; /* same as pane color */\n"
"}\n"
"\n"
"QTabBar::tab:!selected {\n"
"    margin-top: 2px; /* make non-selected tabs look smaller */\n"
"}\n"
"\n"
"/* make use of negative margins for overlapping tabs */\n"
"QTabBar::tab:selected {\n"
"    /* "
                        "expand/overlap to the left and right by 4px */\n"
"    margin-left: -4px;\n"
"    margin-right: -4px;\n"
"}\n"
"\n"
"QTabBar::tab:first:selected {\n"
"    margin-left: 0; /* the first selected tab has nothing to overlap with on the left */\n"
"}\n"
"\n"
"QTabBar::tab:last:selected {\n"
"    margin-right: 0; /* the last selected tab has nothing to overlap with on the right */\n"
"}\n"
"\n"
"QTabBar::tab:only-one {\n"
"    margin: 0; /* if there is only one tab, we don't want overlapping margins */\n"
"}\n"
""));
        info_log_tab = new QWidget();
        info_log_tab->setObjectName(QString::fromUtf8("info_log_tab"));
        info_log = new QTextBrowser(info_log_tab);
        info_log->setObjectName(QString::fromUtf8("info_log"));
        info_log->setGeometry(QRect(0, 0, 561, 171));
        log_tab->addTab(info_log_tab, QString());
        diag_log_tab = new QWidget();
        diag_log_tab->setObjectName(QString::fromUtf8("diag_log_tab"));
        diag_log = new QTextBrowser(diag_log_tab);
        diag_log->setObjectName(QString::fromUtf8("diag_log"));
        diag_log->setGeometry(QRect(0, 0, 571, 171));
        log_tab->addTab(diag_log_tab, QString());
        Rover_frame = new QFrame(RoverGUI);
        Rover_frame->setObjectName(QString::fromUtf8("Rover_frame"));
        Rover_frame->setGeometry(QRect(10, 90, 311, 201));
        Rover_frame->setFrameShape(QFrame::StyledPanel);
        Rover_frame->setFrameShadow(QFrame::Raised);
        rover_diags_list = new QListWidget(Rover_frame);
        rover_diags_list->setObjectName(QString::fromUtf8("rover_diags_list"));
        rover_diags_list->setGeometry(QRect(150, 0, 121, 201));
        rover_diags_list->setFrameShape(QFrame::StyledPanel);
        rover_diags_list->setLineWidth(0);
        rover_list = new QListWidget(Rover_frame);
        rover_list->setObjectName(QString::fromUtf8("rover_list"));
        rover_list->setGeometry(QRect(0, 0, 151, 201));
        rover_list->setStyleSheet(QString::fromUtf8(""));
        rover_list->setFrameShadow(QFrame::Plain);
        rover_list->setLineWidth(1);
        map_selection_list = new QListWidget(Rover_frame);
        map_selection_list->setObjectName(QString::fromUtf8("map_selection_list"));
        map_selection_list->setGeometry(QRect(270, 0, 41, 201));
        map_selection_list->setFrameShape(QFrame::StyledPanel);
        map_selection_list->setLineWidth(0);
        label_13 = new QLabel(RoverGUI);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(160, 70, 111, 20));
        label_13->setStyleSheet(QString::fromUtf8("font: 63 8pt \"Ubuntu\";"));
        map_list_label = new QLabel(RoverGUI);
        map_list_label->setObjectName(QString::fromUtf8("map_list_label"));
        map_list_label->setGeometry(QRect(290, 70, 31, 20));
        map_list_label->setStyleSheet(QString::fromUtf8("font: 63 8pt \"Ubuntu\";"));
        gps_numSV_label = new QLabel(RoverGUI);
        gps_numSV_label->setObjectName(QString::fromUtf8("gps_numSV_label"));
        gps_numSV_label->setGeometry(QRect(10, 360, 191, 20));
        gps_numSV_label->setMouseTracking(true);

        retranslateUi(RoverGUI);

        tab_widget->setCurrentIndex(1);
        simulation_timer_combo_box->setCurrentIndex(0);
        log_tab->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(RoverGUI);
    } // setupUi

    void retranslateUi(QWidget *RoverGUI)
    {
        RoverGUI->setWindowTitle(QApplication::translate("RoverGUI", "    Rover Interface", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        gps_checkbox->setToolTip(QApplication::translate("RoverGUI", "<html><head/><body><p>GPS aligned with the map output (mutually recursive with MAP)</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        gps_checkbox->setText(QApplication::translate("RoverGUI", "NAVSAT", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ekf_checkbox->setToolTip(QApplication::translate("RoverGUI", "<html><head/><body><p>EKF combination of IMU, Encoders and GPS (mutually recursive with NAVSAT)</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        ekf_checkbox->setText(QApplication::translate("RoverGUI", "MAP", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        encoder_checkbox->setToolTip(QApplication::translate("RoverGUI", "<html><head/><body><p>EKF combination of IMU and Encoders</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        encoder_checkbox->setText(QApplication::translate("RoverGUI", "ODOM", 0, QApplication::UnicodeUTF8));
        map_manual_radio_button->setText(QApplication::translate("RoverGUI", "Manual", 0, QApplication::UnicodeUTF8));
        map_auto_radio_button->setText(QApplication::translate("RoverGUI", "Auto", 0, QApplication::UnicodeUTF8));
        map_popout_button->setText(QApplication::translate("RoverGUI", "Popout", 0, QApplication::UnicodeUTF8));
        tab_widget->setTabText(tab_widget->indexOf(sensor_display_tab), QApplication::translate("RoverGUI", "Sensor Display", 0, QApplication::UnicodeUTF8));
        target_distribution_group_box->setTitle(QApplication::translate("RoverGUI", "Target Distribution", 0, QApplication::UnicodeUTF8));
        uniform_distribution_radio_button->setText(QApplication::translate("RoverGUI", "Uniform", 0, QApplication::UnicodeUTF8));
        powerlaw_distribution_radio_button->setText(QApplication::translate("RoverGUI", "Power Law", 0, QApplication::UnicodeUTF8));
        clustered_distribution_radio_button->setText(QApplication::translate("RoverGUI", "Clustered", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        custom_distribution_radio_button->setToolTip(QApplication::translate("RoverGUI", "Select a custom target distribution", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        custom_distribution_radio_button->setText(QApplication::translate("RoverGUI", "Custom", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        custom_world_path_button->setToolTip(QApplication::translate("RoverGUI", "<html><head/><body><p>Select custom target distribution</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        custom_world_path_button->setText(QApplication::translate("RoverGUI", "Select", 0, QApplication::UnicodeUTF8));
        round_type_button_group->setTitle(QApplication::translate("RoverGUI", "Round Type", 0, QApplication::UnicodeUTF8));
        joystick_radio_button->setText(QApplication::translate("RoverGUI", "Preliminary", 0, QApplication::UnicodeUTF8));
        final_radio_button->setText(QApplication::translate("RoverGUI", "Final ", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("RoverGUI", "<html><head/><body><p>Ground Texture</p></body></html>", 0, QApplication::UnicodeUTF8));
        texture_combobox->clear();
        texture_combobox->insertItems(0, QStringList()
         << QApplication::translate("RoverGUI", "KSC Concrete", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RoverGUI", "Gravel", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RoverGUI", "Car park", 0, QApplication::UnicodeUTF8)
        );
        custom_world_path->setText(QString());
        override_num_rovers_checkbox->setText(QApplication::translate("RoverGUI", "Set Number of Rovers", 0, QApplication::UnicodeUTF8));
        custom_num_rovers_combobox->clear();
        custom_num_rovers_combobox->insertItems(0, QStringList()
         << QApplication::translate("RoverGUI", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RoverGUI", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RoverGUI", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RoverGUI", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RoverGUI", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RoverGUI", "6", 0, QApplication::UnicodeUTF8)
        );
        simulation_timer_combo_box->clear();
        simulation_timer_combo_box->insertItems(0, QStringList()
         << QApplication::translate("RoverGUI", "no time limit", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RoverGUI", "10 min (Testing)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RoverGUI", "30 min (Preliminary)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RoverGUI", "60 min (Final)", 0, QApplication::UnicodeUTF8)
        );
        simulation_timer_label->setText(QApplication::translate("RoverGUI", "<html><head/><body><p>Simulation Length</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("RoverGUI", "<html><head/><body><p><span style=\" color:#ffffff;\">Simulation Setup</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        rover_image_label->setText(QString());
        build_simulation_button->setText(QApplication::translate("RoverGUI", "Build Simulation", 0, QApplication::UnicodeUTF8));
        label_39->setText(QApplication::translate("RoverGUI", "Horz. Res", 0, QApplication::UnicodeUTF8));
        label_40->setText(QApplication::translate("RoverGUI", "Min Ang.", 0, QApplication::UnicodeUTF8));
        label_41->setText(QApplication::translate("RoverGUI", "Max Ang.", 0, QApplication::UnicodeUTF8));
        label_42->setText(QApplication::translate("RoverGUI", "Max", 0, QApplication::UnicodeUTF8));
        label_43->setText(QApplication::translate("RoverGUI", "Min", 0, QApplication::UnicodeUTF8));
        label_44->setText(QApplication::translate("RoverGUI", "Range Resolution", 0, QApplication::UnicodeUTF8));
        sonar_range_res->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        sonar_max_angle->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        sonar_min_angle->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        sonar_max->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        sonar_min->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        sonar_horz_res->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        label_65->setText(QApplication::translate("RoverGUI", "Gaussian Noise", 0, QApplication::UnicodeUTF8));
        sonar_gaussian_noise->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        clear_simulation_button->setText(QApplication::translate("RoverGUI", "End Simulation", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("RoverGUI", "GPS", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("RoverGUI", "Ref. Lat.", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("RoverGUI", "Rate", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("RoverGUI", "Ref. Long.", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("RoverGUI", "Ref. Head.", 0, QApplication::UnicodeUTF8));
        gps_update_rate->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        gps_ref_lat->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        gps_ref_long->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        gps_ref_heading->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        label_49->setText(QApplication::translate("RoverGUI", "Drift", 0, QApplication::UnicodeUTF8));
        label_50->setText(QApplication::translate("RoverGUI", "Drift Freq.", 0, QApplication::UnicodeUTF8));
        label_51->setText(QApplication::translate("RoverGUI", "Noise", 0, QApplication::UnicodeUTF8));
        gps_drift->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        gps_drift_freq->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        gps_noise->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        label_52->setText(QApplication::translate("RoverGUI", "Ref. Alt.", 0, QApplication::UnicodeUTF8));
        gps_ref_alt->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("RoverGUI", "IMU", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("RoverGUI", "Rate", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("RoverGUI", "Drift", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("RoverGUI", "Noise", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("RoverGUI", "Offsets", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("RoverGUI", "Drift", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("RoverGUI", "Noise", 0, QApplication::UnicodeUTF8));
        label_33->setText(QApplication::translate("RoverGUI", "Accel.", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("RoverGUI", "Drift", 0, QApplication::UnicodeUTF8));
        label_35->setText(QApplication::translate("RoverGUI", "Noise", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("RoverGUI", "Heading", 0, QApplication::UnicodeUTF8));
        label_37->setText(QApplication::translate("RoverGUI", "RPY", 0, QApplication::UnicodeUTF8));
        label_38->setText(QApplication::translate("RoverGUI", "Noise", 0, QApplication::UnicodeUTF8));
        imu_update_rate->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        imu_rate_drift->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        imu_rate_noise->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        imu_heading_drift->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        imu_heading_noise->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        imu_accel_drift->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        imu_accel_noise->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        imu_rpy_offsets->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        imu_noise->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        label_63->setText(QApplication::translate("RoverGUI", "Magnetic Declination", 0, QApplication::UnicodeUTF8));
        label_64->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("RoverGUI", "Camera", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("RoverGUI", "Rate", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("RoverGUI", "Width", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("RoverGUI", "Height", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("RoverGUI", "Format", 0, QApplication::UnicodeUTF8));
        camera_update_rate->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        camera_width->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        camera_height->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        camera_format->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("RoverGUI", "Noise Mean", 0, QApplication::UnicodeUTF8));
        camera_noise_mean->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        label_45->setText(QApplication::translate("RoverGUI", "Stdev", 0, QApplication::UnicodeUTF8));
        camera_noise_stdev->setText(QApplication::translate("RoverGUI", "val", 0, QApplication::UnicodeUTF8));
        visualize_simulation_button->setText(QApplication::translate("RoverGUI", "Toggle Visualization", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("RoverGUI", "Ultrasound", 0, QApplication::UnicodeUTF8));
        tab_widget->setTabText(tab_widget->indexOf(simulation_parameters_tab), QApplication::translate("RoverGUI", "Simulation Control", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("RoverGUI", "<html><head/><body><p><span style=\" color:#ffffff;\">Number of Targets Detected:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        num_targets_detected_label->setText(QApplication::translate("RoverGUI", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("RoverGUI", "<html><head/><body><p><span style=\" color:#ffffff;\">Number of Targets Collected:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        num_targets_collected_label->setText(QApplication::translate("RoverGUI", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("RoverGUI", "<html><head/><body><p><span style=\" color:#fefefe;\">Obstacle Avoidance Calls:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        perc_of_time_avoiding_obstacles->setText(QApplication::translate("RoverGUI", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        currentSimulationTimeLabel->setText(QApplication::translate("RoverGUI", "<html><head/><body><p><span style=\" color:#ffffff;\">---</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        simulationTimerStartLabel->setText(QApplication::translate("RoverGUI", "<html><head/><body><p><span style=\" color:#ffffff;\">---</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        simulationTimerStopLabel->setText(QApplication::translate("RoverGUI", "<html><head/><body><p><span style=\" color:#ffffff;\">---</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        currentSimulationTimeTitle->setText(QApplication::translate("RoverGUI", "<html><head/><body><p><span style=\" color:#fefefe;\">Current Time:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        simulationTimerStartTitle->setText(QApplication::translate("RoverGUI", "<html><head/><body><p><span style=\" color:#fefefe;\">Timer Start:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        simulationTimerStopTitle->setText(QApplication::translate("RoverGUI", "<html><head/><body><p><span style=\" color:#fefefe;\">Timer Stop:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        simulation_timer_frame_label->setText(QApplication::translate("RoverGUI", "<html><head/><body><p><span style=\" color:#fefefe;\">Simulation Timer (for simulated rovers only)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        tab_widget->setTabText(tab_widget->indexOf(stats_tab), QApplication::translate("RoverGUI", "Task Status", 0, QApplication::UnicodeUTF8));
        control_group_box->setTitle(QApplication::translate("RoverGUI", "Rover Control", 0, QApplication::UnicodeUTF8));
        autonomous_control_radio_button->setText(QApplication::translate("RoverGUI", "Autonomous", 0, QApplication::UnicodeUTF8));
        joystick_control_radio_button->setText(QApplication::translate("RoverGUI", "Manual", 0, QApplication::UnicodeUTF8));
        all_stop_button->setText(QApplication::translate("RoverGUI", "Stop All Rovers", 0, QApplication::UnicodeUTF8));
        all_autonomous_button->setText(QApplication::translate("RoverGUI", "All Autonomous", 0, QApplication::UnicodeUTF8));
        drive_label->setText(QApplication::translate("RoverGUI", "Drive", 0, QApplication::UnicodeUTF8));
        gripper_label->setText(QApplication::translate("RoverGUI", "Gripper", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RoverGUI", "<html><head/><body><p><span style=\" color:#ffffff;\">Swarmathon </span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("RoverGUI", "<html><head/><body><p><span style=\" color:#ffffff;\">Rovers</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("RoverGUI", "<html><head/><body><p><span style=\" color:#ffffff;\">Rover Interface</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("RoverGUI", "<html><head/><body><p><span style=\" color:#ffffff;\">Version: </span></p></body></html>", 0, QApplication::UnicodeUTF8));
        version_number_label->setText(QApplication::translate("RoverGUI", "<html><head/><body><p><span style=\" color:#ffffff;\">version</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        rover_name->setText(QApplication::translate("RoverGUI", "<html><head/><body><p><span style=\" color:#ffffff;\">Not Connected</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        log_tab->setTabText(log_tab->indexOf(info_log_tab), QApplication::translate("RoverGUI", "Info", 0, QApplication::UnicodeUTF8));
        log_tab->setTabText(log_tab->indexOf(diag_log_tab), QApplication::translate("RoverGUI", "Diagnostics", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("RoverGUI", "<html><head/><body><p><span style=\" font-size:9pt; color:#ffffff;\">Link Quality | Bitrate</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        map_list_label->setText(QApplication::translate("RoverGUI", "<html><head/><body><p><span style=\" font-size:9pt; color:#ffffff;\">Map</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        gps_numSV_label->setToolTip(QApplication::translate("RoverGUI", "<html><head/><body><p>Displays the number of GPS Satellites detected by the selected physical rover. Simulated rovers will not display a value here.</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        gps_numSV_label->setText(QApplication::translate("RoverGUI", "<html><head/><body><p><span style=\" color:#ffffff;\"></span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RoverGUI: public Ui_RoverGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROVER_GUI_PLUGIN_H
