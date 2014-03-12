//
// Copyright (c) 2008-2014 the Urho3D project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#pragma once

#include "Component.h"
#include <Box2D/Box2D.h>

namespace Urho3D
{

class RigidBody2D;

/// 2D collision shape component.
class URHO3D_API CollisionShape2D : public Component
{
    OBJECT(CollisionShape2D);

public:
    /// Construct.
    CollisionShape2D(Context* scontext);
    /// Destruct.
    virtual ~CollisionShape2D();
    /// Register object factory.
    static void RegisterObject(Context* context);

    /// Handle enabled/disabled state change.
    virtual void OnSetEnabled();

    /// Set sensor (trigger).
    void SetSensor(bool sensor);
    /// Set filter category bits.
    void SetCategoryBits(unsigned short categoryBits);
    /// Set filter mask bits.
    void SetMaskBits(unsigned short maskBits);
    /// Set filter group index.
    void SetGroupIndex(short groupIndex);
    /// Set density.
    void SetDensity(float density);
    /// Set friction.
    void SetFriction(float friction);
    /// Set restitution .
    void SetRestitution(float restitution);

    /// Set circle.
    void SetCircle(float radius, const Vector2& center = Vector2::ZERO);
    /// Set box.
    void SetBox(const Vector2& halfSize, const Vector2& center = Vector2::ZERO);
    /// Set box.
    void SetBox(float halfWidth, float halfHeight, const Vector2& center = Vector2::ZERO);
    /// Set chain.
    void SetChain(const PODVector<Vector2>& vertices);
    /// Set polygon.
    void SetPolygon(const PODVector<Vector2>& vertices);
    /// Set edge.
    void SetEdge(const Vector2& vertex1, const Vector2& vertex2);
    
    /// Create fixture.
    void CreateFixture();
    /// Update fixture.
    void UpdateFixture();
    /// Release fixture.
    void ReleaseFixture();

    /// Return sensor (trigger).
    bool IsSensor() const { return fixtureDef_.isSensor; }
    /// Return filter category bits.
    unsigned short GetCategoryBits() const { return fixtureDef_.filter.categoryBits; }
    /// Return filter mask bits.
    unsigned short GetMaskBits() const { return fixtureDef_.filter.maskBits; }
    /// Return filter group index.
    short GetGroupIndex() const { return fixtureDef_.filter.groupIndex; }
    /// Return density.
    float GetDensity() const { return fixtureDef_.density; }
    /// Return friction.
    float GetFriction() const { return fixtureDef_.friction; }
    /// Return restitution.
    float GetRestitution() const { return fixtureDef_.restitution; }
    /// Return mass.
    float GetMass() const;
    /// Return inertia.
    float GetInertia() const;
    /// Return mass center.
    Vector2 GetMassCenter() const;

    /// Return fixture.
    b2Fixture* GetFixture() const { return fixture_;}
    /// Return is fixture dirty.
    bool IsFixtureDirty() const { return fixtureDirty_; }

private:
    /// Handle node being assigned.
    virtual void OnNodeSet(Node* node);
    /// Release fixture shape.
    void ReleaseFixtureShape();

    /// Rigid body.
    WeakPtr<RigidBody2D> rigidBody_;
    /// Fixture def.
    b2FixtureDef fixtureDef_;
    /// Box2D fixture.
    b2Fixture* fixture_;
    /// Shape dirty.
    bool fixtureDirty_;
};

}