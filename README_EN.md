# Splines
## Welcome to the Bezier splines project! This project offers a simple and convenient way to create and visualize Bezier splines using a custom high-level visualization library [`TESTWIN32APP_GRAPHICAPP`](https://github.com/quqveik1/TESTWIN32_GRAPHICAPP).

## Features of the Program
- Users can click on the screen to set control points for the splines.
- If a mistake is made, the user can clear the screen and select new control points.

<img src="https://user-images.githubusercontent.com/64206443/235349246-40d57425-71fa-4c71-8611-0360a097dc5b.png" width="600">

## Technical Components

The project consists of two main classes:

### 1. SplineArr

`SplineArr` is a class that stores the key points of the spline and provides functions to work with them.
The main idea behind this class is that it can generate intermediate points if you pass non-integer numbers to operator[]. If you call operator[] with integer values, the control points will be returned.

- `keyPoints`: vector of the spline's key points
- `calcPoint(double dindex)`: calculates a point on the spline using a fractional index
- `size() const`: returns the number of key points of the spline
- `push(Vector point)`: adds a new key point to the spline
- `sortedPush(Vector point)`: adds a new key point to the spline and sorts the points
- `sort()`: sorts the spline's key points
- `clear()`: clears the spline (removes all key points)
- `operator[](size_t index)`: returns a reference to the key point with the specified index
- `operator[](double dindex)`: returns a spline point using a fractional index

### 2. SplineControl

`SplineControl` is derived from [`MultiLayCoordinatSystemWindow`](https://github.com/quqveik1/TESTWIN32_GRAPHICAPP/blob/main/MultiLayCoordinatSystemWindow.h) and provides functionality for user interaction and visualization management of Bezier splines. It has the following properties and methods:

- `splineArr`: `SplineArr` object containing the spline's key points
- `keyPointsColor`: color of key points
- `keyPointsLayIndex`: layer index where the key points will be displayed
- `keyPointsR`: radius of key points
- `interPolDelta`: interpolation delta for drawing splines
- `SplineControl(AbstractAppData* _app)`: class constructor
- `updateScreenPoints()`: updates screen points based on current spline key points
- `pushStartPoints()`: adds starting points for demonstration
- `onClick(Vector mp)`: mouse click event handler
- `onMessageRecieve(const char* name, void* data)`: message handler for selecting control points

--------------------------
# Instructions for Launching the Application on Windows
- Requirements: Windows 7 is required for the application to fully function.
- Download the application from this link: https://github.com/quqveik1/Splines/releases/latest
- Run the downloaded .exe file, ignoring antivirus warnings stating the program is dangerous.
In this window, you should click on this button.

<img src="https://user-images.githubusercontent.com/64206443/182945554-ed4d18c6-a25d-4d0d-a331-e268643b3031.png" width="400">

- The application installer will open; follow its instructions.
