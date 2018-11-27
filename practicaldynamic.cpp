#include<iostream>
#include<fstream>
#include <string>
#include<windows.h>
#include<gl\glut.h>
#include<gl\gl.h>
#include<cmath>
#include "stlinput.H"
#include "four_bar.H"
using namespace std;
   const GLfloat pi = 3.141592654;

   GLfloat ob_angle_x =0.0f;
   GLfloat ob_angle_y =0.0f;
   GLfloat ob_angle_z =0.0f;
   GLfloat angle=0.0f;

   GLuint support;
   GLuint base;
   GLuint motorset2;
   GLuint motor;
   GLuint motorset1;
   GLuint pulley_s;
   GLuint pulley_L;
   GLuint pulley_M;
   GLuint bar1;
   GLuint wheel_XL;
   GLuint washer1;
   GLuint bar2;
   GLuint bar3;
   GLuint bar4;
   GLuint axialbearing;
   GLuint adopter;
   GLuint bolt_long;

   GLfloat time = 0.0f;
   GLfloat time2 = 0.0f;
   GLfloat step = 0.5f;
   GLfloat temp ;

   GLfloat thita[4] = {0.0f, 0.0f, 4.0f, 2.0f};
   GLfloat stick[4] = {160.0f,100.0f,160.0f,160.0f};

   int n  = 0;
   int n1 = 1;

   GLfloat sita4_temp[2] = {0};
   GLfloat w4 = 0;

 //  GLfloat wing[6][3] = {0};

   bool deci = false;

   static GLfloat corners[]=
   {
	   0 ,1 ,1,             //0
	   40,6,1,              //1
	   40,5,1,              //2
	   0 ,0 ,1,             //3
	   0 ,1 ,0,             //4
	   40,6,0,              //5
	   40,5,0,              //6
	   0 ,0 ,0              //7
   };

   static GLfloat corners2[]=
   {
	   0 ,-1 ,1,             //0
	   40,-6,1,              //1
	   40,-5,1,              //2
	   0 ,0 ,1,             //3
	   0 ,-1 ,0,             //4
	   40,-6,0,              //5
	   40,-5,0,              //6
	   0 ,0 ,0              //7
   };

   static GLfloat corners3[]=
   {
	   0 ,-1,1,
	   40,-3,1,
	   40,-2,1,
	   0 ,0 ,1,
	   0 ,-1,0,
	   40,-3,0,
	   40,-2,0,
	   0 , 0,0,
   };

   static GLfloat corners4[]=
   {
	   0 ,-1,1,
	   20,26,1,
	   20,25,1,
	   0 ,0 ,1,
	   0 ,-1,0,
	   20,26,0,
	   20,25,0,
	   0 ,0 ,0
   };

   static GLubyte index[]=
   {
	   0,1,2,3,               //front
       4,5,1,0,               //top
	   3,2,6,7,               //bottom
	   5,4,7,6,               //back
	   1,5,6,2,               //right
	   4,0,3,7                //left 
   };



