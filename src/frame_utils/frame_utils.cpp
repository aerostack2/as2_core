/*!*******************************************************************************************
 *  \file       frame_utils.cpp
 *  \brief      Aerostack2 code utils functions implementation file.
 *  \authors    Miguel Fernández Cortizas
 *              Pedro Arias Pérez
 *              David Pérez Saura
 *              Rafael Pérez Seguí
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

#include "as2_core/frame_utils/frame_utils.hpp"

namespace as2
{
    namespace FrameUtils
    {
        void quaternionToEuler(const tf2::Quaternion &quaternion, double &roll, double &pitch, double &yaw)
        {
            tf2::Matrix3x3 rotation_matrix(quaternion);
            rotation_matrix.getRPY(roll, pitch, yaw);
            return;
        }

        void quaternionToEuler(const geometry_msgs::msg::Quaternion &quaternion, double &roll, double &pitch, double &yaw)
        {
            tf2::Quaternion tf_quaternion;
            tf2::fromMsg(quaternion, tf_quaternion);
            quaternionToEuler(tf_quaternion, roll, pitch, yaw);
            return;
        }

        void quaternionToEuler(const Eigen::Quaterniond &quaternion, double &roll, double &pitch, double &yaw)
        {
            tf2::Quaternion tf_quaternion(
                quaternion.x(),
                quaternion.y(),
                quaternion.z(),
                quaternion.w()
            );
            quaternionToEuler(tf_quaternion, roll, pitch, yaw);
            return;
        }

        void eulerToQuaternion(const double &roll, const double &pitch, const double &yaw, tf2::Quaternion &quaternion)
        {
            tf2::Matrix3x3 rotation_matrix;
            rotation_matrix.setRPY(roll, pitch, yaw);
            rotation_matrix.getRotation(quaternion);
            return;
        }

        void eulerToQuaternion(const double &roll, const double &pitch, const double &yaw, geometry_msgs::msg::Quaternion &quaternion)
        {
            tf2::Quaternion tf_quaternion;
            eulerToQuaternion(roll, pitch, yaw, tf_quaternion);
            tf2::convert(tf_quaternion, quaternion);
            return;
        }

        void eulerToQuaternion(const double &roll, const double &pitch, const double &yaw, Eigen::Quaterniond &quaternion)
        {
            tf2::Quaternion tf_quaternion;
            eulerToQuaternion(roll, pitch, yaw, tf_quaternion);
            quaternion = Eigen::Quaterniond(
                tf_quaternion.w(),
                tf_quaternion.x(),
                tf_quaternion.y(),
                tf_quaternion.z()
            );
            return;
        }

        double getYawFromQuaternion(const tf2::Quaternion &quaternion)
        {
            double roll, pitch, yaw;
            quaternionToEuler(quaternion, roll, pitch, yaw);
            return yaw;
        }

        double getYawFromQuaternion(const geometry_msgs::msg::Quaternion &quaternion)
        {
            double roll, pitch, yaw;
            quaternionToEuler(quaternion, roll, pitch, yaw);
            return yaw;
        }

        double getYawFromQuaternion(const Eigen::Quaterniond &quaternion)
        {
            double roll, pitch, yaw;
            quaternionToEuler(quaternion, roll, pitch, yaw);
            return yaw;
        }

        double getVector2DAngle(const double &x, const double &y)
        {
            return atan2f(y, x);
        }

    }; // namespace FrameUtils

}; // namespace as2