package com.trudbot.Temp;

import java.io.PrintStream;
import java.util.*;


class Main {
    static Scanner cin = new Scanner(System.in);
    static PrintStream cout = System.out;

    public static void main(String[] args) {
        String ans = "", s;
        while(cin.hasNext()) {
            s = cin.next();
            ans += s.charAt(0);
        }
        cout.println(ans);
    }

}

