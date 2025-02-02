# README.md

项目位置: ./QT_project

文档位置: ./doc

文档中的素材位置: ./assets

**跳转:**

[技术文档](./doc/技术文档.md)

[测试文档](./doc/测试文档.pdf)

[演示视频](./项目演示视频.mp4)

[开发日志](./doc/开发日志.md)

# 一、赛题题目

## 1.1 项目名称

使用Qt RHI的接口，实现计算给定图片的主色调。

## 1.2 项目描述

输入数据为png或jpg格式的图片，通过使用 Qt RHI 提供的计算 shader 的支持，在着色器中计算出输入图片中的主颜色（即被大范围使用的颜色区间），程序输出一个 RGB 颜色值

使用 Qt6.6版本
无需精准判断颜色，比如一张图片上有 25%的部分用了纯红色，25%的部分用了稍微淡一点的红色，剩下50%是丰富多彩的其它颜色，则输出的颜色可以处于纯红色和淡红色之间（比如进行加权平均计算）

## 1.3 项目要求

必须使用 Qt 完成目标，并且计算过程必须在 GPU 内执行，对 CPU 的消耗可以忽略不计。

## 1.4 预期目标

输入为一个图片路径，输出为一个 ARGB 的颜色值