/*
 * @Author: Zhang Kaixiang
 * @Date: 2022-12-12 15:33:30
 * @Mailbox: kxzhang@buaa.edu.cn
 * @Description: 
 */
#pragma once

#include <boost/shared_ptr.hpp>
#include <opencv2/core/core.hpp>

#include "camera.h"

namespace CameraModel {

class CameraFactory {
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    CameraFactory();

    static boost::shared_ptr<CameraFactory> instance(void);

    CameraPtr generateCamera(Camera::ModelType modelType,
                             const std::string &cameraName,
                             cv::Size imageSize) const;

    CameraPtr generateCameraFromYamlFile(const std::string &filename);

private:
    static boost::shared_ptr<CameraFactory> m_instance;
};

} // namespace CameraModel
