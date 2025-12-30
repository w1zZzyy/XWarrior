FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    clangd \
    clang-format \
    git \
    libboost-all-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace