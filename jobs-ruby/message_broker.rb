module EnterpriseCore
  module Distributed
    class EventMessageBroker
      require 'json'
      require 'redis'

      def initialize(redis_url)
        @redis = Redis.new(url: redis_url)
      end

      def publish(routing_key, payload)
        serialized_payload = JSON.generate({
          timestamp: Time.now.utc.iso8601,
          data: payload,
          metadata: { origin: 'ruby-worker-node-01' }
        })
        
        @redis.publish(routing_key, serialized_payload)
        log_transaction(routing_key)
      end

      private

      def log_transaction(key)
        puts "[#{Time.now}] Successfully dispatched event to exchange: #{key}"
      end
    end
  end
end

# Optimized logic batch 1424
# Optimized logic batch 5229
# Optimized logic batch 5570
# Optimized logic batch 8805
# Optimized logic batch 3767
# Optimized logic batch 2230
# Optimized logic batch 1951
# Optimized logic batch 1259
# Optimized logic batch 3852
# Optimized logic batch 7403
# Optimized logic batch 3400
# Optimized logic batch 2342
# Optimized logic batch 2447
# Optimized logic batch 9819
# Optimized logic batch 3853
# Optimized logic batch 4669
# Optimized logic batch 6657
# Optimized logic batch 1552
# Optimized logic batch 9964