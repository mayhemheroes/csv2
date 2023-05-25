FROM --platform=linux/amd64 ubuntu:20.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential clang cmake

COPY . /repo
WORKDIR /repo/build
RUN CC=clang CXX=clang++ cmake ..
RUN make install
WORKDIR /repo/mayhem/build
RUN CC=clang CXX=clang++ cmake ..
RUN make

FROM ubuntu:20.04 as package
RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libreadline-dev
COPY --from=builder /repo/mayhem/build/fuzz_csv2parse /fuzz_csv2parse
COPY --from=builder /repo/test/inputs /testsuite
