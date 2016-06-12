import java.util.Scanner;

public class ALDS1_5_C {

    private static Scanner sc = new Scanner(System.in);
    private static int n;

    public static void main(String[] args) {
        n = sc.nextInt();

        Point p1 = new Point(0.0, 0.0);
        Point p2 = new Point(100.0, 0.0);

        System.out.println(p1);
        koch(n, p1, p2);
        System.out.println(p2);
    }

    private static void koch(int d, Point p1, Point p2) {
        if (d == 0) {
            return;
        }

        Point s = new Point((2.0 * p1.getX() + 1.0 * p2.getX()) / 3.0, (2.0 * p1.getY() + 1.0 * p2.getY()) / 3.0);
        Point t = new Point((1.0 * p1.getX() + 2.0 * p2.getX()) / 3.0, (1.0 * p1.getY() + 2.0 * p2.getY()) / 3.0);

        Point u = calcPointU(s, t);

        koch(d - 1, p1, s);
        System.out.println(s);
        koch(d - 1, s, u);
        System.out.println(u);
        koch(d-1, u, t);
        System.out.println(t);
        koch(d - 1, t, p2);
    }

    private static Point calcPointU(Point s, Point t) {
        double cos60 = Math.cos(Math.toRadians(60));
        double sin60 = Math.sin(Math.toRadians(60));
        double xDiff = t.getX() - s.getX();
        double yDiff = t.getY() - s.getY();

        double x = xDiff * cos60 - yDiff * sin60 + s.getX();
        double y = xDiff * sin60 + yDiff * cos60 + s.getY();

        return new Point(x, y);
    }
}

class Point {
    double x;
    double y;

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }

    @Override
    public String toString() {
        return String.format("%f %f", getX(), getY());
    }
}
