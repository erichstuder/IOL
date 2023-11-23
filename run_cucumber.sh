#!/bin/bash

# make sure the tag is unique
TAG=$(echo ${PWD:1} | tr '[:upper:]' '[:lower:]' | tr -d '[:space:]')
VOLUME_DIR=/usr/software

cmake_command='
	set -e
	cmake '${VOLUME_DIR}'
	cmake --build .'

cuke_execute='
	feature_path=$(find -P ../.. -name ${feature_file})
	./${executable} >/dev/null &
	cucumber "${feature_path}"'


if [ $# -eq 0 ]
then
	cuke_command_variable='
	for executable in steps/*; do
		echo executable: ${executable}
		feature_file=${executable:6:-7}.feature
		'${cuke_execute}'
	done'
fi

if [ $# -eq 1 ]
then
	cuke_command_variable='
	feature_file='$1'
	executable=steps/${feature_file::-8}__steps
	'${cuke_execute}'
	'
fi



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
	bash -c "${cmake_command} ${cuke_command_variable}"
