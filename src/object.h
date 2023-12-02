#ifndef OBJECT_H_
#define OBJECT_H_

#include <list>
#include "raylib.h"
#include "raymath.h"

#define OBJECT_SIZE 40
#define OBJECT_COLOR CLITERAL(WHITE)

class Container {
    public:
        class Object {
            private:
                int id;
                Vector2 pos;
                double createdTime;
            public:
                Object(int id, Vector2 pos);
                int GetId();
                Vector2 GetPos();
                void DrawObject();
                static bool IsWithinBounds(Vector2 pos, Vector2 objectPos, int objectSize);
        };
        void AddObject(Vector2 pos);
        void AddObjectToNearestEdge(Vector2 pos);
        void RemoveObject(Vector2 pos);
        void DrawAllObjects();
    private:
        std::list<Container::Object> objects;
};

#endif