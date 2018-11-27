#include<iostream>
#include<fstream>
#include <string>
#include<windows.h>
#include<gl\glut.h>
#include<gl\gl.h>
#include"stlinput.H"
using namespace std;


const GLfloat pi=3.1415926f;
	  
	  
      struct set_point
	  {
	    GLdouble X;
	    GLdouble Y;
	    GLdouble Z;  
	  };

      struct set_tri_surface
	  {
	    set_point plan[3];
	  };

      struct tre_dim_object                       //define 3d object
	  {  
	   set_tri_surface obj_plan;
	   set_point nomalvector;	
	  };


GLint sum_of_plan(char fname[20])  //pre-read,row-counting of th document
{
	     string text;
	     string text1;
	     int line =0;             //the number of row counted
	     bool end = false;
	     int size =0;             //total number of row


	     ifstream pre(fname);
	     while(end==false)
		 { 
           getline(pre, text1, '\n');
	       if(text1=="endsolid")
		   {
		    end=true;
		    size = line;
		   }
	       line++;
		 }
	      return size/7;
}


tre_dim_object *read(char filename[20],GLint n)
{
       tre_dim_object *obj1;
    	obj1 = new tre_dim_object[n];
	    string text;
	    string text1;
	    int line =0;             //the number of row counted
	    int choice =0;
	    bool end = false;


	    ifstream fin(filename);
      while (end==false)
	  {
		choice = (line%7);
		
	   switch(choice)
	   {
	     case 1:
		 {
         fin >> text1>>text>>obj1[line/7].nomalvector.X>>obj1[line/7].nomalvector.Y>>obj1[line/7].nomalvector.Z;
		   if (text1 =="endsolid" )
		   {
			 end=true;
		   }
	       break;
		 }

	     case 2:
		 {
			fin >> text >> text;
			break;
		 }

	     case 3:
		 {
			fin >> text >> obj1[line/7].obj_plan.plan[0].X >> obj1[line/7].obj_plan.plan[0].Y >> obj1[line/7].obj_plan.plan[0].Z;
			break;
		 }

	     case 4:
		 {
			fin >> text >> obj1[line/7].obj_plan.plan[1].X >> obj1[line/7].obj_plan.plan[1].Y >> obj1[line/7].obj_plan.plan[1].Z;
			break;
		 }

    	 case 5:
		 {
            fin >> text >> obj1[line/7].obj_plan.plan[2].X >> obj1[line/7].obj_plan.plan[2].Y >> obj1[line/7].obj_plan.plan[2].Z;  
			break;
		 }

	     case 6:
		 {
			fin >> text ;
			break;
		 }

	     case 0:
		 {
			fin >> text;
			if (line==0)
			{
				fin>>text;
			}
			break;
		 }

	   }                 //end of switch case
	     line++;
	  }                  //end of while loop

	    return obj1;
}                       //end of function read




void stlinput(char filenamet[20],GLuint file)
{
	  	 
	  
        tre_dim_object *obj;
        GLint num_plan = 0;

        num_plan = sum_of_plan(filenamet);         //filename
        obj = read(filenamet,num_plan);


      glNewList(file, GL_COMPILE);        //Save 3d-object as "file" temporary
      {
		glBegin(GL_TRIANGLES);            //3d-object drawing start
         for(int i =0;i<num_plan;i++)
		 {
             glNormal3d(obj[i].nomalvector.X, obj[i].nomalvector.Y,obj[i].nomalvector.Z);
			 glVertex3d(obj[i].obj_plan.plan[0].X, obj[i].obj_plan.plan[0].Y, obj[i].obj_plan.plan[0].Z);
			 glVertex3d(obj[i].obj_plan.plan[1].X, obj[i].obj_plan.plan[1].Y, obj[i].obj_plan.plan[1].Z);
			 glVertex3d(obj[i].obj_plan.plan[2].X, obj[i].obj_plan.plan[2].Y, obj[i].obj_plan.plan[2].Z);
		 }
		 glEnd();                          //3d-object drawing end
	  }
	  glEndList();

	  
      
	  
}                                 //end of function stlinput;