# gobang
五子棋游戏，可双人对战，也可人机对战
## 前期准备
* ege库
![image.png](https://upload-images.jianshu.io/upload_images/13964980-8ca1985dde477df4.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

* codeblocks
## 功能实现
### 双人对战
* 黑白方使用鼠标交替落子
* 显示率先连成五子一方的获胜结果
* 返回到菜单
### 人机对战
* 人类作为黑方先行落子
* AI自动应对
* 显示率先连成五子一方的获胜结果
* 返回到菜单
## 算法思想
**alpha-beta剪枝搜索**
* max:己方
* min:对方
* α：max方的当前最优节点
* β：min方的当前最优节点
* 假定：双方都走出最好的一步
* α剪枝：如果当前节点的值不比父节点的前兄弟节点的最大值大，则舍去此节点
* β剪枝：如果当前节点的子节点的值不比当前的父节点的前兄弟节点中的最小值小则舍弃此节点。

* 伪代码：
![image.png](https://upload-images.jianshu.io/upload_images/13964980-51ff13251e7d9688.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

## 函数设计
### 评估函数
![image.png](https://upload-images.jianshu.io/upload_images/13964980-91ebb084d930161c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
* 将棋盘情况转为字符串
* 判断棋盘棋型
（利用scanlines函数判断是否出现符合预设情况的字符串）
* 计算得分

## 成果展示
![image.png](https://upload-images.jianshu.io/upload_images/13964980-177cfad0d97b757a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
