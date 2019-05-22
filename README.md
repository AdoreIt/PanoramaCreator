# PanoramaCreator
Drag and Drop panorama creator written with C++, Qt, OpenCV 

### OpenCV build and installation to separate folder on Ubuntu 18.04 LTS

#### Packages installation

```
sudo apt install build-essential
sudo apt install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
sudo apt install python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev
```

#### OpenCV cloning
```
mkdir opencv_sourses_build
cd opencv_sourses_build
mkdir build opencv_with_contrib_3.4.6

git clone https://github. com/opencv/opencv.git
git clone https://github.com/opencv/opencv_contrib.git

cd opencv
git checkout 3.4.6

cd ../opencv_contrib
git checkout 3.4.6
```

#### OpenCV build to dir

You can replace `~/` with you exact path
```
cd ../build

cmake \
-DCMAKE_INSTALL_PREFIX=~/opencv_sourses_build/opencv_with_contrib_3.4.6 \
-DOPENCV_EXTRA_MODULES_PATH=~/opencv_sourses_build/opencv_contrib/modules \
-DWITH_IPP=OFF -DWITH_CUDA=OFF -DBUILD_opencv_java=OFF ../opencv

make install -j4
```

#### Add to path to be able to find_package
Test example in https://github.com/AdoreIt/PanoramaCreator/tree/master/test_project
```
cd ..
mkdir -p test_project/build
cd test_project/build

export LD_LIBRARY_PATH=~/opencv_sourses_build/opencv_with_contrib_3.4.6/lib
export CMAKE_PREFIX_PATH=~/opencv_sourses_build/opencv_with_contrib_3.4.6
export PKG_CONFIG_PATH=~/opencv_sourses_build/opencv_with_contrib_3.4.6/lib/pkgconfig

cmake ..
make -j4
./opencv_test
```

#### Add to your CMakeLists.txt
Please take a look at the example in https://github.com/AdoreIt/PanoramaCreator/tree/master/test_project
```
find_package(OpenCV 3.4.6 REQUIRED)

...

target_link_libraries(opencv_test
	PRIVATE ${OpenCV_LIBS}
	)

target_include_directories(opencv_test
	PRIVATE ${OpenCV_INCLUDE_DIRS}
	)
```
