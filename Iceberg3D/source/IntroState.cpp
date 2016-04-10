#include "IntroState.h"
#include "GlobalIncludes.h"

using namespace std;
using namespace glm;

void IntroState::pause(){}
void IntroState::resume(){}
void IntroState::finalize(){}
void IntroState::handle_events(){}

void IntroState::initialize()
{
    // Initialize resources
    model = make_unique<Model>("Assets/nanosuit/nanosuit.obj");

    shaderProgram = make_shared<ShaderProgram>();
    shaderProgram->create_program();
    shaderProgram->add_shader_from_file("Shaders/modelVert.glsl", GL_VERTEX_SHADER);
    shaderProgram->add_shader_from_file("Shaders/modelFrag.glsl", GL_FRAGMENT_SHADER);
    shaderProgram->link_program();

    camera = make_unique<Camera>(game_, vec3(0.0, 25.0, -70.0));
    camera->enable_input();

    SkyboxParameters skyboxParameters;
    skyboxParameters.right  = "Assets/skybox/right.jpg";
    skyboxParameters.left   = "Assets/skybox/left.jpg";
    skyboxParameters.top    = "Assets/skybox/top.jpg";
    skyboxParameters.bottom = "Assets/skybox/bottom.jpg";
    skyboxParameters.front  = "Assets/skybox/front.jpg";
    skyboxParameters.back   = "Assets/skybox/back.jpg";

    skybox = make_unique<Skybox>(skyboxParameters);
}

void IntroState::update()
{
    // Update logic
    static float angle = 0.0f;
    angle += game_->time_delta() * float(pi<float>())/2;

    camera->update(game_);

    model->transform_manager()->rotate(mat4(1.0f), angle, vec3(0.0f, 1.0f, 0.0f));

    mat4 mvp = camera->make_mvp(model->transform_manager()->model_matrix());
    shaderProgram->set_uniform("mvpMatrix", &mvp);
}

void IntroState::draw()
{
    skybox->draw(camera.get());
    model->draw(shaderProgram.get(), camera.get());
}
