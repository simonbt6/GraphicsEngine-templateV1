
#include <graphics/Application.hpp>

Graphics::Application application;
Graphics::Layer2D* UILayer;
Graphics::Texture* texture;

Maths::mat4 projectionMatrix(1.0f);

void loop()
{
    Graphics::Primitives::Sprite sprite(texture, Graphics::Color(1, 1, 1, 1), Maths::Rectangle(0, 0, 1, 1));

    UILayer->Submit(&sprite);


    application.OnRender();
}

int main()
{
    application.SetWindowHandler(loop);
    application.OpenWindow();

    UILayer = new Graphics::Layer2D(projectionMatrix);
    application.AddLayer2D(UILayer);

    texture = new Graphics::Texture("lilo.jpg");
    projectionMatrix = Maths::mat4::Rotate(90, Maths::vec3(1, 0, 0));

    application.Start();
}