

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from HSI_Standard_topics.idl
using RTI Code Generator (rtiddsgen) version 4.2.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef HSI_Standard_topicsPlugin_1006183393_h
#define HSI_Standard_topicsPlugin_1006183393_h

#include "HSI_Standard_topics.hpp"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

namespace Common {

    #define TimePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define TimePlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define TimePlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define TimePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define TimePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern Time*
    TimePluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern Time*
    TimePluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Time*
    TimePluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    TimePluginSupport_copy_data(
        Time *out,
        const Time *in);

    NDDSUSERDllExport extern void 
    TimePluginSupport_destroy_data_w_params(
        Time *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    TimePluginSupport_destroy_data_ex(
        Time *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    TimePluginSupport_destroy_data(
        Time *sample);

    NDDSUSERDllExport extern void 
    TimePluginSupport_print_data(
        const Time *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    TimePlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    TimePlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    TimePlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    TimePlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    TimePlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        Time *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    TimePlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        Time *out,
        const Time *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    TimePlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Time *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    TimePlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        Time **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    TimePlugin_deserialize_from_cdr_buffer(
        Time *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    TimePlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    TimePlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    TimePlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    TimePlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    TimePlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Time ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    TimePlugin_new(void);

    NDDSUSERDllExport extern void
    TimePlugin_delete(struct PRESTypePlugin *);

    #define OnOff_tPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define OnOff_tPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define OnOff_tPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define OnOff_tPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define OnOff_tPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern OnOff_t*
    OnOff_tPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern OnOff_t*
    OnOff_tPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern OnOff_t*
    OnOff_tPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    OnOff_tPluginSupport_copy_data(
        OnOff_t *out,
        const OnOff_t *in);

    NDDSUSERDllExport extern void 
    OnOff_tPluginSupport_destroy_data_w_params(
        OnOff_t *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    OnOff_tPluginSupport_destroy_data_ex(
        OnOff_t *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    OnOff_tPluginSupport_destroy_data(
        OnOff_t *sample);

    NDDSUSERDllExport extern void 
    OnOff_tPluginSupport_print_data(
        const OnOff_t *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    OnOff_tPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    OnOff_tPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    OnOff_tPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    OnOff_tPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    OnOff_tPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        OnOff_t *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    OnOff_tPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        OnOff_t *out,
        const OnOff_t *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    OnOff_tPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const OnOff_t *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    OnOff_tPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        OnOff_t **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    OnOff_tPlugin_deserialize_from_cdr_buffer(
        OnOff_t *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    OnOff_tPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    OnOff_tPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    OnOff_tPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    OnOff_tPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    OnOff_tPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        OnOff_t ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    OnOff_tPlugin_new(void);

    NDDSUSERDllExport extern void
    OnOff_tPlugin_delete(struct PRESTypePlugin *);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    Unit_ePlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    Unit_ePlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Unit_ePlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* ----------------------------------------------------------------------------
    Support functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern void
    Unit_ePluginSupport_print_data(
        const Unit_e *sample,
        const char *desc,
        unsigned int indent_level);

    #define Unit_tPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define Unit_tPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define Unit_tPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define Unit_tPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define Unit_tPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern Unit_t*
    Unit_tPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern Unit_t*
    Unit_tPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Unit_t*
    Unit_tPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    Unit_tPluginSupport_copy_data(
        Unit_t *out,
        const Unit_t *in);

    NDDSUSERDllExport extern void 
    Unit_tPluginSupport_destroy_data_w_params(
        Unit_t *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    Unit_tPluginSupport_destroy_data_ex(
        Unit_t *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    Unit_tPluginSupport_destroy_data(
        Unit_t *sample);

    NDDSUSERDllExport extern void 
    Unit_tPluginSupport_print_data(
        const Unit_t *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    Unit_tPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    Unit_tPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    Unit_tPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    Unit_tPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    Unit_tPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        Unit_t *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    Unit_tPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        Unit_t *out,
        const Unit_t *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    Unit_tPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Unit_t *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    Unit_tPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        Unit_t **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Unit_tPlugin_deserialize_from_cdr_buffer(
        Unit_t *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    Unit_tPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Unit_tPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Unit_tPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Unit_tPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Unit_tPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Unit_t ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    Unit_tPlugin_new(void);

    NDDSUSERDllExport extern void
    Unit_tPlugin_delete(struct PRESTypePlugin *);

    #define DatePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define DatePlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define DatePlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define DatePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define DatePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern Date*
    DatePluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern Date*
    DatePluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Date*
    DatePluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    DatePluginSupport_copy_data(
        Date *out,
        const Date *in);

    NDDSUSERDllExport extern void 
    DatePluginSupport_destroy_data_w_params(
        Date *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    DatePluginSupport_destroy_data_ex(
        Date *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    DatePluginSupport_destroy_data(
        Date *sample);

    NDDSUSERDllExport extern void 
    DatePluginSupport_print_data(
        const Date *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    DatePlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    DatePlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    DatePlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    DatePlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    DatePlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        Date *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    DatePlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        Date *out,
        const Date *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    DatePlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Date *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    DatePlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        Date **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    DatePlugin_deserialize_from_cdr_buffer(
        Date *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    DatePlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    DatePlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    DatePlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    DatePlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    DatePlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Date ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    DatePlugin_new(void);

    NDDSUSERDllExport extern void
    DatePlugin_delete(struct PRESTypePlugin *);

} /* namespace Common  */
namespace DeviceInformation {

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct ElementReference_t
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct ElementReference_t)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * ElementReference_t must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct ElementReference_t.
    */
    typedef class ElementReference_t ElementReference_tKeyHolder;

    #define ElementReference_tPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define ElementReference_tPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define ElementReference_tPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define ElementReference_tPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define ElementReference_tPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define ElementReference_tPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define ElementReference_tPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern ElementReference_t*
    ElementReference_tPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern ElementReference_t*
    ElementReference_tPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern ElementReference_t*
    ElementReference_tPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    ElementReference_tPluginSupport_copy_data(
        ElementReference_t *out,
        const ElementReference_t *in);

    NDDSUSERDllExport extern void 
    ElementReference_tPluginSupport_destroy_data_w_params(
        ElementReference_t *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    ElementReference_tPluginSupport_destroy_data_ex(
        ElementReference_t *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    ElementReference_tPluginSupport_destroy_data(
        ElementReference_t *sample);

    NDDSUSERDllExport extern void 
    ElementReference_tPluginSupport_print_data(
        const ElementReference_t *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern ElementReference_t*
    ElementReference_tPluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern ElementReference_t*
    ElementReference_tPluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    ElementReference_tPluginSupport_destroy_key_ex(
        ElementReference_tKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    ElementReference_tPluginSupport_destroy_key(
        ElementReference_tKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    ElementReference_tPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    ElementReference_tPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    ElementReference_tPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    ElementReference_tPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    ElementReference_tPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        ElementReference_t *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    ElementReference_tPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        ElementReference_t *out,
        const ElementReference_t *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    ElementReference_tPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const ElementReference_t *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    ElementReference_tPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        ElementReference_t **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    ElementReference_tPlugin_deserialize_from_cdr_buffer(
        ElementReference_t *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    ElementReference_tPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    ElementReference_tPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    ElementReference_tPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    ElementReference_tPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    ElementReference_tPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        ElementReference_t ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    ElementReference_tPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        ElementReference_tKeyHolder *key, 
        const ElementReference_t *instance);

    NDDSUSERDllExport extern RTIBool 
    ElementReference_tPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        ElementReference_t *instance, 
        const ElementReference_tKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    ElementReference_tPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    ElementReference_tPlugin_new(void);

    NDDSUSERDllExport extern void
    ElementReference_tPlugin_delete(struct PRESTypePlugin *);

    #define Device_tPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define Device_tPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define Device_tPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define Device_tPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define Device_tPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern Device_t*
    Device_tPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern Device_t*
    Device_tPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Device_t*
    Device_tPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    Device_tPluginSupport_copy_data(
        Device_t *out,
        const Device_t *in);

    NDDSUSERDllExport extern void 
    Device_tPluginSupport_destroy_data_w_params(
        Device_t *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    Device_tPluginSupport_destroy_data_ex(
        Device_t *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    Device_tPluginSupport_destroy_data(
        Device_t *sample);

    NDDSUSERDllExport extern void 
    Device_tPluginSupport_print_data(
        const Device_t *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    Device_tPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    Device_tPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    Device_tPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    Device_tPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    Device_tPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        Device_t *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    Device_tPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        Device_t *out,
        const Device_t *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    Device_tPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Device_t *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    Device_tPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        Device_t **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Device_tPlugin_deserialize_from_cdr_buffer(
        Device_t *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    Device_tPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Device_tPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Device_tPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Device_tPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Device_tPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Device_t ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    Device_tPlugin_new(void);

    NDDSUSERDllExport extern void
    Device_tPlugin_delete(struct PRESTypePlugin *);

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct DeviceElement_t
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct DeviceElement_t)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * DeviceElement_t must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct DeviceElement_t.
    */
    typedef class DeviceElement_t DeviceElement_tKeyHolder;

    #define DeviceElement_tPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define DeviceElement_tPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define DeviceElement_tPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define DeviceElement_tPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define DeviceElement_tPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define DeviceElement_tPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define DeviceElement_tPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern DeviceElement_t*
    DeviceElement_tPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern DeviceElement_t*
    DeviceElement_tPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern DeviceElement_t*
    DeviceElement_tPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    DeviceElement_tPluginSupport_copy_data(
        DeviceElement_t *out,
        const DeviceElement_t *in);

    NDDSUSERDllExport extern void 
    DeviceElement_tPluginSupport_destroy_data_w_params(
        DeviceElement_t *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    DeviceElement_tPluginSupport_destroy_data_ex(
        DeviceElement_t *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    DeviceElement_tPluginSupport_destroy_data(
        DeviceElement_t *sample);

    NDDSUSERDllExport extern void 
    DeviceElement_tPluginSupport_print_data(
        const DeviceElement_t *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern DeviceElement_t*
    DeviceElement_tPluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern DeviceElement_t*
    DeviceElement_tPluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    DeviceElement_tPluginSupport_destroy_key_ex(
        DeviceElement_tKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    DeviceElement_tPluginSupport_destroy_key(
        DeviceElement_tKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    DeviceElement_tPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    DeviceElement_tPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    DeviceElement_tPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    DeviceElement_tPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    DeviceElement_tPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        DeviceElement_t *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    DeviceElement_tPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        DeviceElement_t *out,
        const DeviceElement_t *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    DeviceElement_tPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const DeviceElement_t *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    DeviceElement_tPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        DeviceElement_t **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    DeviceElement_tPlugin_deserialize_from_cdr_buffer(
        DeviceElement_t *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    DeviceElement_tPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    DeviceElement_tPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    DeviceElement_tPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    DeviceElement_tPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    DeviceElement_tPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        DeviceElement_t ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    DeviceElement_tPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        DeviceElement_tKeyHolder *key, 
        const DeviceElement_t *instance);

    NDDSUSERDllExport extern RTIBool 
    DeviceElement_tPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        DeviceElement_t *instance, 
        const DeviceElement_tKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    DeviceElement_tPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    DeviceElement_tPlugin_new(void);

    NDDSUSERDllExport extern void
    DeviceElement_tPlugin_delete(struct PRESTypePlugin *);

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct ServiceDiscovery_t
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct ServiceDiscovery_t)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * ServiceDiscovery_t must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct ServiceDiscovery_t.
    */
    typedef class ServiceDiscovery_t ServiceDiscovery_tKeyHolder;

    #define ServiceDiscovery_tPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define ServiceDiscovery_tPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define ServiceDiscovery_tPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define ServiceDiscovery_tPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define ServiceDiscovery_tPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define ServiceDiscovery_tPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define ServiceDiscovery_tPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern ServiceDiscovery_t*
    ServiceDiscovery_tPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern ServiceDiscovery_t*
    ServiceDiscovery_tPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern ServiceDiscovery_t*
    ServiceDiscovery_tPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    ServiceDiscovery_tPluginSupport_copy_data(
        ServiceDiscovery_t *out,
        const ServiceDiscovery_t *in);

    NDDSUSERDllExport extern void 
    ServiceDiscovery_tPluginSupport_destroy_data_w_params(
        ServiceDiscovery_t *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    ServiceDiscovery_tPluginSupport_destroy_data_ex(
        ServiceDiscovery_t *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    ServiceDiscovery_tPluginSupport_destroy_data(
        ServiceDiscovery_t *sample);

    NDDSUSERDllExport extern void 
    ServiceDiscovery_tPluginSupport_print_data(
        const ServiceDiscovery_t *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern ServiceDiscovery_t*
    ServiceDiscovery_tPluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern ServiceDiscovery_t*
    ServiceDiscovery_tPluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    ServiceDiscovery_tPluginSupport_destroy_key_ex(
        ServiceDiscovery_tKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    ServiceDiscovery_tPluginSupport_destroy_key(
        ServiceDiscovery_tKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    ServiceDiscovery_tPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    ServiceDiscovery_tPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    ServiceDiscovery_tPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    ServiceDiscovery_tPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    ServiceDiscovery_tPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        ServiceDiscovery_t *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    ServiceDiscovery_tPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        ServiceDiscovery_t *out,
        const ServiceDiscovery_t *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    ServiceDiscovery_tPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const ServiceDiscovery_t *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    ServiceDiscovery_tPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        ServiceDiscovery_t **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    ServiceDiscovery_tPlugin_deserialize_from_cdr_buffer(
        ServiceDiscovery_t *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    ServiceDiscovery_tPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    ServiceDiscovery_tPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    ServiceDiscovery_tPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    ServiceDiscovery_tPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    ServiceDiscovery_tPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        ServiceDiscovery_t ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    ServiceDiscovery_tPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        ServiceDiscovery_tKeyHolder *key, 
        const ServiceDiscovery_t *instance);

    NDDSUSERDllExport extern RTIBool 
    ServiceDiscovery_tPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        ServiceDiscovery_t *instance, 
        const ServiceDiscovery_tKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    ServiceDiscovery_tPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    ServiceDiscovery_tPlugin_new(void);

    NDDSUSERDllExport extern void
    ServiceDiscovery_tPlugin_delete(struct PRESTypePlugin *);

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct ServiceDiscovery_extended_t
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct ServiceDiscovery_extended_t)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * ServiceDiscovery_extended_t must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct ServiceDiscovery_extended_t.
    */
    typedef class ServiceDiscovery_extended_t ServiceDiscovery_extended_tKeyHolder;

    #define ServiceDiscovery_extended_tPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define ServiceDiscovery_extended_tPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define ServiceDiscovery_extended_tPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define ServiceDiscovery_extended_tPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define ServiceDiscovery_extended_tPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define ServiceDiscovery_extended_tPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define ServiceDiscovery_extended_tPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern ServiceDiscovery_extended_t*
    ServiceDiscovery_extended_tPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern ServiceDiscovery_extended_t*
    ServiceDiscovery_extended_tPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern ServiceDiscovery_extended_t*
    ServiceDiscovery_extended_tPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    ServiceDiscovery_extended_tPluginSupport_copy_data(
        ServiceDiscovery_extended_t *out,
        const ServiceDiscovery_extended_t *in);

    NDDSUSERDllExport extern void 
    ServiceDiscovery_extended_tPluginSupport_destroy_data_w_params(
        ServiceDiscovery_extended_t *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    ServiceDiscovery_extended_tPluginSupport_destroy_data_ex(
        ServiceDiscovery_extended_t *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    ServiceDiscovery_extended_tPluginSupport_destroy_data(
        ServiceDiscovery_extended_t *sample);

    NDDSUSERDllExport extern void 
    ServiceDiscovery_extended_tPluginSupport_print_data(
        const ServiceDiscovery_extended_t *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern ServiceDiscovery_extended_t*
    ServiceDiscovery_extended_tPluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern ServiceDiscovery_extended_t*
    ServiceDiscovery_extended_tPluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    ServiceDiscovery_extended_tPluginSupport_destroy_key_ex(
        ServiceDiscovery_extended_tKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    ServiceDiscovery_extended_tPluginSupport_destroy_key(
        ServiceDiscovery_extended_tKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    ServiceDiscovery_extended_tPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    ServiceDiscovery_extended_tPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    ServiceDiscovery_extended_tPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    ServiceDiscovery_extended_tPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    ServiceDiscovery_extended_tPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        ServiceDiscovery_extended_t *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    ServiceDiscovery_extended_tPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        ServiceDiscovery_extended_t *out,
        const ServiceDiscovery_extended_t *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    ServiceDiscovery_extended_tPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const ServiceDiscovery_extended_t *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    ServiceDiscovery_extended_tPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        ServiceDiscovery_extended_t **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    ServiceDiscovery_extended_tPlugin_deserialize_from_cdr_buffer(
        ServiceDiscovery_extended_t *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    ServiceDiscovery_extended_tPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    ServiceDiscovery_extended_tPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    ServiceDiscovery_extended_tPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    ServiceDiscovery_extended_tPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    ServiceDiscovery_extended_tPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        ServiceDiscovery_extended_t ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    ServiceDiscovery_extended_tPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        ServiceDiscovery_extended_tKeyHolder *key, 
        const ServiceDiscovery_extended_t *instance);

    NDDSUSERDllExport extern RTIBool 
    ServiceDiscovery_extended_tPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        ServiceDiscovery_extended_t *instance, 
        const ServiceDiscovery_extended_tKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    ServiceDiscovery_extended_tPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    ServiceDiscovery_extended_tPlugin_new(void);

    NDDSUSERDllExport extern void
    ServiceDiscovery_extended_tPlugin_delete(struct PRESTypePlugin *);

} /* namespace DeviceInformation  */
namespace Actuation {

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    HandlingFeature_ePlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    HandlingFeature_ePlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    HandlingFeature_ePlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* ----------------------------------------------------------------------------
    Support functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern void
    HandlingFeature_ePluginSupport_print_data(
        const HandlingFeature_e *sample,
        const char *desc,
        unsigned int indent_level);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    HandlingGroup_ePlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    HandlingGroup_ePlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    HandlingGroup_ePlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* ----------------------------------------------------------------------------
    Support functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern void
    HandlingGroup_ePluginSupport_print_data(
        const HandlingGroup_e *sample,
        const char *desc,
        unsigned int indent_level);

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct ControlHandlingCapabilities_t
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct ControlHandlingCapabilities_t)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * ControlHandlingCapabilities_t must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct ControlHandlingCapabilities_t.
    */
    typedef class ControlHandlingCapabilities_t ControlHandlingCapabilities_tKeyHolder;

    #define ControlHandlingCapabilities_tPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define ControlHandlingCapabilities_tPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define ControlHandlingCapabilities_tPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define ControlHandlingCapabilities_tPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define ControlHandlingCapabilities_tPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define ControlHandlingCapabilities_tPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define ControlHandlingCapabilities_tPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern ControlHandlingCapabilities_t*
    ControlHandlingCapabilities_tPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern ControlHandlingCapabilities_t*
    ControlHandlingCapabilities_tPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern ControlHandlingCapabilities_t*
    ControlHandlingCapabilities_tPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    ControlHandlingCapabilities_tPluginSupport_copy_data(
        ControlHandlingCapabilities_t *out,
        const ControlHandlingCapabilities_t *in);

    NDDSUSERDllExport extern void 
    ControlHandlingCapabilities_tPluginSupport_destroy_data_w_params(
        ControlHandlingCapabilities_t *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    ControlHandlingCapabilities_tPluginSupport_destroy_data_ex(
        ControlHandlingCapabilities_t *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    ControlHandlingCapabilities_tPluginSupport_destroy_data(
        ControlHandlingCapabilities_t *sample);

    NDDSUSERDllExport extern void 
    ControlHandlingCapabilities_tPluginSupport_print_data(
        const ControlHandlingCapabilities_t *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern ControlHandlingCapabilities_t*
    ControlHandlingCapabilities_tPluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern ControlHandlingCapabilities_t*
    ControlHandlingCapabilities_tPluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    ControlHandlingCapabilities_tPluginSupport_destroy_key_ex(
        ControlHandlingCapabilities_tKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    ControlHandlingCapabilities_tPluginSupport_destroy_key(
        ControlHandlingCapabilities_tKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    ControlHandlingCapabilities_tPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    ControlHandlingCapabilities_tPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    ControlHandlingCapabilities_tPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    ControlHandlingCapabilities_tPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    ControlHandlingCapabilities_tPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        ControlHandlingCapabilities_t *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    ControlHandlingCapabilities_tPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        ControlHandlingCapabilities_t *out,
        const ControlHandlingCapabilities_t *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    ControlHandlingCapabilities_tPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const ControlHandlingCapabilities_t *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    ControlHandlingCapabilities_tPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        ControlHandlingCapabilities_t **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    ControlHandlingCapabilities_tPlugin_deserialize_from_cdr_buffer(
        ControlHandlingCapabilities_t *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    ControlHandlingCapabilities_tPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    ControlHandlingCapabilities_tPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    ControlHandlingCapabilities_tPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    ControlHandlingCapabilities_tPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    ControlHandlingCapabilities_tPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        ControlHandlingCapabilities_t ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    ControlHandlingCapabilities_tPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        ControlHandlingCapabilities_tKeyHolder *key, 
        const ControlHandlingCapabilities_t *instance);

    NDDSUSERDllExport extern RTIBool 
    ControlHandlingCapabilities_tPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        ControlHandlingCapabilities_t *instance, 
        const ControlHandlingCapabilities_tKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    ControlHandlingCapabilities_tPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    ControlHandlingCapabilities_tPlugin_new(void);

    NDDSUSERDllExport extern void
    ControlHandlingCapabilities_tPlugin_delete(struct PRESTypePlugin *);

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct ControlHandlingValues_t
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct ControlHandlingValues_t)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * ControlHandlingValues_t must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct ControlHandlingValues_t.
    */
    typedef class ControlHandlingValues_t ControlHandlingValues_tKeyHolder;

    #define ControlHandlingValues_tPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define ControlHandlingValues_tPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define ControlHandlingValues_tPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define ControlHandlingValues_tPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define ControlHandlingValues_tPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define ControlHandlingValues_tPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define ControlHandlingValues_tPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern ControlHandlingValues_t*
    ControlHandlingValues_tPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern ControlHandlingValues_t*
    ControlHandlingValues_tPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern ControlHandlingValues_t*
    ControlHandlingValues_tPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    ControlHandlingValues_tPluginSupport_copy_data(
        ControlHandlingValues_t *out,
        const ControlHandlingValues_t *in);

    NDDSUSERDllExport extern void 
    ControlHandlingValues_tPluginSupport_destroy_data_w_params(
        ControlHandlingValues_t *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    ControlHandlingValues_tPluginSupport_destroy_data_ex(
        ControlHandlingValues_t *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    ControlHandlingValues_tPluginSupport_destroy_data(
        ControlHandlingValues_t *sample);

    NDDSUSERDllExport extern void 
    ControlHandlingValues_tPluginSupport_print_data(
        const ControlHandlingValues_t *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern ControlHandlingValues_t*
    ControlHandlingValues_tPluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern ControlHandlingValues_t*
    ControlHandlingValues_tPluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    ControlHandlingValues_tPluginSupport_destroy_key_ex(
        ControlHandlingValues_tKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    ControlHandlingValues_tPluginSupport_destroy_key(
        ControlHandlingValues_tKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    ControlHandlingValues_tPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    ControlHandlingValues_tPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    ControlHandlingValues_tPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    ControlHandlingValues_tPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    ControlHandlingValues_tPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        ControlHandlingValues_t *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    ControlHandlingValues_tPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        ControlHandlingValues_t *out,
        const ControlHandlingValues_t *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    ControlHandlingValues_tPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const ControlHandlingValues_t *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    ControlHandlingValues_tPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        ControlHandlingValues_t **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    ControlHandlingValues_tPlugin_deserialize_from_cdr_buffer(
        ControlHandlingValues_t *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    ControlHandlingValues_tPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    ControlHandlingValues_tPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    ControlHandlingValues_tPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    ControlHandlingValues_tPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    ControlHandlingValues_tPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        ControlHandlingValues_t ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    ControlHandlingValues_tPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        ControlHandlingValues_tKeyHolder *key, 
        const ControlHandlingValues_t *instance);

    NDDSUSERDllExport extern RTIBool 
    ControlHandlingValues_tPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        ControlHandlingValues_t *instance, 
        const ControlHandlingValues_tKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    ControlHandlingValues_tPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    ControlHandlingValues_tPlugin_new(void);

    NDDSUSERDllExport extern void
    ControlHandlingValues_tPlugin_delete(struct PRESTypePlugin *);

} /* namespace Actuation  */
namespace GNSS {

    #define ReferenceStationPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define ReferenceStationPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define ReferenceStationPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define ReferenceStationPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define ReferenceStationPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern ReferenceStation*
    ReferenceStationPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern ReferenceStation*
    ReferenceStationPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern ReferenceStation*
    ReferenceStationPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    ReferenceStationPluginSupport_copy_data(
        ReferenceStation *out,
        const ReferenceStation *in);

    NDDSUSERDllExport extern void 
    ReferenceStationPluginSupport_destroy_data_w_params(
        ReferenceStation *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    ReferenceStationPluginSupport_destroy_data_ex(
        ReferenceStation *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    ReferenceStationPluginSupport_destroy_data(
        ReferenceStation *sample);

    NDDSUSERDllExport extern void 
    ReferenceStationPluginSupport_print_data(
        const ReferenceStation *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    ReferenceStationPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    ReferenceStationPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    ReferenceStationPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    ReferenceStationPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    ReferenceStationPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        ReferenceStation *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    ReferenceStationPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        ReferenceStation *out,
        const ReferenceStation *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    ReferenceStationPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const ReferenceStation *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    ReferenceStationPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        ReferenceStation **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    ReferenceStationPlugin_deserialize_from_cdr_buffer(
        ReferenceStation *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    ReferenceStationPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    ReferenceStationPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    ReferenceStationPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    ReferenceStationPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    ReferenceStationPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        ReferenceStation ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    ReferenceStationPlugin_new(void);

    NDDSUSERDllExport extern void
    ReferenceStationPlugin_delete(struct PRESTypePlugin *);

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct PositionData_t
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct PositionData_t)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * PositionData_t must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct PositionData_t.
    */
    typedef class PositionData_t PositionData_tKeyHolder;

    #define PositionData_tPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define PositionData_tPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define PositionData_tPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define PositionData_tPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define PositionData_tPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define PositionData_tPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define PositionData_tPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PositionData_t*
    PositionData_tPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern PositionData_t*
    PositionData_tPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern PositionData_t*
    PositionData_tPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    PositionData_tPluginSupport_copy_data(
        PositionData_t *out,
        const PositionData_t *in);

    NDDSUSERDllExport extern void 
    PositionData_tPluginSupport_destroy_data_w_params(
        PositionData_t *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    PositionData_tPluginSupport_destroy_data_ex(
        PositionData_t *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    PositionData_tPluginSupport_destroy_data(
        PositionData_t *sample);

    NDDSUSERDllExport extern void 
    PositionData_tPluginSupport_print_data(
        const PositionData_t *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern PositionData_t*
    PositionData_tPluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern PositionData_t*
    PositionData_tPluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    PositionData_tPluginSupport_destroy_key_ex(
        PositionData_tKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    PositionData_tPluginSupport_destroy_key(
        PositionData_tKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    PositionData_tPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    PositionData_tPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    PositionData_tPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    PositionData_tPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    PositionData_tPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        PositionData_t *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    PositionData_tPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        PositionData_t *out,
        const PositionData_t *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    PositionData_tPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const PositionData_t *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    PositionData_tPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        PositionData_t **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    PositionData_tPlugin_deserialize_from_cdr_buffer(
        PositionData_t *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    PositionData_tPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    PositionData_tPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    PositionData_tPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    PositionData_tPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    PositionData_tPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        PositionData_t ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    PositionData_tPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        PositionData_tKeyHolder *key, 
        const PositionData_t *instance);

    NDDSUSERDllExport extern RTIBool 
    PositionData_tPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        PositionData_t *instance, 
        const PositionData_tKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    PositionData_tPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    PositionData_tPlugin_new(void);

    NDDSUSERDllExport extern void
    PositionData_tPlugin_delete(struct PRESTypePlugin *);

} /* namespace GNSS  */
namespace Vehicle {

    #define EnginePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define EnginePlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define EnginePlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define EnginePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define EnginePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern Engine*
    EnginePluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern Engine*
    EnginePluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Engine*
    EnginePluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    EnginePluginSupport_copy_data(
        Engine *out,
        const Engine *in);

    NDDSUSERDllExport extern void 
    EnginePluginSupport_destroy_data_w_params(
        Engine *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    EnginePluginSupport_destroy_data_ex(
        Engine *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    EnginePluginSupport_destroy_data(
        Engine *sample);

    NDDSUSERDllExport extern void 
    EnginePluginSupport_print_data(
        const Engine *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    EnginePlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    EnginePlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    EnginePlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    EnginePlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    EnginePlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        Engine *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    EnginePlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        Engine *out,
        const Engine *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    EnginePlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Engine *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    EnginePlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        Engine **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    EnginePlugin_deserialize_from_cdr_buffer(
        Engine *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    EnginePlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    EnginePlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    EnginePlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    EnginePlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    EnginePlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Engine ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    EnginePlugin_new(void);

    NDDSUSERDllExport extern void
    EnginePlugin_delete(struct PRESTypePlugin *);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    WheelPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    WheelPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    WheelPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* ----------------------------------------------------------------------------
    Support functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern void
    WheelPluginSupport_print_data(
        const Wheel *sample,
        const char *desc,
        unsigned int indent_level);

    #define Wheel_SpeedPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define Wheel_SpeedPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define Wheel_SpeedPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define Wheel_SpeedPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define Wheel_SpeedPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern Wheel_Speed*
    Wheel_SpeedPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern Wheel_Speed*
    Wheel_SpeedPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Wheel_Speed*
    Wheel_SpeedPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    Wheel_SpeedPluginSupport_copy_data(
        Wheel_Speed *out,
        const Wheel_Speed *in);

    NDDSUSERDllExport extern void 
    Wheel_SpeedPluginSupport_destroy_data_w_params(
        Wheel_Speed *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    Wheel_SpeedPluginSupport_destroy_data_ex(
        Wheel_Speed *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    Wheel_SpeedPluginSupport_destroy_data(
        Wheel_Speed *sample);

    NDDSUSERDllExport extern void 
    Wheel_SpeedPluginSupport_print_data(
        const Wheel_Speed *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    Wheel_SpeedPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    Wheel_SpeedPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    Wheel_SpeedPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    Wheel_SpeedPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    Wheel_SpeedPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        Wheel_Speed *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    Wheel_SpeedPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        Wheel_Speed *out,
        const Wheel_Speed *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    Wheel_SpeedPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Wheel_Speed *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    Wheel_SpeedPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        Wheel_Speed **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Wheel_SpeedPlugin_deserialize_from_cdr_buffer(
        Wheel_Speed *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    Wheel_SpeedPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Wheel_SpeedPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Wheel_SpeedPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Wheel_SpeedPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Wheel_SpeedPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Wheel_Speed ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    Wheel_SpeedPlugin_new(void);

    NDDSUSERDllExport extern void
    Wheel_SpeedPlugin_delete(struct PRESTypePlugin *);

    #define DynamicsPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define DynamicsPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define DynamicsPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define DynamicsPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define DynamicsPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern Dynamics*
    DynamicsPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern Dynamics*
    DynamicsPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Dynamics*
    DynamicsPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    DynamicsPluginSupport_copy_data(
        Dynamics *out,
        const Dynamics *in);

    NDDSUSERDllExport extern void 
    DynamicsPluginSupport_destroy_data_w_params(
        Dynamics *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    DynamicsPluginSupport_destroy_data_ex(
        Dynamics *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    DynamicsPluginSupport_destroy_data(
        Dynamics *sample);

    NDDSUSERDllExport extern void 
    DynamicsPluginSupport_print_data(
        const Dynamics *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    DynamicsPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    DynamicsPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    DynamicsPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    DynamicsPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    DynamicsPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        Dynamics *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    DynamicsPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        Dynamics *out,
        const Dynamics *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    DynamicsPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Dynamics *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    DynamicsPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        Dynamics **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    DynamicsPlugin_deserialize_from_cdr_buffer(
        Dynamics *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    DynamicsPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    DynamicsPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    DynamicsPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    DynamicsPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    DynamicsPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Dynamics ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    DynamicsPlugin_new(void);

    NDDSUSERDllExport extern void
    DynamicsPlugin_delete(struct PRESTypePlugin *);

    #define VehicleData_tPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define VehicleData_tPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define VehicleData_tPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define VehicleData_tPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define VehicleData_tPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern VehicleData_t*
    VehicleData_tPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern VehicleData_t*
    VehicleData_tPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern VehicleData_t*
    VehicleData_tPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    VehicleData_tPluginSupport_copy_data(
        VehicleData_t *out,
        const VehicleData_t *in);

    NDDSUSERDllExport extern void 
    VehicleData_tPluginSupport_destroy_data_w_params(
        VehicleData_t *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    VehicleData_tPluginSupport_destroy_data_ex(
        VehicleData_t *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    VehicleData_tPluginSupport_destroy_data(
        VehicleData_t *sample);

    NDDSUSERDllExport extern void 
    VehicleData_tPluginSupport_print_data(
        const VehicleData_t *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    VehicleData_tPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    VehicleData_tPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    VehicleData_tPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    VehicleData_tPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    VehicleData_tPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        VehicleData_t *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    VehicleData_tPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        VehicleData_t *out,
        const VehicleData_t *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    VehicleData_tPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const VehicleData_t *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    VehicleData_tPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        VehicleData_t **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    VehicleData_tPlugin_deserialize_from_cdr_buffer(
        VehicleData_t *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    VehicleData_tPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    VehicleData_tPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    VehicleData_tPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    VehicleData_tPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    VehicleData_tPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        VehicleData_t ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    VehicleData_tPlugin_new(void);

    NDDSUSERDllExport extern void
    VehicleData_tPlugin_delete(struct PRESTypePlugin *);

} /* namespace Vehicle  */
namespace Diagnostics {

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    DiagnosticType_ePlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    DiagnosticType_ePlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    DiagnosticType_ePlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* ----------------------------------------------------------------------------
    Support functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern void
    DiagnosticType_ePluginSupport_print_data(
        const DiagnosticType_e *sample,
        const char *desc,
        unsigned int indent_level);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    DiagnosticCode_ePlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    DiagnosticCode_ePlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    DiagnosticCode_ePlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* ----------------------------------------------------------------------------
    Support functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern void
    DiagnosticCode_ePluginSupport_print_data(
        const DiagnosticCode_e *sample,
        const char *desc,
        unsigned int indent_level);

    #define Diagnostic_tPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define Diagnostic_tPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define Diagnostic_tPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define Diagnostic_tPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define Diagnostic_tPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern Diagnostic_t*
    Diagnostic_tPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern Diagnostic_t*
    Diagnostic_tPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Diagnostic_t*
    Diagnostic_tPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    Diagnostic_tPluginSupport_copy_data(
        Diagnostic_t *out,
        const Diagnostic_t *in);

    NDDSUSERDllExport extern void 
    Diagnostic_tPluginSupport_destroy_data_w_params(
        Diagnostic_t *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    Diagnostic_tPluginSupport_destroy_data_ex(
        Diagnostic_t *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    Diagnostic_tPluginSupport_destroy_data(
        Diagnostic_t *sample);

    NDDSUSERDllExport extern void 
    Diagnostic_tPluginSupport_print_data(
        const Diagnostic_t *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    Diagnostic_tPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    Diagnostic_tPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    Diagnostic_tPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    Diagnostic_tPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    Diagnostic_tPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        Diagnostic_t *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    Diagnostic_tPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        Diagnostic_t *out,
        const Diagnostic_t *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    Diagnostic_tPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Diagnostic_t *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    Diagnostic_tPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        Diagnostic_t **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Diagnostic_tPlugin_deserialize_from_cdr_buffer(
        Diagnostic_t *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    Diagnostic_tPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Diagnostic_tPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Diagnostic_tPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Diagnostic_tPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Diagnostic_tPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Diagnostic_t ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    Diagnostic_tPlugin_new(void);

    NDDSUSERDllExport extern void
    Diagnostic_tPlugin_delete(struct PRESTypePlugin *);

} /* namespace Diagnostics  */

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* HSI_Standard_topicsPlugin_1006183393_h */

