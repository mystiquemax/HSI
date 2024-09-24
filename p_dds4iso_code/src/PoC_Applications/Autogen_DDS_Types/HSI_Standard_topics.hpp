

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from HSI_Standard_topics.idl
using RTI Code Generator (rtiddsgen) version 4.2.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef HSI_Standard_topics_1006183393_hpp
#define HSI_Standard_topics_1006183393_hpp

#include <iosfwd>

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport __declspec(dllexport)
#endif

#include "dds/core/SafeEnumeration.hpp"
#include "dds/core/String.hpp"
#include "dds/core/array.hpp"
#include "dds/core/vector.hpp"
#include "dds/core/External.hpp"
#include "rti/core/LongDouble.hpp"
#include "rti/core/Pointer.hpp"
#include "rti/core/array.hpp"
#include "rti/topic/TopicTraits.hpp"

#include "omg/types/string_view.hpp"

#include "rti/core/BoundedSequence.hpp"
#include "dds/core/Optional.hpp"

#ifndef NDDS_STANDALONE_TYPE
#include "dds/domain/DomainParticipant.hpp"
#include "dds/topic/TopicTraits.hpp"
#include "dds/core/xtypes/DynamicType.hpp"
#include "dds/core/xtypes/StructType.hpp"
#include "dds/core/xtypes/UnionType.hpp"
#include "dds/core/xtypes/EnumType.hpp"
#include "dds/core/xtypes/AliasType.hpp"
#include "rti/util/StreamFlagSaver.hpp"
#include "rti/domain/PluginSupport.hpp"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

namespace Common {

    class NDDSUSERDllExport Time {
      public:

        Time();

        Time(uint8_t Hours_24_,uint8_t Minutes_,double Seconds_);

        uint8_t& Hours_24() noexcept {
            return m_Hours_24_;
        }

        const uint8_t& Hours_24() const noexcept {
            return m_Hours_24_;
        }

        void Hours_24(uint8_t value) {

            m_Hours_24_ = value;
        }

        uint8_t& Minutes() noexcept {
            return m_Minutes_;
        }

        const uint8_t& Minutes() const noexcept {
            return m_Minutes_;
        }

        void Minutes(uint8_t value) {

            m_Minutes_ = value;
        }

        double& Seconds() noexcept {
            return m_Seconds_;
        }

        const double& Seconds() const noexcept {
            return m_Seconds_;
        }

        void Seconds(double value) {

            m_Seconds_ = value;
        }

        bool operator == (const Time& other_) const;
        bool operator != (const Time& other_) const;

        void swap(Time& other_) noexcept ;

      private:

        uint8_t m_Hours_24_;
        uint8_t m_Minutes_;
        double m_Seconds_;

    };

    inline void swap(Time& a, Time& b)  noexcept 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Time& sample);

    class NDDSUSERDllExport OnOff_t {
      public:

        OnOff_t();

        explicit OnOff_t(bool on_);

        bool& on() noexcept {
            return m_on_;
        }

        const bool& on() const noexcept {
            return m_on_;
        }

        void on(bool value) {

            m_on_ = value;
        }

        bool operator == (const OnOff_t& other_) const;
        bool operator != (const OnOff_t& other_) const;

        void swap(OnOff_t& other_) noexcept ;

      private:

        bool m_on_;

    };

    inline void swap(OnOff_t& a, OnOff_t& b)  noexcept 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const OnOff_t& sample);

    enum class Unit_e {
        m, 
        m_2, 
        m_3, 
        kg, 
        s, 
        count, 
        none
    };

    NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const Unit_e& sample);

    class NDDSUSERDllExport Unit_t {
      public:

        Unit_t();

        Unit_t(const ::Common::Unit_e& nominator_,const ::Common::Unit_e& denominator_);

        ::Common::Unit_e& nominator() noexcept {
            return m_nominator_;
        }

        const ::Common::Unit_e& nominator() const noexcept {
            return m_nominator_;
        }

        void nominator(const ::Common::Unit_e& value) {

            m_nominator_ = value;
        }

        void nominator(::Common::Unit_e&& value) {
            m_nominator_ = std::move(value);
        }
        ::Common::Unit_e& denominator() noexcept {
            return m_denominator_;
        }

        const ::Common::Unit_e& denominator() const noexcept {
            return m_denominator_;
        }

        void denominator(const ::Common::Unit_e& value) {

            m_denominator_ = value;
        }

        void denominator(::Common::Unit_e&& value) {
            m_denominator_ = std::move(value);
        }
        bool operator == (const Unit_t& other_) const;
        bool operator != (const Unit_t& other_) const;

        void swap(Unit_t& other_) noexcept ;

      private:

        ::Common::Unit_e m_nominator_;
        ::Common::Unit_e m_denominator_;

    };

    inline void swap(Unit_t& a, Unit_t& b)  noexcept 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Unit_t& sample);

    class NDDSUSERDllExport Date {
      public:

        Date();

        Date(int16_t Year_,uint8_t Month_,uint8_t Day_);

        int16_t& Year() noexcept {
            return m_Year_;
        }

        const int16_t& Year() const noexcept {
            return m_Year_;
        }

        void Year(int16_t value) {

            m_Year_ = value;
        }

        uint8_t& Month() noexcept {
            return m_Month_;
        }

        const uint8_t& Month() const noexcept {
            return m_Month_;
        }

        void Month(uint8_t value) {

            m_Month_ = value;
        }

        uint8_t& Day() noexcept {
            return m_Day_;
        }

        const uint8_t& Day() const noexcept {
            return m_Day_;
        }

        void Day(uint8_t value) {

            m_Day_ = value;
        }

        bool operator == (const Date& other_) const;
        bool operator != (const Date& other_) const;

        void swap(Date& other_) noexcept ;

      private:

        int16_t m_Year_;
        uint8_t m_Month_;
        uint8_t m_Day_;

    };

    inline void swap(Date& a, Date& b)  noexcept 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Date& sample);

} // namespace Common  
namespace DeviceInformation {

    class NDDSUSERDllExport ElementReference_t {
      public:

        ElementReference_t();

        ElementReference_t(uint64_t name_,uint64_t element_id_);

        uint64_t& name() noexcept {
            return m_name_;
        }

        const uint64_t& name() const noexcept {
            return m_name_;
        }

        void name(uint64_t value) {

            m_name_ = value;
        }

        uint64_t& element_id() noexcept {
            return m_element_id_;
        }

        const uint64_t& element_id() const noexcept {
            return m_element_id_;
        }

        void element_id(uint64_t value) {

            m_element_id_ = value;
        }

        bool operator == (const ElementReference_t& other_) const;
        bool operator != (const ElementReference_t& other_) const;

        void swap(ElementReference_t& other_) noexcept ;

      private:

        uint64_t m_name_;
        uint64_t m_element_id_;

    };

