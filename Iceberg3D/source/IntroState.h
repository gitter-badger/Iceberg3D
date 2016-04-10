#include "Game.h"
#include "ShaderProgram.h"
#include "Camera.h"
#include "Model.h"
#include "Skybox.h"

class IntroState : public GameState
{
public:

    IntroState(Game* game) : GameState(game){}
    ~IntroState(){}

    void initialize() override;
    void finalize() override;

    void pause() override;
    void resume() override;

    void draw() override;
    void handle_events() override;
    void update() override;

private:

    std::unique_ptr<Model> model;
    std::shared_ptr<ShaderProgram> shaderProgram;
    glm::mat4 modelMatrix;
    std::unique_ptr<Camera> camera;
    GLuint textureID;

    std::unique_ptr<glm::mat4> modelMatrices;
    std::unique_ptr<Skybox> skybox;

    Texture houseTexture;
};