void RenderScene(void)
{
   
   GLfloat gray[] = {0.75f, 0.75f, 0.75f, 1.0f};

   

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);



	glPushMatrix();
	  
      glRotatef(ob_angle_x,1.0,0.0,0.0);     
	  glRotatef(-ob_angle_y,0.0,1.0,0.0);
	  glRotatef(ob_angle_z,0.0,0.0,1.0);
      glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE,gray);   

         glColor3f(1.0f,0.0f,0.0f);   //make x axis red
		 glLineWidth(3.0f);
		 glBegin(GL_LINES);
		 glVertex3f(0.0f,0.0f,0.0f);
         glVertex3f(200.0f,0.0f,0.0f);
		 glEnd();

		 glColor3f(0.0f,1.0f,0.0f);  //make y axis green
		 glLineWidth(3.0f);
		 glBegin(GL_LINES);
		 glVertex3f(0.0f,0.0f,0.0f);
         glVertex3f(0.0f,200.0f,0.0f);
		 glEnd();

		 glColor3f(0.0f,0.0f,1.0f);  //make z axis blue
		 glLineWidth(3.0f);
		 glBegin(GL_LINES);
		 glVertex3f(0.0f,0.0f,0.0f);
         glVertex3f(0.0f,0.0f,200.0f);
		 glEnd();


         glPushMatrix();
		 glRotatef(180.0f,0.0f,1.0f,0.0f);
		 glTranslatef(-12.5f,-30.9f,0.0f);
         glColor3f(1.0f,0.0f,0.0f);
		 glCallList(support);
		 glPopMatrix();
		 
		 glPushMatrix();
         glRotatef(90.0f,-1.0f,0.0f,0.0f);
		 glTranslatef(-102.5f,-2.9f,-37.9f);
		 glColor3f(1.0f,0.0f,0.0f);
		 glCallList(base);
		 glPopMatrix();

		 glPushMatrix();
         glRotatef(180.0f,0.0f,1.0f,0.0f);
		 glTranslatef(-12.5f+40.0f,-30.9f,0.0f);
		 glColor3f(1.0f,0.0f,0.0f);
		 glCallList(support);
		 glPopMatrix();
         
		 glPushMatrix();
		 glTranslatef(-102.5f,-30.9f,-11.5f);
		 glColor3f(1.0f,0.0f,0.0f);
         glCallList(motorset2);
         glPopMatrix();

         glPushMatrix();
		 glTranslatef(-92.8f,-30.0f,-31.0f);
		 glColor3f(0.5f,0.5f,0.5f);
         glCallList(motor);
         glPopMatrix();

		 glPushMatrix();
		 glRotatef(90.0f,-1.0f,0.0f,0.0f);
		 glTranslatef(-96.0f,3.0f,-22.0f);
		 glColor3f(1.0f,0.0f,0.0f);
         glCallList(motorset1);
		 glPopMatrix();

		 //wheel output(small)
		 glPushMatrix();
		 glRotatef(90.0f,-1.0f,0.0f,0.0f);
		 glTranslatef(-83.8f,-3.2f,-21.0f);
		 glColor3f(1.0f,1.0f,1.0f);
		 glCallList(pulley_s);
         glPopMatrix();

		 //wheel output(Large)
         glPushMatrix();
		 glRotatef(90.0f,-1.0f,0.0f,0.0f);
		 glTranslatef(-49.5f,-3.9f,-27.63f);
		 glCallList(pulley_L);
		 glPopMatrix();

		 //wheel output(medium)
		 glPushMatrix();
		 glRotatef(90.0f,-1.0f,0.0f,0.0f);
		 glTranslatef(-45.1f,-7.7f,-23.6f);
		 glCallList(pulley_M);
		 glPopMatrix();

		 //output bar1
         glPushMatrix();
		 glTranslatef(-167.5f,-7.5f,0.0f);
		 glColor3f(0.0f,1.0f,1.0f);
		 glCallList(bar1);
		 glPopMatrix();

         

		
		 //take straight line as pulley(connect motor with wheel_M(upside))
         glPushMatrix();
		 glTranslatef(-80.0f,-15.0f,1.0f);
         glEnableClientState(GL_VERTEX_ARRAY);
		 glVertexPointer(3, GL_FLOAT, 0, corners);
		 glColor3f(1.0f,1.0f,0.0f);
		 glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, index);
         glPopMatrix();

		 //take straight line as pulley(connect motor with wheel_M(bottom))
		 glPushMatrix();
		 glTranslatef(-80.0f,-20.7f,1.0f);
         glEnableClientState(GL_VERTEX_ARRAY);
		 glVertexPointer(3, GL_FLOAT, 0, corners2);
		 glColor3f(1.0f,1.0f,0.0f);
		 glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, index);
         glPopMatrix();

		 //let the dot translate on the pulley to simulate the rotating of the pulley
         glPushMatrix();
		 if(time >40)
		 time = time-40;
		 glTranslatef(-80.0f+time,-14.2f+time/8,1.0f);
		 glColor3f(0.0f,1.0f,0.0f);
		 glutSolidSphere(1.0f,10,10);
		 glPopMatrix();

         //let the dot translate on the pulley to simulate the rotating of the pulley
		 glPushMatrix();
		 glTranslatef(-80.0f+time-5,-14.2f+(time-5)/8,1.0f);
		 glColor3f(0.0f,1.0f,0.0f);
		 if(time>5)
		 {
		 glutSolidSphere(1.0f,10,10);
		 }
		 glPopMatrix();

         //let the dot translate on the pulley to simulate the rotating of the pulley
		 glPushMatrix();
		 glTranslatef(-time-40.0f,time/8-25.8f,1.1f);
		 glColor3f(0.0f,1.0f,0.0f);
		 glutSolidSphere(1.0f,10,10);
		 glPopMatrix();

		 //let the dot translate on the pulley to simulate the rotating of the pulley
		 glPushMatrix();
		 glTranslatef(-(time+5)-40.0f,(time+5)/8-25.8f,1.1f); 
		 glColor3f(0.0f,1.0f,0.0f);
		 if(time<35)
		 {
		 glutSolidSphere(1.0f,10,10);
		 }
		 glPopMatrix();

		 
		 
		 glPushMatrix();                              //assembling of wheel_XL(rotating included)
		 glRotatef(-20.0f-time2+180,0.0f,0.0f,1.0f);
		 glTranslatef(-25.0f,-25.0f,5.0f);            //glTranslatef(25*sqrt(2)*cos((45-time2)*pi/180)-25.0f,25*sqrt(2)*sin((45-time2)*pi/180)-25.0f,0.0f)-->idiot process
		 glColor3f(1.0f,1.0f,1.0f);
		 glCallList(wheel_XL);
		 glPopMatrix();


		                
		 glPushMatrix();                          //assembling of washer between wheel and bar2 
		 glTranslatef(-5.5f,-5.5f,8.8f);
		 glColor3f(0.5f,0.5f,0.5f);
		 glCallList(washer1);
		 glPopMatrix();
		 
		 glPushMatrix();                          //assemble of bar2
		 glRotatef(180.0f,1.0f,0.0f,0.0f);
		 glRotatef(time2,0.0f,0.0f,1.0f);              //time2+162
		 glTranslatef(-107.5f,-7.5f,-14.8f);
		 glColor3f(1.0f,1.0f,0.0f);
		 glCallList(bar2);
		 glPopMatrix();

		 glPushMatrix();                          //pulley---battom connection between wheel_M and wheel_XL
		 glTranslatef(-40.0f,-22.0f,3.8f);
		 glVertexPointer(3, GL_FLOAT, 0, corners3);
		 glColor3f(1.0f,1.0f,0.0f);
		 glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, index);
		 glPopMatrix();

         glPushMatrix();                          //pulley---top connection between wheel_M and wheel_XL
		 glTranslatef(-41.0f,-12.0f,7.0f);
		 glVertexPointer(3, GL_FLOAT, 0, corners4);
		 glColor3f(1.0f,1.0f,0.0f);
		 glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, index);
		 glPopMatrix();


		 //let the dot translate on the pulley to simulate the rotating of the pulley
		 glPushMatrix();
		 temp = time2;
		 if(time2>120)
		 {
			 while(temp>120)
			 {
			 temp = temp - 120;
			 }
		 }
		 glTranslatef(-temp/3,-24.5f+temp/3/20,3.8f);
		 glColor3f(0.0f,1.0f,0.0f);
		 glutSolidSphere(1.5f,10,10);
		 glPopMatrix();


		 //let the dot translate on the pulley to simulate the rotating of the pulley
		 glPushMatrix();
		 glTranslatef(-41.0f+temp/3.5,-12.0f+temp/3.5*1.25,7.0f);
		 glColor3f(0.0f,1.0f,0.0f);
		 if(temp<60)
		 {
		 glutSolidSphere(1.5f,10,10);
		 }
		 glPopMatrix();


		 thita[1] = (-time2)/180*pi;
         four_bar(stick,thita);


		 glPushMatrix();         // assembling of bar3
     	 glRotatef(thita[2]*180/pi-180,0.0f,0.0f,1.0f);
		 glTranslatef(-7.5f+stick[1]*cos((-time2)/180*pi+pi-thita[2]+pi),-7.5f+stick[1]*sin((-time2)/180*pi+pi-thita[2]+pi),15.8f); //(-7.5f+stick[1]*cos((-time2)/180*pi+pi),-7.5f+stick[1]*sin((-time2)/180*pi+pi),15.8f)
		 glColor3f(0.0f,1.0f,1.0f);
		 glCallList(bar3);
		 glPopMatrix(); 

		 /*glPopMatrix();                     //test of bar assembling
		 glLineWidth(10.0f);
	     glColor3f(1.0f,1.0f,1.0f);
	     glBegin(GL_LINES);
	        glVertex3f(stick[1]*cos((-time2)/180*pi+pi), stick[1]*sin((-time2)/180*pi+pi),15.8f);
	        glVertex3f(stick[1]*cos((-time2)/180*pi+pi)+stick[2]*cos(thita[2]-pi), stick[1]*sin((-time2)/180*pi+pi)+stick[2]*sin(thita[2]-pi), 15.8f);
	     glEnd();
		 glPushMatrix();*/

		 glPushMatrix();           // assembling of the washer between bar2 and bar3
		 glTranslatef(-5.5f+stick[1]*cos((-time2)/180*pi+pi),-5.5f+stick[1]*sin((-time2)/180*pi+pi),14.8f);
		 glColor3f(0.5f,0.5f,0.5f);
		 glCallList(washer1);
		 glPopMatrix();


		 glPushMatrix();                               // assembling of bar4
		 glRotatef(thita[3]*180/pi-180,0.0f,0.0f,1.0f);
		 glTranslatef(-7.5f-160.0f*cos(thita[3]-pi),-7.5f+160.0f*sin(thita[3]-pi),21.8f); 
		 glColor3f(1.0f,0.0f,1.0f);
		 glCallList(bar4);
		 glPopMatrix();

		 glPushMatrix();                              // assembling of the washer between bar3 and bar4
		 glTranslatef(-5.5f-stick[0]+stick[3]*cos(thita[3]-pi),-5.5f+stick[3]*sin(thita[3]-pi),21.8f);
		 glColor3f(0.5f,0.5f,0.5f);
         glCallList(washer1);
		 glPopMatrix();

		 glPushMatrix();                              // assembling of the washer between bar4 and axial bearing
		 glTranslatef(-5.5f-stick[0],-5.5f,26.8f);
		 glColor3f(0.5f,0.5f,0.5f);
         glCallList(washer1);
		 glPopMatrix();

		 glPushMatrix();                              // assembling of the washer between bar4 and axial bearing
		 glTranslatef(-5.5f-stick[0],-5.5f,20.8f);
		 glColor3f(0.5f,0.5f,0.5f);
         glCallList(washer1);
		 glPopMatrix();

		 glPushMatrix();                              // assembling of the axialbearing
		 glTranslatef(-3.8f-stick[0],-3.8f,27.8f);
		 glColor3f(0.8f,0.8f,0.8f);
         glCallList(axialbearing);
         glTranslatef(0.0f,0.0f,2.0f);
		 glCallList(axialbearing);
		 glTranslatef(0.0f,0.0f,2.0f);
		 glCallList(axialbearing);
		 glTranslatef(0.0f,0.0f,-12.0f);
		 glCallList(axialbearing);
		 glTranslatef(0.0f,0.0f,-2.0f);
		 glCallList(axialbearing);
		 glTranslatef(0.0f,0.0f,-2.0f);
		 glCallList(axialbearing);
		 glPopMatrix();
		 
		 glPushMatrix();                            // plastic between bar4 and axialbearing
		 glTranslatef(-7.5f-stick[0],-7.5f,5.0f);
		 glColor3f(0.0f,1.0f,1.0f);
		 glCallList(adopter);
		 glTranslatef(0.0f,0.0f,5.0f);
		 glCallList(adopter);
		 glPopMatrix();

		 glPushMatrix();                           //assemble of the longest bolt
		 glRotatef(180.0f,1.0f,0.0f,0.0f);
		 glTranslatef(-2.5f-stick[0],-2.5f,-50.0f);
		 glColor3f(0.5f,0.5f,0.5f);
		 glCallList(bolt_long);
		 glPopMatrix();



		 n = n1%2;
		 switch(n)                        //impetrate angular velocity of bar4
		 {
		     case 1:
			 {
			 sita4_temp[0] = thita[3];

			   if(n1>1)
				   w4 = sita4_temp[0] - sita4_temp[1];
			 }
			 break;

			 case 0:
			 {
				 sita4_temp[1] = thita[3];
				 w4 = sita4_temp[1] - sita4_temp[0];
			 }
			 break;
		 }

		 glColor3f(1.0f,1.0f,1.0f);              // test of angular speed of bar4
		 glLineWidth(3.0f);
		 glBegin(GL_LINES);
		 glVertex3f(-stick[0]+stick[3]*cos(thita[3]-pi),+stick[3]*sin(thita[3]-pi),40.0f);             
         glVertex3f(-stick[0]+stick[3]*cos(thita[3]-pi)+w4*cos(thita[3]-pi/2)*10000,stick[3]*sin(thita[3]-pi)+w4*sin(thita[3]-pi/2)*10000,40.0f);//thita[3]-pi
		 glEnd();


		 
		 GLfloat wing[6][3] = 
		 {
			 {                    0.0f-5*sin(thita[3]-pi),                         5.0f*cos(thita[3]-pi),  0.0f},
			 {                    0.0f-5*sin(thita[3]-pi),                         5.0f*cos(thita[3]-pi), 60.0f},
			 { 140.0f*cos(thita[3]-pi)-5*sin(thita[3]-pi), 140.0f*sin(thita[3]-pi)+5.0f*cos(thita[3]-pi),  0.0f},  
			 {                    140.0f*cos(thita[3]-pi),                  140.0f*sin(thita[3]-pi)+0.0f,  0.0f},
			 {                                       0.0f,                                          0.0f, 60.0f},
			 {                                       0.0f,                                          0.0f,  0.0f}
		 };

		 GLfloat cosfi = (1-pow(sin(thita[3]-pi),2)*(1-cos(w4*5000/180*pi)))/(sqrt(1-pow(sin(thita[3]-pi),2)*pow(sin(w4*5000/180*pi),2)));
		 GLfloat sinfi = sqrt(1-pow(cosfi,2));
		 GLfloat sinalfa = sin(thita[3]-pi)*sin(w4*5000/180*pi);
		 GLfloat cosalfa = sqrt(1-pow(sinalfa,2));

		 //cout<<"cosfi = "<<cosfi  <<endl;      cosfi adjust
		 //cout<<"sinalfa = "<<sinalfa<<endl;

		 glPushMatrix();
		  glRotatef(w4*5000,cos(thita[3]-pi),sin(thita[3]-pi),0.0f);
		  glTranslatef(26.8f*sin(w4*5000/180*pi)*cos(thita[3]-pi/2),26.8f*sin(w4*5000/180*pi)*sin(thita[3]-pi/2),26.8f*cos(w4*5000/180*pi));
          glTranslatef(-stick[0]*cosalfa*cosfi,-stick[0]*cosalfa*sinfi,-stick[0]*sinalfa);//stick[0]*sinalfa-stick[0]*1.87*sin(w4*5000/180*pi)
		  glColor3f(1.0f,1.0f,1.0f);
		  glBegin(GL_TRIANGLES);
		     glNormal3f(0.0f, 1.0f,0.0f);
             glVertex3f(wing[0][0],wing[0][1],wing[0][2]);
			 glVertex3f(wing[1][0],wing[1][1],wing[1][2]);
			 glVertex3f(wing[2][0],wing[2][1],wing[2][2]);

			 glNormal3f(0.0f, -1.0f,-1.0f);
             glVertex3f(wing[3][0],wing[3][1],wing[3][2]);
			 glVertex3f(wing[4][0],wing[4][1],wing[4][2]);
			 glVertex3f(wing[5][0],wing[5][1],wing[5][2]);

			 glNormal3f(-1.0f, 0.0f,0.0f);
			 glVertex3f(wing[5][0],wing[5][1],wing[5][2]);
			 glVertex3f(wing[4][0],wing[4][1],wing[4][2]);
			 glVertex3f(wing[0][0],wing[0][1],wing[0][2]);

			 glNormal3f(0.0f, 0.0f,-1.0f);
			 glVertex3f(wing[0][0],wing[0][1],wing[0][2]);
			 glVertex3f(wing[4][0],wing[4][1],wing[4][2]);
			 glVertex3f(wing[1][0],wing[1][1],wing[1][2]);

			 glVertex3f(wing[1][0],wing[1][1],wing[1][2]);
			 glVertex3f(wing[4][0],wing[4][1],wing[4][2]);
			 glVertex3f(wing[3][0],wing[3][1],wing[3][2]);

			 glVertex3f(wing[3][0],wing[3][1],wing[3][2]);
			 glVertex3f(wing[2][0],wing[2][1],wing[2][2]);
			 glVertex3f(wing[1][0],wing[1][1],wing[1][2]);

			 glNormal3f(0.0f, 0.0f,-1.0f);
			 glVertex3f(wing[3][0],wing[3][1],wing[3][2]);
			 glVertex3f(wing[5][0],wing[5][1],wing[5][2]);
			 glVertex3f(wing[2][0],wing[2][1],wing[2][2]);

			 glNormal3f(0.0f, 0.0f,-1.0f);
			 glVertex3f(wing[2][0],wing[2][1],wing[2][2]);
			 glVertex3f(wing[5][0],wing[5][1],wing[5][2]);
			 glVertex3f(wing[0][0],wing[0][1],wing[0][2]);
		  glEnd();
         glPopMatrix();


		 


         glPopMatrix();

		 time = time+step;
         time2 = time2+step;
		 n1++;

		 if (time2>360)
			 time2 = time2 -360;

         glutSwapBuffers();

}


