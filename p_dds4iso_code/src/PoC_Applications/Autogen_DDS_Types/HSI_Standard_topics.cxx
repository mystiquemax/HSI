

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from HSI_Standard_topics.idl
using RTI Code Generator (rtiddsgen) version 4.2.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#include <iosfwd>
#include <iomanip>
#include <cmath>
#include <limits>

#ifndef NDDS_STANDALONE_TYPE
#include "rti/topic/cdr/Serialization.hpp"
#include "HSI_Standard_topicsPlugin.hpp"
#else
#include "rti/topic/cdr/SerializationHelpers.hpp"
#endif

#include "HSI_Standard_topics.hpp"

#include <rti/util/ostream_operators.hpp>

namespace Common {

    // ---- Time: 

    Time::Time() :
        m_Hours_24_ (0) ,
        m_Minutes_ (0) ,
        m_Seconds_ (0.0)  {

    }   

    Time::Time (uint8_t Hours_24_,uint8_t Minutes_,double Seconds_):
        m_Hours_24_(Hours_24_), 
        m_Minutes_(Minutes_), 
        m_Seconds_(Seconds_) {
    }

    void Time::swap(Time& other_)  noexcept 
    {
        using std::swap;
        swap(m_Hours_24_, other_.m_Hours_24_);
        swap(m_Minutes_, other_.m_Minutes_);
        swap(m_Seconds_, other_.m_Seconds_);
    }  

    bool Time::operator == (const Time& other_) const {
        if (m_Hours_24_ != other_.m_Hours_24_) {
            return false;
        }
        if (m_Minutes_ != other_.m_Minutes_) {
            return false;
        }
        if (std::fabs(m_Seconds_ - other_.m_Seconds_) > std::numeric_limits< double>::epsilon()
        && !(std::fabs(m_Seconds_ - other_.m_Seconds_) < (std::numeric_limits< double>::min)())) {
            return false;
        }
        return true;
    }

    bool Time::operator != (const Time& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const Time& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "Hours_24: " << (int) sample.Hours_24 ()<<", ";
        o << "Minutes: " << (int) sample.Minutes ()<<", ";
        o << "Seconds: " << std::setprecision(15) << sample.Seconds ();
        o <<"]";
        return o;
    }

    // ---- OnOff_t: 

    OnOff_t::OnOff_t() :
        m_on_ (0)  {

    }   

    OnOff_t::OnOff_t (bool on_):
        m_on_(on_) {
    }

    void OnOff_t::swap(OnOff_t& other_)  noexcept 
    {
        using std::swap;
        swap(m_on_, other_.m_on_);
    }  

    bool OnOff_t::operator == (const OnOff_t& other_) const {
        if (m_on_ != other_.m_on_) {
            return false;
        }
        return true;
    }

    bool OnOff_t::operator != (const OnOff_t& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const OnOff_t& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "on: " << sample.on ();
        o <<"]";
        return o;
    }

    std::ostream& operator << (std::ostream& o,const Unit_e& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        switch(sample){
            case Unit_e::m:
            o << "Unit_e::m" << " ";
            break;
            case Unit_e::m_2:
            o << "Unit_e::m_2" << " ";
            break;
            case Unit_e::m_3:
            o << "Unit_e::m_3" << " ";
            break;
            case Unit_e::kg:
            o << "Unit_e::kg" << " ";
            break;
            case Unit_e::s:
            o << "Unit_e::s" << " ";
            break;
            case Unit_e::count:
            o << "Unit_e::count" << " ";
            break;
            case Unit_e::none:
            o << "Unit_e::none" << " ";
            break;
            default:
            {
                /* Prevents compiler warnings */
            }
        }
        return o;
    }

    // ---- Unit_t: 

    Unit_t::Unit_t() :
        m_nominator_(Common::Unit_e::m) ,
        m_denominator_(Common::Unit_e::m)  {

    }   

    Unit_t::Unit_t (const ::Common::Unit_e& nominator_,const ::Common::Unit_e& denominator_):
        m_nominator_(nominator_), 
        m_denominator_(denominator_) {
    }

    void Unit_t::swap(Unit_t& other_)  noexcept 
    {
        using std::swap;
        swap(m_nominator_, other_.m_nominator_);
        swap(m_denominator_, other_.m_denominator_);
    }  

    bool Unit_t::operator == (const Unit_t& other_) const {
        if (m_nominator_ != other_.m_nominator_) {
            return false;
        }
        if (m_denominator_ != other_.m_denominator_) {
            return false;
        }
        return true;
    }

    bool Unit_t::operator != (const Unit_t& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const Unit_t& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "nominator: " << sample.nominator ()<<", ";
        o << "denominator: " << sample.denominator ();
        o <<"]";
        return o;
    }

    // ---- Date: 

    Date::Date() :
        m_Year_ (2000) ,
        m_Month_ (1) ,
        m_Day_ (1)  {

    }   

    Date::Date (int16_t Year_,uint8_t Month_,uint8_t Day_):
        m_Year_(Year_), 
        m_Month_(Month_), 
        m_Day_(Day_) {
    }

    void Date::swap(Date& other_)  noexcept 
    {
        using std::swap;
        swap(m_Year_, other_.m_Year_);
        swap(m_Month_, other_.m_Month_);
        swap(m_Day_, other_.m_Day_);
    }  

    bool Date::operator == (const Date& other_) const {
        if (m_Year_ != other_.m_Year_) {
            return false;
        }
        if (m_Month_ != other_.m_Month_) {
            return false;
        }
        if (m_Day_ != other_.m_Day_) {
            return false;
        }
        return true;
    }

    bool Date::operator != (const Date& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const Date& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "Year: " << sample.Year ()<<", ";
        o << "Month: " << (int) sample.Month ()<<", ";
        o << "Day: " << (int) sample.Day ();
        o <<"]";
        return o;
    }

} // namespace Common  

namespace DeviceInformation {

    // ---- ElementReference_t: 

    ElementReference_t::ElementReference_t() :
        m_name_ (0ull) ,
        m_element_id_ (0ull)  {

    }   

    ElementReference_t::ElementReference_t (uint64_t name_,uint64_t element_id_):
        m_name_(name_), 
        m_element_id_(element_id_) {
    }

    void ElementReference_t::swap(ElementReference_t& other_)  noexcept 
    {
        using std::swap;
        swap(m_name_, other_.m_name_);
        swap(m_element_id_, other_.m_element_id_);
    }  

    bool ElementReference_t::operator == (const ElementReference_t& other_) const {
        if (m_name_ != other_.m_name_) {
            return false;
        }
        if (m_element_id_ != other_.m_element_id_) {
            return false;
        }
        return true;
    }

    bool ElementReference_t::operator != (const ElementReference_t& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const ElementReference_t& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "name: " << sample.name ()<<", ";
        o << "element_id: " << sample.element_id ();
        o <<"]";
        return o;
    }

    // ---- Device_t: 

    Device_t::Device_t() :
        m_id_ ("") ,
        m_designator_ ("") ,
        m_software_version_ ("") ,
        m_name_ ("") ,
        m_serial_number_ ("") ,
        m_structure_label_ ("") ,
        m_localization_label_ ("")  {

    }   

    Device_t::Device_t (const std::string& id_,const std::string& designator_,const std::string& software_version_,const std::string& name_,const std::string& serial_number_,const std::string& structure_label_,const std::string& localization_label_):
        m_id_(id_), 
        m_designator_(designator_), 
        m_software_version_(software_version_), 
        m_name_(name_), 
        m_serial_number_(serial_number_), 
        m_structure_label_(structure_label_), 
        m_localization_label_(localization_label_) {
    }

    void Device_t::swap(Device_t& other_)  noexcept 
    {
        using std::swap;
        swap(m_id_, other_.m_id_);
        swap(m_designator_, other_.m_designator_);
        swap(m_software_version_, other_.m_software_version_);
        swap(m_name_, other_.m_name_);
        swap(m_serial_number_, other_.m_serial_number_);
        swap(m_structure_label_, other_.m_structure_label_);
        swap(m_localization_label_, other_.m_localization_label_);
    }  

    bool Device_t::operator == (const Device_t& other_) const {
        if (m_id_ != other_.m_id_) {
            return false;
        }
        if (m_designator_ != other_.m_designator_) {
            return false;
        }
        if (m_software_version_ != other_.m_software_version_) {
            return false;
        }
        if (m_name_ != other_.m_name_) {
            return false;
        }
        if (m_serial_number_ != other_.m_serial_number_) {
            return false;
        }
        if (m_structure_label_ != other_.m_structure_label_) {
            return false;
        }
        if (m_localization_label_ != other_.m_localization_label_) {
            return false;
        }
        return true;
    }

    bool Device_t::operator != (const Device_t& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const Device_t& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "id: " << sample.id ()<<", ";
        o << "designator: " << sample.designator ()<<", ";
        o << "software_version: " << sample.software_version ()<<", ";
        o << "name: " << sample.name ()<<", ";
        o << "serial_number: " << sample.serial_number ()<<", ";
        o << "structure_label: " << sample.structure_label ()<<", ";
        o << "localization_label: " << sample.localization_label ();
        o <<"]";
        return o;
    }

    // ---- DeviceElement_t: 

    DeviceElement_t::DeviceElement_t() :
        m_name_ ("")  {

    }   

    DeviceElement_t::DeviceElement_t (const std::string& name_,const ::DeviceInformation::ElementReference_t& element_ref_,const ::DeviceInformation::ElementReference_t& parent_ref_):
        m_name_(name_), 
        m_element_ref_(element_ref_), 
        m_parent_ref_(parent_ref_) {
    }

    void DeviceElement_t::swap(DeviceElement_t& other_)  noexcept 
    {
        using std::swap;
        swap(m_name_, other_.m_name_);
        swap(m_element_ref_, other_.m_element_ref_);
        swap(m_parent_ref_, other_.m_parent_ref_);
    }  

    bool DeviceElement_t::operator == (const DeviceElement_t& other_) const {
        if (m_name_ != other_.m_name_) {
            return false;
        }
        if (m_element_ref_ != other_.m_element_ref_) {
            return false;
        }
        if (m_parent_ref_ != other_.m_parent_ref_) {
            return false;
        }
        return true;
    }

    bool DeviceElement_t::operator != (const DeviceElement_t& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const DeviceElement_t& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "name: " << sample.name ()<<", ";
        o << "element_ref: " << sample.element_ref ()<<", ";
        o << "parent_ref: " << sample.parent_ref ();
        o <<"]";
        return o;
    }

    // ---- ServiceDiscovery_t: 

    ServiceDiscovery_t::ServiceDiscovery_t() :
        m_NAME_ (0ull)  {

    }   

    ServiceDiscovery_t::ServiceDiscovery_t (uint64_t NAME_,const ::dds::core::optional< uint8_t >& TC_client_version_,const ::dds::core::optional< uint8_t >& TC_server_version_,const ::dds::core::optional< uint8_t >& VT_client_version_,const ::dds::core::optional< uint8_t >& VT_server_version_):
        m_NAME_(NAME_), 
        m_TC_client_version_(TC_client_version_), 
        m_TC_server_version_(TC_server_version_), 
        m_VT_client_version_(VT_client_version_), 
        m_VT_server_version_(VT_server_version_) {
    }

    void ServiceDiscovery_t::swap(ServiceDiscovery_t& other_)  noexcept 
    {
        using std::swap;
        swap(m_NAME_, other_.m_NAME_);
        swap(m_TC_client_version_, other_.m_TC_client_version_);
        swap(m_TC_server_version_, other_.m_TC_server_version_);
        swap(m_VT_client_version_, other_.m_VT_client_version_);
        swap(m_VT_server_version_, other_.m_VT_server_version_);
    }  

    bool ServiceDiscovery_t::operator == (const ServiceDiscovery_t& other_) const {
        if (m_NAME_ != other_.m_NAME_) {
            return false;
        }
        if (m_TC_client_version_ != other_.m_TC_client_version_) {
            return false;
        }
        if (m_TC_server_version_ != other_.m_TC_server_version_) {
            return false;
        }
        if (m_VT_client_version_ != other_.m_VT_client_version_) {
            return false;
        }
        if (m_VT_server_version_ != other_.m_VT_server_version_) {
            return false;
        }
        return true;
    }

    bool ServiceDiscovery_t::operator != (const ServiceDiscovery_t& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const ServiceDiscovery_t& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "NAME: " << sample.NAME ()<<", ";
        o << "TC_client_version: " << sample.TC_client_version ()<<", ";
        o << "TC_server_version: " << sample.TC_server_version ()<<", ";
        o << "VT_client_version: " << sample.VT_client_version ()<<", ";
        o << "VT_server_version: " << sample.VT_server_version ();
        o <<"]";
        return o;
    }

    // ---- ServiceDiscovery_extended_t: 

    ServiceDiscovery_extended_t::ServiceDiscovery_extended_t()  {

    }   

    ServiceDiscovery_extended_t::ServiceDiscovery_extended_t (uint64_t NAME_,const ::dds::core::optional< uint8_t >& TC_client_version_,const ::dds::core::optional< uint8_t >& TC_server_version_,const ::dds::core::optional< uint8_t >& VT_client_version_,const ::dds::core::optional< uint8_t >& VT_server_version_,const ::dds::core::optional< ::rti::core::bounded_sequence< int8_t, 256L > >& hsi_conformity_certificate_) :
        ::DeviceInformation::ServiceDiscovery_t(NAME_, TC_client_version_, TC_server_version_, VT_client_version_, VT_server_version_), 
        m_hsi_conformity_certificate_(hsi_conformity_certificate_) {
    }

    void ServiceDiscovery_extended_t::swap(ServiceDiscovery_extended_t& other_)  noexcept 
    {
        using std::swap;
        ::DeviceInformation::ServiceDiscovery_t::swap(other_);
        swap(m_hsi_conformity_certificate_, other_.m_hsi_conformity_certificate_);
    }  

    bool ServiceDiscovery_extended_t::operator == (const ServiceDiscovery_extended_t& other_) const {
        if (!::DeviceInformation::ServiceDiscovery_t::operator == (other_)){
            return false;
        }
        if (m_hsi_conformity_certificate_ != other_.m_hsi_conformity_certificate_) {
            return false;
        }
        return true;
    }

    bool ServiceDiscovery_extended_t::operator != (const ServiceDiscovery_extended_t& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const ServiceDiscovery_extended_t& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << static_cast<const ::DeviceInformation::ServiceDiscovery_t &>(sample);
        o << "hsi_conformity_certificate: " << sample.hsi_conformity_certificate ();
        o <<"]";
        return o;
    }

} // namespace DeviceInformation  

namespace Actuation {

    std::ostream& operator << (std::ostream& o,const HandlingFeature_e& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        switch(sample){
            case HandlingFeature_e::minimum:
            o << "HandlingFeature_e::minimum" << " ";
            break;
            case HandlingFeature_e::maximum:
            o << "HandlingFeature_e::maximum" << " ";
            break;
            case HandlingFeature_e::actual:
            o << "HandlingFeature_e::actual" << " ";
            break;
            case HandlingFeature_e::setpoint:
            o << "HandlingFeature_e::setpoint" << " ";
            break;
            case HandlingFeature_e::iso_default:
            o << "HandlingFeature_e::iso_default" << " ";
            break;
            default:
            {
                /* Prevents compiler warnings */
            }
        }
        return o;
    }

    std::ostream& operator << (std::ostream& o,const HandlingGroup_e& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        switch(sample){
            case HandlingGroup_e::tillage_depth:
            o << "HandlingGroup_e::tillage_depth" << " ";
            break;
            case HandlingGroup_e::seeding_depth:
            o << "HandlingGroup_e::seeding_depth" << " ";
            break;
            case HandlingGroup_e::application_rate:
            o << "HandlingGroup_e::application_rate" << " ";
            break;
            case HandlingGroup_e::working_height:
            o << "HandlingGroup_e::working_height" << " ";
            break;
            case HandlingGroup_e::fill_level:
            o << "HandlingGroup_e::fill_level" << " ";
            break;
            case HandlingGroup_e::flow_rate:
            o << "HandlingGroup_e::flow_rate" << " ";
            break;
            default:
            {
                /* Prevents compiler warnings */
            }
        }
        return o;
    }

