window.onload = function () {
$(document).ready(function() {
  setInterval(function() {
    cache_clear()
  }, 3000);
});

function cache_clear() {
  window.location.reload(true);
  // window.location.reload(); use this if you do not remove cache
}
    var pieces = [];
    var tiles = [];

    //distance formula
    var dist = function (x1, y1, x2, y2) {
        return Math.sqrt(Math.pow((x1 - x2), 2) + Math.pow((y1 - y2), 2));
    }
    //Piece object - there are 24 instances of them in a checkers game
    function Piece(element, position) {
        //linked DOM element
        this.element = element;
        //positions on gameBoard array in format row, column
        this.position = position;
        //which player's piece i it
        this.player = '';
        //figure out player by piece id
        if (this.element.attr("id") < 12)
            this.player = 1;
        else
            this.player = 2;
        //makes object a king
        this.king = false;
        this.makeKing = function () {
            this.element.css("backgroundImage", "url('king" + this.player + ".png')");
            this.king = true;
        }
    }

    function Tile(element, position) {
        //linked DOM element
        this.element = element;
        //position in gameboard
        this.position = position;
        //if tile is in range from the piece
        this.inRange = function (piece) {
            if (dist(this.position[0], this.position[1], piece.position[0], piece.position[1]) == Math.sqrt(2)) {
                //regular move
                return 'regular';
            } else if (dist(this.position[0], this.position[1], piece.position[0], piece.position[1]) == 2 * Math.sqrt(2)) {
                //jump move
                return 'jump';
            }
        };
    }

    //Board object - controls logistics of game
    var Board = {
        board: gameBoard,
        playerTurn: 1,
        tilesElement: $('div.tiles'),
        dictionary: ["0vmin", "10vmin", "20vmin", "30vmin", "40vmin", "50vmin", "60vmin", "70vmin", "80vmin", "90vmin"],
        initalize: function () {
            var countPieces = 0;
            var countTiles = 0;
            for (row in this.board) { //row is the index
                for (column in this.board[row]) { //column is the index
                    //whole set of if statements control where the tiles and pieces should be placed on the board
                    if (row % 2 == 1) {
                        if (column % 2 == 0) {
                            this.tilesElement.append("<div class='tile' id='tile" + countTiles + "' style='top:" + this.dictionary[row] + ";left:" + this.dictionary[column] + ";'></div>");
                            tiles[countTiles] = new Tile($("#tile" + countTiles), [parseInt(row), parseInt(column)]);
                            countTiles += 1;
                        }
                    } else {
                        if (column % 2 == 1) {
                            this.tilesElement.append("<div class='tile' id='tile" + countTiles + "' style='top:" + this.dictionary[row] + ";left:" + this.dictionary[column] + ";'></div>");
                            tiles[countTiles] = new Tile($("#tile" + countTiles), [parseInt(row), parseInt(column)]);
                            countTiles += 1;
                        }
                    }
                    if (this.board[row][column] == 1) {
                        $('.player1pieces').append("<div class='piece' id='" + countPieces + "' style='top:" + this.dictionary[row] + ";left:" + this.dictionary[column] + ";'></div>");
                        pieces[countPieces] = new Piece($("#" + countPieces), [parseInt(row), parseInt(column)]);
                        countPieces += 1;
                    } else if (this.board[row][column] == 2) {
                        $('.player2pieces').append("<div class='piece' id='" + countPieces + "' style='top:" + this.dictionary[row] + ";left:" + this.dictionary[column] + ";'></div>");
                        pieces[countPieces] = new Piece($("#" + countPieces), [parseInt(row), parseInt(column)]);
                        countPieces += 1;
                    }
                }
            }
        },
        changePlayerTurn: function () {
            if (this.playerTurn == 1) {
                this.playerTurn = 2;
                $('.turn').css("background", "linear-gradient(to right, transparent 50%, #BEEE62 50%)");
                return;
            }
            if (this.playerTurn == 2) {
                this.playerTurn = 1;
                $('.turn').css("background", "linear-gradient(to right, #BEEE62 50%, transparent 50%)");
            }
        },
        //reset the game
        clear: function () {
            location.reload();
        }
    }

    Board.initalize();
    var x = 1;
    //location.reaload();
    $('#cleargame').on("click", function () {
        Board.clear();
    });

}
