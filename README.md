# OOP-Horse-Race

classDiagram

class Horse {
- int horsePosition
- int index
- int trackLength
+ Horse()
+ init(int index, int tracklength)
+ advance()
+ printLane()
+ isWinner() bool
}

class Race {
    - int NUM_HORSES
    - int TRACK_LENGTH
    + Horse hoses[]
    + Race()
    + start()
}

Race --> Horse
