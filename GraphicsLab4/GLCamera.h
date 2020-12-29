#ifndef GLCAMERA_H
#define GLCAMERA_H

#include "libs\GL_AL\glew.h"
#include "libs\GL_AL\glfw3.h"

#include <cstdio>

namespace rory {
    namespace GraphCore {

        class Camera {
        public:

            virtual void setPerspective(float fov, float aspect, float near, float far) {

            };

            virtual void setPos(glm::vec3 pos) {
            };

            virtual void setTarget(glm::vec3 pos) {

            };

            virtual void start() {

            };

            virtual void end() {

            };

            virtual glm::vec3 getPos() = 0;

            virtual glm::mat4 getMat4ModelView() = 0;
            virtual glm::mat4 getMat4ModelProj() = 0;




        protected:

            glm::mat4 _modelproj = glm::mat4(0.0f);
            glm::vec3 _pos = glm::vec3(0.0f);
            glm::vec3 _direction = glm::vec3(0.0f);
            glm::mat4 _modelview = glm::mat4(0.0f);
        };

        class GLCameraFree : public Camera {
        public:

            void setPerspective(float fov, float aspect, float near1, float far1) {


                glMatrixMode(GL_PROJECTION);
                _modelproj = glm::perspective(fov, aspect, near1, far1);
                glLoadMatrixf(glm::value_ptr(_modelproj));


            };

            void setPos(glm::vec3 pos) {
                glm::vec3 target = glm::vec3(0.0f);
                glm::vec3 direction = glm::normalize(pos - target);
                _modelview = glm::lookAt(pos, direction, glm::vec3(0, 1, 0));

            }

            void start() {
                glMatrixMode(GL_MODELVIEW);
                glPushMatrix();
                glLoadMatrixf(glm::value_ptr(_modelview));
            }

            void end() {
                glPopMatrix();
            }

            glm::vec3 getPos() {
                return glm::vec3(0);
            };

            glm::mat4 getMat4ModelView() {
                return _modelview;
            };

            glm::mat4 getMat4ModelProj() {
                return _modelproj;
            };
        };

        class GLCameraTarget : public Camera {
            
        };



    };
}

#endif /* GLCAMERA_H */

