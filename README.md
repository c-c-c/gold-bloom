# gold-bloom

# Sakura Bloom

‘Bloom’ is an art installation celebrating Spring, which is visually represented through a graphic abstraction of cherry blossom flowers and tree branches.


## Getting Started

The input for the system is a leap motion sensor. This enables the piece to be interactive, in that the participants’ gestures are used like a brush to construct the tree. The path of the hand movements builds the tree trunk, while simultaneously generating cherry blossom flowers around it of various sizes.
As the output of the system is the graphic representation of the cherry blossom tree, the piece is projected on a wall from a laptop for maximum effect.
Participants can clear the canvas and export their creation through the use of specific gestures or a keyboard (see doc).


### Prerequisites 

You will need :

* A Developer License from LeapMotion - [Sign up here](https://www.leapmotion.com/developers)
* Leap Software software, I'm using V2 tracking for OSX support - [Download SDK](https://developer.leapmotion.com/sdk/v2)
* openFrameworks - [Download toolkit](http://openframeworks.cc/)
* A copy of the ofxLeapMotion2 addon - [Download source](http://github.com/genekogan/ofxLeapMotion2). Or run : 

```
git clone git://github.com/genekogan/ofxLeapMotion2.git
```

### Installing

Place the addon ofxLeapMotion2:

```
openFrameworks/addons/ofxLeapMotion2/
```

And make sure the .h and .cpp files are correctly linked in your core files.


## Running the project

### OSX

Xcode: Open the Xcode project file, select the "leapMotionExample Debug" scheme, and hit "Run".

## Built With

* [openFrameworks](http://openframeworks.cc/) - open source C++ toolkit for creative coding
* [Xcode](https://developer.apple.com/xcode/) - IDE
* [Leap Motion SDK](https://developer.leapmotion.com/sdk/v2) - V2 Tracking built for OSX support 
* [ofxLeapMotion2](https://github.com/genekogan/ofxLeapMotion2) - wrapper for the Leap Motion SDK compatible with Leap 2.0 Beta with skeletal tracking 


## Authors

* **Celine Chappert** - *Design & Code* - [Personal Website](https://www.celinechappert.com)


## Acknowledgments

* Hat tip to anyone who's code was used
* Inspiration
* etc

