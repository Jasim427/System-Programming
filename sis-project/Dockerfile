FROM ubuntu:22.04

RUN apt update && apt install -y \
    g++ \
    cmake \
    libpqxx-dev

WORKDIR /app

COPY . .

CMD ["bash"]
