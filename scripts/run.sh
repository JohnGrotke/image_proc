
if [[ -z "${1}" ]]; then
    echo "command was empty. Defaulting to bash"
    command="bash"
else
    echo "Executing command ${1}"
    command=build/${1}
fi

docker run \
    --user ${UID} \
    -it \
    --rm \
    -v "$(pwd)":/app \
    -e HISTFILE=/app/.bash_history \
    -w /app johngrotke/hello-world:latest \
    ${command}
