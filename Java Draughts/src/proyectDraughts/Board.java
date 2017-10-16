
package proyectDraughts;

import java.io.File;
import java.io.FileNotFoundException;
import javafx.scene.image.*;
import javafx.scene.paint.Color;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.Node;
import javafx.scene.layout.GridPane;
import javafx.scene.paint.ImagePattern;
import javafx.stage.*;
import javafx.scene.shape.Rectangle;
import java.util.Scanner;
import java.util.concurrent.CountDownLatch;
import java.util.logging.Level;
import java.util.logging.Logger;
public class Board extends Application {
    GridPane root = new GridPane();
    final  int size = 8;
    Image img = new Image("image/black.png");
    Image img2 = new Image("image/white.png");
    Image img3 = new Image("image/empty.png");
     public static final CountDownLatch latch = new CountDownLatch(1);
    public static Board startUpTest = null;

    public static Board waitForStartUpTest() {
        try {
            latch.await();
        } catch (InterruptedException e) {
        }
        return startUpTest;
    }

    public static void setStartUpTest(Board startUpTest0) {
        startUpTest = startUpTest0;
        latch.countDown();
    }

    public Board() {
        setStartUpTest(this);
    }
    public void start(Stage primaryStage) {
        for (int row = 0; row < size; row++) {
            for (int col = 0; col < size; col++) {
                Rectangle square = new Rectangle();
                Color color;
                if ((row + col) % 2 == 0) color = Color.WHITE;
                else color = Color.BLACK;
                square.setFill(color);
                
                root.add(square, col, row);
                square.widthProperty().bind(root.widthProperty().divide(size));
                square.heightProperty().bind(root.heightProperty().divide(size));
            }
        }
        primaryStage.setScene(new Scene(root, 400, 400));
        primaryStage.show();
        inicializar();
        jugadas();
    }
        public void inicializar()
    {
        for (int row = 0; row < size; row++) {
            for (int col = 0; col < size; col++) {
                  Rectangle rectangle = new Rectangle();
                    if(row<3)
                    {
                        if ((row + col) % 2 == 1)     
                        {  
                            rectangle.setFill(new ImagePattern(img)); 
                            root.add(rectangle, col, row);
                        }
                    }
                     if(row>4)
                    if ((row + col) % 2 == 1) 
                    {
                        rectangle.setFill(new ImagePattern(img2));
                         root.add(rectangle, col, row);
                    }
                
                rectangle.widthProperty().bind(root.widthProperty().divide(size));
                rectangle.heightProperty().bind(root.heightProperty().divide(size));
            }
        }
    }
        public  void jugadas()
        {
                
                String jugada;
                System.out.println("Comienza la partida");
               
                int m = 0;
                int l=0;
                int j= 0;
                jugada=initialize();
                char move[];
                 move = jugada.toCharArray();
                System.out.println(jugada);
            while(jugada!="1-0"||jugada!="0-1"||jugada!="0-0") //Que no pare hasta que no sea una string de fin de partida
            {
                if(m%2==0) //En caso de que sea sacar piezas comidas
                {
                   while(jugada.length()>=(j+2))
                   {
                       
                       Rectangle rectangle = new Rectangle();
                                        rectangle.setFill(new ImagePattern(img3)); 
                                        System.out.println((move[j]-48)+""+(move[j+1]-48));
                                        root.add(rectangle, move[j]-48, move[j+1]-48);
                                       if(jugada.length()>=(j+2))
                              
                             rectangle.widthProperty().bind(root.widthProperty().divide(size));
                             rectangle.heightProperty().bind(root.heightProperty().divide(size));
                             j+=2;
                                  
                     }  
                   break;
                }
                else //En caso de que sea movimiento
                {
                int col_ = move[0]-48;
                int row_ = move[1]-48;
                int col1= move[2]-48;
                int row1 = move[3]-48;
                System.out.println(col_+" "+row_+" "+col1+" "+row1);
                   
                    for (int row = 0; row < size; row++) {
                        for (int col = 0; col < size; col++) {
                              Rectangle rectangle = new Rectangle();
                               Rectangle rectangle1 = new Rectangle();
                                if(row==row_ && col == col_)
                                {
                                    
                                       if (l%2==0)     
                                    {  
                                        rectangle.setFill(new ImagePattern(img3)); 
                                        root.add(rectangle, col_, row_);
                                        rectangle1.setFill(new ImagePattern(img)); 
                                        root.add(rectangle1, col1, row1);
                                    }
                                    else
                                     {
                                         rectangle.setFill(new ImagePattern(img3));
                                          root.add(rectangle, col_, row_);
                                          rectangle1.setFill(new ImagePattern(img2));
                                          root.add(rectangle1, col1, row1);
                                     }   
                                    
                                }

                            rectangle.widthProperty().bind(root.widthProperty().divide(size));
                            rectangle.heightProperty().bind(root.heightProperty().divide(size));
                            rectangle1.widthProperty().bind(root.widthProperty().divide(size));
                            rectangle1.heightProperty().bind(root.heightProperty().divide(size));
                        }
                    }
                    //Para pasar esperara a mas jugadas
                   // jugada="a";
                    /*
                    while(anterior==jugada)
                    {
                    jugada=initialize();
                    }
                     move = jugada.toCharArray();
                    */
                    break;
                }
            }
        }
     public String initialize() {
         String game="";
    
        Scanner s;
        try {
            s = new Scanner(new File("move.txt"));
              while (s.hasNext()) {
            if (s.hasNextLine()) { // check if next token is an int
                game+=s.nextLine();
        }  
}
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Board.class.getName()).log(Level.SEVERE, null, ex);
        }
        return game;
     }
}