    // ---- ControlHandlingCapabilities_t: 

    ControlHandlingCapabilities_t::ControlHandlingCapabilities_t() :
        m_handling_group_(Actuation::HandlingGroup_e::tillage_depth) ,
        m_option_nr_ (0)  {

    }   

    ControlHandlingCapabilities_t::ControlHandlingCapabilities_t (const ::DeviceInformation::ElementReference_t& element_ref_,const ::Actuation::HandlingGroup_e& handling_group_,uint8_t option_nr_,const ::Common::Unit_t& unit_):
        m_element_ref_(element_ref_), 
        m_handling_group_(handling_group_), 
        m_option_nr_(option_nr_), 
        m_unit_(unit_) {
    }

    void ControlHandlingCapabilities_t::swap(ControlHandlingCapabilities_t& other_)  noexcept 
    {
        using std::swap;
        swap(m_element_ref_, other_.m_element_ref_);
        swap(m_handling_group_, other_.m_handling_group_);
        swap(m_option_nr_, other_.m_option_nr_);
        swap(m_unit_, other_.m_unit_);
    }  

    bool ControlHandlingCapabilities_t::operator == (const ControlHandlingCapabilities_t& other_) const {
        if (m_element_ref_ != other_.m_element_ref_) {
            return false;
        }
        if (m_handling_group_ != other_.m_handling_group_) {
            return false;
        }
        if (m_option_nr_ != other_.m_option_nr_) {
            return false;
        }
        if (m_unit_ != other_.m_unit_) {
            return false;
        }
        return true;
    }

    bool ControlHandlingCapabilities_t::operator != (const ControlHandlingCapabilities_t& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const ControlHandlingCapabilities_t& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "element_ref: " << sample.element_ref ()<<", ";
        o << "handling_group: " << sample.handling_group ()<<", ";
        o << "option_nr: " << (int) sample.option_nr ()<<", ";
        o << "unit: " << sample.unit ();
        o <<"]";
        return o;
    }

    // ---- ControlHandlingValues_t: 

    ControlHandlingValues_t::ControlHandlingValues_t() :
        m_handling_feature_(Actuation::HandlingFeature_e::minimum) ,
        m_handling_group_(Actuation::HandlingGroup_e::tillage_depth) ,
        m_value_ (0.0)  {

    }   

    ControlHandlingValues_t::ControlHandlingValues_t (const ::DeviceInformation::ElementReference_t& element_ref_,const ::Actuation::HandlingFeature_e& handling_feature_,const ::Actuation::HandlingGroup_e& handling_group_,double value_,const ::Common::Unit_t& unit_):
        m_element_ref_(element_ref_), 
        m_handling_feature_(handling_feature_), 
        m_handling_group_(handling_group_), 
        m_value_(value_), 
        m_unit_(unit_) {
    }

    void ControlHandlingValues_t::swap(ControlHandlingValues_t& other_)  noexcept 
    {
        using std::swap;
        swap(m_element_ref_, other_.m_element_ref_);
        swap(m_handling_feature_, other_.m_handling_feature_);
        swap(m_handling_group_, other_.m_handling_group_);
        swap(m_value_, other_.m_value_);
        swap(m_unit_, other_.m_unit_);
    }  

    bool ControlHandlingValues_t::operator == (const ControlHandlingValues_t& other_) const {
        if (m_element_ref_ != other_.m_element_ref_) {
            return false;
        }
        if (m_handling_feature_ != other_.m_handling_feature_) {
            return false;
        }
        if (m_handling_group_ != other_.m_handling_group_) {
            return false;
        }
        if (std::fabs(m_value_ - other_.m_value_) > std::numeric_limits< double>::epsilon()
        && !(std::fabs(m_value_ - other_.m_value_) < (std::numeric_limits< double>::min)())) {
            return false;
        }
        if (m_unit_ != other_.m_unit_) {
            return false;
        }
        return true;
    }

    bool ControlHandlingValues_t::operator != (const ControlHandlingValues_t& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const ControlHandlingValues_t& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "element_ref: " << sample.element_ref ()<<", ";
        o << "handling_feature: " << sample.handling_feature ()<<", ";
        o << "handling_group: " << sample.handling_group ()<<", ";
        o << "value: " << std::setprecision(15) << sample.value ()<<", ";
        o << "unit: " << sample.unit ();
        o <<"]";
        return o;
    }

} // namespace Actuation  

namespace GNSS {

    // ---- ReferenceStation: 

    ReferenceStation::ReferenceStation() :
        m_Type_ (0) ,
        m_ID_ (0) ,
        m_AgeDGNSS_ (0.0f)  {

    }   

    ReferenceStation::ReferenceStation (uint8_t Type_,uint16_t ID_,float AgeDGNSS_):
        m_Type_(Type_), 
        m_ID_(ID_), 
        m_AgeDGNSS_(AgeDGNSS_) {
    }

    void ReferenceStation::swap(ReferenceStation& other_)  noexcept 
    {
        using std::swap;
        swap(m_Type_, other_.m_Type_);
        swap(m_ID_, other_.m_ID_);
        swap(m_AgeDGNSS_, other_.m_AgeDGNSS_);
    }  

    bool ReferenceStation::operator == (const ReferenceStation& other_) const {
        if (m_Type_ != other_.m_Type_) {
            return false;
        }
        if (m_ID_ != other_.m_ID_) {
            return false;
        }
        if (std::fabs(m_AgeDGNSS_ - other_.m_AgeDGNSS_) > std::numeric_limits< float>::epsilon()
        && !(std::fabs(m_AgeDGNSS_ - other_.m_AgeDGNSS_) < (std::numeric_limits< float>::min)())) {
            return false;
        }
        return true;
    }

    bool ReferenceStation::operator != (const ReferenceStation& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const ReferenceStation& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "Type: " << (int) sample.Type ()<<", ";
        o << "ID: " << sample.ID ()<<", ";
        o << "AgeDGNSS: " << std::setprecision(9) << sample.AgeDGNSS ();
        o <<"]";
        return o;
    }

    // ---- PositionData_t: 

    PositionData_t::PositionData_t() :
        m_NAME_ (0ull) ,
        m_SID_ (0)  {

    }   

    PositionData_t::PositionData_t (uint64_t NAME_,uint8_t SID_,const ::dds::core::optional< ::Common::Date >& PositionDate_,const ::dds::core::optional< ::Common::Time >& PositionTime_,const ::dds::core::optional< double >& Lat_,const ::dds::core::optional< double >& Lon_,const ::dds::core::optional< double >& Alt_,const ::dds::core::optional< uint8_t >& TypeOfSystem_,const ::dds::core::optional< uint8_t >& Method_,const ::dds::core::optional< uint8_t >& Integrity_,const ::dds::core::optional< uint8_t >& NumOfSVs_,const ::dds::core::optional< float >& HDOP_,const ::dds::core::optional< float >& PDOP_,const ::dds::core::optional< float >& GeoidalSeparation_,const ::dds::core::optional< ::rti::core::bounded_sequence< ::GNSS::ReferenceStation, 10L > >& ReferenceStation_):
        m_NAME_(NAME_), 
        m_SID_(SID_), 
        m_PositionDate_(PositionDate_), 
        m_PositionTime_(PositionTime_), 
        m_Lat_(Lat_), 
        m_Lon_(Lon_), 
        m_Alt_(Alt_), 
        m_TypeOfSystem_(TypeOfSystem_), 
        m_Method_(Method_), 
        m_Integrity_(Integrity_), 
        m_NumOfSVs_(NumOfSVs_), 
        m_HDOP_(HDOP_), 
        m_PDOP_(PDOP_), 
        m_GeoidalSeparation_(GeoidalSeparation_), 
        m_ReferenceStation_(ReferenceStation_) {
    }

    void PositionData_t::swap(PositionData_t& other_)  noexcept 
    {
        using std::swap;
        swap(m_NAME_, other_.m_NAME_);
        swap(m_SID_, other_.m_SID_);
        swap(m_PositionDate_, other_.m_PositionDate_);
        swap(m_PositionTime_, other_.m_PositionTime_);
        swap(m_Lat_, other_.m_Lat_);
        swap(m_Lon_, other_.m_Lon_);
        swap(m_Alt_, other_.m_Alt_);
        swap(m_TypeOfSystem_, other_.m_TypeOfSystem_);
        swap(m_Method_, other_.m_Method_);
        swap(m_Integrity_, other_.m_Integrity_);
        swap(m_NumOfSVs_, other_.m_NumOfSVs_);
        swap(m_HDOP_, other_.m_HDOP_);
        swap(m_PDOP_, other_.m_PDOP_);
        swap(m_GeoidalSeparation_, other_.m_GeoidalSeparation_);
        swap(m_ReferenceStation_, other_.m_ReferenceStation_);
    }  

    bool PositionData_t::operator == (const PositionData_t& other_) const {
        if (m_NAME_ != other_.m_NAME_) {
            return false;
        }
        if (m_SID_ != other_.m_SID_) {
            return false;
        }
        if (m_PositionDate_ != other_.m_PositionDate_) {
            return false;
        }
        if (m_PositionTime_ != other_.m_PositionTime_) {
            return false;
        }
        if (m_Lat_.has_value() != other_.m_Lat_.has_value()) {
            return false;
        } else if (m_Lat_.has_value()) {
            if (std::fabs(*m_Lat_ - *other_.m_Lat_) > std::numeric_limits< double>::epsilon()
            && !(std::fabs(*m_Lat_ - *other_.m_Lat_) < (std::numeric_limits< double>::min)())) {
                return false;
            }
        }
        if (m_Lon_.has_value() != other_.m_Lon_.has_value()) {
            return false;
        } else if (m_Lon_.has_value()) {
            if (std::fabs(*m_Lon_ - *other_.m_Lon_) > std::numeric_limits< double>::epsilon()
            && !(std::fabs(*m_Lon_ - *other_.m_Lon_) < (std::numeric_limits< double>::min)())) {
                return false;
            }
        }
        if (m_Alt_.has_value() != other_.m_Alt_.has_value()) {
            return false;
        } else if (m_Alt_.has_value()) {
            if (std::fabs(*m_Alt_ - *other_.m_Alt_) > std::numeric_limits< double>::epsilon()
            && !(std::fabs(*m_Alt_ - *other_.m_Alt_) < (std::numeric_limits< double>::min)())) {
                return false;
            }
        }
        if (m_TypeOfSystem_ != other_.m_TypeOfSystem_) {
            return false;
        }
        if (m_Method_ != other_.m_Method_) {
            return false;
        }
        if (m_Integrity_ != other_.m_Integrity_) {
            return false;
        }
        if (m_NumOfSVs_ != other_.m_NumOfSVs_) {
            return false;
        }
        if (m_HDOP_.has_value() != other_.m_HDOP_.has_value()) {
            return false;
        } else if (m_HDOP_.has_value()) {
            if (std::fabs(*m_HDOP_ - *other_.m_HDOP_) > std::numeric_limits< float>::epsilon()
            && !(std::fabs(*m_HDOP_ - *other_.m_HDOP_) < (std::numeric_limits< float>::min)())) {
                return false;
            }
        }
        if (m_PDOP_.has_value() != other_.m_PDOP_.has_value()) {
            return false;
        } else if (m_PDOP_.has_value()) {
            if (std::fabs(*m_PDOP_ - *other_.m_PDOP_) > std::numeric_limits< float>::epsilon()
            && !(std::fabs(*m_PDOP_ - *other_.m_PDOP_) < (std::numeric_limits< float>::min)())) {
                return false;
            }
        }
        if (m_GeoidalSeparation_.has_value() != other_.m_GeoidalSeparation_.has_value()) {
            return false;
        } else if (m_GeoidalSeparation_.has_value()) {
            if (std::fabs(*m_GeoidalSeparation_ - *other_.m_GeoidalSeparation_) > std::numeric_limits< float>::epsilon()
            && !(std::fabs(*m_GeoidalSeparation_ - *other_.m_GeoidalSeparation_) < (std::numeric_limits< float>::min)())) {
                return false;
            }
        }
        if (m_ReferenceStation_ != other_.m_ReferenceStation_) {
            return false;
        }
        return true;
    }

    bool PositionData_t::operator != (const PositionData_t& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const PositionData_t& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "NAME: " << sample.NAME ()<<", ";
        o << "SID: " << (int) sample.SID ()<<", ";
        o << "PositionDate: " << sample.PositionDate ()<<", ";
        o << "PositionTime: " << sample.PositionTime ()<<", ";
        o << "Lat: " << sample.Lat ()<<", ";
        o << "Lon: " << sample.Lon ()<<", ";
        o << "Alt: " << sample.Alt ()<<", ";
        o << "TypeOfSystem: " << sample.TypeOfSystem ()<<", ";
        o << "Method: " << sample.Method ()<<", ";
        o << "Integrity: " << sample.Integrity ()<<", ";
        o << "NumOfSVs: " << sample.NumOfSVs ()<<", ";
        o << "HDOP: " << sample.HDOP ()<<", ";
        o << "PDOP: " << sample.PDOP ()<<", ";
        o << "GeoidalSeparation: " << sample.GeoidalSeparation ()<<", ";
        o << "ReferenceStation: " << sample.ReferenceStation ();
        o <<"]";
        return o;
    }

} // namespace GNSS  

namespace Vehicle {

    // ---- Engine: 

    Engine::Engine() :
        m_RPM_ (0) ,
        m_Fuel_Consumption_Rate_ (0) ,
        m_EGT_ (0) ,
        m_Engine_Coolant_Temperature_ (0) ,
        m_Intake_Air_Temperature_ (0) ,
        m_Throttle_Position_ (0) ,
        m_Engine_Load_ (0) ,
        m_MAF_ (0) ,
        m_Fuel_System_Pressure_ (0u)  {

    }   

    Engine::Engine (uint16_t RPM_,uint16_t Fuel_Consumption_Rate_,uint16_t EGT_,uint16_t Engine_Coolant_Temperature_,uint16_t Intake_Air_Temperature_,uint8_t Throttle_Position_,uint8_t Engine_Load_,uint8_t MAF_,uint32_t Fuel_System_Pressure_):
        m_RPM_(RPM_), 
        m_Fuel_Consumption_Rate_(Fuel_Consumption_Rate_), 
        m_EGT_(EGT_), 
        m_Engine_Coolant_Temperature_(Engine_Coolant_Temperature_), 
        m_Intake_Air_Temperature_(Intake_Air_Temperature_), 
        m_Throttle_Position_(Throttle_Position_), 
        m_Engine_Load_(Engine_Load_), 
        m_MAF_(MAF_), 
        m_Fuel_System_Pressure_(Fuel_System_Pressure_) {
    }

    void Engine::swap(Engine& other_)  noexcept 
    {
        using std::swap;
        swap(m_RPM_, other_.m_RPM_);
        swap(m_Fuel_Consumption_Rate_, other_.m_Fuel_Consumption_Rate_);
        swap(m_EGT_, other_.m_EGT_);
        swap(m_Engine_Coolant_Temperature_, other_.m_Engine_Coolant_Temperature_);
        swap(m_Intake_Air_Temperature_, other_.m_Intake_Air_Temperature_);
        swap(m_Throttle_Position_, other_.m_Throttle_Position_);
        swap(m_Engine_Load_, other_.m_Engine_Load_);
        swap(m_MAF_, other_.m_MAF_);
        swap(m_Fuel_System_Pressure_, other_.m_Fuel_System_Pressure_);
    }  

