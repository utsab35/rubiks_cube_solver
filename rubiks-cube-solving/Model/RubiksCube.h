// Created by Utsab Mandal

#ifndef RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H
#define RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H

#include "bits/stdc++.h"

using namespace std;

/*
 * A base class for all Rubik's Cube Model. There are various representation for Rubik's Cube.
 * Each one has it's own special ways of definitions. This class provides a shared functionality
 * between all models. This serves as a base class for all the models.
 * We'll benchmark all models and observe which one is better for performance.
 */



/*
 * This is the BASE CLASS for the various models of a rubiks cube like the 1d, 3d representations
 */

class RubiksCube {
public:
    // enums are used as they are basically a optionlist.

    // face could be any one of the below 6 types
    /*
     * 0 ---> Up
     * 1 ---> Left
     * 2 ---> Front
     * 3 ---> Right
     * 4 ---> Back
     * 5 ---> Down
     */
    enum class FACE {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };


    // colour could be any one of the below 6 types

    enum class COLOR {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };

    // move could be any one of the below 6 types
    enum class MOVE {
        L, LPRIME, L2,
        R, RPRIME, R2,
        U, UPRIME, U2,
        D, DPRIME, D2,
        F, FPRIME, F2,
        B, BPRIME, B2
    };


    /******* These all will be implemented in the derived classes which represents the various models ********/


    /*
     * Returns the color of the cell at (row, col) in face.
     * If Rubik's Cube face is pointing at you, then the row numbering starts from the
     * top to bottom, and column numbering starts from the left to right.
     *
     * The rows and columns are 0-indexed.
     * Face, row, and column index are the data given to the function
     */
    virtual COLOR getColor(FACE face, unsigned row, unsigned col) const = 0;



    /*
     * This function returns the first letter of the colour given
     * eg -> returns 'R' for the colour 'RED'
     */
    static char getColorLetter(COLOR color);



    /*
     * This function returns true if the Rubik Cube is solved, otherwise returns false.
     */
    virtual bool isSolved() const = 0;



    /*
     * Returns the move in the string format.
     */
    static string getMove(MOVE ind);



    /* The print function is defined in the base class and later this will be used in the derived classes
     *
     * Printing the Rubik Cube in Planar format.
     *
     *
     * U -> Up
     * F -> Front
     * R -> Right
     * B -> Back
     * D -> Down
     * L -> Left
     *
     * The cube is laid out as follows.
     *
     * The sides:
     *    U
     *  L F R B
     *    D
     *
     *
     * Color wise:
     *
     *          W W W
     *          W W W
     *          W W W
     *
     *  G G G   R R R   B B B   O O O
     *  G G G   R R R   B B B   O O O
     *  G G G   R R R   B B B   O O O
     *
     *          Y Y Y
     *          Y Y Y
     *          Y Y Y
     *
     * Row and Column Numberings are done in the following way :
     * rx -> row numbering
     * cx -> column numbering
     * bx -> both row and column numbering
     *
     *             b0 c1 c2
     *             r1  .  .
     *             r2  .  .
     *
     *  b0 c1 c2   b0 c1 c2   b0 c1 c2   b0 c1 c2
     *  r1  .  .   r1  .  .   r1  .  .   r1  .  .
     *  r2  .  .   r2  .  .   r2  .  .   r2  .  .
     *
     *             b0 c1 c2
     *             r1  .  .
     *             r2  .  .
     *
     */
    void print() const;




    /*
     * Randomly shuffle the cube with 'times' moves and returns a vector containing the moves performed to shuffle the cube, in order
     */
    vector<MOVE> randomShuffleCube(unsigned int times);

    /*
     * Perform moves on the Rubik Cube
     */
    RubiksCube &move(MOVE ind);

    /*
     * Invert a move
     */
    RubiksCube &invert(MOVE ind);

    /*
     *  mentioning the 18 different fundamental operations in a rubiks cube
     *
     * F, F’, F2,
     * U, U’, U2,
     * L, L’, L2,
     * D, D’, D2,
     * R, R’, R2,
     * B, B’, B2
     */

    virtual RubiksCube &f() = 0;

    virtual RubiksCube &fPrime() = 0;

    virtual RubiksCube &f2() = 0;

    virtual RubiksCube &u() = 0;

    virtual RubiksCube &uPrime() = 0;

    virtual RubiksCube &u2() = 0;

    virtual RubiksCube &l() = 0;

    virtual RubiksCube &lPrime() = 0;

    virtual RubiksCube &l2() = 0;

    virtual RubiksCube &r() = 0;

    virtual RubiksCube &d() = 0;

    virtual RubiksCube &dPrime() = 0;

    virtual RubiksCube &d2() = 0;

    virtual RubiksCube &rPrime() = 0;

    virtual RubiksCube &r2() = 0;

    virtual RubiksCube &b() = 0;

    virtual RubiksCube &bPrime() = 0;

    virtual RubiksCube &b2() = 0;

    string getCornerColorString(uint8_t ind) const;

    uint8_t getCornerIndex(uint8_t ind) const;

    uint8_t getCornerOrientation(uint8_t ind) const;
};


#endif //RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H
