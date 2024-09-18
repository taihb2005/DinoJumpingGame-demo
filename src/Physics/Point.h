#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        float X , Y;

        Point(float x = 0, float y = 0): X(x) , Y(y){};

    public:
        void Log()
        {
            std::cout << X << " " << Y << std::endl;
        }

    private:

        inline Point operator+(const Point & B) const
        {
            return Point(X + B.X , Y + B.Y);
        };

        inline friend Point operator+=(Point & A , const Point & B)
        {
            A.X += B.X;
            A.Y += B.Y;
            return A;
        };

        inline Point operator-(const Point & B) const
        {
            return Point(X - B.X , Y - B.Y);
        };

        inline friend Point operator-=(Point & A , const Point & B)
        {
            A.X -= B.X;
            A.Y -= B.Y;
            return A;
        };

        inline Point operator*(const float k) const
        {
            return Point(X * k , Y * k);
        };
};

#endif // POINT_H