void SetupRC(void)
{

	GLfloat ambientLight[]={0.3f, 0.3f, 0.3f, 1.0f};
	GLfloat diffuseLight[]={0.7f, 0.7f, 0.7f, 1.0f};

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_CCW);

	glEnable(GL_LIGHTING);

	//glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glEnable(GL_LIGHT0);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambientLight);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    stlinput("base120x14.7x7mm.STL",base);
	stlinput("suport12.35Xdir12.8or24.7ydir.STL",support);
	stlinput("motorset2_14.05y.STL",motorset2);
	stlinput("motor25.15mmx36.2mm.STL",motor);
	stlinput("mortorset1_30.4y.STL",motorset1);
	stlinput("pulley6.9x2.6.STL",pulley_s);
	stlinput("pulley19.45x3.8mm.STL",pulley_L);
	stlinput("pulley10.7x3.8mm.STL",pulley_M);
	stlinput("bar1.STL",bar1);
	stlinput("pulley48.75x5mm.STL",wheel_XL);
	stlinput("washer.STL",washer1);
	stlinput("bar2.STL",bar2);
	stlinput("bar3.STL",bar3);
	stlinput("bar4.STL",bar4);
	stlinput("axialbearing7.6x1mm.STL",axialbearing);
	stlinput("bearing15x5mm.STL",adopter);
	stlinput("bolt3mm_51.85mm.STL",bolt_long);
	

	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
}


