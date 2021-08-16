#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
int day=1;
static float	x	= 0.0;
static float	y	= 0.0;
float p=-1200; ///For Car Moving At Day
float q=-1400; ///For Car Moving At sunset
float o=2400; ///For Car Moving At night
float sm=1120; ///For Sun Moving At Sunset
float bn=550; ///For  ForwardBoat Moving at day
float bns=600; ///For  ForwardBoat Moving at sunset
float bnr=1280; ///For Reverse Boat Moving at day
float cm=-1200; ///For Cloud Moving
float bm=-200; ///For bird Moving
///Skies
void sky(){ ///Day Sky
    glBegin(GL_POLYGON);
    glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
    glVertex3i(0, 900, 0);
    glVertex3i(1200, 900, 0);
    glVertex3i(1200, 1200, 0);
    glVertex3i(0, 1200, 0);
glEnd();
}


///Clouds
void rainy_clouds(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y)
{
    glColor3f(1.0f, 1.0f, 1.0f);
    int i=0;
    float angle;
    GLfloat PI= 2.0f * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(i=0; i<100; i++)
    {
        angle = 2 * PI * i/100;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)* ry));
    }
glEnd();
}
void sunset_sky(){ ///Evening Sky
    glBegin(GL_POLYGON);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3i(0, 900, 0);
    glVertex3i(1200, 900, 0);
    glVertex3i(1200, 1200, 0);
    glVertex3i(0, 1200, 0);
glEnd();
}
void night_sky(){ ///Night Sky
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
    glVertex3i(0, 900, 0);
    glVertex3i(1200, 900, 0);
    glVertex3i(1200, 1200, 0);
    glVertex3i(0, 1200, 0);
glEnd();
}
/// Three Birds
void bird(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y){ ///Bird 1
    glColor3f(1.0f,1.0f, 0.0f);
    int i=0;
    float angle;
    GLfloat PI= 2.0f * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(i=0; i<100; i++)
    {
        angle = 2 * PI * i/100;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)* ry));
    }
glEnd();
    glBegin(GL_TRIANGLES); ///Left Wing
    glColor3f(0.4f,0.4f,0.4f);
    glVertex3i(23+bm,1167,0);
    glVertex3i(28+bm,1187,0);
    glVertex3i(32+bm,1167,0);
glEnd();
    glBegin(GL_TRIANGLES); ///Right Wing
    glColor3f(0.4f,0.4f,0.4f);
    glVertex3i(27+bm,1167,0);
    glVertex3i(32+bm,1187,0);
    glVertex3i(36+bm,1167,0);
glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0,0,1);
    glVertex3i(54+bm,1145,0);
    glVertex3i(57+bm,1149,0);
    glVertex3i(54+bm,1153,0);
glEnd();
}
void eyes(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y){
    glColor3f(0.0f,0.0f, 0.0f);
    int i=0;
    float angle;
    GLfloat PI= 2.0f * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(i=0; i<100; i++)
    {
        angle = 2 * PI * i/100;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)* ry));
    }
glEnd();
}

void bird2(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y){ ///Bird 1
    glColor3f(0.5f,0.0f, 0.0f);
    int i=0;
    float angle;
    GLfloat PI= 2.0f * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(i=0; i<100; i++)
    {
        angle = 2 * PI * i/100;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)* ry));
    }
glEnd();
    glBegin(GL_TRIANGLES); ///Left Wing
    glColor3f(0.4f,0.4f,0.4f);
    glVertex3i(85+bm,1148,0);
    glVertex3i(90+bm,1168,0);
    glVertex3i(94+bm,1148,0);
glEnd();
    glBegin(GL_TRIANGLES); ///Right Wing
    glColor3f(0.4f,0.4f,0.4f);
    glVertex3i(89+bm,1148,0);
    glVertex3i(94+bm,1168,0);
    glVertex3i(98+bm,1148,0);
glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0,0,1);
    glVertex3i(114+bm,1127,0);
    glVertex3i(117+bm,1131,0);
    glVertex3i(114+bm,1135,0);
glEnd();
}
void eyes2(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y){
    glColor3f(0.0f,0.0f, 0.0f);
    int i=0;
    float angle;
    GLfloat PI= 2.0f * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(i=0; i<100; i++)
    {
        angle = 2 * PI * i/100;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)* ry));
    }
glEnd();
}
void bird3(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y){ ///Bird 1
    glColor3f(0.0, 1.0, 1.0);
    int i=0;
    float angle;
    GLfloat PI= 2.0f * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(i=0; i<100; i++)
    {
        angle = 2 * PI * i/100;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)* ry));
    }
glEnd();
    glBegin(GL_TRIANGLES); ///Left Wing
    glColor3f(0.4f,0.4f,0.4f);
    glVertex3i(143+bm,1167,0);
    glVertex3i(148+bm,1187,0);
    glVertex3i(152+bm,1167,0);
glEnd();
    glBegin(GL_TRIANGLES); ///Right Wing
    glColor3f(0.4f,0.4f,0.4f);
    glVertex3i(147+bm,1167,0);
    glVertex3i(152+bm,1187,0);
    glVertex3i(156+bm,1167,0);
glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0,0,1);
    glVertex3i(174+bm,1146,0);
    glVertex3i(177+bm,1150,0);
    glVertex3i(174+bm,1154,0);
glEnd();
}
void eyes3(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y){
    glColor3f(0.0f,0.0f, 0.0f);
    int i=0;
    float angle;
    GLfloat PI= 2.0f * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(i=0; i<100; i++)
    {
        angle = 2 * PI * i/100;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)* ry));
    }
