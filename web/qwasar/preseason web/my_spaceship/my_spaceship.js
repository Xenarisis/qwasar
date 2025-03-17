 
 function my_spaceship(param_1)
 {
     let i =0;
     let X =0;
     let Y =0;
     directions ='up';
     while(i < param_1.length)
     {
        if(directions=='up')
        {
            if(param_1[i]=="A")
            {
                Y-=1;
                i++ ;
            }
            if(param_1[i]=="L")
            {
                directions='left';
                i++ ;
            }
            
            if(param_1[i]=="R")
            {
                directions='right';
                i++ ;
            }
        }   
        if(directions=='down')
        {
            if(param_1[i]=="A")
            {
                Y+=1;
                i++ ;
            }
            if(param_1[i]=="R")
            {
                directions='left';
                i++ ;
            }
            if(param_1[i]=="L")
            {
                directions='right';
                i++ ;
            }
            
        }
        if(directions=='right')
        {
            if(param_1[i]=="A")
            {
                X+=1;
                i++ ;
            }
            if(param_1[i]=="R")
            {
                directions='down';
                i++ ;
            }
            if(param_1[i]=="L")
            {
                directions='up';
                i++ ;
            }
            
        }
        if(directions=='left')
        {
            if(param_1[i]=="A")
            {
                X-=1;
                i++ ;
            }
            if(param_1[i]=="R")
            {
                directions='up';
                i++ ;
            }
            if(param_1[i]=="L")
            {
                directions='down';
                i++ ;
            }
            
        }
         
        //i++ ;
     }
     //console.log(directions);
     return "{x: "+X+", y: "+Y+", direction: '"+directions+"'}";
 }

 //console.log(my_spaceship("RA"))