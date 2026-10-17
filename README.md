# LRU-Cache-Implementation-CPP
Efficient LRU Cache implementation in C++ using HashMap and Doubly Linked List with O(1) operations.
# LRU Cache Visualizer

A C++ implementation of the **Least Recently Used (LRU) Cache** algorithm using a hash map and a doubly linked list. This project demonstrates efficient cache management with **O(1) average time complexity** for `get()` and `put()` operations.

## Overview

An LRU Cache stores a limited number of key-value pairs. When the cache reaches its capacity, it removes the least recently used entry to make space for a new one.

This project implements the LRU caching mechanism and displays the cache order from Most Recently Used (MRU) to Least Recently Used (LRU).

## Features

- Insert and update key-value pairs.
- Retrieve values using keys.
- Automatically evict the least recently used entry when the cache is full.
- Display cache contents in MRU-to-LRU order.
- Efficient lookups using `unordered_map`.
- Efficient cache ordering using a doubly linked list.
- C++17 compatible implementation.

## Technologies Used

- C++
- C++ Standard Template Library (STL)
- `unordered_map`
- `list`
- CMake

## How It Works

The implementation uses two data structures:

1. **Hash Map (`unordered_map`)**: Maps each key to its corresponding node in the linked list.
2. **Doubly Linked List (`list`)**: Maintains entries in usage order, with the most recently used entry at the front and the least recently used entry at the back.

### Cache Operations

- `get(key)`: Returns the value associated with the key and moves the entry to the front. Returns `-1` if the key is absent.
- `put(key, value)`: Inserts a new entry or updates an existing entry. If the cache is full, the least recently used entry is removed.

## Example

For a cache with capacity `3`:

```cpp
LRUCache lru(3);

lru.put(1, 100);
lru.put(2, 200);
lru.put(3, 300);

lru.get(1);
lru.put(4, 400);
lru.display();
```

Output:

```text
MRU -> LRU: [4:400] [