    bool Engine::operator == (const Engine& other_) const {
        if (m_RPM_ != other_.m_RPM_) {
            return false;
        }
        if (m_Fuel_Consumption_Rate_ != other_.m_Fuel_Consumption_Rate_) {
            return false;
        }
        if (m_EGT_ != other_.m_EGT_) {
            return false;
        }
        if (m_Engine_Coolant_Temperature_ != other_.m_Engine_Coolant_Temperature_) {
            return false;
        }
        if (m_Intake_Air_Temperature_ != other_.m_Intake_Air_Temperature_) {
            return false;
        }
        if (m_Throttle_Position_ != other_.m_Throttle_Position_) {
            return false;
        }
        if (m_Engine_Load_ != other_.m_Engine_Load_) {
            return false;
        }
        if (m_MAF_ != other_.m_MAF_) {
            return false;
        }
        if (m_Fuel_System_Pressure_ != other_.m_Fuel_System_Pressure_) {
            return false;
        }
        return true;
    }

    bool Engine::operator != (const Engine& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const Engine& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "RPM: " << sample.RPM ()<<", ";
        o << "Fuel_Consumption_Rate: " << sample.Fuel_Consumption_Rate ()<<", ";
        o << "EGT: " << sample.EGT ()<<", ";
        o << "Engine_Coolant_Temperature: " << sample.Engine_Coolant_Temperature ()<<", ";
        o << "Intake_Air_Temperature: " << sample.Intake_Air_Temperature ()<<", ";
        o << "Throttle_Position: " << (int) sample.Throttle_Position ()<<", ";
        o << "Engine_Load: " << (int) sample.Engine_Load ()<<", ";
        o << "MAF: " << (int) sample.MAF ()<<", ";
        o << "Fuel_System_Pressure: " << sample.Fuel_System_Pressure ();
        o <<"]";
        return o;
    }

    std::ostream& operator << (std::ostream& o,const Wheel& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        switch(sample){
            case Wheel::Front_Left:
            o << "Wheel::Front_Left" << " ";
            break;
            case Wheel::Front_Right:
            o << "Wheel::Front_Right" << " ";
            break;
            case Wheel::Rear_Left:
            o << "Wheel::Rear_Left" << " ";
            break;
            case Wheel::Rear_Right:
            o << "Wheel::Rear_Right" << " ";
            break;
            default:
            {
                /* Prevents compiler warnings */
            }
        }
        return o;
    }

    // ---- Wheel_Speed: 

    Wheel_Speed::Wheel_Speed() :
        m_Wheel_(Vehicle::Wheel::Front_Left) ,
        m_Speed_ (0)  {

    }   

    Wheel_Speed::Wheel_Speed (const ::Vehicle::Wheel& Wheel_,uint16_t Speed_):
        m_Wheel_(Wheel_), 
        m_Speed_(Speed_) {
    }

    void Wheel_Speed::swap(Wheel_Speed& other_)  noexcept 
    {
        using std::swap;
        swap(m_Wheel_, other_.m_Wheel_);
        swap(m_Speed_, other_.m_Speed_);
    }  

    bool Wheel_Speed::operator == (const Wheel_Speed& other_) const {
        if (m_Wheel_ != other_.m_Wheel_) {
            return false;
        }
        if (m_Speed_ != other_.m_Speed_) {
            return false;
        }
        return true;
    }

    bool Wheel_Speed::operator != (const Wheel_Speed& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const Wheel_Speed& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "Wheel: " << sample.Wheel ()<<", ";
        o << "Speed: " << sample.Speed ();
        o <<"]";
        return o;
    }

    // ---- Dynamics: 

    Dynamics::Dynamics() :
        m_Speed_ (0) ,
        m_Acceleration_ (0) ,
        m_Steering_Angle_ (0)  {

    }   

    Dynamics::Dynamics (uint16_t Speed_,const ::rti::core::bounded_sequence< ::Vehicle::Wheel_Speed, 4L >& Wheel_Speed_,uint8_t Acceleration_,uint16_t Steering_Angle_):
        m_Speed_(Speed_), 
        m_Wheel_Speed_(Wheel_Speed_), 
        m_Acceleration_(Acceleration_), 
        m_Steering_Angle_(Steering_Angle_) {
    }

    void Dynamics::swap(Dynamics& other_)  noexcept 
    {
        using std::swap;
        swap(m_Speed_, other_.m_Speed_);
        swap(m_Wheel_Speed_, other_.m_Wheel_Speed_);
        swap(m_Acceleration_, other_.m_Acceleration_);
        swap(m_Steering_Angle_, other_.m_Steering_Angle_);
    }  

    bool Dynamics::operator == (const Dynamics& other_) const {
        if (m_Speed_ != other_.m_Speed_) {
            return false;
        }
        if (m_Wheel_Speed_ != other_.m_Wheel_Speed_) {
            return false;
        }
        if (m_Acceleration_ != other_.m_Acceleration_) {
            return false;
        }
        if (m_Steering_Angle_ != other_.m_Steering_Angle_) {
            return false;
        }
        return true;
    }

    bool Dynamics::operator != (const Dynamics& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const Dynamics& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "Speed: " << sample.Speed ()<<", ";
        o << "Wheel_Speed: " << sample.Wheel_Speed ()<<", ";
        o << "Acceleration: " << (int) sample.Acceleration ()<<", ";
        o << "Steering_Angle: " << sample.Steering_Angle ();
        o <<"]";
        return o;
    }

    // ---- VehicleData_t: 

    VehicleData_t::VehicleData_t() :
        m_ID_ (0u)  {

    }   

    VehicleData_t::VehicleData_t (uint32_t ID_,const ::dds::core::optional< ::Vehicle::Engine >& Engine_,const ::dds::core::optional< ::Vehicle::Dynamics >& Dynamics_):
        m_ID_(ID_), 
        m_Engine_(Engine_), 
        m_Dynamics_(Dynamics_) {
    }

    void VehicleData_t::swap(VehicleData_t& other_)  noexcept 
    {
        using std::swap;
        swap(m_ID_, other_.m_ID_);
        swap(m_Engine_, other_.m_Engine_);
        swap(m_Dynamics_, other_.m_Dynamics_);
    }  

    bool VehicleData_t::operator == (const VehicleData_t& other_) const {
        if (m_ID_ != other_.m_ID_) {
            return false;
        }
        if (m_Engine_ != other_.m_Engine_) {
            return false;
        }
        if (m_Dynamics_ != other_.m_Dynamics_) {
            return false;
        }
        return true;
    }

    bool VehicleData_t::operator != (const VehicleData_t& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const VehicleData_t& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "ID: " << sample.ID ()<<", ";
        o << "Engine: " << sample.Engine ()<<", ";
        o << "Dynamics: " << sample.Dynamics ();
        o <<"]";
        return o;
    }

} // namespace Vehicle  

namespace Diagnostics {

    std::ostream& operator << (std::ostream& o,const DiagnosticType_e& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        switch(sample){
            case DiagnosticType_e::info:
            o << "DiagnosticType_e::info" << " ";
            break;
            case DiagnosticType_e::warning:
            o << "DiagnosticType_e::warning" << " ";
            break;
            case DiagnosticType_e::error_recoverable:
            o << "DiagnosticType_e::error_recoverable" << " ";
            break;
            case DiagnosticType_e::error_fatal:
            o << "DiagnosticType_e::error_fatal" << " ";
            break;
            default:
            {
                /* Prevents compiler warnings */
            }
        }
        return o;
    }

    std::ostream& operator << (std::ostream& o,const DiagnosticCode_e& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        switch(sample){
            case DiagnosticCode_e::no_diagnostic_code:
            o << "DiagnosticCode_e::no_diagnostic_code" << " ";
            break;
            case DiagnosticCode_e::unit_mismatch:
            o << "DiagnosticCode_e::unit_mismatch" << " ";
            break;
            case DiagnosticCode_e::handling_group_mismatch:
            o << "DiagnosticCode_e::handling_group_mismatch" << " ";
            break;
            default:
            {
                /* Prevents compiler warnings */
            }
        }
        return o;
    }

    // ---- Diagnostic_t: 

    Diagnostic_t::Diagnostic_t() :
        m_diagnostic_code_(Diagnostics::DiagnosticCode_e::no_diagnostic_code) ,
        m_diagnostic_type_(Diagnostics::DiagnosticType_e::info) ,
        m_message_ ("")  {

    }   

    Diagnostic_t::Diagnostic_t (const ::DeviceInformation::ElementReference_t& element_ref_,const ::Diagnostics::DiagnosticCode_e& diagnostic_code_,const ::Diagnostics::DiagnosticType_e& diagnostic_type_,const std::string& message_):
        m_element_ref_(element_ref_), 
        m_diagnostic_code_(diagnostic_code_), 
        m_diagnostic_type_(diagnostic_type_), 
        m_message_(message_) {
    }

    void Diagnostic_t::swap(Diagnostic_t& other_)  noexcept 
    {
        using std::swap;
        swap(m_element_ref_, other_.m_element_ref_);
        swap(m_diagnostic_code_, other_.m_diagnostic_code_);
        swap(m_diagnostic_type_, other_.m_diagnostic_type_);
        swap(m_message_, other_.m_message_);
    }  

    bool Diagnostic_t::operator == (const Diagnostic_t& other_) const {
        if (m_element_ref_ != other_.m_element_ref_) {
            return false;
        }
        if (m_diagnostic_code_ != other_.m_diagnostic_code_) {
            return false;
        }
        if (m_diagnostic_type_ != other_.m_diagnostic_type_) {
            return false;
        }
        if (m_message_ != other_.m_message_) {
            return false;
        }
        return true;
    }

    bool Diagnostic_t::operator != (const Diagnostic_t& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const Diagnostic_t& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "element_ref: " << sample.element_ref ()<<", ";
        o << "diagnostic_code: " << sample.diagnostic_code ()<<", ";
        o << "diagnostic_type: " << sample.diagnostic_type ()<<", ";
        o << "message: " << sample.message ();
        o <<"]";
        return o;
    }

} // namespace Diagnostics  

#ifdef NDDS_STANDALONE_TYPE
namespace rti {
    namespace topic {
        const ::Common::Unit_e default_enumerator< ::Common::Unit_e>::value = ::Common::Unit_e::m;
        const ::Actuation::HandlingFeature_e default_enumerator< ::Actuation::HandlingFeature_e>::value = ::Actuation::HandlingFeature_e::minimum;
        const ::Actuation::HandlingGroup_e default_enumerator< ::Actuation::HandlingGroup_e>::value = ::Actuation::HandlingGroup_e::tillage_depth;
        const ::Vehicle::Wheel default_enumerator< ::Vehicle::Wheel>::value = ::Vehicle::Wheel::Front_Left;
        const ::Diagnostics::DiagnosticType_e default_enumerator< ::Diagnostics::DiagnosticType_e>::value = ::Diagnostics::DiagnosticType_e::info;
        const ::Diagnostics::DiagnosticCode_e default_enumerator< ::Diagnostics::DiagnosticCode_e>::value = ::Diagnostics::DiagnosticCode_e::no_diagnostic_code;
    }
}

