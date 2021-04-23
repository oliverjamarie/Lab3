FROM dependencies:latest

# These commands copy your files into the specified directory in the image
# and set that as the working location
COPY  . /Users/oliver/Documents/GitHub/Lab3/

WORKDIR /Users/oliver/Documents/GitHub/Lab3/

#RUN apt-get update
#RUN apt-get install -y valgrind
# RUN apt-get install -y build-essential

RUN g++ -o Experiment1A Experiment1A.cpp
RUN g++ -o Experiment1B Experiment1B.cpp
RUN g++ -o Experiment2A Experiment2A.cpp
RUN g++ -o Experiment2B Experiment2B.cpp

RUN chmod +x runExperiments.sh runExp1A.sh runExp1B.sh runExp2B.sh runExp2A.sh


LABEL Name=lab3 Version=0.0.1