    inline void swap(ElementReference_t& a, ElementReference_t& b)  noexcept 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ElementReference_t& sample);

    class NDDSUSERDllExport Device_t {
      public:

        Device_t();

        Device_t(const std::string& id_,const std::string& designator_,const std::string& software_version_,const std::string& name_,const std::string& serial_number_,const std::string& structure_label_,const std::string& localization_label_);

        std::string& id() noexcept {
            return m_id_;
        }

        const std::string& id() const noexcept {
            return m_id_;
        }

        void id(const std::string& value) {

            m_id_ = value;
        }

        void id(std::string&& value) {
            m_id_ = std::move(value);
        }
        std::string& designator() noexcept {
            return m_designator_;
        }

        const std::string& designator() const noexcept {
            return m_designator_;
        }

        void designator(const std::string& value) {

            m_designator_ = value;
        }

        void designator(std::string&& value) {
            m_designator_ = std::move(value);
        }
        std::string& software_version() noexcept {
            return m_software_version_;
        }

        const std::string& software_version() const noexcept {
            return m_software_version_;
        }

        void software_version(const std::string& value) {

            m_software_version_ = value;
        }

        void software_version(std::string&& value) {
            m_software_version_ = std::move(value);
        }
        std::string& name() noexcept {
            return m_name_;
        }

        const std::string& name() const noexcept {
            return m_name_;
        }

        void name(const std::string& value) {

            m_name_ = value;
        }

        void name(std::string&& value) {
            m_name_ = std::move(value);
        }
        std::string& serial_number() noexcept {
            return m_serial_number_;
        }

        const std::string& serial_number() const noexcept {
            return m_serial_number_;
        }

        void serial_number(const std::string& value) {

            m_serial_number_ = value;
        }

        void serial_number(std::string&& value) {
            m_serial_number_ = std::move(value);
        }
        std::string& structure_label() noexcept {
            return m_structure_label_;
        }

        const std::string& structure_label() const noexcept {
            return m_structure_label_;
        }

        void structure_label(const std::string& value) {

            m_structure_label_ = value;
        }

        void structure_label(std::string&& value) {
            m_structure_label_ = std::move(value);
        }
        std::string& localization_label() noexcept {
            return m_localization_label_;
        }

        const std::string& localization_label() const noexcept {
            return m_localization_label_;
        }

        void localization_label(const std::string& value) {

            m_localization_label_ = value;
        }

        void localization_label(std::string&& value) {
            m_localization_label_ = std::move(value);
        }
        bool operator == (const Device_t& other_) const;
        bool operator != (const Device_t& other_) const;

        void swap(Device_t& other_) noexcept ;

      private:

        std::string m_id_;
        std::string m_designator_;
        std::string m_software_version_;
        std::string m_name_;
        std::string m_serial_number_;
        std::string m_structure_label_;
        std::string m_localization_label_;

    };

    inline void swap(Device_t& a, Device_t& b)  noexcept 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Device_t& sample);

    class NDDSUSERDllExport DeviceElement_t {
      public:

        DeviceElement_t();

        DeviceElement_t(const std::string& name_,const ::DeviceInformation::ElementReference_t& element_ref_,const ::DeviceInformation::ElementReference_t& parent_ref_);

        std::string& name() noexcept {
            return m_name_;
        }

        const std::string& name() const noexcept {
            return m_name_;
        }

        void name(const std::string& value) {

            m_name_ = value;
        }

        void name(std::string&& value) {
            m_name_ = std::move(value);
        }
        ::DeviceInformation::ElementReference_t& element_ref() noexcept {
            return m_element_ref_;
        }

        const ::DeviceInformation::ElementReference_t& element_ref() const noexcept {
            return m_element_ref_;
        }

        void element_ref(const ::DeviceInformation::ElementReference_t& value) {

            m_element_ref_ = value;
        }

        void element_ref(::DeviceInformation::ElementReference_t&& value) {
            m_element_ref_ = std::move(value);
        }
        ::DeviceInformation::ElementReference_t& parent_ref() noexcept {
            return m_parent_ref_;
        }

        const ::DeviceInformation::ElementReference_t& parent_ref() const noexcept {
            return m_parent_ref_;
        }

        void parent_ref(const ::DeviceInformation::ElementReference_t& value) {

            m_parent_ref_ = value;
        }

        void parent_ref(::DeviceInformation::ElementReference_t&& value) {
            m_parent_ref_ = std::move(value);
        }
        bool operator == (const DeviceElement_t& other_) const;
        bool operator != (const DeviceElement_t& other_) const;

        void swap(DeviceElement_t& other_) noexcept ;

      private:

        std::string m_name_;
        ::DeviceInformation::ElementReference_t m_element_ref_;
        ::DeviceInformation::ElementReference_t m_parent_ref_;

    };

    inline void swap(DeviceElement_t& a, DeviceElement_t& b)  noexcept 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DeviceElement_t& sample);

    class NDDSUSERDllExport ServiceDiscovery_t {
      public:

        ServiceDiscovery_t();

        ServiceDiscovery_t(uint64_t NAME_,const ::dds::core::optional< uint8_t >& TC_client_version_,const ::dds::core::optional< uint8_t >& TC_server_version_,const ::dds::core::optional< uint8_t >& VT_client_version_,const ::dds::core::optional< uint8_t >& VT_server_version_);

        uint64_t& NAME() noexcept {
            return m_NAME_;
        }

        const uint64_t& NAME() const noexcept {
            return m_NAME_;
        }

        void NAME(uint64_t value) {

            m_NAME_ = value;
        }

        ::dds::core::optional< uint8_t >& TC_client_version() noexcept {
            return m_TC_client_version_;
        }

        const ::dds::core::optional< uint8_t >& TC_client_version() const noexcept {
            return m_TC_client_version_;
        }

        void TC_client_version(const ::dds::core::optional< uint8_t >& value) {

            m_TC_client_version_ = value;
        }

        void TC_client_version(::dds::core::optional< uint8_t >&& value) {
            m_TC_client_version_ = std::move(value);
        }
        ::dds::core::optional< uint8_t >& TC_server_version() noexcept {
            return m_TC_server_version_;
        }

        const ::dds::core::optional< uint8_t >& TC_server_version() const noexcept {
            return m_TC_server_version_;
        }

        void TC_server_version(const ::dds::core::optional< uint8_t >& value) {

            m_TC_server_version_ = value;
        }

        void TC_server_version(::dds::core::optional< uint8_t >&& value) {
            m_TC_server_version_ = std::move(value);
        }
        ::dds::core::optional< uint8_t >& VT_client_version() noexcept {
            return m_VT_client_version_;
        }

        const ::dds::core::optional< uint8_t >& VT_client_version() const noexcept {
            return m_VT_client_version_;
        }

        void VT_client_version(const ::dds::core::optional< uint8_t >& value) {

            m_VT_client_version_ = value;
        }

        void VT_client_version(::dds::core::optional< uint8_t >&& value) {
            m_VT_client_version_ = std::move(value);
        }
        ::dds::core::optional< uint8_t >& VT_server_version() noexcept {
            return m_VT_server_version_;
        }

        const ::dds::core::optional< uint8_t >& VT_server_version() const noexcept {
            return m_VT_server_version_;
        }

        void VT_server_version(const ::dds::core::optional< uint8_t >& value) {

            m_VT_server_version_ = value;
        }

        void VT_server_version(::dds::core::optional< uint8_t >&& value) {
            m_VT_server_version_ = std::move(value);
        }
        bool operator == (const ServiceDiscovery_t& other_) const;
        bool operator != (const ServiceDiscovery_t& other_) const;

        void swap(ServiceDiscovery_t& other_) noexcept ;

      private:

        uint64_t m_NAME_;
        ::dds::core::optional< uint8_t > m_TC_client_version_;
        ::dds::core::optional< uint8_t > m_TC_server_version_;
        ::dds::core::optional< uint8_t > m_VT_client_version_;
        ::dds::core::optional< uint8_t > m_VT_server_version_;

    };

    inline void swap(ServiceDiscovery_t& a, ServiceDiscovery_t& b)  noexcept 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ServiceDiscovery_t& sample);

    #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
    // On Windows, dll-export template instantiations of standard types used by
    // other dll-exported types
    template class NDDSUSERDllExport std::allocator< int8_t >;
    template class NDDSUSERDllExport std::vector< int8_t >;
    #endif
    class NDDSUSERDllExport ServiceDiscovery_extended_t
    : public ::DeviceInformation::ServiceDiscovery_t {
      public:

        ServiceDiscovery_extended_t();

        explicit ServiceDiscovery_extended_t(uint64_t NAME_,const ::dds::core::optional< uint8_t >& TC_client_version_,const ::dds::core::optional< uint8_t >& TC_server_version_,const ::dds::core::optional< uint8_t >& VT_client_version_,const ::dds::core::optional< uint8_t >& VT_server_version_,const ::dds::core::optional< ::rti::core::bounded_sequence< int8_t, 256L > >& hsi_conformity_certificate_);

        ::dds::core::optional< ::rti::core::bounded_sequence< int8_t, 256L > >& hsi_conformity_certificate() noexcept {
            return m_hsi_conformity_certificate_;
        }

        const ::dds::core::optional< ::rti::core::bounded_sequence< int8_t, 256L > >& hsi_conformity_certificate() const noexcept {
            return m_hsi_conformity_certificate_;
        }

        void hsi_conformity_certificate(const ::dds::core::optional< ::rti::core::bounded_sequence< int8_t, 256L > >& value) {

            m_hsi_conformity_certificate_ = value;
        }

        void hsi_conformity_certificate(::dds::core::optional< ::rti::core::bounded_sequence< int8_t, 256L > >&& value) {
            m_hsi_conformity_certificate_ = std::move(value);
        }
        bool operator == (const ServiceDiscovery_extended_t& other_) const;
        bool operator != (const ServiceDiscovery_extended_t& other_) const;

        void swap(ServiceDiscovery_extended_t& other_) noexcept ;

      private:

        ::dds::core::optional< ::rti::core::bounded_sequence< int8_t, 256L > > m_hsi_conformity_certificate_;

    };

    inline void swap(ServiceDiscovery_extended_t& a, ServiceDiscovery_extended_t& b)  noexcept 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ServiceDiscovery_extended_t& sample);

} // namespace DeviceInformation  
namespace Actuation {
    enum class HandlingFeature_e {
        minimum, 
        maximum, 
        actual, 
        setpoint, 
        iso_default
    };

    NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const HandlingFeature_e& sample);
    enum class HandlingGroup_e {
        tillage_depth, 
        seeding_depth, 
        application_rate, 
        working_height, 
        fill_level, 
        flow_rate
    };

    NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const HandlingGroup_e& sample);

    class NDDSUSERDllExport ControlHandlingCapabilities_t {
      public:

        ControlHandlingCapabilities_t();

        ControlHandlingCapabilities_t(const ::DeviceInformation::ElementReference_t& element_ref_,const ::Actuation::HandlingGroup_e& handling_group_,uint8_t option_nr_,const ::Common::Unit_t& unit_);

        ::DeviceInformation::ElementReference_t& element_ref() noexcept {
            return m_element_ref_;
        }

        const ::DeviceInformation::ElementReference_t& element_ref() const noexcept {
            return m_element_ref_;
        }

        void element_ref(const ::DeviceInformation::ElementReference_t& value) {

            m_element_ref_ = value;
        }

        void element_ref(::DeviceInformation::ElementReference_t&& value) {
            m_element_ref_ = std::move(value);
        }
        ::Actuation::HandlingGroup_e& handling_group() noexcept {
            return m_handling_group_;
        }

        const ::Actuation::HandlingGroup_e& handling_group() const noexcept {
            return m_handling_group_;
        }

        void handling_group(const ::Actuation::HandlingGroup_e& value) {

            m_handling_group_ = value;
        }

        void handling_group(::Actuation::HandlingGroup_e&& value) {
            m_handling_group_ = std::move(value);
        }
        uint8_t& option_nr() noexcept {
            return m_option_nr_;
        }

        const uint8_t& option_nr() const noexcept {
            return m_option_nr_;
        }

        void option_nr(uint8_t value) {

            m_option_nr_ = value;
        }

        ::Common::Unit_t& unit() noexcept {
            return m_unit_;
        }

        const ::Common::Unit_t& unit() const noexcept {
            return m_unit_;
        }

        void unit(const ::Common::Unit_t& value) {

            m_unit_ = value;
        }

        void unit(::Common::Unit_t&& value) {
            m_unit_ = std::move(value);
        }
        bool operator == (const ControlHandlingCapabilities_t& other_) const;
        bool operator != (const ControlHandlingCapabilities_t& other_) const;

        void swap(ControlHandlingCapabilities_t& other_) noexcept ;

      private:

        ::DeviceInformation::ElementReference_t m_element_ref_;
        ::Actuation::HandlingGroup_e m_handling_group_;
        uint8_t m_option_nr_;
        ::Common::Unit_t m_unit_;

    };

    inline void swap(ControlHandlingCapabilities_t& a, ControlHandlingCapabilities_t& b)  noexcept 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ControlHandlingCapabilities_t& sample);

    class NDDSUSERDllExport ControlHandlingValues_t {
      public:

        ControlHandlingValues_t();

        ControlHandlingValues_t(const ::DeviceInformation::ElementReference_t& element_ref_,const ::Actuation::HandlingFeature_e& handling_feature_,const ::Actuation::HandlingGroup_e& handling_group_,double value_,const ::Common::Unit_t& unit_);

        ::DeviceInformation::ElementReference_t& element_ref() noexcept {
            return m_element_ref_;
        }

        const ::DeviceInformation::ElementReference_t& element_ref() const noexcept {
            return m_element_ref_;
        }

        void element_ref(const ::DeviceInformation::ElementReference_t& value) {

            m_element_ref_ = value;
        }

        void element_ref(::DeviceInformation::ElementReference_t&& value) {
            m_element_ref_ = std::move(value);
        }
        ::Actuation::HandlingFeature_e& handling_feature() noexcept {
            return m_handling_feature_;
        }

        const ::Actuation::HandlingFeature_e& handling_feature() const noexcept {
            return m_handling_feature_;
        }

        void handling_feature(const ::Actuation::HandlingFeature_e& value) {

            m_handling_feature_ = value;
        }

        void handling_feature(::Actuation::HandlingFeature_e&& value) {
            m_handling_feature_ = std::move(value);
        }
        ::Actuation::HandlingGroup_e& handling_group() noexcept {
            return m_handling_group_;
        }

        const ::Actuation::HandlingGroup_e& handling_group() const noexcept {
            return m_handling_group_;
        }

        void handling_group(const ::Actuation::HandlingGroup_e& value) {

            m_handling_group_ = value;
        }

        void handling_group(::Actuation::HandlingGroup_e&& value) {
            m_handling_group_ = std::move(value);
        }
        double& value() noexcept {
            return m_value_;
        }

        const double& value() const noexcept {
            return m_value_;
        }

        void value(double value) {

            m_value_ = value;
        }

        ::Common::Unit_t& unit() noexcept {
            return m_unit_;
        }

        const ::Common::Unit_t& unit() const noexcept {
            return m_unit_;
        }

        void unit(const ::Common::Unit_t& value) {

            m_unit_ = value;
        }

        void unit(::Common::Unit_t&& value) {
            m_unit_ = std::move(value);
        }
        bool operator == (const ControlHandlingValues_t& other_) const;
        bool operator != (const ControlHandlingValues_t& other_) const;

        void swap(ControlHandlingValues_t& other_) noexcept ;

      private:

        ::DeviceInformation::ElementReference_t m_element_ref_;
        ::Actuation::HandlingFeature_e m_handling_feature_;
        ::Actuation::HandlingGroup_e m_handling_group_;
        double m_value_;
        ::Common::Unit_t m_unit_;

    };

    inline void swap(ControlHandlingValues_t& a, ControlHandlingValues_t& b)  noexcept 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ControlHandlingValues_t& sample);

} // namespace Actuation  
namespace GNSS {

