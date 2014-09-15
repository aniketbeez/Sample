/**
 * Display video from webcam */
 
#include <stdio.h>
#include "cv.h"
#include "highgui.h"
#include<windows.h>
#include<winable.h>

 IplImage * sh1=0;
 IplImage * sh2=0;
CvFont font;
double hScale=2.0;
double vScale=2.0;
int    lineWidth=3;
CvScalar seq;
CvSize size;
    CvCapture *capture = 0;
    IplImage  *frame = 0;
    IplImage *DES=0;
    IplImage *des=0;
    IplImage *GRA=0;
    IplImage* hsv_mask=0;
    IplImage* mask=0;
    IplImage* hsv_mask1=0;
    IplImage* buf2=0;
   IplImage * rec=0; 
    CvArr * hullPoints;
    CvSeq* cont;
CvRect bndRect=cvRect(0,0,0,0);   
CvRect bndR=cvRect(0,0,0,0); 
CvPoint pt1,pt2;    
 int state1,state2;   
 int x,y,xn,ynn;
 int yx,yy,yxn,yyn;
 
 int xmax,ymax,xmin,ymin;
  CvPoint pp1,pp2;
 int x1,x2,y11,y2;
char str[50];








void getpoint()
{des->origin=1;

IplImage *ok=0;


cvInitFont(&font,CV_FONT_HERSHEY_SIMPLEX|CV_FONT_ITALIC, hScale,vScale,0,lineWidth);


rec= cvCreateImage( size, frame->depth, 1);    
ok= cvCreateImage( size, frame->depth, 1);   
xmax=0; ymax=0;xmin=639;ymin=479;

x1=0; y11=0;x2=0;y2=0;
int count;

CvMemStorage* buf=cvCreateMemStorage(0);
mask = cvCreateImage( size, frame->depth, 3);
buf2 = cvCreateImage( size, frame->depth, 1);
mask->origin=1;
buf2->origin=1;
hsv_mask1->origin=1;
hsv_mask->origin=1;
rec->origin=1;
	CvSeq* contours2 = NULL;
	double result = 0, result2 = 0;
CvScalar  hsv_min = cvScalar(20, 100, 100, 0);

	CvScalar  hsv_max = cvScalar(30, 255, 255, 0);

		cvInRangeS (des, hsv_min, hsv_max, hsv_mask1);
	//	cvCvtColor(,buf2,CV_BGR2GRAY);
//cvAbsDiff(buf1,buf2,fin);
//cvCopyImage(ip,op);

//cvShowImage("input",ip);
//cvShowImage("fin",fin);
cvErode(hsv_mask1, hsv_mask1 , 0,1);
cvDilate(hsv_mask1, hsv_mask1 , 0, 7);
	cvSmooth( hsv_mask1, hsv_mask1, CV_MEDIAN, 21, 0, 0, 0 );





	
   cvThreshold( hsv_mask1, buf2,40, 1, CV_THRESH_BINARY );
    
cvFindContours(buf2,buf,&cont,sizeof(CvContour),CV_RETR_LIST,CV_CHAIN_APPROX_SIMPLE);



		
int ct=0;
		while(cont)

		{

			result = fabs( cvContourArea( cont, CV_WHOLE_SEQ ) );

			if( result > result2) {result2 = result; contours2 = cont;};

			cont  =  cont->h_next;
ct++;
		}
		
		printf("\n%f",result2);
		if(contours2)
		{//cvDrawContours( buf2, contours2,  CV_RGB( 2555, 255, 255), CV_RGB( 0, 0, 0),3, 1, 8);
		CvPoint *point=(CvPoint *)cvGetSeqElem( contours2,0);
CvSeq* res;

	res = cvApproxPoly(contours2, sizeof(CvContour), buf, CV_POLY_APPROX_DP, cvContourPerimeter(contours2)*0.02, 0);
 //int count = 10;
 count=contours2->total;
		 cvPolyLine( buf2, &point, &count, 1, 1, CV_RGB(255,255,255), 3, CV_AA, 0 );
		
		
		
bndRect = cvBoundingRect(contours2, 0);

pt1.x = bndRect.x;
pt1.y = bndRect.y;

pt2.x = pt1.x+bndRect.width;
pt2.y = pt1.y+bndRect.height;

	cvRectangle(buf2, pt1, pt2, CV_RGB(255,255,255), 1);
	
//	CvSeqReader reader;
//	cvStartReadSeq(contours2, &reader);
//	CV_READ_SEQ_ELEM( point, reader );

//	 CvPoint *point =  (CvPoint *)CV_GET_SEQ_ELEM(CvPoint,reader);
	
	
//IplImage* eig_image = cvCreateImage( size, frame->depth, 1 );
//	IplImage* tmp_image = cvCreateImage( size, frame->depth, 1 );

//	int corner_count = 10;
//	CvPoint2D32f* cornersA = new CvPoint2D32f[ 10 ];

//	cvGoodFeaturesToTrack( buf2, eig_image, tmp_image, cornersA, &corner_count,
	//	0.05, 5.0, 0, 3, 0, 0.04 );

	//cvFindCornerSubPix( buf2, cornersA, corner_count, size,
	//	cvSize( -1, -1 ), cvTermCriteria( CV_TERMCRIT_ITER | CV_TERMCRIT_EPS, 20, 0.03 ) );	
	
	
	
// CvPoint  curve1[]={200,200,  10,20,  150,20,  150,150};
// CvPoint2D32f * rect=cornersA;

       // cvNamedWindow("cont",1);
	//	cvShowImage("cont",buf2);
    }
		
		
		
		
		
		
		
		
		
	hsv_mask->origin=1;
      int i,j;
      x=0;y=0;xn=0;ynn=0;
      yx=0;yy=0;
      yxn=0;yyn=0;
      
      
          for(i=0;i<des->height;i++)
     {
         for(j=0;j<des->width;j++)
         {
     seq=cvGet2D(des,i,j);
     
   //if((5.75 <= seq.val[0] &&  seq.val[0]<= 6.30) && (0.10 <= seq.val[1] &&  seq.val[1]<= 0.40) && (100 <= seq.val[2]  && seq.val[2]<= 250))
     if((seq.val[0]>=0 && seq.val[0]<=20) && (seq.val[1]>=30 && seq.val[1]<=150) && (seq.val[2]>=80 && seq.val[2]<=255))
     {  
              //if((5.75 <= seq.val[0] <= 6.30))	 
              cvSet2D(mask,i,j,seq);	
              seq.val[0]=0;
              //if((0.10 <= seq.val[1] <= 0.40))
              seq.val[1]=0;
              //if(100 <= seq.val[2] <= 250)
              seq.val[2]=255;              
               //if(1 <= seq.val[0] <= 1.3)
              seq.val[3]=0;
 x=x+j;
 y=y+i;
 xn++;
 ynn++;
 
 
              cvSet2D(des,i,j,seq);
               seq.val[0]=255;
              //if((0.10 <= seq.val[1] <= 0.40))
              seq.val[1]=255;
              //if(100 <= seq.val[2] <= 250)
              seq.val[2]=255;              
               //if(1 <= seq.val[0] <= 1.3)
              seq.val[3]=255;
              
              cvSet2D(hsv_mask,i,j,seq);
              
              
              }
              else 
             { if((seq.val[0]>=20 && seq.val[0]<=30) && (seq.val[1]>=100 && seq.val[1]<=255) && (seq.val[2]>=100 && seq.val[2]<=255))
              {cvSet2D(mask,i,j,seq);
              
              if(contours2)
        {      
             // bndRect = cvBoundingRect(contours2, 0);
              pt1.x = bndRect.x;
pt1.y = bndRect.y;

pt2.x = pt1.x+bndRect.width;
pt2.y = pt1.y+bndRect.height;
             if( (j>pt1.x && j<pt2.x) && (i>pt1.y && i<pt2.y) ) 
           {   if (xmax<j)
              {xmax=j;
              y11=i;}
              
              if(ymax<i)
             { ymax=i;
              x1=j;}
              
              
                if (xmin>j)
              {xmin=j;
              y2=i;
              }
              if(ymin>i)
             { ymin=i;
              x2=j;}
              }
              }       
              
                                    seq.val[0]=255;
                                    
              //if((0.10 <= seq.val[1] <= 0.40))
              seq.val[1]=255;
              //if(100 <= seq.val[2] <= 250)
              seq.val[2]=255;              
               //if(1 <= seq.val[0] <= 1.3)
              seq.val[3]=0;
              
              cvSet2D(hsv_mask,i,j,seq);
              
              yx=yx+j;
              yy=yy+i;
              yxn++;
              yyn++;
                                 
                                 
               }
               else
                                 
               {  seq.val[0]=0;
              //if((0.10 <= seq.val[1] <= 0.40))
                  seq.val[1]=0;
              //if(100 <= seq.val[2] <= 250)
                  seq.val[2]=0;
              
               //if(1 <= seq.val[0] <= 1.3)
                  seq.val[3]=0;
              cvSet2D(des,i,j,seq);
              
              seq.val[0]=0;
              //if((0.10 <= seq.val[1] <= 0.40))
              seq.val[1]=0;
              //if(100 <= seq.val[2] <= 250)
              seq.val[2]=0;              
               //if(1 <= seq.val[0] <= 1.3)
              seq.val[3]=0;
              
              cvSet2D(hsv_mask,i,j,seq);
               }  
                }
                   
              }
              
              
              
              } 
          if(contours2)    
        {   CvPoint p1,p2,p3,p4;
           
              p1.x=xmax;
           p1.y=y11;
           
           p2.x=x1;
           p2.y=ymax;
              
           p3.x=xmin;
           p3.y=y2;
              
           p4.x=x2;
           p4.y=ymin;
              
        CvPoint pp[]={p1,p2,p3,p4};
        CvPoint *p=pp;
        
        count=4;
        
         cvPolyLine( rec, &p, &count, 1, 1, CV_RGB(255,255,255), 3, CV_AA, 0 );  
           
              //	cvNamedWindow("rect",1);
             // cvShowImage("rect",rec);
              }        
              	//cvNamedWindow("final",1);
              	cvNamedWindow("mask",1);
             
              cvCvtColor(mask,mask,CV_HSV2BGR);
              yx=yx/yxn;
              yy=yy/yyn;
              cvCircle(mask, cvPoint(yx,yy), 8, cvScalar(0,0,255), 3);
              int ht=0,wd=0;
              ht=bndRect.height/2;
              wd=bndRect.width/2;
              yx=bndRect.x+wd;
              yy=bndRect.y+ht;
          
           pp1.x=yx+4*ht;
           pp1.y=yy+10*ht;
           
           
           
           pp2.x=yx-4*ht;
           pp2.y=yy+ht;
           if(pp1.x<0)
           pp1.x=0;
           if(pp1.x>639)
           pp1.x=639;
           
           if(pp1.y<0)
           pp1.y=0;
           if(pp1.y>479)
           pp1.y=479; 
           
            if(pp2.x<0)
           pp2.x=0;
           if(pp2.x>639)
           pp2.x=639;
           
           if(pp2.y<0)
           pp2.y=0;
           if(pp2.y>479)
           pp2.y=479; 
           
            cvRectangle(mask, pp1, pp2, CV_RGB(255,255,255), 1);  
              
     bndRect.x=pp2.x;
     bndRect.y=pp2.y;
       bndRect.width=fabs(pp1.x-pp2.x);
       bndRect.height=fabs(pp1.y-pp2.y);       
        cvCopyImage(hsv_mask,ok);      
       cvSetImageROI(ok,bndRect);   
       
         //cvErode(ok, ok , 0,2);
//cvDilate(ok, ok , 0, 5);
       
       
       
       
      	cvErode(ok, ok , 0,1);
       	
	cvDilate(ok, ok , 0, 2);
	cvSmooth( ok, ok, CV_MEDIAN, 5, 0, 0, 0 );
//	cvErode(ok, ok , 0,2);



       
       ok->origin=1;    
        
         // cvResize(ok,hsv_mask);
  //        cvErode(hsv_mask, hsv_mask , 0,1);
      //    	cvDilate(hsv_mask,hsv_mask, 0,6);
//	cvErode(hsv_mask, hsv_mask , 0,2);
	
	

     //cvCvtColor(hsv_mask,hsv_mask,CV_GRAY2BGR);
   IplImage *def=cvCreateImage(size,frame->depth,3);
   sh2=cvCreateImage(cvGetSize(ok),frame->depth,frame->nChannels);
       cvFindContours(ok,buf,&cont,sizeof(CvContour),CV_RETR_LIST,CV_CHAIN_APPROX_SIMPLE);



		
//int ct=0;
		while(cont)

		{

			result = fabs( cvContourArea( cont, CV_WHOLE_SEQ ) );

			if ( result > result2) {result2 = result; contours2 = cont;};

			cont  =  cont->h_next;
//ct++;
		}
		cvDrawContours( def, contours2,  CV_RGB( 0, 200, 250), CV_RGB( 0, 0, 0),3, -1, 8);
		cvDrawContours( sh2, contours2,  CV_RGB( 0, 200, 250), CV_RGB( 0, 0, 0),3, -1, 8);
	contours2 = cvApproxPoly(contours2, sizeof(CvContour), buf, CV_POLY_APPROX_DP, cvContourPerimeter(contours2)*0.02,0);
	
    	IplImage *temp=0;
		temp=cvCreateImage(size,frame->depth,1);
		temp->origin=1;
		cvDrawContours( temp, contours2,  CV_RGB( 255, 255, 255), CV_RGB( 0, 0, 0),3, -1, 8);
		
		CvSeq *hull,*defect;
		//CvConvexityDefect *defect;
		  hull = cvConvexHull2(contours2,0,CV_CLOCKWISE,0); 
                hullPoints = (CvArr *)malloc((hull->total)*sizeof(CvSeq)); 
              //  tot = hull->total; 
                cvCvtSeqToArray(hull,hullPoints);
                
		defect=cvConvexityDefects(contours2,hull);
		//hullPoints = (CvArr *)malloc((defect->total)*sizeof(CvSeq)); 
		 
		 int hulltotal = hull->total;
int defecttotal = defect->total;



CvConvexityDefect *defects =
(CvConvexityDefect*)malloc(sizeof(CvConvexityDefect)*defecttotal);
cvCvtSeqToArray(defect, defects, CV_WHOLE_SEQ);

int lx,ly;
int llx,lly;
llx=2*ht;
lly=0;
lx=llx-ht;
ly=lly+3.5*ht;
int cnt=0;

cvCircle(def, cvPoint(lx,ly), 8, cvScalar(0,255,255), 3);

state2=0;
int p=0;
int pp=0;

CvPoint stack[20];
for(int i = 0; i < defecttotal; i++) {
  
        
 double  a,b,c,d,e,f,g;
 
 a=((*(defects[i].start)).x)-((*(defects[i].depth_point)).x);
 b=((*(defects[i].start)).y)-((*(defects[i].depth_point)).y);
 c=sqrt(a*a+b*b);
 
  a=((*(defects[i].start)).x)-((*(defects[i].end)).x);
 b=((*(defects[i].start)).y)-((*(defects[i].end)).y);
 e=sqrt(a*a+b*b);
 
  a=((*(defects[i].end)).x)-((*(defects[i].depth_point)).x);
 b=((*(defects[i].end)).y)-((*(defects[i].depth_point)).y);
 d=sqrt(a*a+b*b);
   
   f=(c*c+d*d-e*e)/(2*c*d);
  // printf("\n%f",f);     
        if(f>(0))
        {
                 state2++;
  stack[pp]=*(defects[i].start);
 // p=i+1;
 pp++;
  stack[pp]=*(defects[i].end);            
//cvLine(def, *(defects[i].start),*(defects[i].end), CV_RGB(0,0,255), 2, 8, 0);
cvLine(def, *(defects[i].start),
*(defects[i].depth_point), CV_RGB(255,0,0
), 2, 8, 0);
cvLine(def, *(defects[i].depth_point),
*(defects[i].end), CV_RGB(255,0,2),
2, 8, 0);

cvLine(sh2, *(defects[i].start),
*(defects[i].depth_point), CV_RGB(255,0,0
), 2, 8, 0);
cvLine(sh2, *(defects[i].depth_point),
*(defects[i].end), CV_RGB(255,0,2),
2, 8, 0);


   cvCircle(def, *(defects[i].start), 8, cvScalar(0,255,255), 3);
      cvCircle(def, *(defects[i].end), 8, cvScalar(0,255,255), 3);
      
      
   cvCircle(sh2, *(defects[i].start), 8, cvScalar(0,255,255), 3);
      cvCircle(sh2, *(defects[i].end), 8, cvScalar(0,255,255), 3);
//cvLine(def, *(defects[i].depth_point),*(defects[i].end), CV_RGB(0,0,255),2, 8, 0);
}
else
break;

}

double ds=0;
ds=stack[1].y-stack[0].y;
ds=ds/ht;

//printf("\n%f",ds);


def->origin=1;
state2++;
itoa(state2,str,10);
cvPutText (def,str,cvPoint(455,300), &font, cvScalar(255,255,255));
		 
if(state1==1 && state2==2)
{          if(ds>1.9);
         //   printf("left click");
          else
           if(ds>0.0 && ds<1.2);
        //    printf("right click");
            
            
            }		 
		 
state1=state2;
	
    	 
	
	///	CvPoint *point1=(CvPoint *)cvGetSeqElem( defect,0);
//CvSeq* res;
//IplImage *okk=cvCreateImage(size,frame->depth,1);
//	res = cvApproxPoly(contours2, sizeof(CvContour), buf, CV_POLY_APPROX_DP, cvContourPerimeter(contours2)*0.02, 0);
 //int count = 10;
// count=defect->total;
	//	 cvPolyLine( okk, &point1, &count, 1, 1, CV_RGB(255,255,255), 3, CV_AA, 0 );
		cvNamedWindow("hull",1);
		
	//	cvShowImage("hull",)
     
     
     
          
          // cvShowImage("final",temp); 
           
          // cvResetImageROI(ok);
           bndRect = cvBoundingRect(contours2, 0);
           
         //  cvDrawContours( temp, hull,  CV_RGB( 255, 255, 255), CV_RGB( 0, 0, 0),3, -1, 8);
          def->origin=1;
           	cvShowImage("hull",def);
           cvSetImageROI(temp,bndRect);   
       
          // int u=cvSaveImage("c:\\432.jpg",ok);
          sh2->origin=1;
          IplImage * sh3=cvCreateImage(cvSize(150,200),sh2->depth,sh2->nChannels);
          cvResize(sh2,sh3);
          sh3->origin=1;
          cvMoveWindow("mask", 0, 200); 
       cvShowImage("mask", sh3);
       
        cvResetImageROI(ok);
        cvResetImageROI(temp);
        
        cvReleaseMemStorage(&buf);
}



 
int main( int argc, char **argv )
{
    int       key = 0;
    int i,j;
    state1=1;
    
 int l=0;
 char str1[200];
 char str[200];
 
 x=0;y=0;xn=0;ynn=0;
 
 state1=0;
 state2=0;
 

    /* initialize camera */
    capture = cvCaptureFromCAM( 0 );
    frame = cvQueryFrame( capture );
    size=cvGetSize(frame);
   des=cvCreateImage(size,frame->depth,frame->nChannels);
    DES=cvCreateImage(size,frame->depth,frame->nChannels);
    
    GRA=cvCreateImage(size,frame->depth,1);
    hsv_mask = cvCreateImage( size, frame->depth, 1);
  hsv_mask1 = cvCreateImage( size, frame->depth, 1);
  sh1=cvCreateImage(cvSize(150,200),frame->depth,frame->nChannels);
  

    /* always check */
    if ( !capture ) 
    {
        fprintf( stderr, "Cannot open initialize webcam!\n" );
        return 1;
    }
 
    /* create a window for the video */
    cvNamedWindow( "camera", CV_WINDOW_AUTOSIZE );
    //cvNamedWindow( "result", CV_WINDOW_AUTOSIZE );
 key='c';
    while(key!='y') {
                    
      
           //key = cvWaitKey( 100 );
     //   /* get a frame */if(key=='c')
        {
        frame = cvQueryFrame( capture );
        cvResize(frame,sh1);
        sh1->origin=1;
        cvMoveWindow("camera", 0, 0); 
       cvShowImage( "camera", sh1 ); 
        if( !frame ) break;
         
        cvCvtColor(frame,des,CV_BGR2HSV); 
     des->origin=frame->origin;
          getpoint();
              cvCvtColor(des,DES,CV_HSV2BGR);   
              DES->origin=frame->origin;
              if(xn!=0&&yn!=0)
              {
              x=x/xn;
              y=y/ynn;
              cvCircle(DES, cvPoint(x,y), 8, cvScalar(0,0,255), 3);
              }
                 
                 
              cvCircle(DES, cvPoint(x,y), 8, cvScalar(0,0,255), 3);     
         //cvNamedWindow("fin",CV_WINDOW_AUTOSIZE);     
     //cvShowImage( "camera", frame ); 
     cvCvtColor(DES,GRA,CV_BGR2GRAY);
  //  cvSmooth( GRA, GRA, CV_MEDIAN, 3, 0, 0, 0 );

	//	cvCanny(GRA, GRA, 0, 255, 5);
		//cvErode(GRA, GRA , 0,1);
	cvDilate(GRA,GRA, 0,3);
	cvErode(GRA, GRA , 0,2);
     cvCvtColor(GRA,DES,CV_GRAY2BGR);
      cvCircle(DES, cvPoint(x,y), 8, cvScalar(0,0,255), 3);
     // bndRect.x=20;
     // bndRect.y=20;
    //  bndRect.width=50;
     // bndRect.height=50;
     
   //  bndRect.x=pp1.x;
   //   bndRect.y=pp1.y;
   //   bndRect.width=fabs(pp1.x-pp2.x);
    //  bndRect.height=fabs(pp1.y-pp2.y); 
     
    //  cvSetImageROI(DES,bndRect);
      
  //   cvShowImage("result",DES);
     
    // cvResetImageROI(DES);
  
//     cvReleaseImage(&frame);
     //cvReleaseImage(&des);
     //cvReleaseImage(&DES);
    
     }   
          // cvReleaseData(frame);         //  cvReleaseHeader(des);
        key = cvWaitKey(1);
        
    }
 
 
 
    /* free memory */
    cvDestroyWindow( "result" );
    cvReleaseCapture( &capture );
 
    return 0;
}