glEnd();
}
///Sun
void sun(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y)
{
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    int i=0;
    float angle;
    GLfloat PI= 2.0f * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(i=0; i<100; i++)
    {
        angle = 2 * PI * i/100;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)* ry));
    }
glEnd();
}
///Sun Set
void sunset(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y)
{
    glColor3f(1.0f,0.0f, 0.0f);
    int i=0;
    float angle;
    GLfloat PI= 2.0f * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(i=0; i<100; i++)
    {
        angle = 2 * PI * i/100;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)* ry));
    }
glEnd();
}
///Moon
void moon(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y)
{
    glColor3f(1.0f,1.0f,1.0f);
    int i=0;
    float angle;
    GLfloat PI= 2.0f * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(i=0; i<100; i++)
    {
        angle = 2 * PI * i/100;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)* ry));
    }
glEnd();
}
///Clouds
void clouds(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y)
{
    glColor3f(1.0f, 1.0f, 1.0f);
    int i=0;
    float angle;
    GLfloat PI= 2.0f * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(i=0; i<100; i++)
    {
        angle = 2 * PI * i/100;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)* ry));
    }
glEnd();
}

///Stars
void star()
{
///star1
    glColor3f(1, 1, 1); ///Left Side Polygon
    glBegin(GL_POLYGON);
    glVertex3i(150, 1080, 0);
    glVertex3i(170, 1110, 0);
    glVertex3i(170, 1160, 0);
glEnd();
    glColor3f(1, 1, 1); ///Right Side Polygon
    glBegin(GL_POLYGON);
    glVertex3i(190, 1080, 0);
    glVertex3i(170, 1160, 0);
    glVertex3i(170, 1110, 0);
glEnd();
    glColor3f(1, 1, 1);   ///downward Polygon
    glBegin(GL_POLYGON);
    glVertex3i(170, 1110, 0);
    glVertex3i(200, 1130, 0);
    glVertex3i(140, 1130, 0);
glEnd();
///star2
    glColor3f(1, 1, 1);  ///Left Side Polygon
    glBegin(GL_POLYGON);
    glVertex3i(270, 1020, 0);
    glVertex3i(290, 1050, 0);
    glVertex3i(290, 1100, 0);
glEnd();
    glColor3f(1, 1, 1); ///Right Side Polygon
    glBegin(GL_POLYGON);
    glVertex3i(310, 1020, 0);
    glVertex3i(290, 1100, 0);
    glVertex3i(290, 1050, 0);
glEnd();
    glColor3f(1, 1, 1); ///downward Polygon
    glBegin(GL_POLYGON);
    glVertex3i(290, 1050, 0);
    glVertex3i(320, 1070, 0);
    glVertex3i(260, 1070, 0);
glEnd();
///star3
    glColor3f(1, 1, 1); ///Left Side Polygon
    glBegin(GL_POLYGON);
    glVertex3i(390, 1080, 0);
    glVertex3i(410, 1110, 0);
    glVertex3i(410, 1160, 0);
glEnd();
    glColor3f(1, 1, 1); ///Right Side Polygon
    glBegin(GL_POLYGON);
    glVertex3i(430, 1080, 0);
    glVertex3i(410, 1160, 0);
    glVertex3i(410, 1110, 0);
glEnd();
    glColor3f(1, 1, 1);///Downward Polygon
    glBegin(GL_POLYGON);
    glVertex3i(410, 1110, 0);
    glVertex3i(440, 1130, 0);
    glVertex3i(380, 1130, 0);
glEnd();
///star4
    glColor3f(1, 1, 1);///Left Side Polygon
    glBegin(GL_POLYGON);
    glVertex3i(790, 1080, 0);
    glVertex3i(810, 1110, 0);
    glVertex3i(810, 1160, 0);
glEnd();
    glColor3f(1, 1, 1);///Right Side Polygon
    glBegin(GL_POLYGON);
    glVertex3i(830, 1080, 0);
    glVertex3i(810, 1160, 0);
    glVertex3i(810, 1110, 0);
glEnd();
    glColor3f(1, 1, 1); ///Downward Polygon
    glBegin(GL_POLYGON);
    glVertex3i(810, 1110, 0);
    glVertex3i(840, 1130, 0);
    glVertex3i(780, 1130, 0);
glEnd();

///star5
    glColor3f(1, 1, 1); ///Left Side Polygon
    glBegin(GL_POLYGON);
    glVertex3i(1050, 1080, 0);
    glVertex3i(1070, 1110, 0);
    glVertex3i(1070, 1160, 0);
glEnd();
    glColor3f(1, 1, 1); ///Right Side Polygon
    glBegin(GL_POLYGON);
    glVertex3i(1090, 1080, 0);
    glVertex3i(1070, 1160, 0);
    glVertex3i(1070, 1110, 0);
glEnd();
    glColor3f(1, 1, 1); ///Downward Polygon
    glBegin(GL_POLYGON);
    glVertex3i(1070, 1110, 0);
    glVertex3i(1100, 1130, 0);
    glVertex3i(1040, 1130, 0);
glEnd();
///star6
    glColor3f(1, 1, 1); ///Left Side Polygon
    glBegin(GL_POLYGON);
    glVertex3i(1150, 1080, 0);
    glVertex3i(1170, 1110, 0);
    glVertex3i(1170, 1160, 0);
glEnd();
    glColor3f(1, 1, 1);///Right Side Polygon
    glBegin(GL_POLYGON);
    glVertex3i(1190, 1080, 0);
    glVertex3i(1170, 1160, 0);
    glVertex3i(1170, 1110, 0);
glEnd();
    glColor3f(1, 1, 1);///Downward Polygon
    glBegin(GL_POLYGON);
    glVertex3i(1170, 1110, 0);
    glVertex3i(1200, 1130, 0);
    glVertex3i(1140, 1130, 0);
glEnd();
}
///HILL
void hill(){
    glColor3f(0.50196, 0.25098, 0.0);
    glBegin(GL_POLYGON);
    glVertex3i(0, 900, 0);
    glVertex3i(200, 1050, 0);
    glVertex3i(300, 900, 0);

    glBegin(GL_POLYGON);
    glVertex3i(300, 900, 0);
    glVertex3i(400, 1000, 0);
    glVertex3i(500, 900, 0);

    glBegin(GL_POLYGON);
    glVertex3i(500, 900, 0);
    glVertex3i(600, 1100, 0);
    glVertex3i(700, 900, 0);

    glBegin(GL_POLYGON);
    glVertex3i(700, 900, 0);
    glVertex3i(800, 1100, 0);
    glVertex3i(900, 900, 0);
glEnd();
}
///Hill For Night
void hill_night(){
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex3i(0, 900, 0);
    glVertex3i(200, 1050, 0);
    glVertex3i(300, 900, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.50196, 0.25098, 0.0);
    glVertex3i(300, 900, 0);
    glVertex3i(400, 1000, 0);
    glVertex3i(500, 900, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.50196, 0.25098, 0.0);
    glVertex3i(500, 900, 0);
    glVertex3i(600, 1100, 0);
    glVertex3i(700, 900, 0);

    glBegin(GL_POLYGON);
    glColor3f(0.50196, 0.25098, 0.0);
    glVertex3i(700, 900, 0);
    glVertex3i(800, 1100, 0);
    glVertex3i(900, 900, 0);
glEnd();
}
void line1(){
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    ///  Middle Line
    glVertex3f(90,460,0);
    glVertex3f(90,540,0);
///Left
    glVertex3f(90,460,0);
    glVertex3f(50,520,0);
    glVertex3f(90,460,0);
    glVertex3f(70,520,0);
///Right
    glVertex3f(90,460,0);
    glVertex3f(110,520,0);
    glVertex3f(90,460,0);
    glVertex3f(130,520,0);
glEnd();
}
void line2(){
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
  ///Middle
    glVertex3f(390,540,0);
    glVertex3f(390,620,0);
///Left
    glVertex3f(390,540,0);
    glVertex3f(350,600,0);
    glVertex3f(390,540,0);
    glVertex3f(370,610,0);
///Right
    glVertex3f(390,540,0);
    glVertex3f(410,610,0);
    glVertex3f(390,540,0);
    glVertex3f(430,610,0);
glEnd();
}
void line3(){
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    ///Middle
    glVertex3f(810,810,0);
    glVertex3f(810,850,0);
///Left
    glVertex3f(810,810,0);
    glVertex3f(800,850,0);
    glVertex3f(810,810,0);
    glVertex3f(790,850,0);
///Right
    glVertex3f(810,810,0);
    glVertex3f(820,850,0);
    glVertex3f(810,810,0);
    glVertex3f(830,850,0);
glEnd();

}
///Flowers
void flowerred(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y)
{
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    int i=0;
    float angle;
    GLfloat PI= 2.0f * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(i=0; i<100; i++)
    {
        angle = 2 * PI * i/100;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)* ry));
    }
    glEnd();
}
void flowerorrange(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y)
{
    glColor3f(1.0f, 0.5f, 0.0f);
    int i=0;
    float angle;
    GLfloat PI= 2.0f * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(i=0; i<100; i++)
    {
        angle = 2 * PI * i/100;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)* ry));
    }
    glEnd();
}
void flowergreen(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y)
{
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    int i=0;
    float angle;
    GLfloat PI= 2.0f * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(i=0; i<100; i++)
    {
        angle = 2 * PI * i/100;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)* ry));
    }
    glEnd();
}
void flowerpurple(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y)
{
    glColor3f(1.0f, 0.0f, 1.0f);
    int i=0;
    float angle;
    GLfloat PI= 2.0f * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(i=0; i<100; i++)
    {
        angle = 2 * PI * i/100;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)* ry));
    }
    glEnd();
}
void floweryellow(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y)
{
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    int i=0;
    float angle;
    GLfloat PI= 2.0f * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(i=0; i<100; i++)
    {
        angle = 2 * PI * i/100;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)* ry));
    }
    glEnd();
}
void flowerblack(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y)
{
    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
    int i=0;
    float angle;
    GLfloat PI= 2.0f * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(i=0; i<100; i++)
    {
        angle = 2 * PI * i/100;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)* ry));
    }
    glEnd();
}
///GrassLand
void grass(){
    glBegin(GL_QUADS);
    glColor3f(0.5 ,1.0 ,0.5);
    glVertex3i(0,300,0);
    glVertex3i(1200,300,0);
    glVertex3i(1200,900,0);
    glVertex3i(0,900,0);
glEnd();

}
///GrassLand For Sunset
void grass_sunset(){
glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 0.5f);
    glVertex3i(0,300,0);
    glVertex3i(1200,300,0);
    glVertex3i(1200,900,0);
    glVertex3i(0,900,0);
