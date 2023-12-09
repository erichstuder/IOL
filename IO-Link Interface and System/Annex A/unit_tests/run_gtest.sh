#!/bin/bash

# make sure the tag is unique
TAG=$(echo ${PWD:1} | tr '[:upper:]' '[:lower:]' | tr -d '[:space:]')
WORKDIR=/usr/software
echo "building container, please wait (the first time this may take several minutes) ..."
docker build -t $TAG . >/dev/nul
docker run \
	--rm \
	--name gtest_$(date +%s) \
	--volume "${PWD}":${WORKDIR} \
	--workdir "${WORKDIR}" \
	-it $TAG \
	bash -c "cmake . && cmake --build . && ./unit_tests"
