FROM alpine:latest 

# These commands copy your files into the specified directory in the image
# and set that as the working location
COPY . /Users/oliver/Documents/GitHub/Lab3/
WORKDIR /Users/oliver/Documents/GitHub/Lab3/

#RUN apt-get update
#RUN apt-get install -y valgrind
#RUN apt-get install -y build-essential

RUN apk add --allow-untrusted valgrind
RUN apk add build-base

LABEL name="dependencies"