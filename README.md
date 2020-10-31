# **`DFS`**

> Peripheral EOSIO smart contracts for interacting with PTO

## Dependencies

- [`sx.uniswap`](https://github.com/stableex/sx.uniswap)
- [`sx.dfs`](https://github.com/stableex/sx.dfs)

## Quickstart

```c++
#include <sx.pto/pto.hpp>
#include <sx.uniswap/uniswap.hpp>

// user input
const asset quantity = asset{10000, symbol{"EOS", 4}};
const uint64_t mid = 1; // EOS/PTO pair

// get reserves
const auto [ reserve_in, reserve_out ] = pto::get_reserves( mid, quantity.symbol );
const uint8_t fee = pto::get_fee();

// calculate out price
const asset out = uniswap::get_amount_out( quantity, reserves_in, reserves_out, fee );
// => "6.9446 PTO"
```

## Table of Content

- [STATIC `get_reserves`](#static-get_reserves)
- [STATIC `get_fee`](#static-get_fee)

## STATIC `get_reserves`

Get reserves for a pair

### params

- `{uint64_t} mid` - market id
- `{symbol} sort` - sort by symbol (reserve0 will be first item in pair)
- `{name} [code="ptoswapaccts"]` - code account

### returns

- `{pair<asset, asset>}` - pair of reserve assets

### example

```c++
const uint64_t mid = 1;
const symbol sort = symbol{"EOS", 4};

const auto [reserve0, reserve1] = pto::get_reserves( mid, sort );
// reserve0 => "52552.7608 EOS"
// reserve1 => "364519.3066 PTO"
```

## STATIC `get_fee`

Get total fee

### params

- `{name} [code="ptoswapaccts"]` - code account

### returns

- `{uint8_t}` - total fee (trade + protocol)

### example

```c++
const uint8_t fee = pto::get_fee();
// => 30
```