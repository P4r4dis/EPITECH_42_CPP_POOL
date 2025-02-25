/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:59:19 by Paradis           #+#    #+#             */
/*   Updated: 2025/02/25 20:25:42 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/Bsp.hpp"
#include <iostream>

int     main(void)
{
    std::cout << "Point inside triangle?" << std::endl;
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 10);
    Point p(5, 5);

    std::cout   << "Coordinates Point a: x = " << a.getX().toFloat()
                << ", y = " << a.getY().toFloat() << std::endl;
    std::cout   << "Coordinates Point b: x = " << b.getX().toFloat()
                << ", y = " << b.getY().toFloat() << std::endl;
    std::cout   << "Coordinates Point c: x = " << c.getX().toFloat()
                << ", y = " << c.getY().toFloat() << std::endl;
    std::cout   << "Coordinates Point p: x = " << p.getX().toFloat()
                << ", y = " << p.getY().toFloat() << std::endl;

    if (bsp(a, b, c, p))
        std::cout << "Point p is inside the triangle." << std::endl;
    else
        std::cout << "Point p is outside the triangle." << std::endl;

    std::cout << "NEXT CASE:" << std::endl;
    std::cout << "Point outside triangle?" << std::endl;
    Point a1(0, 0);
    Point b1(10, 0);
    Point c1(5, 10);
    Point p1(10, 10);

    std::cout   << "Coordinates Point a1: x = " << a1.getX().toFloat()
                << ", y = " << a1.getY().toFloat() << std::endl;
    std::cout   << "Coordinates Point b1: x = " << b1.getX().toFloat()
                << ", y = " << b1.getY().toFloat() << std::endl;
    std::cout   << "Coordinates Point c: x = " << c1.getX().toFloat()
                << ", y = " << c1.getY().toFloat() << std::endl;
    std::cout   << "Coordinates Point p: x = " << p1.getX().toFloat()
                << ", y = " << p1.getY().toFloat() << std::endl;

    if (bsp(a1, b1, c1, p1))
        std::cout << "Point p1 is inside the triangle." << std::endl;
    else
        std::cout << "Point p1 is outside the triangle." << std::endl;

    std::cout << "NEXT CASE:" << std::endl;
    std::cout << "Point on vertex?" << std::endl;
    Point a2(0, 0);
    Point b2(10, 0);
    Point c2(5, 10);


    std::cout   << "Coordinates Point a2: x = " << a2.getX().toFloat()
                << ", y = " << a2.getY().toFloat() << std::endl;
    std::cout   << "Coordinates Point b2: x = " << b2.getX().toFloat()
                << ", y = " << b2.getY().toFloat() << std::endl;
    std::cout   << "Coordinates Point c2: x = " << c2.getX().toFloat()
                << ", y = " << c2.getY().toFloat() << std::endl;

    if (bsp(a2, b2, c2, a2) &&
        bsp(a2, b2, c2, b2) &&
        bsp(a2, b2, c2, c2))
        std::cout << "Point p2 is inside the triangle." << std::endl;
    else
        std::cout << "Point p2 is outside the triangle." << std::endl;

    std::cout << "NEXT CASE:" << std::endl;
    std::cout << "Point on edge?" << std::endl;
    Point a3(0, 0);
    Point b3(10, 0);
    Point c3(5, 10);
    Point p3(5, 0);

    std::cout   << "Coordinates Point a3: x = " << a3.getX().toFloat()
                << ", y = " << a3.getY().toFloat() << std::endl;
    std::cout   << "Coordinates Point b3: x = " << b3.getX().toFloat()
                << ", y = " << b3.getY().toFloat() << std::endl;
    std::cout   << "Coordinates Point c3: x = " << c3.getX().toFloat()
                << ", y = " << c3.getY().toFloat() << std::endl;
    std::cout   << "Coordinates Point p3: x = " << p3.getX().toFloat()
                << ", y = " << p3.getY().toFloat() << std::endl;

    if (bsp(a3, b3, c3, p3))
        std::cout << "Point p3 is inside the triangle." << std::endl;
    else
        std::cout << "Point p3 is outside the triangle." << std::endl;

    std::cout << "NEXT CASE:" << std::endl;
    std::cout << "Point at triangle center?" << std::endl;
    Point a4(0, 0);
    Point b4(10, 0);
    Point c4(5, 10);
    Point p4(5, 3.33f);

    std::cout   << "Coordinates Point a4: x = " << a4.getX().toFloat()
                << ", y = " << a4.getY().toFloat() << std::endl;
    std::cout   << "Coordinates Point b4: x = " << b4.getX().toFloat()
                << ", y = " << b4.getY().toFloat() << std::endl;
    std::cout   << "Coordinates Point c4: x = " << c4.getX().toFloat()
                << ", y = " << c4.getY().toFloat() << std::endl;
    std::cout   << "Coordinates Point p4: x = " << p4.getX().toFloat()
                << ", y = " << p4.getY().toFloat() << std::endl;

    if (bsp(a4, b4, c4, p4))
        std::cout << "Point p4 is inside the triangle." << std::endl;
    else
        std::cout << "Point p4 is outside the triangle." << std::endl;

    std::cout << "NEXT CASE:" << std::endl;
    std::cout << "Point in degenerate triangle?" << std::endl;
    Point a5(0, 0);
    Point b5(5, 0);
    Point c5(10, 0);
    Point p5(5, 1);

    std::cout   << "Coordinates Point a5: x = " << a5.getX().toFloat()
                << ", y = " << a5.getY().toFloat() << std::endl;
    std::cout   << "Coordinates Point b5: x = " << b5.getX().toFloat()
                << ", y = " << b5.getY().toFloat() << std::endl;
    std::cout   << "Coordinates Point c5: x = " << c5.getX().toFloat()
                << ", y = " << c5.getY().toFloat() << std::endl;
    std::cout   << "Coordinates Point p5: x = " << p5.getX().toFloat()
                << ", y = " << p5.getY().toFloat() << std::endl;

    if (bsp(a5, b5, c5, p5))
        std::cout << "Point p5 is inside the triangle." << std::endl;
    else
        std::cout << "Point p5 is outside the triangle." << std::endl;

    std::cout << "END" << std::endl;
    return 0;
}