glEnd();
}
///Grassland For Night Mood
void grass_night(){
glBegin(GL_QUADS);
    glColor3f(0.0f, 0.1f, 0.0f);
    glVertex3i(0,300,0);
    glVertex3i(1200,300,0);
    glVertex3i(1200,900,0);
    glVertex3i(0,900,0);
glEnd();
}
///Trees
void tree(){
glBegin(GL_QUADS); ///Left Side Tree
glColor3f(0.6156863,0,0);
    glVertex3i(35, 740, 0);
    glVertex3i(55, 740, 0);
    glVertex3i(55, 950, 0);
    glVertex3i(35, 950, 0);
glEnd();
glBegin(GL_POLYGON); ///Upper Leaves
glColor3f(0.0, 0.5, 0.0);
    glVertex3i(0, 900, 0);
    glVertex3i(45, 1100, 0);
    glVertex3i(90, 900, 0);
glEnd();
glBegin(GL_POLYGON); ///Lower Leaves
glColor3f(0.0, 0.5, 0.0);
    glVertex3i(0, 850, 0);
    glVertex3i(45, 1000, 0);
    glVertex3i(90, 850, 0);
glEnd();

glBegin(GL_QUADS); ///Middle Point Trees
glColor3f(0.6156863,0,0);
    glVertex3i(300, 740, 0);
    glVertex3i(320, 740, 0);
    glVertex3i(320, 950, 0);
    glVertex3i(300, 950, 0);
glEnd();
glBegin(GL_POLYGON);///Upper Leaves
glColor3f(0.0, 0.5, 0.0);
    glVertex3i(265, 900, 0);
    glVertex3i(310, 1100, 0);
    glVertex3i(355, 900, 0);
glEnd();
glBegin(GL_POLYGON); ///Lower Leaves
glColor3f(0.0, 0.5, 0.0);
    glVertex3i(265, 850, 0);
    glVertex3i(310, 1000, 0);
    glVertex3i(355, 850, 0);
glEnd();

glBegin(GL_QUADS); ///Middle Point Trees
glColor3f(0.6156863,0,0);
    glVertex3i(375, 740, 0);
    glVertex3i(395, 740, 0);
    glVertex3i(395, 950, 0);
    glVertex3i(375, 950, 0);
glEnd();
glBegin(GL_POLYGON);///Upper Leaves
glColor3f(0.0, 0.5, 0.0);
    glVertex3i(335, 900, 0);
    glVertex3i(380, 1100, 0);
    glVertex3i(435, 900, 0);
glEnd();
glBegin(GL_POLYGON); ///Lower Leaves
glColor3f(0.0, 0.5, 0.0);
    glVertex3i(335, 850, 0);
    glVertex3i(380, 1000, 0);
    glVertex3i(435, 850, 0);
glEnd();
glBegin(GL_QUADS); ///Middle Point Trees
glColor3f(0.6156863,0,0);
    glVertex3i(450, 740, 0);
    glVertex3i(470, 740, 0);
    glVertex3i(470, 950, 0);
    glVertex3i(450, 950, 0);
glEnd();
glBegin(GL_POLYGON);///Upper Leaves
glColor3f(0.0, 0.5, 0.0);
    glVertex3i(410, 900, 0);
    glVertex3i(460, 1100, 0);
    glVertex3i(510, 900, 0);
glEnd();
glBegin(GL_POLYGON); ///Lower Leaves
glColor3f(0.0, 0.5, 0.0);
    glVertex3i(410, 850, 0);
    glVertex3i(460, 1000, 0);
    glVertex3i(510, 850, 0);
glEnd();

glBegin(GL_QUADS); ///Right Side Tree
glColor3f(0.6156863,0,0);
    glVertex3i(695, 740, 0);
    glVertex3i(715, 740, 0);
    glVertex3i(715, 950, 0);
    glVertex3i(695, 950, 0);
glEnd();
glBegin(GL_POLYGON);///Upper Leaves
glColor3f(0.0, 0.5, 0.0);
    glVertex3i(660, 900, 0);
    glVertex3i(705, 1100, 0);
    glVertex3i(750, 900, 0);
glEnd();
glBegin(GL_POLYGON); ///Lower Leaves
glColor3f(0.0, 0.5, 0.0);
    glVertex3i(660, 850, 0);
    glVertex3i(705, 1000, 0);
    glVertex3i(750, 850, 0);
glEnd();
}
///Trees For Night
void tree_night(){
glBegin(GL_QUADS); ///Left Side Tree
glColor3f(0.6156863,0,0);
    glVertex3i(35, 740, 0);
    glVertex3i(55, 740, 0);
    glVertex3i(55, 950, 0);
    glVertex3i(35, 950, 0);
glEnd();
glBegin(GL_POLYGON); ///Upper Leaves
glColor3f(0.0f, 0.1f, 0.0f);
    glVertex3i(0, 900, 0);
    glVertex3i(45, 1100, 0);
    glVertex3i(90, 900, 0);
glEnd();
glBegin(GL_POLYGON); ///Lower Leaves
glColor3f(0.0f, 0.1f, 0.0f);
    glVertex3i(0, 850, 0);
    glVertex3i(45, 1000, 0);
    glVertex3i(90, 850, 0);
glEnd();
glBegin(GL_QUADS); ///Middle Point Trees
glColor3f(0.6156863,0,0);
    glVertex3i(300, 740, 0);
    glVertex3i(320, 740, 0);
    glVertex3i(320, 950, 0);
    glVertex3i(300, 950, 0);
glEnd();
glBegin(GL_POLYGON);///Upper Leaves
glColor3f(0.0f, 0.1f, 0.0f);
    glVertex3i(265, 900, 0);
    glVertex3i(310, 1100, 0);
    glVertex3i(355, 900, 0);
glEnd();
glBegin(GL_POLYGON); ///Lower Leaves
glColor3f(0.0f, 0.1f, 0.0f);
    glVertex3i(265, 850, 0);
    glVertex3i(310, 1000, 0);
    glVertex3i(355, 850, 0);
glEnd();
glBegin(GL_QUADS); ///Middle Point Trees
glColor3f(0.6156863,0,0);
    glVertex3i(375, 740, 0);
    glVertex3i(395, 740, 0);
    glVertex3i(395, 950, 0);
    glVertex3i(375, 950, 0);
glEnd();
glBegin(GL_POLYGON);///Upper Leaves
glColor3f(0.0f, 0.1f, 0.0f);
    glVertex3i(335, 900, 0);
    glVertex3i(380, 1100, 0);
    glVertex3i(435, 900, 0);
glEnd();
glBegin(GL_POLYGON); ///Lower Leaves
glColor3f(0.0f, 0.1f, 0.0f);
    glVertex3i(335, 850, 0);
    glVertex3i(380, 1000, 0);
    glVertex3i(435, 850, 0);
glEnd();
glBegin(GL_QUADS); ///Middle Point Trees
glColor3f(0.6156863,0,0);
    glVertex3i(450, 740, 0);
    glVertex3i(470, 740, 0);
    glVertex3i(470, 950, 0);
    glVertex3i(450, 950, 0);
glEnd();
glBegin(GL_POLYGON);///Upper Leaves
glColor3f(0.0f, 0.1f, 0.0f);
    glVertex3i(410, 900, 0);
    glVertex3i(460, 1100, 0);
    glVertex3i(510, 900, 0);
glEnd();
glBegin(GL_POLYGON); ///Lower Leaves
glColor3f(0.0f, 0.1f, 0.0f);
    glVertex3i(410, 850, 0);
    glVertex3i(460, 1000, 0);
    glVertex3i(510, 850, 0);
glEnd();

glBegin(GL_QUADS); ///Right Side Tree
glColor3f(0.6156863,0,0);
    glVertex3i(695, 740, 0);
    glVertex3i(715, 740, 0);
    glVertex3i(715, 950, 0);
    glVertex3i(695, 950, 0);
glEnd();
glBegin(GL_POLYGON);///Upper Leaves
glColor3f(0.0f, 0.1f, 0.0f);
    glVertex3i(660, 900, 0);
    glVertex3i(705, 1100, 0);
    glVertex3i(750, 900, 0);
glEnd();
glBegin(GL_POLYGON); ///Lower Leaves
glColor3f(0.0f, 0.1f, 0.0f);
    glVertex3i(660, 850, 0);
    glVertex3i(705, 1000, 0);
    glVertex3i(750, 850, 0);
glEnd();
}

