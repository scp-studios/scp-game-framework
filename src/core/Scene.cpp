#include <scp/Scene.hpp>

using scp::Scene;

scp::Scene* scp::Scene::activeScene = nullptr;

using scp::events::KeyPressEvent;
using scp::events::MouseButtonEvent;
using scp::events::MouseMoveEvent;
using scp::events::MouseScrollEvent;

void Scene::updateActive(double deltaTime)
{
    activeScene->onUpdate(deltaTime);
}










void Scene::renderActive()
{
    activeScene->render();
}










void Scene::onUpdate(double deltaTime)
{
    
}









void Scene::render()
{
    
}










void Scene::onKeyPress(KeyPressEvent& event)
{
    
}










void Scene::onMouseClick(MouseButtonEvent& event)
{
    
}










void Scene::onMouseMove(MouseMoveEvent& event)
{
    
}










void Scene::onMouseScroll(MouseScrollEvent& event)
{
    
}
