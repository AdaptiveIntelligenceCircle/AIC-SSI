#include "dht_storage.h"

namespace aic::ssi::storage::distributed {

DHTStorage::DHTStorage(const std::string& nodeId)
    : m_nodeId(nodeId) {}

bool DHTStorage::put(const std::string& key, const std::string& value) {
    (void)key;
    (void)value;
    // TODO: integrate real DHT
    return false;
}

bool DHTStorage::get(const std::string& key, std::string& out) {
    (void)key;
    (void)out;
    return false;
}

bool DHTStorage::remove(const std::string& key) {
    (void)key;
    return false;
}

bool DHTStorage::exists(const std::string& key) {
    (void)key;
    return false;
}

std::vector<std::string> DHTStorage::listKeys(const std::string& prefix) {
    (void)prefix;
    return {};
}

} // namespace aic::ssi::storage::distributed