#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/steven/rover_workspace/src/rqt_rover_gui"

# snsure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/steven/rover_workspace/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/steven/rover_workspace/install/lib/python2.7/dist-packages:/home/steven/rover_workspace/build/rqt_rover_gui/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/steven/rover_workspace/build/rqt_rover_gui" \
    "/usr/bin/python" \
    "/home/steven/rover_workspace/src/rqt_rover_gui/setup.py" \
    build --build-base "/home/steven/rover_workspace/build/rqt_rover_gui" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/steven/rover_workspace/install" --install-scripts="/home/steven/rover_workspace/install/bin"