///Houses
void house(){
glBegin(GL_QUADS);///Room Big Square
    glColor3f(1.80f, 0.59f, 0.06589f);
    glVertex3i(90, 740, 0);
    glVertex3i(250, 740, 0);
    glVertex3i(250, 850, 0);
    glVertex3i(90, 850, 0);
glEnd();
glBegin(GL_POLYGON);///Roof
    glColor3f(0.5f, 1.0f, 1.0f);
    glVertex3i(70, 850, 0);
    glVertex3i(270, 850, 0);
    glVertex3i(170, 1050, 0);
glEnd();
glBegin(GL_QUADS); ///Door
    glColor3f(0.0f, 0.5f, 1.0f);
    glVertex3i(150, 740, 0);
    glVertex3i(190, 740, 0);
    glVertex3i(190, 830, 0);
    glVertex3i(150, 830, 0);
glEnd();
glBegin(GL_QUADS);///Left Window
    glColor3f(1,1,1);
    glVertex3i(110, 780, 0);
    glVertex3i(130, 780, 0);
    glVertex3i(130, 810, 0);
    glVertex3i(110, 810, 0);
glEnd();
glBegin(GL_QUADS);///Right Window
    glColor3f(1,1,1);
    glVertex3i(210, 780, 0);
    glVertex3i(230, 780, 0);
    glVertex3i(230, 810, 0);
    glVertex3i(210, 810, 0);
glEnd();

///Another House
glBegin(GL_QUADS);///Room Big Square
    glColor3f(1.80f, 0.59f, 0.06589f);
    glVertex3i(500, 740, 0);
    glVertex3i(660, 740, 0);
    glVertex3i(660, 850, 0);
    glVertex3i(500, 850, 0);
glEnd();
glBegin(GL_POLYGON); ///Roof
    glColor3f(0.5f, 1.0f, 1.0f);
    glVertex3i(480, 850, 0);
    glVertex3i(680, 850, 0);
    glVertex3i(580, 1050, 0);
glEnd();
glBegin(GL_QUADS);///Door
    glColor3f(0.0f, 0.5f, 1.0f);
    glVertex3i(560, 740, 0);
    glVertex3i(600, 740, 0);
    glVertex3i(600, 830, 0);
    glVertex3i(560, 830, 0);
glEnd();
glBegin(GL_QUADS); ///Left Window
    glColor3f(1,1,1);
    glVertex3i(520, 780, 0);
    glVertex3i(540, 780, 0);
    glVertex3i(540, 810, 0);
    glVertex3i(520, 810, 0);
glEnd();
glColor3f(1,0,0);
glBegin(GL_QUADS);///Right Window
    glColor3f(1,1,1);
    glVertex3i(620, 780, 0);
    glVertex3i(640, 780, 0);
    glVertex3i(640, 810, 0);
    glVertex3i(620, 810, 0);
glEnd();
}
///Houses For Night
void house_night(){
glBegin(GL_QUADS);///Room Big Square
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex3i(90, 740, 0);
    glVertex3i(250, 740, 0);
    glVertex3i(250, 850, 0);
    glVertex3i(90, 850, 0);
glEnd();
glBegin(GL_POLYGON);///Roof
    glColor3f(1.9f, 1.9f, 1.9f);
    glVertex3i(70, 850, 0);
    glVertex3i(270, 850, 0);
    glVertex3i(170, 1050, 0);
glEnd();
glBegin(GL_QUADS); ///Door
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3i(150, 740, 0);
    glVertex3i(190, 740, 0);
    glVertex3i(190, 830, 0);
    glVertex3i(150, 830, 0);
glEnd();
glBegin(GL_QUADS);///Left Window
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3i(110, 780, 0);
    glVertex3i(130, 780, 0);
    glVertex3i(130, 810, 0);
    glVertex3i(110, 810, 0);
glEnd();
glBegin(GL_QUADS);///Right Window
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3i(210, 780, 0);
    glVertex3i(230, 780, 0);
    glVertex3i(230, 810, 0);
    glVertex3i(210, 810, 0);
glEnd();

///Another House
glBegin(GL_QUADS);///Room Big Square
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex3i(500, 740, 0);
    glVertex3i(660, 740, 0);
    glVertex3i(660, 850, 0);
    glVertex3i(500, 850, 0);
glEnd();
glBegin(GL_POLYGON); ///Roof
    glColor3f(1.9f, 1.9f, 1.9f);
    glVertex3i(480, 850, 0);
    glVertex3i(680, 850, 0);
    glVertex3i(580, 1050, 0);
glEnd();
glBegin(GL_QUADS);///Door
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3i(560, 740, 0);
    glVertex3i(600, 740, 0);
    glVertex3i(600, 830, 0);
    glVertex3i(560, 830, 0);
glEnd();
glBegin(GL_QUADS); ///Left Window
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3i(520, 780, 0);
    glVertex3i(540, 780, 0);
    glVertex3i(540, 810, 0);
    glVertex3i(520, 810, 0);
glEnd();
glColor3f(1,0,0);
glBegin(GL_QUADS);///Right Window
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    glVertex3i(620, 780, 0);
    glVertex3i(640, 780, 0);
    glVertex3i(640, 810, 0);
    glVertex3i(620, 810, 0);
glEnd();
}