    class NDDSUSERDllExport ReferenceStation {
      public:

        ReferenceStation();

        ReferenceStation(uint8_t Type_,uint16_t ID_,float AgeDGNSS_);

        uint8_t& Type() noexcept {
            return m_Type_;
        }

        const uint8_t& Type() const noexcept {
            return m_Type_;
        }

        void Type(uint8_t value) {

            m_Type_ = value;
        }

        uint16_t& ID() noexcept {
            return m_ID_;
        }

        const uint16_t& ID() const noexcept {
            return m_ID_;
        }

        void ID(uint16_t value) {

            m_ID_ = value;
        }

        float& AgeDGNSS() noexcept {
            return m_AgeDGNSS_;
        }

        const float& AgeDGNSS() const noexcept {
            return m_AgeDGNSS_;
        }

        void AgeDGNSS(float value) {

            m_AgeDGNSS_ = value;
        }

        bool operator == (const ReferenceStation& other_) const;
        bool operator != (const ReferenceStation& other_) const;

        void swap(ReferenceStation& other_) noexcept ;

      private:

        uint8_t m_Type_;
        uint16_t m_ID_;
        float m_AgeDGNSS_;

    };

    inline void swap(ReferenceStation& a, ReferenceStation& b)  noexcept 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ReferenceStation& sample);

    #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
    // On Windows, dll-export template instantiations of standard types used by
    // other dll-exported types
    template class NDDSUSERDllExport std::allocator< ::GNSS::ReferenceStation >;
    template class NDDSUSERDllExport std::vector< ::GNSS::ReferenceStation >;
    #endif
    class NDDSUSERDllExport PositionData_t {
      public:

        PositionData_t();

        PositionData_t(uint64_t NAME_,uint8_t SID_,const ::dds::core::optional< ::Common::Date >& PositionDate_,const ::dds::core::optional< ::Common::Time >& PositionTime_,const ::dds::core::optional< double >& Lat_,const ::dds::core::optional< double >& Lon_,const ::dds::core::optional< double >& Alt_,const ::dds::core::optional< uint8_t >& TypeOfSystem_,const ::dds::core::optional< uint8_t >& Method_,const ::dds::core::optional< uint8_t >& Integrity_,const ::dds::core::optional< uint8_t >& NumOfSVs_,const ::dds::core::optional< float >& HDOP_,const ::dds::core::optional< float >& PDOP_,const ::dds::core::optional< float >& GeoidalSeparation_,const ::dds::core::optional< ::rti::core::bounded_sequence< ::GNSS::ReferenceStation, 10L > >& ReferenceStation_);

        uint64_t& NAME() noexcept {
            return m_NAME_;
        }

        const uint64_t& NAME() const noexcept {
            return m_NAME_;
        }

        void NAME(uint64_t value) {

            m_NAME_ = value;
        }

        uint8_t& SID() noexcept {
            return m_SID_;
        }

        const uint8_t& SID() const noexcept {
            return m_SID_;
        }

        void SID(uint8_t value) {

            m_SID_ = value;
        }

        ::dds::core::optional< ::Common::Date >& PositionDate() noexcept {
            return m_PositionDate_;
        }

        const ::dds::core::optional< ::Common::Date >& PositionDate() const noexcept {
            return m_PositionDate_;
        }

        void PositionDate(const ::dds::core::optional< ::Common::Date >& value) {

            m_PositionDate_ = value;
        }

        void PositionDate(::dds::core::optional< ::Common::Date >&& value) {
            m_PositionDate_ = std::move(value);
        }
        ::dds::core::optional< ::Common::Time >& PositionTime() noexcept {
            return m_PositionTime_;
        }

        const ::dds::core::optional< ::Common::Time >& PositionTime() const noexcept {
            return m_PositionTime_;
        }

        void PositionTime(const ::dds::core::optional< ::Common::Time >& value) {

            m_PositionTime_ = value;
        }

        void PositionTime(::dds::core::optional< ::Common::Time >&& value) {
            m_PositionTime_ = std::move(value);
        }
        ::dds::core::optional< double >& Lat() noexcept {
            return m_Lat_;
        }

        const ::dds::core::optional< double >& Lat() const noexcept {
            return m_Lat_;
        }

        void Lat(const ::dds::core::optional< double >& value) {

            m_Lat_ = value;
        }

        void Lat(::dds::core::optional< double >&& value) {
            m_Lat_ = std::move(value);
        }
        ::dds::core::optional< double >& Lon() noexcept {
            return m_Lon_;
        }

        const ::dds::core::optional< double >& Lon() const noexcept {
            return m_Lon_;
        }

        void Lon(const ::dds::core::optional< double >& value) {

            m_Lon_ = value;
        }

        void Lon(::dds::core::optional< double >&& value) {
            m_Lon_ = std::move(value);
        }
        ::dds::core::optional< double >& Alt() noexcept {
            return m_Alt_;
        }

        const ::dds::core::optional< double >& Alt() const noexcept {
            return m_Alt_;
        }

        void Alt(const ::dds::core::optional< double >& value) {

            m_Alt_ = value;
        }

        void Alt(::dds::core::optional< double >&& value) {
            m_Alt_ = std::move(value);
        }
        ::dds::core::optional< uint8_t >& TypeOfSystem() noexcept {
            return m_TypeOfSystem_;
        }

        const ::dds::core::optional< uint8_t >& TypeOfSystem() const noexcept {
            return m_TypeOfSystem_;
        }

        void TypeOfSystem(const ::dds::core::optional< uint8_t >& value) {

            m_TypeOfSystem_ = value;
        }

        void TypeOfSystem(::dds::core::optional< uint8_t >&& value) {
            m_TypeOfSystem_ = std::move(value);
        }
        ::dds::core::optional< uint8_t >& Method() noexcept {
            return m_Method_;
        }

        const ::dds::core::optional< uint8_t >& Method() const noexcept {
            return m_Method_;
        }

        void Method(const ::dds::core::optional< uint8_t >& value) {

            m_Method_ = value;
        }

        void Method(::dds::core::optional< uint8_t >&& value) {
            m_Method_ = std::move(value);
        }
        ::dds::core::optional< uint8_t >& Integrity() noexcept {
            return m_Integrity_;
        }

        const ::dds::core::optional< uint8_t >& Integrity() const noexcept {
            return m_Integrity_;
        }

        void Integrity(const ::dds::core::optional< uint8_t >& value) {

            m_Integrity_ = value;
        }

        void Integrity(::dds::core::optional< uint8_t >&& value) {
            m_Integrity_ = std::move(value);
        }
        ::dds::core::optional< uint8_t >& NumOfSVs() noexcept {
            return m_NumOfSVs_;
        }

        const ::dds::core::optional< uint8_t >& NumOfSVs() const noexcept {
            return m_NumOfSVs_;
        }

        void NumOfSVs(const ::dds::core::optional< uint8_t >& value) {

            m_NumOfSVs_ = value;
        }

        void NumOfSVs(::dds::core::optional< uint8_t >&& value) {
            m_NumOfSVs_ = std::move(value);
        }
        ::dds::core::optional< float >& HDOP() noexcept {
            return m_HDOP_;
        }

        const ::dds::core::optional< float >& HDOP() const noexcept {
            return m_HDOP_;
        }

        void HDOP(const ::dds::core::optional< float >& value) {

            m_HDOP_ = value;
        }

        void HDOP(::dds::core::optional< float >&& value) {
            m_HDOP_ = std::move(value);
        }
        ::dds::core::optional< float >& PDOP() noexcept {
            return m_PDOP_;
        }

        const ::dds::core::optional< float >& PDOP() const noexcept {
            return m_PDOP_;
        }

        void PDOP(const ::dds::core::optional< float >& value) {

            m_PDOP_ = value;
        }

        void PDOP(::dds::core::optional< float >&& value) {
            m_PDOP_ = std::move(value);
        }
        ::dds::core::optional< float >& GeoidalSeparation() noexcept {
            return m_GeoidalSeparation_;
        }

        const ::dds::core::optional< float >& GeoidalSeparation() const noexcept {
            return m_GeoidalSeparation_;
        }

        void GeoidalSeparation(const ::dds::core::optional< float >& value) {

            m_GeoidalSeparation_ = value;
        }

        void GeoidalSeparation(::dds::core::optional< float >&& value) {
            m_GeoidalSeparation_ = std::move(value);
        }
        ::dds::core::optional< ::rti::core::bounded_sequence< ::GNSS::ReferenceStation, 10L > >& ReferenceStation() noexcept {
            return m_ReferenceStation_;
        }

        const ::dds::core::optional< ::rti::core::bounded_sequence< ::GNSS::ReferenceStation, 10L > >& ReferenceStation() const noexcept {
            return m_ReferenceStation_;
        }

        void ReferenceStation(const ::dds::core::optional< ::rti::core::bounded_sequence< ::GNSS::ReferenceStation, 10L > >& value) {

            m_ReferenceStation_ = value;
        }

        void ReferenceStation(::dds::core::optional< ::rti::core::bounded_sequence< ::GNSS::ReferenceStation, 10L > >&& value) {
            m_ReferenceStation_ = std::move(value);
        }
        bool operator == (const PositionData_t& other_) const;
        bool operator != (const PositionData_t& other_) const;

        void swap(PositionData_t& other_) noexcept ;

      private:

        uint64_t m_NAME_;
        uint8_t m_SID_;
        ::dds::core::optional< ::Common::Date > m_PositionDate_;
        ::dds::core::optional< ::Common::Time > m_PositionTime_;
        ::dds::core::optional< double > m_Lat_;
        ::dds::core::optional< double > m_Lon_;
        ::dds::core::optional< double > m_Alt_;
        ::dds::core::optional< uint8_t > m_TypeOfSystem_;
        ::dds::core::optional< uint8_t > m_Method_;
        ::dds::core::optional< uint8_t > m_Integrity_;
        ::dds::core::optional< uint8_t > m_NumOfSVs_;
        ::dds::core::optional< float > m_HDOP_;
        ::dds::core::optional< float > m_PDOP_;
        ::dds::core::optional< float > m_GeoidalSeparation_;
        ::dds::core::optional< ::rti::core::bounded_sequence< ::GNSS::ReferenceStation, 10L > > m_ReferenceStation_;

    };

    inline void swap(PositionData_t& a, PositionData_t& b)  noexcept 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const PositionData_t& sample);

} // namespace GNSS  
namespace Vehicle {

