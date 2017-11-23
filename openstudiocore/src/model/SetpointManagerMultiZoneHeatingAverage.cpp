/***********************************************************************************************************************
 *  OpenStudio(R), Copyright (c) 2008-2017, Alliance for Sustainable Energy, LLC. All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
 *  following conditions are met:
 *
 *  (1) Redistributions of source code must retain the above copyright notice, this list of conditions and the following
 *  disclaimer.
 *
 *  (2) Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *  following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *  (3) Neither the name of the copyright holder nor the names of any contributors may be used to endorse or promote
 *  products derived from this software without specific prior written permission from the respective party.
 *
 *  (4) Other than as required in clauses (1) and (2), distributions in any form of modifications or other derivative
 *  works may not use the "OpenStudio" trademark, "OS", "os", or any other confusingly similar designation without
 *  specific prior written permission from Alliance for Sustainable Energy, LLC.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER, THE UNITED STATES GOVERNMENT, OR ANY CONTRIBUTORS BE LIABLE FOR
 *  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *  AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 **********************************************************************************************************************/

#include "SetpointManagerMultiZoneHeatingAverage.hpp"
#include "SetpointManagerMultiZoneHeatingAverage_Impl.hpp"
#include "Node.hpp"
#include "Node_Impl.hpp"

#include <utilities/idd/IddFactory.hxx>
#include <utilities/idd/OS_SetpointManager_MultiZone_Heating_Average_FieldEnums.hxx>
#include <utilities/idd/IddEnums.hxx>
#include "../utilities/core/Assert.hpp"

namespace openstudio {
namespace model {

namespace detail {

  SetpointManagerMultiZoneHeatingAverage_Impl::SetpointManagerMultiZoneHeatingAverage_Impl(const IdfObject& idfObject,
                                                                                           Model_Impl* model,
                                                                                           bool keepHandle)
    : SetpointManager_Impl(idfObject,model,keepHandle)
  {
    OS_ASSERT(idfObject.iddObject().type() == SetpointManagerMultiZoneHeatingAverage::iddObjectType());
  }

  SetpointManagerMultiZoneHeatingAverage_Impl::SetpointManagerMultiZoneHeatingAverage_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                                                                           Model_Impl* model,
                                                                                           bool keepHandle)
    : SetpointManager_Impl(other,model,keepHandle)
  {
    OS_ASSERT(other.iddObject().type() == SetpointManagerMultiZoneHeatingAverage::iddObjectType());
  }

  SetpointManagerMultiZoneHeatingAverage_Impl::SetpointManagerMultiZoneHeatingAverage_Impl(const SetpointManagerMultiZoneHeatingAverage_Impl& other,
                                                                                           Model_Impl* model,
                                                                                           bool keepHandle)
    : SetpointManager_Impl(other,model,keepHandle)
  {}

  const std::vector<std::string>& SetpointManagerMultiZoneHeatingAverage_Impl::outputVariableNames() const
  {
    static std::vector<std::string> result;
    if (result.empty()){
    }
    return result;
  }

  IddObjectType SetpointManagerMultiZoneHeatingAverage_Impl::iddObjectType() const {
    return SetpointManagerMultiZoneHeatingAverage::iddObjectType();
  }

  std::string SetpointManagerMultiZoneHeatingAverage_Impl::controlVariable() const {
    boost::optional<std::string> value = getString(OS_SetpointManager_MultiZone_Heating_AverageFields::ControlVariable,true);
    OS_ASSERT(value);
    return value.get();
  }

  double SetpointManagerMultiZoneHeatingAverage_Impl::minimumSetpointTemperature() const {
    boost::optional<double> value = getDouble(OS_SetpointManager_MultiZone_Heating_AverageFields::MinimumSetpointTemperature,true);
    OS_ASSERT(value);
    return value.get();
  }

  double SetpointManagerMultiZoneHeatingAverage_Impl::maximumSetpointTemperature() const {
    boost::optional<double> value = getDouble(OS_SetpointManager_MultiZone_Heating_AverageFields::MaximumSetpointTemperature,true);
    OS_ASSERT(value);
    return value.get();
  }

  boost::optional<Node> SetpointManagerMultiZoneHeatingAverage_Impl::setpointNode() const {
    return getObject<ModelObject>().getModelObjectTarget<Node>(OS_SetpointManager_MultiZone_Heating_AverageFields::SetpointNodeorNodeListName);
  }

