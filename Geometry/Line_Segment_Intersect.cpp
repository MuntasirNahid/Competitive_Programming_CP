/*
https://youtu.be/bbTqI0oqL5U

Given two line segments(p1,q1) and (p2,q2),find if the given line segments intersect with each other


1)
                    p3
                    |
                   |
                  |
p1 --------------|----------------------- p2
                |
               |
              |
            p4

in this case general cases means p3 is in counter clockwise side of line p1p2's point p2 , and p4 is in clockwise side of line p1p2's point p2.
which means their orientation is different. ONe is clockwise and other is counter clockwise

p3(p1p2)=AC(p3 from p2)
p4(p1p2)=C

again,
p1(p3p4)= C(p1,from p4)
p2(p3p4)AC

same goes for counter case. p1 is in clockwise and p2 is in anticlockwise from p3p4's p4 point

if both were in same direction,then both lines will never intersect


2)
                        p3
p1 ----------------------|--------------------------p2
                        |
                       |
                      |
                    p4

here p1(p3p4)=clockwise(orientation of p1 from point p4)
    p2(p3p4)=anti-clockwise

p4(p1p2)=cloclwise
p3(p1p2)=0( theta =180, sintheta =0)

when theta is equal to zero.we will always assume that it is opposite to the previous orientation(p4(p1p2))
so,p3(p1p2)=anti-clockwise



3)Collinear

p1----------p2 p3-------------p4 , p1-------p3-----p2------p4

orientation =0 , as theta=180
 so in both cases cross product will be =0(as sin 180=0)

when the orientation is zero, we know that they are collinear. now we have to determine wheather they overlap or not overlap

1)if either p3 lies in range of (p1p2)
 or p4 lies in the range of (p1p2)

 then overlapping

else
 no overlap so no intersection.



4)Not intersecting:

p1 --------------------p2
            p4
            |
            |
            |
            |
            p3

p1(p3p4)=AC
p2(p3p4)=C

but
p4(p1p2)=C
p3(p1p2)=C

so no intersection.

--------------------------------------##----------------------

The orientation of a point p2 from a vector p0p1 means if we want to reach p2 from p1,whether we have to move clock-wise or counter clockwise.

if cross product of vector p2p1 and p2p0= (+) ve
    then p2 is clockwise from p0
         p2 is clockwise from p1

else if coss product is= (-)ve
    then p2 is anticlockwise from p0
         p2 is anticlockwise from p1

determinant formula : p2p1 * p2p0=(x2-x1)(y0-y2) -(x0-x2)(y1-y2)


*/
#include <iostream>
using namespace std;

struct Point
{
    int x;
    int y;
};

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;

    return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/
    // for details of below formula.
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0; // colinear

    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1))
        return true;

    // p1, q1 and q2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1))
        return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2))
        return true;

    // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2))
        return true;

    return false; // Doesn't fall in any of the above cases
}

// Driver program to test above functions
int main()
{
    struct Point p1 = {1, 1}, q1 = {10, 1};
    struct Point p2 = {1, 2}, q2 = {10, 2};

    cout << "Does They Intersect?" << endl
         << "-";
    doIntersect(p1, q1, p2, q2) ? cout << "Yes\n" : cout << "No\n";

    p1 = {10, 0}, q1 = {0, 10};
    p2 = {0, 0}, q2 = {10, 10};
    cout << "Does They Intersect?" << endl
         << "-";
    doIntersect(p1, q1, p2, q2) ? cout << "Yes\n" : cout << "No\n";

    p1 = {-5, -5}, q1 = {0, 0};
    p2 = {1, 1}, q2 = {10, 10};
    cout << "Does They Intersect?" << endl
         << "-";
    doIntersect(p1, q1, p2, q2) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}