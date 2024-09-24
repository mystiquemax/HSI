#include <dds/core/QosProvider.hpp>
#include <dds/domain/ddsdomain.hpp>
#include "Discovery_Timing_Tests_dp.hpp"
#include "app_utils.hpp"

void main()
{
    application::setup_signal_handlers();
    rti::core::QosProviderParams provider_params;
    provider_params.url_profile({"InformationModel/HSI_Standard_topics.xml"
                ,"InformationModel/Timing_Test.xml" });
    rti::core::default_qos_provider_params(provider_params);
    rti::domain::register_type<DeviceInformation::DeviceElement_t>("DeviceElement_t");

    std::cout << "Please enter number of running applications:" << std::endl;
    std::string input;
    std::cin >> input;
    int num_expected_applications;
    try {
        num_expected_applications = std::stoi(input);
    }
    catch (std::exception const& e)
    {
        throw std::runtime_error("Argument for the number of running applications!");
    }

    Timing_Tests_dp dp(10, 10, num_expected_applications, "Timing_Test::Timing_Test_dp");
    dp.start_test();

    bool is_done = false;
    while (application::run_application)
    {
        if (dp.is_finished() && !is_done)
        {
            std::cout << "Done" << std::endl;
            is_done = true;
        }
    }
    
    if (dp.is_finished())
    {
        std::cout << "Reader's matching times: " << std::endl;
        for (const auto& time : dp.get_readers_microseconds_matching_times())
        {
            std::cout << time << " microseconds" << std::endl;
        }

        std::cout << "Writer's matching times: " << std::endl;
        for (const auto& time : dp.get_writers_microseconds_matching_times())
        {
            std::cout << time << " microseconds" << std::endl;
        }
    }

    dp.stop_test();
 }