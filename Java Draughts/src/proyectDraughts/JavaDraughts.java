package proyectDraughts;

import javafx.scene.image.*;
import javafx.scene.paint.Color;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.Node;
import javafx.scene.layout.GridPane;
import javafx.scene.paint.ImagePattern;
import javafx.stage.*;
import javafx.scene.shape.Rectangle;


public class JavaDraughts extends Application {
    GridPane root = new GridPane();
    final int size = 8;

    public void start(Stage primaryStage) {
        Image img = new Image("image/black.png");
        Image img2 = new Image("image/white.png");
        ImagePattern imagePattern = new ImagePattern(img);
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
    }

    public static void main(String[] args) {
        // launch(args);
        MainInterface mi = new MainInterface();
    }
}
