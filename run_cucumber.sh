#!/bin/bash

# make sure the tag is unique
TAG=$(echo ${PWD:1} | tr '[:upper:]' '[:lower:]' | tr -d '[:space:]')
VOLUME_DIR=/usr/software
echo "building container, please wait (the first time this may take several minutes) ..."
docker build -t $TAG . >/dev/nul

BUILD_DIR=/tmp/cucumber_build
mkdir -p ${BUILD_DIR}
docker run \
	--rm \
	--name cucumber_$(date +%s) \
	--volume "${PWD}":${VOLUME_DIR} \
	--workdir "${VOLUME_DIR}${BUILD_DIR}" \
	-it $TAG \
	bash -c '
		cmake '${VOLUME_DIR}'
		cmake --build .
		for executable in steps/*; do
			feature_file=${executable:6:-7}.feature
			feature_path=$(find -P ../.. -name ${feature_file})
			cucumber "${feature_path}"
		done
		'
