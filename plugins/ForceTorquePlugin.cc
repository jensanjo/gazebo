/*
 * Copyright 2012 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
/*
 * Desc: 3D position interface for ground truth.
 * Author: Sachin Chitta and John Hsu
 * Date: 1 June 2008
 */

#include <plugins/ForceTorquePlugin.hh>

namespace gazebo
{
/////////////////////////////////////////////////
ForceTorquePlugin::ForceTorquePlugin()
{
}

/////////////////////////////////////////////////
ForceTorquePlugin::~ForceTorquePlugin()
{
  event::Events::DisconnectWorldUpdateStart(this->updateConnection);
}

/////////////////////////////////////////////////
void ForceTorquePlugin::Load(physics::ModelPtr _parent,
                                 sdf::ElementPtr /*_sdf*/)
{
  //  the world name.
  this->world = _parent->GetWorld();
  this->model = _parent;
  this->joints = this->model->GetJoints();

  // this->world->PhysicsEngine()->SetGravity(math::Vector3(0,0,0));

  // New Mechanism for Updating every World Cycle
  // Listen to the update event. This event is broadcast every
  // simulation iteration.
  this->updateConnection = event::Events::ConnectWorldUpdateStart(
      boost::bind(&ForceTorquePlugin::UpdateStates, this));
}

/////////////////////////////////////////////////
void ForceTorquePlugin::UpdateStates()
{
  common::Time cur_time = this->world->GetSimTime();

  // convert to joint frame?

  gzdbg << "-----------------------------------------------------\n";
  for (unsigned int i = 0; i < this->joints.size(); ++i)
  {
    
    if (i < 2)
      this->joints[i]->SetForce(0, 1.0);


    physics::JointWrench jw = this->joints[i]->GetForceTorque(0);
    gzdbg << "model [" << this->model->GetName()
          << "] joint [" << this->joints[i]->GetName()
          << "] b1f [" << jw.body1Force
          << "] b1t [" << jw.body1Torque
          << "] b2f [" << jw.body2Force
          << "] b2t [" << jw.body2Torque
          << "]\n";
  }
}

GZ_REGISTER_MODEL_PLUGIN(ForceTorquePlugin)
}
