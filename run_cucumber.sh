#!/bin/bash

while getopts c:f:C flag
do
    case "${flag}" in
        c) cmake_params=${OPTARG};;
        f) feature=${OPTARG};;
	C) colored=t;;
    esac
done

# make sure the TAG is unique by using PWD
TAG=$(echo ${PWD:1} | tr '[:upper:]' '[:lower:]' | tr -d '[:space:]')
VOLUME_DIR=/usr/software

cmake_command='
	set -e
	cmake '${VOLUME_DIR}'
	cmake --build . '${cmake_params}

cuke_execute='
	feature_path=$(find -P ../.. -name ${feature}.feature)
	./${executable} >/dev/null &
	cucumber "${feature_path}"'


if [[ -z "${feature}" ]]
then
	cuke_command_variable='
	for executable in steps/*; do
		echo executable: ${executable}
		feature=${executable:6:-7}
		'${cuke_execute}'
	done'
else
	cuke_command_variable='
	feature='${feature}'
	executable=steps/${feature}__steps
	'${cuke_execute}
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
	-i${colored} $TAG \
	bash -c "${cmake_command} ${cuke_command_variable}"