#else
// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        template<>
        struct native_type_code< ::Common::Time > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member Time_g_tc_members[3]=
                {

                    {
                        (char *)"Hours_24",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Minutes",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Seconds",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode Time_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Common::Time", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        Time_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for Time*/

                if (is_initialized) {
                    return &Time_g_tc;
                }

                is_initialized = RTI_TRUE;

                Time_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                Time_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                Time_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                Time_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;

                /* Initialize the values for member annotations. */
                Time_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                Time_g_tc_members[0]._annotations._defaultValue._u.octet_value = 0;
                Time_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                Time_g_tc_members[0]._annotations._minValue._u.octet_value = 0;
                Time_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                Time_g_tc_members[0]._annotations._maxValue._u.octet_value = 23;
                Time_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                Time_g_tc_members[1]._annotations._defaultValue._u.octet_value = 0;
                Time_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                Time_g_tc_members[1]._annotations._minValue._u.octet_value = 0;
                Time_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                Time_g_tc_members[1]._annotations._maxValue._u.octet_value = 59;
                Time_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_DOUBLE;
                Time_g_tc_members[2]._annotations._defaultValue._u.double_value = 0.0;
                Time_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_DOUBLE;
                Time_g_tc_members[2]._annotations._minValue._u.double_value = 0ULL;
                Time_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_DOUBLE;
                Time_g_tc_members[2]._annotations._maxValue._u.double_value = 60ULL;

                Time_g_tc._data._sampleAccessInfo = sample_access_info();
                Time_g_tc._data._typePlugin = type_plugin_info();    

                return &Time_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::Common::Time *sample;

                static RTIXCdrMemberAccessInfo Time_g_memberAccessInfos[3] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo Time_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &Time_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::Common::Time);
                if (sample == NULL) {
                    return NULL;
                }

                Time_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Hours_24() - (char *)sample);

                Time_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Minutes() - (char *)sample);

                Time_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Seconds() - (char *)sample);

                Time_g_sampleAccessInfo.memberAccessInfos = 
                Time_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::Common::Time);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        Time_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        Time_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                Time_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                Time_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::Common::Time >;

                Time_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &Time_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin Time_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &Time_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::Common::Time >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::Common::Time >::get())));
        }

        template<>
        struct native_type_code< ::Common::OnOff_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member OnOff_t_g_tc_members[1]=
                {

                    {
                        (char *)"on",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode OnOff_t_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Common::OnOff_t", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        OnOff_t_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for OnOff_t*/

                if (is_initialized) {
                    return &OnOff_t_g_tc;
                }

                is_initialized = RTI_TRUE;

                OnOff_t_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                OnOff_t_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();

                /* Initialize the values for member annotations. */
                OnOff_t_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                OnOff_t_g_tc_members[0]._annotations._defaultValue._u.boolean_value = 0;

                OnOff_t_g_tc._data._sampleAccessInfo = sample_access_info();
                OnOff_t_g_tc._data._typePlugin = type_plugin_info();    

                return &OnOff_t_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::Common::OnOff_t *sample;

                static RTIXCdrMemberAccessInfo OnOff_t_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo OnOff_t_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &OnOff_t_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::Common::OnOff_t);
                if (sample == NULL) {
                    return NULL;
                }

                OnOff_t_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->on() - (char *)sample);

                OnOff_t_g_sampleAccessInfo.memberAccessInfos = 
                OnOff_t_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::Common::OnOff_t);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        OnOff_t_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        OnOff_t_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                OnOff_t_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                OnOff_t_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::Common::OnOff_t >;

                OnOff_t_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &OnOff_t_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin OnOff_t_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &OnOff_t_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::Common::OnOff_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::Common::OnOff_t >::get())));
        }

        const ::Common::Unit_e default_enumerator< ::Common::Unit_e>::value = ::Common::Unit_e::m;
        template<>
        struct native_type_code< ::Common::Unit_e > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member Unit_e_g_tc_members[7]=
                {

                    {
                        (char *)"m",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Common::Unit_e::m), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"m_2",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Common::Unit_e::m_2), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"m_3",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Common::Unit_e::m_3), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"kg",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Common::Unit_e::kg), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"s",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Common::Unit_e::s), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"count",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Common::Unit_e::count), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"none",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Common::Unit_e::none), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode Unit_e_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Common::Unit_e", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        7, /* Number of members */
                        Unit_e_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for Unit_e*/

                if (is_initialized) {
                    return &Unit_e_g_tc;
                }

                is_initialized = RTI_TRUE;

                Unit_e_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                Unit_e_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                Unit_e_g_tc._data._annotations._defaultValue._u.long_value = 0;

                Unit_e_g_tc._data._sampleAccessInfo = sample_access_info();
                Unit_e_g_tc._data._typePlugin = type_plugin_info();    

                return &Unit_e_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo Unit_e_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo Unit_e_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &Unit_e_g_sampleAccessInfo;
                }

                Unit_e_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                Unit_e_g_sampleAccessInfo.memberAccessInfos = 
                Unit_e_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::Common::Unit_e);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        Unit_e_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        Unit_e_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                Unit_e_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                Unit_e_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::Common::Unit_e >;

                Unit_e_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &Unit_e_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin Unit_e_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &Unit_e_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::EnumType& dynamic_type< ::Common::Unit_e >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::Common::Unit_e >::get())));
        }

        template<>
        struct native_type_code< ::Common::Unit_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member Unit_t_g_tc_members[2]=
                {

                    {
                        (char *)"nominator",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"denominator",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode Unit_t_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Common::Unit_t", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        Unit_t_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for Unit_t*/

                if (is_initialized) {
                    return &Unit_t_g_tc;
                }

                is_initialized = RTI_TRUE;

                Unit_t_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                Unit_t_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::Common::Unit_e>::get().native();
                Unit_t_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::Common::Unit_e>::get().native();

                /* Initialize the values for member annotations. */
                Unit_t_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                Unit_t_g_tc_members[0]._annotations._defaultValue._u.enumerated_value = 0;
                Unit_t_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                Unit_t_g_tc_members[1]._annotations._defaultValue._u.enumerated_value = 0;

                Unit_t_g_tc._data._sampleAccessInfo = sample_access_info();
                Unit_t_g_tc._data._typePlugin = type_plugin_info();    

                return &Unit_t_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::Common::Unit_t *sample;

                static RTIXCdrMemberAccessInfo Unit_t_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo Unit_t_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &Unit_t_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::Common::Unit_t);
                if (sample == NULL) {
                    return NULL;
                }

                Unit_t_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->nominator() - (char *)sample);

                Unit_t_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->denominator() - (char *)sample);

                Unit_t_g_sampleAccessInfo.memberAccessInfos = 
                Unit_t_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::Common::Unit_t);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        Unit_t_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        Unit_t_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                Unit_t_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                Unit_t_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::Common::Unit_t >;

                Unit_t_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &Unit_t_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin Unit_t_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &Unit_t_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::Common::Unit_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::Common::Unit_t >::get())));
        }

        template<>
        struct native_type_code< ::Common::Date > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member Date_g_tc_members[3]=
                {

                    {
                        (char *)"Year",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Month",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Day",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode Date_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Common::Date", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        Date_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for Date*/

                if (is_initialized) {
                    return &Date_g_tc;
                }

                is_initialized = RTI_TRUE;

                Date_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                Date_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;
                Date_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                Date_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

                /* Initialize the values for member annotations. */
                Date_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_SHORT;
                Date_g_tc_members[0]._annotations._defaultValue._u.short_value = 2000;
                Date_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_SHORT;
                Date_g_tc_members[0]._annotations._minValue._u.short_value = RTIXCdrShort_MIN;
                Date_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_SHORT;
                Date_g_tc_members[0]._annotations._maxValue._u.short_value = RTIXCdrShort_MAX;
                Date_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                Date_g_tc_members[1]._annotations._defaultValue._u.octet_value = 1;
                Date_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                Date_g_tc_members[1]._annotations._minValue._u.octet_value = 1;
                Date_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                Date_g_tc_members[1]._annotations._maxValue._u.octet_value = 12;
                Date_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                Date_g_tc_members[2]._annotations._defaultValue._u.octet_value = 1;
                Date_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                Date_g_tc_members[2]._annotations._minValue._u.octet_value = 1;
                Date_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                Date_g_tc_members[2]._annotations._maxValue._u.octet_value = 31;

                Date_g_tc._data._sampleAccessInfo = sample_access_info();
                Date_g_tc._data._typePlugin = type_plugin_info();    

                return &Date_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::Common::Date *sample;

                static RTIXCdrMemberAccessInfo Date_g_memberAccessInfos[3] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo Date_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &Date_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::Common::Date);
                if (sample == NULL) {
                    return NULL;
                }

                Date_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Year() - (char *)sample);

                Date_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Month() - (char *)sample);

                Date_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Day() - (char *)sample);

                Date_g_sampleAccessInfo.memberAccessInfos = 
                Date_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::Common::Date);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        Date_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        Date_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                Date_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                Date_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::Common::Date >;

                Date_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &Date_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin Date_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &Date_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::Common::Date >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::Common::Date >::get())));
        }

        template<>
        struct native_type_code< ::DeviceInformation::ElementReference_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member ElementReference_t_g_tc_members[2]=
                {

                    {
                        (char *)"name",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"element_id",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode ElementReference_t_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DeviceInformation::ElementReference_t", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        ElementReference_t_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for ElementReference_t*/

                if (is_initialized) {
                    return &ElementReference_t_g_tc;
                }

                is_initialized = RTI_TRUE;

                ElementReference_t_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                ElementReference_t_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulonglong;
                ElementReference_t_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulonglong;

                /* Initialize the values for member annotations. */
                ElementReference_t_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ULONGLONG;
                ElementReference_t_g_tc_members[0]._annotations._defaultValue._u.ulong_long_value = 0ull;
                ElementReference_t_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_ULONGLONG;
                ElementReference_t_g_tc_members[0]._annotations._minValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MIN;
                ElementReference_t_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_ULONGLONG;
                ElementReference_t_g_tc_members[0]._annotations._maxValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MAX;
                ElementReference_t_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ULONGLONG;
                ElementReference_t_g_tc_members[1]._annotations._defaultValue._u.ulong_long_value = 0ull;
                ElementReference_t_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_ULONGLONG;
                ElementReference_t_g_tc_members[1]._annotations._minValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MIN;
                ElementReference_t_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_ULONGLONG;
                ElementReference_t_g_tc_members[1]._annotations._maxValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MAX;

                ElementReference_t_g_tc._data._sampleAccessInfo = sample_access_info();
                ElementReference_t_g_tc._data._typePlugin = type_plugin_info();    

                return &ElementReference_t_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::DeviceInformation::ElementReference_t *sample;

                static RTIXCdrMemberAccessInfo ElementReference_t_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ElementReference_t_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ElementReference_t_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::DeviceInformation::ElementReference_t);
                if (sample == NULL) {
                    return NULL;
                }

                ElementReference_t_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->name() - (char *)sample);

                ElementReference_t_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->element_id() - (char *)sample);

                ElementReference_t_g_sampleAccessInfo.memberAccessInfos = 
                ElementReference_t_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::DeviceInformation::ElementReference_t);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        ElementReference_t_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        ElementReference_t_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ElementReference_t_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ElementReference_t_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::DeviceInformation::ElementReference_t >;

                ElementReference_t_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ElementReference_t_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ElementReference_t_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &ElementReference_t_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::DeviceInformation::ElementReference_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::DeviceInformation::ElementReference_t >::get())));
        }

        template<>
        struct native_type_code< ::DeviceInformation::Device_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode Device_t_g_tc_id_string;
                static DDS_TypeCode Device_t_g_tc_designator_string;
                static DDS_TypeCode Device_t_g_tc_software_version_string;
                static DDS_TypeCode Device_t_g_tc_name_string;
                static DDS_TypeCode Device_t_g_tc_serial_number_string;
                static DDS_TypeCode Device_t_g_tc_structure_label_string;
                static DDS_TypeCode Device_t_g_tc_localization_label_string;

                static DDS_TypeCode_Member Device_t_g_tc_members[7]=
                {

                    {
                        (char *)"id",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"designator",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"software_version",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"name",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"serial_number",/* Member name */
                        {
                            4,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"structure_label",/* Member name */
                        {
                            5,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"localization_label",/* Member name */
                        {
                            6,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode Device_t_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DeviceInformation::Device_t", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        7, /* Number of members */
                        Device_t_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for Device_t*/

                if (is_initialized) {
                    return &Device_t_g_tc;
                }

                is_initialized = RTI_TRUE;

                Device_t_g_tc_id_string = initialize_string_typecode((100L));
                Device_t_g_tc_designator_string = initialize_string_typecode((100L));
                Device_t_g_tc_software_version_string = initialize_string_typecode((100L));
                Device_t_g_tc_name_string = initialize_string_typecode((100L));
                Device_t_g_tc_serial_number_string = initialize_string_typecode((100L));
                Device_t_g_tc_structure_label_string = initialize_string_typecode((100L));
                Device_t_g_tc_localization_label_string = initialize_string_typecode((100L));

                Device_t_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                Device_t_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&Device_t_g_tc_id_string;
                Device_t_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&Device_t_g_tc_designator_string;
                Device_t_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&Device_t_g_tc_software_version_string;
                Device_t_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&Device_t_g_tc_name_string;
                Device_t_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&Device_t_g_tc_serial_number_string;
                Device_t_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&Device_t_g_tc_structure_label_string;
                Device_t_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&Device_t_g_tc_localization_label_string;

                /* Initialize the values for member annotations. */
                Device_t_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                Device_t_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";
                Device_t_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                Device_t_g_tc_members[1]._annotations._defaultValue._u.string_value = (DDS_Char *) "";
                Device_t_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                Device_t_g_tc_members[2]._annotations._defaultValue._u.string_value = (DDS_Char *) "";
                Device_t_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                Device_t_g_tc_members[3]._annotations._defaultValue._u.string_value = (DDS_Char *) "";
                Device_t_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                Device_t_g_tc_members[4]._annotations._defaultValue._u.string_value = (DDS_Char *) "";
                Device_t_g_tc_members[5]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                Device_t_g_tc_members[5]._annotations._defaultValue._u.string_value = (DDS_Char *) "";
                Device_t_g_tc_members[6]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                Device_t_g_tc_members[6]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                Device_t_g_tc._data._sampleAccessInfo = sample_access_info();
                Device_t_g_tc._data._typePlugin = type_plugin_info();    

                return &Device_t_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::DeviceInformation::Device_t *sample;

                static RTIXCdrMemberAccessInfo Device_t_g_memberAccessInfos[7] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo Device_t_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &Device_t_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::DeviceInformation::Device_t);
                if (sample == NULL) {
                    return NULL;
                }

                Device_t_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->id() - (char *)sample);

                Device_t_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->designator() - (char *)sample);

                Device_t_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->software_version() - (char *)sample);

                Device_t_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->name() - (char *)sample);

                Device_t_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->serial_number() - (char *)sample);

                Device_t_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->structure_label() - (char *)sample);

                Device_t_g_memberAccessInfos[6].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->localization_label() - (char *)sample);

                Device_t_g_sampleAccessInfo.memberAccessInfos = 
                Device_t_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::DeviceInformation::Device_t);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        Device_t_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        Device_t_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                Device_t_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                Device_t_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::DeviceInformation::Device_t >;

                Device_t_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &Device_t_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin Device_t_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &Device_t_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::DeviceInformation::Device_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::DeviceInformation::Device_t >::get())));
        }

        template<>
        struct native_type_code< ::DeviceInformation::DeviceElement_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode DeviceElement_t_g_tc_name_string;

                static DDS_TypeCode_Member DeviceElement_t_g_tc_members[3]=
                {

                    {
                        (char *)"name",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"element_ref",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"parent_ref",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode DeviceElement_t_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DeviceInformation::DeviceElement_t", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        DeviceElement_t_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for DeviceElement_t*/

                if (is_initialized) {
                    return &DeviceElement_t_g_tc;
                }

                is_initialized = RTI_TRUE;

                DeviceElement_t_g_tc_name_string = initialize_string_typecode((100L));

                DeviceElement_t_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                DeviceElement_t_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DeviceElement_t_g_tc_name_string;
                DeviceElement_t_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::DeviceInformation::ElementReference_t>::get().native();
                DeviceElement_t_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::DeviceInformation::ElementReference_t>::get().native();

                /* Initialize the values for member annotations. */
                DeviceElement_t_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                DeviceElement_t_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                DeviceElement_t_g_tc._data._sampleAccessInfo = sample_access_info();
                DeviceElement_t_g_tc._data._typePlugin = type_plugin_info();    

                return &DeviceElement_t_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::DeviceInformation::DeviceElement_t *sample;

                static RTIXCdrMemberAccessInfo DeviceElement_t_g_memberAccessInfos[3] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo DeviceElement_t_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &DeviceElement_t_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::DeviceInformation::DeviceElement_t);
                if (sample == NULL) {
                    return NULL;
                }

                DeviceElement_t_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->name() - (char *)sample);

                DeviceElement_t_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->element_ref() - (char *)sample);

                DeviceElement_t_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->parent_ref() - (char *)sample);

                DeviceElement_t_g_sampleAccessInfo.memberAccessInfos = 
                DeviceElement_t_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::DeviceInformation::DeviceElement_t);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        DeviceElement_t_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        DeviceElement_t_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                DeviceElement_t_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                DeviceElement_t_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::DeviceInformation::DeviceElement_t >;

                DeviceElement_t_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &DeviceElement_t_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin DeviceElement_t_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &DeviceElement_t_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::DeviceInformation::DeviceElement_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::DeviceInformation::DeviceElement_t >::get())));
        }

        template<>
        struct native_type_code< ::DeviceInformation::ServiceDiscovery_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member ServiceDiscovery_t_g_tc_members[5]=
                {

                    {
                        (char *)"NAME",/* Member name */
                        {
                            82195117,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"TC_client_version",/* Member name */
                        {
                            141986760,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"TC_server_version",/* Member name */
                        {
                            29364960,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"VT_client_version",/* Member name */
                        {
                            141461715,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"VT_server_version",/* Member name */
                        {
                            222723738,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode ServiceDiscovery_t_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DeviceInformation::ServiceDiscovery_t", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        5, /* Number of members */
                        ServiceDiscovery_t_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for ServiceDiscovery_t*/

                if (is_initialized) {
                    return &ServiceDiscovery_t_g_tc;
                }

                is_initialized = RTI_TRUE;

                ServiceDiscovery_t_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                ServiceDiscovery_t_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulonglong;
                ServiceDiscovery_t_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                ServiceDiscovery_t_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                ServiceDiscovery_t_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                ServiceDiscovery_t_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

                /* Initialize the values for member annotations. */
                ServiceDiscovery_t_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ULONGLONG;
                ServiceDiscovery_t_g_tc_members[0]._annotations._defaultValue._u.ulong_long_value = 0ull;
                ServiceDiscovery_t_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_ULONGLONG;
                ServiceDiscovery_t_g_tc_members[0]._annotations._minValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MIN;
                ServiceDiscovery_t_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_ULONGLONG;
                ServiceDiscovery_t_g_tc_members[0]._annotations._maxValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MAX;
                ServiceDiscovery_t_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                ServiceDiscovery_t_g_tc_members[1]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                ServiceDiscovery_t_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                ServiceDiscovery_t_g_tc_members[1]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;
                ServiceDiscovery_t_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                ServiceDiscovery_t_g_tc_members[2]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                ServiceDiscovery_t_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                ServiceDiscovery_t_g_tc_members[2]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;
                ServiceDiscovery_t_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                ServiceDiscovery_t_g_tc_members[3]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                ServiceDiscovery_t_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                ServiceDiscovery_t_g_tc_members[3]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;
                ServiceDiscovery_t_g_tc_members[4]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                ServiceDiscovery_t_g_tc_members[4]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                ServiceDiscovery_t_g_tc_members[4]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                ServiceDiscovery_t_g_tc_members[4]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;

                ServiceDiscovery_t_g_tc._data._sampleAccessInfo = sample_access_info();
                ServiceDiscovery_t_g_tc._data._typePlugin = type_plugin_info();    

                return &ServiceDiscovery_t_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::DeviceInformation::ServiceDiscovery_t *sample;

                static RTIXCdrMemberAccessInfo ServiceDiscovery_t_g_memberAccessInfos[5] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ServiceDiscovery_t_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ServiceDiscovery_t_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::DeviceInformation::ServiceDiscovery_t);
                if (sample == NULL) {
                    return NULL;
                }

                ServiceDiscovery_t_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->NAME() - (char *)sample);

                ServiceDiscovery_t_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->TC_client_version() - (char *)sample);

                ServiceDiscovery_t_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->TC_server_version() - (char *)sample);

                ServiceDiscovery_t_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->VT_client_version() - (char *)sample);

                ServiceDiscovery_t_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->VT_server_version() - (char *)sample);

                ServiceDiscovery_t_g_sampleAccessInfo.memberAccessInfos = 
                ServiceDiscovery_t_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::DeviceInformation::ServiceDiscovery_t);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        ServiceDiscovery_t_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        ServiceDiscovery_t_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ServiceDiscovery_t_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ServiceDiscovery_t_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::DeviceInformation::ServiceDiscovery_t >;

                ServiceDiscovery_t_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ServiceDiscovery_t_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ServiceDiscovery_t_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &ServiceDiscovery_t_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::DeviceInformation::ServiceDiscovery_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::DeviceInformation::ServiceDiscovery_t >::get())));
        }

        template<>
        struct native_type_code< ::DeviceInformation::ServiceDiscovery_extended_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode ServiceDiscovery_extended_t_g_tc_hsi_conformity_certificate_sequence;

                static DDS_TypeCode_Member ServiceDiscovery_extended_t_g_tc_members[1]=
                {

                    {
                        (char *)"hsi_conformity_certificate",/* Member name */
                        {
                            173148305,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode ServiceDiscovery_extended_t_g_tc =
                {{
                        DDS_TK_VALUE, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DeviceInformation::ServiceDiscovery_extended_t", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        ServiceDiscovery_extended_t_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for ServiceDiscovery_extended_t*/

                if (is_initialized) {
                    return &ServiceDiscovery_extended_t_g_tc;
                }

                is_initialized = RTI_TRUE;

                ServiceDiscovery_extended_t_g_tc_hsi_conformity_certificate_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< int8_t, 256L > >((256L));

                ServiceDiscovery_extended_t_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                ServiceDiscovery_extended_t_g_tc_hsi_conformity_certificate_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                ServiceDiscovery_extended_t_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)& ServiceDiscovery_extended_t_g_tc_hsi_conformity_certificate_sequence;

                /* Initialize the values for member annotations. */

                ServiceDiscovery_extended_t_g_tc._data._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::DeviceInformation::ServiceDiscovery_t >::get().native(); /* Base class */

                ServiceDiscovery_extended_t_g_tc._data._sampleAccessInfo = sample_access_info();
                ServiceDiscovery_extended_t_g_tc._data._typePlugin = type_plugin_info();    

                return &ServiceDiscovery_extended_t_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::DeviceInformation::ServiceDiscovery_extended_t *sample;

                static RTIXCdrMemberAccessInfo ServiceDiscovery_extended_t_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ServiceDiscovery_extended_t_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ServiceDiscovery_extended_t_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::DeviceInformation::ServiceDiscovery_extended_t);
                if (sample == NULL) {
                    return NULL;
                }

                ServiceDiscovery_extended_t_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->hsi_conformity_certificate() - (char *)sample);

                ServiceDiscovery_extended_t_g_sampleAccessInfo.memberAccessInfos = 
                ServiceDiscovery_extended_t_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::DeviceInformation::ServiceDiscovery_extended_t);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        ServiceDiscovery_extended_t_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        ServiceDiscovery_extended_t_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ServiceDiscovery_extended_t_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ServiceDiscovery_extended_t_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::DeviceInformation::ServiceDiscovery_extended_t >;

                ServiceDiscovery_extended_t_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ServiceDiscovery_extended_t_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ServiceDiscovery_extended_t_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &ServiceDiscovery_extended_t_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::DeviceInformation::ServiceDiscovery_extended_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::DeviceInformation::ServiceDiscovery_extended_t >::get())));
        }

        const ::Actuation::HandlingFeature_e default_enumerator< ::Actuation::HandlingFeature_e>::value = ::Actuation::HandlingFeature_e::minimum;
        template<>
        struct native_type_code< ::Actuation::HandlingFeature_e > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member HandlingFeature_e_g_tc_members[5]=
                {

                    {
                        (char *)"minimum",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Actuation::HandlingFeature_e::minimum), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"maximum",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Actuation::HandlingFeature_e::maximum), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"actual",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Actuation::HandlingFeature_e::actual), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"setpoint",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Actuation::HandlingFeature_e::setpoint), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"iso_default",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Actuation::HandlingFeature_e::iso_default), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode HandlingFeature_e_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Actuation::HandlingFeature_e", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        5, /* Number of members */
                        HandlingFeature_e_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for HandlingFeature_e*/

                if (is_initialized) {
                    return &HandlingFeature_e_g_tc;
                }

                is_initialized = RTI_TRUE;

                HandlingFeature_e_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                HandlingFeature_e_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                HandlingFeature_e_g_tc._data._annotations._defaultValue._u.long_value = 0;

                HandlingFeature_e_g_tc._data._sampleAccessInfo = sample_access_info();
                HandlingFeature_e_g_tc._data._typePlugin = type_plugin_info();    

                return &HandlingFeature_e_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo HandlingFeature_e_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo HandlingFeature_e_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &HandlingFeature_e_g_sampleAccessInfo;
                }

                HandlingFeature_e_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                HandlingFeature_e_g_sampleAccessInfo.memberAccessInfos = 
                HandlingFeature_e_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::Actuation::HandlingFeature_e);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        HandlingFeature_e_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        HandlingFeature_e_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                HandlingFeature_e_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                HandlingFeature_e_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::Actuation::HandlingFeature_e >;

                HandlingFeature_e_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &HandlingFeature_e_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin HandlingFeature_e_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &HandlingFeature_e_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::EnumType& dynamic_type< ::Actuation::HandlingFeature_e >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::Actuation::HandlingFeature_e >::get())));
        }

        const ::Actuation::HandlingGroup_e default_enumerator< ::Actuation::HandlingGroup_e>::value = ::Actuation::HandlingGroup_e::tillage_depth;
        template<>
        struct native_type_code< ::Actuation::HandlingGroup_e > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member HandlingGroup_e_g_tc_members[6]=
                {

                    {
                        (char *)"tillage_depth",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Actuation::HandlingGroup_e::tillage_depth), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"seeding_depth",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Actuation::HandlingGroup_e::seeding_depth), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"application_rate",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Actuation::HandlingGroup_e::application_rate), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"working_height",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Actuation::HandlingGroup_e::working_height), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"fill_level",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Actuation::HandlingGroup_e::fill_level), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"flow_rate",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Actuation::HandlingGroup_e::flow_rate), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode HandlingGroup_e_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Actuation::HandlingGroup_e", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        6, /* Number of members */
                        HandlingGroup_e_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for HandlingGroup_e*/

                if (is_initialized) {
                    return &HandlingGroup_e_g_tc;
                }

                is_initialized = RTI_TRUE;

                HandlingGroup_e_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                HandlingGroup_e_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                HandlingGroup_e_g_tc._data._annotations._defaultValue._u.long_value = 0;

                HandlingGroup_e_g_tc._data._sampleAccessInfo = sample_access_info();
                HandlingGroup_e_g_tc._data._typePlugin = type_plugin_info();    

                return &HandlingGroup_e_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo HandlingGroup_e_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo HandlingGroup_e_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &HandlingGroup_e_g_sampleAccessInfo;
                }

                HandlingGroup_e_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                HandlingGroup_e_g_sampleAccessInfo.memberAccessInfos = 
                HandlingGroup_e_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::Actuation::HandlingGroup_e);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        HandlingGroup_e_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        HandlingGroup_e_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                HandlingGroup_e_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                HandlingGroup_e_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::Actuation::HandlingGroup_e >;

                HandlingGroup_e_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &HandlingGroup_e_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin HandlingGroup_e_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &HandlingGroup_e_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::EnumType& dynamic_type< ::Actuation::HandlingGroup_e >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::Actuation::HandlingGroup_e >::get())));
        }

        template<>
        struct native_type_code< ::Actuation::ControlHandlingCapabilities_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member ControlHandlingCapabilities_t_g_tc_members[4]=
                {

                    {
                        (char *)"element_ref",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"handling_group",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"option_nr",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"unit",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode ControlHandlingCapabilities_t_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Actuation::ControlHandlingCapabilities_t", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        ControlHandlingCapabilities_t_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for ControlHandlingCapabilities_t*/

                if (is_initialized) {
                    return &ControlHandlingCapabilities_t_g_tc;
                }

                is_initialized = RTI_TRUE;

                ControlHandlingCapabilities_t_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                ControlHandlingCapabilities_t_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::DeviceInformation::ElementReference_t>::get().native();
                ControlHandlingCapabilities_t_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::Actuation::HandlingGroup_e>::get().native();
                ControlHandlingCapabilities_t_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                ControlHandlingCapabilities_t_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::Common::Unit_t>::get().native();

                /* Initialize the values for member annotations. */
                ControlHandlingCapabilities_t_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                ControlHandlingCapabilities_t_g_tc_members[1]._annotations._defaultValue._u.enumerated_value = 0;
                ControlHandlingCapabilities_t_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                ControlHandlingCapabilities_t_g_tc_members[2]._annotations._defaultValue._u.octet_value = 0;
                ControlHandlingCapabilities_t_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                ControlHandlingCapabilities_t_g_tc_members[2]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                ControlHandlingCapabilities_t_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                ControlHandlingCapabilities_t_g_tc_members[2]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;

                ControlHandlingCapabilities_t_g_tc._data._sampleAccessInfo = sample_access_info();
                ControlHandlingCapabilities_t_g_tc._data._typePlugin = type_plugin_info();    

                return &ControlHandlingCapabilities_t_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::Actuation::ControlHandlingCapabilities_t *sample;

                static RTIXCdrMemberAccessInfo ControlHandlingCapabilities_t_g_memberAccessInfos[4] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ControlHandlingCapabilities_t_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ControlHandlingCapabilities_t_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::Actuation::ControlHandlingCapabilities_t);
                if (sample == NULL) {
                    return NULL;
                }

                ControlHandlingCapabilities_t_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->element_ref() - (char *)sample);

                ControlHandlingCapabilities_t_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->handling_group() - (char *)sample);

                ControlHandlingCapabilities_t_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->option_nr() - (char *)sample);

                ControlHandlingCapabilities_t_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->unit() - (char *)sample);

                ControlHandlingCapabilities_t_g_sampleAccessInfo.memberAccessInfos = 
                ControlHandlingCapabilities_t_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::Actuation::ControlHandlingCapabilities_t);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        ControlHandlingCapabilities_t_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        ControlHandlingCapabilities_t_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ControlHandlingCapabilities_t_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ControlHandlingCapabilities_t_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::Actuation::ControlHandlingCapabilities_t >;

                ControlHandlingCapabilities_t_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ControlHandlingCapabilities_t_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ControlHandlingCapabilities_t_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &ControlHandlingCapabilities_t_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::Actuation::ControlHandlingCapabilities_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::Actuation::ControlHandlingCapabilities_t >::get())));
        }

        template<>
        struct native_type_code< ::Actuation::ControlHandlingValues_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member ControlHandlingValues_t_g_tc_members[5]=
                {

                    {
                        (char *)"element_ref",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"handling_feature",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"handling_group",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"value",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"unit",/* Member name */
                        {
                            4,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode ControlHandlingValues_t_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Actuation::ControlHandlingValues_t", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        5, /* Number of members */
                        ControlHandlingValues_t_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for ControlHandlingValues_t*/

                if (is_initialized) {
                    return &ControlHandlingValues_t_g_tc;
                }

                is_initialized = RTI_TRUE;

                ControlHandlingValues_t_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                ControlHandlingValues_t_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::DeviceInformation::ElementReference_t>::get().native();
                ControlHandlingValues_t_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::Actuation::HandlingFeature_e>::get().native();
                ControlHandlingValues_t_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::Actuation::HandlingGroup_e>::get().native();
                ControlHandlingValues_t_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
                ControlHandlingValues_t_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::Common::Unit_t>::get().native();

                /* Initialize the values for member annotations. */
                ControlHandlingValues_t_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                ControlHandlingValues_t_g_tc_members[1]._annotations._defaultValue._u.enumerated_value = 0;
                ControlHandlingValues_t_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                ControlHandlingValues_t_g_tc_members[2]._annotations._defaultValue._u.enumerated_value = 0;
                ControlHandlingValues_t_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_DOUBLE;
                ControlHandlingValues_t_g_tc_members[3]._annotations._defaultValue._u.double_value = 0.0;
                ControlHandlingValues_t_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_DOUBLE;
                ControlHandlingValues_t_g_tc_members[3]._annotations._minValue._u.double_value = RTIXCdrDouble_MIN;
                ControlHandlingValues_t_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_DOUBLE;
                ControlHandlingValues_t_g_tc_members[3]._annotations._maxValue._u.double_value = RTIXCdrDouble_MAX;

                ControlHandlingValues_t_g_tc._data._sampleAccessInfo = sample_access_info();
                ControlHandlingValues_t_g_tc._data._typePlugin = type_plugin_info();    

                return &ControlHandlingValues_t_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::Actuation::ControlHandlingValues_t *sample;

                static RTIXCdrMemberAccessInfo ControlHandlingValues_t_g_memberAccessInfos[5] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ControlHandlingValues_t_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ControlHandlingValues_t_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::Actuation::ControlHandlingValues_t);
                if (sample == NULL) {
                    return NULL;
                }

                ControlHandlingValues_t_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->element_ref() - (char *)sample);

                ControlHandlingValues_t_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->handling_feature() - (char *)sample);

                ControlHandlingValues_t_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->handling_group() - (char *)sample);

                ControlHandlingValues_t_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->value() - (char *)sample);

                ControlHandlingValues_t_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->unit() - (char *)sample);

                ControlHandlingValues_t_g_sampleAccessInfo.memberAccessInfos = 
                ControlHandlingValues_t_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::Actuation::ControlHandlingValues_t);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        ControlHandlingValues_t_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        ControlHandlingValues_t_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ControlHandlingValues_t_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ControlHandlingValues_t_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::Actuation::ControlHandlingValues_t >;

                ControlHandlingValues_t_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ControlHandlingValues_t_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ControlHandlingValues_t_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &ControlHandlingValues_t_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::Actuation::ControlHandlingValues_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::Actuation::ControlHandlingValues_t >::get())));
        }

        template<>
        struct native_type_code< ::GNSS::ReferenceStation > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member ReferenceStation_g_tc_members[3]=
                {

                    {
                        (char *)"Type",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"ID",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"AgeDGNSS",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode ReferenceStation_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"GNSS::ReferenceStation", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        ReferenceStation_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for ReferenceStation*/

                if (is_initialized) {
                    return &ReferenceStation_g_tc;
                }

                is_initialized = RTI_TRUE;

                ReferenceStation_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                ReferenceStation_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                ReferenceStation_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                ReferenceStation_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                /* Initialize the values for member annotations. */
                ReferenceStation_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                ReferenceStation_g_tc_members[0]._annotations._defaultValue._u.octet_value = 0;
                ReferenceStation_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                ReferenceStation_g_tc_members[0]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                ReferenceStation_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                ReferenceStation_g_tc_members[0]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;
                ReferenceStation_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                ReferenceStation_g_tc_members[1]._annotations._defaultValue._u.ushort_value = 0;
                ReferenceStation_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                ReferenceStation_g_tc_members[1]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
                ReferenceStation_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                ReferenceStation_g_tc_members[1]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;
                ReferenceStation_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
                ReferenceStation_g_tc_members[2]._annotations._defaultValue._u.float_value = 0.0f;
                ReferenceStation_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
                ReferenceStation_g_tc_members[2]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
                ReferenceStation_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
                ReferenceStation_g_tc_members[2]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

                ReferenceStation_g_tc._data._sampleAccessInfo = sample_access_info();
                ReferenceStation_g_tc._data._typePlugin = type_plugin_info();    

                return &ReferenceStation_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::GNSS::ReferenceStation *sample;

                static RTIXCdrMemberAccessInfo ReferenceStation_g_memberAccessInfos[3] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ReferenceStation_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ReferenceStation_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::GNSS::ReferenceStation);
                if (sample == NULL) {
                    return NULL;
                }

                ReferenceStation_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Type() - (char *)sample);

                ReferenceStation_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->ID() - (char *)sample);

                ReferenceStation_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->AgeDGNSS() - (char *)sample);

                ReferenceStation_g_sampleAccessInfo.memberAccessInfos = 
                ReferenceStation_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::GNSS::ReferenceStation);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        ReferenceStation_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        ReferenceStation_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ReferenceStation_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ReferenceStation_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::GNSS::ReferenceStation >;

                ReferenceStation_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ReferenceStation_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ReferenceStation_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &ReferenceStation_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::GNSS::ReferenceStation >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::GNSS::ReferenceStation >::get())));
        }

        template<>
        struct native_type_code< ::GNSS::PositionData_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode PositionData_t_g_tc_ReferenceStation_sequence;

                static DDS_TypeCode_Member PositionData_t_g_tc_members[15]=
                {

                    {
                        (char *)"NAME",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"SID",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"PositionDate",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"PositionTime",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Lat",/* Member name */
                        {
                            4,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Lon",/* Member name */
                        {
                            5,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Alt",/* Member name */
                        {
                            6,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"TypeOfSystem",/* Member name */
                        {
                            7,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Method",/* Member name */
                        {
                            8,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Integrity",/* Member name */
                        {
                            9,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"NumOfSVs",/* Member name */
                        {
                            10,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"HDOP",/* Member name */
                        {
                            11,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"PDOP",/* Member name */
                        {
                            12,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"GeoidalSeparation",/* Member name */
                        {
                            13,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"ReferenceStation",/* Member name */
                        {
                            14,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode PositionData_t_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"GNSS::PositionData_t", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        15, /* Number of members */
                        PositionData_t_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for PositionData_t*/

                if (is_initialized) {
                    return &PositionData_t_g_tc;
                }

                is_initialized = RTI_TRUE;

                PositionData_t_g_tc_ReferenceStation_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< ::GNSS::ReferenceStation, 10L > >((10L));

                PositionData_t_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                PositionData_t_g_tc_ReferenceStation_sequence._data._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::GNSS::ReferenceStation>::get().native();
                PositionData_t_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulonglong;
                PositionData_t_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                PositionData_t_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::Common::Date>::get().native();
                PositionData_t_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::Common::Time>::get().native();
                PositionData_t_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
                PositionData_t_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
                PositionData_t_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
                PositionData_t_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                PositionData_t_g_tc_members[8]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                PositionData_t_g_tc_members[9]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                PositionData_t_g_tc_members[10]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                PositionData_t_g_tc_members[11]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
                PositionData_t_g_tc_members[12]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
                PositionData_t_g_tc_members[13]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
                PositionData_t_g_tc_members[14]._representation._typeCode = (RTICdrTypeCode *)& PositionData_t_g_tc_ReferenceStation_sequence;

                /* Initialize the values for member annotations. */
                PositionData_t_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ULONGLONG;
                PositionData_t_g_tc_members[0]._annotations._defaultValue._u.ulong_long_value = 0ull;
                PositionData_t_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_ULONGLONG;
                PositionData_t_g_tc_members[0]._annotations._minValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MIN;
                PositionData_t_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_ULONGLONG;
                PositionData_t_g_tc_members[0]._annotations._maxValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MAX;
                PositionData_t_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                PositionData_t_g_tc_members[1]._annotations._defaultValue._u.octet_value = 0;
                PositionData_t_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                PositionData_t_g_tc_members[1]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                PositionData_t_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                PositionData_t_g_tc_members[1]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;
                PositionData_t_g_tc_members[4]._annotations._minValue._d = RTI_XCDR_TK_DOUBLE;
                PositionData_t_g_tc_members[4]._annotations._minValue._u.double_value = RTIXCdrDouble_MIN;
                PositionData_t_g_tc_members[4]._annotations._maxValue._d = RTI_XCDR_TK_DOUBLE;
                PositionData_t_g_tc_members[4]._annotations._maxValue._u.double_value = RTIXCdrDouble_MAX;
                PositionData_t_g_tc_members[5]._annotations._minValue._d = RTI_XCDR_TK_DOUBLE;
                PositionData_t_g_tc_members[5]._annotations._minValue._u.double_value = RTIXCdrDouble_MIN;
                PositionData_t_g_tc_members[5]._annotations._maxValue._d = RTI_XCDR_TK_DOUBLE;
                PositionData_t_g_tc_members[5]._annotations._maxValue._u.double_value = RTIXCdrDouble_MAX;
                PositionData_t_g_tc_members[6]._annotations._minValue._d = RTI_XCDR_TK_DOUBLE;
                PositionData_t_g_tc_members[6]._annotations._minValue._u.double_value = RTIXCdrDouble_MIN;
                PositionData_t_g_tc_members[6]._annotations._maxValue._d = RTI_XCDR_TK_DOUBLE;
                PositionData_t_g_tc_members[6]._annotations._maxValue._u.double_value = RTIXCdrDouble_MAX;
                PositionData_t_g_tc_members[7]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                PositionData_t_g_tc_members[7]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                PositionData_t_g_tc_members[7]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                PositionData_t_g_tc_members[7]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;
                PositionData_t_g_tc_members[8]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                PositionData_t_g_tc_members[8]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                PositionData_t_g_tc_members[8]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                PositionData_t_g_tc_members[8]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;
                PositionData_t_g_tc_members[9]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                PositionData_t_g_tc_members[9]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                PositionData_t_g_tc_members[9]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                PositionData_t_g_tc_members[9]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;
                PositionData_t_g_tc_members[10]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                PositionData_t_g_tc_members[10]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                PositionData_t_g_tc_members[10]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                PositionData_t_g_tc_members[10]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;
                PositionData_t_g_tc_members[11]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
                PositionData_t_g_tc_members[11]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
                PositionData_t_g_tc_members[11]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
                PositionData_t_g_tc_members[11]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;
                PositionData_t_g_tc_members[12]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
                PositionData_t_g_tc_members[12]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
                PositionData_t_g_tc_members[12]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
                PositionData_t_g_tc_members[12]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;
                PositionData_t_g_tc_members[13]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
                PositionData_t_g_tc_members[13]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
                PositionData_t_g_tc_members[13]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
                PositionData_t_g_tc_members[13]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

                PositionData_t_g_tc._data._sampleAccessInfo = sample_access_info();
                PositionData_t_g_tc._data._typePlugin = type_plugin_info();    

                return &PositionData_t_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::GNSS::PositionData_t *sample;

                static RTIXCdrMemberAccessInfo PositionData_t_g_memberAccessInfos[15] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo PositionData_t_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &PositionData_t_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::GNSS::PositionData_t);
                if (sample == NULL) {
                    return NULL;
                }

                PositionData_t_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->NAME() - (char *)sample);

                PositionData_t_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->SID() - (char *)sample);

                PositionData_t_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->PositionDate() - (char *)sample);

                PositionData_t_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->PositionTime() - (char *)sample);

                PositionData_t_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Lat() - (char *)sample);

                PositionData_t_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Lon() - (char *)sample);

                PositionData_t_g_memberAccessInfos[6].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Alt() - (char *)sample);

                PositionData_t_g_memberAccessInfos[7].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->TypeOfSystem() - (char *)sample);

                PositionData_t_g_memberAccessInfos[8].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Method() - (char *)sample);

                PositionData_t_g_memberAccessInfos[9].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Integrity() - (char *)sample);

                PositionData_t_g_memberAccessInfos[10].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->NumOfSVs() - (char *)sample);

                PositionData_t_g_memberAccessInfos[11].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->HDOP() - (char *)sample);

                PositionData_t_g_memberAccessInfos[12].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->PDOP() - (char *)sample);

                PositionData_t_g_memberAccessInfos[13].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->GeoidalSeparation() - (char *)sample);

                PositionData_t_g_memberAccessInfos[14].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->ReferenceStation() - (char *)sample);

                PositionData_t_g_sampleAccessInfo.memberAccessInfos = 
                PositionData_t_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::GNSS::PositionData_t);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        PositionData_t_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        PositionData_t_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                PositionData_t_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                PositionData_t_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::GNSS::PositionData_t >;

                PositionData_t_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &PositionData_t_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin PositionData_t_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &PositionData_t_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::GNSS::PositionData_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::GNSS::PositionData_t >::get())));
        }

        template<>
        struct native_type_code< ::Vehicle::Engine > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member Engine_g_tc_members[9]=
                {

                    {
                        (char *)"RPM",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Fuel_Consumption_Rate",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"EGT",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Engine_Coolant_Temperature",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Intake_Air_Temperature",/* Member name */
                        {
                            4,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Throttle_Position",/* Member name */
                        {
                            5,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Engine_Load",/* Member name */
                        {
                            6,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"MAF",/* Member name */
                        {
                            7,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Fuel_System_Pressure",/* Member name */
                        {
                            8,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode Engine_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Vehicle::Engine", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        9, /* Number of members */
                        Engine_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for Engine*/

                if (is_initialized) {
                    return &Engine_g_tc;
                }

                is_initialized = RTI_TRUE;

                Engine_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                Engine_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                Engine_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                Engine_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                Engine_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                Engine_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                Engine_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                Engine_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                Engine_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                Engine_g_tc_members[8]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;

                /* Initialize the values for member annotations. */
                Engine_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                Engine_g_tc_members[0]._annotations._defaultValue._u.ushort_value = 0;
                Engine_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                Engine_g_tc_members[0]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
                Engine_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                Engine_g_tc_members[0]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;
                Engine_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                Engine_g_tc_members[1]._annotations._defaultValue._u.ushort_value = 0;
                Engine_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                Engine_g_tc_members[1]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
                Engine_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                Engine_g_tc_members[1]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;
                Engine_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                Engine_g_tc_members[2]._annotations._defaultValue._u.ushort_value = 0;
                Engine_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                Engine_g_tc_members[2]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
                Engine_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                Engine_g_tc_members[2]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;
                Engine_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                Engine_g_tc_members[3]._annotations._defaultValue._u.ushort_value = 0;
                Engine_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                Engine_g_tc_members[3]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
                Engine_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                Engine_g_tc_members[3]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;
                Engine_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                Engine_g_tc_members[4]._annotations._defaultValue._u.ushort_value = 0;
                Engine_g_tc_members[4]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                Engine_g_tc_members[4]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
                Engine_g_tc_members[4]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                Engine_g_tc_members[4]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;
                Engine_g_tc_members[5]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                Engine_g_tc_members[5]._annotations._defaultValue._u.octet_value = 0;
                Engine_g_tc_members[5]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                Engine_g_tc_members[5]._annotations._minValue._u.octet_value = 0;
                Engine_g_tc_members[5]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                Engine_g_tc_members[5]._annotations._maxValue._u.octet_value = 100;
                Engine_g_tc_members[6]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                Engine_g_tc_members[6]._annotations._defaultValue._u.octet_value = 0;
                Engine_g_tc_members[6]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                Engine_g_tc_members[6]._annotations._minValue._u.octet_value = 0;
                Engine_g_tc_members[6]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                Engine_g_tc_members[6]._annotations._maxValue._u.octet_value = 100;
                Engine_g_tc_members[7]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                Engine_g_tc_members[7]._annotations._defaultValue._u.octet_value = 0;
                Engine_g_tc_members[7]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                Engine_g_tc_members[7]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                Engine_g_tc_members[7]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                Engine_g_tc_members[7]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;
                Engine_g_tc_members[8]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
                Engine_g_tc_members[8]._annotations._defaultValue._u.ulong_value = 0u;
                Engine_g_tc_members[8]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
                Engine_g_tc_members[8]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
                Engine_g_tc_members[8]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
                Engine_g_tc_members[8]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

                Engine_g_tc._data._sampleAccessInfo = sample_access_info();
                Engine_g_tc._data._typePlugin = type_plugin_info();    

                return &Engine_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::Vehicle::Engine *sample;

                static RTIXCdrMemberAccessInfo Engine_g_memberAccessInfos[9] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo Engine_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &Engine_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::Vehicle::Engine);
                if (sample == NULL) {
                    return NULL;
                }

                Engine_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->RPM() - (char *)sample);

                Engine_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Fuel_Consumption_Rate() - (char *)sample);

                Engine_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->EGT() - (char *)sample);

                Engine_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Engine_Coolant_Temperature() - (char *)sample);

                Engine_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Intake_Air_Temperature() - (char *)sample);

                Engine_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Throttle_Position() - (char *)sample);

                Engine_g_memberAccessInfos[6].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Engine_Load() - (char *)sample);

                Engine_g_memberAccessInfos[7].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->MAF() - (char *)sample);

                Engine_g_memberAccessInfos[8].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Fuel_System_Pressure() - (char *)sample);

                Engine_g_sampleAccessInfo.memberAccessInfos = 
                Engine_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::Vehicle::Engine);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        Engine_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        Engine_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                Engine_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                Engine_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::Vehicle::Engine >;

                Engine_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &Engine_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin Engine_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &Engine_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::Vehicle::Engine >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::Vehicle::Engine >::get())));
        }

        const ::Vehicle::Wheel default_enumerator< ::Vehicle::Wheel>::value = ::Vehicle::Wheel::Front_Left;
        template<>
        struct native_type_code< ::Vehicle::Wheel > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member Wheel_g_tc_members[4]=
                {

                    {
                        (char *)"Front_Left",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Vehicle::Wheel::Front_Left), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Front_Right",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Vehicle::Wheel::Front_Right), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Rear_Left",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Vehicle::Wheel::Rear_Left), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Rear_Right",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Vehicle::Wheel::Rear_Right), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode Wheel_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Vehicle::Wheel", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        Wheel_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for Wheel*/

                if (is_initialized) {
                    return &Wheel_g_tc;
                }

                is_initialized = RTI_TRUE;

                Wheel_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                Wheel_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                Wheel_g_tc._data._annotations._defaultValue._u.long_value = 0;

                Wheel_g_tc._data._sampleAccessInfo = sample_access_info();
                Wheel_g_tc._data._typePlugin = type_plugin_info();    

                return &Wheel_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo Wheel_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo Wheel_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &Wheel_g_sampleAccessInfo;
                }

                Wheel_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                Wheel_g_sampleAccessInfo.memberAccessInfos = 
                Wheel_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::Vehicle::Wheel);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        Wheel_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        Wheel_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                Wheel_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                Wheel_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::Vehicle::Wheel >;

                Wheel_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &Wheel_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin Wheel_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &Wheel_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::EnumType& dynamic_type< ::Vehicle::Wheel >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::Vehicle::Wheel >::get())));
        }

        template<>
        struct native_type_code< ::Vehicle::Wheel_Speed > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member Wheel_Speed_g_tc_members[2]=
                {

                    {
                        (char *)"Wheel",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Speed",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode Wheel_Speed_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Vehicle::Wheel_Speed", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        Wheel_Speed_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for Wheel_Speed*/

                if (is_initialized) {
                    return &Wheel_Speed_g_tc;
                }

                is_initialized = RTI_TRUE;

                Wheel_Speed_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                Wheel_Speed_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::Vehicle::Wheel>::get().native();
                Wheel_Speed_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;

                /* Initialize the values for member annotations. */
                Wheel_Speed_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                Wheel_Speed_g_tc_members[0]._annotations._defaultValue._u.enumerated_value = 0;
                Wheel_Speed_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                Wheel_Speed_g_tc_members[1]._annotations._defaultValue._u.ushort_value = 0;
                Wheel_Speed_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                Wheel_Speed_g_tc_members[1]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
                Wheel_Speed_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                Wheel_Speed_g_tc_members[1]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;

                Wheel_Speed_g_tc._data._sampleAccessInfo = sample_access_info();
                Wheel_Speed_g_tc._data._typePlugin = type_plugin_info();    

                return &Wheel_Speed_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::Vehicle::Wheel_Speed *sample;

                static RTIXCdrMemberAccessInfo Wheel_Speed_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo Wheel_Speed_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &Wheel_Speed_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::Vehicle::Wheel_Speed);
                if (sample == NULL) {
                    return NULL;
                }

                Wheel_Speed_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Wheel() - (char *)sample);

                Wheel_Speed_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Speed() - (char *)sample);

                Wheel_Speed_g_sampleAccessInfo.memberAccessInfos = 
                Wheel_Speed_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::Vehicle::Wheel_Speed);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        Wheel_Speed_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        Wheel_Speed_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                Wheel_Speed_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                Wheel_Speed_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::Vehicle::Wheel_Speed >;

                Wheel_Speed_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &Wheel_Speed_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin Wheel_Speed_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &Wheel_Speed_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::Vehicle::Wheel_Speed >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::Vehicle::Wheel_Speed >::get())));
        }

        template<>
        struct native_type_code< ::Vehicle::Dynamics > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode Dynamics_g_tc_Wheel_Speed_sequence;

                static DDS_TypeCode_Member Dynamics_g_tc_members[4]=
                {

                    {
                        (char *)"Speed",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Wheel_Speed",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Acceleration",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Steering_Angle",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode Dynamics_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Vehicle::Dynamics", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        Dynamics_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for Dynamics*/

                if (is_initialized) {
                    return &Dynamics_g_tc;
                }

                is_initialized = RTI_TRUE;

                Dynamics_g_tc_Wheel_Speed_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< ::Vehicle::Wheel_Speed, 4L > >((4L));

                Dynamics_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                Dynamics_g_tc_Wheel_Speed_sequence._data._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::Vehicle::Wheel_Speed>::get().native();
                Dynamics_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                Dynamics_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)& Dynamics_g_tc_Wheel_Speed_sequence;
                Dynamics_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                Dynamics_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;

                /* Initialize the values for member annotations. */
                Dynamics_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                Dynamics_g_tc_members[0]._annotations._defaultValue._u.ushort_value = 0;
                Dynamics_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                Dynamics_g_tc_members[0]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
                Dynamics_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                Dynamics_g_tc_members[0]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;
                Dynamics_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                Dynamics_g_tc_members[2]._annotations._defaultValue._u.octet_value = 0;
                Dynamics_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                Dynamics_g_tc_members[2]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                Dynamics_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                Dynamics_g_tc_members[2]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;
                Dynamics_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                Dynamics_g_tc_members[3]._annotations._defaultValue._u.ushort_value = 0;
                Dynamics_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                Dynamics_g_tc_members[3]._annotations._minValue._u.ushort_value = 0U;
                Dynamics_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                Dynamics_g_tc_members[3]._annotations._maxValue._u.ushort_value = 360U;

                Dynamics_g_tc._data._sampleAccessInfo = sample_access_info();
                Dynamics_g_tc._data._typePlugin = type_plugin_info();    

                return &Dynamics_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::Vehicle::Dynamics *sample;

                static RTIXCdrMemberAccessInfo Dynamics_g_memberAccessInfos[4] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo Dynamics_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &Dynamics_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::Vehicle::Dynamics);
                if (sample == NULL) {
                    return NULL;
                }

                Dynamics_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Speed() - (char *)sample);

                Dynamics_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Wheel_Speed() - (char *)sample);

                Dynamics_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Acceleration() - (char *)sample);

                Dynamics_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Steering_Angle() - (char *)sample);

                Dynamics_g_sampleAccessInfo.memberAccessInfos = 
                Dynamics_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::Vehicle::Dynamics);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        Dynamics_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        Dynamics_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                Dynamics_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                Dynamics_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::Vehicle::Dynamics >;

                Dynamics_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &Dynamics_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin Dynamics_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &Dynamics_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::Vehicle::Dynamics >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::Vehicle::Dynamics >::get())));
        }

        template<>
        struct native_type_code< ::Vehicle::VehicleData_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member VehicleData_t_g_tc_members[3]=
                {

                    {
                        (char *)"ID",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Engine",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"Dynamics",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode VehicleData_t_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Vehicle::VehicleData_t", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        VehicleData_t_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for VehicleData_t*/

                if (is_initialized) {
                    return &VehicleData_t_g_tc;
                }

                is_initialized = RTI_TRUE;

                VehicleData_t_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                VehicleData_t_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
                VehicleData_t_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::Vehicle::Engine>::get().native();
                VehicleData_t_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::Vehicle::Dynamics>::get().native();

                /* Initialize the values for member annotations. */
                VehicleData_t_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
                VehicleData_t_g_tc_members[0]._annotations._defaultValue._u.ulong_value = 0u;
                VehicleData_t_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
                VehicleData_t_g_tc_members[0]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
                VehicleData_t_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
                VehicleData_t_g_tc_members[0]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

                VehicleData_t_g_tc._data._sampleAccessInfo = sample_access_info();
                VehicleData_t_g_tc._data._typePlugin = type_plugin_info();    

                return &VehicleData_t_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::Vehicle::VehicleData_t *sample;

                static RTIXCdrMemberAccessInfo VehicleData_t_g_memberAccessInfos[3] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo VehicleData_t_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &VehicleData_t_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::Vehicle::VehicleData_t);
                if (sample == NULL) {
                    return NULL;
                }

                VehicleData_t_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->ID() - (char *)sample);

                VehicleData_t_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Engine() - (char *)sample);

                VehicleData_t_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->Dynamics() - (char *)sample);

                VehicleData_t_g_sampleAccessInfo.memberAccessInfos = 
                VehicleData_t_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::Vehicle::VehicleData_t);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        VehicleData_t_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        VehicleData_t_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                VehicleData_t_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                VehicleData_t_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::Vehicle::VehicleData_t >;

                VehicleData_t_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &VehicleData_t_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin VehicleData_t_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &VehicleData_t_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::Vehicle::VehicleData_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::Vehicle::VehicleData_t >::get())));
        }

        const ::Diagnostics::DiagnosticType_e default_enumerator< ::Diagnostics::DiagnosticType_e>::value = ::Diagnostics::DiagnosticType_e::info;
        template<>
        struct native_type_code< ::Diagnostics::DiagnosticType_e > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member DiagnosticType_e_g_tc_members[4]=
                {

                    {
                        (char *)"info",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Diagnostics::DiagnosticType_e::info), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"warning",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Diagnostics::DiagnosticType_e::warning), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"error_recoverable",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Diagnostics::DiagnosticType_e::error_recoverable), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"error_fatal",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Diagnostics::DiagnosticType_e::error_fatal), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode DiagnosticType_e_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Diagnostics::DiagnosticType_e", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        DiagnosticType_e_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for DiagnosticType_e*/

                if (is_initialized) {
                    return &DiagnosticType_e_g_tc;
                }

                is_initialized = RTI_TRUE;

                DiagnosticType_e_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                DiagnosticType_e_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                DiagnosticType_e_g_tc._data._annotations._defaultValue._u.long_value = 0;

                DiagnosticType_e_g_tc._data._sampleAccessInfo = sample_access_info();
                DiagnosticType_e_g_tc._data._typePlugin = type_plugin_info();    

                return &DiagnosticType_e_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo DiagnosticType_e_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo DiagnosticType_e_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &DiagnosticType_e_g_sampleAccessInfo;
                }

                DiagnosticType_e_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                DiagnosticType_e_g_sampleAccessInfo.memberAccessInfos = 
                DiagnosticType_e_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::Diagnostics::DiagnosticType_e);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        DiagnosticType_e_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        DiagnosticType_e_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                DiagnosticType_e_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                DiagnosticType_e_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::Diagnostics::DiagnosticType_e >;

                DiagnosticType_e_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &DiagnosticType_e_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin DiagnosticType_e_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &DiagnosticType_e_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::EnumType& dynamic_type< ::Diagnostics::DiagnosticType_e >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::Diagnostics::DiagnosticType_e >::get())));
        }

        const ::Diagnostics::DiagnosticCode_e default_enumerator< ::Diagnostics::DiagnosticCode_e>::value = ::Diagnostics::DiagnosticCode_e::no_diagnostic_code;
        template<>
        struct native_type_code< ::Diagnostics::DiagnosticCode_e > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member DiagnosticCode_e_g_tc_members[3]=
                {

                    {
                        (char *)"no_diagnostic_code",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Diagnostics::DiagnosticCode_e::no_diagnostic_code), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"unit_mismatch",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Diagnostics::DiagnosticCode_e::unit_mismatch), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"handling_group_mismatch",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(::Diagnostics::DiagnosticCode_e::handling_group_mismatch), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode DiagnosticCode_e_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Diagnostics::DiagnosticCode_e", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        DiagnosticCode_e_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for DiagnosticCode_e*/

                if (is_initialized) {
                    return &DiagnosticCode_e_g_tc;
                }

                is_initialized = RTI_TRUE;

                DiagnosticCode_e_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                DiagnosticCode_e_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                DiagnosticCode_e_g_tc._data._annotations._defaultValue._u.long_value = 0;

                DiagnosticCode_e_g_tc._data._sampleAccessInfo = sample_access_info();
                DiagnosticCode_e_g_tc._data._typePlugin = type_plugin_info();    

                return &DiagnosticCode_e_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo DiagnosticCode_e_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo DiagnosticCode_e_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &DiagnosticCode_e_g_sampleAccessInfo;
                }

                DiagnosticCode_e_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                DiagnosticCode_e_g_sampleAccessInfo.memberAccessInfos = 
                DiagnosticCode_e_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::Diagnostics::DiagnosticCode_e);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        DiagnosticCode_e_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        DiagnosticCode_e_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                DiagnosticCode_e_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                DiagnosticCode_e_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::Diagnostics::DiagnosticCode_e >;

                DiagnosticCode_e_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &DiagnosticCode_e_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin DiagnosticCode_e_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &DiagnosticCode_e_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::EnumType& dynamic_type< ::Diagnostics::DiagnosticCode_e >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::Diagnostics::DiagnosticCode_e >::get())));
        }

        template<>
        struct native_type_code< ::Diagnostics::Diagnostic_t > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode Diagnostic_t_g_tc_message_string;

                static DDS_TypeCode_Member Diagnostic_t_g_tc_members[4]=
                {

                    {
                        (char *)"element_ref",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"diagnostic_code",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"diagnostic_type",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"message",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode Diagnostic_t_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Diagnostics::Diagnostic_t", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        Diagnostic_t_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for Diagnostic_t*/

                if (is_initialized) {
                    return &Diagnostic_t_g_tc;
                }

                is_initialized = RTI_TRUE;

                Diagnostic_t_g_tc_message_string = initialize_string_typecode((100L));

                Diagnostic_t_g_tc._data._annotations._allowedDataRepresentationMask = 4;

                Diagnostic_t_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::DeviceInformation::ElementReference_t>::get().native();
                Diagnostic_t_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::Diagnostics::DiagnosticCode_e>::get().native();
                Diagnostic_t_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< ::Diagnostics::DiagnosticType_e>::get().native();
                Diagnostic_t_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&Diagnostic_t_g_tc_message_string;

                /* Initialize the values for member annotations. */
                Diagnostic_t_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                Diagnostic_t_g_tc_members[1]._annotations._defaultValue._u.enumerated_value = 0;
                Diagnostic_t_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                Diagnostic_t_g_tc_members[2]._annotations._defaultValue._u.enumerated_value = 0;
                Diagnostic_t_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                Diagnostic_t_g_tc_members[3]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                Diagnostic_t_g_tc._data._sampleAccessInfo = sample_access_info();
                Diagnostic_t_g_tc._data._typePlugin = type_plugin_info();    

                return &Diagnostic_t_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::Diagnostics::Diagnostic_t *sample;

                static RTIXCdrMemberAccessInfo Diagnostic_t_g_memberAccessInfos[4] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo Diagnostic_t_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &Diagnostic_t_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::Diagnostics::Diagnostic_t);
                if (sample == NULL) {
                    return NULL;
                }

                Diagnostic_t_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->element_ref() - (char *)sample);

                Diagnostic_t_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->diagnostic_code() - (char *)sample);

                Diagnostic_t_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->diagnostic_type() - (char *)sample);

                Diagnostic_t_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->message() - (char *)sample);

                Diagnostic_t_g_sampleAccessInfo.memberAccessInfos = 
                Diagnostic_t_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::Diagnostics::Diagnostic_t);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        Diagnostic_t_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        Diagnostic_t_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                Diagnostic_t_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                Diagnostic_t_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::Diagnostics::Diagnostic_t >;

                Diagnostic_t_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &Diagnostic_t_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin Diagnostic_t_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &Diagnostic_t_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::Diagnostics::Diagnostic_t >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::Diagnostics::Diagnostic_t >::get())));
        }
    }
}

