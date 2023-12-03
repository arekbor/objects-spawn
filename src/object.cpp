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

bool Container::Object::IsWithinBounds(Vector2 pos, Vector2 areaPos, int areaSize) {
    return pos.x > areaPos.x && pos.x < (areaPos.x + areaSize) && 
        pos.y > areaPos.y && pos.y < (areaPos.y + areaSize);
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
        DrawRectangleLines(i->GetPos().x, i->GetPos().y, OBJECT_SIZE, OBJECT_SIZE, GRAY);
    }
}

void Container::AddObjectToNearestEdge(Vector2 pos) {
    const Vector2 offsets[] = {
        { 0, -OBJECT_SIZE },
        { 0, OBJECT_SIZE },
        { -OBJECT_SIZE, 0 },
        { OBJECT_SIZE, 0 }
    };

    for(std::list<Object>::iterator i = this->objects.begin(); i != this->objects.end(); i++) {
        for(Vector2 offset : offsets) {
            Vector2 objPos = Vector2Add(i->GetPos(), offset);
            if (Container::Object::IsWithinBounds(pos, objPos, OBJECT_SIZE)) {
                this->AddObject(objPos);
                return;
            }
        }
    }
}