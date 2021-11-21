一个基于[Insert Every Thing Through EA](https://feuniverse.us/t/ea-wip-a-guide-to-inserting-everything-through-ea/1627 )的理念来实现的汉化字模转EA的工程；目标为采用纯EA的方式实现FE8U的汉化工作。

# 如何使用
### 1.前置补丁:
烧录字库需要两个补丁，`UTF8`与`AntiHuffman`。二者分别对应`DrawUTF8/Installer.event`,以及`_FE8EssentialFixes.event`，需要在`Buildfile`中将上述两个文件包含进来；

### 2.烧录字库:
1. 将对应的字库文件放置在`fonts\Glyph\`文件夹中。text类型的字模命名为`FontTtem×.png`，item字模则命名为`FontItem×.png`
2. 需要另行保存文件`font.fontall.txt`于`fonts\Glyph\`中，其文件内容格式与FEB导出字模后的文件一致；
3. 进入`fonts\`文件夹内,依次点击`_BatchFont.bat`与`_BatchInstaller.bat`，二者烧录时间较长。前者结束时会提示`"Dmp2Font Done!"`，后者则提示`Installer Done!`等待运行完成,即可生成字模的EA烧录文件`FontInstaller.event`.

### 3. Buildfile: 
在`Buildfile`中将`FontInstaller.event`包含其中，此时烧录则已经实现字库烧录；

### 4. 烧录字串:
``` texts\TextBuildfile.txt```保存有所有待烧录字串，语法同textprocess。但目前只支持```[N] [X]```两种标记。
系统安装python3后，在```\texts```文件夹内打开cmd并执行指令```python3 text-process-cn.py TextBuildfile.txt InstallTextData.event TextDefinition.txt```，即可生成字串烧录文件

### 5. 烧录:
FE8U clean rom命名为`FE8U.gba`,将`Evenet Assembler`放置在根目录下点击`MAKE HACK.cmd`即可完成汉化。



# 如果想额外补字
首先，不可以用已经烧录了字库的rom再做二次烧录本工程。必须基于FE8U clean rom进行烧录。
在烧录完成后，若想补单个字的话，简便的方法可以参考[瓜鸽的FEBuilder方案](https://www.bilibili.com/video/BV1Q34y1d7gL)。 如果打算使用EA的方案替换或者添加字，则请在更新过图片以及`font.fontall.txt`后，双击`_BatchAll.bat`将整个字库重新烧录一遍。