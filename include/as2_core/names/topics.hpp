/*!*******************************************************************************************
 *  \file       topics.hpp
 *  \brief      This file contains the definition of the topics used by the AS2 framework.
 *  \authors    Miguel Fernández Cortizas
 *              Pedro Arias Pérez
 *              David Pérez Saura
 *              Rafael Pérez Seguí
 *
 *  \copyright  Copyright (c) 2022 Universidad Politécnica de Madrid
 *              All Rights Reserved
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ********************************************************************************/

#ifndef __AS2_NAMES_TOPICS_HPP__
#define __AS2_NAMES_TOPICS_HPP__

#include <rclcpp/rclcpp.hpp>
#include <string>

namespace as2_names
{
  namespace topics
  {
    namespace sensor_measurements
    {
      const rclcpp::QoS qos = rclcpp::SensorDataQoS();
      const std::string imu = "sensor_measurements/imu";
      const std::string lidar = "sensor_measurements/lidar";
      const std::string gps = "sensor_measurements/gps";
    }
    namespace self_localization
    {
      const rclcpp::QoS qos = rclcpp::SensorDataQoS();
      const std::string odom = "self_localization/odom";
    }
    namespace motion_reference
    {
      const rclcpp::QoS qos = rclcpp::SensorDataQoS();
      const std::string pose = "motion_reference/pose";
      const std::string twist = "motion_reference/twist";
      const std::string trajectory = "motion_reference/trajectory";
      // const rclcpp::QoS qos_wp = rclcpp::ServicesQoS();
      // const std::string wayp = "motion_reference/waypoints";
      const rclcpp::QoS qos_waypoint = rclcpp::QoS(10);
      const std::string modify_waypoint = "motion_reference/modify_waypoint";
    }
    namespace actuator_command
    {
      const rclcpp::QoS qos = rclcpp::SensorDataQoS();
      const std::string pose = "actuator_command/pose";
      const std::string twist = "actuator_command/twist";
      const std::string thrust = "actuator_command/thrust";
    }
    namespace platform
    {
      const rclcpp::QoS qos = rclcpp::QoS(10);
      const std::string info = "platform/info";
    }
    namespace controller
    {
      const rclcpp::QoS qos_info = rclcpp::QoS(10);
      const std::string info = "controller/info";
    }
  }
}
#endif // __AS2_NAMES_TOPICS_HPP__
