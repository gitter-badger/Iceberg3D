#ifndef __CAMERA_H
#define __CAMERA_H

#include "GlobalIncludes.h"

class Camera
{
    public:

        Camera(vec3 position = vec3(0.0f));
        ~Camera();

        void Update();

        // Membor Accessors
        float GetPitchSensitivity();
        void  SetPitchSensitivity(float newSens);
        float GetYawSensitivity();
        void  SetYawSensitivity(float newSens);

        void EnableInput(bool enabled = true);
        void LookAt(glm::vec3 position, glm::vec3 focusPoint, glm::vec3 up);

        glm::mat4 GetMVP(glm::mat4 &modelMatrix);

    private:

        glm::mat4 projectionMatrix;
        glm::mat4 viewMatrix;

        bool inputEnabled;

        vec3 position;
        vec3 direction;
        vec3 right;
        vec3 up;

        float horizontalAngle;
        float verticalAngle;

        float initialFOV;
        float curFOV;

        float speed;
        float pitchSensitivity;
        float yawSensitivity;

        int mouseX;
        int mouseY;

};

#endif