  bool SetpointManagerMultiZoneHeatingAverage_Impl::setControlVariable(const std::string& controlVariable) {
    bool result = setString(OS_SetpointManager_MultiZone_Heating_AverageFields::ControlVariable, controlVariable);
    return result;
  }

  bool SetpointManagerMultiZoneHeatingAverage_Impl::setMinimumSetpointTemperature(double minimumSetpointTemperature) {
    bool result = setDouble(OS_SetpointManager_MultiZone_Heating_AverageFields::MinimumSetpointTemperature, minimumSetpointTemperature);
    return result;
  }

  bool SetpointManagerMultiZoneHeatingAverage_Impl::setMaximumSetpointTemperature(double maximumSetpointTemperature) {
    bool result = setDouble(OS_SetpointManager_MultiZone_Heating_AverageFields::MaximumSetpointTemperature, maximumSetpointTemperature);
    return result;
  }

  bool SetpointManagerMultiZoneHeatingAverage_Impl::setSetpointNode(const Node& node) {
    bool result = setPointer(OS_SetpointManager_MultiZone_Heating_AverageFields::SetpointNodeorNodeListName, node.handle());
    return result;
  }

  void SetpointManagerMultiZoneHeatingAverage_Impl::resetSetpointNode() {
    bool result = setString(OS_SetpointManager_MultiZone_Heating_AverageFields::SetpointNodeorNodeListName, "");
    OS_ASSERT(result);
  }

} // detail

SetpointManagerMultiZoneHeatingAverage::SetpointManagerMultiZoneHeatingAverage(const Model& model)
  : SetpointManager(SetpointManagerMultiZoneHeatingAverage::iddObjectType(),model)
{
  OS_ASSERT(getImpl<detail::SetpointManagerMultiZoneHeatingAverage_Impl>());

  setControlVariable("Temperature");
  setMinimumSetpointTemperature(20.);
  setMaximumSetpointTemperature(50.);
}

IddObjectType SetpointManagerMultiZoneHeatingAverage::iddObjectType() {
  return IddObjectType(IddObjectType::OS_SetpointManager_MultiZone_Heating_Average);
}

std::vector<std::string> SetpointManagerMultiZoneHeatingAverage::controlVariableValues() {
  return getIddKeyNames(IddFactory::instance().getObject(iddObjectType()).get(),
                        OS_SetpointManager_MultiZone_Heating_AverageFields::ControlVariable);
}

std::string SetpointManagerMultiZoneHeatingAverage::controlVariable() const {
  return getImpl<detail::SetpointManagerMultiZoneHeatingAverage_Impl>()->controlVariable();
}

double SetpointManagerMultiZoneHeatingAverage::minimumSetpointTemperature() const {
  return getImpl<detail::SetpointManagerMultiZoneHeatingAverage_Impl>()->minimumSetpointTemperature();
}

double SetpointManagerMultiZoneHeatingAverage::maximumSetpointTemperature() const {
  return getImpl<detail::SetpointManagerMultiZoneHeatingAverage_Impl>()->maximumSetpointTemperature();
}

boost::optional<Node> SetpointManagerMultiZoneHeatingAverage::setpointNode() const {
  return getImpl<detail::SetpointManagerMultiZoneHeatingAverage_Impl>()->setpointNode();
}

bool SetpointManagerMultiZoneHeatingAverage::setControlVariable(const std::string& controlVariable) {
  return getImpl<detail::SetpointManagerMultiZoneHeatingAverage_Impl>()->setControlVariable(controlVariable);
}

bool SetpointManagerMultiZoneHeatingAverage::setMinimumSetpointTemperature(double minimumSetpointTemperature) {
  return getImpl<detail::SetpointManagerMultiZoneHeatingAverage_Impl>()->setMinimumSetpointTemperature(minimumSetpointTemperature);
}

bool SetpointManagerMultiZoneHeatingAverage::setMaximumSetpointTemperature(double maximumSetpointTemperature) {
  return getImpl<detail::SetpointManagerMultiZoneHeatingAverage_Impl>()->setMaximumSetpointTemperature(maximumSetpointTemperature);
}

/// @cond
SetpointManagerMultiZoneHeatingAverage::SetpointManagerMultiZoneHeatingAverage(std::shared_ptr<detail::SetpointManagerMultiZoneHeatingAverage_Impl> impl)
  : SetpointManager(std::move(impl))
{}
/// @endcond

} // model
} // openstudio