void ChangeSize(GLsizei w,GLsizei h)
{
	GLfloat lightPos[]={0.0f,0.0f,400.0f,1.0f};
	if(h==0)
		h=1;
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

   glOrtho(-300.0f,100.0f, -200.0f, 200.f, -200.0f, 200.0f); //Area showed

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

}


void SpecialKeyHandler(int key, int x, int y)
{  


	if(key == GLUT_KEY_LEFT)
	{
		ob_angle_y = ob_angle_y+10.0f;

		if (ob_angle_y<-180.0f)
			ob_angle_y = ob_angle_y+360.0f;
	}

	if(key == GLUT_KEY_RIGHT)
	{
		ob_angle_y = ob_angle_y-10.0f;

		if (ob_angle_y>360.0f)
			ob_angle_y = ob_angle_y-360.0f;
	}
	     

	if(key == GLUT_KEY_UP)
	{
		ob_angle_x = ob_angle_x-10.0f;

		if (ob_angle_x>360.0f)
			ob_angle_x = ob_angle_x-360.0f;
	}

	if(key == GLUT_KEY_DOWN)
	{
		ob_angle_x = ob_angle_x+10.0f;

		if (ob_angle_y<-180.0f)
			ob_angle_y = ob_angle_y+360.0f;
	}

	if(key == GLUT_KEY_PAGE_UP)
	{
		ob_angle_z = ob_angle_z+10.0f;

		while(ob_angle_z>360.0f)
			ob_angle_z = ob_angle_z - 360.0f;
	}

	if(key == GLUT_KEY_PAGE_DOWN)
	{
		ob_angle_z = ob_angle_z-10.0f;

		while(ob_angle_z < 0.0f)
			ob_angle_z = ob_angle_z + 360.0f;
	}


}


