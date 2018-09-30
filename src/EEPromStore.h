#pragma once
#include "Settings.h"
#include "stdint.h"

struct blobData_t {
    float m_hue;
    float m_saturation;
    float m_brightness;
    float m_white1;
    float m_white2;
    uint16_t m_filters;
    uint32_t m_remoteBase;
    bool     m_power;
    float m_onBrightness;
};

class EEPromStore final : public Settings {
private:
    const uint16_t m_eepromAddress;

public:
    EEPromStore(const uint16_t p_eepromAddress, const uint32_t p_debounceWaitTime, const uint32_t p_commitWaitTime);
    SettingsDTO get() const;

private:
    virtual void store(const SettingsDTO& settings) override;

    blobData_t getBlob() const;
    void storeBlob(const blobData_t& p_blob) const;

    uint16_t crc16(uint8_t* a, uint16_t length) const;
    uint16_t crc16Update(uint16_t crc, uint8_t a) const;
};
