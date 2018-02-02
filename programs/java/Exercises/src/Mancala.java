import java.util.Scanner;

public class Mancala {
    public static void main(String[] args) {
        int[][] board = {{4, 4, 4, 4, 4, 4},{4, 4, 4, 4, 4, 4}};
        int l = 0, r = 0;
        int turn = 1;

        Scanner kb = new Scanner(System.in);

        System.out.println("Welcome to Mancala.");
        drawBoard(board, l, r);

        int in, beans, pos, side;
        while (!empty(board)) {
            turn = ((turn==1)?0:1);
            System.out.println("Player " + (turn+1) + "'s turn.");
            do {
                System.out.print("Enter the number (1-6) of the space to take beans from: ");
                in = kb.nextInt()-1;
            } while (!(in < 6 && in >= 0));
            beans = board[turn][in];
            board[turn][in] = 0;

            pos = in + 1;
            side = turn;
            for (int i = 0; i < beans; i++) {
                System.out.println(pos);
                if (pos > 5) {
                    pos = -1;
                    if (side == 0) l++;
                    else r++;
                    // Switch to putting beans on the other side
                    side = ((side==1)?0:1);
                } else board[side][pos]++;
                pos++;
                if (i+1 == beans && board[side][pos] == 1) {
                    l += board[((side==1)?0:1)][5-pos];
                    board[((side==1)?0:1)][5-pos] = 0;
                }
            }
            drawBoard(board, l, r);
        }
        System.out.println("Player " + ((l > r) ? 1 : 2) + " wins. Good job!");
    }
    private static void drawBoard(int[][] board, int l, int r) {
        System.out.println("      6 5 4 3 2 1");
        System.out.println("      -----------");
        System.out.print("| " + l + " | ");
        for (int i = board[0].length-1; i >= 0; i--) System.out.print(board[0][i] + " ");
        System.out.print("      \n      ");
        for (int i = 0; i < board[1].length; i++) System.out.print(board[1][i] + " ");
        System.out.println("| " + r + " |");
        System.out.println("      -----------");
        System.out.println("      1 2 3 4 5 6");
    }
    private static boolean empty(int[][] board) {
        boolean top = true;
        boolean bottom = true;
        for (int i = 0; i < 6; i++) {
            if (board[0][i] > 0) top = false;
            if (board[1][i] > 0) bottom = false;
        }
        return top || bottom;
    }
}
