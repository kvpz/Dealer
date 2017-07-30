#!/bin/bash
# Get specific details about a model and the features that it can be
# customized with from factory.
# https://www.bmwusa.com/api/byo/models/<naModelCode>/configuration/33157
# download json if it hasn't been downloaded

function get_car_features(){
if [[ !(-f "$1.json") ]]; then
curl 'https://www.bmwusa.com/api/byo/models/'"$1"'/configuration' -H 'Pragma: no-cache' -H 'Origin: https://www.bmwusa.com' -H 'Accept-Encoding: gzip, deflate, br' -H 'Accept-Language: en-US,en;q=0.8' -H 'User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/59.0.3071.115 Safari/537.36' -H 'Content-Type: application/json;charset=UTF-8' -H 'Accept: application/json, text/plain, */*' -H 'Cache-Control: no-cache' -H 'Referer: https://www.bmwusa.com/byo.html' -H 'source-identifier: byo' -H 'Connection: keep-alive' -H 'DNT: 1' --data-binary '{"sessionId":"8621586e-38d4-440a-a9fa-5bf1e62c0519"}' --compressed | python -mjson.tool > "$1.json"
fi
}

#get_car_features $1
for model in $(python ./bmwmodels.py); do
    get_car_features $model
done

    
