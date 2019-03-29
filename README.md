=============================
GaussianBlur
=============================

This applies a Gaussian blur to a 256x256 image using a 5x5 Gaussian kernel. Regardless of whether or not the input image is in color, the output will be in black and white. Gaussian is an often used blurring algorithm, as it can be more powerful than a simple Average Blur. While a true Gaussian blur would in theory use every pixel in the image to calculate the blur on each individual pixel, this one only uses the 5 neighboring pixels for efficiency. In practical terms this makes almost no difference on the actual output image.


Introduction
------------

* This is a relatively simple implementation of the Gaussian blur algorithm for Maxeler dataflow computing.
* It uses a hard-coded kernel to run on uploaded images.


Usage
-----

* This application is currently only set to work on 256x256 images.
* The output is in black in white, even if the input was in color.


Features
--------

* More or less the entire process is inside a loop in the ControlFlow implementation, so it stands to gain considerable speed in the DataFlow implementation.


To-Do
-----

* Support for more image sizes
* Support for color image output
* Support for different levels of blur, ie more standard deviations
