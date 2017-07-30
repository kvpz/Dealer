#!/bin/bash

# where the JSON response will reside
models='bmw_models.json'

# https://www.bmwusa.com/api/byo/models
curlcmd="curl 'https://www.bmwusa.com/api/byo/models' -H 'Pragma: no-cache'  -H 'DNT: 1' -H 'Accept-Encoding: gzip, deflate, br' -H 'Accept-Language: en-US,en;q=0.8' -H 'User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/59.0.3071.115 Safari/537.36' -H 'Accept: application/json, text/plain, */*' -H 'Cache-Control: no-cache' -H 'Referer: https://www.bmwusa.com/byo.html' -H 'source-identifier: byo' -H 'Connection: keep-alive' --compressed"

# get model codes
if [ $1 = "-c" ]; then
    if [ $(find -name $models) ]; then
	#modelcodes=$(cat $models | grep "naModelCode")
	#echo $modelcodes
	python ./bmwmodels.py
    else
	echo "Creating new bmw_models.json from uri..."
	$(eval $curlcmd | python -m json.tool > $models) 
    fi
    
elif [ $1 = "-a" ]; then
    echo "Getting "
fi