    class NDDSUSERDllExport Engine {
      public:

        Engine();

        Engine(uint16_t RPM_,uint16_t Fuel_Consumption_Rate_,uint16_t EGT_,uint16_t Engine_Coolant_Temperature_,uint16_t Intake_Air_Temperature_,uint8_t Throttle_Position_,uint8_t Engine_Load_,uint8_t MAF_,uint32_t Fuel_System_Pressure_);

        uint16_t& RPM() noexcept {
            return m_RPM_;
        }

        const uint16_t& RPM() const noexcept {
            return m_RPM_;
        }

        void RPM(uint16_t value) {

            m_RPM_ = value;
        }

        uint16_t& Fuel_Consumption_Rate() noexcept {
            return m_Fuel_Consumption_Rate_;
        }

        const uint16_t& Fuel_Consumption_Rate() const noexcept {
            return m_Fuel_Consumption_Rate_;
        }

        void Fuel_Consumption_Rate(uint16_t value) {

            m_Fuel_Consumption_Rate_ = value;
        }

        uint16_t& EGT() noexcept {
            return m_EGT_;
        }

        const uint16_t& EGT() const noexcept {
            return m_EGT_;
        }

        void EGT(uint16_t value) {

            m_EGT_ = value;
        }

        uint16_t& Engine_Coolant_Temperature() noexcept {
            return m_Engine_Coolant_Temperature_;
        }

        const uint16_t& Engine_Coolant_Temperature() const noexcept {
            return m_Engine_Coolant_Temperature_;
        }

        void Engine_Coolant_Temperature(uint16_t value) {

            m_Engine_Coolant_Temperature_ = value;
        }

        uint16_t& Intake_Air_Temperature() noexcept {
            return m_Intake_Air_Temperature_;
        }

        const uint16_t& Intake_Air_Temperature() const noexcept {
            return m_Intake_Air_Temperature_;
        }

        void Intake_Air_Temperature(uint16_t value) {

            m_Intake_Air_Temperature_ = value;
        }

        uint8_t& Throttle_Position() noexcept {
            return m_Throttle_Position_;
        }

        const uint8_t& Throttle_Position() const noexcept {
            return m_Throttle_Position_;
        }

        void Throttle_Position(uint8_t value) {

            m_Throttle_Position_ = value;
        }

        uint8_t& Engine_Load() noexcept {
            return m_Engine_Load_;
        }

        const uint8_t& Engine_Load() const noexcept {
            return m_Engine_Load_;
        }

        void Engine_Load(uint8_t value) {

            m_Engine_Load_ = value;
        }

        uint8_t& MAF() noexcept {
            return m_MAF_;
        }

        const uint8_t& MAF() const noexcept {
            return m_MAF_;
        }

        void MAF(uint8_t value) {

            m_MAF_ = value;
        }

        uint32_t& Fuel_System_Pressure() noexcept {
            return m_Fuel_System_Pressure_;
        }

        const uint32_t& Fuel_System_Pressure() const noexcept {
            return m_Fuel_System_Pressure_;
        }

        void Fuel_System_Pressure(uint32_t value) {

            m_Fuel_System_Pressure_ = value;
        }

        bool operator == (const Engine& other_) const;
        bool operator != (const Engine& other_) const;

        void swap(Engine& other_) noexcept ;

