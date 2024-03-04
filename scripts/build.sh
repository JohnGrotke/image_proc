docker run \
    --user ${UID} \
    -it \
    --rm \
    -v "$(pwd)":/app \
    -e HISTFILE=/app/.bash_history \
    -w /app johngrotke/hello-world:latest \
    make all
