#include "object.h"

Container::Object::Object(int id, Vector2 pos) {
    this->createdTime = GetTime();
    this->pos = pos;
    this->id = id;
}

void Container::Object::DrawObject() {
    DrawRectangle(this->pos.x, this->pos.y, OBJECT_SIZE, OBJECT_SIZE, OBJECT_COLOR);
}

int Container::Object::GetId() {
    return this->id;
}

Vector2 Container::Object::GetPos() {
    return this->pos;
}

// bool Container::Object::IsWithinBounds(Vector2 pos) {
//     return pos.x > this->pos.x && pos.x < (this->pos.x + OBJECT_SIZE) &&
//         pos.y > this->pos.y && pos.y < (this->pos.y + OBJECT_SIZE);
// }
//this method not working on bottom every object, fix this!
bool Container::Object::IsWithinBounds(Vector2 pos, Vector2 objectPos, int objectSize) {
    return pos.x > objectPos.x && pos.x < (objectPos.x + objectSize) && 
        pos.y > objectPos.y && objectPos.y < (objectPos.y + objectSize);
}

void Container::AddObject(Vector2 pos) {
    this->objects.push_front(Object(this->objects.size(), pos));
}

void Container::RemoveObject(Vector2 pos) {
    for(std::list<Object>::iterator i = this->objects.begin(); i != this->objects.end(); i++) {
        if (Container::Object::IsWithinBounds(pos, i->GetPos(), OBJECT_SIZE)) {
            this->objects.erase(i);
            break;
        }
    }
}

void Container::DrawAllObjects() {
    for(std::list<Object>::iterator i = this->objects.begin(); i != this->objects.end(); i++) {
        i->DrawObject();
    }
}

void Container::AddObjectToNearestEdge(Vector2 pos) {
    for(std::list<Object>::iterator i = this->objects.begin(); i != this->objects.end(); i++) {
        Vector2 topOffset = Vector2Add(i->GetPos(), (Vector2){ 0, -OBJECT_SIZE });
        Vector2 downOffset = Vector2Add(i->GetPos(), (Vector2){ 0, OBJECT_SIZE });
        Vector2 leftOffset = Vector2Add(i->GetPos(), (Vector2){ -OBJECT_SIZE, 0 });
        Vector2 rightOffset = Vector2Add(i->GetPos(), (Vector2){ OBJECT_SIZE, 0 });


        //DrawRectangleLines(topOffset.x, topOffset.y, OBJECT_SIZE, OBJECT_SIZE, RED);
    }
}