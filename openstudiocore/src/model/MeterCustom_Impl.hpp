/**********************************************************************
 *  Copyright (c) 2008-2016, Alliance for Sustainable Energy.
 *  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **********************************************************************/

#ifndef MODEL_METERCUSTOM_IMPL_HPP
#define MODEL_METERCUSTOM_IMPL_HPP

#include "ModelAPI.hpp"
#include "ModelObject_Impl.hpp"


namespace openstudio {
namespace model {

namespace detail {

  /** MeterCustom_Impl is a ModelObject_Impl that is the implementation class for MeterCustom.*/
class MODEL_API MeterCustom_Impl : public ModelObject_Impl {

   public:
    /** @name Constructors and Destructors */
    //@{
    
    // constructor
    MeterCustom_Impl(const IdfObject& idfObject,
                     Model_Impl* model,
                     bool keepHandle);
    
    // construct from workspace
    MeterCustom_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                     Model_Impl* model,
                     bool keepHandle);

    // clone copy constructor
    MeterCustom_Impl(const MeterCustom_Impl& other,
                     Model_Impl* model,
                     bool keepHandle);

    // virtual destructor
    virtual ~MeterCustom_Impl() {}

    //@}
    /** @name Virtual Methods */
    //@{

    virtual const std::vector<std::string>& outputVariableNames() const;

    virtual IddObjectType iddObjectType() const;

    //@}
    /** @name Getters */
    //@{

    boost::optional<std::string> fuelType() const;

    // TODO: Handle this object's extensible fields.

    // Return a vector of (Key, Var) pairs
    std::vector< std::pair<std::string, std::string> > keyVarGroups();

    // Return the number of (KeyName, OutputVariableorMeterName) groups
    unsigned numKeyVarGroups() const;


    // Lower Level functions
    /** Get the Key Name at index. Indexing starts at 0. */
    boost::optional<std::string> keyName(unsigned index) const;

    /** Get the Output Variable of Meter Name at index. Indexing starts at 0. */
    boost::optional<std::string> outputVariableorMeterName(unsigned index) const;

    //@}
    /** @name Setters */
    //@{

    bool setFuelType(boost::optional<std::string> fuelType);

    void resetFuelType();

    // TODO: Handle this object's extensible fields.

    // Add a new (Key, Var) group
    bool addKeyVarGroup(const std::string& keyName, const std::string& outputVariableorMeterName);

    // Remove the (Key, Var) group at given index
    bool removeKeyVarGroup(unsigned groupIndex);

    // Remove all the (Key, Var) groups
    void removeAllKeyVarGroups();


    // Lower level functions
    /** Set the Key Name at index. Indexing starts at 0. */
    bool setKeyName(unsigned index, const std::string& str);

    /** Set the Output Variable of Meter Name at index. Indexing starts at 0. */
    bool setOutputVariableorMeterName(unsigned index, const std::string& str);





    //@}
    /** @name Other */
    //@{

    //@}
    /** @name Type Casting */
    //@{

    /** Get a public object that wraps this impl.*/
    template<typename T>
    T getPublicObject() const {
      T result(std::dynamic_pointer_cast<typename T::ImplType>(
                 std::const_pointer_cast<MeterCustom_Impl>(shared_from_this())));
      return result;
    }

    //@}
   protected:
   private:
    REGISTER_LOGGER("openstudio.model.MeterCustom");
  };

} // detail

} // model
} // openstudio

#endif // MODEL_METERCUSTOM_IMPL_HPP

