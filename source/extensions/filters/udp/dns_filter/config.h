#pragma once

#include "envoy/config/filter/udp/dns_filter/v2alpha/dns_filter.pb.h"
#include "envoy/config/filter/udp/dns_filter/v2alpha/dns_filter.pb.validate.h"
#include "envoy/server/filter_config.h"

#include "extensions/filters/udp/dns_filter/dns_filter.h"

namespace Envoy {
namespace Extensions {
namespace UdpFilters {
namespace DnsFilter {

/**
 * Config registration for the UDP proxy filter. @see NamedUdpListenerFilterConfigFactory.
 */
class DnsFilterConfigFactory : public Server::Configuration::NamedUdpListenerFilterConfigFactory {
public:
  // NamedUdpListenerFilterConfigFactory
  Network::UdpListenerFilterFactoryCb
  createFilterFactoryFromProto(const Protobuf::Message& config,
                               Server::Configuration::ListenerFactoryContext& context) override;

  ProtobufTypes::MessagePtr createEmptyConfigProto() override;
  std::string name() const override;
};

} // namespace DnsFilter
} // namespace UdpFilters
} // namespace Extensions
} // namespace Envoy
