#pragma once

#include "core/module.h"
#include "instruments/msumr/msumr_reader.h"
#include "instruments/mtvza/mtvza_reader.h"

namespace meteor
{
    namespace instruments
    {
        class MeteorInstrumentsDecoderModule : public ProcessingModule
        {
        protected:
            std::atomic<size_t> filesize;
            std::atomic<size_t> progress;

            // Readers
            msumr::MSUMRReader msumr_reader;
            mtvza::MTVZAReader mtvza_reader, mtvza_reader2;

            // Statuses
            instrument_status_t msumr_status = DECODING;
            instrument_status_t mtvza_status = DECODING;

        public:
            MeteorInstrumentsDecoderModule(std::string input_file, std::string output_file_hint, nlohmann::json parameters);
            void process();
            void drawUI(bool window);

        public:
            static std::string getID();
            virtual std::string getIDM() { return getID(); };
            static std::vector<std::string> getParameters();
            static std::shared_ptr<ProcessingModule> getInstance(std::string input_file, std::string output_file_hint, nlohmann::json parameters);
        };
    } // namespace amsu
} // namespace Meteor