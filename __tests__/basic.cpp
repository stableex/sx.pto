#include <eosio/eosio.hpp>

#include "../pto.hpp"

using namespace eosio;

class [[eosio::contract]] basic : public contract {

public:
    using contract::contract;

    [[eosio::action]]
    void getreserves( const uint64_t pair_id, const symbol sort )
    {
        const auto [ reserveIn, reserveOut] = pto::get_reserves(pair_id, sort );
        print( reserveIn );
        print( reserveOut );
    }

    [[eosio::action]]
    void getfee() {
        const uint8_t fee = pto::get_fee();
        print( fee );
    }
};