void TimerFunc(int value)
{
    glutPostRedisplay();
    glutTimerFunc(1, TimerFunc, 1);
}


int main()
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("Sample");
	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(SpecialKeyHandler);
	glutDisplayFunc(RenderScene);
	glutTimerFunc(500, TimerFunc, 1);

	base = glGenLists(1);
	support= glGenLists(1);
	motorset2 = glGenLists(1);
	motor = glGenLists(1);
    motorset1 = glGenLists(1);
	pulley_s = glGenLists(1);
	pulley_L = glGenLists(1);
	pulley_M = glGenLists(1);
	bar1 = glGenLists(1);
	wheel_XL = glGenLists(1);
	washer1 = glGenLists(1);
	bar2 = glGenLists(1);
	bar3 = glGenLists(1);
	bar4 = glGenLists(1);
	axialbearing = glGenLists(1);
	adopter = glGenLists(1);
	bolt_long = glGenLists(1);

	SetupRC();
	glutMainLoop();
	glDeleteLists(base, 1);
	glDeleteLists(support, 1);
	glDeleteLists(motorset2, 1);
	glDeleteLists(motor, 1);
	glDeleteLists(motorset1, 1);
	glDeleteLists(pulley_s, 1);
	glDeleteLists(pulley_L, 1);
	glDeleteLists(pulley_M, 1);
	glDeleteLists(bar1, 1);
	glDeleteLists(wheel_XL, 1);
	glDeleteLists(washer1, 1);
	glDeleteLists(bar2, 1);
	glDeleteLists(bar3, 1);
	glDeleteLists(bar4, 1);
	glDeleteLists(axialbearing, 1);
	glDeleteLists(adopter, 1);
	glDeleteLists(bolt_long, 1);
    
   return 0;
}