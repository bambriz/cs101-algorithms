//Bryan Ambriz
//cs 101
//tantalo
//1320937

import java.io.*;
import java.util.Scanner;

class Lex{
    public static void main(String[] args) throws IOException{
      Scanner in = null;
      Scanner in2 = null;
      PrintWriter out = null;
      
      int lineNumber = 0;

      if(args.length < 2){
         System.err.println("Usage: FileIO infile outfile");
         System.exit(1);
      }

      in = new Scanner(new File(args[0]));
      in2 = new Scanner(new File(args[0]));
      out = new PrintWriter(new FileWriter(args[1]));
   
      while( in.hasNextLine() ){
           lineNumber++;
           in.nextLine();
          }
        
         String[] sArray = new String[lineNumber];
        // String[] token = new String[lineNumber];
         int count = 0;
         while (in2.hasNextLine()){
             sArray[count] = in2.nextLine();
             count += 1;
         }
        
       List A = new List();
    
        for(int i =1; i< sArray.length; i++){
            String temp = sArray[i];
            int j;
            for(j = i-1; j >= 0 && temp.compareToIgnoreCase(sArray[j]) <= 0; j--){
                if(A.length() == 0){
                    A.prepend(i);
                    A.append(j);
                    break;
                } else if(j-1 >= 0){
                       if(temp.compareToIgnoreCase(sArray[j-1]) <= 0){
                            continue;
                       }
                }else{
                   A.moveTo(j);
                   A.insertBefore(i);
                }
            }
            if(A.length() == 0){
                A.prepend(j);
            
          
            } if(j>= 0 && temp.compareToIgnoreCase(sArray[j]) >= 0){
                    A.moveTo(j);
                    A.insertAfter(i);
            }
            
        } 
      
      
      
      
       for(A.moveTo(0); A.getIndex()>=0; A.moveNext()){
         out.println(sArray[A.getElement()]+" ");
      }
      
      in.close();
      out.close();
       
    }
}