///River
void river(){
  glBegin(GL_QUADS);
  glColor3f(0.0352941176470588, 0.5098039215686275, 0.9568627450980392);
  glVertex3i(500,300,0);
  glVertex3i(1200,300,0);
  glVertex3i(1200,900,0);
  glVertex3i(900,900,0);
  glEnd();
}

///River for sunset
void river_sunset(){
  glBegin(GL_QUADS);
  glColor3f(0.0352941176470588, 0.5098039215686275, 0.9568627450980392);
  glVertex3i(500,300,0);
  glVertex3i(1200,300,0);
  glVertex3i(1200,900,0);
  glVertex3i(900,900,0);
  glEnd();
}
///River For Night
void river_night(){
///Day Boat Moving
  glBegin(GL_QUADS);
  glColor3f(0.1f, 0.1f, 0.1f);
  glVertex3i(500,300,0);
  glVertex3i(1200,300,0);
  glVertex3i(1200,900,0);
  glVertex3i(900,900,0);
  glEnd();
}
///boat1
void boat1(){
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex3i(bn,320,0);
    glVertex3i(bn+60,320,0);
    glVertex3i(bn+80,360,0);
    glVertex3i(bn-20,360,0);
    glEnd();

    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex3i(bn,360,0);
    glVertex3i(bn+60,360,0);
    glVertex3i(bn+60,390,0);
    glVertex3i(bn,390,0);
    glEnd();
}
///boat2
void boat2(){
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glBegin(GL_POLYGON);
    glVertex3i(bnr,520,0);
    glVertex3i(bnr-60,520,0);
    glVertex3i(bnr-80,560,0);
    glVertex3i(bnr+20,560,0);
    glEnd();

    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex3i(bnr,560,0);
    glVertex3i(bnr-60,560,0);
    glVertex3i(bnr-60,590,0);
    glVertex3i(bnr,590,0);
    glEnd();
}
///Boat For Sunset
///boat1
void boat1_for_sunset(){
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex3i(bns,420,0);
    glVertex3i(bns+60,420,0);
    glVertex3i(bns+80,460,0);
    glVertex3i(bns-20,460,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3i(bns+40,460,0);
    glVertex3i(bns+40,530,0);
    glEnd();

    glColor3f(1,0,0);
    glBegin(GL_TRIANGLES);
    glVertex3f(bns+40,465,0);
    glVertex3f(bns+40,530,0);
    glVertex3f(bns+5,465,0);
    glEnd();
}
///boat for night
void boat_night(){
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex3i(bn,320,0);
    glVertex3i(bn+60,320,0);
    glVertex3i(bn+80,360,0);
    glVertex3i(bn-20,360,0);
    glEnd();

    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex3i(bn,360,0);
    glVertex3i(bn+60,360,0);
    glVertex3i(bn+60,390,0);
    glVertex3i(bn,390,0);
    glEnd();
}

///Road
void road(){
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3i(0, 0, 0);
    glVertex3i(1200, 0, 0);
    glVertex3i(1200, 300, 0);
    glVertex3i(0, 300, 0);
glEnd();
}
///Road Divider
void roaddivider(){
glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex3i(0, 100, 0);
    glVertex3i(50, 100, 0);
    glVertex3i(50, 130, 0);
    glVertex3i(0, 130, 0);

    glBegin(GL_QUADS);
    glVertex3i(100, 100, 0);
    glVertex3i(200, 100, 0);
    glVertex3i(200, 130, 0);
    glVertex3i(100, 130, 0);

    glBegin(GL_QUADS);
    glVertex3i(300, 100, 0);
    glVertex3i(400, 100, 0);
    glVertex3i(400, 130, 0);
    glVertex3i(300, 130, 0);

    glBegin(GL_QUADS);
    glVertex3i(500, 100, 0);
    glVertex3i(600, 100, 0);
    glVertex3i(600, 130, 0);
    glVertex3i(500, 130, 0);

    glBegin(GL_QUADS);
    glVertex3i(700, 100, 0);
    glVertex3i(800, 100, 0);
    glVertex3i(800, 130, 0);
    glVertex3i(700, 130, 0);

    glBegin(GL_QUADS);
    glVertex3i(900, 100, 0);
    glVertex3i(1000, 100, 0);
    glVertex3i(1000, 130, 0);
    glVertex3i(900, 130, 0);

    glBegin(GL_QUADS);
    glVertex3i(1100, 100, 0);
    glVertex3i(1200, 100, 0);
    glVertex3i(1200, 130, 0);
    glVertex3i(1100, 130, 0);
glEnd();
}
///car
void car(){
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 1.0f);
    glVertex3i(0+p,170,0);
    glVertex3i(100+p,170,0);
    glVertex3i(90+p,200,0);
    glVertex3i(10+p,200,0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3i(15+p,200,0);
    glVertex3i(85+p,200,0);
    glVertex3i(70+p,230,0);
    glVertex3i(30+p,230,0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3i(300+p,170,0);
    glVertex3i(400+p,170,0);
    glVertex3i(390+p,200,0);
    glVertex3i(310+p,200,0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3i(315+p,200,0);
    glVertex3i(385+p,200,0);
    glVertex3i(370+p,230,0);
    glVertex3i(330+p,230,0);
    glEnd();
}

///car In Sunset
void carsunset(){
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 1.0f);
    glVertex3i(0+q,170,0);
    glVertex3i(100+q,170,0);
    glVertex3i(90+q,200,0);
    glVertex3i(10+q,200,0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3i(15+q,200,0);
    glVertex3i(85+q,200,0);
    glVertex3i(70+q,230,0);
    glVertex3i(30+q,230,0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3i(300+q,170,0);
    glVertex3i(400+q,170,0);
    glVertex3i(390+q,200,0);
    glVertex3i(310+q,200,0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3i(315+q,200,0);
    glVertex3i(385+q,200,0);
    glVertex3i(370+q,230,0);
    glVertex3i(330+q,230,0);
    glEnd();
}

///car For Night
void car_night(){
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3i(o-10,190,0);
    glVertex3i(o-100,190,0);
    glVertex3i(o-100,220,0);
    glVertex3i(o-10,220,0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3i(o-10,220,0);
    glVertex3i(o-100,220,0);
    glVertex3i(o-90,260,0);
    glVertex3i(o-10,260,0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3i(o-100,195,0);
    glVertex3i(o-103,195,0);
    glVertex3i(o-103,210,0);
    glVertex3i(o-100,210,0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3i(o-300,170,0);
    glVertex3i(o-400,170,0);
    glVertex3i(o-400,200,0);
    glVertex3i(o-300,200,0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3i(o-300,200,0);
    glVertex3i(o-400,200,0);
    glVertex3i(o-390,240,0);
    glVertex3i(o-300,240,0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3i(o-400,175,0);
    glVertex3i(o-403,175,0);
    glVertex3i(o-403,190,0);
    glVertex3i(o-400,190,0);
    glEnd();
}

/// Car Wheel
void wheel(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y)
{
    glColor3f(0.1f, 0.1f, 0.1f);
    int i=0;
    float angle;
    GLfloat PI= 2.0f * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(i=0; i<100; i++)
    {
        angle = 2 * PI * i/100;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)* ry));
    }
    glEnd();
}
///All are responsible for movements
void cloudmove(){
    if(cm<=1200){
    cm=cm+.09;
}
else{
    cm=-1200;
}
glutPostRedisplay();
}

void boatmove_sunset(){
    if(bns<=1400){
    bns=bns+.04;
}
else{
    bns=1400;
}
glutPostRedisplay();
}

void boatmove_night(){
    if(bn<=1400){
    bn=bn+.03;
}
else{
    bn=550;
}
glutPostRedisplay();
}

void boatmoverev_night(){
    if(bnr>=720){
    bnr=bnr-.03;
}
else{
    bnr=720;
}
glutPostRedisplay();
}

void carmove_day(){
    if(p<=1200){
    p=p+.95;
}
else{
    p=-1200;
}
glutPostRedisplay();
}

void carmove_sunset(){
    if(q<=1200){
    q=q+.95;
}
else{
    q=-1400;
}
glutPostRedisplay();
}

void sunmove(){
   if(sm>=920){
    sm=sm-.05;
}
else{
    sm=920;
}
glutPostRedisplay();
}
void birdmove(){
    if(bm<=1200){
    bm=bm+.3;
}
else{
    bm=-200;
}
glutPostRedisplay();
}

void carmove_night(){
    if(o>=-100){
    o=o-.95;
}
else{
    o=2400;
}
glutPostRedisplay();
}


void draw_object()
{
    if(day==1){
    sky();
    sun(40,70,140,1120);///For Sun
    ///Start For Making Clouds
    clouds(30,40, 260+cm,1150);
    clouds(30,40, 285+cm,1160);
    clouds(30,40, 310+cm,1145);
    clouds(30,40, 285+cm,1130);

    clouds(30,40, 460+cm,1150);
    clouds(30,40, 485+cm,1160);
    clouds(30,40, 510+cm,1145);
    clouds(30,40, 485+cm,1130);

    clouds(30,40, 860+cm,1150);
    clouds(30,40, 885+cm,1160);
    clouds(30,40, 910+cm,1145);
    clouds(30,40, 885+cm,1130);

    clouds(30,40, 1060+cm,1150);
    clouds(30,40, 1085+cm,1160);
    clouds(30,40, 1110+cm,1145);
    clouds(30,40, 1085+cm,1130);
    ///End For Making Clouds
    hill();
    road();
    roaddivider();
    car();
    carmove_day();
    cloudmove();
    wheel(7,15,20+p,165);///First Wheel For First Car
    wheel(7,15,85+p,165);///Second Wheel For First  Car
    wheel(7,15,320+p,165);///First Wheel For Second Car
    wheel(7,15,385+p,165);///Second Wheel For Second Car
    grass();
    line1();
    line2();
    line3();
    flowerred(10,15,90,540);
    flowerorrange(10,15,70,520);
    flowergreen(10,15,110,520);
    flowerpurple(10,15,50,520);
    floweryellow(10,15,130,520);

    flowerred(10,15,390,620);
    flowerorrange(10,15,350,600);
    flowergreen(10,15,370,610);
    flowerpurple(10,15,410,610);
    floweryellow(10,15,430,610);

    flowerred(5,10,810,850);
    flowerorrange(5,10,800,850);
    flowergreen(5,10,790,850);
    flowerpurple(5,10,820,850);
    floweryellow(5,10,830,850);

    river();
    boat1();
    boat2();
    boatmove_night();
    boatmoverev_night();
    tree();
    house();
    }
    else if(day==2){
    sunset_sky();
    hill();
    road();
    roaddivider();
    carsunset();
    carmove_sunset();
    wheel(7,15,20+q,165);///First Wheel For First Car
    wheel(7,15,85+q,165);///Second Wheel For First  Car
    wheel(7,15,320+q,165);///First Wheel For Second Car
    wheel(7,15,385+q,165);///Second Wheel For Second Car*/
    grass_sunset();
    line1();
    line2();
    line3();
    flowerred(10,15,90,540);
    flowerorrange(10,15,70,520);
    flowergreen(10,15,110,520);
    flowerpurple(10,15,50,520);
    floweryellow(10,15,130,520);

    flowerred(10,15,390,620);
    flowerorrange(10,15,350,600);
    flowergreen(10,15,370,610);
    flowerpurple(10,15,410,610);
    floweryellow(10,15,430,610);

    flowerred(5,10,810,850);
    flowerorrange(5,10,800,850);
    flowergreen(5,10,790,850);
    flowerpurple(5,10,820,850);
    floweryellow(5,10,830,850);
    sunset(40,70,1150,sm);///For Sun
    ///For Bird 1
    bird(6,12,48+bm,1150);
    bird(2,4,48+bm,1150);
    bird(13,18,30+bm,1150);
    eyes(1,2,51+bm,1153);
    ///For Bird 2
    bird2(6,12,108+bm,1130);
    bird2(2,4,108+bm,1130);
    bird2(13,18,90+bm,1130);
    eyes2(1,2,111+bm,1133);
    ///For Bird 3
    bird3(6,12,168+bm,1150);
    bird3(2,4,168+bm,1150);
    bird3(13,18,150+bm,1150);
    eyes3(1,2,171+bm,1153);
    birdmove();
    river_sunset();
    boat1_for_sunset();
    boatmove_sunset();
    sunmove();
    tree();
    house();
    }
    else{
    night_sky();
    star();
    hill_night();
    moon(30,50,680,1140);///For Moon
    road();
    roaddivider();
    car_night();
    carmove_night();
    wheel(7,15,o-20,185);///First Wheel For First Car
    wheel(7,15,o-85,185);///Second Wheel For First  Car
    wheel(7,15,o-320,165);///First Wheel For Second Car
    wheel(7,15,o-385,165);///Second Wheel For Second Car
    grass_night();
     line1();
    line2();
    line3();
    flowerblack(10,15,90,540);
    flowerblack(10,15,70,520);
    flowerblack(10,15,110,520);
    flowerblack(10,15,50,520);
    flowerblack(10,15,130,520);

    flowerblack(10,15,390,620);
    flowerblack(10,15,350,600);
    flowerblack(10,15,370,610);
    flowerblack(10,15,410,610);
    flowerblack(10,15,430,610);

    flowerblack(5,10,810,850);
    flowerblack(5,10,800,850);
    flowerblack(5,10,790,850);
    flowerblack(5,10,820,850);
    flowerblack(5,10,830,850);
    river_night();
    boat_night();
    boatmove_night();
    tree_night();
    house_night();
    }
}
void display(void){
glClear (GL_COLOR_BUFFER_BIT);


draw_object();
glFlush();
}
void keyboardFunc(unsigned char key, int x, int y)
{
	switch(key)
	{
    case 'n':
        day=3;
        display();
        break;
	  case 'd':
        day=1;
        display();
        break;
        case 'N':
        day=3;
        display();
        break;
        case 'D':
        day=1;
        display();
        break;
        case 'S':
        day=2;
        display();
        break;
        case 's':
        day=2;
        display();
        break;
        case 'r':
        day=4;
        display();
        break;

	}
}
void init (void)
{
/* select clearing (background) color */
glClearColor (0.0, 0.0, 0.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 1200.0, 0.0, 1200.0);
}
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1000, 600);
glutInitWindowPosition (0,0);
glutCreateWindow ("Lab Final Project");
init ();
glutDisplayFunc(display);
glutKeyboardFunc(keyboardFunc);
glutMainLoop();
return 0; /* ISO C requires main to return int. */
}
