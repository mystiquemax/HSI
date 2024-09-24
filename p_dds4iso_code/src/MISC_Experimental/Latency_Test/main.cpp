#include <dds/core/QosProvider.hpp>
#include <thread>
#include "Latency_Tests_dp.hpp"
#include "app_utils.hpp"

void main(int argc, char* argv[])
{
    application::setup_signal_handlers();
    bool is_tester = false;
    unsigned int num_latency_messages = 1;
    // Command line argument is number of tries for latency tests
    if (argc >= 3)
    {
        try {
            num_latency_messages = std::stoi(argv[2]);
        }
        catch (std::exception const& e)
        {
            throw std::runtime_error("Invalid command-line argument for the number of messages in latency test!");
        }

        std::string argument(argv[1]);
        if (argument == "Tester" || argument == "tester")
        {
            is_tester = true;
        }
    }
    else if (argc > 1)
    {
        std::cout << "Wrong command line arguments given. Either none for refector or: \"tester <num_messages>\" for tester!"<<std::endl;
        return;
    }

    rti::core::QosProviderParams provider_params;
    provider_params.url_profile({"InformationModel/HSI_Standard_topics.xml"
                , "InformationModel/Timing_Test.xml" });
    rti::core::default_qos_provider_params(provider_params);
    rti::domain::register_type<DeviceInformation::DeviceElement_t>("DeviceElement_t");


    if (is_tester)
    {
        Latency_Tests_dp latency_tester(num_latency_messages, "Timing_Test::Latency_Tester_dp");

        latency_tester.conduct_latency_test();

        while (!latency_tester.is_done() && application::run_application)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }

        latency_tester.stop_logic();

        if (latency_tester.is_done())
        {
            std::cout << "Round-Trip-Time results after " << num_latency_messages << " latency-messages:" << std::endl;
            for (const auto& latency_time : latency_tester.get_latency_times())
            {
                std::cout << latency_time <<" microseconds"<< std::endl;
            }
        }
    }
    else
    {
        Latency_Tests_Reflector_dp latency_reflector("Timing_Test::Latency_Reflector_dp");

        while (application::run_application);
        latency_reflector.stop_logic();
    }
}