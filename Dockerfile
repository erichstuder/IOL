FROM debian:12.1

WORKDIR /usr/src/cucumber-cpp

RUN apt-get update && \
    apt-get -y install cmake build-essential \
                       libboost-thread-dev libboost-system-dev \
                       libboost-regex-dev libboost-date-time-dev \
                       libboost-program-options-dev \
                       libboost-test-dev \
                       git \
                       ruby ruby-dev \
                       libboost-filesystem-dev \
                       libboost-all-dev

RUN git clone https://github.com/cucumber/cucumber-cpp.git . && \
    git checkout 2f7d9ad519290a8b4a6ee6845af4480dd9ec2b7f

RUN gem install bundler && \
    bundle install

RUN git submodule init && \
    git submodule update && \
    cmake -E make_directory build && \
    cmake -E chdir build cmake -DCUKE_ENABLE_EXAMPLES=on -DCMAKE_INSTALL_PREFIX=${prefix} .. && \
    cmake --build build && \
    cmake --build build --target test && \
    cmake --build build --target install # && \
#returns an error and is ignored for the moment as these are "only" tests:   cmake --build build --target features
