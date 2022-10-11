//修改代码
//将isLeapYear函数中的if结构改写成多分支结构
//输入一个年份进行闰年的判断
//有没有一些可能需要考虑

package com.trudbot.Temp;

/**
 * The complex usage of the if statement.
 *
 * @author .
 */

public class Main {

    /**
     *********************
     * The entrance of the program.
     *
     * @param args Not used now.
     *********************
     */
    public static void main(String[] args) {
        // Test isLeapYear
        int tempYear = 2021;

        System.out.print("" + tempYear + " is ");
        if (!isLeapYear(tempYear)) {
            System.out.print("NOT ");
        } // Of if
        System.out.println("a leap year.");
    }// Of main

    /**
     *********************
     * Is the given year leap?
     *
     * @param paraYear The given year.
     *********************
     */
    public static boolean isLeapYear(int paraYear) {
        // Of if
        return (paraYear % 4 == 0) && (paraYear % 100 != 0) || (paraYear % 400 == 0);
    }// Of isLeapYear

}// Of class LeapYear
