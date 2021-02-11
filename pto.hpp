#pragma once

#include <sx.dfs/dfs.hpp>

namespace pto {

    using eosio::asset;
    using eosio::symbol;
    using eosio::name;

    const name id = "pto"_n;
    const name code = "ptoswapaccts"_n;
    const std::string description = "PTO Swap Converter";

    /**
     * markets
     */
    typedef eosio::multi_index< "markets"_n, dfs::markets_row > markets;

    /**
     * ## STATIC `get_fee`
     *
     * Get total fee
     *
     * ### params
     *
     * - `{name} [code="ptoswapaccts"]` - code account
     *
     * ### returns
     *
     * - `{uint8_t}` - total fee (trade + protocol)
     *
     * ### example
     *
     * ```c++
     * const uint8_t fee = pto::get_fee();
     * // => 30
     * ```
     */
    static uint8_t get_fee( const name code = "ptoswapaccts"_n )
    {
        return 30;
    }

    /**
     * ## STATIC `get_reserves`
     *
     * Get reserves for a pair
     *
     * ### params
     *
     * - `{uint64_t} mid` - market id
     * - `{symbol} sort` - sort by symbol (reserve0 will be first item in pair)
     * - `{name} [code="ptoswapaccts"]` - code account
     *
     * ### returns
     *
     * - `{pair<asset, asset>}` - pair of reserve assets
     *
     * ### example
     *
     * ```c++
     * const uint64_t mid = 1;
     * const symbol sort = symbol{"EOS", 4};
     *
     * const auto [reserve0, reserve1] = pto::get_reserves( mid, sort );
     * // reserve0 => "52552.7608 EOS"
     * // reserve1 => "364519.3066 PTO"
     * ```
     */
    static std::pair<asset, asset> get_reserves( const uint64_t mid, const symbol sort, const name code = "ptoswapaccts"_n )
    {
        return dfs::get_reserves( mid, sort, code );
    }
}