namespace dds { 
    namespace topic {
        void topic_type_support< ::Common::Time >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::Common::TimePlugin_new,
                ::Common::TimePlugin_delete);
        }

        std::vector<char>& topic_type_support< ::Common::Time >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::Common::Time& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = TimePlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = TimePlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::Common::Time >::from_cdr_buffer(::Common::Time& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = TimePlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::Common::Time from cdr buffer");
        }

        void topic_type_support< ::Common::Time >::reset_sample(::Common::Time& sample) 
        {
            sample.Hours_24(0);
            sample.Minutes(0);
            sample.Seconds(0.0);
        }

        void topic_type_support< ::Common::Time >::allocate_sample(::Common::Time& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }
        void topic_type_support< ::Common::OnOff_t >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::Common::OnOff_tPlugin_new,
                ::Common::OnOff_tPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::Common::OnOff_t >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::Common::OnOff_t& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = OnOff_tPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = OnOff_tPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::Common::OnOff_t >::from_cdr_buffer(::Common::OnOff_t& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = OnOff_tPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::Common::OnOff_t from cdr buffer");
        }

        void topic_type_support< ::Common::OnOff_t >::reset_sample(::Common::OnOff_t& sample) 
        {
            sample.on(0);
        }

        void topic_type_support< ::Common::OnOff_t >::allocate_sample(::Common::OnOff_t& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }
        void topic_type_support< ::Common::Unit_t >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::Common::Unit_tPlugin_new,
                ::Common::Unit_tPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::Common::Unit_t >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::Common::Unit_t& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = Unit_tPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = Unit_tPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::Common::Unit_t >::from_cdr_buffer(::Common::Unit_t& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = Unit_tPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::Common::Unit_t from cdr buffer");
        }

        void topic_type_support< ::Common::Unit_t >::reset_sample(::Common::Unit_t& sample) 
        {
            sample.nominator(Common::Unit_e::m);
            sample.denominator(Common::Unit_e::m);
        }

        void topic_type_support< ::Common::Unit_t >::allocate_sample(::Common::Unit_t& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.nominator(),  -1, -1);
            ::rti::topic::allocate_sample(sample.denominator(),  -1, -1);
        }
        void topic_type_support< ::Common::Date >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::Common::DatePlugin_new,
                ::Common::DatePlugin_delete);
        }

        std::vector<char>& topic_type_support< ::Common::Date >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::Common::Date& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = DatePlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = DatePlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::Common::Date >::from_cdr_buffer(::Common::Date& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = DatePlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::Common::Date from cdr buffer");
        }

        void topic_type_support< ::Common::Date >::reset_sample(::Common::Date& sample) 
        {
            sample.Year(2000);
            sample.Month(1);
            sample.Day(1);
        }

        void topic_type_support< ::Common::Date >::allocate_sample(::Common::Date& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }
        void topic_type_support< ::DeviceInformation::ElementReference_t >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::DeviceInformation::ElementReference_tPlugin_new,
                ::DeviceInformation::ElementReference_tPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::DeviceInformation::ElementReference_t >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::DeviceInformation::ElementReference_t& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = ElementReference_tPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = ElementReference_tPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::DeviceInformation::ElementReference_t >::from_cdr_buffer(::DeviceInformation::ElementReference_t& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = ElementReference_tPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::DeviceInformation::ElementReference_t from cdr buffer");
        }

        void topic_type_support< ::DeviceInformation::ElementReference_t >::reset_sample(::DeviceInformation::ElementReference_t& sample) 
        {
            sample.name(0ull);
            sample.element_id(0ull);
        }

        void topic_type_support< ::DeviceInformation::ElementReference_t >::allocate_sample(::DeviceInformation::ElementReference_t& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }
        void topic_type_support< ::DeviceInformation::Device_t >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::DeviceInformation::Device_tPlugin_new,
                ::DeviceInformation::Device_tPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::DeviceInformation::Device_t >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::DeviceInformation::Device_t& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = Device_tPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = Device_tPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::DeviceInformation::Device_t >::from_cdr_buffer(::DeviceInformation::Device_t& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = Device_tPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::DeviceInformation::Device_t from cdr buffer");
        }

        void topic_type_support< ::DeviceInformation::Device_t >::reset_sample(::DeviceInformation::Device_t& sample) 
        {
            sample.id("");
            sample.designator("");
            sample.software_version("");
            sample.name("");
            sample.serial_number("");
            sample.structure_label("");
            sample.localization_label("");
        }

        void topic_type_support< ::DeviceInformation::Device_t >::allocate_sample(::DeviceInformation::Device_t& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.id(),  -1, 100L);
            ::rti::topic::allocate_sample(sample.designator(),  -1, 100L);
            ::rti::topic::allocate_sample(sample.software_version(),  -1, 100L);
            ::rti::topic::allocate_sample(sample.name(),  -1, 100L);
            ::rti::topic::allocate_sample(sample.serial_number(),  -1, 100L);
            ::rti::topic::allocate_sample(sample.structure_label(),  -1, 100L);
            ::rti::topic::allocate_sample(sample.localization_label(),  -1, 100L);
        }
        void topic_type_support< ::DeviceInformation::DeviceElement_t >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::DeviceInformation::DeviceElement_tPlugin_new,
                ::DeviceInformation::DeviceElement_tPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::DeviceInformation::DeviceElement_t >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::DeviceInformation::DeviceElement_t& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = DeviceElement_tPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = DeviceElement_tPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::DeviceInformation::DeviceElement_t >::from_cdr_buffer(::DeviceInformation::DeviceElement_t& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = DeviceElement_tPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::DeviceInformation::DeviceElement_t from cdr buffer");
        }

        void topic_type_support< ::DeviceInformation::DeviceElement_t >::reset_sample(::DeviceInformation::DeviceElement_t& sample) 
        {
            sample.name("");
            ::rti::topic::reset_sample(sample.element_ref());
            ::rti::topic::reset_sample(sample.parent_ref());
        }

        void topic_type_support< ::DeviceInformation::DeviceElement_t >::allocate_sample(::DeviceInformation::DeviceElement_t& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.name(),  -1, 100L);
            ::rti::topic::allocate_sample(sample.element_ref(),  -1, -1);
            ::rti::topic::allocate_sample(sample.parent_ref(),  -1, -1);
        }
        void topic_type_support< ::DeviceInformation::ServiceDiscovery_t >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::DeviceInformation::ServiceDiscovery_tPlugin_new,
                ::DeviceInformation::ServiceDiscovery_tPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::DeviceInformation::ServiceDiscovery_t >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::DeviceInformation::ServiceDiscovery_t& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = ServiceDiscovery_tPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = ServiceDiscovery_tPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::DeviceInformation::ServiceDiscovery_t >::from_cdr_buffer(::DeviceInformation::ServiceDiscovery_t& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = ServiceDiscovery_tPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::DeviceInformation::ServiceDiscovery_t from cdr buffer");
        }

        void topic_type_support< ::DeviceInformation::ServiceDiscovery_t >::reset_sample(::DeviceInformation::ServiceDiscovery_t& sample) 
        {
            sample.NAME(0ull);
            ::rti::topic::reset_sample(sample.TC_client_version());
            ::rti::topic::reset_sample(sample.TC_server_version());
            ::rti::topic::reset_sample(sample.VT_client_version());
            ::rti::topic::reset_sample(sample.VT_server_version());
        }

        void topic_type_support< ::DeviceInformation::ServiceDiscovery_t >::allocate_sample(::DeviceInformation::ServiceDiscovery_t& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }
        void topic_type_support< ::DeviceInformation::ServiceDiscovery_extended_t >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::DeviceInformation::ServiceDiscovery_extended_tPlugin_new,
                ::DeviceInformation::ServiceDiscovery_extended_tPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::DeviceInformation::ServiceDiscovery_extended_t >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::DeviceInformation::ServiceDiscovery_extended_t& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = ServiceDiscovery_extended_tPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = ServiceDiscovery_extended_tPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::DeviceInformation::ServiceDiscovery_extended_t >::from_cdr_buffer(::DeviceInformation::ServiceDiscovery_extended_t& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = ServiceDiscovery_extended_tPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::DeviceInformation::ServiceDiscovery_extended_t from cdr buffer");
        }

        void topic_type_support< ::DeviceInformation::ServiceDiscovery_extended_t >::reset_sample(::DeviceInformation::ServiceDiscovery_extended_t& sample) 
        {
            // Initialize base
            topic_type_support< ::DeviceInformation::ServiceDiscovery_t >::reset_sample(sample);

            ::rti::topic::reset_sample(sample.hsi_conformity_certificate());
        }

        void topic_type_support< ::DeviceInformation::ServiceDiscovery_extended_t >::allocate_sample(::DeviceInformation::ServiceDiscovery_extended_t& sample, int, int) 
        {
            // Initialize base
            topic_type_support< ::DeviceInformation::ServiceDiscovery_t >::allocate_sample(sample, -1, -1);

        }
        void topic_type_support< ::Actuation::ControlHandlingCapabilities_t >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::Actuation::ControlHandlingCapabilities_tPlugin_new,
                ::Actuation::ControlHandlingCapabilities_tPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::Actuation::ControlHandlingCapabilities_t >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::Actuation::ControlHandlingCapabilities_t& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = ControlHandlingCapabilities_tPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = ControlHandlingCapabilities_tPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::Actuation::ControlHandlingCapabilities_t >::from_cdr_buffer(::Actuation::ControlHandlingCapabilities_t& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = ControlHandlingCapabilities_tPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::Actuation::ControlHandlingCapabilities_t from cdr buffer");
        }

        void topic_type_support< ::Actuation::ControlHandlingCapabilities_t >::reset_sample(::Actuation::ControlHandlingCapabilities_t& sample) 
        {
            ::rti::topic::reset_sample(sample.element_ref());
            sample.handling_group(Actuation::HandlingGroup_e::tillage_depth);
            sample.option_nr(0);
            ::rti::topic::reset_sample(sample.unit());
        }

        void topic_type_support< ::Actuation::ControlHandlingCapabilities_t >::allocate_sample(::Actuation::ControlHandlingCapabilities_t& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.element_ref(),  -1, -1);
            ::rti::topic::allocate_sample(sample.handling_group(),  -1, -1);
            ::rti::topic::allocate_sample(sample.unit(),  -1, -1);
        }
        void topic_type_support< ::Actuation::ControlHandlingValues_t >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::Actuation::ControlHandlingValues_tPlugin_new,
                ::Actuation::ControlHandlingValues_tPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::Actuation::ControlHandlingValues_t >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::Actuation::ControlHandlingValues_t& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = ControlHandlingValues_tPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = ControlHandlingValues_tPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::Actuation::ControlHandlingValues_t >::from_cdr_buffer(::Actuation::ControlHandlingValues_t& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = ControlHandlingValues_tPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::Actuation::ControlHandlingValues_t from cdr buffer");
        }

        void topic_type_support< ::Actuation::ControlHandlingValues_t >::reset_sample(::Actuation::ControlHandlingValues_t& sample) 
        {
            ::rti::topic::reset_sample(sample.element_ref());
            sample.handling_feature(Actuation::HandlingFeature_e::minimum);
            sample.handling_group(Actuation::HandlingGroup_e::tillage_depth);
            sample.value(0.0);
            ::rti::topic::reset_sample(sample.unit());
        }

        void topic_type_support< ::Actuation::ControlHandlingValues_t >::allocate_sample(::Actuation::ControlHandlingValues_t& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.element_ref(),  -1, -1);
            ::rti::topic::allocate_sample(sample.handling_feature(),  -1, -1);
            ::rti::topic::allocate_sample(sample.handling_group(),  -1, -1);
            ::rti::topic::allocate_sample(sample.unit(),  -1, -1);
        }
        void topic_type_support< ::GNSS::ReferenceStation >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::GNSS::ReferenceStationPlugin_new,
                ::GNSS::ReferenceStationPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::GNSS::ReferenceStation >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::GNSS::ReferenceStation& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = ReferenceStationPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = ReferenceStationPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::GNSS::ReferenceStation >::from_cdr_buffer(::GNSS::ReferenceStation& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = ReferenceStationPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::GNSS::ReferenceStation from cdr buffer");
        }

        void topic_type_support< ::GNSS::ReferenceStation >::reset_sample(::GNSS::ReferenceStation& sample) 
        {
            sample.Type(0);
            sample.ID(0);
            sample.AgeDGNSS(0.0f);
        }

        void topic_type_support< ::GNSS::ReferenceStation >::allocate_sample(::GNSS::ReferenceStation& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }
        void topic_type_support< ::GNSS::PositionData_t >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::GNSS::PositionData_tPlugin_new,
                ::GNSS::PositionData_tPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::GNSS::PositionData_t >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::GNSS::PositionData_t& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = PositionData_tPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = PositionData_tPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::GNSS::PositionData_t >::from_cdr_buffer(::GNSS::PositionData_t& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = PositionData_tPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::GNSS::PositionData_t from cdr buffer");
        }

        void topic_type_support< ::GNSS::PositionData_t >::reset_sample(::GNSS::PositionData_t& sample) 
        {
            sample.NAME(0ull);
            sample.SID(0);
            ::rti::topic::reset_sample(sample.PositionDate());
            ::rti::topic::reset_sample(sample.PositionTime());
            ::rti::topic::reset_sample(sample.Lat());
            ::rti::topic::reset_sample(sample.Lon());
            ::rti::topic::reset_sample(sample.Alt());
            ::rti::topic::reset_sample(sample.TypeOfSystem());
            ::rti::topic::reset_sample(sample.Method());
            ::rti::topic::reset_sample(sample.Integrity());
            ::rti::topic::reset_sample(sample.NumOfSVs());
            ::rti::topic::reset_sample(sample.HDOP());
            ::rti::topic::reset_sample(sample.PDOP());
            ::rti::topic::reset_sample(sample.GeoidalSeparation());
            ::rti::topic::reset_sample(sample.ReferenceStation());
        }

        void topic_type_support< ::GNSS::PositionData_t >::allocate_sample(::GNSS::PositionData_t& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }
        void topic_type_support< ::Vehicle::Engine >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::Vehicle::EnginePlugin_new,
                ::Vehicle::EnginePlugin_delete);
        }

        std::vector<char>& topic_type_support< ::Vehicle::Engine >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::Vehicle::Engine& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = EnginePlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = EnginePlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::Vehicle::Engine >::from_cdr_buffer(::Vehicle::Engine& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = EnginePlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::Vehicle::Engine from cdr buffer");
        }

        void topic_type_support< ::Vehicle::Engine >::reset_sample(::Vehicle::Engine& sample) 
        {
            sample.RPM(0);
            sample.Fuel_Consumption_Rate(0);
            sample.EGT(0);
            sample.Engine_Coolant_Temperature(0);
            sample.Intake_Air_Temperature(0);
            sample.Throttle_Position(0);
            sample.Engine_Load(0);
            sample.MAF(0);
            sample.Fuel_System_Pressure(0u);
        }

        void topic_type_support< ::Vehicle::Engine >::allocate_sample(::Vehicle::Engine& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }
        void topic_type_support< ::Vehicle::Wheel_Speed >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::Vehicle::Wheel_SpeedPlugin_new,
                ::Vehicle::Wheel_SpeedPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::Vehicle::Wheel_Speed >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::Vehicle::Wheel_Speed& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = Wheel_SpeedPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = Wheel_SpeedPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::Vehicle::Wheel_Speed >::from_cdr_buffer(::Vehicle::Wheel_Speed& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = Wheel_SpeedPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::Vehicle::Wheel_Speed from cdr buffer");
        }

        void topic_type_support< ::Vehicle::Wheel_Speed >::reset_sample(::Vehicle::Wheel_Speed& sample) 
        {
            sample.Wheel(Vehicle::Wheel::Front_Left);
            sample.Speed(0);
        }

        void topic_type_support< ::Vehicle::Wheel_Speed >::allocate_sample(::Vehicle::Wheel_Speed& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.Wheel(),  -1, -1);
        }
        void topic_type_support< ::Vehicle::Dynamics >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::Vehicle::DynamicsPlugin_new,
                ::Vehicle::DynamicsPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::Vehicle::Dynamics >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::Vehicle::Dynamics& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = DynamicsPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = DynamicsPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::Vehicle::Dynamics >::from_cdr_buffer(::Vehicle::Dynamics& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = DynamicsPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::Vehicle::Dynamics from cdr buffer");
        }

        void topic_type_support< ::Vehicle::Dynamics >::reset_sample(::Vehicle::Dynamics& sample) 
        {
            sample.Speed(0);
            ::rti::topic::reset_sample(sample.Wheel_Speed());
            sample.Acceleration(0);
            sample.Steering_Angle(0);
        }

        void topic_type_support< ::Vehicle::Dynamics >::allocate_sample(::Vehicle::Dynamics& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.Wheel_Speed(),  4L, -1);
        }
        void topic_type_support< ::Vehicle::VehicleData_t >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::Vehicle::VehicleData_tPlugin_new,
                ::Vehicle::VehicleData_tPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::Vehicle::VehicleData_t >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::Vehicle::VehicleData_t& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = VehicleData_tPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = VehicleData_tPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::Vehicle::VehicleData_t >::from_cdr_buffer(::Vehicle::VehicleData_t& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = VehicleData_tPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::Vehicle::VehicleData_t from cdr buffer");
        }

        void topic_type_support< ::Vehicle::VehicleData_t >::reset_sample(::Vehicle::VehicleData_t& sample) 
        {
            sample.ID(0u);
            ::rti::topic::reset_sample(sample.Engine());
            ::rti::topic::reset_sample(sample.Dynamics());
        }

        void topic_type_support< ::Vehicle::VehicleData_t >::allocate_sample(::Vehicle::VehicleData_t& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }
        void topic_type_support< ::Diagnostics::Diagnostic_t >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::Diagnostics::Diagnostic_tPlugin_new,
                ::Diagnostics::Diagnostic_tPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::Diagnostics::Diagnostic_t >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::Diagnostics::Diagnostic_t& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = Diagnostic_tPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = Diagnostic_tPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::Diagnostics::Diagnostic_t >::from_cdr_buffer(::Diagnostics::Diagnostic_t& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = Diagnostic_tPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::Diagnostics::Diagnostic_t from cdr buffer");
        }

        void topic_type_support< ::Diagnostics::Diagnostic_t >::reset_sample(::Diagnostics::Diagnostic_t& sample) 
        {
            ::rti::topic::reset_sample(sample.element_ref());
            sample.diagnostic_code(Diagnostics::DiagnosticCode_e::no_diagnostic_code);
            sample.diagnostic_type(Diagnostics::DiagnosticType_e::info);
            sample.message("");
        }

        void topic_type_support< ::Diagnostics::Diagnostic_t >::allocate_sample(::Diagnostics::Diagnostic_t& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.element_ref(),  -1, -1);
            ::rti::topic::allocate_sample(sample.diagnostic_code(),  -1, -1);
            ::rti::topic::allocate_sample(sample.diagnostic_type(),  -1, -1);
            ::rti::topic::allocate_sample(sample.message(),  -1, 100L);
        }
    }
}  

#endif // NDDS_STANDALONE_TYPE