      private:

        uint16_t m_RPM_;
        uint16_t m_Fuel_Consumption_Rate_;
        uint16_t m_EGT_;
        uint16_t m_Engine_Coolant_Temperature_;
        uint16_t m_Intake_Air_Temperature_;
        uint8_t m_Throttle_Position_;
        uint8_t m_Engine_Load_;
        uint8_t m_MAF_;
        uint32_t m_Fuel_System_Pressure_;

    };

    inline void swap(Engine& a, Engine& b)  noexcept 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Engine& sample);

    enum class Wheel {
        Front_Left, 
        Front_Right, 
        Rear_Left, 
        Rear_Right
    };

    NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const Wheel& sample);

    class NDDSUSERDllExport Wheel_Speed {
      public:

        Wheel_Speed();

        Wheel_Speed(const ::Vehicle::Wheel& Wheel_,uint16_t Speed_);

        ::Vehicle::Wheel& Wheel() noexcept {
            return m_Wheel_;
        }

        const ::Vehicle::Wheel& Wheel() const noexcept {
            return m_Wheel_;
        }

        void Wheel(const ::Vehicle::Wheel& value) {

            m_Wheel_ = value;
        }

        void Wheel(::Vehicle::Wheel&& value) {
            m_Wheel_ = std::move(value);
        }
        uint16_t& Speed() noexcept {
            return m_Speed_;
        }

        const uint16_t& Speed() const noexcept {
            return m_Speed_;
        }

        void Speed(uint16_t value) {

            m_Speed_ = value;
        }

        bool operator == (const Wheel_Speed& other_) const;
        bool operator != (const Wheel_Speed& other_) const;

        void swap(Wheel_Speed& other_) noexcept ;

      private:

        ::Vehicle::Wheel m_Wheel_;
        uint16_t m_Speed_;

    };

    inline void swap(Wheel_Speed& a, Wheel_Speed& b)  noexcept 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Wheel_Speed& sample);

    #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
    // On Windows, dll-export template instantiations of standard types used by
    // other dll-exported types
    template class NDDSUSERDllExport std::allocator< ::Vehicle::Wheel_Speed >;
    template class NDDSUSERDllExport std::vector< ::Vehicle::Wheel_Speed >;
    #endif
    class NDDSUSERDllExport Dynamics {
      public:

        Dynamics();

        Dynamics(uint16_t Speed_,const ::rti::core::bounded_sequence< ::Vehicle::Wheel_Speed, 4L >& Wheel_Speed_,uint8_t Acceleration_,uint16_t Steering_Angle_);

        uint16_t& Speed() noexcept {
            return m_Speed_;
        }

        const uint16_t& Speed() const noexcept {
            return m_Speed_;
        }

        void Speed(uint16_t value) {

            m_Speed_ = value;
        }

        ::rti::core::bounded_sequence< ::Vehicle::Wheel_Speed, 4L >& Wheel_Speed() noexcept {
            return m_Wheel_Speed_;
        }

        const ::rti::core::bounded_sequence< ::Vehicle::Wheel_Speed, 4L >& Wheel_Speed() const noexcept {
            return m_Wheel_Speed_;
        }

        void Wheel_Speed(const ::rti::core::bounded_sequence< ::Vehicle::Wheel_Speed, 4L >& value) {

            m_Wheel_Speed_ = value;
        }

        void Wheel_Speed(::rti::core::bounded_sequence< ::Vehicle::Wheel_Speed, 4L >&& value) {
            m_Wheel_Speed_ = std::move(value);
        }
        uint8_t& Acceleration() noexcept {
            return m_Acceleration_;
        }

        const uint8_t& Acceleration() const noexcept {
            return m_Acceleration_;
        }

        void Acceleration(uint8_t value) {

            m_Acceleration_ = value;
        }

        uint16_t& Steering_Angle() noexcept {
            return m_Steering_Angle_;
        }

        const uint16_t& Steering_Angle() const noexcept {
            return m_Steering_Angle_;
        }

        void Steering_Angle(uint16_t value) {

            m_Steering_Angle_ = value;
        }

        bool operator == (const Dynamics& other_) const;
        bool operator != (const Dynamics& other_) const;

        void swap(Dynamics& other_) noexcept ;

      private:

        uint16_t m_Speed_;
        ::rti::core::bounded_sequence< ::Vehicle::Wheel_Speed, 4L > m_Wheel_Speed_;
        uint8_t m_Acceleration_;
        uint16_t m_Steering_Angle_;

    };

    inline void swap(Dynamics& a, Dynamics& b)  noexcept 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Dynamics& sample);

    class NDDSUSERDllExport VehicleData_t {
      public:

        VehicleData_t();

        VehicleData_t(uint32_t ID_,const ::dds::core::optional< ::Vehicle::Engine >& Engine_,const ::dds::core::optional< ::Vehicle::Dynamics >& Dynamics_);

        uint32_t& ID() noexcept {
            return m_ID_;
        }

        const uint32_t& ID() const noexcept {
            return m_ID_;
        }

        void ID(uint32_t value) {

            m_ID_ = value;
        }

        ::dds::core::optional< ::Vehicle::Engine >& Engine() noexcept {
            return m_Engine_;
        }

        const ::dds::core::optional< ::Vehicle::Engine >& Engine() const noexcept {
            return m_Engine_;
        }

        void Engine(const ::dds::core::optional< ::Vehicle::Engine >& value) {

            m_Engine_ = value;
        }

        void Engine(::dds::core::optional< ::Vehicle::Engine >&& value) {
            m_Engine_ = std::move(value);
        }
        ::dds::core::optional< ::Vehicle::Dynamics >& Dynamics() noexcept {
            return m_Dynamics_;
        }

        const ::dds::core::optional< ::Vehicle::Dynamics >& Dynamics() const noexcept {
            return m_Dynamics_;
        }

        void Dynamics(const ::dds::core::optional< ::Vehicle::Dynamics >& value) {

            m_Dynamics_ = value;
        }

        void Dynamics(::dds::core::optional< ::Vehicle::Dynamics >&& value) {
            m_Dynamics_ = std::move(value);
        }
        bool operator == (const VehicleData_t& other_) const;
        bool operator != (const VehicleData_t& other_) const;

        void swap(VehicleData_t& other_) noexcept ;

      private:

        uint32_t m_ID_;
        ::dds::core::optional< ::Vehicle::Engine > m_Engine_;
        ::dds::core::optional< ::Vehicle::Dynamics > m_Dynamics_;

    };

    inline void swap(VehicleData_t& a, VehicleData_t& b)  noexcept 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const VehicleData_t& sample);

} // namespace Vehicle  
namespace Diagnostics {
    enum class DiagnosticType_e {
        info, 
        warning, 
        error_recoverable, 
        error_fatal
    };

    NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const DiagnosticType_e& sample);
    enum class DiagnosticCode_e {
        no_diagnostic_code, 
        unit_mismatch, 
        handling_group_mismatch
    };

    NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const DiagnosticCode_e& sample);

    class NDDSUSERDllExport Diagnostic_t {
      public:

        Diagnostic_t();

        Diagnostic_t(const ::DeviceInformation::ElementReference_t& element_ref_,const ::Diagnostics::DiagnosticCode_e& diagnostic_code_,const ::Diagnostics::DiagnosticType_e& diagnostic_type_,const std::string& message_);

        ::DeviceInformation::ElementReference_t& element_ref() noexcept {
            return m_element_ref_;
        }

        const ::DeviceInformation::ElementReference_t& element_ref() const noexcept {
            return m_element_ref_;
        }

        void element_ref(const ::DeviceInformation::ElementReference_t& value) {

            m_element_ref_ = value;
        }

        void element_ref(::DeviceInformation::ElementReference_t&& value) {
            m_element_ref_ = std::move(value);
        }
        ::Diagnostics::DiagnosticCode_e& diagnostic_code() noexcept {
            return m_diagnostic_code_;
        }

        const ::Diagnostics::DiagnosticCode_e& diagnostic_code() const noexcept {
            return m_diagnostic_code_;
        }

        void diagnostic_code(const ::Diagnostics::DiagnosticCode_e& value) {

            m_diagnostic_code_ = value;
        }

        void diagnostic_code(::Diagnostics::DiagnosticCode_e&& value) {
            m_diagnostic_code_ = std::move(value);
        }
        ::Diagnostics::DiagnosticType_e& diagnostic_type() noexcept {
            return m_diagnostic_type_;
        }

        const ::Diagnostics::DiagnosticType_e& diagnostic_type() const noexcept {
            return m_diagnostic_type_;
        }

        void diagnostic_type(const ::Diagnostics::DiagnosticType_e& value) {

            m_diagnostic_type_ = value;
        }

        void diagnostic_type(::Diagnostics::DiagnosticType_e&& value) {
            m_diagnostic_type_ = std::move(value);
        }
        std::string& message() noexcept {
            return m_message_;
        }

        const std::string& message() const noexcept {
            return m_message_;
        }

        void message(const std::string& value) {

            m_message_ = value;
        }

        void message(std::string&& value) {
            m_message_ = std::move(value);
        }
        bool operator == (const Diagnostic_t& other_) const;
        bool operator != (const Diagnostic_t& other_) const;

        void swap(Diagnostic_t& other_) noexcept ;

      private:

        ::DeviceInformation::ElementReference_t m_element_ref_;
        ::Diagnostics::DiagnosticCode_e m_diagnostic_code_;
        ::Diagnostics::DiagnosticType_e m_diagnostic_type_;
        std::string m_message_;

    };

    inline void swap(Diagnostic_t& a, Diagnostic_t& b)  noexcept 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Diagnostic_t& sample);

} // namespace Diagnostics  

#ifdef NDDS_STANDALONE_TYPE
namespace rti { 
    namespace topic {
        template <>
        struct default_enumerator< ::Common::Unit_e>
        {
            static const ::Common::Unit_e value;
        };
        template <>
        struct default_enumerator< ::Actuation::HandlingFeature_e>
        {
            static const ::Actuation::HandlingFeature_e value;
        };
        template <>
        struct default_enumerator< ::Actuation::HandlingGroup_e>
        {
            static const ::Actuation::HandlingGroup_e value;
        };
        template <>
        struct default_enumerator< ::Vehicle::Wheel>
        {
            static const ::Vehicle::Wheel value;
        };
        template <>
        struct default_enumerator< ::Diagnostics::DiagnosticType_e>
        {
            static const ::Diagnostics::DiagnosticType_e value;
        };
        template <>
        struct default_enumerator< ::Diagnostics::DiagnosticCode_e>
        {
            static const ::Diagnostics::DiagnosticCode_e value;
        };
    }
}
#else

namespace rti {
    namespace flat {
        namespace topic {
        }
    }
}
namespace dds {
    namespace topic {

        template<>
        struct topic_type_name< ::Common::Time > {
            NDDSUSERDllExport static std::string value() {
                return "Common::Time";
            }
        };

        template<>
        struct is_topic_type< ::Common::Time > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::Common::Time > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::Common::Time& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::Common::Time& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::Common::Time& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::Common::Time& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::Common::OnOff_t > {
            NDDSUSERDllExport static std::string value() {
                return "Common::OnOff_t";
            }
        };

        template<>
        struct is_topic_type< ::Common::OnOff_t > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::Common::OnOff_t > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::Common::OnOff_t& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::Common::OnOff_t& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::Common::OnOff_t& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::Common::OnOff_t& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::Common::Unit_t > {
            NDDSUSERDllExport static std::string value() {
                return "Common::Unit_t";
            }
        };

        template<>
        struct is_topic_type< ::Common::Unit_t > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::Common::Unit_t > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::Common::Unit_t& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::Common::Unit_t& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::Common::Unit_t& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::Common::Unit_t& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::Common::Date > {
            NDDSUSERDllExport static std::string value() {
                return "Common::Date";
            }
        };

        template<>
        struct is_topic_type< ::Common::Date > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::Common::Date > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::Common::Date& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::Common::Date& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::Common::Date& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::Common::Date& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::DeviceInformation::ElementReference_t > {
            NDDSUSERDllExport static std::string value() {
                return "DeviceInformation::ElementReference_t";
            }
        };

        template<>
        struct is_topic_type< ::DeviceInformation::ElementReference_t > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::DeviceInformation::ElementReference_t > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::DeviceInformation::ElementReference_t& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::DeviceInformation::ElementReference_t& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::DeviceInformation::ElementReference_t& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::DeviceInformation::ElementReference_t& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::DeviceInformation::Device_t > {
            NDDSUSERDllExport static std::string value() {
                return "DeviceInformation::Device_t";
            }
        };

        template<>
        struct is_topic_type< ::DeviceInformation::Device_t > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::DeviceInformation::Device_t > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::DeviceInformation::Device_t& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::DeviceInformation::Device_t& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::DeviceInformation::Device_t& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::DeviceInformation::Device_t& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::DeviceInformation::DeviceElement_t > {
            NDDSUSERDllExport static std::string value() {
                return "DeviceInformation::DeviceElement_t";
            }
        };

        template<>
        struct is_topic_type< ::DeviceInformation::DeviceElement_t > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::DeviceInformation::DeviceElement_t > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::DeviceInformation::DeviceElement_t& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::DeviceInformation::DeviceElement_t& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::DeviceInformation::DeviceElement_t& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::DeviceInformation::DeviceElement_t& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::DeviceInformation::ServiceDiscovery_t > {
            NDDSUSERDllExport static std::string value() {
                return "DeviceInformation::ServiceDiscovery_t";
            }
        };

        template<>
        struct is_topic_type< ::DeviceInformation::ServiceDiscovery_t > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::DeviceInformation::ServiceDiscovery_t > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::DeviceInformation::ServiceDiscovery_t& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::DeviceInformation::ServiceDiscovery_t& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::DeviceInformation::ServiceDiscovery_t& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::DeviceInformation::ServiceDiscovery_t& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::DeviceInformation::ServiceDiscovery_extended_t > {
            NDDSUSERDllExport static std::string value() {
                return "DeviceInformation::ServiceDiscovery_extended_t";
            }
        };

        template<>
        struct is_topic_type< ::DeviceInformation::ServiceDiscovery_extended_t > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::DeviceInformation::ServiceDiscovery_extended_t > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::DeviceInformation::ServiceDiscovery_extended_t& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::DeviceInformation::ServiceDiscovery_extended_t& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::DeviceInformation::ServiceDiscovery_extended_t& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::DeviceInformation::ServiceDiscovery_extended_t& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::Actuation::ControlHandlingCapabilities_t > {
            NDDSUSERDllExport static std::string value() {
                return "Actuation::ControlHandlingCapabilities_t";
            }
        };

