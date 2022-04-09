FROM alpine
RUN apk add clang
RUN apk add vim
RUN apk add make
ADD ./nm /nm
ADD ./cmd.sh /cmd.sh
RUN /cmd.sh
RUN echo 'alias gcc="clang' >> ~/.bashrc
