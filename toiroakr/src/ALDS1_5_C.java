import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import util.FastReader;

/**
 * @see <a href='http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?lang=jp&id=ALDS1_5_C'>コッホ曲線</a>
 */
public class ALDS1_5_C {
    private static util.FastReader in = new FastReader();
    private static final double SQRT3 = Math.sqrt(3d);

    enum Direction {
        LR, UL, DL, UR, DR
    }

    public static void main(String[] args) throws Exception {
        ALDS1_5_C main = new ALDS1_5_C();
        main.run();
    }

    private void run() {
        int n = in.nextInt();

        List<Point> points = Arrays.asList(Point.of(0, 0), Point.of(100, 0));
        for (int i = 0; i < n; i++) {
            List<Point> newPoints = new ArrayList<>(points.size() * 4 - 3);
            for (int j = 0; j < points.size() - 1; j++) {
                Point temp = points.get(j);
                Point next = points.get(j + 1);
                newPoints.add(temp);
                addPointsBetweem(newPoints, temp, next);
            }
            newPoints.add(points.get(points.size() - 1));
            points = newPoints;
        }

        points.forEach(System.out::println);
    }

    private void addPointsBetweem(List<Point> points, Point temp, Point next) {
        points.add(temp.internalDivide(next, 1d, 3d));
        switch (directBetween(temp, next)) {
            case LR:
                points.add(Point.of((temp.x + next.x) / 2, temp.y + (next.x - temp.x) / 2 / SQRT3));
                break;
            case UR:
            case DL:
                points.add(Point.of(temp.x, (temp.y + 2d * next.y) / 3));
                break;
            case UL:
            case DR:
                points.add(Point.of(next.x, (2d * temp.y + next.y) / 3));
                break;
            default:
                System.exit(-1);
        }
        points.add(temp.internalDivide(next, 2d, 3d));
    }

    private Direction directBetween(Point temp, Point next) {
        if (temp.y == next.y) {
            return Direction.LR;
        }
        if (temp.y < next.y) {
            if (temp.x < next.x) {
                return Direction.UR;
            }
            return Direction.UL;
        }
        if (temp.x < next.x) {
            return Direction.DR;
        }
        return Direction.DL;
    }

    private static class Point {
        double x;
        double y;

        static Point of(double x, double y) {
            Point newInstance = new Point();
            newInstance.x = x;
            newInstance.y = y;
            return newInstance;
        }

        Point internalDivide(Point opponent, double numerator, double denominator) {
            double coefficientThis = denominator - numerator;
            return Point.of(
                    (coefficientThis * x + numerator * opponent.x) / denominator,
                    (coefficientThis * y + numerator * opponent.y) / denominator
            );
        }

        @Override
        public String toString() {
            return x + " " + y;
        }
    }
}
