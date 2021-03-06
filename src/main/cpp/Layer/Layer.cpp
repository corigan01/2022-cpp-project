#include "Layer.h"

#include <string>
#include <iostream>

Layer::Layer() {
    forward_drive_speed = 0;
    turning_drive_speed = 0;

    std::cout << "[LAYER]: INIT" << std::endl;
}

Layer::~Layer() {

}

#define TO_STRING(str) #str

#define MODE_CASE(ca)         \
    case ca:                  \
        Mode = TO_STRING(ca); \
        break;


void Layer::OutputToSmartdashboard() {
    
    frc::SmartDashboard::PutNumber("Forward Driving", forward_drive_speed);
    frc::SmartDashboard::PutNumber("Turning Driving", turning_drive_speed);

    frc::SmartDashboard::PutBoolean("Left Locked", left_locked);
    frc::SmartDashboard::PutBoolean("Right Locked", right_locked);

    frc::SmartDashboard::PutNumber("pi YAW", pi_yaw);
    frc::SmartDashboard::PutNumber("pi PIT", pi_pitch);
    frc::SmartDashboard::PutNumber("pi Mode", pi_mode);
    frc::SmartDashboard::PutBoolean("Driver Mode", pi_driver_mode);
    frc::SmartDashboard::PutBoolean("Getting Info", pi_active);

    std::string Mode = "";

    switch (this->r_mode)
    {
        MODE_CASE(RobotMode::AUTO);
        MODE_CASE(RobotMode::DISABLED);
        MODE_CASE(RobotMode::PROTECTION);
        MODE_CASE(RobotMode::TELEOP);
        MODE_CASE(RobotMode::TEST);
    
    default:
        break;
    }

    Mode = Mode.substr(11);

    frc::SmartDashboard::PutString("Robot Mode", Mode);

    frc::SmartDashboard::PutNumber("Color Sensor R", cs_r);
    frc::SmartDashboard::PutNumber("Color Sensor G", cs_g);
    frc::SmartDashboard::PutNumber("Color Sensor B", cs_b);
    
}

void Layer::ProtectHuman() {
    this->r_mode = RobotMode::PROTECTION;

    this->forward_drive_speed = 0;
    this->turning_drive_speed = 0;
    this->intaking = 0;
}

void Layer::SetMode(RobotMode::mode mode) {

}