        template<>
        struct is_topic_type< ::Actuation::ControlHandlingCapabilities_t > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::Actuation::ControlHandlingCapabilities_t > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::Actuation::ControlHandlingCapabilities_t& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::Actuation::ControlHandlingCapabilities_t& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::Actuation::ControlHandlingCapabilities_t& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::Actuation::ControlHandlingCapabilities_t& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::Actuation::ControlHandlingValues_t > {
            NDDSUSERDllExport static std::string value() {
                return "Actuation::ControlHandlingValues_t";
            }
        };

        template<>
        struct is_topic_type< ::Actuation::ControlHandlingValues_t > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::Actuation::ControlHandlingValues_t > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::Actuation::ControlHandlingValues_t& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::Actuation::ControlHandlingValues_t& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::Actuation::ControlHandlingValues_t& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::Actuation::ControlHandlingValues_t& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::GNSS::ReferenceStation > {
            NDDSUSERDllExport static std::string value() {
                return "GNSS::ReferenceStation";
            }
        };

        template<>
        struct is_topic_type< ::GNSS::ReferenceStation > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::GNSS::ReferenceStation > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::GNSS::ReferenceStation& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::GNSS::ReferenceStation& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::GNSS::ReferenceStation& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::GNSS::ReferenceStation& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::GNSS::PositionData_t > {
            NDDSUSERDllExport static std::string value() {
                return "GNSS::PositionData_t";
            }
        };

        template<>
        struct is_topic_type< ::GNSS::PositionData_t > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::GNSS::PositionData_t > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::GNSS::PositionData_t& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::GNSS::PositionData_t& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::GNSS::PositionData_t& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::GNSS::PositionData_t& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::Vehicle::Engine > {
            NDDSUSERDllExport static std::string value() {
                return "Vehicle::Engine";
            }
        };

        template<>
        struct is_topic_type< ::Vehicle::Engine > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::Vehicle::Engine > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::Vehicle::Engine& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::Vehicle::Engine& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::Vehicle::Engine& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::Vehicle::Engine& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::Vehicle::Wheel_Speed > {
            NDDSUSERDllExport static std::string value() {
                return "Vehicle::Wheel_Speed";
            }
        };

        template<>
        struct is_topic_type< ::Vehicle::Wheel_Speed > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::Vehicle::Wheel_Speed > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::Vehicle::Wheel_Speed& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::Vehicle::Wheel_Speed& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::Vehicle::Wheel_Speed& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::Vehicle::Wheel_Speed& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::Vehicle::Dynamics > {
            NDDSUSERDllExport static std::string value() {
                return "Vehicle::Dynamics";
            }
        };

        template<>
        struct is_topic_type< ::Vehicle::Dynamics > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::Vehicle::Dynamics > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::Vehicle::Dynamics& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::Vehicle::Dynamics& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::Vehicle::Dynamics& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::Vehicle::Dynamics& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::Vehicle::VehicleData_t > {
            NDDSUSERDllExport static std::string value() {
                return "Vehicle::VehicleData_t";
            }
        };

        template<>
        struct is_topic_type< ::Vehicle::VehicleData_t > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::Vehicle::VehicleData_t > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::Vehicle::VehicleData_t& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::Vehicle::VehicleData_t& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::Vehicle::VehicleData_t& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::Vehicle::VehicleData_t& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::Diagnostics::Diagnostic_t > {
            NDDSUSERDllExport static std::string value() {
                return "Diagnostics::Diagnostic_t";
            }
        };

        template<>
        struct is_topic_type< ::Diagnostics::Diagnostic_t > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::Diagnostics::Diagnostic_t > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::Diagnostics::Diagnostic_t& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::Diagnostics::Diagnostic_t& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::Diagnostics::Diagnostic_t& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::Diagnostics::Diagnostic_t& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
    }
}

namespace rti { 
    namespace topic {

        template<>
        struct dynamic_type< ::Common::Time > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::Common::Time > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::Common::OnOff_t > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::Common::OnOff_t > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template <>
        struct default_enumerator< ::Common::Unit_e>
        {
            static const ::Common::Unit_e value;
        };
        template<>
        struct dynamic_type< ::Common::Unit_e > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };

        template <>
        struct extensibility< ::Common::Unit_e > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::Common::Unit_t > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::Common::Unit_t > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::Common::Date > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::Common::Date > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::DeviceInformation::ElementReference_t > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::DeviceInformation::ElementReference_t > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::DeviceInformation::Device_t > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::DeviceInformation::Device_t > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::DeviceInformation::DeviceElement_t > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::DeviceInformation::DeviceElement_t > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::DeviceInformation::ServiceDiscovery_t > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::DeviceInformation::ServiceDiscovery_t > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::DeviceInformation::ServiceDiscovery_extended_t > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::DeviceInformation::ServiceDiscovery_extended_t > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template <>
        struct default_enumerator< ::Actuation::HandlingFeature_e>
        {
            static const ::Actuation::HandlingFeature_e value;
        };
        template<>
        struct dynamic_type< ::Actuation::HandlingFeature_e > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };

        template <>
        struct extensibility< ::Actuation::HandlingFeature_e > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template <>
        struct default_enumerator< ::Actuation::HandlingGroup_e>
        {
            static const ::Actuation::HandlingGroup_e value;
        };
        template<>
        struct dynamic_type< ::Actuation::HandlingGroup_e > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };

        template <>
        struct extensibility< ::Actuation::HandlingGroup_e > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::Actuation::ControlHandlingCapabilities_t > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::Actuation::ControlHandlingCapabilities_t > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::Actuation::ControlHandlingValues_t > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::Actuation::ControlHandlingValues_t > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::GNSS::ReferenceStation > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::GNSS::ReferenceStation > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::GNSS::PositionData_t > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::GNSS::PositionData_t > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::Vehicle::Engine > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::Vehicle::Engine > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template <>
        struct default_enumerator< ::Vehicle::Wheel>
        {
            static const ::Vehicle::Wheel value;
        };
        template<>
        struct dynamic_type< ::Vehicle::Wheel > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };

        template <>
        struct extensibility< ::Vehicle::Wheel > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::Vehicle::Wheel_Speed > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::Vehicle::Wheel_Speed > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::Vehicle::Dynamics > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::Vehicle::Dynamics > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::Vehicle::VehicleData_t > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::Vehicle::VehicleData_t > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template <>
        struct default_enumerator< ::Diagnostics::DiagnosticType_e>
        {
            static const ::Diagnostics::DiagnosticType_e value;
        };
        template<>
        struct dynamic_type< ::Diagnostics::DiagnosticType_e > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };

        template <>
        struct extensibility< ::Diagnostics::DiagnosticType_e > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template <>
        struct default_enumerator< ::Diagnostics::DiagnosticCode_e>
        {
            static const ::Diagnostics::DiagnosticCode_e value;
        };
        template<>
        struct dynamic_type< ::Diagnostics::DiagnosticCode_e > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };

        template <>
        struct extensibility< ::Diagnostics::DiagnosticCode_e > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::Diagnostics::Diagnostic_t > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::Diagnostics::Diagnostic_t > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

    }
}

#endif // NDDS_STANDALONE_TYPE
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // HSI_Standard_topics_1006183393_hpp

