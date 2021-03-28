## 环境

VsCode + g++(MingW32-make--利用Widows下cmd进行的make操作)  +  gitbash(Windows 下运行bash脚本) 

建议测试时配置好VsCode的g++开发环境，并且配置好gitbash环境变量后，在VsCode下用powershell运行脚本即可。水平有限--不确定是否其他版本shell脚本解释能否运行

## 文档说明：

**data.txt** 为pdadd的数据获取文档，**每次仅获取第一条记录**，日期需按格式，否则输出参数错误或者记录当前 pc日期。读取文档直到遇到"." 或者EOF为止。起始状态为空。-- 由shell脚本重定向输入信息--已经在脚本中加入3条测试信息

**hw4.txt** 为person diary文档，里面已经包含15条符合格式要求的相关日记内容，用于其他测试

**hw4_copy.txt** 为日记的备份，用于在remove后重新恢复日记信息

**show.txt** pdshow 根据相关内容的输出

**list.txt** pdlist 根据相关内容输出

**out.txt** 所有程序的交互输出窗口 包括 pdadd的交互，pdremove的成功与否信息显示，pdshow的日期是否正确等等。

**test.sh** 进行测试的shell脚本，包含了相关内容的测试，具体内容与注释可以打开查看

## 注意

* hw4.txt尽量不要手动修改内容--不要手动在最后添加换行。

* list和show的显示格式会根据shell的执行与环境不同而有所不同，但内容均为正确。建议vscode下放到同一目录打开使用。主要就是换行与否的差别。文件重定向方式均为append -- a+追加

* 所有的exe文件查找的均为当前目录--具体可以看代码

* 提供了makefile以供发现问题时重新编译。用法make(mingw32-make) pdadd(pdlist/pdremove/pdshow) make clean。 makefile 写法较为简陋，见谅

## 本机测试结果

<img src="C:\Users\Dell\AppData\Roaming\Typora\typora-user-images\image-20200423094622538.png" alt="image-20200423094622538" style="zoom:50%;" />

<img src="C:\Users\Dell\AppData\Roaming\Typora\typora-user-images\image-20200423094802396.png" alt="image-20200423094802396" style="zoom:50%;" />



<img src="C:\Users\Dell\AppData\Roaming\Typora\typora-user-images\image-20200423094833473.png" alt="image-20200423094833473" style="zoom:50%;" />



<img src="C:\Users\Dell\AppData\Roaming\Typora\typora-user-images\image-20200423094846267.png" alt="image-20200423094846267" style="zoom:50%;" />



<img src="C:\Users\Dell\AppData\Roaming\Typora\typora-user-images\image-20200423094902994.png" alt="image-20200423094902994" style="zoom:50%;" />



<img src="C:\Users\Dell\AppData\Roaming\Typora\typora-user-images\image-20200423094917160.png" alt="image-20200423094917160" style="zoom:50%;" />



<img src="C:\Users\Dell\AppData\Roaming\Typora\typora-user-images\image-20200423094930310.png" alt="image-20200423094930310" style="zoom:50%;" />



<img src="C:\Users\Dell\AppData\Roaming\Typora\typora-user-images\image-20200423094943207.png" alt="image-20200423094943207" style="zoom:50%;" />