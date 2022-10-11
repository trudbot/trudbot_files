package com.trudbot.MainTest;

import java.util.*;


public class Test {

    @SuppressWarnings("unchecked")
    //用注解消除“未检查类型转换”的警告信息
    public static void main(String[] args) {
        ArrayList arrayList = new ArrayList();
        arrayList.add(101);//列表元素默认是 Object 类型，直接加入整数，而未进行强制类型转换，就会产生编译时警告
        arrayList.add(100);
        System.out.println(arrayList);

        @SuppressWarnings("unused")
//用注解消除“变量未引用”的警告信息
        String e="abc";//变量 e 在 main() 内没有被引用过，会产生警告信息
    }
}